/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T23 ispcore_core_ops_ioctl (Lu-Fi/openimp#189).
 *
 * Events 0x1000000 (core init: core_ops[1](sd, *arg)) and 0x1000001 (sync sensor attr:
 * sensor_ops[1](sd, arg)) go to the ISP core sub-device itself and then to every
 * non-NULL entry of its table of 16 sub-device pointers at +0x38.  The lifted version
 * read the table through `uint32_t *` / `uintptr_t *` registers (`s1 + 56` stepped 224
 * bytes, `s2 += 4` stepped 16) and had no third argument at all (the argument pointer
 * was a zero local), so the walk read the wrong words and a real event dereferenced NULL.
 *
 * Result as the vendor libt23-firmware 1.3.0 module (ISVP-T23-1.3.0): -ENOIOCTLCMD (-515) from a
 * sub-device without a handler is not an error; the first other non-zero result ends the walk and is
 * returned; an error of the core sub-device itself is also logged ("Failed to ioctl!", the
 * caller does that via *own_failed).  Other commands do nothing and return 0.
 *
 * Offsets are the 32-bit target layout (sd + 0xc4 = ops, ops + 0 = core ops, ops + 0xc = sensor ops,
 * table slot [1]); the table strides use sizeof(void *) so the host test can use its own pointers.
 */
#ifndef TX_ISP_T23_CORE_IOCTL_H
#define TX_ISP_T23_CORE_IOCTL_H

#ifdef __KERNEL__
#include <linux/string.h>
#include <linux/types.h>
#else
#include <stddef.h>
#include <string.h>
#endif

#define T23_EV_CORE_INIT     0x1000000u
#define T23_EV_SYNC_SENSOR   0x1000001u
#define T23_SD_OPS_OFF       0xc4u
#define T23_SD_SUBMODS_OFF   0x38u
#define T23_SD_SUBMODS_N     16u
#define T23_ENOIOCTLCMD      (-515)
#define T23_EV_ENODEV        (-19)

typedef int (*t23_core_ioctl_fn)(void *sd, void *arg);

static inline void *t23_ci_ptr(const void *base, unsigned long off)
{
	void *p;

	memcpy(&p, (const char *)base + off, sizeof(p));
	return p;
}

/* one sub-device: -ENOIOCTLCMD without ops / table / handler, else the handler's result */
static inline int t23_core_ioctl_one(void *sd, u32 cmd, void *arg)
{
	void *ops = t23_ci_ptr(sd, T23_SD_OPS_OFF);
	void *tbl;
	t23_core_ioctl_fn fn;
	void *a;

	if (!ops)
		return T23_ENOIOCTLCMD;
	if (cmd == T23_EV_CORE_INIT) {
		tbl = t23_ci_ptr(ops, 0);
		a = arg ? t23_ci_ptr(arg, 0) : NULL;     /* the argument is the address of the value */
	} else {
		tbl = t23_ci_ptr(ops, 3 * sizeof(void *));
		a = arg;
	}
	if (!tbl)
		return T23_ENOIOCTLCMD;
	fn = (t23_core_ioctl_fn)t23_ci_ptr(tbl, sizeof(void *));
	if (!fn)
		return T23_ENOIOCTLCMD;
	return fn(sd, a);
}

static inline int t23_core_ioctl(void *sd, u32 cmd, void *arg, int *own_failed)
{
	unsigned int i;
	int r;

	*own_failed = 0;
	if (cmd != T23_EV_CORE_INIT && cmd != T23_EV_SYNC_SENSOR)
		return 0;
	if (!sd) {
		*own_failed = 1;
		return T23_EV_ENODEV;
	}
	r = t23_core_ioctl_one(sd, cmd, arg);
	if (r != 0 && r != T23_ENOIOCTLCMD) {
		*own_failed = 1;
		return r;
	}
	for (i = 0; i < T23_SD_SUBMODS_N; i++) {
		void *child = t23_ci_ptr(sd, T23_SD_SUBMODS_OFF + i * sizeof(void *));

		if (!child)
			continue;
		r = t23_core_ioctl_one(child, cmd, arg);
		if (r != 0 && r != T23_ENOIOCTLCMD)
			return r;
	}
	return 0;
}

#endif
