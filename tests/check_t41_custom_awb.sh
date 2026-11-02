#!/bin/sh
# check_t41_custom_awb.sh [driver/t41]   (Lu-Fi/openimp#195)
# Source guard for the custom AWB algorithm library path (IMP_ISP_SetAwbAlgoFunc on T41, an extra beyond the vendor): the dispatcher routes
# 0xc0045423..0xc0045426 to t41_ioctl_awb_algo, the native AWB frame work wakes the library once per processed frame, the release of the
# registering file unregisters it, the result uses the manual-gain control plane and the close restores the application's white balance.
d=${1:-$(dirname "$0")/../driver/t41}
f=$d/tx_isp_t41_recovered.c
a=$d/tx_isp_t41_awb_algo.h
r=$d/tx_isp_t41_awb_runtime.inc
[ -f "$f" ] && [ -f "$a" ] && [ -f "$r" ] || { echo "usage: $0 [driver/t41]" >&2; exit 2; }
fail=0
grep -q 'a1 >= 0xc0045423U && a1 <= 0xc0045426U' "$f" && grep -q 'regtrace_ret = t41_ioctl_awb_algo(a0, a1, a2);' "$f" || { echo "check_t41_custom_awb: tx_isp_unlocked_ioctl must route 0xc0045423..0xc0045426 to t41_ioctl_awb_algo"; fail=1; }
grep -q '#include "tx_isp_t41_awb_algo.h"' "$f" || { echo "check_t41_custom_awb: tx_isp_t41_awb_algo.h is not included"; fail=1; }
awk '/^static void t41_native_awb_workfn\(/,/^}/' "$r" | grep -q 't41_awb_algo_wake();' || { echo "check_t41_custom_awb: the native AWB frame work must call t41_awb_algo_wake()"; fail=1; }
awk '/^int32_t tx_isp_release\(uint32_t a0, uintptr_t a1\)$/,/^}/' "$f" | head -8 | grep -q 't41_awb_algo_release(a1);' || { echo "check_t41_custom_awb: tx_isp_release must call t41_awb_algo_release (a crashed streamer must not leave a registered library)"; fail=1; }
grep -q 'case 0xc0045420U' "$a" "$f" && { echo "check_t41_custom_awb: the second-sensor handle 0xc0045420 does not exist in the stock T41 module (ENOTTY)"; fail=1; }
grep -q 't41_native_awb_compat(0, r, b, 0, NULL)' "$a" || { echo "check_t41_custom_awb: results must go through the SetWB control plane (t41_native_awb_compat, manual hardware gains)"; fail=1; }
grep -q 'READ_ONCE(t41_awb_last_rgain)' "$a" && grep -q 'T41_AWB_GLOBAL' "$a" && grep -q 'T41_AWB_ZONE' "$a" || { echo "check_t41_custom_awb: the info block must carry the current WB-register gains, the global and the zone statistics"; fail=1; }
grep -q 'T41_AWB_ALGO_GAIN_MIN	0x200U' "$a" && grep -q 'T41_AWB_ALGO_GAIN_MAX	0x1800U' "$a" || { echo "check_t41_custom_awb: result gains must stay in the SetWB range 0x200..0x1800"; fail=1; }
[ $fail = 0 ] && echo "check_t41_custom_awb: ok"
exit $fail
