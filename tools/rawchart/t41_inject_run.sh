#!/bin/bash
# t41_inject_run.sh <tag> <ko> <chart.raw16> <ip>   (OUT=dir, default ./out/rawinject-<tag>)
# Proof of concept: load the raw-inject ko from /tmp, start the streamer,
# push the synthetic Bayer chart into DDR and feed it through the ISP
# (RAW RDMA), grab snapshots, then restore the installed ko.
# Needs: tools/rawchart/rawchart.py chart (sensor size/Bayer/bits), timps.
TAG=$1; KO=$2; CHART=$3; IP=${4:?usage: t41_inject_run.sh <tag> <ko> <chart.raw16> <camera-ip>}
OUT=${OUT:-./out/rawinject-$TAG}; mkdir -p $OUT
[ -S /run/user/1000/ssh-cam.sock ] && export SSH_AUTH_SOCK=/run/user/1000/ssh-cam.sock
SSH="ssh -o BatchMode=yes -o ConnectTimeout=8 -o ServerAliveInterval=3 -o ServerAliveCountMax=4 root@$IP"
LINES=${LINES:-0}; DTYPE=${DTYPE:-0}; N=${N:-4}
snap(){ $SSH 'T=$(cat /run/timps.token 2>/dev/null); curl -sk -m 8 ${T:+-H "Authorization: Bearer $T"} "http://127.0.0.1:8880/snapshot.jpg?chn=0"' > $OUT/$1.jpg; echo "snap $1 $(stat -c %s $OUT/$1.jpg) bytes"; }
log(){ echo "$(date +%T) $*" | tee -a $OUT/run.log; }

$SSH 'mkdir -p /tmp/rj; cat > /tmp/rj/tx-isp-t41.ko' < $KO || { log "upload ko failed"; exit 2; }
ISPP=$($SSH 'sed -n "s/^tx_isp_t41 *//p" /etc/modules.d/20-isp')
SENS=$($SSH 'sed -n "s/^\(sensor_[a-z0-9_]*\).*/\1/p" /etc/modules.d/30-sensor')
log "isp params=[$ISPP] sensor=$SENS"
$SSH "/etc/init.d/S95timps stop >/dev/null 2>&1; sleep 2; dmesg -c >/dev/null; rmmod $SENS; rmmod tx_isp_t41 || echo FAIL-rmmod; sleep 1; insmod /tmp/rj/tx-isp-t41.ko $ISPP || echo FAIL-insmod; modprobe $SENS || echo FAIL-sensor; ls -la /proc/t41_rawinject /proc/t41_rawbuf; /etc/init.d/S95timps start >/dev/null 2>&1; sleep 12; pidof timpsd" 2>&1 | tee -a $OUT/run.log
$SSH true || { log "camera not reachable after reload - STOP"; exit 4; }
snap 00-baseline
log "alloc"; $SSH "echo alloc $(stat -c %s $CHART) > /proc/t41_rawinject; cat /proc/t41_rawinject" | tee -a $OUT/run.log
log "upload chart"; $SSH 'cat > /proc/t41_rawbuf' < $CHART; $SSH 'cat /proc/t41_rawinject; head -c 32 /proc/t41_rawbuf | hexdump -C | head -2' | tee -a $OUT/run.log
for i in $(seq 1 $N); do
  log "inject $i"; $SSH "timeout 10 sh -c 'echo inject $LINES $DTYPE > /proc/t41_rawinject'; echo rc=\$?; cat /proc/t41_rawinject; dmesg | tail -4" 2>&1 | tee -a $OUT/run.log
  $SSH true || { log "camera not reachable after inject - STOP"; exit 4; }
  snap 1$i-inject
done
log "stop"; $SSH "timeout 10 sh -c 'echo stop > /proc/t41_rawinject'; echo rc=\$?; dmesg | tail -3" | tee -a $OUT/run.log
sleep 2; snap 20-after-stop
$SSH 'dmesg' > $OUT/dmesg.txt
log "restore installed ko"
$SSH "echo free > /proc/t41_rawinject; /etc/init.d/S95timps stop >/dev/null 2>&1; sleep 2; rmmod $SENS; rmmod tx_isp_t41 || echo FAIL-rmmod2; sleep 1; modprobe tx_isp_t41 $ISPP || echo FAIL-modprobe; modprobe $SENS; /etc/init.d/S95timps start >/dev/null 2>&1; sleep 10; pidof timpsd; dmesg | grep -i -E 'oops|bug|unable to handle' | head -3" 2>&1 | tee -a $OUT/run.log
snap 30-restored
log "done -> $OUT"
