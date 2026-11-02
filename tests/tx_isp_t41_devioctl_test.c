#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "../driver/t41/tx_isp_t41_devioctl.h"

int main(void)
{
	uint8_t b = 0xee;
	uint32_t c;

	assert(t41_night_start_word(0) == 0);
	assert(t41_night_start_word(2) == 2);
	assert(t41_night_start_word(3) == -EINVAL);
	assert(t41_night_start_word(0xffffffffU) == -EINVAL);

	assert(t41_wdr_open_mode(0, &b) == -EFAULT && b == 0xee);
	assert(t41_wdr_open_mode(1, &b) == 0 && b == 1);
	assert(t41_wdr_open_mode(2, &b) == 0 && b == 2);
	assert(t41_wdr_open_mode(0x1ff, &b) == 0 && b == 0xff);

	for (c = 0xc0045470U; c < 0xc0045490U; c++) {
		int want = (c >= 0xc0045479U && c <= 0xc004547bU) ||
			   c == 0xc004548eU || c == 0xc004548fU;
		assert(t41_devioctl_is_vendor_noop(c) == want);
	}
	assert(!t41_devioctl_is_vendor_noop(0xc004548dU));
	assert(!t41_devioctl_is_vendor_noop(0xc004542eU));
	puts("tx_isp_t41_devioctl_test: ok");
	return 0;
}
