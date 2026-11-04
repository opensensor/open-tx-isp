#!/bin/sh
# check_t30_system_items.sh [driver/t30]
# Regression guard for the T30 APICAL system table accessors: every system_* item function of
# tx_isp_t30_recovered.c (apical_command type 1) must be the one-line t30_system_item() call on the
# vendor item offset and width (table from tx-isp-t30 H20190523a, xrefs of the stab items).  The
# lifted copies had lost the set arm of 21 of them (manual exposure/integration time/gains/AWB/
# saturation, limits, anti-flicker ...), see driver/t30/tx_isp_t30_system_item.h.
d=${1:-$(dirname "$0")/../driver/t30}; r=$d/tx_isp_t30_recovered.c
[ -f "$r" ] || { echo "usage: $0 [driver/t30]" >&2; exit 2; }
python3 - "$r" <<'PY' || { echo "check_t30_system_items: FAIL"; exit 1; }
import re, sys
exp = {
 'system_freeze_firmware': (0, 1), 'system_manual_exposure': (1, 1), 'system_manual_exposure_ratio': (2, 1),
 'system_manual_integration_time': (3, 1), 'system_manual_sensor_analog_gain': (4, 1),
 'system_manual_sensor_digital_gain': (5, 1), 'system_manual_isp_digital_gain': (6, 1),
 'system_manual_directional_sharpening': (7, 1), 'system_manual_un_directional_sharpening': (8, 1),
 'system_manual_iridix': (9, 1), 'system_manual_sinter': (10, 1), 'system_manual_temper': (11, 1),
 'system_manual_awb': (12, 1), 'system_slow_frame_rate_enable': (14, 1), 'system_manual_saturation': (15, 1),
 'system_manual_exposure_time': (16, 4), 'system_exposure_dark_target': (20, 1),
 'system_exposure_bright_target': (21, 1), 'system_exposure_ratio': (22, 1), 'system_max_exposure_ratio': (23, 1),
 'system_integration_time': (24, 2), 'system_max_integration_time': (26, 2), 'system_sensor_analog_gain': (28, 1),
 'system_max_sensor_analog_gain': (29, 1), 'system_sensor_digital_gain': (30, 1),
 'system_max_sensor_digital_gain': (31, 1), 'system_isp_digital_gain': (32, 1), 'system_max_isp_digital_gain': (33, 1),
 'system_directional_sharpening_target': (34, 1), 'system_maximum_directional_sharpening': (35, 1),
 'system_minimum_directional_sharpening': (36, 1), 'system_un_directional_sharpening_target': (37, 1),
 'system_maximum_un_directional_sharpening': (38, 1), 'system_minimum_un_directional_sharpening': (39, 1),
 'system_iridix_strength_target': (40, 1), 'system_maximum_iridix_strength': (41, 1),
 'system_minimum_iridix_strength': (42, 1), 'system_sinter_threshold_target': (43, 1),
 'system_maximum_sinter_strength': (44, 1), 'system_minimum_sinter_strength': (45, 1),
 'system_temper_threshold_target': (46, 1), 'system_maximum_temper_strength': (47, 1),
 'system_minimum_temper_strength': (48, 1), 'system_awb_red_gain': (49, 1), 'system_awb_blue_gain': (50, 1),
 'system_saturation_target': (51, 1), 'system_anti_flicker_frequency': (52, 1), 'system_ae_compensation': (53, 1),
 'system_calibrate_bad_pixels': (54, 1), 'system_dis_x': (56, 2), 'system_dis_y': (58, 2),
}
src = open(sys.argv[1]).read().split('\n')
seen = {}
bad = 0
for i, l in enumerate(src):
    m = re.match(r'^(?:int32_t|int)\s+(system_\w+)\(.*\)\s*$', l)
    if not m or m.group(1) not in exp:
        continue
    n = m.group(1)
    body = ' '.join(x.strip() for x in src[i + 1:i + 4])
    g = re.fullmatch(r'\{ return t30_system_item\(stab \+ (\d+), (\d+), \(u32\)arg2, \(u8\)arg3, \(int \*\)arg4\); \}', body)
    if not g or (int(g.group(1)), int(g.group(2))) != exp[n]:
        print("%s: not the vendor accessor %s: %s" % (n, exp[n], body[:90]))
        bad += 1
    seen[n] = 1
for n in exp:
    if n not in seen:
        print("%s: definition missing" % n)
        bad += 1
sys.exit(1 if bad else 0)
PY
echo "check_t30_system_items: PASS (51 vendor system table accessors)"
