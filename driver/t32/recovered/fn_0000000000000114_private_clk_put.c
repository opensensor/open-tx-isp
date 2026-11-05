/* T32 OEM 0x114: private_clk_put; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_clk_put(struct clk *clk);
void private_clk_put(struct clk *clk)
{
    clk_put(clk);
}
