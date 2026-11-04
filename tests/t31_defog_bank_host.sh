#!/bin/bash
# T31 defog tables from the active tuning bank (driver/t31/tx_isp_tuning.c, tiziano_defog_load_bank) vs the vendor
# tiziano_defog_params_refresh in Unicorn (tools/ko_emu/diff_t31_defog_bank.py).
# Always: static table checks (bounds, overlap, sizes) and a mutation that must be detected.
# Oracle part needs T31_OEM_KO (vendor tx-isp-t31.ko), T31_TUNING_BINS (dir with T31 sensor bins) and python3 unicorn, else SKIP.
HERE=$(cd "$(dirname "$0")" && pwd); SRC=$HERE/../driver/t31/tx_isp_tuning.c; PY=$HERE/../tools/ko_emu/diff_t31_defog_bank.py
python3 -I "$PY" - "$SRC" || { echo "t31_defog_bank_host: FAIL (static)"; exit 1; }
W=$(mktemp -d); trap 'rm -rf "$W"' EXIT
sed 's/DEFOG_BANK(defog_trsy0_list, 0x10b90)/DEFOG_BANK(defog_trsy0_list, 0x10b80)/' "$SRC" > "$W/m.c"
python3 -I "$PY" - "$W/m.c" >/dev/null && { echo "t31_defog_bank_host: FAIL (overlap mutation not detected)"; exit 1; }
KO=${T31_OEM_KO:-}; BD=${T31_TUNING_BINS:-}
if [ ! -r "$KO" ] || [ ! -d "$BD" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then
	echo "t31_defog_bank_host: SKIP (T31_OEM_KO / T31_TUNING_BINS / python3 unicorn+pyelftools missing; static checks ok)"
	[ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0
fi
python3 -I "$PY" "$KO" "$SRC" "$BD"/*.bin > "$W/o.txt" || { grep -v ": checked" "$W/o.txt" | tail; echo "t31_defog_bank_host: FAIL"; exit 1; }
tail -1 "$W/o.txt"
sed 's/DEFOG_BANK(defog_dark_l1_array, 0x10d60)/DEFOG_BANK(defog_dark_l1_array, 0x10d58)/' "$SRC" > "$W/m.c"
python3 -I "$PY" "$KO" "$W/m.c" "$BD"/sc2336.bin >/dev/null && { echo "t31_defog_bank_host: FAIL (offset mutation not detected)"; exit 1; }
echo "t31_defog_bank_host: ok (vendor == table for all bins, mutation detected)"
