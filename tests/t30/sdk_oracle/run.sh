#!/bin/sh
# T30 day/night table + system-table layout vs the Ingenic T30 SDK source (the vendor C of the ISP core).
# run.sh   (T30_SDK_DIR=<ingenic-sdk>/common/isp/t30, default: the pinned external/ingenic-sdk submodule; else SKIP)
# Checks, nothing is copied from the SDK (it is parsed and compiled at test time only):
#  1. tctl_dn_tables (driver/t30/tx_isp_t30_tuning_ctl.h): the 93 (firmware table index, calibration API id) pairs
#     of the day/night reload equal the 93 apical_api_calibration(SET) calls of the SDK
#     apical_isp_day_or_night_s_ctrl_internal, same order;
#  2. t30_stab_items (driver/t30/tx_isp_t30_stab.h): offset and width of the 52 system-table items equal
#     offsetof/sizeof of the SDK system_tab (60 bytes);
#  4. the 43 customer register fields (register + field width) by running the SDK register writers;
#  5. exec_oracle.py: SDK function bodies and driver functions executed on the same inputs (custom init, ...);
#  3. the stab[] indices written by the day/night reload name the SDK fields (35/36 max/min directional sharpening ...).
set -e
HERE=$(cd "$(dirname "$0")" && pwd)
SDK=${T30_SDK_DIR:-$HERE/../../../external/ingenic-sdk/common/isp/t30}
[ -r "$SDK/apical-isp/tx-isp-core-tuning.c" ] || { echo "t30_sdk_oracle: SKIP (no Ingenic T30 SDK source: set T30_SDK_DIR or init external/ingenic-sdk)"; [ -z "$T30_ORACLE_STRICT" ] || exit 1; exit 0; }
python3 -I "$HERE/oracle.py" "$SDK" "$HERE/../../../driver/t30"
# 5. executed differential checks (SDK function vs driver function, same register file + customer block)
python3 -I "$HERE/exec_oracle.py" "$SDK" "$HERE/../../../driver/t30"
# mutation self-test: each executed check must fail on a one-mask change of the driver text
for m in $(sed -n "s/^    if MUT == '\\([a-z_]*\\)'.*/\\1/p" "$HERE/exec_oracle.py"); do
	if T30_ORACLE_MUTATE=$m T30_ORACLE_CASES=40 python3 -I "$HERE/exec_oracle.py" "$SDK" "$HERE/../../../driver/t30" >/dev/null; then
		echo "t30_sdk_oracle: FAIL (mutation $m not detected)"; exit 1
	fi
	echo "mutation $m: detected"
done
