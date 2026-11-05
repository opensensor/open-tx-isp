/* T32 OEM 0xc14: private_remove_proc_entry; recovery status: normalized_exact_match. */
#include "../compat.h"
/*
 * Tail-call thunk wrapper for remove_proc_entry().
 * Original binary: lui/addiu t9 to remove_proc_entry, jr t9, nop.
 */
void private_remove_proc_entry(const char *name, struct proc_dir_entry *parent)
{
	remove_proc_entry(name, parent);
}
