#!/bin/sh
# check_t40_custom_algo_wake.sh [driver/t40]   (Lu-Fi/openimp#65)
# Source guard: the user-space AE/AWB algorithm workers (ioctl get 0xc004541b / 0xc0045423) sleep on ae_algo_comp / awb_algo_comp.
# Vendor wake-ups: tisp_ae_main_process ends with complete(ae_algo_comp) when ta_custom_en == 1 (here: the AE histogram IRQ, event 1 is
# not pushed), tisp_awb_main_process completes awb_algo_comp when the custom-AWB array is 1.  The translated AWB chain must read the
# SAME array tisp_awb_algo_init writes (awb_algo_enable), not a private copy; the own exposure loop must stand still while a custom AE runs.
d=${1:-$(dirname "$0")/../driver/t40}
f=$d/tx_isp_t40_recovered.c
v=$d/tx_isp_t40_vawb.h
[ -f "$f" ] && [ -f "$v" ] || { echo "usage: $0 [driver/t40]" >&2; exit 2; }
fail=0
grep -q '^#define vawb_tawb_custom_en ((u32 \*)awb_algo_enable)' "$v" || { echo "check_t40_custom_algo_wake: vawb_tawb_custom_en must alias awb_algo_enable"; fail=1; }
grep -q 'READ_ONCE(ta_custom_en\[0\]) == 1' "$f" && grep -q 'private_complete((uintptr_t)&ae_algo_comp\[0\])' "$f" || { echo "check_t40_custom_algo_wake: AE hist IRQ must complete ae_algo_comp[0] when ta_custom_en[0] == 1"; fail=1; }
grep -q 'regtrace_enable_ae_sensor_apply && READ_ONCE(ta_custom_en\[0\]) != 1' "$f" || { echo "check_t40_custom_algo_wake: the own exposure loop must be skipped while a custom AE is registered"; fail=1; }
grep -q 'attr = t40_ae_algo_attr(core, ch);' "$f" && grep -q 'attr = (char \*)t40_ae_algo_attr' "$f" || { echo "check_t40_custom_algo_wake: AE open / get-handle must resolve the sensor attribute through t40_ae_algo_attr (NULL core copy before the first stream)"; fail=1; }
[ $fail = 0 ] && echo "check_t40_custom_algo_wake: ok"
exit $fail
