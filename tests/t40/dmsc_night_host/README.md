# T40 DMSC chain: host check

Runs `driver/t40/tx_isp_t40_dmsc.inc` (the plain-C chain tx_isp_t40_dmsc_chain.h) on an x86-64 host (heap and the worker stack live below 4 GiB because
the driver code keeps addresses in `uint32_t`). With only a bin it prints the main DMSC registers per bank and total
gain. With a register dump (32768 words from 0x13300000, as `devmem` prints them) it compares 0xa000..0xa27c.

    ./run.sh sc830ai-t40.bin                          # table: day/night bank x gain
    ./run.sh sc830ai-t40.bin dump.txt 1 458752        # night bank at total gain 7.0 log2

Result 2026-10-24 (vendor .184 night dump, dark scene, 32x sensor x 4x ISP gain): 5 of 160 words differ, all of
them status/trigger words 0xa18c..0xa19c. Everything else is bit-exact.

Result 2026-10-25 (vendor .184 day dump `vab2/vendor/isp_regs_day.txt`, day bank at the vendor TotalGainDb 75639):
5 of 160 words differ, again only 0xa18c..0xa19c. This needed the OEM rounding in `tisp_simple_intp_int8` (bit 15 of
the product); with the old truncating helper 10 further words were one interpolation step off.

    ./run.sh sc830ai-t40.bin isp_regs_day.txt 0 75639
