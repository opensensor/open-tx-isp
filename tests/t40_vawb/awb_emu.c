/* SPDX-License-Identifier: GPL-2.0 */
/*
 * The C AWB init / EV / process chain and the gain / threshold chain (tx_isp_t40_awb_init.inc, _main.inc, _gain.inc) built for
 * mipsel as a relocatable object, for tools/ko_emu/diff_awb_chain.py: Unicorn runs this object and the OEM tx-isp-t40.ko on the same
 * random state and compares every byte of it.  The system register / event / completion calls are left undefined (the script hooks
 * them and logs the arguments).  Build: tests/t40_vawb/build_emu.sh <mipsel-linux-gcc> <out.o>
 */
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef uint64_t u64;
typedef unsigned int uint; typedef int8_t s8; typedef int16_t s16; typedef int32_t s32; typedef int64_t s64;
#define noinline __attribute__((noinline))
#define __aligned(x) __attribute__((aligned(x)))
#define unlikely(x) __builtin_expect(!!(x), 0)
#define likely(x) __builtin_expect(!!(x), 1)
#define KERN_WARNING ""
#define KERN_INFO ""
#define BIT(n) (1U << (n))
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define PAGE_SIZE 4096
#define THREAD_SIZE 8192
#define module_param(a, b, c)
#define t40_bringup_param(...)
#define t40_bringup_param_named(...)
#define t40_bringup_param_array_named(...)
#define t40_bringup_param_cb(...)
#define t40_bringup_parm_desc(...)
#define module_param_named(a, b, c, d)
#define module_param_cb(a, b, c, d)
#define MODULE_PARM_DESC(a, b)
#define scnprintf(...) 0
#define printk(...) 0
#define div64_u64(a, b) ((a) / (b))
#define in_interrupt() 0
struct kernel_param { int x; };
struct kernel_param_ops { int (*get)(char *, const struct kernel_param *); };

u32 pstMainAwbOri[128], pstSecAwbOri[128], pstMainAwbCtDetectOri[34];
u32 stMainAwbInter, stMainAwbOuter, stSecAwbInter, stSecAwbOuter;
u8 pstMainAeOri_storage[0x164], pstSecAeOri_storage[0x164];
u32 tparamsN[4], awb_algo_comp[8];
u8 tispinfo[64];
u32 pstMainCcmOri_lit[26], pstMainBcshOri_lit[72], t40_bcsh_oem_ctx[72];
struct { u8 mjpeg_mode[2], mjpeg_y_low[2], mjpeg_y_high[2]; } t40_bcsh;
u8 s_bcsh_mjpeg_mode_lit[2], s_bcsh_mjpeg_y_range_low_lit[2], s_bcsh_mjpeg_y_range_high_lit[16];
u32 emu_argarea[16];
u32 emu_algo_enable[2];	/* OEM tawb_custom_en */
#define awb_algo_enable emu_algo_enable

/* resolved by the script */
extern int system_reg_write(u32 a, u32 v);
extern int system_reg_read(u32 a);
extern int tisp_event_push(u32 a, u32 b);
extern void private_complete(u32 c);
static int regtrace_is_kernel_ptr(const void *p) { return p != 0; }
static int regtrace_is_kernel_ptr_any(const void *p) { return p != 0; }
static bool regtrace_enable_isp_3a_diag;
#include CFIX_INC
#include CTD_INC
#include VAWB_TOP

#define EMU(name, call) u64 emu_##name(u32 a0, u32 a1, u32 a2, u32 a3) { return call; }
EMU(params_transmit, vawb_s_tisp_awb_params_transmit(a0, a1, a2, a3, (u32)(uintptr_t)emu_argarea))
EMU(params_refresh, vawb_s_tisp_awb_params_refresh(a0, a1, a2, a3, (u32)(uintptr_t)emu_argarea))
EMU(set_hardware_param, vawb_s_tisp_awb_set_hardware_param(a0, a1, a2, a3, (u32)(uintptr_t)emu_argarea))
EMU(dn_params_refresh, vawb_s_tisp_awb_dn_params_refresh(a0, a1, a2, a3, (u32)(uintptr_t)emu_argarea))
EMU(main_ev_update, vawb_s_tisp_awb_main_ev_update(a0, a1, a2, a3, (u32)(uintptr_t)emu_argarea))
EMU(ev_update_Ywgt, vawb_s_tisp_awb_ev_update_Ywgt(a0, a1, a2, a3, (u32)(uintptr_t)emu_argarea))
EMU(set_regional_threshold, vawb_s_tisp_awb_set_regional_threshold(a0, a1, a2, a3, (u32)(uintptr_t)emu_argarea))
EMU(set_lum_th_freq, vawb_s_tisp_awb_set_lum_th_freq(a0, a1, a2, a3, (u32)(uintptr_t)emu_argarea))
EMU(tgain_update, vawb_s_tisp_awb_tgain_update(a0, a1, a2, a3, (u32)(uintptr_t)emu_argarea))
EMU(set_gain, vawb_s_tisp_awb_set_gain(a0, a1, a2, a3, (u32)(uintptr_t)emu_argarea))
#ifdef HAVE_AWB_MAIN
EMU(long_par_update, vawb_s_tisp_awb_long_par_update(a0, a1, a2, a3, (u32)(uintptr_t)emu_argarea))
EMU(spec_calculate, vawb_s_tisp_awb_spec_calculate(a0, a1, a2, a3, (u32)(uintptr_t)emu_argarea))
EMU(main_process, vawb_s_tisp_awb_main_process(a0, a1, a2, a3, (u32)(uintptr_t)emu_argarea))
#endif
