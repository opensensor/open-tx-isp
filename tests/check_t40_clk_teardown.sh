#!/bin/sh
# check_t40_clk_teardown.sh [driver/t40]   (Lu-Fi/openimp#152)
# Source guards for the T40 module-exit clock teardown (proven in QEMU: tests/t40_qemu/clk_reload_cycle.sh):
#  1. private_clk_prepare_enable counts a successful enable per clock name, private_clk_disable_unprepare
#     takes it back, so what the ISP/CSI activation (and the sensors' MCLK) left on is known;
#  2. tx_isp_t40_core_exit gates whatever is still counted (t40_clk_release_all) AFTER the last child
#     remove (exit steps, sensor i2c client) - the CSI remove still writes registers behind the ISP clocks.
d=${1:-$(dirname "$0")/../driver/t40}
f=$d/tx_isp_t40_recovered.c
[ -f "$f" ] || { echo "usage: $0 [driver/t40]" >&2; exit 2; }
fail=0
chk() { grep -q -- "$1" "$f" || { echo "check_t40_clk_teardown: missing: $2"; fail=1; }; }
chk 't40_clk_own_add((struct clk \*)arg1, 1);' 'enable counted'
chk 't40_clk_own_add((struct clk \*)a0, -1);' 'disable uncounted'
chk 'static void t40_clk_release_all(void)' 'release helper'
a=$(grep -n 'regtrace_core_exit_steps(REGTRACE_EXIT_STEPS, 0);' "$f" | tail -1 | cut -d: -f1)
b=$(grep -n '^    t40_clk_release_all();' "$f" | tail -1 | cut -d: -f1)
if [ -z "$a" ] || [ -z "$b" ] || [ "$a" -ge "$b" ]; then
	echo "check_t40_clk_teardown: t40_clk_release_all must run after the exit steps in tx_isp_t40_core_exit"; fail=1
fi
[ $fail = 0 ] && echo "check_t40_clk_teardown: ok"
exit $fail
