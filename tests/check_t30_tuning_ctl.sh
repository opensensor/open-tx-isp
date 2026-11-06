#!/bin/sh
# check_t30_tuning_ctl.sh [driver/t30]  (Lu-Fi/openimp#177)
# Regression guard for the T30 tuning controls: (1) host test of the arithmetic and id
# mappings with a mutation check, (2) every control id the lifted switch had lost has a
# get and/or set arm in tx_isp_t30_tuning_ctl.h, (3) the tuning ioctl calls the handlers
# before the lifted switch, (4) the lifted fixes that came with it stay in (sensor fps
# callback read as a pointer, calibration type 6).
d=${1:-$(dirname "$0")/../driver/t30}; t=$(dirname "$0")
h=$d/tx_isp_t30_tuning_math.h; c=$d/tx_isp_t30_tuning_ctl.h; r=$d/tx_isp_t30_recovered.c
src=$t/t30_tuning_ctl_host_test.c
[ -f "$h" ] && [ -f "$c" ] && [ -f "$r" ] || { echo "usage: $0 [driver/t30]" >&2; exit 2; }
CC=${CC:-cc}; W=$(mktemp -d); trap 'rm -rf "$W"' EXIT
run() { $CC -std=c99 -Wall -Wextra -Werror -DTUNING_MATH_HDR="\"$1\"" -o "$W/t" "$src" && "$W/t" >"$W/out" 2>&1; }
run "$h" || { echo "check_t30_tuning_ctl: FAIL"; head -20 "$W/out"; exit 1; }
cat "$W/out"
fail=0
mut() {
	sed "$2" "$h" > "$W/m.h"
	cmp -s "$h" "$W/m.h" && { echo "check_t30_tuning_ctl: mutation $1 did not apply"; fail=1; return; }
	if run "$W/m.h"; then echo "check_t30_tuning_ctl: mutation $1 NOT detected"; fail=1; else echo "check_t30_tuning_ctl: mutation $1 detected"; fi
}
mut fps-table 's/{ 5, 15, 25, 30, 50, 60 }/{ 5, 10, 15, 20, 25, 30 }/'
mut mid-node 's/mid + (0xff - mid) \* (value - 128) \/ 128/mid + (0xff - mid) * (value - 127) \/ 128/'
mut contrast-end 's/x1 = x2 = i - 1;/x1 = x2 = i;/'
mut contrast-lerp 's/(gx2 - gx1);/(gx2 - gx1) + 1;/'
mut wb-base 's/0x32 + mode/0x33 + mode/'
mut strategy 's/return user ? 0x2a : 0x29;/return user ? 0x29 : 0x2a;/'
mut colorfx-sepia 's/case 2: return 0x52;/case 2: return 0x51;/'
mut expr-lines 's/\*lines = us \/ one_line_us;/*lines = us * one_line_us;/'
# arms present in the handlers (get/set)
for id in 0x08000001 0x08000004 0x08000005 0x08000006 0x08000007 0x08000008 0x08000022 0x08000023 0x08000024 \
	0x08000025 0x08000026 0x08000028 0x08000029 0x0800002a 0x0800002b 0x0800002d 0x0800002e \
	0x08000042 0x08000161 0x080000e0 0x080000e1 0x08000165 V4L2_CID_POWER_LINE_FREQUENCY \
	V4L2_CID_HFLIP V4L2_CID_VFLIP V4L2_CID_SCENE_MODE V4L2_CID_COLORFX V4L2_CID_SATURATION \
	V4L2_CID_BRIGHTNESS V4L2_CID_CONTRAST V4L2_CID_SHARPNESS; do
	n=$(grep -c "case $id:" "$c")
	[ "$n" -ge 1 ] || { echo "check_t30_tuning_ctl: no arm for $id"; fail=1; }
done
# getters that must exist (an id with only a set arm is how the cells went err)
for id in 0x08000001 0x08000004 0x08000005 0x08000006 0x08000007 0x08000008 0x08000022 0x08000023 0x08000024 \
	0x08000025 0x08000026 0x08000028 0x08000029 0x0800002a 0x0800002b 0x0800002d 0x0800002e \
	0x08000042 0x08000161 V4L2_CID_POWER_LINE_FREQUENCY V4L2_CID_SATURATION V4L2_CID_BRIGHTNESS; do
	a=$(awk '/^static int tx_isp_t30_tuning_ctl_get/{g=1} /^static int tx_isp_t30_tuning_ctl_set/{g=0} g&&/case '"$id"':/{n++} END{print n+0}' "$c")
	[ "$a" -ge 1 ] || { echo "check_t30_tuning_ctl: no getter arm for $id"; fail=1; }
done
# AWB_CWF_SHIFT has a setter arm (vendor apical_isp_awb_cwf_s_shift writes the light source table)
a=$(awk '/^static int tx_isp_t30_tuning_ctl_set/{g=1} g&&/case 0x08000001:/{n++} END{print n+0}' "$c")
[ "$a" -ge 1 ] || { echo "check_t30_tuning_ctl: no setter arm for 0x08000001"; fail=1; }
# the ioctl asks the handlers first, at all four sites
n=$(grep -c "tx_isp_t30_tuning_ctl_\(get\|set\)(" "$r")
[ "$n" -ge 4 ] || { echo "check_t30_tuning_ctl: tuning ioctl calls the handlers $n times (want 4)"; fail=1; }
# lifted fixes
grep -qF 'fn = *(sensor_fps_fn_t *)((uint8_t *)arg1 + 0xcc);' "$r" || { echo "check_t30_tuning_ctl: sensor fps callback not read as a pointer"; fail=1; }
grep -qF 'tctl_fps_by_id[arg2 - 6]' "$r" || { echo "check_t30_tuning_ctl: set_sensor_fps does not use the fps id table"; fail=1; }
awk '/^int32_t apical_command\(/{a=1} a&&/^\tcase 6:/{f=1} END{exit f?0:1}' "$r" || { echo "check_t30_tuning_ctl: apical_command has no calibration type 6"; fail=1; }
[ $fail = 0 ] && echo "check_t30_tuning_ctl: ok (8/8 mutations detected, arms and dispatch present)"
exit $fail
