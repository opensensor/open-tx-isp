#!/bin/sh
# guest-loop.sh KO CYCLES [STREAM_SECS]  -- reload tx_isp_t40 from KO N times with timpsd streaming in between,
# validate all slabs after every step, print slub/oops lines.  Run inside the QEMU guest (busybox sh).
# KO=none: control run, only timps stop/start (no module reload).
KO=${1:-/lib/modules/4.4.94/ingenic/tx-isp-t40.ko}; N=${2:-3}; SECS=${3:-15}
M=/lib/modules/4.4.94/ingenic
validate() { for f in /sys/kernel/slab/*/validate; do echo 1 > $f 2>/dev/null; done; }
hits() { dmesg | grep -a -E "BUG [a-z0-9_-]+ \(|Redzone|Poison|Object already|Invalid |Bad page|Oops|Unable to handle|Data bus|Kernel panic|general protection|corrupt|Freepointer|Padding overwritten|Wrong object|double free" | sort | uniq -c | head -${1:-20}; }
dmesg -c > /dev/null
i=1
while [ $i -le $N ]; do
  echo "== cycle $i"
  /etc/init.d/S95timps stop >/dev/null 2>&1; sleep 2
  if [ "$KO" != none ]; then
    rmmod sensor_sc3338_t40 sensor_sc830ai_t40 2>&1; rmmod tx_isp_t40 2>&1 || echo RMFAIL
    validate; echo "after-unload:"; hits
    insmod $KO isp_clk=300000000 print_level=1 || echo INSFAIL
    insmod $M/sensor_sc830ai_t40.ko; insmod $M/sensor_sc3338_t40.ko
  fi
  /etc/init.d/S95timps start >/dev/null 2>&1; sleep $SECS
  validate; echo "after-stream:"; hits
  i=$((i+1))
done
echo LOOPDONE; lsmod | grep tx_isp; pidof timpsd
