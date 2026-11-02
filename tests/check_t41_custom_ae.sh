#!/bin/sh
# check_t41_custom_ae.sh [driver/t41]   (Lu-Fi/openimp#76)
# Source guard for the custom AE algorithm library path (IMP_ISP_SetAeAlgoFunc on T41): the stock dispatcher serves 0xc004541b..0xc004541e
# (get handle / set handle / open / close, ONE channel); the AWB ioctls 0xc0045423..26 and the second-sensor handle 0xc0045420 do not exist in the
# stock T41 module and must keep answering -ENOTTY; the AWB ioctls 0xc0045423..26 are served as an extra beyond the vendor since #195
# (check_t41_custom_awb.sh).  tisp_ae_algo_{init,handle,deinit_internal} are the translated chain (vae_*), the library is woken by the
# complete(ae_algo_comp) at the end of the translated tisp_ae_calc_process (vae_ta_custom_en), the close frees the info block once.
d=${1:-$(dirname "$0")/../driver/t41}
f=$d/tx_isp_t41_recovered.c
v=$d/tx_isp_t41_vae.h
g=$d/tx_isp_t41_vae_gen.inc
[ -f "$f" ] && [ -f "$v" ] && [ -f "$g" ] || { echo "usage: $0 [driver/t41]" >&2; exit 2; }
fail=0
grep -q 'a1 >= 0xc004541bU && a1 <= 0xc004541eU' "$f" && grep -q 'regtrace_ret = t41_ioctl_ae_algo(a0, a1, a2);' "$f" || { echo "check_t41_custom_ae: tx_isp_unlocked_ioctl must route 0xc004541b..0xc004541e to t41_ioctl_ae_algo"; fail=1; }
grep -q '0xc0045420' "$f" && { echo "check_t41_custom_ae: the second-sensor handle 0xc0045420 does not exist in the stock T41 module (-ENOTTY), do not route it"; fail=1; }
grep -q 'u64 noinline vae_tisp_ae_algo_init(' "$g" && grep -q 'u64 noinline vae_tisp_ae_algo_handle(' "$g" && grep -q 'u64 noinline vae_tisp_ae_algo_deinit_internal(' "$g" || { echo "check_t41_custom_ae: the translated tisp_ae_algo_* chain is missing from tx_isp_t41_vae_gen.inc (tools/t41_vae/gen.sh roots)"; fail=1; }
grep -q "'ta_custom_en': 'vae_ta_custom_en'" $(dirname "$0")/../tools/t41_vae/asm2c.py || { echo "check_t41_custom_ae: ta_custom_en must map to vae_ta_custom_en (the flag vae_tisp_ae_calc_process reads)"; fail=1; }
grep -q 'vae_tisp_ae_algo_init(ch, 1, (u32)(uintptr_t)u' "$v" || { echo "check_t41_custom_ae: open must run the translated tisp_ae_algo_init(ch, 1, ...)"; fail=1; }
grep -q 'vae_tisp_ae_algo_deinit_internal(u\[1\]' "$v" && grep -q 'vae_tisp_ae_algo_init(u\[1\], 0, 0' "$v" || { echo "check_t41_custom_ae: close must run tisp_ae_algo_deinit + tisp_ae_algo_init(ch, 0, 0)"; fail=1; }
grep -q 't41_ae_algo_info = NULL;' "$v" || { echo "check_t41_custom_ae: close must clear the info pointer (a second close freed it twice, #65 on T40)"; fail=1; }
grep -q 'vae_ta_custom_en\[channel\] ? (const unsigned char \*)(uintptr_t)info\[1\] + 8608' "$v" || { echo "check_t41_custom_ae: the realized exposure of a custom AE is the library's answer (AE state +8608..)"; fail=1; }
awk '/^static int t41_ae_algo_open\(/,/^}/' "$v" | grep -q 't41_vendor_ae <= 0' || { echo "check_t41_custom_ae: open must refuse the safe AE controller (no statistics event)"; fail=1; }
[ $fail = 0 ] && echo "check_t41_custom_ae: ok"
exit $fail
