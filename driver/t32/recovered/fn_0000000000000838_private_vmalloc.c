/* T32 OEM 0x838: private_vmalloc; recovery status: diff_mismatch. */
#include "../compat.h"
void *private_vmalloc(unsigned long size);
void *private_vmalloc(unsigned long size)
{
    return vmalloc(size);
}
