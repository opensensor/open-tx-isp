#!/usr/bin/env python3
"""T40 #173: no lifted pointer may be a bare integer literal (decompiler artefact: an OEM .data/.bss anchor
emitted as a hard-coded address, e.g. (int32_t *)(16712) in tisp_awb_algo_deinit_internal -> kernel oops).

1. tisp_awb_algo_deinit_internal must address awb_algo_enable[] (the array tisp_awb_algo_init fills).
2. No local pointer may be initialised from a bare integer literal below 0x80000000.
Usage: t40_hardcoded_anchor_check.py [driver.c]"""
import os, re, sys
src = sys.argv[1] if len(sys.argv) > 1 else os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                                          "../driver/t40/tx_isp_t40_recovered.c")
text = open(src, encoding="utf-8", errors="replace").read()
bad = []
m = re.search(r"\bint32_t tisp_awb_algo_deinit_internal\(int32_t arg1\)\s*\{(.*?)\n\}", text, re.S)
if not m:
    bad.append("tisp_awb_algo_deinit_internal definition not found")
else:
    body = re.sub(r"/\*.*?\*/", "", m.group(1), flags=re.S)
    if "awb_algo_enable" not in body:
        bad.append("tisp_awb_algo_deinit_internal does not use awb_algo_enable")
    if re.search(r"\*\s*\)\s*\(?\s*(0x[0-9a-fA-F]+|\d+)\s*\)?", body):
        bad.append("tisp_awb_algo_deinit_internal casts an integer literal to a pointer")
# a local pointer initialised from a bare literal, `int32_t *base = (int32_t *)(16712);` (values that are
# stored as plain integers, e.g. OEM size constants in frame slots, are not pointers and are not matched)
for mm in re.finditer(r"\b(u?int(?:8|16|32)_t)\s*\*\s*(\w+)\s*=\s*\(\s*\1\s*\*\s*\)\s*\(?\s*(0x[0-9a-fA-F]+|\d+)\s*\)?\s*;", text):
    v = int(mm.group(3), 0)
    if 0x1000 <= v < 0x80000000:
        bad.append("line %d: pointer %s initialised from the literal %s" % (text.count("\n", 0, mm.start()) + 1, mm.group(2), mm.group(3)))
# #182: the WDR-enable / LCE-tgain readers and writers must meet on the OEM [2] arrays (never on the isp_memopt
# module parameter or a stray offset from a 4-byte stand-in).
def body_of(name, sig_re):
    mm = re.search(sig_re + r"\s*\{(.*?)\n\}", text, re.S)
    if not mm:
        bad.append(name + " definition not found")
        return None
    return re.sub(r"/\*.*?\*/", "", mm.group(1), flags=re.S)
for fn, sig, want in (
        ("tisp_dmsc_dn_params_refresh", r"\bint32_t tisp_dmsc_dn_params_refresh\(uint32_t a0\)", "t40_dmsc_wdr_en"),
        ("tisp_ydns_dn_params_refresh", r"\bint32_t tisp_ydns_dn_params_refresh\(uint32_t a0\)", "regtrace_ydns_wdr_flag"),
        ("tisp_ysp_dn_params_refresh", r"\bint32_t tisp_ysp_dn_params_refresh\(uint32_t a0\)", "regtrace_ysp_wdr_flags"),
        ("tisp_lce_tgain_interp_strength", r"\bint32_t tisp_lce_tgain_interp_strength\(uint32_t a0\)", "t40_lce_tgain_oem"),
        ("tisp_lce_tgain_update", r"\bint32_t tisp_lce_tgain_update\(uint32_t a0, uint32_t a1\)", "t40_lce_tgain_oem"),
        ("tisp_dmsc_wdr_en", r"\bint64_t tisp_dmsc_wdr_en\(uint32_t a0, uint32_t a1\)", "t40_dmsc_wdr_en")):
    b = body_of(fn, sig)
    if b is None:
        continue
    if "isp_memopt" in b:
        bad.append(fn + " still addresses isp_memopt")
    if want not in b:
        bad.append(fn + " does not use " + want)
    if re.search(r"&(dmsc_wdr_en|ydns_wdr_en|ysp_wdr_en|lce_tgain)\b", b):
        bad.append(fn + " still uses a 4-byte stand-in (&dmsc_wdr_en/&ydns_wdr_en/&ysp_wdr_en/&lce_tgain)")
nocomment = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
for stand in ("dmsc_wdr_en", "ydns_wdr_en", "ysp_wdr_en", "lce_tgain"):
    for mm in re.finditer(r"&" + stand + r"\b(?!\w)", nocomment):
        bad.append("&%s used in code (OEM array replaces it)" % stand)
for b in bad:
    print("FAIL: " + b)
if bad:
    sys.exit(1)
print("t40_hardcoded_anchor_check: ok")
