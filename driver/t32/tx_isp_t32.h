/* SPDX-License-Identifier: GPL-2.0 */
/* T32 driver-internal declarations. */
#ifndef TX_ISP_T32_H
#define TX_ISP_T32_H

#include <linux/types.h>

struct i2c_driver;
struct platform_device;

extern int t32_print_level;

int isp_printf(unsigned int level, const char *fmt, ...);

/* tx_isp_t32_core.c */
int tx_isp_t32_core_init(void);
void tx_isp_t32_core_exit(void);
void t32_core_sensor_driver_gone(struct i2c_driver *drv);
int tx_isp_subdev_init(struct platform_device *pdev, void *sd, void *ops);
void tx_isp_subdev_deinit(void *sd);

u32 t32_core_sensor_fps(void);
int t32_core_sensor_size(u32 *w, u32 *h);
unsigned int t32_core_memopt(void);
int t32_core_iq_bin(const u8 **bin, u32 *bytes);
int t32_core_sensor_mbus(u32 *code);
int t32_core_sensor_expo(u32 packed);
u32 t32_core_sensor_vts(void);

/* tx_isp_t32_hw.c */
struct t32_hw_stats {
	u32 isp_irqs, vic_irqs, frame_ends, stream_ons;
	u32 ae_irqs, ae_hist_irqs, awb_irqs, stats_inits;
	u32 bringup_steps, bringup_mean16, bringup_it;
};
extern struct t32_hw_stats t32_hw_stats;
int t32_hw_init(void);
void t32_hw_exit(void);
int t32_hw_input_setup(const void *attr, u32 w, u32 h);
void t32_hw_rcfg_run_stream_on(void);
extern u32 t32_rcfg_runs, t32_rcfg_timeouts, t32_rcfg_last_len;
void t32_hw_stream_on(void);
void t32_hw_stream_off(void);
void t32_hw_msca_push(int ch, u32 y, u32 uv);
void t32_hw_msca_start(int ch, u32 w, u32 h, u32 stride, u32 in_w, u32 in_h);
void t32_hw_msca_stop(int ch);
int t32_hw_msca_pop_done(int ch, u32 *y, u32 *uv);

/* tx_isp_t32_fs.c */
struct seq_file;
int t32_fs_init(void);
void t32_fs_exit(void);
void t32_fs_stop_all(void);
void t32_fs_done_irq(u32 done);
void t32_fs_show(struct seq_file *m);

/* tx_isp_t32_sinfo.c (shared registry, driver/common/tx_isp_sinfo.c) */
int tx_isp_sinfo_init(void);
void tx_isp_sinfo_exit(void);
int tx_isp_sinfo_sensor_bind(void *subdev, struct module *owner);
void tx_isp_sinfo_sensor_unbind(void *subdev, struct module *owner);

/* raw access to objects owned by the sensor modules */
#define T32_AT(base, off, type)		(*(type *)((char *)(base) + (off)))

#endif /* TX_ISP_T32_H */
