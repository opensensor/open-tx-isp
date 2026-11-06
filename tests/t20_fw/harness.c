/*
 * T20/T10 firmware differential harness: host-side environment.
 *
 * Runs driver/t20/tx_isp_t20_firmware.c (built as i386, see Makefile) through
 * a deterministic scenario and prints a trace whose every line must be
 * identical between two builds of the firmware unit (e.g. -O0 vs -Os, or
 * -O0 with two different stack-poison patterns).  Everything the firmware
 * does to its environment is recorded: ISP register reads/writes, sensor
 * callbacks, sbus/I2C traffic, printk text, return values of API calls and,
 * at checkpoints, a hash of every data/bss object of the firmware unit with
 * pointers normalised to symbol+offset (so a different code layout does not
 * count as a difference).  A firmware constant that merely lies inside the
 * image is normalised too, to a different symbol per build; compare.sh then
 * re-runs both builds with dump=<object> and accepts a word only when its
 * normalised form or its raw value is identical (see there).
 *
 * Usage: t20fw-<variant> <symfile> [calib.bin] [opts]
 *   opts: v      verbose (every register access on its own line)
 *         pN     stack poison byte N (hex) before every firmware entry
 *         oem    OEM AE/AWB/NR paths (t20_simple_* = 0)
 *         trace  t20_trace_events = 1
 */
#include <stdint.h>
#include "rt.h"
#include "harness.h"

extern unsigned long rt_div0_count;

/* ------------------------------------------------------------------ */
/* trace                                                                */

static int verbose;
static uint64_t th = 0xcbf29ce484222325ULL;	/* running FNV-1a */
static unsigned long tev;			/* events since checkpoint */
static unsigned long reads, writes;
static char line[512];

static void hash_bytes(uint64_t *h, const void *p, unsigned n)
{
	const unsigned char *b = p;
	while (n--) { *h ^= *b++; *h *= 0x100000001b3ULL; }
}

static void ev(const char *s)
{
	hash_bytes(&th, s, strlen(s));
	tev++;
	if (verbose) { rt_puts(s); rt_puts("\n"); }
}

#define EVF(...) do { snprintf(line, sizeof(line), __VA_ARGS__); ev(line); } while (0)

/* ------------------------------------------------------------------ */
/* symbol table of this binary (from nm), for pointer normalisation      */

struct sym { uint32_t addr, size; char type, fw, hit; char name[64]; };
#define MAXSYM 8192
static struct sym syms[MAXSYM];
static int nsyms;
static uint32_t text_lo = 0xffffffff, text_hi, data_lo = 0xffffffff, data_hi;

static uint32_t hexval(const char **p)
{
	uint32_t v = 0;
	for (;; (*p)++) {
		char c = **p;
		if (c >= '0' && c <= '9') v = v * 16 + c - '0';
		else if (c >= 'a' && c <= 'f') v = v * 16 + c - 'a' + 10;
		else break;
	}
	return v;
}

static void load_syms(const char *path)
{
	static char buf[1 << 20];
	int fd = rt_open(path, 0);
	long n, tot = 0;
	const char *p;
	if (fd < 0) { rt_printf("cannot open %s\n", path); rt_flush(); rt_exit(2); }
	while ((n = rt_read(fd, buf + tot, sizeof(buf) - 1 - tot)) > 0) tot += n;
	rt_close(fd);
	buf[tot] = 0;
	/* "addr size type name" lines from nm -S -n --defined-only */
	for (p = buf; *p && nsyms < MAXSYM; ) {
		struct sym *s = &syms[nsyms];
		int i = 0;
		s->addr = hexval(&p); if (*p != ' ') goto skip; p++;
		s->size = hexval(&p); if (*p != ' ') goto skip; p++;
		s->type = *p++; if (*p != ' ') goto skip; p++;
		while (*p && *p != '\n' && *p != ' ' && i < 63) s->name[i++] = *p++;
		s->name[i] = 0;
		/* GCC numbers function-local statics (foo.3); the number is not
		 * stable across optimisation levels */
		while (i > 0 && s->name[i - 1] >= '0' && s->name[i - 1] <= '9') i--;
		if (i > 0 && i < (int)strlen(s->name) && s->name[i - 1] == '.') s->name[i - 1] = 0;
		s->fw = (p[0] == ' ' && p[1] == 'F');
		if (s->type == 'T' || s->type == 't') {
			if (s->addr < text_lo) text_lo = s->addr;
			if (s->addr + s->size > text_hi) text_hi = s->addr + s->size;
		} else {
			if (s->addr < data_lo) data_lo = s->addr;
			if (s->addr + s->size > data_hi) data_hi = s->addr + s->size;
		}
		nsyms++;
skip:
		while (*p && *p != '\n') p++;
		if (*p) p++;
	}
}

static const struct sym *sym_of(uint32_t a)
{
	int lo = 0, hi = nsyms - 1, best = -1;
	while (lo <= hi) {
		int m = (lo + hi) / 2;
		if (syms[m].addr <= a) { best = m; lo = m + 1; } else hi = m - 1;
	}
	while (best >= 0 && !(a < syms[best].addr + (syms[best].size ? syms[best].size : 1))) best--;
	if (best >= 0 && a - syms[best].addr < (syms[best].size ? syms[best].size : 1))
		return &syms[best];
	return 0;
}

/* Hash one 32-bit word, replacing in-image pointers by symbol+offset. */
static void hash_word(uint64_t *h, uint32_t w)
{
	if ((w >= text_lo && w < text_hi) || (w >= data_lo && w < data_hi)) {
		const struct sym *s = sym_of(w);
		if (s) {
			uint32_t off = w - s->addr;
			hash_bytes(h, "P", 1);
			hash_bytes(h, s->name, strlen(s->name));
			hash_bytes(h, &off, 4);
			return;
		}
	}
	if (w >= (uint32_t)(uintptr_t)harness_stack_lo() && w < (uint32_t)(uintptr_t)harness_stack_hi()) {
		hash_bytes(h, "S", 1);	/* stack address: value not comparable */
		return;
	}
	hash_bytes(h, &w, 4);
}

static int is_fw_object(const struct sym *s)
{
	/* data/bss objects of the firmware unit: harness/rt/calib objects are
	 * prefixed or listed in harness_own_object() */
	if (s->type != 'd' && s->type != 'D' && s->type != 'b' && s->type != 'B')
		return 0;
	return s->fw;
}

/* Hash all firmware data objects; print one line per object if verbose,
 * else one line for the total.  Objects missing in one build simply do not
 * appear (reported by the comparison as a line diff only in verbose mode). */
static const char *dump_obj;

/* n-th firmware object with this (suffix-stripped) name, in address order */
static int dup_index(int idx)
{
	int i, n = 0;
	for (i = 0; i < idx; i++)
		if (syms[i].fw && !strcmp(syms[i].name, syms[idx].name))
			n++;
	return n;
}

static void checkpoint(const char *tag)
{
	uint64_t all = 0xcbf29ce484222325ULL;
	int i;
	for (i = 0; i < nsyms; i++) {
		const struct sym *s = &syms[i];
		uint64_t h = 0xcbf29ce484222325ULL;
		uint32_t a;
		if (!is_fw_object(s) || !s->size)
			continue;
		for (a = 0; a + 4 <= s->size; a += 4)
			hash_word(&h, *(const uint32_t *)(uintptr_t)(s->addr + a));
		if (a < s->size)
			hash_bytes(&h, (const void *)(uintptr_t)(s->addr + a), s->size - a);
		rt_printf("STATE %s %s#%d %08x%08x\n", tag, s->name, dup_index(i), (unsigned)(h >> 32), (unsigned)h);
		if (dump_obj && !strcmp(dump_obj, s->name)) {
			for (a = 0; a + 4 <= s->size; a += 4) {
				uint32_t w = *(const uint32_t *)(uintptr_t)(s->addr + a);
				uint64_t wh = 0;
				hash_word(&wh, w);
				rt_printf("DUMP %s %s#%d+%04x %08x %08x%08x\n", tag, s->name, dup_index(i), a, w, (unsigned)(wh >> 32), (unsigned)wh);
			}
		}
		hash_bytes(&all, s->name, strlen(s->name));
		hash_bytes(&all, &h, 8);
	}
	rt_printf("CP %-24s events=%lu trace=%08x%08x state=%08x%08x\n", tag, tev,
		  (unsigned)(th >> 32), (unsigned)th, (unsigned)(all >> 32), (unsigned)all);
	tev = 0;
}

/* function coverage (variant "cov", -finstrument-functions) */
static int cov_on;
__attribute__((no_instrument_function)) void __cyg_profile_func_enter(void *fn, void *site)
{
	int lo = 0, hi = nsyms - 1;
	uint32_t a = (uint32_t)(uintptr_t)fn;
	(void)site;
	while (lo <= hi) {
		int m = (lo + hi) / 2;
		if (syms[m].addr == a) { syms[m].hit = 1; return; }
		if (syms[m].addr < a) lo = m + 1; else hi = m - 1;
	}
}
__attribute__((no_instrument_function)) void __cyg_profile_func_exit(void *fn, void *site) { (void)fn; (void)site; }

static void cov_report(void)
{
	int i;
	for (i = 0; i < nsyms; i++)
		if (syms[i].fw && (syms[i].type == 't' || syms[i].type == 'T'))
			rt_printf("COV %s %s %d %x\n", syms[i].hit ? "hit" : "miss", syms[i].name, i, syms[i].addr);
}

/* ------------------------------------------------------------------ */
/* ISP register file                                                    */

#define REG_SPACE 0x20000
static uint8_t regs[REG_SPACE] __attribute__((aligned(4)));
static unsigned frame_no;
static unsigned access_budget;

static void budget(void)
{
	if (++access_budget > 20000000u) {
		rt_printf("ABORT: >20M register accesses in one firmware entry (poll loop?)\n");
		rt_flush();
		rt_exit(3);
	}
}

static uint32_t reg_rd(uint32_t off, int w)
{
	uint32_t v = 0;
	budget();
	reads++;
	if (off + w > REG_SPACE) { EVF("R%d OOB %x", w * 8, off); return 0; }
	memcpy(&v, regs + off, w);
	if (verbose) EVF("R%d %05x %x", w * 8, off, v);
	else { hash_bytes(&th, "R", 1); hash_bytes(&th, &off, 4); hash_bytes(&th, &v, 4); tev++; }
	return v;
}

static void reg_wr(uint32_t off, uint32_t v, int w)
{
	budget();
	writes++;
	if (off + w > REG_SPACE) { EVF("W%d OOB %x %x", w * 8, off, v); return; }
	memcpy(regs + off, &v, w);
	if (verbose) EVF("W%d %05x %x", w * 8, off, v);
	else { hash_bytes(&th, "W", 1); hash_bytes(&th, &off, 4); hash_bytes(&th, &v, 4); tev++; }
}

int32_t system_isp_read_32(uint32_t o) { return (int32_t)reg_rd(o, 4); }
uint32_t system_isp_read_16(uint32_t o) { return reg_rd(o, 2); }
uint32_t system_isp_read_8(uint32_t o) { return reg_rd(o, 1); }
void system_isp_write_32(uint32_t o, uint32_t v) { reg_wr(o, v, 4); }
int16_t *system_isp_write_16(uint32_t o, uint16_t v) { reg_wr(o, v, 2); return 0; }
char *system_isp_write_8(uint32_t o, uint8_t v) { reg_wr(o, v, 1); return 0; }

/* ------------------------------------------------------------------ */
/* scene model: statistics written into the register file each frame     */

static uint32_t rng;
static uint32_t prand(void) { rng = rng * 1664525u + 1013904223u; return rng >> 8; }

static int32_t scene_ev;	/* scene luminance, log2 Q16 */
static int32_t cur_exp_log2;	/* sensor exposure product, log2 Q16 */
static uint32_t cur_int_time = 500, cur_again_code, cur_dgain_code;
static int ct_bias;		/* colour temperature skew of AWB zones */

static uint32_t hist_pack(uint32_t v)
{
	/* inverse of ae_read_full_histogram_data(): 12-bit mantissa, 4-bit exp */
	uint32_t e = 0;
	if (v < 0x1000) return v;
	while (v >= 0x2000 && e < 14) { v >>= 1; e++; }
	return ((e + 1) << 12) | (v & 0xfff);
}

static void fill_stats(void)
{
	/* mean output level in 0..255 from scene * exposure (log domain) */
	int32_t lvl_log2 = scene_ev + cur_exp_log2 - (24 << 16);
	int32_t mean;
	unsigned i;
	if (lvl_log2 > (8 << 16)) mean = 255;
	else if (lvl_log2 < 0) mean = 1;
	else mean = (int32_t)(math_exp2_host(lvl_log2) >> 16);
	if (mean > 255) mean = 255;
	if (mean < 1) mean = 1;
	rng = 0x1234567u + frame_no * 7919u + (uint32_t)scene_ev;
	/* AE 256-bin histogram at 0x10000, total ~ 1920*1080/16 */
	for (i = 0; i < 256; i++) {
		int d = (int)i - mean;
		uint32_t cnt = d * d < 2500 ? (uint32_t)(2500 - d * d) * 3 + (prand() & 63) : (prand() & 7);
		if (i == 255 && mean > 230) cnt += 40000;
		*(uint32_t *)(regs + 0x10000 + i * 4) = hist_pack(cnt);
	}
	/* rest of the statistics/metering memory: AWB zones, AF, etc. */
	for (i = 0x10400; i < REG_SPACE; i += 4) {
		uint32_t r = (uint32_t)(mean * 4 + ct_bias + (prand() & 15));
		uint32_t b = (uint32_t)(mean * 4 - ct_bias + (prand() & 15));
		*(uint32_t *)(regs + i) = (r & 0xfff) | ((b & 0xfff) << 16) | (prand() & 0x0000f000);
	}
}

/* ------------------------------------------------------------------ */
/* sensor control (mirror of SDK sensor_drv.h, SENSOR_EXP_NUMBER == 1)   */

struct h_sbus {
	uint32_t mask; uint8_t device; uint32_t control; void *p_control;
	void *read_sample; void *write_sample;
};
struct h_sctx { uint16_t again, dgain; uint8_t n_context, wdr_mode; uint16_t again_x2, dgain_coarse, dgain_fine; uint8_t cbgi; };
struct h_res { uint16_t width, height; };
struct h_param {
	uint8_t mode; struct h_res total, active; struct h_sctx ctx;
	int32_t again_log2_max, dgain_log2_max;
	uint32_t it_min, it_max, it_long_max, it_limit;
	uint16_t day_it_max; uint8_t it_delay, again_delay, dgain_delay;
	int32_t xoffset, yoffset, anti_flicker_pos; uint32_t lines_per_second;
};
struct h_ctrl {
	struct h_sbus sbus;
	struct h_param param;
	void (*hw_reset_disable)(void);
	void (*hw_reset_enable)(void);
	int32_t (*alloc_analog_gain)(int32_t, struct h_sctx *);
	int32_t (*alloc_digital_gain)(int32_t, struct h_sctx *);
	void (*alloc_integration_time)(uint16_t *, struct h_sctx *);
	void (*set_integration_time)(void *, uint16_t, struct h_param *);
	void (*start_changes)(void *, struct h_sctx *);
	void (*end_changes)(void *, struct h_sctx *);
	void (*set_analog_gain)(void *, uint32_t, struct h_sctx *);
	void (*set_digital_gain)(void *, uint32_t, struct h_sctx *);
	uint16_t (*get_normal_fps)(struct h_param *);
	uint16_t (*read_black_pedestal)(void *, int, uint32_t);
	void (*set_mode)(void *, uint8_t, struct h_param *);
	void (*set_wdr_mode)(void *, uint8_t, struct h_param *);
	uint8_t (*fps_control)(void *, uint8_t, struct h_param *);
	uint16_t (*get_id)(void *);
	void (*disable_isp)(void *);
	uint32_t (*get_lines_per_second)(void *, struct h_param *);
};
_Static_assert(sizeof(struct h_sbus) == 24, "sbus");
_Static_assert(sizeof(struct h_param) == 72, "param");
_Static_assert(__builtin_offsetof(struct h_ctrl, hw_reset_enable) == 0x64, "ctrl");
_Static_assert(__builtin_offsetof(struct h_ctrl, set_mode) == 0x90, "ctrl");

#define JX_TOTAL_W 2560
#define JX_TOTAL_H 1125
#define JX_MAX_AGAIN 259142	/* log2(15.5) Q16 */
#define JX_FPS ((25 << 16) | 1)

static void s_hw_reset_disable(void) { ev("SENS hw_reset_disable"); }
static void s_hw_reset_enable(void) { ev("SENS hw_reset_enable"); }
static int32_t s_alloc_again(int32_t g, struct h_sctx *c)
{
	int32_t q;
	if (g < 0) g = 0;
	if (g > JX_MAX_AGAIN) g = JX_MAX_AGAIN;
	q = g & ~0xfff;		/* 1/16 EV steps */
	c->again = (uint16_t)(q >> 12);
	EVF("SENS alloc_again %d -> %d code %u", g, q, c->again);
	return q;
}
static int32_t s_alloc_dgain(int32_t g, struct h_sctx *c)
{
	EVF("SENS alloc_dgain %d", g);
	c->dgain = 0;
	return 0;
}
static void s_alloc_it(uint16_t *t, struct h_sctx *c)
{
	uint16_t in = *t;
	(void)c;
	if (*t < 2) *t = 2;
	if (*t > JX_TOTAL_H - 5) *t = JX_TOTAL_H - 5;
	EVF("SENS alloc_it %u -> %u", in, *t);
}
uint32_t log2_fixed_to_fixed(uint32_t v, int in_prec, uint8_t out_prec);
static void oem_exposure(void)
{
	cur_exp_log2 = (int32_t)log2_fixed_to_fixed(cur_int_time ? cur_int_time : 1, 0, 16) +
		       (int32_t)(cur_again_code << 12) + (2 << 16);
}
static void s_set_it(void *b, uint16_t t, struct h_param *p) { (void)b; (void)p; cur_int_time = t; oem_exposure(); EVF("SENS set_it %u", t); }
static void s_start(void *b, struct h_sctx *c) { (void)b; (void)c; ev("SENS start_changes"); }
static void s_end(void *b, struct h_sctx *c) { (void)b; (void)c; ev("SENS end_changes"); }
static void s_set_again(void *b, uint32_t v, struct h_sctx *c) { (void)b; (void)c; cur_again_code = v; oem_exposure(); EVF("SENS set_again %u", v); }
static void s_set_dgain(void *b, uint32_t v, struct h_sctx *c) { (void)b; (void)c; cur_dgain_code = v; EVF("SENS set_dgain %u", v); }
static uint16_t s_fps(struct h_param *p) { (void)p; ev("SENS get_normal_fps"); return 25 << 8; }
static uint16_t s_black(void *b, int i, uint32_t g) { (void)b; EVF("SENS black %d %u", i, g); return 0; }
static void s_set_mode(void *b, uint8_t m, struct h_param *p)
{
	(void)b;
	EVF("SENS set_mode %u", m);
	p->active.width = 1920; p->active.height = 1080;
	p->total.width = JX_TOTAL_W; p->total.height = JX_TOTAL_H;
	p->it_min = 2; p->it_max = JX_TOTAL_H - 5; p->it_long_max = JX_TOTAL_H - 5;
	p->it_limit = JX_TOTAL_H - 5; p->mode = m;
}
static void s_set_wdr(void *b, uint8_t m, struct h_param *p) { (void)b; (void)p; EVF("SENS set_wdr %u", m); }
static uint8_t s_fps_ctl(void *b, uint8_t f, struct h_param *p)
{
	(void)b;
	EVF("SENS fps_control %u", f);
	p->total.width = JX_TOTAL_W; p->total.height = JX_TOTAL_H;
	p->it_min = 2; p->it_max = JX_TOTAL_H - 5; p->it_long_max = JX_TOTAL_H - 5;
	p->it_limit = JX_TOTAL_H - 5;
	return 25;
}
static uint16_t s_get_id(void *b) { (void)b; ev("SENS get_id"); return 0x0f23; }
static void s_disable_isp(void *b) { (void)b; ev("SENS disable_isp"); }
static uint32_t s_lps(void *b, struct h_param *p) { (void)b; (void)p; ev("SENS lines_per_second"); return 0; }

int32_t sensor_init(int32_t *arg)
{
	struct h_ctrl *c = (struct h_ctrl *)arg;
	ev("SENS sensor_init");
	c->sbus.mask = 0x0f; c->sbus.device = 0x40;
	apical_sbus_i2c_init(&c->sbus);
	c->param.again_log2_max = JX_MAX_AGAIN;
	c->param.dgain_log2_max = 0;
	c->param.it_delay = 2; c->param.again_delay = 2; c->param.dgain_delay = 2;
	c->hw_reset_disable = s_hw_reset_disable;
	c->hw_reset_enable = s_hw_reset_enable;
	c->alloc_analog_gain = s_alloc_again;
	c->alloc_digital_gain = s_alloc_dgain;
	c->alloc_integration_time = s_alloc_it;
	c->set_integration_time = s_set_it;
	c->start_changes = s_start;
	c->end_changes = s_end;
	c->set_analog_gain = s_set_again;
	c->set_digital_gain = s_set_dgain;
	c->get_normal_fps = s_fps;
	c->read_black_pedestal = s_black;
	c->set_mode = s_set_mode;
	c->set_wdr_mode = s_set_wdr;
	c->fps_control = s_fps_ctl;
	c->get_id = s_get_id;
	c->disable_isp = s_disable_isp;
	c->get_lines_per_second = s_lps;
	return 0;
}

int tx_isp_t20_simple_ae_apply(int32_t *total, uint32_t *it, int32_t *again_log2,
			       uint32_t *again_code, const uint8_t *steps, uint32_t nsteps)
{
	int32_t t, ilog, g;
	uint32_t i;
	if (!total) return -19;
	t = *total;
	if (t < 0) t = (9 << 16) + ((int32_t)stab[28] << 11);
	if (t < (1 << 16)) t = 1 << 16;
	if (t > (10 << 16) + JX_MAX_AGAIN) t = (10 << 16) + JX_MAX_AGAIN;
	*total = t;
	ilog = t > (10 << 16) ? (10 << 16) : t;	/* 1024 lines max */
	g = t - ilog;
	g &= ~0xfff;
	cur_int_time = (uint32_t)(math_exp2_host(ilog) >> 16);
	cur_again_code = (uint32_t)g >> 12;
	cur_exp_log2 = ilog + g + (2 << 16);
	EVF("SENS simple_ae_apply total=%d it=%u again=%d code=%u steps=%u",
	    t, cur_int_time, g, cur_again_code, nsteps);
	for (i = 0; steps && i < nsteps; i++)
		EVF("SENS   step %u %u", steps[i * 2], steps[i * 2 + 1]);
	if (it) *it = cur_int_time;
	if (again_log2) *again_log2 = g;
	if (again_code) *again_code = cur_again_code;
	return 0;
}

/* ------------------------------------------------------------------ */
/* remaining externals                                                  */

static struct { int32_t fn, arg; } irq_handler[16];
int32_t system_set_interrupt_handler(int32_t idx, int32_t fn, int32_t arg)
{
	EVF("IRQ register %d", idx);
	if (idx >= 0 && idx < 16) { irq_handler[idx].fn = fn; irq_handler[idx].arg = arg; }
	return 0;
}
int32_t system_init_interrupt(void) { ev("IRQ init"); return 0; }
static int irq_off;
int32_t system_hw_interrupts_disable(void) { irq_off++; return 0; }
int32_t system_hw_interrupts_enable(void) { irq_off--; return 0; }
int32_t *init_semaphore(uintptr_t a) { (void)a; ev("SEM init"); return 0; }
int32_t destroy_semaphore(uintptr_t a) { (void)a; ev("SEM destroy"); return 0; }
static unsigned sem_raised;
int32_t raise_semaphore(uintptr_t a) { (void)a; sem_raised++; return 0; }
int32_t wait_semaphore(uintptr_t a, uint32_t t) { (void)a; EVF("SEM wait %u pending=%u", t, sem_raised); sem_raised = 0; return 0; }
uint32_t system_timer_timestamp(void) { return frame_no * 40000u; }
int32_t system_timer_frequency(void) { return 1000000; }
int32_t system_timer_init(void) { ev("TIMER init"); return 0; }
void usleep_range(unsigned long a, unsigned long b) { EVF("usleep %lu %lu", a, b); }
int32_t I2C_init(void) { ev("I2C init"); return 0; }
int32_t I2C_write(int32_t add, char *data, int32_t size)
{
	int i;
	snprintf(line, sizeof(line), "I2C w %x n=%d", add, size);
	for (i = 0; i < size && i < 8; i++) { size_t l = strlen(line); snprintf(line + l, sizeof(line) - l, " %02x", (unsigned char)data[i]); }
	ev(line);
	return size;
}
int32_t I2C_read(int32_t a, int32_t b, int32_t c) { EVF("I2C r %x %x", a, c); (void)b; return 0; }
int32_t spi_rw32(void) { ev("SPI rw32"); return 0; }
int32_t spi_rw48(void) { ev("SPI rw48"); return 0; }
int32_t spi_init_access(void) { ev("SPI init"); return 0; }
void init_sensor_interface(void) { ev("SIF init"); }
int32_t reset_sensor_interface(void) { ev("SIF reset"); return 0; }
int32_t load_sensor_interface(void) { ev("SIF load"); return 0; }
/*
 * Sensor register sequence
 *
 * load_isp_sequence() asks the driver for the sensor's register table through
 * apical_custom_sequence(); the stock driver answers with the table of the
 * detected sensor out of the tuning data.  Returning nothing keeps the whole
 * sequence interpreter plus the sbus layer dark, so the harness answers with a
 * small table made of the opcodes sensor_load_binary_sequence() understands:
 *
 *   after a 4-entry u16 offset table:
 *     0x00           end of this sequence
 *     0x01 lo hi     offset = 16-bit value
 *     0x02 b0..b3    offset = 32-bit value
 *     0x10 n         offset += n
 *     0x11 n         offset -= n
 *     0xe0/e1/e2     sleep (8/16/32 bit argument)
 *     0x2n d0..dn    write n+1 bytes at offset+reg
 *     0x3n r d..d m..m  read-modify-write n+1 bytes (n+1 data, n+1 mask bytes)
 *     0xfn           run sequence n, then carry on
 *
 * Unused bytes stay 0, so a lookup past the end ends instead of walking out of
 * the buffer.  The two-byte and four-byte read-modify-write forms are the ones
 * that exercise the sbus read path, the rest the write path.  Register
 * addresses are kept small so they land in the harness register file.
 */
#define SEQ_SIZE 192
static uint8_t sensor_seq[SEQ_SIZE];
static int sensor_seq_on;

static uint8_t *sensor_seq_put(uint8_t *p, uint8_t b) { *p++ = b; return p; }

static void sensor_seq_build(void)
{
	uint8_t *w;
	uint8_t *s1;
	uint8_t *s2;
	uint8_t *s3;
	uint16_t off[4];

	memset(sensor_seq, 0, sizeof(sensor_seq));
	w = sensor_seq + 8;	/* room for the four offsets */

	/* sequence 0: WDR sensor table, the one load_isp_sequence(0) asks for */
	w = sensor_seq_put(w, 0x01); w = sensor_seq_put(w, 0x00); w = sensor_seq_put(w, 0x03);	/* offset 0x0300 */
	w = sensor_seq_put(w, 0x20); w = sensor_seq_put(w, 0x00); w = sensor_seq_put(w, 0x01);	/* 1 byte  @0x300 */
	w = sensor_seq_put(w, 0x21); w = sensor_seq_put(w, 0x02);				/* 2 bytes @0x302 */
	w = sensor_seq_put(w, 0x11); w = sensor_seq_put(w, 0x22);
	w = sensor_seq_put(w, 0x23); w = sensor_seq_put(w, 0x04);				/* 4 bytes @0x304 */
	w = sensor_seq_put(w, 0xaa); w = sensor_seq_put(w, 0xbb); w = sensor_seq_put(w, 0xcc); w = sensor_seq_put(w, 0xdd);
	w = sensor_seq_put(w, 0xe0); w = sensor_seq_put(w, 0x01);				/* sleep 1 ms */
	w = sensor_seq_put(w, 0x31); w = sensor_seq_put(w, 0x08);				/* rmw 2 bytes @0x308 */
	w = sensor_seq_put(w, 0x5a); w = sensor_seq_put(w, 0x0f);
	w = sensor_seq_put(w, 0x33); w = sensor_seq_put(w, 0x0c);				/* rmw 4 bytes @0x30c */
	w = sensor_seq_put(w, 0x01); w = sensor_seq_put(w, 0x02); w = sensor_seq_put(w, 0x03); w = sensor_seq_put(w, 0x04);
	w = sensor_seq_put(w, 0xff); w = sensor_seq_put(w, 0x00); w = sensor_seq_put(w, 0xff); w = sensor_seq_put(w, 0x00);
	w = sensor_seq_put(w, 0x30); w = sensor_seq_put(w, 0x10);				/* rmw 1 byte @0x310 */
	w = sensor_seq_put(w, 0x0f); w = sensor_seq_put(w, 0xf0);
	w = sensor_seq_put(w, 0x10); w = sensor_seq_put(w, 0x10);				/* offset += 0x10 */
	w = sensor_seq_put(w, 0x20); w = sensor_seq_put(w, 0x00); w = sensor_seq_put(w, 0x02);	/* 1 byte  @0x320 */
	w = sensor_seq_put(w, 0x11); w = sensor_seq_put(w, 0x08);				/* offset -= 8 */
	w = sensor_seq_put(w, 0x20); w = sensor_seq_put(w, 0x00); w = sensor_seq_put(w, 0x03);	/* 1 byte  @0x318 */
	w = sensor_seq_put(w, 0x02);								/* offset = 0x400 */
	w = sensor_seq_put(w, 0x00); w = sensor_seq_put(w, 0x04); w = sensor_seq_put(w, 0x00); w = sensor_seq_put(w, 0x00);
	w = sensor_seq_put(w, 0xe1); w = sensor_seq_put(w, 0x02); w = sensor_seq_put(w, 0x00);	/* sleep 2 ms */
	w = sensor_seq_put(w, 0x20); w = sensor_seq_put(w, 0x01); w = sensor_seq_put(w, 0x07);	/* 1 byte  @0x401 */
	w = sensor_seq_put(w, 0xf1);								/* run sequence 1 */
	w = sensor_seq_put(w, 0x00);
	s1 = w;

	/* sequence 1: WDR-off table, also used as a sub-sequence from entry 0 */
	w = sensor_seq_put(w, 0x01); w = sensor_seq_put(w, 0x00); w = sensor_seq_put(w, 0x05);	/* offset 0x0500 */
	w = sensor_seq_put(w, 0x21); w = sensor_seq_put(w, 0x00);				/* 2 bytes @0x500 */
	w = sensor_seq_put(w, 0x34); w = sensor_seq_put(w, 0x12);
	w = sensor_seq_put(w, 0xe2);								/* sleep 3 ms */
	w = sensor_seq_put(w, 0x03); w = sensor_seq_put(w, 0x00); w = sensor_seq_put(w, 0x00); w = sensor_seq_put(w, 0x00);
	w = sensor_seq_put(w, 0x32); w = sensor_seq_put(w, 0x10);				/* rmw 2 bytes @0x510 */
	w = sensor_seq_put(w, 0x34); w = sensor_seq_put(w, 0x12); w = sensor_seq_put(w, 0xff); w = sensor_seq_put(w, 0x0f);
	w = sensor_seq_put(w, 0x20); w = sensor_seq_put(w, 0x20); w = sensor_seq_put(w, 0x00);	/* 1 byte  @0x520 */
	w = sensor_seq_put(w, 0x00);
	s2 = w;

	/* sequence 2: the table apical_init() asks for at start-up */
	w = sensor_seq_put(w, 0x01); w = sensor_seq_put(w, 0x00); w = sensor_seq_put(w, 0x06);	/* offset 0x0600 */
	w = sensor_seq_put(w, 0x23); w = sensor_seq_put(w, 0x00);				/* 4 bytes @0x600 */
	w = sensor_seq_put(w, 0x11); w = sensor_seq_put(w, 0x22); w = sensor_seq_put(w, 0x33); w = sensor_seq_put(w, 0x44);
	w = sensor_seq_put(w, 0x31); w = sensor_seq_put(w, 0x40);				/* rmw 2 bytes @0x640 */
	w = sensor_seq_put(w, 0x00); w = sensor_seq_put(w, 0x80);
	w = sensor_seq_put(w, 0x00);
	s3 = w;

	off[0] = 8;						/* sequence 0 starts right after the table */
	off[1] = (uint16_t)(s1 - sensor_seq);
	off[2] = (uint16_t)(s2 - sensor_seq);
	off[3] = (uint16_t)(s3 - sensor_seq);
	memcpy(sensor_seq, off, sizeof(off));
}

int32_t apical_custom_sequence(void)
{
	ev("custom_sequence");
	if (!sensor_seq_on)
		return 0;
	sensor_seq_build();
	return (int32_t)(uintptr_t)sensor_seq;
}
uint32_t apical_custom_initialization(void) { ev("custom_initialization"); return 0; }
bool tx_isp_t20_fw_parked(void) { return 0; }
unsigned char stab[60] __attribute__((aligned(4)));

void t20fw_bug(const char *file, int line_no)
{
	rt_printf("BUG() at %s:%d\n", file, line_no);
	rt_flush();
	rt_exit(4);
}

int printk(const char *fmt, ...)
{
	char b[512];
	va_list ap;
	char *p;
	va_start(ap, fmt);
	vsnprintf(b, sizeof(b), fmt, ap);
	va_end(ap);
	/* %p values are addresses: not comparable across builds */
	for (p = b; (p = (char *)strstr_h(p, "0x")) != 0; ) {
		char *q = p + 2;
		uint32_t v = 0;
		while ((*q >= '0' && *q <= '9') || (*q >= 'a' && *q <= 'f')) { v = v * 16 + (*q <= '9' ? *q - '0' : *q - 'a' + 10); q++; }
		if (q - p > 6 && ((v >= text_lo && v < text_hi) || (v >= data_lo && v < data_hi) ||
				  (v >= (uint32_t)(uintptr_t)harness_stack_lo() && v < (uint32_t)(uintptr_t)harness_stack_hi()))) {
			const struct sym *s = sym_of(v);
			char r[96];
			size_t rl;
			if (s) snprintf(r, sizeof(r), "<%s+%x>", s->name, v - s->addr);
			else snprintf(r, sizeof(r), "<stack>");
			rl = strlen(r);
			memmove_h(p + rl, q, strlen(q) + 1);
			memcpy(p, r, rl);
			p += rl;
		} else
			p = q;
	}
	snprintf(line, sizeof(line), "PRINTK %s", b);
	{ size_t l = strlen(line); while (l && line[l - 1] == '\n') line[--l] = 0; }
	ev(line);
	return 0;
}

/* ------------------------------------------------------------------ */
/* firmware entry wrappers (stack poisoning)                            */

static int poison = -1;
static char *stack_lo_mark, *stack_hi_mark;
void *harness_stack_lo(void) { return stack_lo_mark; }
void *harness_stack_hi(void) { return stack_hi_mark; }

__attribute__((noinline)) static void poison_below(void)
{
	char here;
	char *top = &here - 256;
	if (poison < 0) return;
	memset(top - (256 << 10), poison, 256 << 10);
}

#define ENTER() do { poison_below(); access_budget = 0; } while (0)

static void irq(int idx)
{
	ENTER();
	if (irq_handler[idx].fn) {
		int32_t r = ((int32_t (*)(int32_t))irq_handler[idx].fn)(irq_handler[idx].arg);
		EVF("IRQ %d ret %d", idx, r);
	}
}

static void process(void)
{
	int32_t r;
	ENTER();
	r = apical_process();
	EVF("process ret %d", r);
}

static void cmd_process(void)
{
	int32_t r;
	ENTER();
	r = apical_cmd_process();
	EVF("cmd_process ret %d", r);
}

static void cmd(uint32_t type, uint32_t id, uint32_t val, uint32_t dir)
{
	uint32_t ret = 0xdeadbeef;
	int32_t st;
	ENTER();
	st = apical_command(type, id, val, dir, &ret);
	EVF("CMD %u 0x%x %u %s -> st=%d ret=%u", type, id, val, dir ? "GET" : "SET", st, ret);
}

static void frame(void)
{
	frame_no++;
	fill_stats();
	/* AE state readback for the log */
	irq(7);		/* frame start */
	irq(3);		/* AE statistics */
	irq(4);		/* AWB statistics */
	irq(5);		/* FR / DS1 / DS2 frame buffer */
	irq(6);
	irq(12);
	irq(0);		/* frame end */
	/* isp_fw_process(): apical_process(); apical_cmd_process(); */
	process();
	cmd_process();
	process();
	cmd_process();
}

/* ------------------------------------------------------------------ */

static int hexarg(const char *s) { int v = 0; for (; *s; s++) v = v * 16 + (*s <= '9' ? *s - '0' : (*s | 32) - 'a' + 10); return v; }

/*
 * Register poke: the type 5 ids 0x7c..0x7f are the debug access the vendor
 * tool uses (address, size, source, value) and type 6 adds exposure_log2 /
 * gain_log2.  The default and extended runs never touch them.  This is a
 * separate invocation because the value/size/source triple selects an interior
 * pointer of the firmware context to read or write through, which cannot be
 * checked from the harness.
 */
static void poke_scenario(void)
{
	static const uint32_t sizes[] = { 8, 0x10, 0x20 };
	static const uint32_t sources[] = { 0x5b, 0x5d, 0x5e, 0 };
	static const uint32_t addrs[] = { 0x400, 0x300, 0x200, 0x0 };
	unsigned a, s, z;

	for (s = 0; s < sizeof(sources) / sizeof(sources[0]); s++) {
		cmd(5, 0x7e, sources[s], 0);	/* register_source */
		cmd(5, 0x7e, 0, 1);
		for (z = 0; z < sizeof(sizes) / sizeof(sizes[0]); z++) {
			cmd(5, 0x7d, sizes[z], 0);	/* register_size */
			cmd(5, 0x7d, 0, 1);
			for (a = 0; a < sizeof(addrs) / sizeof(addrs[0]); a++) {
				cmd(5, 0x7c, addrs[a], 0);	/* register_address */
				cmd(5, 0x7c, 0, 1);
				cmd(5, 0x7f, 0x5a, 0);		/* value -> write */
				cmd(5, 0x7f, 0, 1);		/* value -> read back */
				frame();
			}
		}
	}
	cmd(6, 0x80, 0, 1);		/* exposure_log2 */
	cmd(6, 0x81, 0, 1);		/* gain_log2 */
	checkpoint("poke-register");
}

/*
 * Extended scenario: the parts of the API the default run deliberately leaves
 * alone because they re-initialise blocks of the pipeline, plus read-back of
 * values the default run only writes.  Run as its own invocation so the default
 * run keeps its frozen trace.
 */
static void ext_scenario(void)
{
	static const uint32_t wdr_modes[] = { 1, 0, 2, 0 };
	static const uint32_t vals[] = { 0, 1, 2, 0x32, 0x80, 0xff };
	static const uint32_t ae_modes[] = { 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a };
	static const uint32_t api_knobs[] = {
		AE_MODE_ID_H, AWB_MODE_ID_H, AE_COMPENSATION_ID_H, ANTIFLICKER_MODE_ID_H,
		SYSTEM_MAX_SENSOR_ANALOG_GAIN_H, SYSTEM_EXPOSURE_DARK_TARGET_H,
	};
	unsigned i, v, f, g;

	/* 1. active image switch.  resolution_active_image() only does work for a
	 *    value of 4 or 5: it stages the new pipe, raises a general FSM event
	 *    and calls apical_init_calibrations(), which loads the sensor isp
	 *    sequence again.  The default run never gets past the early return. */
	cmd(2, 0x3f, 4, 0);
	for (f = 0; f < 4; f++) frame();
	cmd(2, 0x3f, 5, 0);
	for (f = 0; f < 4; f++) frame();
	cmd(2, 0x3f, 1, 1);
	checkpoint("ext-resolution");

	/* 2. sensor frame rate: set_sensor_fps() indexes fps_table[] for 6..11 and
	 *    calls the sensor op, which the default run never reaches. */
	for (i = 6; i <= 11; i++) {
		cmd(2, 0x40, i, 0);
		frame();
		cmd(2, 0x40, 0, 1);
	}
	checkpoint("ext-fps");

	/* 3. WDR on / off / HDR on / off: general_set_wdr_mode() loads the isp
	 *    sequences 0 and 1 back to back and switches the shading mesh. */
	for (i = 0; i < sizeof(wdr_modes) / sizeof(wdr_modes[0]); i++) {
		cmd(2, 0x45, wdr_modes[i], 0);
		for (f = 0; f < 4; f++) frame();
		cmd(2, 0x45, 0, 1);
	}
	checkpoint("ext-wdr");

	/* 3b. the WDR statistics interrupt (IRQ 10, apical_interrupt_fpga_frame_wdr):
	 *     frame() raises IRQ 7/3/4/5/6/12/0 but never 10, so the handler and the
	 *     interrupt dispatch it feeds stay cold in every other run.  It only
	 *     does work when the global stab[0] is zero, which init_stab() sets. */
	cmd(2, 0x45, 1, 0);		/* back to WDR mode 1 */
	for (f = 0; f < 4; f++) {
		frame();
		irq(10);
	}
	irq(10);
	irq(10);
	checkpoint("ext-wdr-irq");
	cmd(2, 0x45, 0, 0);

	/* 4. remaining type 2 setup block: pipe status, dvi output, orientation,
	 *    resize and crop.  Each one re-initialises part of the pipeline, which
	 *    is why the default sweep skips 0x3f..0x4d. */
	for (i = 0x41; i <= 0x4d; i++) {
		if (i == 0x45)
			continue;
		for (v = 0; v < sizeof(vals) / sizeof(vals[0]); v++) {
			cmd(2, i, vals[v], 0);
			cmd(2, i, 0, 1);
		}
		frame();
	}
	checkpoint("ext-setup");

	/* 5. ae_mode needs a frame after the switch before the next mode is set,
	 *    and the read-back path computes from the running AE state. */
	for (i = 0; i < sizeof(ae_modes) / sizeof(ae_modes[0]); i++) {
		cmd(TALGORITHMS_H, AE_MODE_ID_H, ae_modes[i], 0);
		for (f = 0; f < 3; f++) frame();
		cmd(TALGORITHMS_H, AE_MODE_ID_H, 0, 1);
		cmd(TALGORITHMS_H, AWB_MODE_ID_H, 0, 1);
	}
	checkpoint("ext-ae-modes");

	/* 6. read back every knob the default run writes, and write every id the
	 *    default sweep only reads */
	for (g = 0; g < sizeof(api_knobs) / sizeof(api_knobs[0]); g++) {
		cmd(TALGORITHMS_H, api_knobs[g], 0, 1);
		cmd(TSYSTEM_H, api_knobs[g], 0, 1);
	}
	for (i = 0x51; i <= 0x70; i++) {	/* type 3: af / ae / awb / iridix / ... */
		for (v = 0; v < sizeof(vals) / sizeof(vals[0]); v++)
			cmd(TALGORITHMS_H, i, vals[v], 0);
		cmd(TALGORITHMS_H, i, 0, 1);
		frame();
	}
	for (i = 0x71; i <= 0x7b; i++) {	/* type 4: scene / colour / output / ... */
		for (v = 0; v < sizeof(vals) / sizeof(vals[0]); v++)
			cmd(4, i, vals[v], 0);
		cmd(4, i, 0, 1);
		frame();
	}
	for (i = 0xa0; i < 0x100; i += 0x11) {	/* ids past the tables */
		cmd(1, i, 0, 1);
		cmd(2, i, 0, 1);
		cmd(3, i, 0, 1);
		cmd(4, i, 0, 1);
	}
	for (f = 0; f < 5; f++) frame();
	checkpoint("ext-readback");
}

int main(int argc, char **argv)
{
	char top;
	const char *calib = 0;
	int oem = 0, trace = 0, i, f;
	int ext = 0, poke = 0;

	stack_hi_mark = &top + 4096;
	stack_lo_mark = &top - (1 << 20);
	if (argc < 2) { rt_puts("usage: t20fw <symfile> [calib.bin|-] [v] [pXX] [oem] [trace]\n"); return 2; }
	load_syms(argv[1]);
	for (i = 2; i < argc; i++) {
		if (!strcmp(argv[i], "v")) verbose = 1;
		else if (!strcmp(argv[i], "oem")) oem = 1;
		else if (!strcmp(argv[i], "trace")) trace = 1;
		else if (!strcmp(argv[i], "ext")) ext = 1;
		else if (!strcmp(argv[i], "poke")) ext = poke = 1;
		else if (argv[i][0] == 'p' && argv[i][1]) poison = hexarg(argv[i] + 1);
		else if (!strncmp(argv[i], "dump=", 5)) dump_obj = argv[i] + 5;
		else if (!strcmp(argv[i], "cov")) cov_on = 1;
		else if (i == 2) calib = argv[i];
	}
	/* the extended runs feed the firmware a sensor register sequence */
	sensor_seq_on = ext;
	t20fw_set_knobs(oem, trace);
	rt_printf("T20FW harness: calib=%s oem=%d poison=%d syms=%d\n",
		  calib ? calib : "-", oem, poison, nsyms);

	if (calib_load(calib && strcmp(calib, "-") ? calib : 0) < 0)
		return 2;
	checkpoint("loaded");

	ENTER();
	apical_init();
	checkpoint("init");

	/* stream on, bright daylight scene: AE/AWB converge */
	scene_ev = 22 << 16; ct_bias = 40;
	for (f = 0; f < 40; f++) frame();
	checkpoint("day-converge");

	/* API: AE / AWB / anti-flicker / compensation knobs */
	cmd(TALGORITHMS_H, AE_COMPENSATION_ID_H, 160, 0);
	cmd(TALGORITHMS_H, AE_COMPENSATION_ID_H, 0, 1);
	cmd(TALGORITHMS_H, ANTIFLICKER_MODE_ID_H, 50, 0);
	cmd(TALGORITHMS_H, AE_MODE_ID_H, 0, 1);
	cmd(TALGORITHMS_H, AWB_MODE_ID_H, 0, 1);
	cmd(TSYSTEM_H, SYSTEM_MAX_SENSOR_ANALOG_GAIN_H, 160, 0);
	cmd(TSYSTEM_H, SYSTEM_EXPOSURE_DARK_TARGET_H, 0, 1);
	for (f = 0; f < 15; f++) frame();
	checkpoint("api-day");

	/* dusk: scene gets dark, AE runs into gain */
	for (f = 0; f < 30; f++) { scene_ev -= 1 << 15; frame(); }
	checkpoint("dusk");

	/* night tuning set + IR-like neutral scene */
	calib_switch_set(1);
	ct_bias = 0;
	for (f = 0; f < 30; f++) frame();
	checkpoint("night");

	/* sudden bright light at night, then back to the day set */
	scene_ev = 23 << 16;
	for (f = 0; f < 15; f++) frame();
	calib_switch_set(0);
	ct_bias = -30;
	cmd(TALGORITHMS_H, AE_COMPENSATION_ID_H, 128, 0);
	cmd(TALGORITHMS_H, ANTIFLICKER_MODE_ID_H, 0, 0);
	for (f = 0; f < 30; f++) frame();
	checkpoint("day-again");

	/* AE modes / manual exposure, each followed by frames */
	{
		static const uint32_t ae_modes[] = { 0x26, 0x27, 0x28, 0x2a, 0x29, 0x25 };
		unsigned m;
		cmd(TSYSTEM_H, 0x0d, 1, 0);	/* SYSTEM_MANUAL_EXPOSURE */
		cmd(TSYSTEM_H, 0x22, 300, 0);	/* SYSTEM_INTEGRATION_TIME */
		cmd(TSYSTEM_H, 0x24, 40, 0);	/* SYSTEM_SENSOR_ANALOG_GAIN */
		for (f = 0; f < 5; f++) frame();
		cmd(TSYSTEM_H, 0x0d, 0, 0);
		for (m = 0; m < sizeof(ae_modes) / sizeof(ae_modes[0]); m++) {
			cmd(TALGORITHMS_H, AE_MODE_ID_H, ae_modes[m], 0);
			cmd(TALGORITHMS_H, 0x58, 64, 0);	/* AE_GAIN */
			cmd(TALGORITHMS_H, 0x59, 2000, 0);	/* AE_EXPOSURE */
			for (f = 0; f < 4; f++) frame();
			cmd(TALGORITHMS_H, 0x58, 0, 1);
			cmd(TALGORITHMS_H, 0x59, 0, 1);
		}
		cmd(TALGORITHMS_H, 0x5c, 1, 0);	/* AE_FREEZE */
		for (f = 0; f < 3; f++) frame();
		cmd(TALGORITHMS_H, 0x5c, 0, 0);
		cmd(TALGORITHMS_H, ANTIFLICKER_MODE_ID_H, 60, 0);
		for (f = 0; f < 6; f++) frame();
	}
	checkpoint("ae-modes");

	/* manual white balance, then back to AUTO.  The scene has no usable
	 * AWB zones (as night/IR), so AUTO must bring back the AWB result it
	 * had before MANUAL at once instead of holding the manual gains. */
	{
		uint32_t g0[4], g1[4], g2[4];
		for (f = 0; f < 3; f++) frame();
		t20fw_awb_gains(g0);
		cmd(TALGORITHMS_H, AWB_MODE_ID_H, AWB_MANUAL_H, 0);
		cmd(TSYSTEM_H, SYSTEM_AWB_RED_GAIN_H, 200, 0);
		cmd(TSYSTEM_H, SYSTEM_AWB_BLUE_GAIN_H, 44, 0);
		for (f = 0; f < 3; f++) frame();
		t20fw_awb_gains(g1);
		cmd(TALGORITHMS_H, AWB_MODE_ID_H, AWB_AUTO_H, 0);
		frame();
		t20fw_awb_gains(g2);
		cmd(TSYSTEM_H, SYSTEM_AWB_RED_GAIN_H, 0, 1);
		cmd(TSYSTEM_H, SYSTEM_AWB_BLUE_GAIN_H, 0, 1);
		rt_printf("AWB auto %u/%u/%u/%u manual %u/%u/%u/%u auto-again %u/%u/%u/%u\n",
			  g0[0], g0[1], g0[2], g0[3], g1[0], g1[1], g1[2], g1[3],
			  g2[0], g2[1], g2[2], g2[3]);
		if (!oem && (!memcmp(g0, g1, sizeof(g0)) || memcmp(g0, g2, sizeof(g0))))
			rt_printf("FAIL: simple AWB did not return from MANUAL to the AUTO gains\n");
		for (f = 0; f < 5; f++) frame();
	}
	checkpoint("awb-manual-auto");

	/* Safe anti-fog preset (t20_antifog_request): validated, applied by the AE
	 * path between frames.  Manual Iridix at the preset strength, the upper
	 * clamp raised and restored, "off" undoes only what the preset did, the
	 * variance word 0x3c8 (opt-in) is written at frame start and put back,
	 * and a request with the Iridix block off changes nothing. */
	{
		static const uint32_t lvl_strength[4] = { 0, 0xff, 0xc0, 0x80 };
		static const uint32_t lvl_var[4] = { 0, 0x00, 0x44, 0x77 };
		uint32_t l, saved41, saved9, reg3c0, reg3c8;
		unsigned ign;

		memcpy(&reg3c0, regs + 0x3c0, 4);
		if (!(reg3c0 & 1)) {
			rt_printf("antifog: Iridix block off in the scene, enabling it for the test\n");
			reg3c0 |= 1;
			memcpy(regs + 0x3c0, &reg3c0, 4);
		}
		for (f = 0; f < 3; f++) frame();
		saved41 = stab[41];
		saved9 = stab[9];
		if (t20fw_antifog(4) != -22 || t20fw_antifog(0xffffffffu) != -22)
			rt_printf("FAIL: antifog accepted a level above 3\n");
		for (f = 0; f < 3; f++) frame();
		if (stab[9] != saved9 || stab[41] != saved41)
			rt_printf("FAIL: antifog rejected level changed the Iridix state\n");
		for (l = 1; l <= 3; l++) {
			if (t20fw_antifog(l))
				rt_printf("FAIL: antifog level %u refused\n", l);
			if (l == 1 && stab[9] != saved9)
				rt_printf("FAIL: antifog level %u applied outside the AE path\n", l);
			for (f = 0; f < 3; f++) frame();
			if (stab[9] != 1 || stab[40] != lvl_strength[l] || stab[41] != 0xff)
				rt_printf("FAIL: antifog level %u: manual=%u strength=0x%x max=0x%x\n",
					  l, stab[9], stab[40], stab[41]);
		}
		if (t20fw_antifog(0))
			rt_printf("FAIL: antifog off refused\n");
		for (f = 0; f < 3; f++) frame();
		if (stab[9] != saved9 || stab[41] != saved41)
			rt_printf("FAIL: antifog off: manual=%u (was %u) max=0x%x (was 0x%x)\n",
				  stab[9], saved9, stab[41], saved41);
		/* off without a preset is a no-op */
		t20fw_antifog(0);
		for (f = 0; f < 3; f++) frame();
		if (stab[9] != saved9 || stab[41] != saved41)
			rt_printf("FAIL: antifog off without preset changed the Iridix state\n");
		/* a manual Iridix chosen by the application stays manual */
		cmd(TALGORITHMS_H, 0x69, 0x3b, 0);	/* IRIDIX manual */
		saved9 = stab[9];
		t20fw_antifog(2);
		for (f = 0; f < 3; f++) frame();
		t20fw_antifog(0);
		for (f = 0; f < 3; f++) frame();
		if (stab[9] != saved9)
			rt_printf("FAIL: antifog off dropped the application's manual Iridix\n");
		cmd(TALGORITHMS_H, 0x69, 0x3d, 0);	/* IRIDIX auto preset (block on, manual off) */
		for (f = 0; f < 3; f++) frame();
		saved9 = stab[9];
		/* variance nibbles, opt-in */
		memcpy(&reg3c8, regs + 0x3c8, 4);
		t20fw_antifog(2);
		for (f = 0; f < 3; f++) frame();
		if (memcmp(&reg3c8, regs + 0x3c8, 4))
			rt_printf("FAIL: antifog wrote 0x3c8 with the variance option off\n");
		t20fw_antifog(0);
		for (f = 0; f < 3; f++) frame();
		t20fw_antifog_variance(1);
		for (l = 1; l <= 3; l++) {
			uint32_t v;

			t20fw_antifog(l);
			for (f = 0; f < 3; f++) frame();
			memcpy(&v, regs + 0x3c8, 4);
			if ((v & 0xff) != lvl_var[l] || (v & ~0xffu) != (reg3c8 & ~0xffu))
				rt_printf("FAIL: antifog level %u variance word 0x%08x (original 0x%08x)\n", l, v, reg3c8);
		}
		t20fw_antifog(0);
		for (f = 0; f < 3; f++) frame();
		memcpy(&l, regs + 0x3c8, 4);
		if (l != reg3c8)
			rt_printf("FAIL: antifog off did not restore 0x3c8 (0x%08x, original 0x%08x)\n", l, reg3c8);
		t20fw_antifog_variance(0);
		/* Iridix block off: kept and counted, nothing written */
		ign = t20fw_antifog_ignored();
		reg3c0 &= ~1u;
		memcpy(regs + 0x3c0, &reg3c0, 4);
		t20fw_antifog(1);
		for (f = 0; f < 3; f++) frame();
		if (t20fw_antifog_ignored() != ign + 1 || stab[9] != saved9)
			rt_printf("FAIL: antifog with the Iridix block off: ignored=%u manual=%u\n",
				  t20fw_antifog_ignored() - ign, stab[9]);
		t20fw_antifog(0);
		reg3c0 |= 1;
		memcpy(regs + 0x3c0, &reg3c0, 4);
		for (f = 0; f < 3; f++) frame();
	}
	checkpoint("antifog");

	/* Lens-shading scale (t20_mesh_scale_request): validated, written to
	 * bits 2..4 of register 0x380 at the frame-end interrupt, other bits kept. */
	{
		uint32_t l, r380, keep;

		memcpy(&r380, regs + 0x380, 4);
		keep = r380 & ~0x1cu;
		if (t20fw_mesh_scale(8) != -22 || t20fw_mesh_scale(0xffffffffu) != -22)
			rt_printf("FAIL: mesh scale accepted a value above 7\n");
		for (f = 0; f < 3; f++) frame();
		memcpy(&l, regs + 0x380, 4);
		if (l != r380)
			rt_printf("FAIL: mesh scale: a refused value changed 0x380 (0x%08x -> 0x%08x)\n", r380, l);
		for (l = 0; l <= 7; l++) {
			uint32_t v;

			if (t20fw_mesh_scale(l))
				rt_printf("FAIL: mesh scale %u refused\n", l);
			memcpy(&v, regs + 0x380, 4);
			if (v != r380 && l != ((r380 >> 2) & 7))
				rt_printf("FAIL: mesh scale %u written in the caller's context\n", l);
			for (f = 0; f < 2; f++) frame();
			memcpy(&v, regs + 0x380, 4);
			if (((v >> 2) & 7) != l || (v & ~0x1cu) != keep)
				rt_printf("FAIL: mesh scale %u: 0x380 = 0x%08x (other bits 0x%08x)\n", l, v, keep);
			r380 = v;
		}
		t20fw_mesh_scale(1);
		for (f = 0; f < 2; f++) frame();
	}
	checkpoint("mesh-scale");

	/* API sweep: every GET, then SETs with a few values (coverage of the
	 * API dispatch and its getters/setters) */
	{
		static const uint32_t vals[] = { 0, 1, 2, 0x32, 0x80, 0xff };
		uint32_t type, id, v;
		for (type = 0; type <= 6; type++)
			for (id = 0; id < 0x100; id++)
				cmd(type, id, 0, 1);	/* incl. 0/0 selftest_sensor_id */
		checkpoint("api-get-sweep");
		for (type = 1; type <= 4; type++)
			for (id = 0; id < 0x80; id++) {
				if (type == TSYSTEM_H && (id == 0x0c || id == 0x0a || id == 0x0b))
					continue;	/* freeze firmware / test pattern */
				if (type == 2 && id >= 0x3f && id <= 0x4d)
					continue;	/* resolution / fps / wdr / crop: re-init */
				for (v = 0; v < sizeof(vals) / sizeof(vals[0]); v++)
					cmd(type, id, vals[v], 0);
				if ((id & 15) == 15)
					frame();
			}
		for (f = 0; f < 10; f++) frame();
	}
	checkpoint("api-set-sweep");

	if (poke)
		poke_scenario();
	else if (ext)
		ext_scenario();

	if (cov_on)
		cov_report();

	rt_printf("END frames=%u reads=%lu writes=%lu div64-by-zero=%lu\n", frame_no, reads, writes, rt_div0_count);
	return 0;
}
