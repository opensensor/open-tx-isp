#!/bin/bash
# run-dbg.sh [flash.bin] [uImage]  -- QEMU ingenic-t40 guest with a debug kernel (slub_debug) loaded into RAM at 0xc00000.
# env: QEMU (qemu-system-mipsel with the ingenic-txx machines), PORT (console tcp, default 3341), SSHP, SBUS (sensor i2c bus).
# The flash image needs bootcmd=...bootm 0x80c00000 and extra=slub_debug=FZPU, see uenv_edit.py and README text in the header of guest-loop.sh.
D=$(dirname "$(readlink -f "$0")"); mkdir -p $D/q
FL=${1:-$D/q/dbg.bin}; KI=${2:-$D/q/uImage-dbg}
exec nice -n 19 ${QEMU:-qemu-system-mipsel} -M ingenic-t40 -m 256M ${SMP:+-smp $SMP} -display none -pidfile $D/q/qemu.pid \
  -drive file=$FL,format=raw,if=none,id=flash0 -device loader,file=$KI,addr=0xc00000 \
  -serial null -chardev socket,id=con,host=127.0.0.1,port=${PORT:-3341},server=on,wait=off,logfile=$D/q/console.log -serial chardev:con \
  -netdev user,id=n0,hostfwd=tcp:127.0.0.1:${SSHP:-2241}-:22 \
  -device image-sensor,model=sc830ai,bus=${SBUS:-i2c1} -d guest_errors,unimp -D $D/q/qemu-guest.log \
  -monitor unix:$D/q/qemu.mon,server=on,wait=off
