/* T32 OEM 0xd4: private_clk_disable_unprepare; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_clk_disable_unprepare(struct clk *clk)
{
    clk_disable(clk);
    clk_unprepare(clk);
}
