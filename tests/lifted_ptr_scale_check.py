#!/usr/bin/env python3
"""Lifted-driver typed-pointer scaling scanner (T40 #186/#187 bug class, T40 + T41 recovered drivers).

The lifter declares MIPS registers as `uintptr_t *` / `uint32_t *` ... and keeps the OEM byte arithmetic
(`addiu rD, rS, imm`) as C `rD = rS + imm;`.  C scales that by sizeof(*rS): `v0 = v0 + 24` on a `uintptr_t *`
steps 96 bytes, so a stride walk reads the wrong units, loops `!=`-compare against an integer bound and never
end, and stores land behind the object (#186: tisp_g/s_mscaler_mask_attr).  Classes (per function):

  step   `P = P +/- N`, `P += N` on a typed pointer P with element size > 1 (walk / stride)
  off    `X = P +/- N`, `X = N + P` on a typed P (offset from a typed base, N a literal)
  loop   a backward `goto` whose `!=` / `==` condition names a typed pointer that the function steps (a step that
         is not a multiple of the bound never meets it: endless loop)
  ctr    a `loop` whose stepped pointer starts at a literal, is stepped by literal N and meets a literal bound that
         (bound - start) is not a multiple of N*sizeof(*P): the compiled counter never equals the bound, the loop
         only ends through another exit (#190-class: streamoff wait loop ran without its 21 * 100 ms limit)
  unal   `*(uint32_t *)((char *)X + k)` with k not a multiple of 4 (u16: odd k): unaligned access, usually a
         u16 field read as a word

Baseline file (tests/lifted_ptr_scale_baseline.txt): `<tag> <function> <class> <count> <status> [note]`, one line
per (function, class).  status: `open` (not yet compared with the OEM), `unreach` (no static path from hand-written code, see live_set),
`shim` (confirmed against the OEM, but the call is skipped by a
hand-written path: needs a fix before that path is enabled), `layout` (confirmed, but the typed access hits a stray OEM .bss anchor such as `&isp_memopt + K`: a type fix alone moves the stray write, needs a real object first), `dead` (reviewed, never runs), `ok` (reviewed against the OEM, correct), `fixed`.  The check
fails when a function/class is missing from the baseline or its count grew; shrinking counts are reported so
the baseline can be tightened.  A function that gets a hand-written replacement just disappears from the scan.

usage: lifted_ptr_scale_check.py [--baseline FILE] [--write-baseline FILE] [--list CLASS] [--func NAME]
"""
import os, re, sys, argparse, collections

HERE = os.path.dirname(os.path.abspath(__file__))
FILES = (("t40", "../driver/t40/tx_isp_t40_recovered.c"), ("t41", "../driver/t41/tx_isp_t41_recovered.c"))
SZ = {"uintptr_t": 4, "uint32_t": 4, "int32_t": 4, "int": 4, "uint16_t": 2, "int16_t": 2,
      "int64_t": 8, "uint64_t": 8, "long": 4, "unsigned": 4}
DECL = re.compile(r"\b(uintptr_t|uint32_t|int32_t|int|uint16_t|int16_t|int64_t|uint64_t|long|unsigned)\s*\*\s*(\w+)")
NUM = r"(0x[0-9a-fA-F]+|\d+)"
FUNC = re.compile(r"^[A-Za-z_][\w \*]*?[ \*](\w+)\(([^;]*)\)\s*$")
RE_OFF = re.compile(r"^\s*(\w+)\s*=\s*(?:(\w+)\s*[+-]\s*" + NUM + r"|" + NUM + r"\s*\+\s*(\w+))\s*;")
RE_ACC = re.compile(r"^\s*(\w+)\s*(\+=|-=)\s*" + NUM + r"\s*;")
RE_BACK = re.compile(r"if \((\w+) (!=|==) (\w+)\) \{ goto (\w+); \}")
RE_UNAL = re.compile(r"\(\s*(uint32_t|int32_t|uint16_t|int16_t)\s*\*\s*\)\s*\(\s*\(\s*(?:char|uint8_t)\s*\*\s*\)\s*\w+\s*\+\s*" + NUM + r"\s*\)")


def mask_inactive(lines):
    """Blank the lines the real (Kbuild: -DREGTRACE_KERNEL_TREE_BUILD) build does not compile: `#if 0`, the #else
    side of `#ifdef REGTRACE_KERNEL_TREE_BUILD` and the body of `#ifndef REGTRACE_KERNEL_TREE_BUILD` (the old lifted
    code behind the hand-written kernel-tree replacements).  Other conditionals count as taken on both sides."""
    out = []
    stack = []  # entries: [parent_active, this_branch_active]
    act = True
    for ln in lines:
        m = re.match(r"\s*#\s*(ifdef|ifndef|if|elif|else|endif)\b\s*(.*)", ln)
        if m:
            d, arg = m.group(1), m.group(2).strip()
            if d in ("ifdef", "ifndef", "if"):
                br = True
                if d == "ifdef" and arg.startswith("REGTRACE_KERNEL_TREE_BUILD"):
                    br = True
                elif d == "ifndef" and arg.startswith("REGTRACE_KERNEL_TREE_BUILD"):
                    br = False
                elif d == "if" and arg in ("0", "(0)"):
                    br = False
                stack.append((act, br, d == "ifdef" and arg.startswith("REGTRACE_KERNEL_TREE_BUILD") or
                              d == "ifndef" and arg.startswith("REGTRACE_KERNEL_TREE_BUILD") or
                              d == "if" and arg in ("0", "(0)")))
                act = act and br
            elif d == "else" and stack:
                pa, br, known = stack.pop()
                nb = (not br) if known else True
                stack.append((pa, nb, known))
                act = pa and nb
            elif d == "elif" and stack:
                pa, br, known = stack.pop()
                stack.append((pa, True, False))
                act = pa
            elif d == "endif" and stack:
                act = stack.pop()[0]
            out.append("")
            continue
        out.append(ln if act else "")
    return out


def cut_stub_tails(lines):
    """A lifted function whose body starts with `#ifdef REGTRACE_KERNEL_TREE_BUILD { ...; return X; } #endif` (no #else)
    is a hand-written kernel-tree replacement: in the Kbuild build the lifted tail behind it never runs.  Blank it."""
    out = list(lines)
    i = 0
    while i < len(out):
        if FUNC.match(out[i]) and i + 1 < len(out) and out[i + 1] == "{":
            j = i + 1
            while j < len(out) and out[j] != "}":
                j += 1
            k = i + 2
            while k < j:
                if re.match(r"\s*#\s*ifdef\s+REGTRACE_KERNEL_TREE_BUILD\b", out[k]):
                    d, e, has_else = 1, k + 1, False
                    while e < j and d:
                        if re.match(r"\s*#\s*(if|ifdef|ifndef)\b", out[e]):
                            d += 1
                        elif re.match(r"\s*#\s*(else|elif)\b", out[e]) and d == 1:
                            has_else = True
                        elif re.match(r"\s*#\s*endif\b", out[e]):
                            d -= 1
                        e += 1
                    blk = [l for l in out[k + 1:e - 1] if l.strip()]
                    if (not has_else and len(blk) >= 3 and ((blk[0] == "    {" and blk[-1] == "    }"
                            and re.match(r"^\s{8}return\b.*;", blk[-2])) or re.match(r"^\s{4}return\b.*;", blk[-1]))):
                        for q in range(e, j):
                            out[q] = ""
                        break
                    k = e
                else:
                    k += 1
            i = j
        i += 1
    return out


def functions(lines):
    i = 0
    while i < len(lines):
        m = FUNC.match(lines[i])
        if m and i + 1 < len(lines) and lines[i + 1] == "{":
            j = i + 1
            while j < len(lines) and lines[j] != "}":
                j += 1
            yield m.group(1), i + 1, lines[i:j + 1]
            i = j
        i += 1


def live_set(rec, others):
    """Static over-approximation of the functions that can run: hand-written functions, anything named in other
    files / EXPORT_SYMBOL / ops tables is a root, edges are identifier references (an `if (1) { ... return }` stub
    cuts the rest of its body).  Functions outside it are marked `unreach` in the baseline (not device-proven)."""
    lines=mask_inactive(cut_stub_tails(open(rec,errors='replace').read().split("\n")))
    funcs={};i=0;span=[]
    while i<len(lines):
        m=re.match(r'^[A-Za-z_][\w \*]*?[ \*](\w+)\(([^;]*)\)\s*$',lines[i])
        if m and i+1<len(lines) and lines[i+1]=='{':
            j=i+1
            while j<len(lines) and lines[j]!='}': j+=1
            funcs[m.group(1)]=("\n".join(lines[i:j+1]), lines[i-1].startswith('/* WHOLE_DRIVER_CANDIDATE'))
            span.append((i,j)); i=j
        i+=1
    inf=set()
    for a,b in span: inf.update(range(a,b+1))
    non="\n".join(l for k,l in enumerate(lines) if k not in inf and not re.match(r'^[\w \*]+\(.*\);\s*$',l) and not l.startswith('#'))
    idre=re.compile(r'\b[A-Za-z_]\w*\b')
    F=set(funcs)
    def strip(b):
        b=re.sub(r'/\*.*?\*/','',b,flags=re.S)
        m=re.search(r'\n\s*if \(1\) \{.*?\n\s*return[^\n]*\n\s*\}',b,re.S)
        if m: b=b[:m.end()]   # stub: rest is dead
        return b
    refs={f:set(idre.findall(strip(b)))&F-{f} for f,(b,c) in funcs.items()}
    oth=""
    for f in others: oth+=open(f,errors='replace').read()
    roots={f for f,(b,c) in funcs.items() if not c}
    roots|=set(idre.findall(oth))&F
    roots|=set(idre.findall("\n".join(l for l in non.split("\n") if re.search(r"EXPORT_SYMBOL|module_init|module_exit|\.\w+\s*=|^\s*    roots|=set(idre.findall(non))&F?\w+,\s*$",l))))&F
    live=set();st=list(roots)
    while st:
        f=st.pop()
        if f in live: continue
        live.add(f); st.extend(refs[f])
    return F,live,roots,funcs


def scan(path):
    """-> {(func, class): [(line, text)]}"""
    lines = mask_inactive(cut_stub_tails(open(path, encoding="utf-8", errors="replace").read().split("\n")))
    res = collections.defaultdict(list)
    for name, first, body in functions(lines):
        tv = {}
        for ln in body:
            if ln.lstrip().startswith(("/*", "*", "#")):
                continue
            for d in DECL.finditer(ln):
                if "(" in ln[:d.start()] and ln is not body[0]:
                    continue  # cast, not a declaration
                tv[d.group(2)] = SZ[d.group(1)]
        stepped = set()
        stepn = collections.defaultdict(list)
        lit = collections.defaultdict(list)
        for k_, ln in enumerate(body):
            mm = re.match(r"^\s*(\w+)\s*=\s*" + NUM + r"\s*;", re.sub(r"/\*.*?\*/", "", ln))
            if mm:
                lit[mm.group(1)].append((k_, int(mm.group(2), 0)))
        labels = {}
        for k, ln in enumerate(body):
            s = re.sub(r"/\*.*?\*/", "", ln)
            m = RE_ACC.match(s)
            if m and m.group(1) in tv:
                res[(name, "step")].append((first + k, s.strip()))
                stepped.add(m.group(1))
                stepn[m.group(1)].append(int(m.group(3), 0) * (1 if m.group(2) == "+=" else -1))
                continue
            m = RE_OFF.match(s)
            if m:
                lhs, p = m.group(1), m.group(2) or m.group(5)
                if p in tv:
                    if p == lhs:
                        res[(name, "step")].append((first + k, s.strip()))
                        stepped.add(p)
                        stepn[p].append(int(m.group(3), 0) * (1 if "+" in s.split("=", 1)[1] else -1))
                    else:
                        res[(name, "off")].append((first + k, s.strip()))
            for u in ([] if "_setLeftPart32" in s or "_setRightPart32" in s else RE_UNAL.finditer(s)):  # lwl/lwr pair
                w = 4 if "32" in u.group(1) else 2
                if int(u.group(2), 0) % w:
                    res[(name, "unal")].append((first + k, s.strip()))
            m = re.match(r"^(\w+):", s)
            if m:
                labels[m.group(1)] = k
        for k, ln in enumerate(body):
            m = RE_BACK.search(ln)
            if m and labels.get(m.group(4), 1 << 30) < k and (m.group(1) in stepped or m.group(3) in stepped):
                res[(name, "loop")].append((first + k, ln.strip()))
                for a_, b_ in ((m.group(1), m.group(3)), (m.group(3), m.group(1))):
                    bl = [v for q, v in lit.get(b_, ()) if q < k]
                    sl = [v for q, v in lit.get(a_, ()) if q < labels[m.group(4)]]
                    if a_ in stepped and a_ in tv and m.group(2) == "!=" and bl and sl and sum(stepn[a_]):
                        st_ = sum(stepn[a_]) * tv[a_]
                        if st_ and (bl[-1] - sl[-1]) % st_:
                            res[(name, "ctr")].append((first + k, ln.strip()))
    return res


SELFTEST_SRC = """
int64_t bad_fn(uintptr_t a0)
{
    uintptr_t a1 = 0;
    uintptr_t *v0 = 0;
    uintptr_t *s0 = 0;
    v0 = 0;
    a1 = 12;
bad_fn0x10:
    v0 = v0 + 4;
    s0 = v0 + 24;
    if (v0 != a1) { goto bad_fn0x10; }
    return 0;
}

int64_t fixed_fn(uintptr_t a0)
{
    uintptr_t a1 = 0;
    uintptr_t v0 = 0;
    uintptr_t s0 = 0;
    v0 = 0;
    a1 = 12;
fixed_fn0x10:
    v0 = v0 + 4;
    s0 = v0 + 24;
    if (v0 != a1) { goto fixed_fn0x10; }
    return 0;
}

int64_t stub_fn(uintptr_t a0)
{
    uintptr_t *v0 = 0;
#ifdef REGTRACE_KERNEL_TREE_BUILD
    if (a0) {
        return 1;
    }
    return 0;
#endif
    v0 = v0 + 4;
    return 0;
}
"""


def selftest():
    import tempfile
    with tempfile.NamedTemporaryFile("w", suffix=".c", delete=False) as f:
        f.write(SELFTEST_SRC)
    try:
        r = scan(f.name)
    finally:
        os.unlink(f.name)
    got = {k: len(v) for k, v in r.items()}
    want = {("bad_fn", "step"): 1, ("bad_fn", "off"): 1, ("bad_fn", "loop"): 1, ("bad_fn", "ctr"): 1}
    if got != want:
        print("selftest FAIL: got %s want %s" % (got, want))
        return 1
    print("lifted_ptr_scale_check selftest: ok (typed pointer flagged, uintptr_t byte arithmetic and KERNEL_TREE stub tail not)")
    return 0


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--selftest", action="store_true")
    ap.add_argument("--baseline")
    ap.add_argument("--write-baseline")
    ap.add_argument("--list")
    ap.add_argument("--func")
    ap.add_argument("files", nargs="*")
    a = ap.parse_args()
    if a.selftest:
        return selftest()
    allres = {}
    for tag, rel in FILES:
        p = os.path.join(HERE, rel)
        if os.path.exists(p):
            for (fn, cl), v in scan(p).items():
                allres[(tag, fn, cl)] = v
    if a.list or a.func:
        for (tag, fn, cl), v in sorted(allres.items()):
            if (not a.list or cl == a.list) and (not a.func or fn == a.func):
                for ln, t in v:
                    print("%s %s %s:%d %s" % (tag, cl, fn, ln, t))
        return 0
    if a.write_baseline:
        live = {}
        for tag, rel in FILES:
            p = os.path.join(HERE, rel)
            d = os.path.dirname(p)
            oth = [os.path.join(d, f) for f in os.listdir(d) if f.rsplit(".", 1)[-1] in ("c", "h", "inc") and not f.endswith("recovered.c")]
            oth += [os.path.join(HERE, "../driver/common", f) for f in os.listdir(os.path.join(HERE, "../driver/common")) if f.endswith((".c", ".h"))]
            live[tag] = live_set(p, oth)[1]
        old = {}
        if os.path.exists(a.write_baseline):
            for l in open(a.write_baseline):
                f = l.rstrip("\n").split(None, 5)
                if len(f) >= 5 and not l.startswith("#"):
                    old[tuple(f[:3])] = (f[4], f[5] if len(f) > 5 else "")
        with open(a.write_baseline, "w") as o:
            o.write("# lifted_ptr_scale_check.py baseline: <tag> <function> <class> <count> <status> [note]\n"
                    "# status open = not yet compared with the OEM, dead/ok/fixed = reviewed (see the script header)\n")
            for (tag, fn, cl), v in sorted(allres.items()):
                st, note = old.get((tag, fn, cl), ("open" if fn in live[tag] else "unreach", ""))
                o.write(("%s %s %s %d %s %s" % (tag, fn, cl, len(v), st, note)).rstrip() + "\n")
        print("wrote %d entries" % len(allres))
        return 0
    base = {}
    if a.baseline:
        for l in open(a.baseline):
            f = l.rstrip("\n").split(None, 5)
            if len(f) >= 5 and not l.startswith("#"):
                base[tuple(f[:3])] = int(f[3])
    bad = 0
    for key, v in sorted(allres.items()):
        if key not in base:
            print("FAIL: new %s finding %s %s (%d): %s" % (key[2], key[0], key[1], len(v), v[0][1]))
            bad += 1
        elif len(v) > base[key]:
            print("FAIL: %s %s %s grew %d -> %d: %s" % (key[0], key[1], key[2], base[key], len(v), v[-1][1]))
            bad += 1
    for key, n in sorted(base.items()):
        got = len(allres.get(key, ()))
        if got < n:
            print("note: %s %s %s shrank %d -> %d (tighten the baseline)" % (key[0], key[1], key[2], n, got))
    cnt = collections.Counter(k[2] for k in allres)
    print("lifted_ptr_scale_check: %s, %d function/class entries" % (dict(cnt), len(allres)))
    if bad:
        return 1
    print("lifted_ptr_scale_check: ok")
    return 0


if __name__ == "__main__":
    sys.exit(main())
