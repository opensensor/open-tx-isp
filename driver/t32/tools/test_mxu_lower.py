#!/usr/bin/env python3
"""Exercise emitted scalar C against independent lane-level reference arithmetic."""
import ctypes,random,re,subprocess,tempfile
from pathlib import Path
from mxu_lower import emit

def signed(v,b): return v-(1<<b) if v>>(b-1) else v

def reference(op,args,raw,scalar):
 a=args.split(',');out=bytearray(raw);fmt=op[-1];bits={'b':8,'h':16,'w':32,'d':64}.get(fmt,32);n=bits//8;mask=(1<<bits)-1
 def vr(s):
  m=re.fullmatch(r'\$vr(\d+)(?:\[(\d+)\])?',s);return int(m[1]),int(m[2] or 0)
 def lane(s,i,bits=bits):
  reg,sel=vr(s);nn=bits//8;ix=sel if '[' in s else i
  return int.from_bytes(raw[reg*16+ix*nn:reg*16+(ix+1)*nn],'little')
 def store(s,i,val,bits=bits):
  reg,sel=vr(s);nn=bits//8;ix=sel if '[' in s else i
  out[reg*16+ix*nn:reg*16+(ix+1)*nn]=(val&((1<<bits)-1)).to_bytes(nn,'little')
 if op.startswith(('mtcpus','mtcpuu')):
  val=lane(a[1],0);return raw,(signed(val,bits) if op.startswith('mtcpus') else val)&0xffffffff
 if op.startswith('insfmxu'):
  store(a[0],0,lane(a[1],0));return bytes(out),scalar
 if op=='shufv':
  for i in range(16):
   sel=lane(a[3],i,8);j=(sel&31)//2
   store(a[0],i,0 if sel&128 else lane(a[1] if sel%2 else a[2],j,8),8)
  return bytes(out),scalar
 if op in ['bselv','andv','orv','xorv','norv']:bits=32;n=4;mask=0xffffffff
 stem=op[:-1]
 for i in range(16//n):
  if stem in ['li']:v=int(a[1],0)
  elif op.startswith('mfcpu'):v=0 if a[1]=='zero' else scalar
  elif op.startswith('repi'):v=lane(a[1],0)
  else:
   x=lane(a[1],i,bits);sx=signed(x,bits)
   if stem in ['ceqz','cnez','cltz']:v=mask if {'ceqz':x==0,'cnez':x!=0,'cltz':sx<0}[stem] else 0
   else:
    y=int(a[2],0) if stem.endswith('i') and op not in ['bselv'] else lane(a[2],i,bits);sy=signed(y&mask,bits)
    if stem=='add':v=x+y
    elif stem=='sub':v=x-y
    elif stem=='mul':v=x*y
    elif stem=='madd':v=lane(a[0],i,bits)+x*y
    elif stem=='msub':v=lane(a[0],i,bits)-x*y
    elif stem=='subua':v=abs(x-y)
    elif stem=='subsa':v=abs(sx-sy)
    elif stem=='adduu':v=min(mask,x+y)
    elif stem=='subuu':v=max(0,x-y)
    elif stem in ['addss','subss']:v=max(-(1<<(bits-1)),min((1<<(bits-1))-1,sx+sy if stem=='addss' else sx-sy))
    elif stem=='divu':v=x//y if y else mask
    elif stem in ['ceq','cltu','cleu','clts','cles']:v=mask if {'ceq':x==y,'cltu':x<y,'cleu':x<=y,'clts':sx<sy,'cles':sx<=sy}[stem] else 0
    elif stem.startswith(('sll','srl','sra')):
     sh=y%(bits);v=(x<<sh) if stem.startswith('sll') else ((sx if stem.startswith('sra') else x)>>sh)
     if stem in ['srar','srari','srlr','srlri'] and sh:v+=(x>>(sh-1))&1
    elif op=='andv':v=x&y
    elif op=='orv':v=x|y
    elif op=='xorv':v=x^y
    elif op=='norv':v=~(x|y)
    elif op=='bselv':m=lane(a[3],i,32);v=(x&~m)|(y&m)
    else:raise ValueError((op,args))
  store(a[0],i,v,bits)
 return bytes(out),scalar

def main():
 samples={}
 # ISA operations exercised in the T32 OEM, with destination aliasing tested below.
 for op in ['addh','addw','addssw','adduuh','adduuw','andv','orv','xorv','norv','ceqb','cleuh','cltsb','cltsh','cltsw','cltuh','cltuw','cleuw','divuw','maddw','mulh','mulw','sllw','sraw','srlw','srlrw','subh','subsah','subssb','subssw','subuub','subuuh','subuaw','subw']:samples[op]='$vr0,$vr1,$vr2'
 for op in ['ceqzh','cltzw','cnezh']:samples[op]='$vr0,$vr1'
 for op in ['slliw','sraih','sraiw','srarih','srariw','srlih','srliw']:samples[op]='$vr0,$vr1,7'
 for op in ['lib','lih','liw']:samples[op]='$vr0,-1'
 for op in ['mfcpuh','mfcpuw']:samples[op]='$vr0,a0'
 for op in ['mtcpush','mtcpusw','mtcpuuw']:samples[op]='a0,$vr1[2]'
 for op in ['repih','repiw','repid']:samples[op]='$vr0,$vr1[1]'
 samples.update(bselv='$vr0,$vr1,$vr2,$vr3',shufv='$vr0,$vr1,$vr2,$vr3',insfmxud='$vr0[1],$vr1[0]')
 cases=[(op,a.replace('$vr0',dst)) for op,a in samples.items() for dst in ['$vr0','$vr1','$vr2']]
 src='#include <stdint.h>\ntypedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef uint64_t u64; typedef int16_t s16; typedef int32_t s32; typedef int64_t s64;\nunion t32_vec {u8 b[16];u16 h[8];u32 w[4];u64 d[2];};\n'
 for j,(op,args) in enumerate(cases):src+=f'void test_{j}(union t32_vec *vx,u32 *cpu){{u32 a0=*cpu; '+emit(op,args)+' *cpu=a0;}\n'
 with tempfile.TemporaryDirectory() as tmp:
  path=Path(tmp);(path/'test.c').write_text(src);subprocess.run(['cc','-shared','-fPIC','-O2','-fsanitize=undefined','-fno-sanitize-recover=all',str(path/'test.c'),'-o',str(path/'test.so')],check=True)
  lib=ctypes.CDLL(str(path/'test.so'));rng=random.Random(32);count=0
  boundaries=[0,1,0x7f,0x80,0xff,0x7fff,0x8000,0xffff,0x7fffffff,0x80000000,0xffffffff]
  for j,(op,args) in enumerate(cases):
   for k in range(100):
    words=[rng.choice(boundaries) if k<50 else rng.getrandbits(32) for _ in range(128)];raw=b''.join(w.to_bytes(4,'little') for w in words);scalar=rng.getrandbits(32)
    if op=='shufv' and k==0:raw=raw[:48]+bytes([0,1,2,3,30,31,32,33,63,64,127,128,129,254,255,16])+raw[64:]
    expected,cpu=reference(op,args,raw,scalar);buf=ctypes.create_string_buffer(raw,len(raw));actual_cpu=ctypes.c_uint32(scalar)
    getattr(lib,f'test_{j}')(buf,ctypes.byref(actual_cpu));assert (buf.raw,actual_cpu.value)==(expected,cpu),(op,args,k)
    count+=1
 print(f'PASS: {len(samples)} MXU2 operations, {count} boundary/random/aliasing cases; UBSan enabled')
if __name__=='__main__':main()
