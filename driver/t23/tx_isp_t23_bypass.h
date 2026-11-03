/* SPDX-License-Identifier: GPL-2.0 */
#ifndef TX_ISP_T23_BYPASS_H
#define TX_ISP_T23_BYPASS_H

/*
 * Optional ISP bypass graph (link config 1, isp_bypass_graph=1): frame
 * channel 0 is fed by the VIC MDMA with the sensor's raw frames (RG12,
 * 2 bytes per pixel), they do not go through the ISP pipeline or the MSCA.
 *
 * The VIC MDMA writes into five banks in index order; bank n is the address
 * in VIC register 0x318 + 4 * n and the capture count (VIC register 0x300,
 * bits 16..19) says how many frames it may still write.  A buffer queued by
 * user space is loaded into the free bank that is next in line (free banks
 * are kept in the order the hardware reaches them); a frame-done interrupt completes
 * the oldest loaded bank (and, when VIC register 0x380 -- the address of
 * the frame just written -- names a later one, every bank up to it), and
 * the freed banks are reloaded from the waiting buffers.
 *
 * This header is the bookkeeping only (no register access), shared with the
 * host test tests/tx_isp_t23_bypass_test.c.  The driver writes the bank
 * registers named by the struct t23_bp_load entries the calls return.
 */

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
typedef uint32_t u32;
typedef uint8_t u8;
#endif

#define T23_BP_BANKS 5
#define T23_BP_QUEUE 16

struct t23_bp_load {
	u32 addr;		/* value to write ... */
	u8 bank;		/* ... into VIC register 0x318 + 4 * bank */
};

struct t23_bp_ring {
	u32 bank_addr[T23_BP_BANKS];
	u8 free_q[T23_BP_BANKS];	/* free bank ids, oldest first */
	u8 free_n;
	u8 busy_q[T23_BP_BANKS];	/* loaded bank ids, hardware order */
	u8 busy_n;
	u32 queue[T23_BP_QUEUE];	/* buffers waiting for a bank */
	u8 q_head;
	u8 q_n;
	u8 streaming;
	u32 delivered;
	u32 bad_addr;		/* done with an address no bank holds */
	u32 stale;		/* frames the hardware wrote to a free bank */
};

static inline void t23_bp_init(struct t23_bp_ring *r)
{
	u8 i;

	for (i = 0; i < sizeof(*r); i++)
		((u8 *)r)[i] = 0;
	for (i = 0; i < T23_BP_BANKS; i++)
		r->free_q[i] = i;
	r->free_n = T23_BP_BANKS;
}

static inline void t23_bp_free_push(struct t23_bp_ring *r, u8 bank)
{
	r->free_q[r->free_n++] = bank;
}

static inline u8 t23_bp_free_pop(struct t23_bp_ring *r)
{
	u8 bank = r->free_q[0];
	u8 i;

	for (i = 1; i < r->free_n; i++)
		r->free_q[i - 1] = r->free_q[i];
	r->free_n--;
	return bank;
}

static inline u8 t23_bp_busy_pop(struct t23_bp_ring *r)
{
	u8 bank = r->busy_q[0];
	u8 i;

	for (i = 1; i < r->busy_n; i++)
		r->busy_q[i - 1] = r->busy_q[i];
	r->busy_n--;
	return bank;
}

static inline u32 t23_bp_queue_pop(struct t23_bp_ring *r)
{
	u32 addr = r->queue[r->q_head];

	r->q_head = (r->q_head + 1) % T23_BP_QUEUE;
	r->q_n--;
	return addr;
}

static inline int t23_bp_queue_push(struct t23_bp_ring *r, u32 addr)
{
	if (r->q_n >= T23_BP_QUEUE)
		return -1;
	r->queue[(r->q_head + r->q_n) % T23_BP_QUEUE] = addr;
	r->q_n++;
	return 0;
}

static inline void t23_bp_load_bank(struct t23_bp_ring *r, u32 addr,
				    struct t23_bp_load *ld)
{
	u8 bank = t23_bp_free_pop(r);

	r->bank_addr[bank] = addr;
	r->busy_q[r->busy_n++] = bank;
	ld->bank = bank;
	ld->addr = addr;
}

/*
 * QBUF: 1 = loaded into a bank (*ld says which register to write),
 * 0 = waits in the queue, -1 = refused (no address or queue full).
 * A buffer never overtakes one already waiting.
 */
static inline int t23_bp_qbuf(struct t23_bp_ring *r, u32 addr,
			      struct t23_bp_load *ld)
{
	if (!addr)
		return -1;
	if (r->free_n && !r->q_n) {
		t23_bp_load_bank(r, addr, ld);
		return 1;
	}
	return t23_bp_queue_push(r, addr);
}

/*
 * STREAMON: the hardware captures as many frames as the count in VIC register
 * 0x300 (bits 16..19) says, into the next banks in index order (all five
 * rotate), and stops when the count is used up.  Returns the number of
 * banks loaded now; 0 = nothing queued, no stream.  The driver refreshes the
 * count with t23_bp_pending() after every change (frame done, QBUF), as the
 * vendor frame-done interrupt does, so the engine never writes into a bank
 * whose buffer user space holds.
 */
static inline u8 t23_bp_start(struct t23_bp_ring *r)
{
	if (!r->busy_n)
		return 0;
	r->streaming = 1;
	return r->busy_n;
}

/* Banks loaded and not yet written: the value for the VIC capture count. */
static inline u8 t23_bp_pending(const struct t23_bp_ring *r)
{
	return r->busy_n;
}

/*
 * Frame-done interrupt.  cur = VIC register 0x380.  The oldest loaded bank
 * is complete; while its address is not cur, the next ones are too (a lost
 * interrupt).  Completed addresses go to out[] (at most outmax), their banks
 * are freed and reloaded from the waiting buffers (loads[], at most
 * T23_BP_BANKS).  Returns the number of completed buffers.
 */
static inline int t23_bp_done(struct t23_bp_ring *r, u32 cur,
			      u32 *out, int outmax,
			      struct t23_bp_load *loads, int *nloads)
{
	int n = 0;
	int nl = 0;

	*nloads = 0;
	if (!r->streaming || !r->busy_n)
		return 0;
	/* The frame landed on a free bank (no buffer was queued for it): the
	 * loaded banks keep their turn, nobody owns this frame. */
	if (r->bank_addr[r->busy_q[0]] != cur) {
		u8 i;

		for (i = 0; i < r->free_n; i++)
			if (r->bank_addr[r->free_q[i]] == cur) {
				r->stale++;
				return 0;
			}
	}
	for (;;) {
		u8 bank = t23_bp_busy_pop(r);
		u32 addr = r->bank_addr[bank];

		if (n < outmax)
			out[n++] = addr;
		r->delivered++;
		t23_bp_free_push(r, bank);
		if (addr == cur)
			break;
		if (!r->busy_n) {
			r->bad_addr++;
			break;
		}
	}
	while (r->free_n && r->q_n && nl < T23_BP_BANKS)
		t23_bp_load_bank(r, t23_bp_queue_pop(r), &loads[nl++]);
	*nloads = nl;
	return n;
}

/* STREAMOFF / graph teardown: forget every buffer (user space owns them). */
static inline void t23_bp_clear(struct t23_bp_ring *r)
{
	t23_bp_init(r);
}

#endif /* TX_ISP_T23_BYPASS_H */
