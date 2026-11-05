#!/usr/bin/env python3
"""Check checked-in mechanical C against the decoder and exact OEM input."""
import json
import lower_mips as lower

def main():
    manifest=json.loads((lower.dst/'recovery_manifest.json').read_text())
    checked=0
    for entry in manifest:
        if entry['implementation']!='decoded_instruction_C':
            continue
        path=lower.dst/entry['source']
        expected=lower.generate(int(entry['address'],16),False)
        assert path.read_text()==expected, f'generated source differs: {path.name}'
        checked+=1
    print(f'PASS: {checked} complete decoded function bodies reproduce exactly')

if __name__=='__main__':
    main()
