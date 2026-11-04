#!/bin/sh
# check_t30_ae_gain.sh [driver/t30]   (Lu-Fi/openimp#202)
# Source guards for the T30 compact AE -> sensor gain fixes (host test: t30_ae_gain_host_test):
#  1. apical_fw_init clears the compact 3A state together with the OEM firmware state, so the
#     analog gain is posted again after the sensor init table reset the sensor to 1x;
#  2. the anti-flicker tuning control sets item 13 and the compact AE reads the frequency
#     only through t30_ae_antiflicker_hz (item 13 gate);
#  3. the automatic analog gain request is capped by item 29, the integration time by item 26.
d=${1:-$(dirname "$0")/../driver/t30}
f=$d/tx_isp_t30_recovered.c
[ -f "$f" ] || { echo "usage: $0 [driver/t30]" >&2; exit 2; }
fail=0
chk() { grep -q -- "$1" "$f" || { echo "check_t30_ae_gain: missing: $2"; fail=1; }; }
s=$(grep -n '^int32_t apical_fw_init(int32_t \*arg1)$' "$f" | cut -d: -f1)
e=$(awk -v s="$s" 'NR>s && /^}/ {print NR; exit}' "$f")
r=$(grep -n 'memset(&tx_isp_t30_simple_3a, 0, sizeof(tx_isp_t30_simple_3a));' "$f" | awk -F: -v s="$s" -v e="$e" '$1>s && $1<e {print $1; exit}')
[ -n "$r" ] || { echo "check_t30_ae_gain: compact 3A not cleared in apical_fw_init"; fail=1; }
chk 'stab\[13\] = frequency_hz\[mode\] ? 1 : 0;' 'item 13 set by the anti-flicker control'
chk 'u32 frequency = t30_ae_antiflicker_hz(stab);' 'item 13 gate in the compact anti-flicker'
chk 't30_ae_auto_again_cap(stab, attr->max_again)' 'item 29 analog gain cap'
chk 'max_integration = t30_ae_max_integration(stab, max_integration);' 'item 26 integration cap'
[ $fail = 0 ] && echo "check_t30_ae_gain: ok"
exit $fail
