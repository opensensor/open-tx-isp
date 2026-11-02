/* Host test of driver/t23/tx_isp_t23_core_ioctl.h (T23 ispcore_core_ops_ioctl event walk, Lu-Fi/openimp#189). */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint32_t u32;
#include "../driver/t23/tx_isp_t23_core_ioctl.h"

#define PS sizeof(void *)

struct sdbuf { unsigned char b[0x100]; };  /* sd: +0x38 table (16 slots), +0xc4 ops */

static void setp(void *base, unsigned long off, void *v) { memcpy((char *)base + off, &v, sizeof v); }

static void *calls_sd[40];
static void *calls_arg[40];
static int ncalls;
static int ret_for[40];

static int handler(void *sd, void *arg)
{
	int idx = ncalls;

	calls_sd[ncalls] = sd;
	calls_arg[ncalls++] = arg;
	return ret_for[idx];
}

/* ops -> { core table, ?, ?, sensor table }, tables [0, fn] */
static void mk(struct sdbuf *sd, void *ops, void *coretbl, void *senstbl, t23_core_ioctl_fn core_fn, t23_core_ioctl_fn sens_fn)
{
	setp(sd, 0xc4, ops);
	setp(ops, 0, coretbl);
	setp(ops, 3 * PS, senstbl);
	setp(coretbl, PS, (void *)core_fn);
	setp(senstbl, PS, (void *)sens_fn);
}

int main(void)
{
	static struct sdbuf core, c1, c2, c3;
	static void *opsm[8], *opsa[8], *opsb[8], *opsc[8], *tm[2][4], *ta[2][4], *tb[2][4], *tc[2][4];
	static void *val = (void *)0x1234;
	int own;

	memset(opsm, 0, sizeof opsm);
	mk(&core, opsm, tm[0], tm[1], handler, handler);
	mk(&c1, opsa, ta[0], ta[1], handler, handler);
	mk(&c2, opsb, tb[0], tb[1], NULL, NULL);     /* no handler: -515, skipped */
	mk(&c3, opsc, tc[0], tc[1], handler, handler);
	/* children in slots 0, 2 (slot 1 NULL), 5; the stride is the pointer size, not 4 * sizeof */
	setp(&core, 0x38 + 0 * PS, &c1);
	setp(&core, 0x38 + 2 * PS, &c2);
	setp(&core, 0x38 + 5 * PS, &c3);

	/* 0x1000000: core init; the handler gets *arg (the value), own sd first, then the children in slot order */
	ncalls = 0; memset(ret_for, 0, sizeof ret_for);
	assert(t23_core_ioctl(&core, 0x1000000, &val, &own) == 0 && !own);
	assert(ncalls == 3);
	assert(calls_sd[0] == &core && calls_sd[1] == &c1 && calls_sd[2] == &c3);
	assert(calls_arg[0] == val && calls_arg[1] == val && calls_arg[2] == val);

	/* 0x1000001: sync sensor attr; the handler gets arg itself */
	ncalls = 0;
	assert(t23_core_ioctl(&core, 0x1000001, &c3, &own) == 0 && !own);
	assert(ncalls == 3 && calls_arg[0] == &c3 && calls_arg[2] == &c3);

	/* a child error ends the walk and is returned (not logged as own failure) */
	ncalls = 0; ret_for[1] = -22;
	assert(t23_core_ioctl(&core, 0x1000001, &c3, &own) == -22 && !own);
	assert(ncalls == 2);
	/* child result -515 is no error */
	ncalls = 0; ret_for[1] = -515;
	assert(t23_core_ioctl(&core, 0x1000001, &c3, &own) == 0 && ncalls == 3);

	/* own error: logged, children not called */
	ncalls = 0; memset(ret_for, 0, sizeof ret_for); ret_for[0] = -5;
	assert(t23_core_ioctl(&core, 0x1000000, &val, &own) == -5 && own && ncalls == 1);
	/* own -515 (no handler) is no error, the children still run */
	ncalls = 0; memset(ret_for, 0, sizeof ret_for);
	setp(tm[0], PS, NULL);
	assert(t23_core_ioctl(&core, 0x1000000, &val, &own) == 0 && !own && ncalls == 2);
	setp(tm[0], PS, (void *)handler);

	/* NULL sd: -ENODEV logged; other commands: nothing */
	assert(t23_core_ioctl(NULL, 0x1000000, &val, &own) == -19 && own);
	ncalls = 0;
	assert(t23_core_ioctl(&core, 0x1000002, &val, &own) == 0 && !own && ncalls == 0);
	assert(t23_core_ioctl(NULL, 0x4000000, &val, &own) == 0 && !own);

	/* NULL ops of a child is skipped like a missing handler */
	setp(&c1, 0xc4, NULL);
	ncalls = 0;
	assert(t23_core_ioctl(&core, 0x1000001, &c3, &own) == 0 && ncalls == 2);

	printf("tx_isp_t23_core_ioctl_test: ok\n");
	return 0;
}
