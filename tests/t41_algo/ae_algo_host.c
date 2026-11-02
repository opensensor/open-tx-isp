/* Host test of the T41 custom AWB library protocol (Lu-Fi/openimp#195): the block between T41-AE-ALGO-PROTOCOL-BEGIN / END of
 * driver/t41/tx_isp_t41_vae.h is extracted by t41_ae_algo_host.sh and compiled here with pthread stand-ins for the kernel mutex and
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
static int copy_to_fail;
static unsigned long private_copy_to_user(void *d, const void *s, unsigned long n) { if (copy_fail || copy_to_fail) return n; memcpy(d, s, n); return 0; }
static void isp_printf(int lvl, const char *fmt, ...) { (void)lvl; (void)fmt; }

#define BUILD_BUG_ON(x) do { } while (0)
#define ae_algo_comp_storage ((unsigned char *)&ae_comp)
static struct completion ae_comp;
/* hardware hooks */
static int hw_reg_calls, hw_unreg_calls, hw_reg_fail, hw_fill_fail, custom_en, fill_hold_ms, fill_poison_seen, set_calls;
#include "ae_block.inc"

static int t41_ae_algo_hw_precheck(const u32 *u) { if (u[0] != T41_AE_ALGO_COOKIE) return -EPERM; if (u[1] >= 1U) return -EINVAL; return 0; }
static int t41_ae_algo_hw_register(u32 *u) { if (hw_reg_fail) return -ENODEV; hw_reg_calls++; custom_en = 1; for (int i = 2; i < 8; i++) u[i] = 0x100 + i; return 0; }
static void t41_ae_algo_hw_unregister(u32 ch) { (void)ch; hw_unreg_calls++; custom_en = 0; }
static int t41_ae_algo_hw_fill(unsigned char *b)
{
	if (hw_fill_fail) return -EINVAL;
	memcpy(b, "FILLED", 6);
	if (fill_hold_ms) { usleep(fill_hold_ms * 1000); if (b[0] != 'F') fill_poison_seen = 1; }
	return 0;
}
static int t41_ae_algo_hw_set(u32 *u) { (void)u; set_calls++; return 0; }
/* the vendor chain wakes the library at the end of its AE frame (only while a custom AE is active) */
static void vendor_wake(void) { if (custom_en) complete(T41_AE_ALGO_COMP); }

static u32 ubuf[700];
struct g { int id; volatile int ret, done; };
static void *getter(void *p)
{
	struct g *g = p;
	u32 req[2] = { T41_AE_ALGO_COOKIE, 0 };

	my_id = g->id;
	memcpy(ubuf, req, 8);
	g->ret = t41_ae_algo_get((u32)(uintptr_t)ubuf);
	g->done = 1;
	return NULL;
}
static int wait_done(struct g *g, int ms) { while (!g->done && ms-- > 0) usleep(1000); return g->done; }
static u32 U(void *p) { return (u32)(uintptr_t)p; }
static int do_open(uintptr_t file) { static u32 o[34]; memset(o, 0, sizeof(o)); o[0] = T41_AE_ALGO_COOKIE; memcpy(ubuf, o, sizeof(o)); return t41_ae_algo_open(file, U(ubuf)); }
static int do_close(void) { u32 c[2] = { T41_AE_ALGO_COOKIE, 0 }; static u32 b[2]; memcpy(b, c, 8); return t41_ae_algo_close(U(b)); }
static int do_set(u32 ch) { static u32 s[14]; s[0] = T41_AE_ALGO_COOKIE; s[1] = ch; return t41_ae_algo_set(U(s)); }

int main(void)
{
	pthread_t th;
	struct g g;

	/* 1: GET / SET / CLOSE without a registered library (the vendor default: nothing registered, nothing changes) */
	memset(&g, 0, sizeof(g)); g.id = 1;
	pthread_create(&th, NULL, getter, &g);
	assert(wait_done(&g, 500) && g.ret == -EINVAL);
	pthread_join(th, NULL);
	assert(do_set(0) == -EINVAL && set_calls == 0);
	assert(do_close() == 0 && hw_unreg_calls == 0 && blocks_in_use() == 0);
	t41_ae_algo_release(1);
	assert(hw_unreg_calls == 0 && blocks_in_use() == 0);

	/* 2: open: cookie / channel / double open / hardware refusal / copy failure */
	{ u32 bad[34] = { 0x1234, 0 }; memcpy(ubuf, bad, sizeof(bad)); assert(t41_ae_algo_open(1, U(ubuf)) == -EPERM); }
	{ u32 bad[34] = { T41_AE_ALGO_COOKIE, 1 }; memcpy(ubuf, bad, sizeof(bad)); assert(t41_ae_algo_open(1, U(ubuf)) == -EINVAL); }
	hw_reg_fail = 1; assert(do_open(1) == -ENODEV); hw_reg_fail = 0;
	copy_fail = 1; assert(do_open(1) == -EFAULT); copy_fail = 0;
	copy_to_fail = 1; assert(do_open(1) == -EFAULT); copy_to_fail = 0;
	assert(blocks_in_use() == 0 && !t41_ae_algo_info && !custom_en && hw_unreg_calls == hw_reg_calls);
	assert(do_open(1) == 0 && blocks_in_use() == 1 && custom_en);
	assert(ubuf[3] == 0x103);
	assert(do_open(2) == -EBUSY && blocks_in_use() == 1);

	/* 3: wake -> GET returns the block; two wakes before a GET count once per wake (kernel semantics: both stay pending) */
	vendor_wake();
	memset(&g, 0, sizeof(g)); g.id = 1;
	pthread_create(&th, NULL, getter, &g);
	assert(wait_done(&g, 1000) && g.ret == 0);
	pthread_join(th, NULL);
	assert(!memcmp((char *)ubuf, "FILLED", 6));
	memset(&g, 0, sizeof(g)); g.id = 1;
	pthread_create(&th, NULL, getter, &g);
	{ static struct g g2; pthread_t th2; memset(&g2, 0, sizeof(g2)); g2.id = 3;
	  pthread_create(&th2, NULL, getter, &g2);
	  usleep(50000); assert(!g.done && !g2.done);
	  assert(do_close() == 0);
	  assert(wait_done(&g, 1000) && g.ret == -EINVAL && wait_done(&g2, 1000) && g2.ret == -EINVAL);	/* every waiter woken */
	  pthread_join(th, NULL); pthread_join(th2, NULL); }
	assert(do_open(1) == 0);
	memset(&g, 0, sizeof(g)); g.id = 1;
	pthread_create(&th, NULL, getter, &g);
	usleep(50000); assert(!g.done);

	/* 4: close while a GET waits: woken, -EINVAL, block freed once, a repeated close frees nothing, GET after the close -EINVAL */
	assert(do_close() == 0);
	assert(wait_done(&g, 1000) && g.ret == -EINVAL);
	pthread_join(th, NULL);
	assert(blocks_in_use() == 0 && !custom_en);
	{ int u0 = hw_unreg_calls; assert(do_close() == 0 && blocks_in_use() == 0 && hw_unreg_calls == u0); }
	vendor_wake();
	memset(&g, 0, sizeof(g)); g.id = 1;
	pthread_create(&th, NULL, getter, &g);
	assert(wait_done(&g, 500) && g.ret == -EINVAL);
	pthread_join(th, NULL);

	/* 5: re-open: the completion is initialised once, no stale wake-up */
	assert(init_count == 1);
	assert(do_open(1) == 0 && init_count == 1);
	memset(&g, 0, sizeof(g)); g.id = 1;
	pthread_create(&th, NULL, getter, &g);
	usleep(50000); assert(!g.done);
	vendor_wake();
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
	assert(t41_ae_algo_info && blocks_in_use() == 1);

	/* 7: close while a GET holds the block: the close waits, the block is not freed under the GET */
	fill_hold_ms = 200; fill_poison_seen = 0;
	memset(&g, 0, sizeof(g)); g.id = 1;
	pthread_create(&th, NULL, getter, &g);
	usleep(30000);
	vendor_wake();
	usleep(60000);
	assert(do_close() == 0);
	assert(g.done && g.ret == 0 && !fill_poison_seen && blocks_in_use() == 0);
	pthread_join(th, NULL);
	fill_hold_ms = 0;

	/* 8: results: applied, late result after the close refused, GET with a vanished AE answers the error */
	assert(do_open(7) == 0);
	set_calls = 0;
	assert(do_set(0) == 0 && set_calls == 1 && do_set(1) == -EINVAL && set_calls == 1);
	hw_fill_fail = 1; vendor_wake();
	memset(&g, 0, sizeof(g)); g.id = 1; pthread_create(&th, NULL, getter, &g);
	assert(wait_done(&g, 1000) && g.ret == -EINVAL); pthread_join(th, NULL); hw_fill_fail = 0;
	assert(do_close() == 0 && blocks_in_use() == 0);
	assert(do_set(0) == -EINVAL && set_calls == 1);

	/* 9: release hook: only the file that registered the library unregisters it (a killed client); close + release free once */
	assert(do_open(42) == 0);
	{ int u0 = hw_unreg_calls; t41_ae_algo_release(43); assert(t41_ae_algo_info && hw_unreg_calls == u0);
	  t41_ae_algo_release(42);
	  assert(!t41_ae_algo_info && hw_unreg_calls == u0 + 1 && blocks_in_use() == 0 && !custom_en);
	  t41_ae_algo_release(42); assert(hw_unreg_calls == u0 + 1 && blocks_in_use() == 0);
	  assert(do_close() == 0 && blocks_in_use() == 0 && hw_unreg_calls == u0 + 1); }
	/* the EBUSY of the stock module: a new client opens right after the killed one */
	assert(do_open(44) == 0 && blocks_in_use() == 1);

	/* 9b: release while a GET waits: woken with -EINVAL */
	memset(&g, 0, sizeof(g)); g.id = 1; pthread_create(&th, NULL, getter, &g);
	usleep(50000); assert(!g.done);
	t41_ae_algo_release(44);
	assert(wait_done(&g, 1000) && g.ret == -EINVAL); pthread_join(th, NULL);
	assert(blocks_in_use() == 0);

	/* 10: ioctl dispatch */
	assert(t41_ioctl_ae_algo(1, 0xc0045420U, 0) == -ENOTTY && t41_ioctl_ae_algo(1, 0xc0045423U, 0) == -ENOTTY);
	{ u32 c[34] = { T41_AE_ALGO_COOKIE, 0 }; memcpy(ubuf, c, sizeof(c)); }
	assert(t41_ioctl_ae_algo(5, 0xc004541dU, U(ubuf)) == 0 && t41_ae_algo_info);
	t41_ae_algo_release(5);
	assert(blocks_in_use() == 0);
	printf("t41_ae_algo_host: 11 case groups ok\n");
	return 0;
}
