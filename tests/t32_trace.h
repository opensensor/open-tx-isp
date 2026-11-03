/* Host test helper: the vendor's AddSensor register writes from a local QEMU
 * trace (T32_ADD_TRACE, lines "W <block> ISP_AddSensor <addr> = <value>"),
 * and a full-sequence match of a module's computed writes against it. The
 * vendor data stays outside the repository. */
#ifndef T32_TRACE_H
#define T32_TRACE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tr_w { unsigned int reg, val; unsigned char hit; };
static struct tr_w *tr;
static unsigned int tr_n;

static int tr_load(const char *path)
{
	FILE *f = path ? fopen(path, "r") : NULL;
	char line[256], blk[32], ph[32];
	unsigned int a, v, cap = 8192;

	if (!f)
		return 0;
	tr = calloc(cap, sizeof(*tr));
	while (fgets(line, sizeof(line), f)) {
		if (line[0] != 'W' || sscanf(line, "W %31s %31s %x = %x", blk, ph, &a, &v) != 4)
			continue;
		if (strcmp(ph, "ISP_AddSensor") || !(!strncmp(blk, "CORE_", 5) || !strcmp(blk, "AE") ||
		    !strcmp(blk, "AWB") || !strcmp(blk, "MSCA")))
			continue;
		if (tr_n == cap)
			tr = realloc(tr, (cap *= 2) * sizeof(*tr));
		tr[tr_n].reg = a;
		tr[tr_n].val = v;
		tr[tr_n++].hit = 0;
	}
	fclose(f);
	return tr_n;
}

/* index of the first window equal to all n writes, -1 if none */
static int tr_find(const unsigned int *reg, const unsigned int *val, unsigned int n)
{
	unsigned int i, j;

	for (i = 0; i + n <= tr_n; i++) {
		for (j = 0; j < n && tr[i + j].reg == reg[j] && tr[i + j].val == val[j]; j++)
			;
		if (j == n)
			return (int)i;
	}
	return -1;
}

#endif
