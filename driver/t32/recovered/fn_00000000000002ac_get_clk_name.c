/* T32 OEM 0x2ac: get_clk_name; recovery status: diff_mismatch. */
#include "../compat.h"
static const char clk_names[15][5] __section(".data") = {
	{ 0 },
};

char const (*get_clk_name(void))[5]
{
	return &clk_names[12];
}
