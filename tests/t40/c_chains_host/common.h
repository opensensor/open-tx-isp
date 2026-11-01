/* Host frame for the T40 C-chain checks: the literal OEM chain (from git, see run.sh) and the
 * readable driver chain run in one unit with the same bank pointers; every system_reg_write
 * goes to a log, the two logs and the chain state must be identical.
 * The literal code keeps stack/heap addresses in uint32_t: heap (MAP_32BIT arena), the worker
 * stack and the image (-no-pie) all live below 4 GiB. */
#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <sys/mman.h>
#include <pthread.h>
#ifndef MAP_32BIT
#define MAP_32BIT 0
#endif
typedef unsigned int uint;
typedef unsigned int gfp_t;
typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef int32_t s32;
#define module_param_named(a, b, c, d)
#define module_param(a, b, c)
#define MODULE_PARM_DESC(a, b)
/* bring-up-only parameters of the driver (Kbuild TX_ISP_T40_BRINGUP_PARAMS) */
#define t40_bringup_param(...)
#define t40_bringup_param_named(...)
#define t40_bringup_param_array_named(...)
#define t40_bringup_param_cb(...)
#define t40_bringup_parm_desc(...)
#define KERN_INFO ""
#define KERN_ERR ""
#define KERN_WARNING ""
#define printk(...) 0
#define pr_info(...) 0
#define READ_ONCE(x) (x)
#define WRITE_ONCE(x, v) ((x) = (v))
#define BIT(n) (1U << (n))
#define T40C2	/* driver: own section outside .bss/.data */
#define GFP_KERNEL 0x24000c0U
#define REGTRACE_LWLR(b, o) \
    ((uint32_t)*(const uint8_t *)(uintptr_t)((b) + (o)) | \
     ((uint32_t)*(const uint8_t *)(uintptr_t)((b) + (o) + 1) << 8) | \
     ((uint32_t)*(const uint8_t *)(uintptr_t)((b) + (o) + 2) << 16) | \
     ((uint32_t)*(const uint8_t *)(uintptr_t)((b) + (o) + 3) << 24))

static uint8_t *arena; static size_t used, arena_bytes = 256u << 20;	/* ARENA_MB on small targets */
static void *arena_alloc(size_t n) { void *p = arena + used; used += (n + 15) & ~15UL; assert(used < arena_bytes); return p; }
static void *kmalloc(size_t n, gfp_t f) { void *p = arena_alloc(n); (void)f; memset(p, 0xa5, n); return p; } /* not zeroed, like the kernel */
static void *kzalloc(size_t n, gfp_t f) { void *p = arena_alloc(n); (void)f; memset(p, 0, n); return p; }
static void *vzalloc(size_t n) { return kzalloc(n, 0); }
static void *vmalloc(size_t n) { return kmalloc(n, 0); }
static void kfree(const void *p) { (void)p; }
static void vfree(const void *p) { (void)p; }
/* address-only dispatch keys of the literal code */
static void *private_kmalloc(size_t n, gfp_t f) { return kmalloc(n, f); }
static void private_kfree(const void *p) { (void)p; }

/* register log */
struct wr { uint32_t r, v; };
#define LOGMAX (4u << 20)
static struct wr *wlog; static unsigned nlog;
static uint32_t regs[0x40000 / 4];
static int system_reg_write(uint32_t r, uint32_t v)
{
    assert(nlog < LOGMAX); wlog[nlog].r = r; wlog[nlog].v = v; nlog++;
    if (r < sizeof(regs)) regs[r / 4] = v;
    return 0;
}
static uint32_t (*reg_read_hook)(uint32_t r);	/* a chain test can feed statistics ports */
static uint32_t system_reg_read(uint32_t r) { return reg_read_hook ? reg_read_hook(r) : r < sizeof(regs) ? regs[r / 4] : 0; }

static uintptr_t tparamsN[0x4000];
/* inputs where the literal OEM code is undefined (division by zero, ...): run.sh instruments it */
static unsigned lit_ub;

/* copies of the driver helpers (tx_isp_t40_recovered.c, OEM rounding: bit 15 of the product) */
static uint32_t tisp_simple_intp_int8(int32_t i, int32_t f, void *t)
{
    uint8_t *p = t; uint32_t a, b, d, s;
    if (i >= 10) return p[10];
    a = p[i]; b = p[i + 1];
    if (a == b) return b;
    d = a >= b ? a - b : b - a;
    s = (uint32_t)((int32_t)(d * (uint32_t)f) >> 16);
    s = (s + (((d * (uint32_t)f) >> 15) & 1)) & 0xff;
    return (a >= b ? a - s : a + s) & 0xff;
}
static uint32_t tisp_simple_intp_int16(int32_t i, int32_t f, void *t)
{
    uint16_t *p = t; uint32_t a, b, d, m;
    if ((uint32_t)i >= 10) return p[10];
    a = p[i]; b = p[i + 1];
    if (a == b) return b;
    d = a >= b ? a - b : b - a;
    m = d * (uint32_t)f;
    m = (m >> 16) + ((m >> 15) & 1);
    return a >= b ? a - m : a + m;
}

/* bins */
#define BIN_BYTES 204800u
#define BANK_DAY(b) ((b) + 0x18)
#define BANK_NIGHT(b) ((b) + 0x18 + 0x18ff4)
/* "fuzz:<seed>" gives a bin of random bytes (covers fields every real bin leaves equal) */
static uint8_t *load_bin(const char *path)
{
    uint8_t *b = arena_alloc(BIN_BYTES); FILE *f;
    if (!strncmp(path, "fuzz:", 5)) {
        uint32_t x = strtoul(path + 5, 0, 0) * 2654435761u + 1;
        for (unsigned i = 0; i < BIN_BYTES; i++) { x ^= x << 13; x ^= x >> 17; x ^= x << 5; b[i] = x >> 3; }
        return b;
    }
    f = fopen(path, "rb");
    if (!f || fread(b, 1, BIN_BYTES, f) != BIN_BYTES) { fprintf(stderr, "bad bin %s\n", path); exit(2); }
    fclose(f); return b;
}

/* log snapshots */
static struct wr *snap(unsigned *n) { struct wr *s = malloc(nlog * sizeof(*s) + 1); memcpy(s, wlog, nlog * sizeof(*s)); *n = nlog; nlog = 0; return s; }
static unsigned cmp_logs(const char *what, struct wr *a, unsigned na, struct wr *b, unsigned nb)
{
    unsigned i, n = na < nb ? na : nb, bad = 0;
    if (na != nb) { printf("  %s: write count lit %u c %u\n", what, na, nb); bad++; }
    for (i = 0; i < n; i++)
        if (a[i].r != b[i].r || a[i].v != b[i].v) {
            if (bad < 8) printf("  %s: #%u lit %05x=%08x c %05x=%08x\n", what, i, a[i].r, a[i].v, b[i].r, b[i].v);
            bad++;
        }
    return bad;
}

/* deterministic gain sequences (16.16 log2 total gain) */
static uint32_t lcg_state = 12345;
static uint32_t lcg(void) { lcg_state = lcg_state * 1103515245u + 12345u; return lcg_state >> 1; }

static int chain_main(int argc, char **argv);
static int g_argc; static char **g_argv;
static void *worker(void *a) { (void)a; return (void *)(intptr_t)chain_main(g_argc, g_argv); }
#ifdef ALIGN_TRAP	/* -fsanitize=alignment -fsanitize-trap=alignment: count the trapping PCs, step over ud2 */
#include <signal.h>
#include <ucontext.h>
static uintptr_t at_pc[512]; static unsigned long at_n[512];
static void at_handler(int sig, siginfo_t *si, void *uc_)
{
    ucontext_t *uc = uc_; uintptr_t pc = uc->uc_mcontext.gregs[REG_RIP]; unsigned i;
    (void)sig; (void)si;
    for (i = 0; i < 512 && at_pc[i] && at_pc[i] != pc; i++) ;
    if (i < 512) { at_pc[i] = pc; at_n[i]++; }
    uc->uc_mcontext.gregs[REG_RIP] += 2;
}
static void at_report(void)
{
    unsigned i; FILE *f = fopen(getenv("ALIGN_TRAP_OUT") ? getenv("ALIGN_TRAP_OUT") : "/dev/stderr", "w");
    for (i = 0; i < 512 && at_pc[i]; i++) fprintf(f, "%#lx %lu\n", (unsigned long)at_pc[i], at_n[i]);
    fclose(f);
}
#endif
int main(int argc, char **argv)
{
#ifdef ALIGN_TRAP
    { struct sigaction sa; memset(&sa, 0, sizeof(sa)); sa.sa_sigaction = at_handler; sa.sa_flags = SA_SIGINFO; sigaction(SIGILL, &sa, NULL); atexit(at_report); }
#endif
    pthread_attr_t at; pthread_t t; void *rv; size_t ss = getenv("ARENA_MB") ? 1u << 20 : 16u << 20;
    void *stk = mmap(NULL, ss, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_32BIT, -1, 0);
    if (getenv("ARENA_MB")) arena_bytes = (size_t)atoi(getenv("ARENA_MB")) << 20;
    arena = mmap(NULL, arena_bytes, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_32BIT, -1, 0);
    assert(stk != MAP_FAILED && arena != MAP_FAILED);
    wlog = malloc(LOGMAX * sizeof(*wlog));
    setvbuf(stdout, NULL, _IONBF, 0);
    g_argc = argc; g_argv = argv;
    pthread_attr_init(&at); pthread_attr_setstack(&at, stk, ss);
    pthread_create(&t, &at, worker, NULL); pthread_join(t, &rv);
    return (int)(intptr_t)rv;
}
