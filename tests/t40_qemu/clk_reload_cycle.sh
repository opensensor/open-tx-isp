#!/bin/sh
# (Lu-Fi/openimp#152) Guest-side QEMU loop (ingenic-t40, Eufy image): load/unload the T40 ISP + sensors N times.
# Run on the guest console: RUNTIMPS=8 sh clk_reload_cycle.sh /lib/modules/4.4.94/ingenic/tx-isp-t40.ko 22
# Expect after every "out_N" line: div_isp=0 gate_isp=0 gate_csi=0 (clock counts from /proc/jz/clock/clocks),
# CLKGR bits 23/24 set (ISP/CSI gated), oops=0, and the same counts at every "start_unloaded"/"out_N".
# usage: [RUNTIMPS=s] sh /tmp/cyc152.sh <ko> <cycles>  -- ISP load/unload loop; clock counts (/proc/jz/clock/clocks), CLKGR, oops after each rmmod
KO=$1; N=${2:-3}; M=/lib/modules/4.4.94/ingenic
ck() { echo "$1 $(grep -E ' (gate_isp|gate_csi|gate_ahb0|div_isp|div_cim1) ' /proc/jz/clock/clocks | tr -s ' ' | awk '{print $2"="$5}' | tr '\n' ' ') CLKGR=$(devmem 0x10000020 32) oops=$(dmesg | grep -ciE 'Oops|BUG:|Unable to handle|WARNING|clk_core|unbalanced')"; }
/etc/init.d/S95timps stop >/dev/null 2>&1; sleep 2
for m in sensor_sc3338_t40 sensor_sc830ai_t40 tx_isp_t40; do lsmod | grep -q "^$m " && rmmod $m; done
ck start_unloaded
i=1; while [ $i -le $N ]; do
  insmod $KO isp_clk=300000000 print_level=1 || echo INSFAIL_$i
  insmod $M/sensor_sc830ai_t40.ko; insmod $M/sensor_sc3338_t40.ko
  if [ -n "$RUNTIMPS" ]; then /etc/init.d/S95timps start >/dev/null 2>&1; sleep $RUNTIMPS; ck run_$i; /etc/init.d/S95timps stop >/dev/null 2>&1; sleep 2; fi
  ck loaded_$i
  rmmod sensor_sc3338_t40 || echo RMFAIL_s3_$i; rmmod sensor_sc830ai_t40 || echo RMFAIL_s8_$i
  rmmod tx_isp_t40 || echo RMFAIL_isp_$i
  ck out_$i
  i=$((i+1))
done
