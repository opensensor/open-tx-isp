# SPDX-License-Identifier: GPL-2.0
"""Compare recovered WDR against an offline MIPS reference and generate fixtures.

Requires a native C compiler, pyelftools and unicorn; no device is accessed.
The supplied vendor executable is never copied into the generated header.
"""

from pathlib import Path
import argparse
import ctypes as C
import re
import subprocess
import tempfile
from t31_wdr_mips_oracle import Oracle, PACK

root = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument(
    "--vendor-ko",
    type=Path,
    required=True,
    help="Local unstripped T31 reference ELF module",
)
parser.add_argument(
    "--output", type=Path, default=root / "tests/t31_wdr_oracle_expected.h"
)
parser.add_argument("--cc", default="cc")
args = parser.parse_args()
x = Oracle(args.vendor_ko)
U = C.c_uint32
P = C.POINTER(U)
temporary = tempfile.TemporaryDirectory(prefix="t31-wdr-oracle-")
library = Path(temporary.name) / "runtime.so"
subprocess.run(
    [
        args.cc,
        "-std=c99",
        "-Wall",
        "-Wextra",
        "-Werror",
        "-Wno-unused-function",
        "-DT31_WDR_ORACLE_LIBRARY",
        "-fPIC",
        "-shared",
        "-O2",
        str(root / "tests/tx_isp_t31_wdr_runtime_test.c"),
        "-o",
        str(library),
    ],
    check=True,
)
n = C.CDLL(str(library))
for f in [
    "test_param",
    "test_fpga_arg",
    "test_log",
    "test_ev_state",
    "test_ae_controls",
]:
    getattr(n, f).restype = P
n.test_log_hash.restype = U
n.test_fpga_hash.restype = U
n.test_ev_hash.restype = U
names = re.findall(
    r"WDR_PARAM\((\w+),", (root / "driver/t31/tx_isp_t31_wdr_params.inc").read_text()
)
fpganames = [
    "param_computerModle_software_in_array",
    "param_deviationPara_software_in_array",
    "param_ratioPara_software_in_array",
    "param_x_thr_software_in_array",
    "param_y_thr_software_in_array",
    "param_thrPara_software_in_array",
    "param_xy_pix_low_software_in_array",
    "param_motionThrPara_software_in_array",
    "param_d_thr_normal_software_in_array",
    "param_d_thr_normal1_software_in_array",
    "param_d_thr_normal2_software_in_array",
    "param_d_thr_normal_min_software_in_array",
    "param_d_thr_2_software_in_array",
    "param_multiValueLow_software_in_array",
    "param_multiValueHigh_software_in_array",
    "wdr_hist_R0",
    "wdr_hist_G0",
    "wdr_hist_B0",
    "wdr_hist_R1",
    "wdr_hist_G1",
    "wdr_hist_B1",
    "wdr_mapR_software_out",
    "wdr_mapB_software_out",
    "wdr_mapG_software_out",
    "param_wdr_thrLable_array",
    "wdr_thrLableN_software_out",
    "wdr_thrAll_software_out",
    "wdr_thrRangeK_software_out",
    "param_wdr_detial_para_software_in_array",
    "wdr_detial_para_software_out",
]


def hash_words(words):
    h = 2166136261
    for v in words:
        for b in PACK(v):
            h = ((h ^ b) * 16777619) & 0xFFFFFFFF
    return h


def loadparams():
    for i, name in enumerate(names):
        x.put(name, [n.test_param(i)[j] for j in range(n.test_param_size(i) // 4)])


def fail(msg, case, expected, actual):
    raise AssertionError((msg, case, hex(expected), hex(actual)))


fpga = []
for case in range(432):
    n.test_fpga_prepare(case)
    for i, name in enumerate(fpganames):
        x.put(name, [n.test_fpga_arg(i)[j] for j in range(n.test_fpga_size(i))])
    x.call("Tiziano_wdr_fpga", *[x.syms[name][0] for name in fpganames])
    expected = hash_words(sum([x.get(name) for name in fpganames], []))
    rc = n.test_fpga_calculate()
    actual = n.test_fpga_hash()
    if rc or expected != actual:
        for i, name in enumerate(fpganames):
            e = x.get(name)
            a = [n.test_fpga_arg(i)[j] for j in range(n.test_fpga_size(i))]
            if a != e:
                print(
                    name,
                    [(j, ee, aa) for j, (ee, aa) in enumerate(zip(e, a)) if ee != aa][
                        :10
                    ],
                )
        fail("FPGA", case, expected, actual)
    fpga.append(expected)
print("432 FPGA cases matched", flush=True)
init = []
for case in range(72):
    n.test_init_prepare(case)
    loadparams()
    x.put("wdr_gam_y33_array", [i * 4 * 4095 // 128 for i in range(33)])
    x.writes.clear()
    x.call("tiziano_wdr_params_init")
    expected = hash_words(sum([list(v) for v in x.writes], []))
    assert n.test_param_init() == 0
    actual = n.test_log_hash()
    if expected != actual:
        fail("init", case, expected, actual)
    init.append(expected)
print("72 register initialization cases matched", flush=True)
ev = []
for case in range(240):
    n.test_ev_prepare(case)
    loadparams()
    state = n.test_ev_state()
    for i, name in enumerate(
        ["wdr_ev_now", "wdr_ev_old", "wdr_ev_changed", "wdr_ev_changed_deghost"]
    ):
        x.put(name, state[i])
    x.put("wdr_ev_out_list", [state[i] for i in range(4, 11)])
    x.put("wdr_s2l_ratio", state[11])
    x.put("tisp_ae_ctrls", [n.test_ae_controls()[i] for i in range(38)])
    x.call("tisp_wdr_ev_calculate")
    expected_words = sum(
        [
            x.get(name)
            for name in [
                "wdr_ev_now",
                "wdr_ev_old",
                "wdr_ev_changed",
                "wdr_ev_changed_deghost",
                "wdr_ev_out_list",
                "wdr_s2l_ratio",
                "param_wdr_para_array",
                "param_wdr_detail_th_w_array",
                "param_wdr_degost_para_array",
                "param_fusion1_cure_y_array",
            ]
        ],
        [],
    )
    expected = hash_words(expected_words)
    assert n.tisp_wdr_ev_calculate() == 0
    actual = n.test_ev_hash()
    if expected != actual:
        fail("EV", case, expected, actual)
    ev.append(expected)
print("240 EV/fusion/deghost cases matched", flush=True)
output = []
for case in range(72):
    n.test_output_prepare(case)
    loadparams()
    for i, name in enumerate(fpganames):
        x.put(name, [n.test_fpga_arg(i)[j] for j in range(n.test_fpga_size(i))])
    for i, name in enumerate(
        [
            "wdr_para_array4",
            "wdr_para_array5",
            "wdr_para_init_div4",
            "wdr_para_init_div5",
        ]
    ):
        x.put(name, n.test_param(0)[4 + i])
    x.writes.clear()
    x.call("tiziano_wdr_soft_para_out")
    expected = hash_words(sum([list(v) for v in x.writes], []))
    assert n.tiziano_wdr_soft_para_out() == 0
    actual = n.test_log_hash()
    if expected != actual:
        fail("output", case, expected, actual)
    output.append(expected)
print("72 software result register cases matched", flush=True)
spatial = []
n.test_spatial_case.restype = U
for case, (width, height, radius) in enumerate(
    [(64, 40, 8), (1920, 1080, 90), (2048, 1536, 96), (640, 480, 30), (1281, 721, 60)]
):
    x.put("width_wdr_def", width)
    x.put("height_wdr_def", height)
    tool = x.get("param_wdr_tool_control_array")
    tool[2] = radius
    x.put("param_wdr_tool_control_array", tool)
    x.call("tiziano_wdr_5x5_param")
    expected = hash_words(
        sum(
            [
                x.get("param_wdr_weightLUT" + name + "_array_def")
                for name in ["20", "02", "12", "22", "21"]
            ],
            [],
        )
        + x.get("param_centre5x5_w_distance_array_def")
    )
    actual = n.test_spatial_case(case)
    if expected != actual:
        fail("spatial", case, expected, actual)
    spatial.append(expected)
print("5 spatial cases matched", flush=True)
lines = [
    "/* SPDX-License-Identifier: GPL-2.0 */",
    "/* Generated from the offline T31 vendor oracle; no executable vendor code. */",
]
for name, values in [
    ("fpga", fpga),
    ("init", init),
    ("ev", ev),
    ("output", output),
    ("spatial", spatial),
]:
    lines.append("static const u32 wdr_" + name + "_expected[] = {")
    for i in range(0, len(values), 8):
        lines.append("\t" + ", ".join("0x%08xU" % v for v in values[i : i + 8]) + ",")
    lines.append("};")
args.output.write_text("\n".join(lines) + "\n")

temporary.cleanup()
