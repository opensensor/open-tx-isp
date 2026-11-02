/* SPDX-License-Identifier: MIT */
#ifdef REGTRACE_KERNEL_TREE_BUILD
#include "tx_isp_t41_awb_frame.h"
#include "tx_isp_t41_awb_zone_report.h"
static void t41_awb_algo_wake(void);   /* custom AWB library (#195), tx_isp_t41_awb_algo.h */
struct t41_awb_runtime {
    struct t41_awb_owned saved, candidate;
    uint32_t info[7];
    uint32_t day_start[2], has_day_start;
    uint8_t *dma;
};
static struct t41_awb_runtime *t41_awb_runtime = (void *)1;
static DEFINE_MUTEX(t41_native_awb_lock);
static DEFINE_SPINLOCK(t41_native_awb_irq_lock);
static unsigned int t41_native_awb_live, t41_native_awb_pending, t41_native_awb_bank;
static unsigned int t41_native_awb_frames = ~0U, t41_native_awb_dropped = ~0U;
static int t41_native_awb_error = -ENODEV;
/* jiffies of the last frame that filled the GetAwbStatistics planes (0: none
 * since the stream started); written under t41_native_awb_lock, .data like
 * the other diagnostic state of this file */
static unsigned long t41_native_awb_zone_stamp __attribute__((section(".data"))) = 0;
module_param(t41_native_awb_frames, uint, 0444);
module_param(t41_native_awb_dropped, uint, 0444);
module_param(t41_native_awb_error, int, 0444);
static void t41_native_awb_workfn(struct work_struct *work);

/* Colour diag (claude/t41-color): one-shot dump of the raw AWB DMA bank plus
 * the derived state s and parameter block p of the same frame. Write 1 to
 * awb_dump_req, then read /proc/t41_awb_dump: [dma 32768][s][p]. */
#ifdef __KERNEL__
#include <linux/proc_fs.h>
#include <linux/vmalloc.h>
static unsigned int t41_awb_dump_req __attribute__((section(".data")));
static unsigned int t41_awb_dump_len __attribute__((section(".data")));
module_param_named(awb_dump_req, t41_awb_dump_req, uint, 0644);
static unsigned char *t41_awb_dump_buf;
static ssize_t t41_awb_dump_read(struct file *f, char __user *u, size_t n, loff_t *off)
{
    ssize_t r;
    mutex_lock(&t41_native_awb_lock);
    r=t41_awb_dump_buf ? simple_read_from_buffer(u,n,off,t41_awb_dump_buf,t41_awb_dump_len) : 0;
    mutex_unlock(&t41_native_awb_lock);
    return r;
}
static const struct file_operations t41_awb_dump_fops = { .owner=THIS_MODULE, .read=t41_awb_dump_read };
#else /* host tests: no proc dump */
static unsigned int t41_awb_dump_req, t41_awb_dump_len;
static unsigned char *t41_awb_dump_buf;
#endif
#define T41_AWB_DUMP_BYTES (32768U+sizeof(((struct t41_awb_owned *)0)->s)+sizeof(((struct t41_awb_owned *)0)->p))
static void t41_native_awb_work_timed(struct work_struct *work);
static DECLARE_WORK(t41_native_awb_work, t41_native_awb_work_timed);

static struct t41_awb_runtime *t41_native_awb_object(unsigned int channel)
{
    return !channel && t41_kernel_data_ptr(t41_awb_runtime) ? t41_awb_runtime : NULL;
}
static void t41_native_awb_emit(const struct t41_awb_register *words, unsigned int n)
{
    unsigned int i;
    for (i=0;i<n;++i) {
        system_reg_write(words[i].address,words[i].value);
        if (words[i].address==0x4004) WRITE_ONCE(t41_awb_last_rgain,words[i].value&0x3fff);
        if (words[i].address==0x4008) WRITE_ONCE(t41_awb_last_bgain,words[i].value&0x3fff);
    }
}
/* Diagnostics of the published AWB result (read-only): mode (state
 * +0xeaa2; 1..8 take CT and gains from the manual slot), the calibrated CT
 * before a manual override (report +0x94) and the published reciprocal
 * R/B gains (report +0x90/+0x92, Q12). */
static unsigned int t41_awb_diag_mode __attribute__((section(".data")));
static unsigned int t41_awb_diag_ct_cal __attribute__((section(".data")));
static unsigned int t41_awb_diag_rgain __attribute__((section(".data")));
static unsigned int t41_awb_diag_bgain __attribute__((section(".data")));
module_param_named(awb_diag_mode, t41_awb_diag_mode, uint, 0444);
module_param_named(awb_diag_ct_cal, t41_awb_diag_ct_cal, uint, 0444);
module_param_named(awb_diag_rgain, t41_awb_diag_rgain, uint, 0444);
module_param_named(awb_diag_bgain, t41_awb_diag_bgain, uint, 0444);
/* t41_awb_long() skips the illuminant detection while state +0xc5f8 == 1,
 * +0xc600 == 1 and the statistics change is below params +0xcdc. */
static unsigned int t41_awb_diag_frz __attribute__((section(".data")));
static unsigned int t41_awb_diag_change __attribute__((section(".data")));
static unsigned int t41_awb_diag_frz_th __attribute__((section(".data")));
module_param_named(awb_diag_frz, t41_awb_diag_frz, uint, 0444);
module_param_named(awb_diag_change, t41_awb_diag_change, uint, 0444);
module_param_named(awb_diag_frz_th, t41_awb_diag_frz_th, uint, 0444);
/* Diagnostics (read-only), refreshed every AWB frame: detector outcome
 * (t41_awb_long_diag), non-zero words of the statistics DMA bank, the
 * global R/G/B sums (0x180ac..), the centre zone's first R/G/B plane values,
 * the published CT, the calibrated CT and the published reciprocal gains,
 * and the last frame error. */
static unsigned int t41_awb_diag[30] __attribute__((section(".data")));
static unsigned int t41_awb_diag_n = 30;
module_param_array_named(awb_diag, t41_awb_diag, uint, &t41_awb_diag_n, 0444);
/* AWB calibration words p+0xd20..0xd5e (u16) and EV knots p+0xf8..0x11c. */
static unsigned int t41_awb_diag_cal[42] __attribute__((section(".data")));
static unsigned int t41_awb_diag_cal_n = 42;
module_param_array_named(awb_diag_cal, t41_awb_diag_cal, uint, &t41_awb_diag_cal_n, 0444);
static unsigned int t41_awb_detect_diag_n = 8;
module_param_array_named(awb_diag_det, t41_awb_detect_diag, uint, &t41_awb_detect_diag_n, 0444);
/* Raw statistics layout check: words 0..31 of the DMA bank (zone 0) and
 * of the centre zone (offset (7*15+7)*128), AWB registers 0x18000..0x1804c. */
static unsigned int t41_awb_diag_raw[84] __attribute__((section(".data")));
static unsigned int t41_awb_diag_p[28] __attribute__((section(".data")));   /* live AWB param-block fields (fable colour diag) */
static unsigned int t41_awb_diag_p_n = 28;
module_param_array_named(awb_diag_p, t41_awb_diag_p, uint, &t41_awb_diag_p_n, 0444);
static unsigned int t41_awb_diag_raw_n = 84;
module_param_array_named(awb_diag_raw, t41_awb_diag_raw, uint, &t41_awb_diag_raw_n, 0444);
static void t41_native_awb_save(struct t41_awb_runtime *s)
{
    memcpy(&s->saved,&s->candidate,sizeof(s->saved));
    WRITE_ONCE(t41_ccm_ct,t41_tmo_le32(s->saved.p+0x28));
    t41_awb_diag_mode=s->saved.s[0xeaa2];
    t41_awb_diag_ct_cal=t41_tmo_le16(s->saved.report+0x94);
    t41_awb_diag_rgain=t41_tmo_le16(s->saved.report+0x90);
    t41_awb_diag_bgain=t41_tmo_le16(s->saved.report+0x92);
    t41_awb_diag_frz=(t41_tmo_le16(s->saved.s+0xc5f8)<<8)|s->saved.s[0xc600];
    t41_awb_diag_change=(t41_awb_absdiff(t41_tmo_le16(s->saved.s+0xeab4),t41_tmo_le16(s->saved.s+0xeaac))+
        t41_awb_absdiff(t41_tmo_le16(s->saved.s+0xeab6),t41_tmo_le16(s->saved.s+0xeaae)))&0xffff;
    t41_awb_diag_frz_th=t41_tmo_le16(s->saved.p+0xcdc);
}
static void t41_native_awb_stop(void)
{
    unsigned long flags;
    /* Gate and schedule share a lock; draining alone permits late requeue. */
    spin_lock_irqsave(&t41_native_awb_irq_lock,flags);
    t41_native_awb_live=0; t41_native_awb_pending=0;
    spin_unlock_irqrestore(&t41_native_awb_irq_lock,flags);
    cancel_work_sync(&t41_native_awb_work);
    WRITE_ONCE(t41_native_awb_zone_stamp,0);
}
static void t41_native_awb_start(void)
{
    unsigned long flags;
    mutex_lock(&t41_native_awb_lock);
    if (t41_native_awb_object(0)) {
        spin_lock_irqsave(&t41_native_awb_irq_lock,flags);
        t41_native_awb_pending=0; t41_native_awb_live=1;
        spin_unlock_irqrestore(&t41_native_awb_irq_lock,flags);
        system_reg_write(0x18000,1);
        system_reg_write(0x4000,1); system_reg_write(0x5000,1);
    }
    mutex_unlock(&t41_native_awb_lock);
}
static void t41_native_awb_queue(void)
{
    unsigned long flags;
    spin_lock_irqsave(&t41_native_awb_irq_lock,flags);
    if (t41_native_awb_live) {
        if (t41_native_awb_pending) ++t41_native_awb_dropped;
        t41_native_awb_bank=system_reg_read(0x18050)&3U;
        t41_native_awb_pending=1;
        queue_work(t41_tuning_wq(), &t41_native_awb_work);
    }
    spin_unlock_irqrestore(&t41_native_awb_irq_lock,flags);
}
static void t41_native_awb_work_timed(struct work_struct *work)
{
    u64 start = t41_work_begin();

    t41_native_awb_workfn(work);
    t41_work_end(T41_WT_AWB, start);
}
static void t41_native_awb_workfn(struct work_struct *work)
{
    struct t41_awb_runtime *s;
    struct t41_awb_frame_buffers buffers;
    struct t41_awb_register words[T41_AWB_FRAME_WORDS];
    unsigned long flags;
    unsigned int bank,bytes,rgb[3],i,n;
    int pending,ret=-EAGAIN;
    (void)work;
    mutex_lock(&t41_native_awb_lock);
    s=t41_native_awb_object(0);
    spin_lock_irqsave(&t41_native_awb_irq_lock,flags);
    pending=t41_native_awb_pending && t41_native_awb_live;
    bank=t41_native_awb_bank; t41_native_awb_pending=0;
    spin_unlock_irqrestore(&t41_native_awb_irq_lock,flags);
    if (!s || !pending) goto done;
    T41_LS_TIME(T41_WT_AWB_COPY, memcpy(&s->candidate,&s->saved,sizeof(s->candidate)));
    if (s->candidate.p[0xcca]>1) { ret=-EINVAL; goto failed; }
    bytes=s->candidate.p[0xcca] ? 8192U : 32768U;
    dma_cache_sync(NULL,s->dma+bank*bytes,bytes,DMA_FROM_DEVICE);
    for (i=0;i<3;++i) rgb[i]=system_reg_read(0x180ac+i*4);
    buffers=t41_awb_buffers(&s->candidate);
    T41_LS_TIME(T41_WT_AWB_FRAME, ret=t41_awb_frame(&buffers,s->candidate.red,s->candidate.blue,
        s->dma+bank*bytes,bytes,rgb,words,&n) ? -ERANGE : 0);
    if (READ_ONCE(t41_awb_dump_req) && t41_awb_dump_buf) {
        memcpy(t41_awb_dump_buf,s->dma+bank*bytes,bytes);
        memcpy(t41_awb_dump_buf+32768,s->candidate.s,sizeof(s->candidate.s));
        memcpy(t41_awb_dump_buf+32768+sizeof(s->candidate.s),s->candidate.p,sizeof(s->candidate.p));
        t41_awb_dump_len=T41_AWB_DUMP_BYTES; WRITE_ONCE(t41_awb_dump_req,0);
    }
    { u64 t41_diag_t0=t41_work_begin();
    {
        const uint32_t *w=(const uint32_t *)(s->dma+bank*bytes);
        unsigned int nz=0,k,zone=(7*15+7)*4;
        for (k=0;k<bytes/4;++k) nz+=w[k]!=0;
        for (k=0;k<32;++k) t41_awb_diag_raw[k]=w[k];
        for (k=0;k<32 && (7*15+7)*32+k<bytes/4;++k) t41_awb_diag_raw[32+k]=w[(7*15+7)*32+k];
        for (k=0;k<20;++k) t41_awb_diag_raw[64+k]=system_reg_read(0x18000+k*4);
        t41_awb_diag[0]=t41_awb_long_diag[0]; t41_awb_diag[1]=t41_awb_long_diag[1];
        t41_awb_diag[2]=t41_awb_long_diag[2]; t41_awb_diag[3]=nz;
        t41_awb_diag[4]=rgb[0]; t41_awb_diag[5]=rgb[1]; t41_awb_diag[6]=rgb[2];
        t41_awb_diag[7]=t41_tmo_le32(s->candidate.s+0x3944+zone);
        t41_awb_diag[8]=t41_tmo_le32(s->candidate.s+0x3944+T41_AWB_PLANE_BYTES+zone);
        t41_awb_diag[9]=t41_tmo_le32(s->candidate.s+0x3944+2*T41_AWB_PLANE_BYTES+zone);
        t41_awb_diag[10]=t41_tmo_le32(s->candidate.p+0x28);
        t41_awb_diag[11]=t41_tmo_le16(s->candidate.report+0x94);
        t41_awb_diag[12]=t41_tmo_le16(s->candidate.report+0x90);
        t41_awb_diag[13]=t41_tmo_le16(s->candidate.report+0x92);
        t41_awb_diag[14]=(unsigned int)ret;
        t41_awb_diag[15]=(s->candidate.p[0xcca]<<24)|(s->candidate.p[0xccc]<<16)|
            (t41_tmo_le16(s->candidate.p+0xc6e)<<8)|t41_tmo_le16(s->candidate.p+0xc72);
        {
            const unsigned char *cp=s->candidate.p,*cs=s->candidate.s;
            unsigned int rows=t41_tmo_le16(cp+0xc6e),cols=t41_tmo_le16(cp+0xc72);
            unsigned int cnt=rows*cols,mx=0,sum=0,r,c,ctr;
            if (rows>15) rows=15;
            if (cols>15) cols=15;
            cnt=rows*cols; ctr=(rows/2)*cols+cols/2;
            for (k=0;k<cnt;++k) if (t41_tmo_le32(cs+0x2a30+k*4)>mx) mx=t41_tmo_le32(cs+0x2a30+k*4);
            for (r=0;r<rows;++r) for (c=0;c<cols;++c) sum+=t41_tmo_le32(cs+0xd904+(r*15+c)*4);
            t41_awb_diag[16]=t41_tmo_le16(cp+0xd60)|(t41_tmo_le16(cp+0xd62)<<8)|(t41_tmo_le16(cp+0xd66)<<16);
            { unsigned int q; for (q=0;q<8;++q) t41_awb_diag_p[q]=t41_tmo_le16(cp+0xd60+q*2);
              for (q=0;q<4;++q) t41_awb_diag_p[8+q]=t41_tmo_le16(cp+0xc6c+q*2);
              t41_awb_diag_p[12]=t41_tmo_le16(cp+0xcd2); t41_awb_diag_p[13]=t41_tmo_le16(cp+0xcd4); t41_awb_diag_p[14]=t41_tmo_le16(cp+0xcd6);
              t41_awb_diag_p[15]=cp[0xcca]; t41_awb_diag_p[16]=cp[0xccc]; t41_awb_diag_p[17]=t41_tmo_le32(cp+0x38); t41_awb_diag_p[18]=t41_tmo_le32(cp+0x70);
              t41_awb_diag_p[19]=t41_tmo_le32(cp+0x74); t41_awb_diag_p[20]=t41_tmo_le32(cp+0xac); t41_awb_diag_p[21]=t41_tmo_le32(cp+0x28); t41_awb_diag_p[22]=cp[0xf0];
              t41_awb_diag_p[23]=t41_tmo_le32(cp+0x120); t41_awb_diag_p[24]=t41_tmo_le16(cp+0xc74); t41_awb_diag_p[25]=t41_tmo_le16(cp+0xc92);
              t41_awb_diag_p[26]=t41_tmo_le32(cs+0x393c); t41_awb_diag_p[27]=t41_tmo_le32(cp+0x4ec+(7*15+7)*4); }
            t41_awb_diag[17]=mx;
            t41_awb_diag[18]=t41_tmo_le32(cs+0x1c20+ctr*4);
            t41_awb_diag[19]=t41_tmo_le32(cs+0x1c20+(cnt+ctr)*4);
            t41_awb_diag[20]=t41_tmo_le32(cs+0xd904+((rows/2)*15+cols/2)*4);
            t41_awb_diag[21]=sum;
            {
                unsigned int at=((rows/2)*15+cols/2)*4,b2,w0=0,w1=0;
                for (b2=0;b2<4;++b2) {
                    w0|=(t41_tmo_le16(cp + 0xd46 + b2*2)&0xff)<<(b2*8);
                    w1|=(t41_tmo_le16(cp + 0xd4e + b2*2)&0xff)<<(b2*8);
                }
                t41_awb_diag[22]=t41_tmo_le32(cp);
                t41_awb_diag[23]=w0;
                t41_awb_diag[24]=t41_tmo_le32(cs+at+0x1518);
                t41_awb_diag[25]=t41_tmo_le32(cs+0x3944+4*T41_AWB_PLANE_BYTES+at);
                t41_awb_diag[26]=w1;
                t41_awb_diag[27]=t41_tmo_le16(cp+0xd44);
                t41_awb_diag[28]=t41_tmo_le16(cs+0x3514);
                t41_awb_diag[29]=t41_tmo_le32(cs+0xea98);
                for (b2=0;b2<32;++b2) t41_awb_diag_cal[b2]=t41_tmo_le16(cp + 0xd20 + b2*2);
                for (b2=0;b2<10;++b2) t41_awb_diag_cal[32+b2]=t41_tmo_le32(cp + 0xf8 + b2*4);
            }
        }
    }
    t41_work_end(T41_WT_AWB_DIAG,t41_diag_t0); }
    if (!ret) {
        /* Exactly one publication after the entire candidate has validated. */
        t41_native_awb_emit(words,n);
        T41_LS_TIME(T41_WT_AWB_SAVE, t41_native_awb_save(s));
        ++t41_native_awb_frames;
        WRITE_ONCE(t41_native_awb_zone_stamp,t41_awb_zone_report_stamp(jiffies));
    }
failed:
    if (ret) ++t41_native_awb_dropped;
    /* A malformed frame never publishes gains, but must not stall capture. */
    if (READ_ONCE(t41_native_awb_live)) system_reg_write(0x18000,1);
    t41_native_awb_error=ret;
    t41_awb_algo_wake();   /* custom AWB library (#195): one wake-up per processed frame, a frame without new gains too */
done:
    mutex_unlock(&t41_native_awb_lock);
}
static int t41_native_awb_init(unsigned int channel, const uint32_t *config)
{
    struct t41_awb_runtime *s;
    struct t41_awb_frame_buffers buffers;
    struct t41_awb_register words[T41_AWB_HARDWARE_WORDS+10];
    const uint8_t *p;
    unsigned int n,m,i;
    int ret=-EINVAL;
    if (channel || !t41_kernel_data_ptr(config)) return -EINVAL;
    mutex_lock(&t41_native_awb_lock);
    if (t41_native_awb_object(0)) { ret=-EBUSY; goto done; }
    p=(void *)(uintptr_t)((uint32_t *)(void *)tparamsP_storage)[0];
    if (!t41_kernel_data_ptr(p)) goto done;
    s=vzalloc(sizeof(*s));
    if (!s) { ret=-ENOMEM; goto done; }
    if (t41_awb_cold(&s->candidate,p+0x978,T41_AWB_PARAM_BYTES,config[0],config[1]) ||
        t41_awb_hardware(&s->candidate,1,words,&n)) goto free_state;
    buffers=t41_awb_buffers(&s->candidate);
    if (t41_awb_gain_words(&buffers,words+n,&m)) goto free_state;
    s->dma=private_kmalloc(131072,0x024000c0);
    if (!s->dma) { ret=-ENOMEM; goto free_state; }
    memset(s->dma,0,131072);
    dma_cache_sync(NULL,s->dma,131072,DMA_BIDIRECTIONAL);
    s->info[0]=(uintptr_t)s->saved.p; s->info[1]=(uintptr_t)s->saved.s;
    s->info[2]=(uintptr_t)s->saved.control; s->info[3]=(uintptr_t)s->saved.report;
    s->info[4]=4; s->info[5]=(uintptr_t)s->dma; s->info[6]=virt_to_phys(s->dma);
    /* Allocation and all math validation precede the first DMA/MMIO write. */
    for (i=0;i<4;++i) system_reg_write(0x1803c+i*4,s->info[6]+i*32768);
    system_reg_write(0x1804c,3);
    t41_native_awb_emit(words,n+m); t41_native_awb_save(s);
    t41_awb_runtime=s; awb_info[0]=(uintptr_t)s->info;
    system_irq_func_set(0,3,0); tisp_event_set_cb(0,12,0);
    system_reg_write(0x304,0x20220702);
    ((uint32_t *)(void *)tpm_cb_storage)[3]=(uintptr_t)tisp_awb_pm_get_regsize;
    ((uint32_t *)(void *)tpm_cb_storage)[4]=(uintptr_t)tisp_awb_pm_suspend;
    ((uint32_t *)(void *)tpm_cb_storage)[5]=(uintptr_t)tisp_awb_pm_resume;
    t41_native_awb_frames=t41_native_awb_dropped=0;
    WRITE_ONCE(t41_native_awb_zone_stamp,0);
    smp_store_release(&t41_awb_ready[0],1);
#ifdef __KERNEL__
    if (!t41_awb_dump_buf) {
        t41_awb_dump_buf=vzalloc(T41_AWB_DUMP_BYTES);
        if (t41_awb_dump_buf) proc_create("t41_awb_dump",0444,NULL,&t41_awb_dump_fops);
    }
#endif
    ret=0; goto done;
free_state:
    vfree(s);
done:
    t41_native_awb_error=ret;
    mutex_unlock(&t41_native_awb_lock);
    return ret;
}
static int t41_native_awb_deinit(unsigned int channel)
{
    struct t41_awb_runtime *s;
    if (channel) return -EINVAL;
    /* The parent must stop the ISP before releasing its DMA allocation.
     * Draining software alone cannot stop the hardware DMA master. */
    if (READ_ONCE(t41_native_awb_live)) return -EBUSY;
    t41_tmo_stream_stop(); t41_native_awb_stop();
    mutex_lock(&t41_native_awb_lock);
    s=t41_native_awb_object(0);
    smp_store_release(&t41_awb_ready[0],0);
    WRITE_ONCE(t41_native_awb_zone_stamp,0);
    system_irq_func_set(0,3,0); tisp_event_set_cb(0,12,0);
    awb_info[0]=0; t41_awb_runtime=(void *)1;
    ((uint32_t *)(void *)tpm_cb_storage)[3]=0;
    ((uint32_t *)(void *)tpm_cb_storage)[4]=0;
    ((uint32_t *)(void *)tpm_cb_storage)[5]=0;
    /* As the OEM: 0x1804c is not cleared (0 = one buffer, not off). */
    if (s) { private_kfree(s->dma); vfree(s); }
#ifdef __KERNEL__
    if (t41_awb_dump_buf) { remove_proc_entry("t41_awb_dump",NULL); vfree(t41_awb_dump_buf); t41_awb_dump_buf=NULL; }
#endif
    t41_native_awb_error=-ENODEV;
    mutex_unlock(&t41_native_awb_lock);
    return 0;
}

/* A geometry/format change while statistics are in flight needs a stopped
 * stream. Same-geometry calibration and software controls commit atomically
 * under the frame mutex. Do not reinterpret an old bank with a new layout. */
static int t41_native_awb_geometry_changed(const struct t41_awb_owned *a,const struct t41_awb_owned *b)
{
    return memcmp(a->p+0xc6c,b->p+0xc6c,0x44) ||
        memcmp(a->p+0xcc8,b->p+0xcc8,6);
}
static int t41_native_awb_control(unsigned int channel,enum t41_awb_control_op op,
        void *data,unsigned int bytes,int get)
{
    struct t41_awb_runtime *s;
    struct t41_awb_register words[T41_AWB_HARDWARE_WORDS];
    unsigned int n=0;
    int ret=-ENODEV;
    if (!t41_kernel_data_ptr(data)) return -EINVAL;
    mutex_lock(&t41_native_awb_lock);
    s=t41_native_awb_object(channel);
    if (!s) goto done;
    if (get) {
        /* GetAwbStatistics: only the planes of a frame of the running
         * stream within the last second (tx_isp_t41_awb_zone_report.h);
         * the stock copies its state regardless. */
        if (op==T41_AWB_ZONE && !t41_awb_zone_report_fresh(READ_ONCE(t41_native_awb_live),
                READ_ONCE(t41_native_awb_zone_stamp),jiffies)) { ret=-EAGAIN; goto done; }
        ret=(op==T41_AWB_PUBLIC ? t41_awb_public_get(&s->saved,data,bytes) :
            t41_awb_control_get(&s->saved,op,data,bytes)) ? -EINVAL : 0;
        goto done;
    }
    memcpy(&s->candidate,&s->saved,sizeof(s->candidate));
    if (op==T41_AWB_PUBLIC) {
        struct t41_awb_frame_buffers b=t41_awb_buffers(&s->candidate);
        const uint8_t *in=data;
        if (t41_awb_public_begin(&s->candidate,in,bytes)) { ret=-EINVAL; goto done; }
        if (t41_tmo_le32(in+64) && t41_awb_gain_words(&b,words,&n)) { ret=-EINVAL; goto done; }
        t41_awb_public_finish(&s->candidate,in);
        if (t41_tmo_le32(in+64)) {
            s->day_start[0]=t41_tmo_le32(in+68); s->day_start[1]=t41_tmo_le32(in+72);
            s->has_day_start=1;
        }
        t41_native_awb_emit(words,n); t41_native_awb_save(s); ret=0; goto done;
    }
    ret=t41_awb_control_set(&s->candidate,op,data,bytes) ? -EINVAL : 0;
    if (ret) goto done;
    if (READ_ONCE(t41_native_awb_live) && t41_native_awb_geometry_changed(&s->saved,&s->candidate)) {
        ret=-EBUSY; goto done;
    }
    if (op==T41_AWB_PARAMS && !s->candidate.s[0xeaa1]) {
        if (t41_awb_hardware(&s->candidate,1,words,&n)) { ret=-EINVAL; goto done; }
    }
    t41_native_awb_emit(words,n); t41_native_awb_save(s);
done:
    mutex_unlock(&t41_native_awb_lock);
    return ret;
}
static int t41_native_awb_refresh(unsigned int channel,int daynight)
{
    struct t41_awb_runtime *s;
    const uint8_t *p;
    struct t41_awb_register words[T41_AWB_HARDWARE_WORDS];
    unsigned int n=0;
    int ret=-ENODEV;
    mutex_lock(&t41_native_awb_lock);
    s=t41_native_awb_object(channel);
    if (!s) goto done;
    memcpy(&s->candidate,&s->saved,sizeof(s->candidate));
    if (daynight) {
        p=(void *)(uintptr_t)((uint32_t *)(void *)tparamsP_storage)[0];
        if (!t41_kernel_data_ptr(p)) { ret=-EINVAL; goto done; }
        memcpy(s->candidate.p,p+0x978,T41_AWB_PARAM_BYTES);
        if (s->has_day_start && !READ_ONCE(*(uint32_t *)(void *)day_night_storage)) {
            unsigned int i;
            for (i=0;i<4;++i) t41_ae_put32(s->candidate.p+0xc+i*4,s->day_start[i&1]);
        }
        ret=t41_awb_daynight_owned(&s->candidate);
    } else ret=t41_awb_params_refresh_owned(&s->candidate);
    if (ret) { ret=-EINVAL; goto done; }
    if (READ_ONCE(t41_native_awb_live) && t41_native_awb_geometry_changed(&s->saved,&s->candidate)) {
        ret=-EBUSY; goto done;
    }
    if (daynight && !s->candidate.s[0xeaa1] && t41_awb_hardware(&s->candidate,1,words,&n)) {
        ret=-EINVAL; goto done;
    }
    t41_native_awb_emit(words,n); t41_native_awb_save(s);
done:
    mutex_unlock(&t41_native_awb_lock);
    return ret;
}
static int t41_native_awb_exposure_update(unsigned int gain,unsigned int ev,unsigned int mask)
{
    struct t41_awb_runtime *s;
    struct t41_awb_register words[T41_AWB_HARDWARE_WORDS];
    unsigned int n=0;
    int ret=-ENODEV;
    mutex_lock(&t41_native_awb_lock);
    s=t41_native_awb_object(0);
    if (!s) goto done;
    if (!(mask&1)) gain=t41_tmo_le32(s->saved.s+0xea9c);
    if (!(mask&2)) ev=t41_tmo_le32(s->saved.s+0xea98);
    if (t41_tmo_le32(s->saved.s+0xea98)==ev && t41_tmo_le32(s->saved.s+0xea9c)==gain) { ret=0; goto done; }
    memcpy(&s->candidate,&s->saved,sizeof(s->candidate));
    t41_ae_put32(s->candidate.s+0xea98,ev); t41_ae_put32(s->candidate.s+0xea9c,gain);
    ret=t41_awb_yweight_owned(&s->candidate);
    if (!ret && gain!=t41_tmo_le32(s->saved.s+0xea9c)) ret=t41_awb_hardware(&s->candidate,0,words,&n);
    if (ret) { ret=-EINVAL; goto done; }
    t41_native_awb_emit(words,n); t41_native_awb_save(s);
done:
    mutex_unlock(&t41_native_awb_lock);
    return ret;
}
static int t41_native_awb_exposure(unsigned int gain,unsigned int ev)
{
    return t41_native_awb_exposure_update(gain,ev,3);
}
static int t41_native_awb_suspend(unsigned int channel,uint32_t **cursor)
{
    unsigned int i,address;
    if (channel || !t41_kernel_data_ptr(cursor) || !t41_kernel_data_ptr(*cursor)) return -EINVAL;
    t41_native_awb_stop();
    mutex_lock(&t41_native_awb_lock);
    for (i=0;i<55;++i) {
        address=i<47 ? 0x18004+i*4 : i<51 ? 0x4004+(i-47)*4 : 0x5004+(i-51)*4;
        *(*cursor)++=address; *(*cursor)++=system_reg_read(address);
    }
    mutex_unlock(&t41_native_awb_lock);
    return 0;
}

/* Legacy writer entry points share the same owner as frame publication.
 * kind: 0 gains, 1 full setup, 2 regional thresholds, 3 luminance thresholds. */
static int t41_native_awb_writer(unsigned int channel,unsigned int kind)
{
    struct t41_awb_runtime *s;
    struct t41_awb_frame_buffers b;
    struct t41_awb_register words[T41_AWB_HARDWARE_WORDS];
    unsigned int n,i,m=0;
    int ret=-ENODEV;
    if (kind>3) return -EINVAL;
    mutex_lock(&t41_native_awb_lock);
    s=t41_native_awb_object(channel);
    if (!s) goto done;
    memcpy(&s->candidate,&s->saved,sizeof(s->candidate));
    b=t41_awb_buffers(&s->candidate);
    ret=kind ? t41_awb_hardware(&s->candidate,kind==1,words,&n) : t41_awb_gain_words(&b,words,&n);
    if (ret) { ret=-EINVAL; goto done; }
    if (kind>=2) {
        if (kind==2) memcpy(s->candidate.p+0xcc0,s->saved.p+0xcc0,6);
        else memcpy(s->candidate.p+0xcb0,s->saved.p+0xcb0,16);
        for (i=0;i<n;++i) {
            if (kind==2 && words[i].address==0x18038) break;
            if (kind==3 && words[i].address!=0x18038 && i!=n-1) continue;
            words[m++]=words[i];
        }
        n=m;
    }
    t41_native_awb_emit(words,n); t41_native_awb_save(s);
done:
    mutex_unlock(&t41_native_awb_lock);
    return ret;
}

/* Open's eight-byte Q10 manual/auto extension predates OEM attribute support.
 * Manual means exact hardware gains; freeze only WB publication while the
 * generic estimator keeps history. Auto relinquishes that explicit override. */
static int t41_native_awb_compat(unsigned int mode,unsigned int red,unsigned int blue,int get,
        unsigned int result[3])
{
    struct t41_awb_runtime *s;
    struct t41_awb_register words[10];
    unsigned int request[3],wb[2],bank,i,n=0;
    int ret=-ENODEV;
    if (!get && (mode>1 || red<512 || red>6144 || blue<512 || blue>6144)) return -EINVAL;
    mutex_lock(&t41_native_awb_lock);
    s=t41_native_awb_object(0);
    if (!s) goto done;
    if (get) {
        if (!result) { ret=-EINVAL; goto done; }
        result[0]=s->saved.s[0xeaa2]==0 || s->saved.s[0xeaa2]==9;
        result[1]=t41_awb_last_rgain; result[2]=t41_awb_last_bgain;
        ret=0; goto done;
    }
    memcpy(&s->candidate,&s->saved,sizeof(s->candidate));
    request[0]=mode ? 0 : 1; request[1]=(red+2)>>2; request[2]=(blue+2)>>2;
    ret=t41_awb_control_set(&s->candidate,T41_AWB_MODE,(void *)request,sizeof(request));
    if (ret) { ret=-EINVAL; goto done; }
    s->candidate.s[0xeaa1]=!mode;
    s->candidate.public_freeze=!mode;
    t41_ae_put32(s->candidate.s+0xeaa4,t41_tmo_le32(s->candidate.p+0x28));
    if (!mode) {
        request[0]=red; request[1]=blue; t41_awb_gain_pack(request,wb);
        for (bank=0;bank<2;++bank) {
            for (i=0;i<4;++i) {
                words[n].address=0x4004+bank*0x1000+i*4; words[n++].value=wb[i&1];
            }
            words[n].address=0x4000+bank*0x1000; words[n++].value=1;
        }
    }
    t41_native_awb_emit(words,n); t41_native_awb_save(s);
done:
    mutex_unlock(&t41_native_awb_lock);
    return ret;
}
static int t41_native_awb_start_gain(unsigned int channel,const unsigned int gains[2])
{
    struct t41_awb_runtime *s;
    struct t41_awb_frame_buffers b;
    struct t41_awb_register words[10];
    unsigned int i,n;
    int ret=-ENODEV;
    if (!t41_kernel_data_ptr(gains)) return -EINVAL;
    mutex_lock(&t41_native_awb_lock);
    s=t41_native_awb_object(channel);
    if (!s) goto done;
    memcpy(&s->candidate,&s->saved,sizeof(s->candidate));
    for (i=0;i<4;++i) t41_ae_put32(s->candidate.p+0xc+i*4,gains[i&1]);
    b=t41_awb_buffers(&s->candidate);
    ret=t41_awb_gain_words(&b,words,&n);
    if (ret) { ret=-EINVAL; goto done; }
    /* OEM also updates day-bank +0xd24..0xd30, subsequently copied to
     * active +0x984..0x990. Keep that RAM-only override here; never edit the
     * installed calibration or let another algorithm observe our scratch. */
    s->day_start[0]=gains[0]; s->day_start[1]=gains[1]; s->has_day_start=1;
    t41_native_awb_emit(words,n); t41_native_awb_save(s);
done:
    mutex_unlock(&t41_native_awb_lock);
    return ret;
}
static int t41_native_awb_observe(int target,unsigned int result[2])
{
    struct t41_awb_runtime *s;
    struct t41_awb_frame_buffers b;
    struct t41_awb_register words[10];
    unsigned int i,n,precision,fraction,mean;
    int ret=-ENODEV;
    if (!result) return -EINVAL;
    mutex_lock(&t41_native_awb_lock);
    s=t41_native_awb_object(0);
    if (!s) goto done;
    if (!t41_native_awb_frames) { ret=-EAGAIN; goto done; }
    if (target) {
        memcpy(&s->candidate,&s->saved,sizeof(s->candidate));
        s->candidate.s[0xeaa1]=s->candidate.s[0xeaa2]=0;
        b=t41_awb_buffers(&s->candidate);
        ret=t41_awb_gain_words(&b,words,&n);
        if (ret || n!=10) { ret=-ERANGE; goto done; }
        result[0]=words[0].value&0x3fff; result[1]=words[1].value&0x3fff;
    } else {
        precision=t41_tmo_le16(s->saved.p+0xcd2); fraction=t41_tmo_le16(s->saved.p+0xcd4);
        if (precision<fraction || precision>31) { ret=-ERANGE; goto done; }
        for (i=0;i<2;++i) {
            mean=t41_tmo_le16(s->saved.s+0xeaac+i*2);
            if (!mean) { ret=-ENODATA; goto done; }
            result[i]=t41_tmo_div(1ULL<<(precision-fraction+10),mean);
        }
    }
    ret=0;
done:
    mutex_unlock(&t41_native_awb_lock);
    return ret;
}
#endif
