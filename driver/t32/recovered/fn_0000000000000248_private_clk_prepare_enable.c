/* T32 OEM 0x248: private_clk_prepare_enable; recovery status: diff_mismatch. */
#include "../compat.h"
int private_clk_prepare_enable(struct clk *clk)
{
    int ret;

    ret = clk_prepare(clk);
    if (ret)
        return ret;

    ret = clk_enable(clk);
    if (ret)
        clk_unprepare(clk);

    return ret;
}
