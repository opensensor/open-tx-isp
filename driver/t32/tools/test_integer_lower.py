#!/usr/bin/env python3
"""Run emitted C for MIPS delay slots, atomics, argument frames and unaligned I/O.
The 32-bit freestanding host executable needs no multilib C library.
"""
import subprocess,tempfile
from pathlib import Path
import lower_mips as l

def lower(name,ins):
 base=0x20000000+len(l.funcs)*0x1000
 l.funcs[base]=name;l.real_sizes[base]=l.export_sizes[base]=len(ins)*4
 for i,(op,args) in enumerate(ins):
  if op.startswith('b'):args=args.rsplit(',',1)[0]+','+f'{base+int(args.rsplit(",",1)[1])*4:x}' if ',' in args else f'{base+int(args)*4:x}'
  l.full_ins[base+i*4]=(op,args)
 return l.generate(base,False).replace('#include "../compat.h"','')

def main():
 src='''typedef unsigned char u8; typedef signed char int8_t; typedef unsigned short u16; typedef short s16; typedef short int16_t; typedef unsigned int u32; typedef int s32; typedef unsigned long long u64; typedef long long s64;
#define __aligned(x) __attribute__((aligned(x)))
#define current_thread_info() ((void *)0)
#define READ_ONCE(x) (*(volatile u32 *)&(x))
#define cmpxchg(p,o,n) __sync_val_compare_and_swap(p,o,n)
#define BUG_ON(x) do {if(x)__builtin_trap();}while(0)
#define mb() __sync_synchronize()
'''
 src+=lower('delay',[('beqz','a0,5'),('li','a0,9'),('li','v0,1'),('jr','ra'),('addiu','v0,v0,1'),('li','v0,5'),('jr','ra'),('addiu','v0,v0,3')])
 src+=lower('likely',[('li','v0,10'),('beqzl','a0,5'),('addiu','v0,v0,100'),('jr','ra'),('nop',''),('jr','ra'),('addiu','v0,v0,7')])
 src+=lower('branch_to_delay',[('b','3'),('li','v0,10'),('b','6'),('addiu','v0,v0,1'),('jr','ra'),('addiu','v0,v0,2'),('jr','ra'),('addiu','v0,v0,50')])
 src+=lower('division',[('div','zero,a0,a1'),('mflo','v0'),('mfhi','v1'),('jr','ra'),('nop','')])
 src+=lower('load_unaligned',[('li','v0,0'),('lwl','v0,3(a0)'),('lwr','v0,0(a0)'),('jr','ra'),('nop','')])
 src+=lower('store_unaligned',[('swl','a1,3(a0)'),('swr','a1,0(a0)'),('jr','ra'),('nop','')])
 src+=lower('split_frame',[('addiu','sp,sp,-16'),('addiu','sp,sp,-32'),('lw','v0,64(sp)'),('addiu','sp,sp,32'),('jr','ra'),('addiu','sp,sp,16')])
 src+=lower('atomic_add',[('ll','v0,0(a0)'),('addiu','v0,v0,1'),('sc','v0,0(a0)'),('beqz','v0,0'),('nop',''),('lw','v0,0(a0)'),('jr','ra'),('nop','')])
 src+='''static int run(void) {
 u32 i,j,word=41; u8 bytes[12];
 if ((u32)delay(0,0,0,0)!=8 || (u32)delay(1,0,0,0)!=2) return 1;
 if ((u32)likely(0,0,0,0)!=117 || (u32)likely(1,0,0,0)!=10) return 2;
 if ((u32)branch_to_delay(0,0,0,0)!=13) return 3;
 if (division(0x80000000U,~0U,0,0)!=0x80000000ULL) return 4;
 if ((u32)division(-17,3,0,0)!=(u32)-5 || (u32)(division(-17,3,0,0)>>32)!=(u32)-2) return 5;
 for(i=0;i<4;i++) {
  for(j=0;j<12;j++)bytes[j]=j+1;
  if((u32)load_unaligned((u32)&bytes[i],0,0,0)!=((u32)(i+1)|((i+2)<<8)|((i+3)<<16)|((i+4)<<24)))return 6;
  store_unaligned((u32)&bytes[i],0x89abcdefU,0,0);
  for(j=0;j<12;j++)if(bytes[j]!=(j>=i&&j<i+4 ? (0x89abcdefU>>(8*(j-i)))&255 : j+1))return 7;
 }
 if((u32)split_frame(0,0,0,0,0x12345678)!=0x12345678)return 8;
 if((u32)atomic_add((u32)&word,0,0,0)!=42 || word!=42)return 9;
 return 0;
}
void _start(void) {int status=run(); __asm__ volatile("int $0x80"::"a"(1),"b"(status)); __builtin_unreachable();}
'''
 with tempfile.TemporaryDirectory() as d:
  p=Path(d);(p/'test.c').write_text(src)
  subprocess.run(['cc','-m32','-O2','-fno-pie','-no-pie','-fno-stack-protector','-nostdlib',str(p/'test.c'),'-o',str(p/'test')],check=True)
  r=subprocess.run([str(p/'test')]);assert r.returncode==0,('integer translation check',r.returncode)
 print('PASS: delay slots, branch-likely annulment, branch into delay slot, signed division edge cases, four unaligned load/store offsets, split stack frame, atomic counter')
if __name__=='__main__':main()
