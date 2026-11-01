#!/bin/bash
# restart.sh [flash.bin] [uImage]  -- (re)start the debug QEMU guest (run-dbg.sh) and wait until the boot has settled
D=$(dirname "$(readlink -f "$0")"); mkdir -p $D/q
[ -f $D/q/qemu.pid ] && kill $(cat $D/q/qemu.pid) 2>/dev/null; sleep 1   # only the guest this script started (PID file)
: > $D/q/console.log
(setsid $D/run-dbg.sh "$@" > $D/q/qemu.out 2>&1 &)
sleep 75; echo started
