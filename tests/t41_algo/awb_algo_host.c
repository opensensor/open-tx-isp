/* Host test of the T41 custom AWB library protocol (Lu-Fi/openimp#195): the block between T41-AWB-ALGO-PROTOCOL-BEGIN / END of
 * driver/t41/tx_isp_t41_awb_algo.h is extracted by t41_awb_algo_host.sh and compiled here with pthread stand-ins for the kernel mutex and
 * completion ("signal" = per-thread flag that makes the interruptible wait return -ERESTARTSYS) and poisoned allocations (a use of the freed info
 * block or a second free aborts).  The hardware hooks are stubs. */
#define _GNU_SOURCE
#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define ERESTARTSYS 512
#define READ_ONCE(x) (*(volatile __typeof__(x) *)&(x))
#define WRITE_ONCE(x, v) (*(volatile __typeof__(x) *)&(x) = (v))
#define __user
#define GFP_KERNEL 0
#define pr_warn_once(...) do { } while (0)
typedef uint32_t u32;
typedef int bool_t;
#define bool int
#define true 1
#define false 0

static pthread_mutex_t big = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
struct completion { unsigned int done; };
struct mutex { pthread_mutex_t m; };
#define DEFINE_MUTEX(n) struct mutex n = { PTHREAD_MUTEX_INITIALIZER }
static void mutex_lock(struct mutex *m) { pthread_mutex_lock(&m->m); }
static void mutex_unlock(struct mutex *m) { pthread_mutex_unlock(&m->m); }
static int init_count;
static void init_completion(struct completion *c) { pthread_mutex_lock(&big); c->done = 0; init_count++; pthread_mutex_unlock(&big); }
static __thread int my_id;
static volatile int sig_for[8];
static int private_wait_for_completion_interruptible(struct completion *c)
{
	int r = 0;

	pthread_mutex_lock(&big);
	while (!c->done) {
		struct timespec ts;

		if (sig_for[my_id]) { r = -ERESTARTSYS; break; }
		clock_gettime(CLOCK_REALTIME, &ts); ts.tv_nsec += 5000000; if (ts.tv_nsec >= 1000000000) { ts.tv_sec++; ts.tv_nsec -= 1000000000; }
		pthread_cond_timedwait(&cv, &big, &ts);
	}
	if (!r && c->done != UINT_MAX / 2)
		c->done--;
	pthread_mutex_unlock(&big);
	return r;
}
static void complete(struct completion *c) { pthread_mutex_lock(&big); if (c->done != UINT_MAX / 2) c->done++; pthread_cond_broadcast(&cv); pthread_mutex_unlock(&big); }
static void complete_all(struct completion *c) { pthread_mutex_lock(&big); c->done = UINT_MAX / 2; pthread_cond_broadcast(&cv); pthread_mutex_unlock(&big); }

/* poisoned allocations: a freed block reads 0x6b, a second free or a leak is caught */
static unsigned char pool[4][4096];
static int pool_used[4];
static void *kzalloc(size_t n, int f) { (void)f; assert(n <= 4096); for (int i = 0; i < 4; i++) if (!pool_used[i]) { pool_used[i] = 1; memset(pool[i], 0, 4096); return pool[i]; } abort(); }
static void kfree(void *p) { for (int i = 0; i < 4; i++) if (pool[i] == p) { assert(pool_used[i]); pool_used[i] = 0; memset(pool[i], 0x6b, 4096); return; } abort(); }
static int blocks_in_use(void) { int n = 0; for (int i = 0; i < 4; i++) n += pool_used[i]; return n; }

/* user memory is host memory */
static int copy_fail;
static unsigned long private_copy_from_user(void *d, const void *s, unsigned long n) { if (copy_fail) return n; memcpy(d, s, n); return 0; }
static unsigned long private_copy_to_user(void *d, const void *s, unsigned long n) { if (copy_fail) return n; memcpy(d, s, n); return 0; }
static void isp_printf(int lvl, const char *fmt, ...) { (void)lvl; (void)fmt; }

/* hardware hooks */
static int apply_calls, apply_fail, restore_calls, fill_hold_ms, fill_calls;
static u32 last_r, last_b;
static int fill_poison_seen;
#include "awb_block.inc"

static void t41_awb_algo_init_attr(u32 attr[5]) { for (int i = 0; i < 5; i++) attr[i] = 0x100 + i; }
static void t41_awb_algo_fill_info(unsigned char *info)
{
	fill_calls++;
	memcpy(info, "FILLED", 6);
	if (fill_hold_ms) { usleep(fill_hold_ms * 1000); if (info[0] != 'F') fill_poison_seen = 1; }
}
static int t41_awb_algo_apply(u32 r, u32 b) { apply_calls++; last_r = r; last_b = b; if (!apply_fail) t41_awb_algo_manual = true; return apply_fail ? -19 : 0; }
static void t41_awb_algo_restore(void) { restore_calls++; }


static u32 ubuf[700];		/* "user" buffer */
struct g { int id; volatile int ret, done; };
static void *getter(void *p)
{
	struct g *g = p;
	u32 req[2] = { T41_AWB_ALGO_COOKIE, 0 };

	my_id = g->id;
	memcpy(ubuf, req, 8);
	g->ret = t41_awb_algo_get((u32)(uintptr_t)ubuf);
	g->done = 1;
	return NULL;
}
static int wait_done(struct g *g, int ms) { while (!g->done && ms-- > 0) usleep(1000); return g->done; }
static u32 U(void *p) { return (u32)(uintptr_t)p; }
static int do_open(uintptr_t file) { u32 o[7] = { T41_AWB_ALGO_COOKIE, 0 }; memcpy(ubuf, o, sizeof(o)); return t41_awb_algo_open(file, U(ubuf)); }
static int do_close(void) { u32 c[2] = { T41_AWB_ALGO_COOKIE, 0 }; static u32 b[2]; memcpy(b, c, 8); return t41_awb_algo_close(U(b)); }
static int do_set(u32 ch, u32 change, u32 r, u32 b) { static u32 s[6]; s[0] = T41_AWB_ALGO_COOKIE; s[1] = ch; s[2] = change; s[3] = r; s[4] = b; s[5] = 0; return t41_awb_algo_set(U(s)); }

int main(void)
{
	pthread_t th;
	struct g g;
	u32 o[7];

	/* 1: GET / SET / CLOSE without a registered library */
	memset(&g, 0, sizeof(g)); g.id = 1;
	pthread_create(&th, NULL, getter, &g);
	assert(wait_done(&g, 500) && g.ret == -EINVAL);
	pthread_join(th, NULL);
	assert(do_set(0, 1, 300, 400) == -EINVAL && apply_calls == 0);
	assert(do_close() == 0 && restore_calls == 0 && blocks_in_use() == 0);

	/* 2: open: cookie / channel / double open / copy failure; the init attribute reaches the user */
	{ u32 bad[2] = { 0x1234, 0 }; memcpy(ubuf, bad, 8); assert(t41_awb_algo_open(1, U(ubuf)) == -EPERM); }
	{ u32 bad[2] = { T41_AWB_ALGO_COOKIE, 1 }; memcpy(ubuf, bad, 8); assert(t41_awb_algo_open(1, U(ubuf)) == -EINVAL); }
	copy_fail = 1; assert(do_open(1) == -EFAULT); copy_fail = 0;
	assert(blocks_in_use() == 0 && !t41_awb_algo_info && !READ_ONCE(t41_awb_algo_on));
	assert(do_open(1) == 0 && blocks_in_use() == 1 && READ_ONCE(t41_awb_algo_on));
	memcpy(o, ubuf, sizeof(o)); assert(o[0] == T41_AWB_ALGO_COOKIE && o[2] == 0x100 && o[6] == 0x104);
	assert(do_open(2) == -EBUSY && blocks_in_use() == 1);

	/* 3: wake -> GET returns the 2732 byte block with the cookie and the hook data; two wakes before a GET count once */
	t41_awb_algo_wake(); t41_awb_algo_wake();
	memset(&g, 0, sizeof(g)); g.id = 1;
	pthread_create(&th, NULL, getter, &g);
	assert(wait_done(&g, 1000) && g.ret == 0);
	pthread_join(th, NULL);
	assert(ubuf[0] == T41_AWB_ALGO_COOKIE && ubuf[1] == 0 && !memcmp((char *)ubuf + 8, "FILLED", 6));
	memset(&g, 0, sizeof(g)); g.id = 1;
	pthread_create(&th, NULL, getter, &g);
	usleep(50000); assert(!g.done);		/* the second wake did not queue a second frame */

	/* 4: close while a GET waits: woken, -EINVAL, block freed once, white balance not restored (no result yet) */
	assert(do_close() == 0);
	assert(wait_done(&g, 1000) && g.ret == -EINVAL);
	pthread_join(th, NULL);
	assert(blocks_in_use() == 0 && restore_calls == 0);
	assert(do_close() == 0 && blocks_in_use() == 0);		/* a repeated close frees nothing */
	t41_awb_algo_wake();						/* wake with no library: nothing */
	memset(&g, 0, sizeof(g)); g.id = 1;
	pthread_create(&th, NULL, getter, &g);
	assert(wait_done(&g, 500) && g.ret == -EINVAL);		/* GET after the close */
	pthread_join(th, NULL);

	/* 5: re-open: the completion is not initialised again, a stale wake-up of the old library is dropped */
	assert(init_count == 1);
	assert(do_open(1) == 0 && init_count == 1);
	memset(&g, 0, sizeof(g)); g.id = 1;
	pthread_create(&th, NULL, getter, &g);
	usleep(50000); assert(!g.done);
	t41_awb_algo_wake();
	assert(wait_done(&g, 1000) && g.ret == 0);
	pthread_join(th, NULL);

	/* 6: signal during the wait: -ERESTARTSYS, library stays registered */
	memset(&g, 0, sizeof(g)); g.id = 2;
	pthread_create(&th, NULL, getter, &g);
	usleep(50000); assert(!g.done);
	sig_for[2] = 1;
	assert(wait_done(&g, 1000) && g.ret == -ERESTARTSYS);
	sig_for[2] = 0;
	pthread_join(th, NULL);
	assert(t41_awb_algo_info && blocks_in_use() == 1);

	/* 7: close while a GET holds the block: the close waits, the block is not freed under the GET */
	fill_hold_ms = 200; fill_poison_seen = 0;
	memset(&g, 0, sizeof(g)); g.id = 1;
	pthread_create(&th, NULL, getter, &g);
	usleep(30000);
	t41_awb_algo_wake();
	usleep(60000);				/* the GET is inside the fill hook, holding the lock */
	assert(do_close() == 0);		/* blocks until the GET is done */
	assert(g.done && g.ret == 0 && !fill_poison_seen && blocks_in_use() == 0);
	pthread_join(th, NULL);
	fill_hold_ms = 0;

	/* 8: results: applied, ignored values answer 0 without touching the white balance, failure answers 0, late result refused */
	assert(do_open(7) == 0);
	apply_calls = 0;
	assert(do_set(0, 0, 600, 700) == 0 && apply_calls == 0);		/* change = 0 */
	assert(do_set(0, 1, 0, 700) == 0 && do_set(0, 1, 600, 0) == 0 && do_set(0, 1, T41_AWB_ALGO_GAIN_MIN - 1, 700) == 0 && do_set(0, 1, 600, T41_AWB_ALGO_GAIN_MIN - 1) == 0 && apply_calls == 0);	/* zero / too small gain */
	assert(do_set(0, 1, T41_AWB_ALGO_GAIN_MAX + 1, 700) == 0 && do_set(0, 1, 600, T41_AWB_ALGO_GAIN_MAX + 1) == 0 && apply_calls == 0);
	assert(do_set(1, 1, 600, 700) == -EINVAL && apply_calls == 0);		/* channel 1 */
	assert(do_set(0, 1, 600, 700) == 0 && apply_calls == 1 && last_r == 600 && last_b == 700 && t41_awb_algo_manual);
	assert(do_set(0, 1, T41_AWB_ALGO_GAIN_MIN, T41_AWB_ALGO_GAIN_MAX) == 0 && apply_calls == 2 && last_r == T41_AWB_ALGO_GAIN_MIN && last_b == T41_AWB_ALGO_GAIN_MAX);
	apply_fail = 1; assert(do_set(0, 1, 610, 710) == 0 && apply_calls == 3); apply_fail = 0;
	assert(do_close() == 0 && restore_calls == 1 && !t41_awb_algo_manual && blocks_in_use() == 0);
	assert(do_set(0, 1, 600, 700) == -EINVAL && apply_calls == 3);		/* late result after the close */

	/* 9: release hook: only the file that registered the library unregisters it (a crashed streamer) */
	assert(do_open(42) == 0);
	assert(do_set(0, 1, 800, 900) == 0 && t41_awb_algo_manual);
	restore_calls = 0;
	t41_awb_algo_release(43);
	assert(t41_awb_algo_info && restore_calls == 0);
	t41_awb_algo_release(42);
	assert(!t41_awb_algo_info && restore_calls == 1 && blocks_in_use() == 0 && !READ_ONCE(t41_awb_algo_on));
	t41_awb_algo_release(42);
	assert(restore_calls == 1);

	/* 10: ioctl dispatch */
	assert(t41_ioctl_awb_algo(1, 0xc0045420U, 0) == -ENOTTY && t41_ioctl_awb_algo(1, 0xc0045427U, 0) == -ENOTTY);
	{ u32 c[2] = { T41_AWB_ALGO_COOKIE, 0 }; memcpy(ubuf, c, 8); }
	assert(t41_ioctl_awb_algo(5, 0xc0045425U, U(ubuf)) == 0 && t41_awb_algo_info);	/* open through the dispatcher */
	t41_awb_algo_release(5);
	assert(blocks_in_use() == 0);
	printf("t41_awb_algo_host: 10 case groups ok\n");
	return 0;
}
