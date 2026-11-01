#!/bin/sh
# check_t30_fw_irq_gate.sh [driver/t30]   (Lu-Fi/openimp#174, #176)
# Source-level guards for two T30 fixes whose behaviour is proven in QEMU (tests/t30_qemu):
#  1. the sensor register ioctls (0x8038564f / 0xc0385650) go through the translated-struct helper,
#     not through the lifted fragment loop (which copied 0x38 bytes over 4-byte locals);
#  2. the ISP IRQ firmware dispatch is gated by tx_isp_t30_fw_ready, cleared first and set last in
#     apical_fw_init, so a frame IRQ inside the init window cannot reach the unset event queue.
d=${1:-$(dirname "$0")/../driver/t30}
f=$d/tx_isp_t30_recovered.c
[ -f "$f" ] || { echo "usage: $0 [driver/t30]" >&2; exit 2; }
fail=0
chk() { grep -q -- "$1" "$f" || { echo "check_t30_fw_irq_gate: missing: $2"; fail=1; }; }
chk 'tx_isp_t30_sensor_register_ioctl(file, cmd, arg)' 'register ioctl helper call'
chk 'sizeof(wire) != 0x38' '0x38-byte wire object check'
chk 'if (!ACCESS_ONCE(tx_isp_t30_fw_ready))' 'dispatch gate'
a=$(grep -n 'ACCESS_ONCE(tx_isp_t30_fw_ready) = 0;' "$f" | head -1 | cut -d: -f1)
m=$(grep -n 'apical_isp_init((int32_t \*)(arg1 + 6));' "$f" | head -1 | cut -d: -f1)
b=$(grep -n 'ACCESS_ONCE(tx_isp_t30_fw_ready) = 1;' "$f" | head -1 | cut -d: -f1)
e=$(grep -n 'system_hw_interrupts_enable();' "$f" | awk -F: -v b="$b" '$1>b{print $1; exit}')
if [ -z "$a" ] || [ -z "$m" ] || [ -z "$b" ] || [ -z "$e" ] || [ "$a" -ge "$m" ] || [ "$m" -ge "$b" ] || [ "$b" -ge "$e" ]; then
	echo "check_t30_fw_irq_gate: fw_ready order wrong (clear=$a isp_init=$m set=$b hw_enable=$e)"; fail=1
fi
[ $fail = 0 ] && echo "check_t30_fw_irq_gate: ok"
exit $fail
