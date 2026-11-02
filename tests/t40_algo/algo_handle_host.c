/* Host test of the T40 custom AE / AWB get-handle protocol (review 2026-11-03 H1).
 * The driver block between "static DEFINE_MUTEX(t40_algo_mutex);" and the AWB get-handle (t40_algo_*) is extracted from
 * driver/t40/tx_isp_t40_recovered.c by t40_algo_handle_host.sh and compiled here with pthread stand-ins for the kernel mutex
 * and completion; a "signal" is a per-thread flag that makes the interruptible wait return -ERESTARTSYS.
 * Cases: GET without an open library, close while a GET waits (must wake it, no use of the freed block), signal during the
 * wait, statistics wake-up, GET after the close, close while a GET holds the block (must wait for it), late result after the
 * close, re-open after the close. */
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
#define T40_ALGO_IDX_COUNT 2
#define BUILD_BUG_ON(c) _Static_assert(!(c), #c)
#define READ_ONCE(x) (*(volatile __typeof__(x) *)&(x))
typedef int bool;
#define true 1
#define false 0

static pthread_mutex_t big = PTHREAD_MUTEX_INITIALIZER;   /* completion / "spinlock" stand-in */
static pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
struct completion { unsigned int done; struct { int lock; int pad[2]; } wait; };   /* 16 bytes like the kernel's */
struct mutex { pthread_mutex_t m; };
#define DEFINE_MUTEX(n) struct mutex n = { PTHREAD_MUTEX_INITIALIZER }
static void mutex_lock(struct mutex *m) { pthread_mutex_lock(&m->m); }
static void mutex_unlock(struct mutex *m) { pthread_mutex_unlock(&m->m); }
#define spin_lock_irqsave(l, f) do { (void)(l); (f) = 0; pthread_mutex_lock(&big); } while (0)
#define spin_unlock_irqrestore(l, f) do { (void)(l); (void)(f); pthread_mutex_unlock(&big); } while (0)
static int inited[64];
static int ninit;
static void init_completion(struct completion *c) { pthread_mutex_lock(&big); c->done = 0; inited[ninit++ & 63] = 1; pthread_mutex_unlock(&big); }
static __thread volatile int sig_pending;
static volatile int sig_for[8];
static __thread int my_id;
static int wait_for_completion_interruptible(struct completion *c)
{
    int r = 0;

    pthread_mutex_lock(&big);
    while (!c->done) {
        if (sig_for[my_id]) { r = -ERESTARTSYS; break; }
        struct timespec ts; clock_gettime(CLOCK_REALTIME, &ts); ts.tv_nsec += 5000000; if (ts.tv_nsec >= 1000000000) { ts.tv_sec++; ts.tv_nsec -= 1000000000; }
        pthread_cond_timedwait(&cv, &big, &ts);
    }
    if (!r && c->done != UINT_MAX / 2)
        c->done--;
    pthread_mutex_unlock(&big);
    return r;
}
static void complete(struct completion *c) { pthread_mutex_lock(&big); if (c->done != UINT_MAX / 2) c->done++; pthread_cond_broadcast(&cv); pthread_mutex_unlock(&big); }
static void complete_all(struct completion *c) { pthread_mutex_lock(&big); c->done = UINT_MAX / 2; pthread_cond_broadcast(&cv); pthread_mutex_unlock(&big); }

static uint32_t ae_algo_comp[T40_ALGO_IDX_COUNT * 4], ae_info_mine[T40_ALGO_IDX_COUNT];
static uint32_t awb_algo_comp[T40_ALGO_IDX_COUNT * 4], awb_info_mine[T40_ALGO_IDX_COUNT];
/* 32-bit kernel pointers in uint32_t slots: hand out blocks from a static pool below 4 GB */
static unsigned char pool[8][4096];
static int pool_used[8], freed[8];
static uint32_t blk_alloc(void) { for (int i = 0; i < 8; i++) if (!pool_used[i]) { assert((uintptr_t)pool[i] <= 0xffffffffu); pool_used[i] = 1; freed[i] = 0; memset(pool[i], 0x5a, 4096); return (uint32_t)(uintptr_t)pool[i]; } abort(); }
static void private_kfree(uint32_t p) { for (int i = 0; i < 8; i++) if ((uintptr_t)pool[i] == p) { assert(!freed[i]); freed[i] = 1; pool_used[i] = 0; memset(pool[i], 0x6b, 4096); return; } abort(); }
static int handled;
static int32_t tisp_awb_algo_handle(uint32_t a0, uintptr_t a1) { (void)a0; (void)a1; handled++; return 0; }
static int32_t tisp_ae_algo_handle(uintptr_t a0, uintptr_t a1) { (void)a0; (void)a1; handled++; return 0; }

#include "algo_block.inc"

/* open / close the way the ioctls do it */
static void lib_open(int awb, uint32_t ch)
{
    mutex_lock(&t40_algo_mutex);
    t40_algo_comp_arm_locked(awb, ch);
    if (!t40_algo_slot(awb)[ch])
        t40_algo_slot(awb)[ch] = blk_alloc();
    mutex_unlock(&t40_algo_mutex);
}
static void lib_close(int awb, uint32_t ch)
{
    mutex_lock(&t40_algo_mutex);
    t40_algo_release_locked(awb, ch);
    mutex_unlock(&t40_algo_mutex);
}

struct g { int awb; uint32_t ch; int id; volatile int ret, done; int hold_ms; volatile int held; char *info; };
static void *getter(void *p)
{
    struct g *g = p;
    char *info = NULL;

    my_id = g->id;
    g->ret = t40_algo_get_begin(g->awb, g->ch, &info);
    if (g->ret == 0) {
        g->info = info;
        g->held = 1;
        memset(info + 8, 0, 64);            /* uses the block (a freed block is 0x6b-poisoned and asserted below) */
        usleep(g->hold_ms * 1000);
        assert(info[8] == 0 && info[71] == 0);
        g->held = 2;
        t40_algo_get_end();
    }
    g->done = 1;
    return NULL;
}
static int wait_done(struct g *g, int ms) { while (!g->done && ms-- > 0) usleep(1000); return g->done; }

int main(void)
{
    pthread_t th;
    struct g g;
    int awb;

    for (awb = 0; awb < 2; awb++) {
        /* 1: GET without an open library: -EINVAL at once (OEM: wait on a zeroed wait queue / NULL + 8) */
        memset(&g, 0, sizeof(g)); g.awb = awb; g.id = 1;
        pthread_create(&th, NULL, getter, &g);
        assert(wait_done(&g, 500) && g.ret == -EINVAL);
        pthread_join(th, NULL);

        /* 2: close while a GET waits: the GET is woken and returns -EINVAL (OEM: sleeps on, then NULL + 8 / freed block) */
        lib_open(awb, 0);
        memset(&g, 0, sizeof(g)); g.awb = awb; g.id = 1;
        pthread_create(&th, NULL, getter, &g);
        usleep(50000); assert(!g.done);
        lib_close(awb, 0);
        assert(wait_done(&g, 1000) && g.ret == -EINVAL);
        pthread_join(th, NULL);

        /* 3: GET after the close (completion done = "all"): -EINVAL, no busy return of stale data */
        memset(&g, 0, sizeof(g)); g.awb = awb; g.id = 1;
        pthread_create(&th, NULL, getter, &g);
        assert(wait_done(&g, 500) && g.ret == -EINVAL);
        pthread_join(th, NULL);

        /* 4: re-open: the GET waits again, a statistics wake-up hands it the block */
        lib_open(awb, 0);
        memset(&g, 0, sizeof(g)); g.awb = awb; g.id = 1;
        pthread_create(&th, NULL, getter, &g);
        usleep(50000); assert(!g.done);
        complete(t40_algo_comp(awb, 0));
        assert(wait_done(&g, 1000) && g.ret == 0 && g.held == 2);
        pthread_join(th, NULL);

        /* 5: signal during the wait: -ERESTARTSYS (OEM: wait result ignored, block used anyway) */
        memset(&g, 0, sizeof(g)); g.awb = awb; g.id = 2;
        pthread_create(&th, NULL, getter, &g);
        usleep(50000); assert(!g.done);
        sig_for[2] = 1;
        assert(wait_done(&g, 1000) && g.ret == -ERESTARTSYS);
        sig_for[2] = 0;
        pthread_join(th, NULL);

        /* 6: close while a GET holds the block: the close waits, the block is not freed under the GET */
        memset(&g, 0, sizeof(g)); g.awb = awb; g.id = 1; g.hold_ms = 200;
        pthread_create(&th, NULL, getter, &g);
        usleep(30000);
        complete(t40_algo_comp(awb, 0));
        while (!g.held) usleep(1000);
        lib_close(awb, 0);                  /* blocks until t40_algo_get_end() */
        assert(g.held == 2 && g.ret == 0);
        pthread_join(th, NULL);
        assert(!t40_algo_slot(awb)[0]);

        /* 7: a late library result after the close is refused (would take the white balance / exposure over again) */
        handled = 0;
        assert(t40_algo_result(awb, 0, 0) == -EINVAL && handled == 0);
        lib_open(awb, 0);
        assert(t40_algo_result(awb, 0, 0) == 0 && handled == 1);
        assert(t40_algo_result(awb, 2, 0) == -EINVAL);
        lib_close(awb, 0);

        /* 8: channels are independent: closing channel 1 does not wake a GET of channel 0 */
        lib_open(awb, 0); lib_open(awb, 1);
        memset(&g, 0, sizeof(g)); g.awb = awb; g.id = 1;
        pthread_create(&th, NULL, getter, &g);
        usleep(30000);
        lib_close(awb, 1);
        usleep(50000); assert(!g.done);
        lib_close(awb, 0);
        assert(wait_done(&g, 1000) && g.ret == -EINVAL);
        pthread_join(th, NULL);
    }
    printf("t40_algo_handle_host: 16 cases ok\n");
    return 0;
}
