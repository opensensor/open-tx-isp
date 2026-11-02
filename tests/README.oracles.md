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
