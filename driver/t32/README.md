# T32 C recovery baseline

This directory builds `tx-isp-t32.ko` against the T32 Linux 4.4.94 kernel.
It is a **compile and source-recovery baseline, not a device-validated driver**.
No camera has been loaded, flashed, or tested with this module.

The branch starts at opensensor/open-tx-isp `aperto`, commit `2fb6534b`.
The input module SHA-256 is
`b1f3ecf114d401b8792606a5a01b0b701387d612fe6660a30a47fe95f1b3ccee`.
The original match-source run reported 1,928 candidates, 1,916 individual
compiles, 271 normalized matches, and a failed whole-driver compile.

## What is included

- C implementations for all **1,591 distinct OEM function entry addresses**.
  The ELF has 1,594 function symbols; three are aliases of existing entries.
- **1,382 mechanical C translations** of decoded MIPS/MXU2 instructions and
  **209 retained or reviewed C candidates/wrappers**. The translations expose
  registers, memory accesses, branches, and delay slots explicitly. They are
  deliberately not presented as polished, idiomatic driver code.
- Scalar C implementations of all 13 routines containing MXU2 instructions,
  including AWB, LCE, and the vector copy routine. These use the T32 instruction
  stream; they do not substitute another SoC's image-processing algorithm.
- Original data layout in C initializers, with **893 data relocations** represented
  by C pointers or internal switch-label tokens. One shared allocation backs
  each original data section; `data-aliases.lds` supplies address aliases.
- All **33 original exports** and **21 module parameters**. Module lifetime
  annotations, variadic logging/module-request wrappers, and the five-argument
  IRQ-request wrapper have been corrected.

There are no assembly function implementations, linked OEM object/code blobs,
or replacement fallback/no-op stubs. GNU `__asm__("symbol")` annotations are
symbol-name declarations, not executable assembly. Genuine no-ops in the OEM
remain no-ops. Normal kernel primitives supply synchronization and architecture
operations.

The export's other **337 entries are interior code fragments**, not additional
ELF functions. Their enclosing functions are implemented in full;
`excluded_fragments.json` records the removed duplicate entries.

The original “0 fallback stubs” report did not establish completeness. Examples
found during integration included a constant-return TMO body, truncated IRQ/AWB
bodies, a core probe that always returned `-ENOMEM`, invented helper functions,
and isolated zero-filled replacements for shared driver globals. Non-matching
bodies were replaced where the instruction decoder could cover the complete
function. Signed MIPS LO16 offsets are resolved using the ELF relocations.

## Build

Run from the repository root with the **prepared T32 kernel tree and its matching
cross compiler**, not a T31 kernel selected by autodetection:

```sh
export KDIR=/path/to/prepared/t32/linux-4.4.94
export CROSS_COMPILE=/path/to/toolchain/bin/mipsel-linux-
make -C "$KDIR" M="$PWD/driver/t32" ARCH=mips \
    CROSS_COMPILE="$CROSS_COMPILE" -j16 modules

python3 driver/t32/tools/check_module.py \
    driver/t32/tx-isp-t32.ko "$KDIR/Module.symvers"
CROSS_COMPILE="$CROSS_COMPILE" tests/check_ko_symbols.sh \
    "$KDIR/Module.symvers" driver/t32/tx-isp-t32.ko
tests/check_isp_exports.sh t32 driver/t32/tx-isp-t32.ko \
    "${CROSS_COMPILE}readelf" driver/t32/required_exports.txt
```

The module build requires only the checked-in C/linker sources and kernel build
inputs; the original OEM module, Binary Ninja export, and model are not needed.
Validation used the Thingino `wyze_campan4_t32nq_sc835hai_atbm6162s-4.4.94-uclibc`
output, kernel source revision `470050ba3702da8bac092f26b327f590abcf976c`, and
GCC 16.2. A clean module build and symbol checks passed. This is not a warning-free
build: Kbuild retains compatibility diagnostic relaxations for recovered C.

## Recovery tests and reproduction

Python tools need `pyelftools`. The MXU arithmetic test also needs a host C
compiler. The integer test uses a freestanding 32-bit x86 Linux executable and
therefore does not need a 32-bit libc; its startup syscall is test harness code.

```sh
python3 driver/t32/tools/test_mxu_lower.py
export T32_OEM_MODULE=/path/to/original/tx-isp-t32.ko
export OBJDUMP="${CROSS_COMPILE}objdump"  # must support -M mxu2
python3 driver/t32/tools/test_integer_lower.py
python3 driver/t32/tools/verify_lowered.py
```

The MXU test checks 57 arithmetic/shuffle/move operations over 17,100 boundary,
random, and overlapping-register cases with UBSan enabled. Integer tests cover
branch delay slots, branch-likely annulment, jumps into delay slots, signed
integer division edge cases, all four unaligned word offsets, a split stack
frame, and an atomic counter loop. `verify_lowered.py` checks that all 1,382
mechanical function bodies reproduce exactly from the hash-checked OEM input.
These tests validate translation mechanics, **not hardware equivalence**.

`tools/lower_mips.py --oem-module ... --objdump ... 209b8` regenerates a selected
mechanical body. `recovery_input.json` contains the address/section inventory;
`recovery_manifest.json` records the final source disposition.
`candidate_manifest.json` preserves the original match-source results, which
must not be interpreted as new equivalence results after integration.

## Handoff work for Lufi

1. Review the register-level C and replace it with typed structures and ordinary
   C functions incrementally. Indirect calls currently use a broad o32 word
   argument signature, including large by-value argument blocks. Compiler
   clones and callback/variadic ABIs need device-backed review.
2. Audit stack use before loading. Scalar vector state and simulated OEM frames
   enlarge some frames; the observed maximum compiler warning is 2,320 bytes in
   `Tisp_lce_soft_simd_v4`, and nested call-stack usage has not been established.
3. Compare AWB/AE/LCE outputs, MMIO traces, interrupt ordering, sensor registration,
   streaming, restart, and teardown against the OEM module on a recoverable test
   device. Scalar MXU replacements may cost substantially more CPU time.
4. Check the retained candidates and relocated data layouts against the actual
   kernel/configuration. Normalized instruction matches from the original run
   are evidence for isolated functions, not proof of full-driver behavior.

The LL/SC translations use kernel compare-exchange for the recognized counter
loops. This preserves their update intent but is not an emulation of every
possible reservation failure. MXU division by zero is unspecified by the ISA;
the scalar helper uses an all-ones result for that input. Neither choice is a
claim of cycle- or fault-identical behavior.
