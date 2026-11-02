#!/bin/bash
# t41_isr_run.sh <tag> <ko> [chart.raw16] <ip>   (OUT=dir, default ./out/isr-<tag>)   (no reboot; restore via modprobe)
# 1. reload <ko> from /tmp with t41_isr_dispatch=1, timps up (ch0+ch1)
# 2. MINUTES (default 10) of normal operation: snapshots ch0/ch1 every minute,
#    dmesg oops/warn scan, irq table counters, TMO worker counters
# 3. optional RAW inject (chart) with the dispatch active
# 4. restore the installed module
TAG=$1; KO=$2; CHART=$3; IP=${4:?usage: t41_isr_run.sh <tag> <ko> [chart.raw16] <camera-ip>}; MINUTES=${MINUTES:-10}
OUT=${OUT:-./out/isr-$TAG}; mkdir -p $OUT
[ -S /run/user/1000/ssh-cam.sock ] && export SSH_AUTH_SOCK=/run/user/1000/ssh-cam.sock
SSH="ssh -o BatchMode=yes -o ConnectTimeout=8 -o ServerAliveInterval=3 -o ServerAliveCountMax=4 root@$IP"
P=/sys/module/tx_isp_t41/parameters
log(){ echo "$(date +%T) $*" | tee -a $OUT/run.log; }
snap(){ $SSH "T=\$(cat /run/timps.token 2>/dev/null); curl -sk -m 8 \${T:+-H \"Authorization: Bearer \$T\"} 'http://127.0.0.1:8880/snapshot.jpg?chn=$2'" > $OUT/$1.jpg; echo "  snap $1 $(stat -c %s $OUT/$1.jpg) bytes" | tee -a $OUT/run.log; }
counts(){ $SSH "echo counts=\$(cat $P/t41_isr_counts | tr ',' ' ' | awk '{for(i=1;i<=NF;i++) if(\$i>0) printf \"[%d]=%s \", i-1, \$i}'); echo tmo_irq17=\$(cat $P/tmo_irq17) tone_kicks=\$(cat $P/tone_kicks) dispatch=\$(cat $P/t41_isr_dispatch)" | tee -a $OUT/run.log; }
health(){ $SSH "pidof timpsd >/dev/null && echo timps=up || echo timps=DOWN; dmesg | grep -i -E 'oops|bug:|unable to handle|warn_on|refcount|hung task' | head -3" | tee -a $OUT/run.log; }

$SSH 'mkdir -p /tmp/isr; cat > /tmp/isr/tx-isp-t41.ko' < $KO || { log "upload failed"; exit 2; }
ISPP=$($SSH 'sed -n "s/^tx_isp_t41 *//p" /etc/modules.d/20-isp'); SENS=$($SSH 'sed -n "s/^\(sensor_[a-z0-9_]*\).*/\1/p" /etc/modules.d/30-sensor')
log "reload with t41_isr_dispatch=1 ($ISPP) sensor=$SENS"
$SSH "/etc/init.d/S95timps stop >/dev/null 2>&1; sleep 2; dmesg -c >/dev/null; rmmod $SENS; rmmod tx_isp_t41 || echo FAIL-rmmod; sleep 1; insmod /tmp/isr/tx-isp-t41.ko $ISPP t41_isr_dispatch=1 || echo FAIL-insmod; modprobe $SENS || echo FAIL-sensor; /etc/init.d/S95timps start >/dev/null 2>&1; sleep 15; pidof timpsd" 2>&1 | tee -a $OUT/run.log
$SSH true || { log "camera not reachable after reload - STOP"; exit 4; }
for m in $(seq 1 $MINUTES); do snap m$m-ch0 0; snap m$m-ch1 1; counts; health; $SSH 'dmesg | grep "ISR dispatch idx"' | sort -u | tee -a $OUT/run.log >/dev/null; [ $m -lt $MINUTES ] && sleep 50; done
$SSH 'dmesg' > $OUT/dmesg-normal.txt
if [ -n "$CHART" ] && [ -f "$CHART" ]; then
  log "raw inject with dispatch"; $SSH "echo alloc $(stat -c %s $CHART) > /proc/t41_rawinject; cat /proc/t41_rawinject" | tee -a $OUT/run.log
  $SSH 'cat > /proc/t41_rawbuf' < $CHART
  for i in 1 2; do $SSH "timeout 10 sh -c 'echo inject 0 ${DTYPE:-32} > /proc/t41_rawinject'; cat /proc/t41_rawinject; dmesg | grep rawinject | tail -3" | tee -a $OUT/run.log; snap inject$i-ch0 0; done
  counts; $SSH "timeout 10 sh -c 'echo stop > /proc/t41_rawinject'; echo free > /proc/t41_rawinject"; sleep 2; snap after-stop-ch0 0; health
  $SSH 'dmesg' > $OUT/dmesg-inject.txt
fi
log "restore installed ko"
$SSH "/etc/init.d/S95timps stop >/dev/null 2>&1; sleep 2; rmmod $SENS; rmmod tx_isp_t41 || echo FAIL-rmmod2; sleep 1; modprobe tx_isp_t41 $ISPP || echo FAIL-modprobe; modprobe $SENS; /etc/init.d/S95timps start >/dev/null 2>&1; sleep 10; pidof timpsd" 2>&1 | tee -a $OUT/run.log
snap restored-ch0 0; log "done -> $OUT"
