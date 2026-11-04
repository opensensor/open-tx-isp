#!/usr/bin/env python3
"""T30 driver code vs the Ingenic T30 SDK source, both EXECUTED on the host (see run.sh).

Each check builds two host programs from source text taken at test time (nothing from the SDK is copied into
the tree): one runs the SDK function body, one runs the driver function (lifted C or rewritten C).  Both get the
same pseudo-random ISP register file and the same customer block per case; APICAL_READ_32/WRITE_32 and
apical_command are recorded.  The ordered write/command logs must be identical.

  custom_init : SDK apical_custom_initialization.c  vs  driver/t30/tx_isp_t30_recovered.c apical_custom_initialization
  dn_customer : SDK apical_isp_day_or_night_s_ctrl_internal customer register block
                vs  driver/t30/tx_isp_t30_tuning_ctl.h tx_isp_t30_daynight_reload customer register block
  sensor_msgs : SDK sensor_drv.c setters + ispcore_irq_thread_handle (message slot, event per slot)
                vs  the driver's sensor_set_* and ispcore_irq_thread_handle_body (compiled SDK enums, parsed driver)
  (mutation: T30_ORACLE_MUTATE=<check> flips one mask in the driver text before compiling; the check must FAIL)
"""
import os, re, subprocess, sys, tempfile

sdk, drv = sys.argv[1], sys.argv[2]
CASES = int(os.environ.get('T30_ORACLE_CASES', '400'))
MUT = os.environ.get('T30_ORACLE_MUTATE', '')
rd = lambda p: open(p, errors='replace').read()

def func(text, head):
    i = text.index(head)
    return text[i:text.index('\n}\n', i) + 3]

COMMON = r"""#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/mman.h>
static uint32_t regs[0x4000]; static unsigned long long seed;
static uint32_t rnd(void){ seed = seed * 6364136223846793005ULL + 1442695040888963407ULL; return (uint32_t)(seed >> 32); }
static uint32_t reg_init(uint32_t a){ unsigned long long s = seed ^ (a * 0x9E3779B97F4A7C15ULL); s ^= s >> 29; s *= 0xBF58476D1CE4E5B9ULL; return (uint32_t)(s >> 32); }
static void regs_reset(void){ for (uint32_t a = 0; a < 0x10000; a += 4) regs[a >> 2] = reg_init(a); }
static uint32_t rd32(uint32_t a){ return regs[(a >> 2) & 0x3fff]; }
static void wr32(uint32_t a, uint32_t d){ printf("W %x %x\n", a, d); regs[(a >> 2) & 0x3fff] = d; }
static unsigned char *cust_block(int k){
    static unsigned char *b;
    if (!b) b = mmap((void *)0x10000000, 0x1000, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_32BIT, -1, 0);
    for (int i = 0; i < 0x400; i++) b[i] = rnd();
    if (k < 8) { uint32_t top; memcpy(&top, b, 4);   /* all combinations of the top bits the function branches on */
        top &= ~((1u << 19) | (1u << 20) | (1u << 27));
        top |= ((k & 1) << 19) | (((k >> 1) & 1) << 20) | (((k >> 2) & 1) << 27); memcpy(b, &top, 4); }
    return b;
}
"""
MAIN = r"""
int main(int argc, char **argv){ int n = atoi(argv[1]);
  for (int k = 0; k < n; k++) { seed = 0x5eed0000ULL + k; regs_reset(); unsigned char *c = cust_block(k);
    printf("CASE %d\n", k); RUN(c); }
  return 0; }
"""

def build(t, name, src, inc):
    p = os.path.join(t, name + '.c'); exe = os.path.join(t, name)
    open(p, 'w').write(src)
    r = subprocess.run(['cc', '-w', '-O1', '-Wno-int-conversion', '-Wno-incompatible-pointer-types', '-include', 'stdlib.h', '-I' + t] + ['-I' + x for x in inc] + ['-o', exe, p],
                       capture_output=True, text=True)
    if r.returncode:
        print('%s: does not compile\n%s' % (name, r.stderr[:1500])); return None
    return subprocess.run([exe, str(CASES)], capture_output=True, text=True).stdout

def compare(name, a, b):
    if a is None or b is None: return 1
    la, lb = a.split('\n'), b.split('\n')
    if la == lb:
        nw = sum(1 for l in la if l.startswith('W ')); nc = sum(1 for l in la if l.startswith('C '))
        print('%s: %d cases, %d register writes + %d commands identical to the SDK' % (name, CASES, nw, nc)); return 0
    case = '?'
    for x, y in zip(la, lb):
        if x.startswith('CASE'): case = x
        if x != y:
            print('%s: FAIL first difference in %s: SDK "%s" driver "%s"' % (name, case, x, y)); break
    else:
        print('%s: FAIL (log length SDK %d driver %d)' % (name, len(la), len(lb)))
    return 1

SDK_IO = r"""
#define KERNEL_MODULE 0
uint32_t system_isp_read_32(uint32_t a){return rd32(a);} uint16_t system_isp_read_16(uint32_t a){return rd32(a);}
uint8_t system_isp_read_8(uint32_t a){return rd32(a);}
void system_isp_write_32(uint32_t a,uint32_t d){wr32(a,d);} void system_isp_write_16(uint32_t a,uint16_t d){wr32(a,d);}
void system_isp_write_8(uint32_t a,uint8_t d){wr32(a,d);}
uint32_t APICAL_READ_32(uint32_t a){return rd32(a);} uint16_t APICAL_READ_16(uint32_t a){return rd32(a);} uint8_t APICAL_READ_8(uint32_t a){return rd32(a);}
void APICAL_WRITE_32(uint32_t a,uint32_t d){wr32(a,d);} void APICAL_WRITE_16(uint32_t a,uint16_t d){wr32(a,d);}
void APICAL_WRITE_8(uint32_t a,uint8_t d){wr32(a,d);}
#include "apical_isp_config.h"
#include "apical_command_api.h"
uint8_t apical_command(uint8_t t, uint8_t id, uint32_t v, uint8_t dir, uint32_t *r){ printf("C %u %u %x %u\n", t, id, v, dir); *r = 0; return 0; }
#define ISP_SUCCESS 0
#define ISP_WARNING_LEVEL 1
#define ISP_PRINT(...) do {} while (0)
#define CONTRAST_CURVES_MAXNUM 10
typedef unsigned char contrast_curves[CONTRAST_CURVES_MAXNUM][2];
"""
SDK_INC = [os.path.join(sdk, 'include'), os.path.join(sdk, 'include/apical-isp'), os.path.join(sdk, 'apical-isp')]

ld = rd(os.path.join(sdk, 'apical-isp/tx-isp-load-parameters.h'))
e = ld.index('} TXispPrivCustomerParamer;')
cust_t = ld[ld.rindex('typedef struct', 0, e):e + len('} TXispPrivCustomerParamer;')]
core_h = rd(os.path.join(sdk, 'apical-isp/tx-isp-core.h'))
defaults = '\n'.join(re.findall(r'#define APICAL_ISP_TOP_CONTROL_\w+_REG_DEFAULT .*', core_h))
common_h = rd(os.path.join(sdk, 'include/tx-isp-common.h'))
t30 = common_h[common_h.index('defined(CONFIG_SOC_T30)'):]
t30 = t30[:t30.index('#elif')] if '#elif' in t30 else t30[:t30.index('#endif')]
chan = '\n'.join(re.findall(r'#define TX_ISP_EXIST_\w+\s+\d+', t30))

DRV_IO = r"""
uintptr_t APICAL_READ_32(uintptr_t a){ return rd32((uint32_t)a); }
uintptr_t APICAL_WRITE_32(uintptr_t a, uintptr_t d){ wr32((uint32_t)a, (uint32_t)d); return 0; }
int32_t apical_command(uint32_t t, uint32_t id, uint32_t v, uint32_t dir, uint32_t *r){ printf("C %u %u %x %u\n", t & 0xff, id & 0xff, v, dir & 0xff); *r = 0; return 0; }
uintptr_t isp_printf(uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d){ return 0; }
static uintptr_t LC0;
#define pr_info(...) do {} while (0)
#define pr_err(...) do {} while (0)
"""

bad = 0
recovered = rd(os.path.join(drv, 'tx_isp_t30_recovered.c'))
tuning_h = rd(os.path.join(drv, 'tx_isp_t30_tuning_ctl.h'))
with tempfile.TemporaryDirectory() as t:
    for d in ('asm', 'linux'): os.makedirs(os.path.join(t, d))
    for stub in ('asm/io.h', 'asm/div64.h', 'linux/math64.h'): open(os.path.join(t, stub), 'w').close()

    # ---- custom_init -------------------------------------------------------------------------------------
    ci = rd(os.path.join(sdk, 'apical-isp/apical_custom_initialization.c'))
    body = func(ci, 'void apical_custom_initialization(void)')
    body = body[:body.index('#if 0')] + '\n}\n'        # the SDK's "#if 1" branch (the "#if 0" tail is dead code)
    body = body.replace('#if 1\n', '', 1)
    sdk_src = COMMON + SDK_IO + chan + '\n' + defaults + '\n' + cust_t + \
        '\nstatic TXispPrivCustomerParamer *customer;\n' + body + \
        '\n#define RUN(c) (customer = (TXispPrivCustomerParamer *)(c), apical_custom_initialization())\n' + MAIN
    dfn = func(recovered, 'uint32_t apical_custom_initialization(void)\n{')
    if MUT == 'custom_init':      # 0x46c: clear 6 bits instead of 7 (the open question of claude/t30-sharpen)
        dfn = dfn.replace('(1132, ((uintptr_t)v0 & (-128))', '(1132, ((uintptr_t)v0 & (-64))', 1)
    drv_src = COMMON + DRV_IO + 'static uint32_t tx_isp_t30_customer;\n' + dfn + \
        '\n#define RUN(c) (tx_isp_t30_customer = (uint32_t)(uintptr_t)(c), apical_custom_initialization())\n' + MAIN
    bad += compare('custom_init', build(t, 'ci_sdk', sdk_src, SDK_INC), build(t, 'ci_drv', drv_src, []))

    # ---- dn_customer -------------------------------------------------------------------------------------
    tune = rd(os.path.join(sdk, 'apical-isp/tx-isp-core-tuning.c'))
    i = tune.index('apical_isp_day_or_night_s_ctrl_internal(image_tuning_vdrv_t')
    dn = tune[i:tune.index('\n}\n', i)]
    stm = dn[dn.index('apical_isp_raw_frontend_ge_strength_write'):dn.index('/* Max ISP Digital Gain */')]
    sdk_src = COMMON + SDK_IO + cust_t + '\nstatic void run(TXispPrivCustomerParamer *customer){\n' + stm + '\n}\n' + \
        '#define RUN(c) run((TXispPrivCustomerParamer *)(c))\n' + MAIN
    rl = func(tuning_h, 'static void tx_isp_t30_daynight_reload(void *tuning,')
    blk = rl[rl.index('\tfor (i = 0; i < 4; i++)'):rl.index('\tif (apical_command(1, 41')]
    if MUT == 'dn_customer':
        blk = blk.replace('& ~0x7fU', '& ~0x3fU', 1)
    regs_tab = tuning_h[tuning_h.index('static const u16 tctl_dn_regs[][3]'):]
    regs_tab = regs_tab[:regs_tab.index('};') + 2]
    fld = func(tuning_h, 'static void tctl_dn_field(u32 reg, u32 bits, u32 value)')
    drv_src = COMMON + 'typedef uint32_t u32; typedef uint16_t u16;\n#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))\n' + \
        'static u32 APICAL_READ_32(u32 a){return rd32(a);} static void APICAL_WRITE_32(u32 a,u32 d){wr32(a,d);}\n' + \
        regs_tab + '\n' + fld + '\nstatic void run(const u32 *cust){ unsigned int i;\n' + blk + '}\n' + \
        '#define RUN(c) run((const u32 *)(c))\n' + MAIN
    bad += compare('dn_customer', build(t, 'dn_sdk', sdk_src, SDK_INC), build(t, 'dn_drv', drv_src, []))

# ---- sensor_msgs: AE -> sensor message slots (SDK sensor_drv.c + tx-isp-core.c ispcore_irq_thread_handle) -----
# SDK side compiled: slot of each setter = its tx_isp_i2c_index, event of each slot = the thread's switch case
# (enum tx_isp_notification).  Driver side: the slot each setter posts to and the slot -> event map of the thread.
sd = rd(os.path.join(sdk, 'apical-isp/sensor_drv.c'))
core_c = rd(os.path.join(sdk, 'apical-isp/tx-isp-core.c'))
en = core_h[core_h.index('enum tx_isp_i2c_index'):]; en = en[:en.index('};') + 2]
cm = rd(os.path.join(sdk, 'include/tx-isp-common.h'))
nt = cm[cm.index('enum tx_isp_notification'):]; nt = nt[:nt.index('};') + 2]
pre = '\n'.join(re.findall(r'#define NOTIFICATION_TYPE_\w+\s+.*', cm))
setters = {n: re.search(r'i2c_msgs\[(TX_ISP_I2C_SET_\w+)\]', func(sd, 'static void sensor_' + n + '(')).group(1)
           for n in ('set_integration_time', 'set_analog_gain', 'set_digital_gain')}
th = func(core_c, 'static irqreturn_t ispcore_irq_thread_handle(')
cases = re.findall(r'case (TX_ISP_I2C_SET_\w+):\s*cmd = (TX_ISP_EVENT_SENSOR_\w+);', th)
src = '#include <stdio.h>\n' + pre + '\n' + en + '\n' + nt + '\nint main(void){\n' + \
    ''.join('printf("S %s %%d\\n", %s);\n' % (n, e) for n, e in setters.items()) + \
    ''.join('printf("E %%d %%#x\\n", %s, %s);\n' % (a, b) for a, b in cases) + 'return 0;}\n'
with tempfile.TemporaryDirectory() as t:
    out = build(t, 'msgs', src, [])
sdk_s = {l.split()[1]: int(l.split()[2]) for l in out.split('\n') if l.startswith('S ')}
sdk_e = {int(l.split()[1]): int(l.split()[2], 16) for l in out.split('\n') if l.startswith('E ')}
drv_s = {}
for n in sdk_s:
    m = re.search(r'messages\[(\d)\]\.value', func(recovered, 'uint32_t sensor_' + n + '(uint32_t a0, uint32_t a1)\n{'))
    if m: drv_s[n] = int(m.group(1))
    else:   # lifted form: sw value at 384 + 8 * slot + 4
        m = re.search(r'\(char \*\)v0 \+ (\d+)\) = a1;', func(recovered, 'uint32_t sensor_' + n + '(uint32_t a0, uint32_t a1)\n{'))
        drv_s[n] = (int(m.group(1)) - 388) // 8 if m else None
tb = func(recovered, 'static int32_t ispcore_irq_thread_handle_body(void *arg1)\n{')
if MUT == 'sensor_msgs':
    tb = tb.replace('i == 0 ? 0x2000006', 'i == 0 ? 0x2000005', 1).replace(': 0x2000005;', ': 0x2000006;', 1)
m = re.search(r'i == 0 \? (0x[0-9a-f]+) :\s*i == 1 \? (0x[0-9a-f]+) : (0x[0-9a-f]+);', tb)
drv_e = {i: int(x, 16) for i, x in enumerate(m.groups())} if m else {}
ok = sdk_s == drv_s and sdk_e == drv_e and len(sdk_e) == 3
print('sensor_msgs: setter slots SDK %s driver %s, slot events SDK %s driver %s: %s' % (
    sdk_s, drv_s, {k: hex(v) for k, v in sdk_e.items()}, {k: hex(v) for k, v in drv_e.items()}, 'OK' if ok else 'FAIL'))
bad += not ok

print('t30_sdk_exec_oracle: %s' % ('FAIL' if bad else 'OK'))
sys.exit(1 if bad else 0)
