#!/bin/bash
# restart.sh [flash.bin] [uImage]  -- (re)start the debug QEMU guest (run-dbg.sh) and wait until the boot has settled
D=$(dirname "$(readlink -f "$0")"); mkdir -p $D/q
[ -f $D/q/qemu.pid ] && kill $(cat $D/q/qemu.pid) 2>/dev/null; sleep 1   # only the guest this script started (PID file)
: > $D/q/console.log
(setsid $D/run-dbg.sh "$@" > $D/q/qemu.out 2>&1 &)
for i in $(seq 1 100); do sleep 3; grep -a -q 'ing-eufy.*#' $D/q/console.log 2>/dev/null && break; done   # shell prompt = boot (rcS incl. timpsd start) finished
sleep 10; echo started after ~$((i*3+10))s
