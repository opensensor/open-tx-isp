#!/bin/sh
# check_t41_af_gate.sh   (#179)
#
# The T41 AF statistics block (IRQ bit 6 + 4 x 4 KB DMA ring) must stay off
# unless t41_af=1 is given at load time:
#  - t41_af has no initializer (default 0),
#  - bit 6 stays in the default-masked IRQ word,
#  - tisp_af_init keeps writing 0x1a000 = 0 when t41_af_start() refuses,
#  - tisp_deinit and tisp_af_deinit disarm before the buffers are freed,
#  - both queries answer -EPERM while the block is off,
#  - the AF code uses no hard-coded .data/.bss anchors of the lifted code.
# Exit 0 = ok, 1 = violation.
D=$(dirname "$0")/../driver/t41
R=$D/tx_isp_t41_recovered.c
I=$D/tx_isp_t41_af_runtime.inc
H=$D/tx_isp_t41_af.h
fail=0
no() { echo "check_t41_af_gate: $*"; fail=1; }

grep -q '^static int t41_af __attribute__((section(".data")));' "$I" || no "t41_af must default to 0 (no initializer)"
grep -q '^#define T41_ISR_G0_UNUSED[[:space:]]*BIT(6)' "$R" || no "IRQ bit 6 no longer masked by default"
awk '/^int32_t tisp_af_init\(/,/^}/' "$R" | tr -d '\n' | grep -q 'if (!t41_af_start(a0, info))        return 0;    system_reg_write(0x1a000, 0);' \
	|| no "tisp_af_init: disabled path must write 0x1a000 = 0 when t41_af_start() refuses"
awk '/^int32_t tisp_af_deinit\(/,/^}/' "$R" | awk '/t41_af_stop\(\)/{s=NR} /private_kfree/{if(!k)k=NR} END{exit !(s && k && s<k)}' \
	|| no "tisp_af_deinit: t41_af_stop() must run before the first private_kfree"
awk '/t41_af_stop\(\);/{if(!s)s=NR} /system_reg_write\(0x1a0dc, 0\);/{if(!d)d=NR} END{exit !(s && d && s<d)}' "$R" \
	|| no "tisp_deinit: t41_af_stop() must precede the AF DMA disable"
[ "$(grep -c 'return -EPERM;\|ret = -EPERM;' "$I")" -ge 2 ] || no "AF queries must answer -EPERM while off"
grep -q 'if (i == 0 && READ_ONCE(t41_af_live))' "$R" || no "IRQ bit 6 must follow t41_af_live"
if grep -nE '&(sclk_name|ivdc_threshold_line|_cb_base|tevent_info)|0x[0-9a-f]{5,} *\+ *&' "$I" "$H"; then
	no "hard-coded anchor in the AF code"
fi
[ $fail -eq 0 ] && echo "check_t41_af_gate: ok"
exit $fail
