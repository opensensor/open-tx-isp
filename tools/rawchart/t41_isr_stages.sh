#!/bin/bash
# t41_isr_stages.sh: staged device test for t41_isr_dispatch (no reboot, ever).
#   load <ko>                      reload <ko> (dispatch=0), timps up
#   stage <name> <min> <dispatch> <skip w0,w1,w2> [tone_trigger]
#                                  set params at runtime, sample every 30 s
#   restore                        rmmod/modprobe the installed module
# Samples: AE (IT/again/gain/mean/zone/meter_err), isp-m0 irq rate (fps),
# tmo/lce counters, dispatch counts, oops scan, snapshots ch0/ch1 each minute.
IP=${IP:?set IP=<camera-ip>}; OUT=${OUT:-./out/isr-stages}; mkdir -p $OUT
[ -S /run/user/1000/ssh-cam.sock ] && export SSH_AUTH_SOCK=/run/user/1000/ssh-cam.sock
SSH="ssh -o BatchMode=yes -o ConnectTimeout=8 -o ServerAliveInterval=3 -o ServerAliveCountMax=4 root@$IP"
P=/sys/module/tx_isp_t41/parameters
log(){ echo "$(date +%T) $*" | tee -a $OUT/run.log; }
snap(){ $SSH "T=\$(cat /run/timps.token 2>/dev/null); curl -sk -m 8 \${T:+-H \"Authorization: Bearer \$T\"} 'http://127.0.0.1:8880/snapshot.jpg?chn=$2'" > $OUT/$1.jpg
  echo "$1 $(python3 -I -c "import sys;from PIL import Image,ImageStat;im=Image.open(sys.argv[1]);print('luma=%.1f rgb=%s'%(ImageStat.Stat(im.convert('L')).mean[0],','.join('%.0f'%v for v in ImageStat.Stat(im.convert('RGB')).mean)))" $OUT/$1.jpg 2>/dev/null || echo luma=ERR)"; }
sample(){ $SSH "cd $P; echo IT=\$(cat t41_safe_ae_integration) ag=\$(cat t41_safe_ae_again) g=\$(cat t41_safe_ae_gain_q16) mean=\$(cat t41_safe_ae_last_mean_q8) zone=\$(cat t41_ae_zone_mean) merr=\$(cat t41_ae_meter_error) tev=\$(cat tone_ev) irq=\$(awk '/isp-m0/{print \$2+\$3}' /proc/interrupts) t17=\$(cat tmo_irq17) kicks=\$(cat tone_kicks) tmof=\$(cat t41_tmo_frames) lcef=\$(cat t41_lce_frames) lceerr=\$(cat t41_lce_error) up=\$(cut -d' ' -f1 /proc/uptime); echo counts=\$(cat t41_isr_counts | tr ',' ' ' | awk '{for(i=1;i<=NF;i++) if(\$i>0) printf \"[%d]=%s \", i-1, \$i}'); pidof timpsd >/dev/null || echo TIMPS-DOWN; dmesg | grep -i -E 'oops|bug:|unable to handle|warn_on|refcount|hung task|rawinject|rdma' | tail -3"; }
case $1 in
load)
  $SSH 'mkdir -p /tmp/isr; cat > /tmp/isr/tx-isp-t41.ko' < $2 || { log "upload failed"; exit 2; }
  ISPP=$($SSH 'sed -n "s/^tx_isp_t41 *//p" /etc/modules.d/20-isp'); SENS=$($SSH 'sed -n "s/^\(sensor_[a-z0-9_]*\).*/\1/p" /etc/modules.d/30-sensor')
  log "load $2 dispatch=0 ($ISPP) sensor=$SENS"
  $SSH "/etc/init.d/S95timps stop >/dev/null 2>&1; sleep 2; dmesg -c >/dev/null; rmmod $SENS; rmmod tx_isp_t41 || echo FAIL-rmmod; sleep 1; insmod /tmp/isr/tx-isp-t41.ko $ISPP t41_isr_dispatch=0 || echo FAIL-insmod; modprobe $SENS || echo FAIL-sensor; /etc/init.d/S95timps start >/dev/null 2>&1; sleep 15; pidof timpsd" 2>&1 | tee -a $OUT/run.log ;;
stage)
  N=$2; MIN=$3; D=$4; SK=$5; TT=${6:-1}
  log "STAGE $N dispatch=$D skip=$SK tone_trigger=$TT ${MIN}min"
  $SSH "echo $SK > $P/t41_isr_dispatch_skip; echo $TT > $P/t41_tone_trigger; echo $D > $P/t41_isr_dispatch; echo skip=\$(cat $P/t41_isr_dispatch_skip) d=\$(cat $P/t41_isr_dispatch) tt=\$(cat $P/t41_tone_trigger)" | tee -a $OUT/run.log
  for s in $(seq 1 $((MIN*2))); do
    sample 2>&1 | sed "s/^/  $N s$s /" | tee -a $OUT/run.log
    [ $((s%2)) = 0 ] && { snap $N-m$((s/2))-ch0 0; snap $N-m$((s/2))-ch1 1; } 2>&1 | sed 's/^/  /' | tee -a $OUT/run.log
    $SSH true || { log "UNREACHABLE - STOP"; exit 4; }
    sleep 27
  done
  $SSH 'dmesg' > $OUT/dmesg-$N.txt ;;
inject)
  CHART=$2; log "raw inject dtype=${DTYPE:-32} with dispatch=$($SSH cat $P/t41_isr_dispatch) skip=$($SSH cat $P/t41_isr_dispatch_skip)"
  $SSH "echo alloc $(stat -c %s $CHART) > /proc/t41_rawinject; cat /proc/t41_rawinject" | tee -a $OUT/run.log
  $SSH 'cat > /proc/t41_rawbuf' < $CHART
  for i in 1 2; do $SSH "timeout 10 sh -c 'echo inject 0 ${DTYPE:-32} > /proc/t41_rawinject'; cat /proc/t41_rawinject; dmesg | grep rawinject | tail -3" | tee -a $OUT/run.log; snap inject$i-ch0 0 | tee -a $OUT/run.log; done
  sample | sed 's/^/  inj /' | tee -a $OUT/run.log
  $SSH "timeout 10 sh -c 'echo stop > /proc/t41_rawinject'; echo free > /proc/t41_rawinject"; sleep 2; snap after-stop-ch0 0 | tee -a $OUT/run.log
  $SSH 'dmesg' > $OUT/dmesg-inject.txt ;;
restore)
  ISPP=$($SSH 'sed -n "s/^tx_isp_t41 *//p" /etc/modules.d/20-isp'); SENS=$($SSH 'sed -n "s/^\(sensor_[a-z0-9_]*\).*/\1/p" /etc/modules.d/30-sensor')
  log "restore installed ko"
  $SSH "/etc/init.d/S95timps stop >/dev/null 2>&1; sleep 2; rmmod $SENS; rmmod tx_isp_t41 || echo FAIL-rmmod2; sleep 1; modprobe tx_isp_t41 $ISPP || echo FAIL-modprobe; modprobe $SENS; /etc/init.d/S95timps start >/dev/null 2>&1; sleep 10; pidof timpsd; ls /sys/module/tx_isp_t41/parameters/t41_isr_dispatch 2>/dev/null || echo installed-ko-active" 2>&1 | tee -a $OUT/run.log
  snap restored-ch0 0 | tee -a $OUT/run.log ;;
esac
