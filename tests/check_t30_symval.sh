#!/bin/sh
# check_t30_symval.sh [driver/t30]   (Lu-Fi/openimp#202)
# Source guards for the lift artefact "symbol address / label used as a value": a data symbol (plus offset) or a string
# label standing where the OEM has an immediate, or a local variable shadowing the global system table `stab`.
# Evidence per site: audit/t30/SYMVAL_SWEEP.md; executed oracle tools/ko_emu/diff_t30_symval.py (session tools).
d=${1:-$(dirname "$0")/../driver/t30}
f=$d/tx_isp_t30_recovered.c
[ -f "$f" ] || { echo "usage: $0 [driver/t30]" >&2; exit 2; }
fail=0
code=$(grep -v '^[[:space:]]*\(/\*\|\*\|//\)' "$f")
no() { echo "$code" | grep -Eq -- "$1" && { echo "check_t30_symval: forbidden: $2"; fail=1; }; }
no '&apical_downscaler_lut *\+' 'register 0x4xxxx expressed as &apical_downscaler_lut + N (OEM lui 0x4)'
no '&isp_kfifo_in *\+ *0x8dc' '&isp_kfifo_in + 0x8dc as a value (OEM lui 0x5 / leftover register)'
no 'APICAL_WRITE_32\(0x10, [^;]*&LC32' 'string label LC32 as the register 0x10 test pattern (OEM 0x1234)'
no 'i = \(uintptr_t\)&LC11; \(uintptr_t\)i != 0x1fe1' 'awb weight loop start as the address of string LC11 (OEM li 7936)'
no '&tx_isp_customer_parameter *\+' 'customer table pointer as an offset into a 4-byte object'
no '&cal_byte *\+' 'stab bytes read through the address of a 1-byte stack local (isp_info_show)'
no '^[[:space:]]+(u?int(8|32)_t) \*stab( =|;)' 'local variable shadowing the global system table stab'
no '\*\(uint8_t \*\)\(\(char \*\)\(\(char \*\)&(fsp_9008|csp_9009) ' 'sharpening state in a private static instead of stab[34..39]'
no '\*\(uint8_t \*\)\(\(char \*\)&csp_9009\)' 'sharpening state in a private static instead of stab[36]'
no '\*\(uint8_t \*\)\(uintptr_t\)&csp_9009' 'sharpening state in a private static instead of stab[36]'
no '\*\(uint8_t \*\)\(\(char \*\)\(\(char \*\)&_qlock1 \+ 0x3\)\)' 'stab[7] read as byte 3 of the unrelated static _qlock1'
echo "$code" | grep -q 'stab\[36\]' || { echo "check_t30_symval: missing: sharpening stab[36]"; fail=1; }
[ $fail = 0 ] && echo "check_t30_symval: ok"
exit $fail
