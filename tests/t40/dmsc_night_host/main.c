/* T40 DMSC literal chain on the host: day/night bank x gain -> registers 0xa000..0xa27c.
 * Build: gcc -O0 -no-pie -fno-pie -w -pthread -o dmschost main.c ;
 * The literal code keeps stack/heap addresses in uint32_t: heap and the worker stack live below 4 GiB.
 * ./dmschost sc830ai-t40.bin [dump.txt bank gain] */
#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/mman.h>
#include <pthread.h>
typedef unsigned int uint;
#define module_param_named(a, b, c, d)
#define KERN_INFO ""
#define printk(...) 0
#include <errno.h>
#define REGTRACE_LWLR(b, o) \
    ((uint32_t)*(const uint8_t *)(uintptr_t)((b) + (o)) | \
     ((uint32_t)*(const uint8_t *)(uintptr_t)((b) + (o) + 1) << 8) | \
     ((uint32_t)*(const uint8_t *)(uintptr_t)((b) + (o) + 2) << 16) | \
     ((uint32_t)*(const uint8_t *)(uintptr_t)((b) + (o) + 3) << 24))
static uint8_t *arena; static size_t used;
static void *vzalloc(size_t n) { void *p = arena + used; used += (n + 15) & ~15UL; assert(used < (64u << 20)); memset(p, 0, n); return p; }
static void vfree(const void *p) { (void)p; }
static uint32_t regs[0x20000 / 4];
static unsigned nwrites;
static int system_reg_write(uint32_t r, uint32_t v) { nwrites++; if (r < 0x20000) regs[r / 4] = v; return 0; }
static uint32_t system_reg_read(uint32_t r) { return r < 0x20000 ? regs[r / 4] : 0; }
static uint32_t tparamsN[2];
/* copies of the driver helpers (tx_isp_t40_recovered.c) */
static uint32_t tisp_simple_intp_int8(int32_t i, int32_t f, void *t)
{
    uint8_t *p = t; uint32_t a, b, d, s;
    if (i >= 10) return p[10];
    a = p[i]; b = p[i + 1];
    if (a == b) return b;
    d = a >= b ? a - b : b - a;
    s = (uint32_t)((int32_t)(d * (uint32_t)f) >> 16);
    s = (s + (((d * (uint32_t)f) >> 15) & 1)) & 0xff;   /* OEM: rounding bit = bit 15 of the product */
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
#include "../../../driver/t40/tx_isp_t40_dmsc.inc"
static uint32_t dump[0x20000 / 4];
static int g_argc; static char **g_argv;
static int run(int argc, char **argv)
{
    static const uint32_t gains[] = { 0, 65536, 131072, 196608, 262144, 327680, 393216, 458752 };
    uint8_t *bin; FILE *f; unsigned g, o, diff;
    arena = mmap(NULL, 64u << 20, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_32BIT, -1, 0);
    assert(arena != MAP_FAILED);
    bin = vzalloc(204800); f = fopen(argv[1], "rb"); assert(f && fread(bin, 1, 204800, f) == 204800); fclose(f);
    if (argc >= 5) { /* compare against a register dump (32768 lines of 0x%08X from 0x13300000) */
        int bank = atoi(argv[3]); uint32_t gain = strtoul(argv[4], 0, 0);
        f = fopen(argv[2], "r"); for (o = 0; o < 0x20000 / 4 && fscanf(f, "%x", &dump[o]) == 1; o++); fclose(f);
        tparamsN[0] = (uint32_t)(uintptr_t)(bin + 0x18 + (bank ? 0x18ff4 : 0));
        regtrace_dmsc_lit_gain = gain; regtrace_dmsc_main_init_lit();
        for (diff = 0, o = 0xa000; o < 0xa280; o += 4)
            if (regs[o / 4] != dump[o / 4]) { diff++; printf("  %05x host %08x dump %08x\n", o, regs[o / 4], dump[o / 4]); }
        printf("bank %s gain %u: %u of 160 DMSC words differ from the dump\n", bank ? "night" : "day", gain, diff);
        return 0;
    }
    for (int bank = 0; bank < 2; bank++)
        for (g = 0; g < sizeof(gains) / 4; g++) {
            memset(regs, 0, sizeof(regs)); nwrites = 0;
            tparamsN[0] = (uint32_t)(uintptr_t)(bin + 0x18 + (bank ? 0x18ff4 : 0));
            regtrace_dmsc_lit_gain = gains[g]; regtrace_dmsc_main_init_lit();
            printf("%s gain %6u: writes %u a014=%08x a038=%08x a048=%08x a060=%08x a24c=%08x a264=%08x\n", bank ? "night" : "day  ",
                   gains[g], nwrites, regs[0xa014/4], regs[0xa038/4], regs[0xa048/4], regs[0xa060/4], regs[0xa24c/4], regs[0xa264/4]);
        }
    return 0;
}

static void *worker(void *a) { (void)a; return (void *)(intptr_t)run(g_argc, g_argv); }
int main(int argc, char **argv)
{
    pthread_attr_t at; pthread_t t; void *rv; size_t ss = 8u << 20;
    void *stk = mmap(NULL, ss, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_32BIT, -1, 0);
    assert(stk != MAP_FAILED);
    g_argc = argc; g_argv = argv;
    pthread_attr_init(&at); pthread_attr_setstack(&at, stk, ss);
    pthread_create(&t, &at, worker, NULL); pthread_join(t, &rv);
    return (int)(intptr_t)rv;
}
