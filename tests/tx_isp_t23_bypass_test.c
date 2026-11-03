/* Host test for the T23 bypass graph VIC bank ring (driver/t23/tx_isp_t23_bypass.h).
 * tests/t23_bypass_host.sh builds it against mutated copies of the header
 * (BYPASS_H) and every mutation must make it fail. */
#include <stdio.h>
#include <string.h>

#ifndef BYPASS_H
#define BYPASS_H "../driver/t23/tx_isp_t23_bypass.h"
#endif
#include BYPASS_H

static int failures;

#define CHECK(cond) do { \
	if (!(cond)) { \
		fprintf(stderr, "%s:%d: CHECK(%s) failed\n", __FILE__, __LINE__, #cond); \
		failures++; \
	} \
} while (0)

#define A(n) (0x1000000U + (n) * 0x1c2000U)

static void init_rings(struct t23_bp_ring *r)
{
	memset(r, 0xee, sizeof(*r));	/* init must not depend on the old state */
	t23_bp_init(r);
}

int main(void)
{
	struct t23_bp_ring r;
	struct t23_bp_load ld, lds[T23_BP_BANKS];
	u32 out[8];
	int nl, n, i;

	memset(&ld, 0, sizeof(ld));
	memset(lds, 0, sizeof(lds));

	/* vendor sample: two buffers, then STREAMON */
	init_rings(&r);
	CHECK(r.free_n == 5 && r.busy_n == 0 && r.q_n == 0 && !r.streaming);
	CHECK(t23_bp_qbuf(&r, 0, &ld) == -1);
	CHECK(t23_bp_qbuf(&r, A(0), &ld) == 1 && ld.bank == 0 && ld.addr == A(0));
	CHECK(t23_bp_qbuf(&r, A(1), &ld) == 1 && ld.bank == 1 && ld.addr == A(1));
	CHECK(t23_bp_pending(&r) == 2);
	CHECK(t23_bp_start(&r) == 2);
	CHECK(r.streaming);
	/* the other three banks are next in line, in index order */
	CHECK(r.free_n == 3 && r.free_q[0] == 2 && r.free_q[1] == 3 && r.free_q[2] == 4);

	/* frame 0 done: head completes, bank 0 free, nothing waiting */
	n = t23_bp_done(&r, A(0), out, 8, lds, &nl);
	CHECK(n == 1 && out[0] == A(0) && nl == 0);
	CHECK(r.busy_n == 1 && r.free_n == 4 && t23_bp_pending(&r) == 1);
	/* the app returns the buffer: it takes the bank the hardware reaches next (2) */
	CHECK(t23_bp_qbuf(&r, A(0), &ld) == 1 && ld.bank == 2 && ld.addr == A(0));
	CHECK(t23_bp_pending(&r) == 2);
	n = t23_bp_done(&r, A(1), out, 8, lds, &nl);
	CHECK(n == 1 && out[0] == A(1) && nl == 0);
	CHECK(t23_bp_qbuf(&r, A(1), &ld) == 1 && ld.bank == 3);
	n = t23_bp_done(&r, A(0), out, 8, lds, &nl);
	CHECK(n == 1 && out[0] == A(0));
	/* the engine ran dry (count 0) and the app queues again: next bank in line (4) */
	n = t23_bp_done(&r, A(1), out, 8, lds, &nl);
	CHECK(n == 1 && out[0] == A(1) && t23_bp_pending(&r) == 0);
	CHECK(t23_bp_qbuf(&r, A(5), &ld) == 1 && ld.bank == 4);
	CHECK(t23_bp_qbuf(&r, A(6), &ld) == 1 && ld.bank == 0);	/* wraps */
	CHECK(t23_bp_pending(&r) == 2);

	/* lost interrupt: cur names the second loaded bank, both complete */
	init_rings(&r);
	for (i = 0; i < 3; i++)
		CHECK(t23_bp_qbuf(&r, A(i), &ld) == 1);
	CHECK(t23_bp_start(&r) == 3);
	n = t23_bp_done(&r, A(1), out, 8, lds, &nl);
	CHECK(n == 2 && out[0] == A(0) && out[1] == A(1));
	CHECK(r.busy_n == 1 && r.free_n == 4);
	CHECK(r.bad_addr == 0 && r.delivered == 2);

	/* done with an address no bank holds: the head is still completed once
	 * per loop pass, the rest is counted as bad; no buffer is lost */
	init_rings(&r);
	for (i = 0; i < 2; i++)
		t23_bp_qbuf(&r, A(i), &ld);
	t23_bp_start(&r);
	n = t23_bp_done(&r, 0xdeadbee8U, out, 8, lds, &nl);
	CHECK(n == 2 && out[0] == A(0) && out[1] == A(1));
	CHECK(r.bad_addr == 1 && r.busy_n == 0 && r.free_n == 5);

	/* more buffers than banks: the rest waits and is loaded as banks free up */
	init_rings(&r);
	for (i = 0; i < 5; i++)
		CHECK(t23_bp_qbuf(&r, A(i), &ld) == 1);
	CHECK(t23_bp_qbuf(&r, A(5), &ld) == 0);
	CHECK(t23_bp_qbuf(&r, A(6), &ld) == 0);
	CHECK(r.q_n == 2 && r.free_n == 0);
	CHECK(t23_bp_start(&r) == 5);
	n = t23_bp_done(&r, A(0), out, 8, lds, &nl);
	CHECK(n == 1 && out[0] == A(0));
	CHECK(nl == 1 && lds[0].addr == A(5) && lds[0].bank == 0);	/* oldest waiting first */
	n = t23_bp_done(&r, A(1), out, 8, lds, &nl);
	CHECK(n == 1 && nl == 1 && lds[0].addr == A(6) && lds[0].bank == 1);
	CHECK(r.q_n == 0 && r.busy_n == 5);

	/* a new buffer never overtakes a waiting one */
	init_rings(&r);
	for (i = 0; i < 5; i++)
		t23_bp_qbuf(&r, A(i), &ld);
	t23_bp_qbuf(&r, A(5), &ld);
	t23_bp_start(&r);
	t23_bp_done(&r, A(0), out, 8, lds, &nl);	/* A(5) takes bank 0 */
	CHECK(r.q_n == 0);
	t23_bp_done(&r, A(1), out, 8, lds, &nl);	/* nothing waits: bank 1 free */
	CHECK(r.free_n == 1);
	t23_bp_qbuf(&r, A(7), &ld);
	CHECK(ld.bank == 1);

	/* queue limit */
	init_rings(&r);
	for (i = 0; i < T23_BP_BANKS; i++)
		t23_bp_qbuf(&r, A(i), &ld);
	for (i = 0; i < T23_BP_QUEUE; i++)
		CHECK(t23_bp_qbuf(&r, A(100 + i), &ld) == 0);
	CHECK(t23_bp_qbuf(&r, A(200), &ld) == -1);
	/* the queue wraps without losing the order */
	t23_bp_start(&r);
	for (i = 0; i < 40; i++) {
		u32 expect = i < T23_BP_BANKS ? A(i) : A(100 + i - T23_BP_BANKS);
		u32 cur = expect;

		if (i >= T23_BP_BANKS + T23_BP_QUEUE) {
			/* the rest of the ring: only the loaded banks remain */
			if (!r.busy_n)
				break;
			cur = r.bank_addr[r.busy_q[0]];
			expect = cur;
		}
		n = t23_bp_done(&r, cur, out, 8, lds, &nl);
		CHECK(n == 1 && out[0] == expect);
	}
	CHECK(r.q_n == 0 && r.busy_n == 0);

	/* STREAMON without a buffer: no stream */
	init_rings(&r);
	CHECK(t23_bp_start(&r) == 0 && !r.streaming);
	/* done while not streaming: nothing */
	t23_bp_qbuf(&r, A(0), &ld);
	n = t23_bp_done(&r, A(0), out, 8, lds, &nl);
	CHECK(n == 0 && nl == 0 && r.busy_n == 1);

	/* a frame on a free bank has no owner: nothing completes (defensive: the capture
	 * count normally stops the engine before it reaches one) */
	init_rings(&r);
	t23_bp_qbuf(&r, A(0), &ld);
	t23_bp_qbuf(&r, A(1), &ld);
	t23_bp_start(&r);
	t23_bp_done(&r, A(0), out, 8, lds, &nl);	/* bank 0 free, stale A(0) */
	n = t23_bp_done(&r, A(0), out, 8, lds, &nl);	/* hardware wrote bank 0 again */
	CHECK(n == 0 && r.stale == 1 && r.busy_n == 1);
	n = t23_bp_done(&r, A(1), out, 8, lds, &nl);
	CHECK(n == 1 && out[0] == A(1));

	/* clear forgets everything */
	t23_bp_qbuf(&r, A(3), &ld);
	t23_bp_clear(&r);
	CHECK(r.free_n == 5 && r.busy_n == 0 && r.q_n == 0 && !r.streaming);

	if (failures) {
		fprintf(stderr, "tx_isp_t23_bypass_test: %d failures\n", failures);
		return 1;
	}
	printf("tx_isp_t23_bypass_test: ok\n");
	return 0;
}
