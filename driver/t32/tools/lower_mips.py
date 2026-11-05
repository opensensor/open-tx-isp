"""Lower integer MIPS control flow to explicit C, retaining branch delay slots.
Used only for candidates truncated by the model, not to embed executable bytes.
"""
from pathlib import Path
import sys, subprocess
from elftools.elf.elffile import ELFFile
import re,json
from mxu_lower import emit as emit_mxu
def is_branch(op): return op in ["b", "beq", "bne", "beqz", "bnez", "bgez", "bltz", "bgtz", "blez", "beql", "bnel", "beqzl", "bnezl", "bgezl", "bltzl", "bgtzl", "blezl"]
import argparse,hashlib,os
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('--oem-module',type=Path,default=os.environ.get('T32_OEM_MODULE'))
parser.add_argument('--objdump',default=os.environ.get('OBJDUMP','mipsel-linux-objdump'))
parser.add_argument('--metadata',type=Path,default=Path(__file__).resolve().parents[1]/'recovery_input.json')
parser.add_argument('--output-dir',type=Path,default=Path(__file__).resolve().parents[1])
parser.add_argument('addresses',nargs='*',help='hexadecimal OEM function addresses to regenerate')
args=parser.parse_args() if __name__=='__main__' else parser.parse_args([])
if args.oem_module is None:parser.error('set T32_OEM_MODULE or pass --oem-module')
oem_path=Path(args.oem_module);dst=args.output_dir
exp=json.loads(args.metadata.read_text())
if hashlib.sha256(oem_path.read_bytes()).hexdigest()!=exp['oem_sha256']:raise ValueError('OEM module hash does not match metadata')
funcs={f['address']:re.sub(r'\W','_',f['name']) for f in exp['functions']}
sections={s['name']:s['address'] for s in exp['sections']}
with oem_path.open('rb') as f:
 elf=ELFFile(f); symtab=elf.get_section_by_name('.symtab'); exact_relocs={}
 for sec in elf.iter_sections():
  if sec['sh_type']=='SHT_REL':
   base=sections.get(elf.get_section(sec['sh_info']).name)
   if base is not None:
    for r in sec.iter_relocations():exact_relocs[base+r['r_offset']]=symtab.get_symbol(r['r_info_sym']).entry
 syms={s.name:s.entry for s in elf.get_section_by_name('.symtab').iter_symbols()}; secnames={i:s.name for i,s in enumerate(elf.iter_sections())}

full_asm=subprocess.check_output([args.objdump, '-dr', '-M', 'mxu2', str(oem_path)],text=True)
full_ins={}; full_rel={}; current_base=0
for line in full_asm.splitlines():
 m=re.match(r'Disassembly of section (.*):',line)
 if m:current_base=sections.get(m[1],0)
 m=re.match(r'\s*([0-9a-f]+):\s+[0-9a-f]{8}\s+(\.?\w+)\s*(.*)',line)
 if m:
  pc=int(m[1],16)+current_base; op=m[2]; args=m[3].split(' <')[0]
  if (is_branch(op) or op in ['j','jal']) and op not in ['break','bitswap']:
   fields=args.split(',');fields[-1]=f'{int(fields[-1],16)+current_base:x}';args=','.join(fields)
  full_ins[pc]=(op,args)
 m=re.match(r'\s*([0-9a-f]+):\s+(R_MIPS_\w+)\s+(\S+)',line)
 if m:full_rel[int(m[1],16)+current_base]=(m[2],m[3])
jump_targets=set()
with oem_path.open('rb') as stream:
 e=ELFFile(stream);t=e.get_section_by_name('.symtab')
 for sec in e.iter_sections():
  if sec['sh_type']!='SHT_REL':continue
  data=e.get_section(sec['sh_info']).data()
  for rr in sec.iter_relocations():
   sy=t.get_symbol(rr['r_info_sym'])
   if rr['r_info_type']==2 and isinstance(sy['st_shndx'],int) and 'text' in e.get_section(sy['st_shndx']).name:
    val=int.from_bytes(data[rr['r_offset']:rr['r_offset']+4],'little')+sy['st_value']+sections[e.get_section(sy['st_shndx']).name]
    jump_targets.add(val)
real_sizes={a:size for a,name,size in exp['elf_functions']}
export_sizes={f['address']:f['size'] for f in exp['functions']}

def generate(addr, write=True):
 name=funcs[addr]; name += ('_'+f'{addr:x}') if name in ['tx_isp_enable_irq','tx_isp_disable_irq'] else ''; size=real_sizes.get(addr,export_sizes[addr])
 ins={pc:v for pc,v in full_ins.items() if addr<=pc<addr+size}
 rel={pc:v for pc,v in full_rel.items() if addr<=pc<addr+size}
 assert len(ins)*4==size,(name,'missing decoded instruction',len(ins)*4,size)
 refs={}; pairs={};pend={}
 def ref(sym,add,pc):
  symbol=exact_relocs.get(pc)
  if symbol is not None and isinstance(symbol['st_shndx'],int):
   sym=secnames[symbol['st_shndx']]; add+=symbol['st_value']
  if sym in sections:
   va=sections[sym]+add
   if 'text' in sym:
    if va in ins and va!=addr:return f'0x{va:x}U'
    assert va in funcs,(name,sym,hex(add),'non-entry text reference')
    target=funcs[va]
    if target in ['tx_isp_enable_irq','tx_isp_disable_irq']:target+='_'+f'{va:x}'
   else:target='__this_module' if sym=='.gnu.linkonce.this_module' else 't32_data_'+f'{va:x}'
  else:
   ent=syms.get(sym)
   if ent and isinstance(ent['st_shndx'],int):
    sec=secnames[ent['st_shndx']]
    if ent['st_info']['type']=='STT_FUNC':target=funcs[sections[sec]+ent['st_value']+add]
    else:target='t32_data_'+f'{sections[sec]+ent["st_value"]+add:x}'
   else:
    target='t32_small_bss' if sym=='.sbss' else sym
  ident='ref_'+re.sub(r'\W','_',target)
  refs[ident]=target
  return f'((u32)(unsigned long){ident} + ({add}))' if sym not in sections and syms.get(sym,{}).get('st_shndx')=='SHN_UNDEF' else f'(u32)(unsigned long){ident}'
 for pc,(kind,sym) in rel.items():
  if kind!='R_MIPS_LO16':continue
  op,args=ins[pc];v=args.split(',')[-1].split('(')[0];low=int(v,0)
  base=args.split(',')[1] if op=='addiu' else re.search(r'\((\w+)\)',args).group(1)
  choices=[p for p,(k,ss) in rel.items() if k=='R_MIPS_HI16' and ss==sym and ins[p][1].split(',')[0]==base]
  if not choices:choices=[p for p,(k,ss) in rel.items() if k=='R_MIPS_HI16' and ss==sym]
  prior=[p for p in choices if p<pc];hi=max(prior) if prior else min(choices)
  add=(int(ins[hi][1].split(',')[-1],0)<<16)+low
  val=ref(sym,add,pc);pairs.setdefault(hi,(val,hi));pairs[pc]=(val,hi)
 # A high relocation can be moved before its low instruction; never silently leave it raw.
 for hi,(kind,sym) in rel.items():
  if kind!='R_MIPS_HI16' or hi in pairs:continue
  lows=[pc for pc,(k,ss) in rel.items() if k=='R_MIPS_LO16' and ss==sym and pc>hi]
  if not lows:lows=[pc for pc,(k,ss) in rel.items() if k=='R_MIPS_LO16' and ss==sym]
  assert lows,(name,hex(hi),'unpaired high relocation')
  pc=min(lows);low=int(ins[pc][1].split(',')[-1].split('(')[0],0)
  val=ref(sym,(int(ins[hi][1].split(',')[-1],0)<<16)+low,pc);pairs[hi]=(val,hi)
 regs=['at','v0','v1','a0','a1','a2','a3','t0','t1','t2','t3','t4','t5','t6','t7','s0','s1','s2','s3','s4','s5','s6','s7','t8','t9','gp','sp','s8','ra']
 def r(x):return '0' if x=='zero' else x
 def mem(x,pc):
  m=re.fullmatch(r'(-?\d+)\((\w+)\)',x);assert m,(pc,x)
  off,base=m.groups()
  if pc in pairs:
   val,hi=pairs[pc];return f'({r(base)} - hi_{hi:x} + {val})'
  return f'({r(base)} + ({off}))'
 def stmt(pc):
  op,ar=ins[pc]
  if '$vr' in ar:return emit_mxu(op,ar)
  a=[r(x) for x in ar.split(',')];d=a[0]
  if op=='nop':return ';'
  if op=='sync':return 'mb();'
  if op=='ll':return f'll_addr = {mem(a[1],pc)}; ll_value = READ_ONCE(*(u32 *)(unsigned long)ll_addr); {d} = ll_value;'
  if op=='sc':
   assert ins[pc-8][0]=='ll' and ins[pc-4][0]=='addiu',(name,pc,'unsupported LL/SC sequence')
   return f'{d} = cmpxchg((u32 *)(unsigned long)ll_addr, ll_value, {d}) == ll_value;'
  if op=='wsbh':return f'{d} = (({a[1]} & 0xff00ffU) << 8) | (({a[1]} >> 8) & 0xff00ffU);'
  if op in ['lwl','lwr','swl','swr']:
   loc=mem(a[1],pc);align=f'({loc} & ~3U)';n=f'({loc} & 3U)';word=f'*(volatile u32 *)(unsigned long){align}'
   if op=='lwl':return f'{d} = ({d} & (0x00ffffffU >> (8 * {n}))) | ({word} << (24 - 8 * {n}));'
   if op=='lwr':return f'{d} = ({d} & (0xffffff00U << (24 - 8 * {n}))) | ({word} >> (8 * {n}));'
   if op=='swl':return f'{word} = ({word} & (0xffffff00U << (8 * {n}))) | ({d} >> (24 - 8 * {n}));'
   return f'{word} = ({word} & (0x00ffffffU >> (24 - 8 * {n}))) | ({d} << (8 * {n}));'
  if op in ['negu','neg']:return f'{d} = -{a[1]};'
  if op=='not':return f'{d} = ~{a[1]};'
  if op=='nor':return f'{d} = ~({a[1]} | {a[2]});'
  if op=='clz':return f'{d} = {a[1]} ? __builtin_clz({a[1]}) : 32;'
  if op=='ins':return f'{d} = ({d} & ~(((1U << {a[3]}) - 1) << {a[2]})) | (({a[1]} & ((1U << {a[3]}) - 1)) << {a[2]});'
  if op in ['mthi','mtlo']:return f'{"hi" if op=="mthi" else "lo"} = {d};'
  if op=='teq':return f'BUG_ON({a[0]} == {a[1]});'
  if op=='lui':
   if pc in pairs:return f'{d} = hi_{pc:x};'
   return f'{d} = {a[1]}U << 16;'
  if op in ['lw','lh','lhu','lb','lbu','sw','sh','sb']:
   ty={'lw':'u32','lh':'s16','lhu':'u16','lb':'int8_t','lbu':'u8','sw':'u32','sh':'u16','sb':'u8'}[op];p=f'*(volatile {ty} *)(unsigned long){mem(a[1],pc)}'
   return f'{d} = {p};' if op[0]=='l' else f'{p} = {d};'
  if op=='move' or op=='li':return f'{d} = {a[1]};'
  if op in ['addiu','addu','subu','and','andi','or','ori','xor','xori','sll','sllv','srl','srlv','sra','srav','mul']:
   oper={'addiu':'+','addu':'+','subu':'-','and':'&','andi':'&','or':'|','ori':'|','xor':'^','xori':'^','sll':'<<','sllv':'<<','srl':'>>','srlv':'>>','sra':'>>','srav':'>>','mul':'*'}[op]
   x,y=a[1:]
   if pc in pairs:
    val,hi=pairs[pc];return f'{d} = {x} - hi_{hi:x} + {val};'
   if op.startswith('sr') and op[2]=='a':x=f'(s32){x}'
   if '<<'==oper or '>>'==oper:y=f'({y} & 31)'
   return f'{d} = {x} {oper} {y};'
  if op in ['slt','slti','sltu','sltiu']:
   ty='u32' if op.endswith('u') else 's32';return f'{d} = ({ty}){a[1]} < ({ty})({a[2]});'
  if op in ['movn','movz']:return f'if ({a[2]} {"!=" if op=="movn" else "=="} 0) {d} = {a[1]};'
  if op in ['seh','seb']:return f'{d} = (int{16 if op=="seh" else 8}_t){a[1]};'
  if op=='ext':return f'{d} = ({a[1]} >> {a[2]}) & ((1U << {a[3]}) - 1);'
  if op in ['div','divu']:
   x,y=a[-2:];ty='s32' if op=='div' else 'u32'
   # MIPS division overflow is defined in hardware, unlike signed C division.
   if op=='div':return f'if ({x} == 0x80000000U && {y} == ~0U) {{ lo = 0x80000000U; hi = 0; }} else if ({y}) {{ lo = (s32){x} / (s32){y}; hi = (s32){x} % (s32){y}; }} else {{ lo = (s32){x} < 0 ? 1 : ~0U; hi = {x}; }}'
   return f'if ({y}) {{ lo = {x} / {y}; hi = {x} % {y}; }} else {{ lo = ~0U; hi = {x}; }}'
  if op in ['mflo','mfhi']:return f'{d} = {"lo" if op=="mflo" else "hi"};'
  if op in ['mult','multu','madd','maddu','msub','msubu']:
   ty='s32' if op in ['mult','madd','msub'] else 'u32';t64='s64' if ty=='s32' else 'u64'
   expr=f'({t64})({ty}){a[0]} * ({ty}){a[1]}'
   if op.startswith('msub'):expr=f'(((u64)hi << 32) | lo) - ({expr})'
   if op.startswith('madd'):expr=f'(((u64)hi << 32) | lo) + ({expr})'
   return f'product = {expr}; lo = product; hi = product >> 32;'
  raise ValueError((name,hex(pc),op,ar))
 targets={v for v in jump_targets if v in ins}; lines=[]
 for pc,(op,ar) in ins.items():
  a=[r(x) for x in ar.split(',')]
  if is_branch(op):
   target=int(a[-1],16);targets.add(target)
   if op=='b':cond='1'
   elif op.startswith('beqz'):cond=f'{a[0]} == 0'
   elif op.startswith('bnez'):cond=f'{a[0]} != 0'
   elif op.startswith('beq'):cond=f'{a[0]} == {a[1]}'
   elif op.startswith('bne'):cond=f'{a[0]} != {a[1]}'
   elif op.startswith('bgez'):cond=f'(s32){a[0]} >= 0'
   elif op.startswith('bltz'):cond=f'(s32){a[0]} < 0'
   elif op.startswith('bgtz'):cond=f'(s32){a[0]} > 0'
   elif op.startswith('blez'):cond=f'(s32){a[0]} <= 0'
   else:raise ValueError(op)
   delay=stmt(pc+4)
   if op=='b':
    s=delay+f' goto L_{target:x};'
    lines.append((pc,s));continue
   if op.endswith('l'):s=f'if ({cond}) {{ {delay} goto L_{target:x}; }}\n    goto L_{pc+8:x};'
   else:s=f'branch = ({cond}); {delay}\n    if (branch) goto L_{target:x};\n    goto L_{pc+8:x};'
   targets.add(pc+8)
  elif op=='jalr':
   # Capture call target and execute the delay slot before the C call.
   s=f'callee = {a[-1]}; {stmt(pc+4)}\n    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, '+', '.join(f'*(u32 *)(unsigned long)(sp + {i})' for i in range(16,256,4))+f');\n    v0 = result; v1 = result >> 32;\n    goto L_{pc+8:x};';targets.add(pc+8)
  elif op=='jr':
   if a==['ra']:s=stmt(pc+4)+'\n    return ((u64)v1 << 32) | v0;'
   else:
    dispatch='\n    switch (callee) { '+''.join(f'case 0x{v:x}: goto L_{v:x}; ' for v in sorted(jump_targets) if v in ins)+'default: break; }\n'
    s=f'callee = {a[-1]}; '+stmt(pc+4)+dispatch+'\n    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, '+', '.join(f'*(u32 *)(unsigned long)(sp + {i})' for i in range(16,256,4))+');'
  else:s=stmt(pc)
  lines.append((pc,s))
 frame=0
 for op,args in ins.values():
  if op=='addiu' and args.startswith('sp,sp,-'):frame+=-int(args.split(',')[-1],0)
 nargs=4
 for pc,(op,args) in ins.items():
  m=re.search(r',([0-9]+)\(sp\)',args)
  if m and op.startswith('l') and int(m[1])>=frame+16:nargs=max(nargs,(int(m[1])-frame)//4+1)
 assert nargs<=64,(name,'too many incoming arguments',nargs)
 header='/* Mechanical C translation of decoded MIPS/MXU2 instructions.\n * Control flow and delay slots are explicit; runtime equivalence is unverified.\n * No executable OEM bytes or assembly implementation are linked. */\n#include "../compat.h"\n'
 for ident,target in refs.items():header+=f'extern unsigned char {ident}[] __asm__("{target}");\n'
 has_mxu=any('$vr' in ar for op,ar in ins.values())
 if has_mxu:header+='union t32_vec { u8 b[16]; u16 h[8]; u32 w[4]; u64 d[2]; };\n'
 header+=f'u64 {name}(u32 a0, u32 a1, u32 a2, u32 a3{''.join(', u32 arg'+str(i) for i in range(4,nargs))})\n{{\n    u32 stack[{frame//4+64}] __aligned(16) = {{0}};\n    u32 '+', '.join(r+(' = (u32)(unsigned long)current_thread_info()' if r=='gp' else ' = 0') for r in regs if r not in ['a0','a1','a2','a3'])+';\n    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;\n    u64 result, product;\n    int branch;\n'
 if has_mxu:header+='    union t32_vec vx[32];\n'
 for pc,(val,_) in pairs.items():
  if rel[pc][0]=='R_MIPS_HI16':header+=f'    const u32 hi_{pc:x} = ({val} + 0x8000U) & 0xffff0000U;\n'
 header+=f'    sp = (u32)(unsigned long)&stack[{frame//4}];\n'
 for i in range(4,nargs):header+=f'    stack[{frame//4+i}] = arg{i};\n'
 assert targets.issubset(ins),(name,'out-of-function branch',sorted(targets-set(ins)))
 for pc,s in lines:
  if pc in targets:header+=f'L_{pc:x}:\n'
  # Delay slots are emitted by their branch, except branch-to-delay-slot entries.
  if pc-4 in ins and (is_branch(ins[pc-4][0]) or ins[pc-4][0] in ['jalr','jr']) and pc not in targets:continue
  header+='    '+s+'\n'
 header+='}\n'
 if write:
  path=next((dst/'recovered').glob('fn_'+f'{addr:016x}'+'_*.c'));path.write_text(header)
 if write:print(name,len(lines),'instructions',len(refs),'references')
 return header
if __name__=='__main__':
 for arg in args.addresses:generate(int(arg,16))
