#!/bin/sh
# check_t30_fmt5c.sh [driver/t30]  (Lu-Fi/openimp#178)
# Host test of the 0x5c format conversion with a mutation check: the test must fail when the
# header drops/shifts crop words, loses the type or the pix header, or when the extra pix words
# are overwritten on the way back; and the dispatch must route both 0x5c commands.
d=${1:-$(dirname "$0")/../driver/t30}; t=$(dirname "$0")
h=$d/tx_isp_t30_fmt5c.h; src=$t/t30_fmt5c_host_test.c
[ -f "$h" ] || { echo "usage: $0 [driver/t30]" >&2; exit 2; }
CC=${CC:-cc}; W=$(mktemp -d); trap 'rm -rf "$W"' EXIT
run() { $CC -std=c99 -Wall -Wextra -Werror -DFMT5C_HDR="\"$1\"" -o "$W/t" "$src" && "$W/t" >"$W/out" 2>&1; }
run "$h" || { echo "check_t30_fmt5c: FAIL"; cat "$W/out"; exit 1; }
cat "$W/out"
fail=0
mut() {
	sed "$2" "$h" > "$W/m.h"
	cmp -s "$h" "$W/m.h" && { echo "check_t30_fmt5c: mutation $1 did not apply"; fail=1; return; }
	if run "$W/m.h"; then echo "check_t30_fmt5c: mutation $1 NOT detected"; fail=1; else echo "check_t30_fmt5c: mutation $1 detected"; fi
}
mut crop-shift 's/o->crop_top = w->crop_top;/o->crop_top = w->crop_left;/'
mut scaler-lost 's/o->scaler_out_height = w->scaler_out_height;/o->scaler_out_height = 0;/'
mut type-lost 's/o->type = w->type;/o->type = 1;/'
mut back-size 's/w->sizeimage = o->sizeimage;/(void)0;/'
mut back-extras 's/w->rate_mask = o->rate_mask;/w->rate_mask = o->rate_mask; w->flags = 0;/'
mut layout 's/u32 flags, ycbcr_enc, quantization, xfer_func;/u32 flags, ycbcr_enc, quantization;/'
# the driver routes both 0x5c commands to the 5c handlers
f=$d/tx_isp_t30_recovered.c
for c in 'case TX_ISP_T30_FRAME_IOCTL_SET_FORMAT_5C:' 'case TX_ISP_T30_FRAME_IOCTL_GET_FORMAT_5C:' 'tx_isp_t30_frame_channel_set_format_5c(chan, arg)' 'tx_isp_t30_frame_channel_get_format_5c(chan, arg)'; do
	grep -qF -- "$c" "$f" || { echo "check_t30_fmt5c: missing in driver: $c"; fail=1; }
done
[ $fail = 0 ] && echo "check_t30_fmt5c: ok (6/6 mutations detected, dispatch present)"
exit $fail
