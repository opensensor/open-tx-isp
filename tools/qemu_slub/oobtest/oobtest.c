// SPDX-License-Identifier: GPL-2.0
// Throwaway test module: provokes the slab bugs that slub_debug=FZPU is expected to catch.
// insmod oobtest.ko mode=N   (1 = write past the object, 2 = use-after-free write,
//                             3 = double free, 4 = write before the object, 5 = clean alloc/free,
//                             6 = write into a freed page: needs DEBUG_PAGEALLOC + debug_pagealloc=on)
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/gfp.h>
static int mode;
static int size = 128;
module_param(mode, int, 0);
module_param(size, int, 0);
static int __init oob_init(void)
{
	volatile u8 *p = kmalloc(size, GFP_KERNEL);
	if (!p) return -ENOMEM;
	switch (mode) {
	case 1: p[size] = 0xAA; p[size + 1] = 0xBB; kfree((void *)p); break;           /* right red zone */
	case 2: kfree((void *)p); p[8] = 0x42; p = kmalloc(size, GFP_KERNEL); kfree((void *)p); break; /* UAF write -> poison check on re-alloc */
	case 3: kfree((void *)p); kfree((void *)p); break;
	case 4: p[-1] = 0x11; kfree((void *)p); break;                          /* left red zone */
	case 6: { unsigned long pg = __get_free_page(GFP_KERNEL); kfree((void *)p); free_page(pg); *(volatile u32 *)(pg + 64) = 0xdeadbeef;
		  pg = __get_free_page(GFP_KERNEL); free_page(pg); (void)__get_free_pages(GFP_KERNEL, 0); return -EAGAIN; }
	default: kfree((void *)p); break;
	}
	pr_info("oobtest: mode %d done\n", mode);
	return -EAGAIN; /* do not stay loaded */
}
module_init(oob_init);
MODULE_LICENSE("GPL");
