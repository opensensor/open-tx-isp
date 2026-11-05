/* T32 OEM 0x978: private_filp_close; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_filp_close(struct file *filp, fl_owner_t id);
int private_filp_close(struct file *filp, fl_owner_t id)
{
    return filp_close(filp, id);
}
