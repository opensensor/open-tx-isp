/* T32 OEM 0x15434: sensor_start_changes; recovery status: normalized_exact_match. */
#include "../compat.h"
/*
 * sensor_start_changes - sensor start notification hook.
 *
 * This ISP function is an empty stub in the original binary: it contains
 * only a return instruction (jr ra / nop) and performs no work.
 */
void sensor_start_changes(void)
{
	/* no-op: nothing to do on sensor start change */
}
