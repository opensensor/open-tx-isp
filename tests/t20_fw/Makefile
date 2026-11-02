# T20/T10 firmware optimisation-safety harness (see README in harness.c).
#
#   make -C tests/t20_fw check          -O0 vs -Os, all scenarios, stack poison
#   make -C tests/t20_fw VARIANTS="O0 Os O2" check
#   make -C tests/t20_fw CALIB=/path/jxf23.bin check
#   make -C tests/t20_fw check-poke     also the vendor register-poke scenario
#   make -C tests/t20_fw SCENARIOS="simple" check
#   make -C tests/t20_fw vdiff          function-level diff against the vendor
#                                       module (see vdiff/vdiff.py; needs
#                                       T20FW_VENDOR_KO, a mipsel gcc and the
#                                       python "unicorn" module, else skips)
#
# Needs only "gcc -m32" code generation (no 32-bit libc).  Skips with a
# message when the compiler cannot produce i386 code.

CC ?= gcc
OUT ?= build
ROOT := ../..
SDK := $(ROOT)/external/ingenic-sdk/3.10.14/isp/t20
CALIB ?= $(firstword $(wildcard $(T20FW_CALIB)))
VARIANTS ?= O0 Os
REF ?= O0

ARCH := -m32 -fno-pic -ffreestanding -mno-sse -mno-mmx -malign-double -fno-stack-protector
# kernel 3.10 MIPS flags that change semantics
KFLAGS := -fno-strict-aliasing -fno-common -fno-delete-null-pointer-checks \
	-fno-strict-overflow -fconserve-stack -fomit-frame-pointer
FWFLAGS := $(ARCH) $(KFLAGS) -std=gnu99 -fpermissive -w -include pre.h
FLAGS_O0 := -O0 -fno-tree-dce -fno-ipa-pure-const -fno-ipa-reference
FLAGS_Os := -Os
FLAGS_O2 := -O2
FLAGS_O1 := -O1
# function coverage of the scenario (-O0 + -finstrument-functions)
FLAGS_cov := $(FLAGS_O0) -finstrument-functions
SDKINC := -nostdinc -Iinclude -isystem $(shell $(CC) -print-file-name=include) \
	-I$(SDK) -I$(SDK)/apical-isp -I$(SDK)/include -I$(ROOT)/external/ingenic-sdk/include
HFLAGS := $(ARCH) -O1 -std=gnu99 -fno-builtin -Wall -Wno-unused-function

HOST_OBJS := $(OUT)/harness.o $(OUT)/calib.o $(OUT)/rt.o \
	$(OUT)/sdk_static.o $(OUT)/sdk_dynamic.o $(OUT)/sdk_calibrations.o $(OUT)/sdk_calinit.o \
	$(OUT)/t20_math.o

.PHONY: all check check-poke clean coverage skip vdiff
.SECONDARY:
M32_OK := $(shell echo 'int x;' | $(CC) -m32 -x c -c -o /dev/null - 2>/dev/null && echo y)
ifneq ($(M32_OK),y)
all check coverage: skip
skip:
	@echo "t20_fw: $(CC) cannot build i386 code, skipping"
else
all: $(foreach v,$(VARIANTS),$(OUT)/t20fw-$(v) $(OUT)/t20fw-$(v).sym)

$(OUT):
	mkdir -p $@

$(OUT)/fw-%.o: fw_unit.c pre.h $(ROOT)/driver/t20/tx_isp_t20_firmware.c | $(OUT)
	$(CC) $(FWFLAGS) $(FLAGS_$*) $(FWEXTRA) -c -o $@ fw_unit.c

$(OUT)/rt.o: rt.c rt.h | $(OUT)
	$(CC) $(ARCH) -O2 -fno-builtin -fno-tree-loop-distribute-patterns -Wall -c -o $@ $<
$(OUT)/harness.o: harness.c harness.h rt.h | $(OUT)
	$(CC) $(HFLAGS) -c -o $@ $<
$(OUT)/calib.o: calib.c rt.h | $(OUT)
	$(CC) $(ARCH) -O1 -w $(SDKINC) -c -o $@ $<
$(OUT)/sdk_static.o: $(SDK)/apical-isp/apical_static_calibrations.c | $(OUT)
	$(CC) $(ARCH) -O1 -w $(SDKINC) -c -o $@ $<
$(OUT)/sdk_dynamic.o: $(SDK)/apical-isp/apical_dynamic_calibrations.c | $(OUT)
	$(CC) $(ARCH) -O1 -w $(SDKINC) -c -o $@ $<
$(OUT)/sdk_calibrations.o: $(SDK)/apical-isp/apical_calibrations.c | $(OUT)
	$(CC) $(ARCH) -O1 -w -std=gnu99 -fpermissive $(SDKINC) -c -o $@ $<
$(OUT)/t20_math.o: $(ROOT)/driver/t20/tx_isp_t20_math.c | $(OUT)
	$(CC) $(ARCH) $(KFLAGS) -Os -w -std=gnu99 $(SDKINC) -include include/kshim.h -c -o $@ $<
$(OUT)/sdk_calinit.o: $(SDK)/apical-isp/apical_calibrations_init.c | $(OUT)
	$(CC) $(ARCH) -O1 -w -std=gnu99 -fpermissive $(SDKINC) -c -o $@ $<

$(OUT)/t20fw-%: $(OUT)/fw-%.o $(HOST_OBJS)
	$(CC) -m32 -nostdlib -static -no-pie -Wl,--build-id=none -o $@ $^

# symbol table with firmware-unit data objects flagged "F"
$(OUT)/t20fw-%.sym: $(OUT)/t20fw-% $(OUT)/fw-%.o
	nm --defined-only $(OUT)/fw-$*.o | awk '$$2 ~ /^[dDbBtT]$$/ {print $$3}' | sort -u > $@.fw
	nm -S -n --defined-only $< | awk 'NR==FNR {fw[$$1]=1; next} NF==4 {print $$0 ((($$3 ~ /^[dDbBtT]$$/) && ($$4 in fw)) ? " F" : "")}' $@.fw - > $@

SCENARIOS ?= simple oem ext ext-oem

check: all
	SCENARIOS="$(SCENARIOS)" ./compare.sh $(OUT) "$(CALIB)" $(REF) $(filter-out $(REF),$(VARIANTS))

# the register-poke scenario drives the vendor debug API (type 5 ids 0x7c..0x7f);
# it is not part of "check" because that path cannot be validated from the host
check-poke: SCENARIOS += poke poke-oem
check-poke: check

# which firmware functions the scenarios execute (coverage limit of check)
coverage: $(OUT)/t20fw-cov $(OUT)/t20fw-cov.sym
	setarch -R $(OUT)/t20fw-cov $(OUT)/t20fw-cov.sym "$(or $(CALIB),-)" cov > $(OUT)/cov-simple.txt
	setarch -R $(OUT)/t20fw-cov $(OUT)/t20fw-cov.sym "$(or $(CALIB),-)" cov oem > $(OUT)/cov-oem.txt
	setarch -R $(OUT)/t20fw-cov $(OUT)/t20fw-cov.sym "$(or $(CALIB),-)" cov ext > $(OUT)/cov-ext.txt
	cat $(OUT)/cov-simple.txt $(OUT)/cov-oem.txt $(OUT)/cov-ext.txt | awk '/^COV hit/ {h[$$3]=1} /^COV miss/ {m[$$3]=1} END {for (f in m) if (!(f in h)) n++; for (f in h) k++; printf "functions executed: %d, never executed: %d\n", k, n}'
	cat $(OUT)/cov-simple.txt $(OUT)/cov-oem.txt $(OUT)/cov-ext.txt | awk '/^COV hit/ {h[$$3]=1} /^COV miss/ {m[$$3]=1} END {for (f in m) if (!(f in h)) print f}' | sort > $(OUT)/cov-missed.txt

endif

# ------------------------------------------------------------------------
# vendor differential test: our firmware unit built for MIPS (same shims as
# the host build) next to the vendor tx-isp-t20.ko in a unicorn emulator.
# The vendor binary is never part of the tree: pass its path.
VENDOR_KO ?= $(T20FW_VENDOR_KO)
MIPS_CC ?= $(or $(T20FW_MIPS_CC),$(CROSS_COMPILE)gcc)
MIPS_LD ?= $(patsubst %gcc,%ld,$(MIPS_CC))
PYTHON ?= python3
VDIFF_VARIANT ?= O0
VDIFF_ARGS ?=
MIPS_FLAGS := -march=mips32 -mabi=32 -msoft-float -G 0 -mno-abicalls -fno-pic \
	-mno-check-zero-division -ffreestanding $(KFLAGS) -std=gnu99 -w
MIPS_OK := $(shell echo 'int x;' | $(MIPS_CC) $(MIPS_FLAGS) -x c -c -o /dev/null - 2>/dev/null && echo y)
UNICORN_OK := $(shell $(PYTHON) -c 'import unicorn' 2>/dev/null && echo y)
MIPS_INC = -nostdinc -Iinclude -isystem $(shell $(MIPS_CC) -print-file-name=include) \
	-I$(SDK) -I$(SDK)/apical-isp -I$(SDK)/include -I$(ROOT)/external/ingenic-sdk/include

$(OUT)/mips-fw-%.o: fw_unit.c pre.h $(ROOT)/driver/t20/tx_isp_t20_firmware.c | $(OUT)
	$(MIPS_CC) $(MIPS_FLAGS) $(MIPS_INC) -fpermissive -include pre.h $(FLAGS_$*) -c -o $@ fw_unit.c
$(OUT)/mips-math.o: $(ROOT)/driver/t20/tx_isp_t20_math.c | $(OUT)
	$(MIPS_CC) $(MIPS_FLAGS) $(MIPS_INC) -Os -include include/kshim.h -c -o $@ $<
$(OUT)/mips-ours-%.o: $(OUT)/mips-fw-%.o $(OUT)/mips-math.o
	$(MIPS_LD) -r -o $@ $^

vdiff:
ifeq ($(and $(VENDOR_KO),$(wildcard $(VENDOR_KO))),)
	@echo "t20_fw vdiff: set T20FW_VENDOR_KO=/path/to/vendor/tx-isp-t20.ko, skipping"
else ifneq ($(MIPS_OK),y)
	@echo "t20_fw vdiff: no MIPS compiler (T20FW_MIPS_CC / CROSS_COMPILE), skipping"
else ifneq ($(UNICORN_OK),y)
	@echo "t20_fw vdiff: $(PYTHON) lacks the unicorn module (pip install unicorn), skipping"
else
	$(MAKE) $(OUT)/mips-ours-$(VDIFF_VARIANT).o
	$(PYTHON) vdiff/vdiff.py $(VENDOR_KO) $(OUT)/mips-ours-$(VDIFF_VARIANT).o \
		$(if $(CALIB),--calib $(CALIB)) --sdk $(SDK) $(VDIFF_ARGS)
endif

clean:
	rm -rf $(OUT)
