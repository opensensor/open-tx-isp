#!/usr/bin/env python3
"""Validate source inventory, OEM exports/parameters and kernel symbol resolution."""
import argparse,json,re
from pathlib import Path
from elftools.elf.elffile import ELFFile

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('module',type=Path)
    ap.add_argument('symvers',type=Path)
    args=ap.parse_args()
    root=Path(__file__).resolve().parents[1]
    metadata=json.loads((root/'recovery_input.json').read_text())
    manifest=json.loads((root/'recovery_manifest.json').read_text())
    expected={a for a,name,size in metadata['elf_functions']}
    assert {int(r['address'],16) for r in manifest}==expected
    assert len(manifest)==len(expected)
    sources={r['source'] for r in manifest}
    assert sources=={str(p.relative_to(root)) for p in (root/'recovered').glob('*.c')}
    kbuild=(root/'Kbuild').read_text()
    for source in sorted(sources):
        assert source[:-2]+'.o' in kbuild,source
        text=(root/source).read_text()
        # GNU asm symbol labels are declarations, not executable assembly.
        text=re.sub(r'__asm__\("[^"\n]*"\)', '', text)
        assert not re.search(r'\b(?:__asm__|asm)\s*(?:volatile\s*)?\(',text),source
    assert not list((root/'recovered').glob('*.S'))
    with args.module.open('rb') as stream:
        elf=ELFFile(stream)
        assert elf['e_machine']=='EM_MIPS'
        symbols=list(elf.get_section_by_name('.symtab').iter_symbols())
        imports={s.name for s in symbols if s.name and s['st_shndx']=='SHN_UNDEF'}
        kernel={line.split()[1] for line in args.symvers.read_text().splitlines() if line.strip()}
        assert not imports-kernel, sorted(imports-kernel)
        exports=set(elf.get_section_by_name('__ksymtab_strings').data().decode().split('\0'))-{''}
        required=set((root/'original_exports.txt').read_text().splitlines())
        assert required<=exports, sorted(required-exports)
        modinfo=elf.get_section_by_name('.modinfo').data().decode().split('\0')
        parameters={x[9:].split(':',1)[0]:x[9:].split(':',1)[1] for x in modinfo if x.startswith('parmtype=')}
        assert parameters==metadata['parameter_types'],parameters
        assert 'license=GPL' in modinfo
        assert any(x.startswith('vermagic=4.4.94 ') for x in modinfo),modinfo
        defined={s.name for s in symbols if s['st_shndx']!='SHN_UNDEF'}
        assert {'init_module','cleanup_module'}<=defined
    print(f'PASS: {len(sources)} C entry points, {len(required)} OEM exports, '
          f'{len(parameters)} module parameters, {len(imports)} resolved kernel imports')

if __name__=='__main__':
    main()
