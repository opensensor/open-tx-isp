# Unicorn oracles (T40)

Eight host checks compare our C code with the instructions of the vendor module under the Unicorn
emulator, or with translated vendor code:
`t40_ccm_conv_host t40_ccm_chain_host t40_dmsc_chain_host t40_mdns_chain_host t40_ysp_chain_host t40_ydns_host t40_gib_host t40_lsc_host`
(need `T40_OEM_KO`, and `T40_CC` for the chain ones), `t40_vct_host` (`T40_TUNING_BIN` + `T40_OEM_DATA`) and
`t40_bcsh_dn_host` (`T40_TUNING_BIN`, or the initialised `external/ingenic-sdk` submodule).

In a plain `make -C tests check` they print `SKIP` and exit 0 when the inputs are missing (the default flow
stays usable without vendor files). Such a SKIP counts as passed, so `check` ends with a line
`!!!! N oracles SKIPPED (...)` naming them. Do not read a green `check` as "oracles ran" when that line is there.

`make -C tests check-oracles` runs only the oracles with `T40_ORACLE_STRICT=1`: a SKIP is a failure.
Required before a merge that touches the T40 colour/denoise/GIB/LSC chains.

Inputs (vendor files are never part of the repository):

    export T40_OEM_KO=<tx-isp-t40.ko of a vendor firmware of the same ISP generation>
    export T40_CC=<mipsel-linux-gcc of any thingino toolchain>
    export T40_OEM_DATA=$(mktemp); objcopy -O binary --only-section=.data "$T40_OEM_KO" "$T40_OEM_DATA"
    export T40_TUNING_BIN=<a T40 sensor tuning bin, e.g. external/ingenic-sdk/sensor-iq/t40/gc2053.bin>
    python3 -m pip install unicorn pyelftools   # if missing
    make -C tests check-oracles

## Status of the two oracles that need more than the Eufy module (2026-11-03)

- `t40_vct_host` does not run with any vendor module we have. The lifted init code (`t40_vct/vct_init_gen.inc`) addresses the OEM `.data`
  at fixed offsets and the harness loads exactly 0x2e640 = 190016 bytes. The `.data` sections of the available vendor `tx-isp-t40.ko`
  builds are shorter: Eufy vendor firmware 189632 (0x2e4c0), Ingenic T40 SDK 1.3.1 images (extracted from the jffs2 appfs of
  `image_t40/*.img`) 189600 (T40XP) and 189616 (T40N). The offsets differ between builds, so a size-compatible substitute is not possible.
  The script now SKIPs (fails under `T40_ORACLE_STRICT=1`) with the size in the message instead of aborting with a read error.
  It runs only with the `.data` of the exact vendor build it was lifted from; that build is not in our archive.
- `t40_bcsh_dn_host` is not a mismatch: the strict run failed because the `external/ingenic-sdk` submodule is not initialised, so the
  default tuning bin is missing. With any T40 tuning bin it passes (0 words differ), e.g. the Ingenic T40 SDK `resource/sensor_settings_t40/gc2053-t40.bin`
  (also sc200ai, os08a10, gc4653: all PASS): `T40_TUNING_BIN=<bin> make -C tests t40_bcsh_dn_host`.
