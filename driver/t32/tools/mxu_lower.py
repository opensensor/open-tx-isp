"""Scalar C semantics for MXU2 integer operations (Ingenic manual, June 2017)."""
import re

def emit(op,args):
 a=args.split(',')
 def vec(s):
  m=re.fullmatch(r'\$vr(\d+)(?:\[(\d+)\])?',s); assert m,s
  return 'vx['+m[1]+']',m[2]
 def v(s):return vec(s)[0]
 def lane(s,fmt='w',ix='i'):
  reg,idx=vec(s);return f'{reg}.{fmt}[{idx or ix}]'
 def loop(fmt,expr):return '{ union t32_vec tmp; unsigned int i; for (i = 0; i < '+str({'b':16,'h':8,'w':4,'d':2}[fmt])+'; i++) tmp.'+fmt+'[i] = '+expr+'; '+v(a[0])+' = tmp; }'
 if op in ['lu1q','su1q','lu1qx','su1qx','la1q','sa1q']:
  m=re.fullmatch(r'(-?\w+)\((\w+)\)',a[1]);assert m,args
  off,base=m.groups();addr=f'({base} + ({off}))'
  ptr=f'(volatile u8 *)(unsigned long){addr}'
  if op[0]=='l':return '{ unsigned int i; for (i = 0; i < 16; i++) '+v(a[0])+'.b[i] = ('+ptr+')[i]; }'
  return '{ unsigned int i; for (i = 0; i < 16; i++) ('+ptr+')[i] = '+v(a[0])+'.b[i]; }'
 if op in ['andv','orv','xorv','norv']:
  x,y=lane(a[1]),lane(a[2]);expr={'andv':f'{x} & {y}','orv':f'{x} | {y}','xorv':f'{x} ^ {y}','norv':f'~({x} | {y})'}[op]
  return loop('w',expr)
 if op=='bselv':return loop('w',f'({lane(a[1])} & ~{lane(a[3])}) | ({lane(a[2])} & {lane(a[3])})')
 if op=='shufv':
  return '{ union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = '+v(a[3])+'.b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? '+v(a[1])+'.b[(sel & 31) >> 1] : '+v(a[2])+'.b[(sel & 31) >> 1]); } '+v(a[0])+' = tmp; }'
 if op.startswith('li') and op[-1] in 'bhwd' and op[2:]==op[-1]:return loop(op[-1],str(int(a[1],0)))
 if op.startswith('mfcpu'):
  return loop(op[-1],'0' if a[1]=='zero' else a[1])
 if op.startswith(('mtcpus','mtcpuu')):
  fmt=op[-1];typ={'b':'int8_t','h':'s16','w':'s32'}[fmt] if op.startswith('mtcpus') else {'b':'u8','h':'u16','w':'u32'}[fmt]
  return f'{a[0]} = ({typ}){lane(a[1],fmt)};'
 if op.startswith('repi'):return loop(op[-1],lane(a[1],op[-1]))
 if op.startswith('insfmxu'):return lane(a[0],op[-1])+' = '+lane(a[1],op[-1])+';'
 fmt=op[-1];stem=op[:-1]
 if fmt in 'bhw':
  bits={'b':8,'h':16,'w':32}[fmt];st='int8_t' if bits==8 else f's{bits}'
  x=lane(a[1],fmt);sx=f'({st}){x}'
  if stem in ['ceqz','cnez','cltz']:
   return loop(fmt,f'({sx} '+{'ceqz':'==','cnez':'!=','cltz':'<'}[stem]+' 0) ? ~0U : 0')
  if len(a)>2:
   y=a[2] if stem.endswith('i') else lane(a[2],fmt);sy=f'({st}){y}'
   if stem in ['clts','cles']:return loop(fmt,f'({sx} '+(' < ' if stem=='clts' else ' <= ')+f'{sy}) ? ~0U : 0')
   if stem in ['subss','addss']:
    expr=f'(s64){sx} '+('-' if stem=='subss' else '+')+f' (s64){sy}';lo=-(1<<(bits-1));hi=(1<<(bits-1))-1
    return loop(fmt,f'({expr}) < ({lo}LL) ? ({lo}LL) : (({expr}) > {hi}LL ? {hi}LL : ({expr}))')
   if stem=='subsa':return loop(fmt,f'{sx} > {sy} ? (s64){sx} - (s64){sy} : (s64){sy} - (s64){sx}')
   if stem=='subuu':return loop(fmt,f'{x} > {y} ? {x} - {y} : 0')
   if stem=='adduu':
    expr=f'(u64){x} + {y}';mx=(1<<bits)-1
    return loop(fmt,f'({expr}) > {mx}ULL ? {mx}ULL : ({expr})')
   if stem=='divu':return loop(fmt,f'{y} ? {x} / {y} : ~0U')
   if stem in ['srar','srari','srlr','srlri']:
    shift=f'({y} & {bits-1})';val=f'(s64){sx}' if stem.startswith('sra') else f'(u64){x}'
    return loop(fmt,f'({val} >> {shift}) + ({shift} ? (({x} >> (({shift} - 1) & {bits-1})) & 1) : 0)')
 if fmt in 'bhwd' and stem in ['add','sub','subua','mul','madd','msub','cltu','cleu','ceq','sll','srl','sra','slli','srli','srai']:
  x=lane(a[1],fmt);y=a[2] if stem.endswith('i') else lane(a[2],fmt);bits={'b':8,'h':16,'w':32,'d':64}[fmt]
  # Force unsigned multiplication: narrow unsigned operands otherwise promote to signed int.
  if stem=='add':expr=f'(u{bits}){x} + (u{bits}){y}'
  elif stem=='sub':expr=f'(u{bits}){x} - (u{bits}){y}'
  elif stem=='subua':expr=f'{x} > {y} ? {x} - {y} : {y} - {x}'
  elif stem in ['mul','madd','msub']:
   prod=f'(u{max(32,bits)}){x} * (u{max(32,bits)}){y}'
   expr=prod if stem=='mul' else f'{lane(a[0],fmt)} '+('+' if stem=='madd' else '-')+' ('+prod+')'
  elif stem in ['cltu','cleu','ceq']:expr=f'({x} '+{'cltu':'<','cleu':'<=','ceq':'=='}[stem]+f' {y}) ? ~0U : 0'
  else:
   expr=(f'(s{bits})' if stem.startswith('sra') else f'(u{max(32,bits)})')+x+(' << ' if stem.startswith('sll') else ' >> ')+f'({y} & {bits-1})'
  return loop(fmt,expr)
 raise ValueError(('unsupported MXU2',op,args))
