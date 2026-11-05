/* T32 OEM 0x94: private_clk_get; recovery status: normalized_exact_match. */
#include "../compat.h"
struct clk *private_clk_get(struct device *dev, const char *id);
struct clk *private_clk_get(struct device *dev, const char *id)
{
    return clk_get(dev, id);
}
