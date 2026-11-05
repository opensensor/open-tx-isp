/* T32 OEM 0x968: private_filp_open; recovery status: normalized_exact_match. */
#include "../compat.h"
struct file *private_filp_open(const char *filename, int flags, umode_t mode);
struct file *private_filp_open(const char *filename, int flags, umode_t mode)
{
    return filp_open(filename, flags, mode);
}
