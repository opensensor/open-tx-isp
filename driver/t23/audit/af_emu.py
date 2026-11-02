#!/usr/bin/env python3
"""Emulator check: the T23 AF chain (shared driver/t31/tx_isp_t31_af.h data
handling) against the stock tx-isp-t23.ko.

usage: af_emu.py <stock tx-isp-t23.ko>

Runs, with random IQ AF parameters and statistics, the stock
tiziano_af_init (register words 0xb800..0xb8a4), af_interrupt_static (the
unpacked arrays, zone focus values, weighted means, frame number), the
control 0x8000042 set/get, and compares every value with the C helpers
(built here with gcc from the header).  The stock tisp_af_get_attr leaves
the bytes it does not write as stack leftovers; the emulator stack is zero
so they compare as 0.  Prints "bad 0" per check when identical.
"""
import os, sys, struct, subprocess, tempfile, random
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
from memu import Mod, CPU
STOCK = sys.argv[1]
INC = os.path.join(HERE, '..', '..', 't31', 'tx_isp_t31_af.h')
TMP = tempfile.mkdtemp()
os.chdir(TMP)
def build(name, src):
    open(name + '.c', 'w').write(src.replace('@INC@', INC))
    subprocess.check_call(['gcc', '-O1', '-o', name, name + '.c'])
build('hw_c', '#include <stdio.h>\n#include <stdlib.h>\n#include "@INC@"\nint main(int argc,char**argv){\n  static struct t31_af_params p; uint32_t w=atoi(argv[2]),h=atoi(argv[3]); int first=atoi(argv[4]);\n  FILE*f=fopen(argv[1],"rb"); fread(&p,1,sizeof p,f); fclose(f);\n  uint32_t r[T31_AF_REGS_MAX][2];\n  t31_af_zone_layout(&p,w,h);\n  unsigned n=t31_af_hw_regs(&p,first,r);\n  for(unsigned i=0;i<n;i++) printf("%x %x\\n",r[i][0],r[i][1]);\n}\n')
bad=0
for seed in range(40):
    random.seed(seed)
    m=Mod(STOCK); c=CPU(m)
    for n in ('system_irq_func_set','private_spin_lock_init','__private_spin_lock_irqsave','private_spin_unlock_irqrestore'): c.hook(n,lambda cc,R:0)
    blob=bytearray()
    zone=[random.randrange(0,16) for _ in range(36)]
    zone[1]=random.randrange(5,16); zone[3]=random.randrange(5,16)
    words=zone+[random.randrange(0,2) for _ in range(13)]
    # rest: random small values
    rest=[random.randrange(0,0x400) for _ in range(0x260//4-len(words))]
    words+=rest
    blob=struct.pack('<%dI'%len(words),*words)+struct.pack('<225I',*[random.randrange(0,9) for _ in range(225)])
    assert len(blob)==0x260+900
    c.wrbytes(m.addr('tparams')+0x27c74,blob)
    h=random.choice([720,1080,1296]);w=random.choice([1280,1920,2304])
    c.writes.clear()
    c.call('tiziano_af_init',(h,w))
    open('p.bin','wb').write(blob)
    # tparams copies; ldg/etc. same layout
    ref=subprocess.check_output(['./hw_c','p.bin',str(w),str(h),'1']).decode().split('\n')[:-1]
    got=['%x %x'%(a,b) for a,b in c.writes if a!=0xb800]
    nb=[b for a,b in c.writes if a==0xb800]
    assert nb==[1],nb
    wi=[a for a,b in c.writes].index(0xb800); assert c.writes[wi+1][0]==0xb828
    # emulator also writes 0xb800 before 0xb828 maybe
    if got!=ref:
        bad+=1
        if bad<3:
            print('seed',seed,len(got),len(ref))
            for a,b in zip(got,ref):
                if a!=b: print(' got',a,' ref',b); break
            print(got[:3],ref[:3])
print('hw regs: bad',bad)

build('isr_c', '#include <stdio.h>\n#include <stdlib.h>\n#include "@INC@"\nint main(int argc,char**argv){\n  static struct t31_af_params p; static struct t31_af_stats st; static struct t31_af_result res; static uint32_t last[225];\n  FILE*f=fopen(argv[1],"rb"); if(fread(&p,1,sizeof p,f)!=sizeof p) return 1; fclose(f);\n  int nf=atoi(argv[2]);\n  for(int k=0;k<nf;k++){\n    static uint32_t buf[1024]; f=fopen(argv[3+k],"rb"); if(fread(buf,1,4096,f)!=4096) return 1; fclose(f);\n    t31_af_unpack(buf,t31_af_rows(&p),t31_af_cols(&p),&st);\n    t31_af_fv_run(&p,&st,&res);\n    memcpy(last,res.fv_value,sizeof last);\n  }\n  for(int i=0;i<225;i++) printf("%u ",last[i]); printf("\\n");\n  printf("%u %u %u %u\\n",p.fv[0],p.fv[1],p.fv[2],res.fv_alt);\n  for(int i=0;i<15;i++) printf("%u ",p.fv_wmean[i]); printf("\\n%u\\n",st.frame_num);\n  for(int i=0;i<225;i++) printf("%u %u %u %u %u %u\\n",st.fird0[i],st.fird1[i],st.iird0[i],st.iird1[i],st.y_sum[i],st.high_luma[i]);\n}\n')
bad=0
for seed in range(30):
    random.seed(1000+seed)
    m=Mod(STOCK); c=CPU(m)
    for n in ('system_irq_func_set','private_spin_lock_init','__private_spin_lock_irqsave','private_spin_unlock_irqrestore','private_dma_cache_sync'): c.hook(n,lambda cc,R:0)
    zone=[random.randrange(0,16) for _ in range(36)]
    zone[1]=random.randrange(5,16); zone[3]=random.randrange(5,16)
    words=zone+[random.randrange(0,2) for _ in range(13)]
    words+= [random.randrange(0,0x400) for _ in range(0x260//4-len(words))]
    # tilt: [t0 t1 t2 t3 q]
    toff=(36+13+5+8+4+5+8+4+10+8+4+10+8+4+2)  # index of tilt in words
    q=random.choice([6,8,10,12]); one=1<<q
    words[toff:toff+5]=[random.randrange(0,one+1),random.randrange(0,one+1),random.randrange(0,one*2),random.randrange(0,one*2),q]
    wt=[random.randrange(0,9) for _ in range(225)]
    blob=struct.pack('<%dI'%len(words),*words)+struct.pack('<225I',*wt)
    c.wrbytes(m.addr('tparams')+0x27c74,blob)
    h,w=1080,1920
    c.call('tiziano_af_init',(h,w))
    buf=c.heapp; c.heapp+=0x4000
    c.w32(m.addr('tispinfo')+96,buf)
    nf=random.choice([1,2,3]); files=[]
    for k in range(nf):
        bank=random.randrange(0,4)
        c.regs_hw[0xb8bc]=bank
        # stock reads buf + bank<<12; fill that page
        data=bytes(random.randrange(256) for _ in range(4096))
        if random.random()<0.5:
            data=bytes((b&0x7f) if random.random()<0.5 else b for b in data)
        c.wrbytes(buf+(bank<<12),data)
        open('s%d.bin'%k,'wb').write(data); files.append('s%d.bin'%k)
        c.call('af_interrupt_static',())
    open('p.bin','wb').write(blob)
    ref=subprocess.check_output(['./isr_c','p.bin',str(nf)]+files).decode().split('\n')
    last=[c.r32(m.addr('.bss')+0x101c+4*i) if False else 0 for i in range(0)]
    bss=[m.secaddr[i] for i,n in enumerate(m.secname) if n=='.bss'][0]
    data_=[m.secaddr[i] for i,n in enumerate(m.secname) if n=='.data'][0]
    last=[c.r32(bss+0x2101c+4*i) for i in range(225)]
    fv=[c.r32(bss+0x21008+4*i) for i in range(3)]; alt=c.r32(bss+0x21018)
    wm=[c.r32(data_+0x34684+4*i) for i in range(15)]
    fn=c.r8(m.addr('frame_num'))
    ok=True
    ok&= ' '.join(map(str,last))==ref[0].strip()
    ok&= ' '.join(map(str,fv+[alt]))==ref[1].strip()
    ok&= ' '.join(map(str,wm))==ref[2].strip()
    ok&= str(fn)==ref[3].strip()
    # unpack arrays
    n=0
    rows,cols=zone[1],zone[3]
    for i in range(rows):
        for j in range(cols):
            k=i*15+j
            exp=ref[4+k].split()
            got=[c.r32(m.addr(a)+4*k) for a in ('af_array_fird0','af_array_fird1','af_array_iird0','af_array_iird1','af_array_y_sum','af_array_high_luma_cnt')]
            if list(map(int,exp))!=got: ok=False
    if not ok:
        bad+=1; print('MISMATCH seed',seed)
print('isr: bad',bad)

build('attr_c', '#include <stdio.h>\n#include <stdlib.h>\n#include "@INC@"\nint main(int argc,char**argv){\n  static struct t31_af_params p; uint8_t u[88],a[88],g[88];\n  FILE*f=fopen(argv[1],"rb"); if(fread(&p,1,sizeof p,f)!=sizeof p) return 1; fclose(f);\n  f=fopen(argv[2],"rb"); if(fread(u,1,88,f)!=88) return 1; fclose(f);\n  uint32_t w=atoi(argv[3]),h=atoi(argv[4]);\n  t31_af_zone_layout(&p,w,h); /* init wrote the layout */\n  int r=t31_af_hist_from_user(u,a);\n  printf("ret %d\\n",r);\n  if(r) return 0;\n  uint8_t en=t31_af_attr_apply(a,&p);\n  t31_af_zone_layout(&p,w,h);\n  uint32_t regs[T31_AF_REGS_MAX][2]; unsigned n=t31_af_hw_regs(&p,1,regs);\n  printf("en %u\\nattr",en); for(int i=0;i<88;i++) printf(" %02x",a[i]); printf("\\nparams");\n  const uint8_t*b=(const uint8_t*)&p; for(unsigned i=0;i<608;i++) printf(" %02x",b[i]); printf("\\nregs");\n  for(unsigned i=0;i<n;i++) printf(" %x:%x",regs[i][0],regs[i][1]);\n  t31_af_attr_read(&p,0,en,a[17],0,g);\n  printf("\\nget"); for(int i=0;i<88;i++) printf(" %02x",g[i]); printf("\\n");\n}\n')
SEC=lambda m,n:[m.secaddr[i] for i,x in enumerate(m.secname) if x==n][0]
tab=[(0x34848,144),(0x34814,52),(0x34800,20),(0x347e0,32),(0x347d0,16),(0x347bc,20),(0x3479c,32),(0x3478c,16),(0x34764,40),(0x34744,32),(0x34734,16),(0x3470c,40),(0x346ec,32),(0x346dc,16),(0x346d4,8),(0x346c0,20),(0x34684,60),('b',0x21008,12),(0x34300,900)]
bad=0;inval=0
for seed in range(60):
    random.seed(5000+seed)
    m=Mod(STOCK); c=CPU(m)
    for n in ('system_irq_func_set','private_spin_lock_init','__private_spin_lock_irqsave','private_spin_unlock_irqrestore','private_dma_cache_sync'): c.hook(n,lambda cc,R:0)
    zone=[random.randrange(0,16) for _ in range(36)]
    zone[1]=random.randrange(5,16); zone[3]=random.randrange(5,16)
    words=zone+[random.randrange(0,2) for _ in range(13)]
    words+= [random.randrange(0,0x400) for _ in range(0x260//4-len(words))]
    blob=struct.pack('<%dI'%len(words),*words)+struct.pack('<225I',*[random.randrange(0,9) for _ in range(225)])
    c.wrbytes(m.addr('tparams')+0x27c74,blob)
    h,w=1080,1920
    c.call('tiziano_af_init',(h,w))
    # reference params after init = what init set (layout widths). Read stock arrays as 'before'
    bss=SEC(m,'.bss'); dat=SEC(m,'.data')
    def dump():
        out=b''
        for t in tab:
            if t[0]=='b': out+=c.rdbytes(bss+t[1],t[2])
            else: out+=c.rdbytes(dat+t[0],t[1])
        return out
    before=dump()
    u=bytearray(random.randrange(256) for _ in range(88))
    r=random.random()
    u[30]=random.randrange(5,16) if r<0.8 else random.randrange(0,20)
    u[31]=random.randrange(5,16) if r<0.8 else random.randrange(0,20)
    if random.random()<.3: u[28]=0
    if random.random()<.3: u[29]=random.randrange(0,3)
    dev=c.heapp; c.heapp+=0x20000
    ctrl=c.heapp; c.heapp+=64
    usr=c.heapp; c.heapp+=0x2000
    c.wrbytes(usr,bytes(u)); c.w32(ctrl,0x8000042); c.w32(ctrl+4,usr)
    c.writes.clear()
    rv=c.call('apical_isp_core_ops_s_ctrl',(dev,ctrl))
    open('pb.bin','wb').write(before); open('u.bin','wb').write(bytes(u))
    # reference uses params after init (layout widths already in zone[4..]); harness re-layouts
    ref=subprocess.check_output(['./attr_c','pb.bin','u.bin',str(w),str(h)]).decode().split('\n')
    if ref[0]=='ret -22':
        inval+=1
        if rv==0: print('seed',seed,'stock accepted, ref rejected', u[30],u[31]); bad+=1
        continue
    if rv!=0: print('seed',seed,'stock rejected rv',rv,u[30],u[31]); bad+=1; continue
    ok=True
    en=c.r8(bss+0x21014)
    if 'en %d'%en!=ref[1]: ok=False; print(' en',en,ref[1])
    attr=' '.join('%02x'%b for b in c.rdbytes(bss+0x2172c,88))
    if 'attr '+attr!=ref[2]: ok=False; print(' attr diff'); print(attr); print(ref[2])
    pm=' '.join('%02x'%b for b in dump()[:608])
    if 'params '+pm!=ref[3]: ok=False; print(' params diff')
    regs=' '.join('%x:%x'%(a,b) for a,b in c.writes if a!=0xb800)
    if 'regs '+regs!=ref[4]: ok=False; print(' regs diff',len(regs),len(ref[4]))
    # get via ctrl
    c.w32(ctrl,0x8000042); c.wrbytes(usr,bytes(88))
    c.call('apical_isp_core_ops_g_ctrl',(dev,ctrl))
    g=' '.join('%02x'%b for b in c.rdbytes(usr,88))
    if 'get '+g!=ref[5]: ok=False; print(' get diff'); print(g); print(ref[5])
    if not ok: bad+=1; print('MISMATCH',seed)
print('hist ctrl: bad',bad,'invalid-cases',inval)

