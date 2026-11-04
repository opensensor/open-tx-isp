#!/usr/bin/env python3
"""T30 driver tables vs the Ingenic T30 SDK ISP core source (see run.sh)."""
import os, re, subprocess, sys, tempfile

sdk, drv = sys.argv[1], sys.argv[2]
tune = open(os.path.join(sdk, 'apical-isp/tx-isp-core-tuning.c'), errors='replace').read()
apical_h = open(os.path.join(sdk, 'include/apical-isp/apical.h'), errors='replace').read()
ctl = open(os.path.join(drv, 'tx_isp_t30_tuning_ctl.h')).read()
stab_h = open(os.path.join(drv, 'tx_isp_t30_stab.h')).read()
bad = 0

# SDK day/night SET list
i = tune.index('apical_isp_day_or_night_s_ctrl_internal(image_tuning_vdrv_t')
body = tune[i:tune.index('\n}\n', i)]
pairs = re.findall(r'apical_api_calibration\((CALIBRATION_\w+)\s*,\s*COMMAND_SET\s*,\s*table\[\s*(_CALIBRATION_\w+)\s*\]', body)

# system_tab
j = apical_h.index('typedef struct _sytem_tab')
st = apical_h[j:apical_h.index('} system_tab;', j) + len('} system_tab;')]
fields = re.findall(r'\buint(8|16|32)_t\s+(global_\w+)\s*;', st)

wanted_fields = {  # stab[N] index written by the T30 day/night reload -> SDK field
    35: 'global_maximum_directional_sharpening', 36: 'global_minimum_directional_sharpening',
    38: 'global_maximum_un_directional_sharpening', 39: 'global_minimum_un_directional_sharpening',
    41: 'global_maximum_iridix_strength', 42: 'global_minimum_iridix_strength',
    44: 'global_maximum_sinter_strength', 45: 'global_minimum_sinter_strength',
    47: 'global_maximum_temper_strength', 48: 'global_minimum_temper_strength',
    13: 'global_antiflicker_enable', 24: 'global_integration_time', 26: 'global_max_integration_time',
    28: 'global_sensor_analog_gain', 29: 'global_max_sensor_analog_gain',
}

c = ['#include <stdio.h>', '#include <stddef.h>', '#include <stdint.h>']
c.append('#define KERNEL_MODULE 0')
c.append('#include "apical-isp/apical_calibrations_id.h"')
c.append('#include "apical_command_api.h"')
c.append(st)
c.append('int main(void){printf("size %zu\\n",sizeof(system_tab));')
for a, b in pairs:
    c.append('printf("P %%d %%d\\n",(int)%s,(int)%s);' % (b, a))
for w, n in fields:
    c.append('printf("F %%zu %%d %s\\n",offsetof(system_tab,%s),%d);' % (n, n, int(w) // 8))
c.append('return 0;}')

with tempfile.TemporaryDirectory() as t:
    os.makedirs(os.path.join(t, 'asm')); os.makedirs(os.path.join(t, 'linux'))
    open(os.path.join(t, 'asm/div64.h'), 'w').close(); open(os.path.join(t, 'linux/math64.h'), 'w').close()
    src = os.path.join(t, 'o.c'); exe = os.path.join(t, 'o')
    open(src, 'w').write('\n'.join(c) + '\n')
    r = subprocess.run(['cc', '-w', '-I' + t, '-I' + os.path.join(sdk, 'include'),
                        '-I' + os.path.join(sdk, 'include/apical-isp'), '-I' + os.path.join(sdk, 'apical-isp'),
                        '-o', exe, src], capture_output=True, text=True)
    if r.returncode:
        print('t30_sdk_oracle: FAIL (SDK headers do not compile)\n' + r.stderr[:800]); sys.exit(1)
    out = subprocess.run([exe], capture_output=True, text=True).stdout.split('\n')

sdk_pairs = [tuple(map(int, l.split()[1:3])) for l in out if l.startswith('P ')]
sdk_f = [(l.split()[3], int(l.split()[1]), int(l.split()[2])) for l in out if l.startswith('F ')]
size = int([l for l in out if l.startswith('size')][0].split()[1])

# 1. day/night tables
k = ctl.index('tctl_dn_tables[][2]')
drv_pairs = [(int(a), int(b, 16)) for a, b in re.findall(r'\{\s*(\d+),\s*(0x[0-9a-f]+)\s*\}', ctl[k:ctl.index('};', k)])]
ok = drv_pairs == sdk_pairs and len(sdk_pairs) == 93
print('day/night tables: driver %d, SDK %d, same order: %s' % (len(drv_pairs), len(sdk_pairs), ok))
bad += not ok

# 2. system table layout
k = stab_h.index('t30_stab_items[T30_STAB_ITEMS] = {')
drv_items = [(int(a), int(b)) for a, b in re.findall(r'\{\s*(\d+),\s*(\d+)\s*\}', stab_h[k:stab_h.index('};', k)])]
sdk_items = [(o, l) for _, o, l in sdk_f]
ok = drv_items == sdk_items and size == 60
print('system table: driver %d items, SDK %d fields, sizeof %d, same offsets/widths: %s' % (len(drv_items), len(sdk_items), size, ok))
bad += not ok

# 3. stab[N] names
byoff = {o: n for n, o, _ in sdk_f}
for idx, name in sorted(wanted_fields.items()):
    if byoff.get(idx) != name:
        print('stab[%d]: SDK field is %s, expected %s: FAIL' % (idx, byoff.get(idx), name)); bad += 1
print('stab[] names: %d checked' % len(wanted_fields))

# 4. the 43 customer register fields: run the SDK register writers (apical_isp_*_write) with one customer word set at a
#    time and compare (register, field mask) with tctl_dn_regs (+ the three words the reload handles by hand)
ld = open(os.path.join(sdk, 'apical-isp/tx-isp-load-parameters.h'), errors='replace').read()
e = ld.index('} TXispPrivCustomerParamer;')
st_c = ld[ld.rindex('typedef struct', 0, e):e + len('} TXispPrivCustomerParamer;')]
a0 = body.index('apical_isp_raw_frontend_ge_strength_write')
stm = body[a0:body.index('/* Max ISP Digital Gain */')]
h = r"""#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define KERNEL_MODULE 0
static uint32_t rr[4096], rv[4096]; static int nrec;
uint32_t system_isp_read_32(uint32_t a){return 0;} uint16_t system_isp_read_16(uint32_t a){return 0;}
uint8_t system_isp_read_8(uint32_t a){return 0;}
void system_isp_write_32(uint32_t a,uint32_t d){rr[nrec]=a;rv[nrec++]=d;}
void system_isp_write_16(uint32_t a,uint16_t d){rr[nrec]=a;rv[nrec++]=d;}
void system_isp_write_8(uint32_t a,uint8_t d){rr[nrec]=a;rv[nrec++]=d;}
#include "apical_isp_config.h"
#define CONTRAST_CURVES_MAXNUM 10
typedef unsigned char contrast_curves[CONTRAST_CURVES_MAXNUM][2];
uint32_t APICAL_READ_32(uint32_t a){return 0;} uint16_t APICAL_READ_16(uint32_t a){return 0;} uint8_t APICAL_READ_8(uint32_t a){return 0;}
void APICAL_WRITE_32(uint32_t a,uint32_t d){system_isp_write_32(a,d);} void APICAL_WRITE_16(uint32_t a,uint16_t d){system_isp_write_32(a,d);}
void APICAL_WRITE_8(uint32_t a,uint8_t d){system_isp_write_32(a,d);}
"""
h += st_c + "\nstatic void run(TXispPrivCustomerParamer *customer){\n" + stm + "\n}\n"
h += r"""int main(void){ TXispPrivCustomerParamer c; unsigned int *w=(unsigned int*)&c;
 for(int k=1;k<=43;k++){ memset(&c,0,sizeof c); w[k]=0xffffffffu; nrec=0; run(&c);
  for(int n=0;n<nrec;n++) if(rv[n]) printf("W %d %x %x\n",k,rr[n],rv[n]); }
 return 0;}
"""
with tempfile.TemporaryDirectory() as t:
    os.makedirs(os.path.join(t, 'asm')); os.makedirs(os.path.join(t, 'linux'))
    for stub in ('asm/io.h', 'asm/div64.h', 'linux/math64.h'):
        open(os.path.join(t, stub), 'w').close()
    src = os.path.join(t, 'r.c'); exe = os.path.join(t, 'r')
    open(src, 'w').write(h)
    r = subprocess.run(['cc', '-w', '-I' + t, '-I' + os.path.join(sdk, 'include'),
                        '-I' + os.path.join(sdk, 'include/apical-isp'), '-I' + os.path.join(sdk, 'apical-isp'),
                        '-o', exe, src], capture_output=True, text=True)
    if r.returncode:
        print('t30_sdk_oracle: FAIL (SDK register writers do not compile)\n' + r.stderr[:800]); sys.exit(1)
    wr = subprocess.run([exe], capture_output=True, text=True).stdout.split('\n')
sdk_w = {}
for l in wr:
    if l.startswith('W '):
        _, k, reg, m = l.split(); sdk_w.setdefault(int(k), set()).add((int(reg, 16), int(m, 16)))
k = ctl.index('tctl_dn_regs[][3]')
drv_w = {}
for w_, reg, bits in re.findall(r'\{\s*(\d+),\s*(0x[0-9a-f]+),\s*(\d+)\s*\}', ctl[k:ctl.index('};', k)]):
    drv_w[int(w_)] = {(int(reg, 16), (1 << int(bits)) - 1)}
drv_w[5] = {(0x1c0, 4)}                      # dp_module -> 0x1c0 bit 2
drv_w[33] = {(0x46c, 0x3f), (0x46c, 0x80)}   # dmsc_np_off (6 bits) + dmsc_np_reflect (bit 7)
drv_w[34] = {(0x2cc, 0xf)}                   # temper_recursion_limit
for need in ('0x1c0', '0x46c', '0x2cc'):
    if need not in ctl[ctl.index('tx_isp_t30_daynight_reload(void *tuning,\n'):]:
        print('driver reload does not touch ' + need); bad += 1
diff = [x for x in sorted(set(sdk_w) | set(drv_w)) if sdk_w.get(x) != drv_w.get(x)]
print('customer register fields: SDK %d words, driver %d words, differing words: %s' % (len(sdk_w), len(drv_w), diff or 'none'))
for x in diff:
    print('  word %d: SDK %s driver %s' % (x, sorted(sdk_w.get(x, [])), sorted(drv_w.get(x, []))))
bad += bool(diff)
print('t30_sdk_oracle: %s' % ('FAIL' if bad else 'OK'))
sys.exit(1 if bad else 0)
