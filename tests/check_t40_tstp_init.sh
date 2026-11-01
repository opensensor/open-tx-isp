#!/bin/sh
# check_t40_tstp_init.sh [driver/t40]   (Lu-Fi/openimp#150)
# Source guard: the kernel-build tisp_main_init shim must run the OEM tisp_tstp_main_init (zeroed block +
# tisp_tstp_reg_cfg(0)) after the block inits, so the pipeline-top block at ISP + 0x60000 reads 0 like the vendor.
d=${1:-$(dirname "$0")/../driver/t40}
f=$d/tx_isp_t40_recovered.c
[ -f "$f" ] || { echo "usage: $0 [driver/t40]" >&2; exit 2; }
fail=0
s=$(grep -n '^int64_t tisp_main_init(uintptr_t a0, uint32_t a1)$' "$f" | cut -d: -f1)
e=$(awk -v s="$s" 'NR>s && /^#else/ {print NR; exit}' "$f")
a=$(awk -v s="$s" -v e="$e" 'NR>s && NR<e && /regtrace_isp_block_init_once\("tisp_main_init"\)/ {print NR; exit}' "$f")
b=$(awk -v s="$s" -v e="$e" 'NR>s && NR<e && /^    subret = tisp_tstp_main_init\(\);/ {print NR; exit}' "$f")
c=$(awk -v s="$s" -v e="$e" 'NR>s && NR<e && /^    tisp_tstp_main_deinit\(\);/ {print NR; exit}' "$f")
if [ -z "$s" ] || [ -z "$a" ] || [ -z "$b" ] || [ -z "$c" ] || [ "$a" -ge "$c" ] || [ "$c" -ge "$b" ]; then
	echo "check_t40_tstp_init: tisp_main_init shim must call tisp_tstp_main_deinit + tisp_tstp_main_init after regtrace_isp_block_init_once"; fail=1
fi
[ $fail = 0 ] && echo "check_t40_tstp_init: ok"
exit $fail
