/* T32 OEM 0xb94: private_set_current_state; recovery status: diff_mismatch. */
#include "../compat.h"
void private_set_current_state(unsigned int state);
void private_set_current_state(unsigned int state)
{
    set_current_state(state);
}
