/* T32 OEM 0x124: private_devm_clk_put; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_devm_clk_put(struct device *dev, struct clk *clk);
void private_devm_clk_put(struct device *dev, struct clk *clk)
{
    devm_clk_put(dev, clk);
}
