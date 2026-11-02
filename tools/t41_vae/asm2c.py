# asm2c.py: mechanical MIPS32 (o32, LE) -> C translation of OEM tx-isp-t41.ko
# functions (H20250310a SDK build with symbols).  Register-level, faithful
# by construction: every instruction becomes one C statement.
import sys, re, bisect, struct, os  # noqa
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from parse import load
IN = os.environ.get('VAE_IN', '.')
OUT = os.environ.get('VAE_OUT', 'vae_gen.inc')
VF = os.environ.get('VAE_VF', '1') == '1'  # frame-slot accesses unguarded (own stack array)
VFW = {'lw': 4, 'lh': 2, 'lhu': 2, 'lb': 1, 'lbu': 1, 'sw': 4, 'sh': 2, 'sb': 1}

F = load(os.path.join(IN, 'sdk.dis'))
sec = {}
for l in open(os.path.join(IN, 'secmap.txt')):
    s, a, sz, n = l.split(); sec.setdefault(s, []).append((int(a, 16), int(sz, 16), n))
for s in sec: sec[s].sort()
rodata = open(os.path.join(IN, 'rodata.bin'), 'rb').read()

def resolve(s, off):
    L = sec[s]; i = bisect.bisect_right([a for a, _, _ in L], off) - 1
    while i > 0 and L[i][2].startswith('.'): i -= 1
    a, sz, n = L[i]
    return n, off - a, sz

# OEM data object -> C address expression (shared driver objects)
DATA = {
    'ae_info': 'ae_info', 'ae_cache': 'ae_cache', 'ae_cache_init': 'ae_cache_init',
    'tisp_par_info': 'tisp_par_info_storage', 'sensor_ctrl_main': 'sensor_ctrl_main_storage',
    'g_ispcore': 'g_ispcore', 'y_arr': 'y_arr_storage', 'fliker_info': '&fliker_info',
    'fliker_para': '&fliker_para', 'fliker_ae_stable': '&fliker_ae_stable',
    'blc_info': 'blc_info', 'gib_info': 'gib_info', 'ae_algo_comp': 'ae_algo_comp_storage',
    'ae_api_tmp': 'ae_api_tmp_storage', 'tisp_ae_hist_last': 'tisp_ae_hist_last',
    'tisp_ae_hist': 'vae_tisp_ae_hist', 'ta_custom_en': 'vae_ta_custom_en',
    'ta_custom_again': 'vae_ta_custom_again', 'ta_custom_ev': 'vae_ta_custom_ev', 'ta_custom_ev_short': 'vae_ta_custom_ev_short',
    'ta_custom_tgain': 'vae_ta_custom_tgain', 'ta_custom_tgain_short': 'vae_ta_custom_tgain_short',
    'ae_ceguang': 'vae_ae_ceguang', 'slock_hist': 'vae_slock', 'slock_stas': 'vae_slock',
    'clm_info': '&clm_info',
    # defog (gen_defog.sh): own storage for the OEM statics, shared tparamsP
    'tparamsP': 'tparamsP_storage', 'deghost_en_flag_tmp': 'dfg_bss', 'tpm_cb': 'dfg_tpm_cb', 'tparams_day': 'tparams_day_storage', 'tparams_night': 'tparams_night_storage',
}
ADAPT = {'memcpy', 'memset', 'private_complete', '__private_spin_lock_irqsave',
         'private_spin_unlock_irqrestore', 'system_reg_write', 'isp_printf',
         'tisp_event_push', 'private_dma_cache_sync', 'private_kmalloc', 'private_kfree',
         'private_vmalloc', 'private_vfree', 'system_irq_func_set', 'system_reg_read',
         'tisp_event_set_cb', 'tisp_get_tuning', '__ashldi3', '__lshrdi3', '__ashrdi3', '__div64_32', 'div64_u64'}
used_data = {}
UNM = {}

R = ['zero', 'at', 'v0', 'v1', 'a0', 'a1', 'a2', 'a3', 't0', 't1', 't2', 't3', 't4', 't5', 't6', 't7',
     's0', 's1', 's2', 's3', 's4', 's5', 's6', 's7', 't8', 't9', 'k0', 'k1', 'gp', 'sp', 's8', 'ra']

# .rodata jump tables: offset -> target (.text offset)
jt = {}
for l in open(os.path.join(IN, 'rodata.rel')):
    p = l.split()
    if len(p) == 3 and p[1] == 'R_MIPS_32' and p[2] == '.text':
        o = int(p[0], 16); jt[o] = struct.unpack_from('<I', rodata, o)[0]

def num(x): return int(x, 0)

def gen(fname, translated, warn):
    fn = F[fname]; ins = fn['ins']; start = ins[0][0]; end = ins[-1][0] + 4
    frame = 0
    for i in ins[:12]:
        if i[1] == 'addiu' and i[2].startswith('sp,sp,-'):
            frame = int(i[2].split(',')[2][1:]); break
    nfr = sum(1 for i in ins if i[1] == 'addiu' and i[2].startswith('sp,sp,-'))
    if nfr > 1: raise Exception(f'multiple frames in {fname}')
    labels = set(); caller_area = False
    for i in ins:
        m = i[1]
        if m in ('b', 'beq', 'bne', 'beqz', 'bnez', 'bgez', 'bltz', 'blez', 'bgtz'):
            labels.add(int(i[2].split(',')[-1], 16))
    jtargets = sorted(set(t for o, t in jt.items() if start <= t < end))
    labels |= set(jtargets)
    out = []
    o = out.append

    def r(x):
        x = x.strip()
        if x == 'zero': return '0U'
        if x == 'fp': x = 's8'
        assert x in R, (fname, x)
        return x

    def w(x):
        x = x.strip()
        if x == 'fp': x = 's8'
        return x

    def reloc_addr(i, imm):
        """C expression for the address a LO16 reloc designates (without base reg)."""
        t, s = [rr for rr in i[3] if rr[0] == 'R_MIPS_LO16'][0]
        if s in ('.bss', '.data', '.sbss'):
            n, k, sz = resolve(s, imm)
            if n not in DATA:
                if os.environ.get('VAE_LISTUNMAPPED'):
                    UNM.setdefault(n, (s, sz)); return '0U'
                raise Exception(f'unmapped {s} object {n}+{k} in {fname}')
            used_data[n] = sz
            return f'((u32)(uintptr_t)({DATA[n]}) + {k}U)'
        if s == '.rodata':
            n, k, sz = resolve(s, imm)
            if n == 'ae_cache':
                used_data[n] = sz; return f'((u32)(uintptr_t)ae_cache + {k}U)'
            return f'((u32)(uintptr_t)vae_rodata + {imm}U)'
        if s.startswith('.rodata.str') or s.startswith('$LC') or s.startswith('__func__'):
            return '((u32)(uintptr_t)vae_str)'
        if s in F and s not in ADAPT and os.environ.get('VAE_ONLY') and not re.match(os.environ['VAE_ONLY'], s):
            UNM.setdefault(s, ('fn', 0)); return '0U'
        if s in F or s in ADAPT:
            if s in ADAPT: return f'((u32)(uintptr_t)vae_x_{s} + {imm}U)'
            translated.add(s)
            return f'((u32)(uintptr_t)vae_{s} + {imm}U)'
        if s in DATA:
            used_data[s] = 0
            return f'((u32)(uintptr_t)({DATA[s]}) + {imm}U)'
        if os.environ.get('VAE_LISTUNMAPPED'):
            UNM.setdefault(s, ('sym', 0)); return '0U'
        raise Exception(f'unmapped symbol {s} in {fname}')

    def mem(i, ops):
        # ops: 'rt,off(base)'
        rt, rest = ops.split(',', 1)
        mm = re.match(r'(-?\d+)\((\w+)\)', rest.strip())
        off, base = int(mm.group(1)), w(mm.group(2))
        if any(t == 'R_MIPS_LO16' for t, _ in i[3]):
            return rt, f'({r(base)} + {reloc_addr(i, off)})'
        if base == 'sp':
            if off >= frame:
                nonlocal caller_area; caller_area = True
                return rt, f'(csp + {off - frame}U)'
            return rt, f'(sp + {off}U)'
        return rt, f'({r(base)} + (u32){off})'

    def vf_ok(ad, m):
        # (sp + N): N-th byte of this function's own vframe[] -> no guard needed
        # (always a valid, naturally aligned kernel stack address)
        mm = re.fullmatch(r'\(sp \+ (\d+)U\)', ad)
        if not VF or not mm: return False
        n, wd = int(mm.group(1)), VFW[m]
        return n % wd == 0 and n + wd <= (max(frame, 4) // 4 + 1) * 4

    def one(i):
        m, ops = i[1], i[2]
        a = [x.strip() for x in ops.split(',')] if ops else []
        pc = i[0]
        hasrel = any(t == 'R_MIPS_LO16' for t, _ in i[3])
        if m in ('nop', 'sync', 'ssnop', 'ehb'): return ''
        if m == 'addiu' and a[0] == 'sp' and a[1] == 'sp': return ''
        if m == 'lui':
            return f'{w(a[0])} = {num(a[1])}U << 16;' if not i[3] else f'{w(a[0])} = 0;'
        if m == 'addiu':
            if hasrel: return f'{w(a[0])} = {r(a[1])} + {reloc_addr(i, num(a[2]))};'
            if a[1] == 'sp':
                k = num(a[2])
                if k >= frame:
                    nonlocal_flag[0] = True
                    return f'{w(a[0])} = csp + {k - frame}U;'
                return f'{w(a[0])} = sp + {k}U;'
            return f'{w(a[0])} = {r(a[1])} + (u32){num(a[2])};'
        if m == 'move':
            if a[1] == 'sp': return f'{w(a[0])} = sp;'
            return f'{w(a[0])} = {r(a[1])};'
        if m == 'li': return f'{w(a[0])} = (u32){num(a[1])};'
        if m == 'addu': return f'{w(a[0])} = {r(a[1])} + {r(a[2])};'
        if m == 'subu': return f'{w(a[0])} = {r(a[1])} - {r(a[2])};'
        if m == 'negu': return f'{w(a[0])} = 0U - {r(a[1])};'
        if m == 'and': return f'{w(a[0])} = {r(a[1])} & {r(a[2])};'
        if m == 'or': return f'{w(a[0])} = {r(a[1])} | {r(a[2])};'
        if m == 'xor': return f'{w(a[0])} = {r(a[1])} ^ {r(a[2])};'
        if m == 'nor': return f'{w(a[0])} = ~({r(a[1])} | {r(a[2])});'
        if m == 'andi': return f'{w(a[0])} = {r(a[1])} & {num(a[2])}U;'
        if m == 'ori': return f'{w(a[0])} = {r(a[1])} | {num(a[2])}U;'
        if m == 'xori': return f'{w(a[0])} = {r(a[1])} ^ {num(a[2])}U;'
        if m == 'sll': return f'{w(a[0])} = {r(a[1])} << {num(a[2])};'
        if m == 'srl': return f'{w(a[0])} = {r(a[1])} >> {num(a[2])};'
        if m == 'sra': return f'{w(a[0])} = (u32)((s32){r(a[1])} >> {num(a[2])});'
        if m == 'sllv': return f'{w(a[0])} = {r(a[1])} << ({r(a[2])} & 31);'
        if m == 'srlv': return f'{w(a[0])} = {r(a[1])} >> ({r(a[2])} & 31);'
        if m == 'srav': return f'{w(a[0])} = (u32)((s32){r(a[1])} >> ({r(a[2])} & 31));'
        if m == 'slt': return f'{w(a[0])} = (s32){r(a[1])} < (s32){r(a[2])};'
        if m == 'sltu': return f'{w(a[0])} = {r(a[1])} < {r(a[2])};'
        if m == 'slti': return f'{w(a[0])} = (s32){r(a[1])} < (s32){num(a[2])};'
        if m == 'sltiu': return f'{w(a[0])} = {r(a[1])} < (u32){num(a[2])};'
        if m == 'mul': return f'{w(a[0])} = (u32)((s32){r(a[1])} * (s32){r(a[2])});'
        if m == 'mult': return f'acc = (u64)((s64)(s32){r(a[0])} * (s64)(s32){r(a[1])});'
        if m == 'multu': return f'acc = (u64){r(a[0])} * (u64){r(a[1])};'
        if m == 'madd': return f'acc += (u64)((s64)(s32){r(a[0])} * (s64)(s32){r(a[1])});'
        if m == 'maddu': return f'acc += (u64){r(a[0])} * (u64){r(a[1])};'
        if m == 'msub': return f'acc -= (u64)((s64)(s32){r(a[0])} * (s64)(s32){r(a[1])});'
        if m == 'msubu': return f'acc -= (u64){r(a[0])} * (u64){r(a[1])};'
        if m == 'mflo': return f'{w(a[0])} = (u32)acc;'
        if m == 'mfhi': return f'{w(a[0])} = (u32)(acc >> 32);'
        if m == 'mtlo': return f'acc = (acc & 0xffffffff00000000ULL) | {r(a[0])};'
        if m == 'mthi': return f'acc = (acc & 0xffffffffULL) | ((u64){r(a[0])} << 32);'
        if m in ('div', 'divu'):
            x, y = (a[1], a[2]) if a[0] == 'zero' else (a[0], a[1])
            f = 'vae_divs' if m == 'div' else 'vae_divu'
            return f'acc = {f}({r(x)}, {r(y)}, {pc}U);'
        if m == 'movz': return f'if ({r(a[2])} == 0) {w(a[0])} = {r(a[1])};'
        if m == 'movn': return f'if ({r(a[2])} != 0) {w(a[0])} = {r(a[1])};'
        if m == 'seb': return f'{w(a[0])} = (u32)(s32)(signed char){r(a[1])};'
        if m == 'seh': return f'{w(a[0])} = (u32)(s32)(short){r(a[1])};'
        if m == 'ext':
            pos, sz = num(a[2]), num(a[3]); mk = (1 << sz) - 1
            return f'{w(a[0])} = ({r(a[1])} >> {pos}) & {mk:#x}U;'
        if m == 'ins':
            pos, sz = num(a[2]), num(a[3]); mk = ((1 << sz) - 1) << pos
            return f'{w(a[0])} = ({r(a[0])} & {(~mk) & 0xffffffff:#x}U) | (({r(a[1])} << {pos}) & {mk:#x}U);'
        if m in ('lw', 'lh', 'lhu', 'lb', 'lbu'):
            rt, ad = mem(i, ops)
            if vf_ok(ad, m):
                return f'{w(rt)} = vf_{m}({ad});'
            f = {'lw': 'vae_lw', 'lh': 'vae_lh', 'lhu': 'vae_lhu', 'lb': 'vae_lb', 'lbu': 'vae_lbu'}[m]
            return f'{w(rt)} = {f}({ad}, {pc}U);'
        if m in ('sw', 'sh', 'sb'):
            rt, ad = mem(i, ops)
            if vf_ok(ad, m):
                return f'vf_{m}({ad}, {r(rt)});'
            return f'vae_{m}({ad}, {r(rt)}, {pc}U);'
        raise Exception(f'unhandled {m} {ops} in {fname}+{pc:x}')

    nonlocal_flag = [False]
    skip = set()
    body = []
    idx = {i[0]: k for k, i in enumerate(ins)}
    for k, i in enumerate(ins):
        m, ops = i[1], i[2]
        a = [x.strip() for x in ops.split(',')] if ops else []
        lab = f'L_{i[0]-start:x}'
        if i[0] in labels: body.append(f'{lab}:')
        if k in skip:
            continue
        nxt = ins[k + 1] if k + 1 < len(ins) else None
        def delay():
            skip.add(k + 1)
            s = one(nxt) if nxt else ''
            return s
        def after():
            if nxt and nxt[0] in labels and k + 2 < len(ins):
                return f' goto L_{ins[k+2][0]-start:x};'
            return ''
        br = None
        if m in ('beq', 'bne'):
            br = f'({r(a[0])} {"==" if m=="beq" else "!="} {r(a[1])})'; tgt = int(a[2], 16)
        elif m in ('beqz', 'bnez'):
            br = f'({r(a[0])} {"==" if m=="beqz" else "!="} 0)'; tgt = int(a[1], 16)
        elif m in ('bgez', 'bltz', 'blez', 'bgtz'):
            op = {'bgez': '>=', 'bltz': '<', 'blez': '<=', 'bgtz': '>'}[m]
            br = f'((s32){r(a[0])} {op} 0)'; tgt = int(a[1], 16)
        elif m == 'b':
            br = '1'; tgt = int(a[0], 16)
        if br is not None:
            if not (start <= tgt < end): raise Exception(f'branch out of fn {fname}')
            body.append(f'\tc = {br}; {delay()} if (c) goto L_{tgt-start:x};{after()}')
            continue
        if m == 'jalr':
            tr = a[-1]
            body.append(f'\ttg = {r(tr)}; {delay()} {{ u64 rv = vae_call(tg, a0, a1, a2, a3, sp, {i[0]}U); v0 = (u32)rv; v1 = (u32)(rv >> 32); }}{after()}')
            continue
        if m in ('jr', 'jr.hb'):
            tr = a[0]
            if tr == 'ra':
                body.append(f'\t{delay()} return ((u64)v1 << 32) | v0;')
            elif tr == 't9':
                body.append(f'\ttg = t9; {delay()} return vae_call(tg, a0, a1, a2, a3, csp, {i[0]}U);')
            else:
                cases = ' '.join(f'case {t}U: goto L_{t-start:x};' for t in jtargets)
                body.append(f'\ttg = {r(tr)}; {delay()} switch (tg) {{ {cases} default: vae_fault_note(0, {i[0]}U); return 0; }}')
            continue
        s = one(i)
        if s: body.append('\t' + s)
    regs = ', '.join(x + ' = 0' for x in R if x not in ('zero', 'sp'))
    hdr = [f'/* OEM {fname} (.text+{start:#x}, {len(ins)} insns, frame {frame}) */',
           f'u64 noinline vae_{fname}(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)',
           '{', f'\tu32 {regs.replace("a0 = 0, a1 = 0, a2 = 0, a3 = 0, ", "")};',
           '\tu32 tg = 0, c = 0; u64 acc = 0;',
           f'\tu32 vframe[{max(frame,4)//4 + 1}] __aligned(8);', '\tu32 sp = (u32)(uintptr_t)vframe;',
           '\t(void)tg; (void)c; (void)acc; (void)sp; (void)csp; (void)at; (void)k0; (void)k1; (void)gp; (void)ra;',
           '\tvae_fn_enter();']
    # silence unused labels warnings
    used = set(re.findall(r'goto (L_[0-9a-f]+)', '\n'.join(body)))
    body = [b for b in body if not (b.endswith(':') and b[:-1] not in used)]
    if caller_area or nonlocal_flag[0]: warn.append(fname)
    return '\n'.join(hdr + body + ['\treturn ((u64)v1 << 32) | v0;', '}', ''])

if __name__ == '__main__':
    roots = sys.argv[1:]
    translated = set(roots); done = []; out = []; warn = []
    q = list(roots)
    while q:
        f = q.pop(0)
        if f in done: continue
        done.append(f)
        out.append(gen(f, translated, warn))
        for t in sorted(translated):
            if t not in done and t not in q: q.append(t)
    protos = [f'u64 vae_{f}(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);' for f in done]
    hdr = ['/* GENERATED by tools/t41_vae/gen.sh from the H20250310a tx-isp-t41.ko (SDK',
           ' * build with symbols).  Do not edit; regenerate. */']
    if not os.environ.get('VAE_NORODATA'):
        rod = ', '.join(f'{b:#04x}' for b in rodata)
        hdr.append(f'static const u8 vae_rodata[{len(rodata)}] __aligned(8) = {{ {rod} }};')
    if UNM: sys.stderr.write('UNMAPPED: ' + ' '.join(f'{k}:{v[0]}:{v[1]}' for k, v in sorted(UNM.items())) + '\n')
    open(OUT, 'w').write('\n'.join(hdr + protos + out))
    sys.stderr.write(f'functions {len(done)}: {" ".join(done)}\ncaller-area users: {" ".join(warn)}\n')
    sys.stderr.write('data: ' + ' '.join(f'{k}:{v}' for k, v in sorted(used_data.items())) + '\n')
