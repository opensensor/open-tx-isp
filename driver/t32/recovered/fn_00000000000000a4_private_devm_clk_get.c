/* T32 OEM 0xa4: private_devm_clk_get; recovery status: normalized_exact_match. */
#include "../compat.h"
struct clk *private_devm_clk_get(struct device *dev, const char *id);
struct clk *private_devm_clk_get(struct device *dev, const char *id)
{
    return devm_clk_get(dev, id);
}
