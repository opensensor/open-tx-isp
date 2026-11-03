// SPDX-License-Identifier: GPL-2.0
/*
 * T32 (PRJ007) TX-ISP driver, S1 skeleton.
 *
 * Scope of S1: the device nodes and the ioctl answers vendor libimp 2.2.0
 * needs to get through IMP_ISP_Open, IMP_ISP_AddSensor and
 * IMP_ISP_EnableSensor with the same ioctl sequence as the vendor driver
 * (reference: QEMU S0 runs, audit/T32_S0_1025.md), sensor registration
 * through the prebuilt T32 sensor modules, and the sensor's own stream-on.
 * Not in S1: the ISP pipeline itself (VIC/CSI/MSCA programming, frames,
 * tisp/3A, IQ bin parsing).  Those ioctls are answered so libimp proceeds,
 * and logged; nothing is written to the ISP yet.
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/i2c.h>
#include <linux/slab.h>
#include <linux/mutex.h>
#include <linux/list.h>
#include <linux/gfp.h>
#include <linux/mm.h>
#include <linux/io.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/platform_device.h>

#include "tx_isp_t32.h"
#include "tx_isp_t32_abi.h"
#include "tx_isp_t32_regs.h"
#include "tx_isp_t32_mem.h"
#include "tx_isp_t32_msca.h"

static unsigned int isp_memopt = T32_MEMOPT_DEFAULT;
module_param(isp_memopt, uint, 0444);
MODULE_PARM_DESC(isp_memopt, "MDNS memory ratio in 1/1000 (<=1000 uncompressed, max 2000)");

/*
 * DRIVER_VERSION: libimp passes a 64-byte buffer (soc name at 0, version at
 * 32) despite the int-sized ioctl and refuses IMP_ISP_Open unless both match
 * its own strings (libimp 2.2.0: "PRJ007" / "20251107a").
 */
static char *driver_soc = "PRJ007";
module_param(driver_soc, charp, 0444);
MODULE_PARM_DESC(driver_soc, "SoC name answered to DRIVER_VERSION");
static char *driver_version = "20251107a";
module_param(driver_version, charp, 0444);
MODULE_PARM_DESC(driver_version, "ISP driver version answered to DRIVER_VERSION (must match libimp)");

/*
 * DEFAULT_BIN: libimp passes an 880-byte buffer (zeroed) and checks two
 * strings the driver puts into it against the IQ bin it is about to load:
 * the bin format version at 863 (bin bytes 0-7, "1.00") and the SoC at 871
 * (bin bytes 152.., "PRJ007").  The rest of the buffer is left zero, as far
 * as libimp 2.2.0 is concerned (S1).
 */
#define T32_DEFAULT_BIN_SIZE	880
#define T32_DEFAULT_BIN_VER	863
#define T32_DEFAULT_BIN_SOC	871
static char *bin_version = "1.00";
module_param(bin_version, charp, 0444);
MODULE_PARM_DESC(bin_version, "IQ bin format version the driver accepts");

static int t32_trace = 1;
module_param(t32_trace, int, 0644);
MODULE_PARM_DESC(t32_trace, "log every ioctl (S1 bring-up)");

#define T32_MAX_VI	1

struct t32_alloc {
	struct list_head node;
	void *kva;
	u32 pa;
	u32 size;
	unsigned int order;
};

struct t32_vi {
	struct i2c_client *client;
	void *sd;			/* struct tx_isp_sensor (sd at 0) */
	struct module *owner;
	struct t32_sensor_reginfo info;
	int registered;
	int input_on;			/* S_INPUT enable */
	int streaming;
	u32 width, height;
	u32 isp_mem_pa, isp_mem_size;
	u32 ipc_mem_pa, ipc_mem_size;
};

static struct t32_core {
	struct mutex lock;
	struct t32_vi vi[T32_MAX_VI];
	struct list_head allocs;
	void *pending_sd;		/* set by tx_isp_subdev_init during probe */
	u32 tiziano_pa;
	u32 default_bin;
	unsigned int ioctls;
	struct proc_dir_entry *proc;
} core;

/* ------------------------------------------------------------------ */
/* subdevices: the sensor modules call these from their i2c probe     */

static int t32_subdev_notify(void *module, unsigned int what, void *data)
{
	/* module is &sd->module, i.e. sd itself */
	if (what == T32_EVENT_SYNC_SENSOR_ATTR && data) {
		u32 w = T32_AT(data, T32_VIDEO_MBUS_WIDTH, u32);
		u32 h = T32_AT(data, T32_VIDEO_MBUS_HEIGHT, u32);

		isp_printf(0, "tx-isp-t32: sensor attr sync %ux%u\n", w, h);
		return 0;
	}
	isp_printf(0, "tx-isp-t32: subdev notify %#x\n", what);
	return 0;
}

int tx_isp_subdev_init(struct platform_device *pdev, void *sd, void *ops)
{
	if (!sd)
		return -EINVAL;
	T32_AT(sd, T32_SD_OPS, void *) = ops;
	T32_AT(sd, T32_SD_MODULE_NAME, const char *) =
		pdev && pdev->name ? pdev->name : "sensor";
	T32_AT(sd, T32_SD_MODULE_NOTIFY, void *) = (void *)t32_subdev_notify;
	T32_AT(sd, T32_SD_MODULE_PARENT, void *) = &core;
	core.pending_sd = sd;
	return 0;
}
EXPORT_SYMBOL(tx_isp_subdev_init);

void tx_isp_subdev_deinit(void *sd)
{
	int i;

	if (!sd)
		return;
	/*
	 * No core.lock here: the sensor's i2c remove runs this from inside
	 * RELEASE_SENSOR and module exit, which hold the lock.
	 */
	for (i = 0; i < T32_MAX_VI; i++)
		if (core.vi[i].sd == sd) {
			core.vi[i].sd = NULL;
			core.vi[i].registered = 0;
		}
	if (core.pending_sd == sd)
		core.pending_sd = NULL;
	T32_AT(sd, T32_SD_OPS, void *) = NULL;
	T32_AT(sd, T32_SD_MODULE_NOTIFY, void *) = NULL;
}
EXPORT_SYMBOL(tx_isp_subdev_deinit);

/* the sensor module is going away: forget every reference into it */
void t32_core_sensor_driver_gone(struct i2c_driver *drv)
{
	int i;

	mutex_lock(&core.lock);
	for (i = 0; i < T32_MAX_VI; i++) {
		struct t32_vi *vi = &core.vi[i];

		if (vi->client && vi->client->dev.driver == &drv->driver) {
			vi->sd = NULL;
			vi->registered = 0;
			vi->streaming = 0;
		}
	}
	mutex_unlock(&core.lock);
}

typedef int (*t32_sd_fn)(void *sd, void *arg);

/* ops->group->fn of a sensor subdevice, or NULL */
static t32_sd_fn t32_sd_op(void *sd, unsigned int group, unsigned int fn)
{
	void *ops, *grp;

	if (!sd)
		return NULL;
	ops = T32_AT(sd, T32_SD_OPS, void *);
	if (!ops)
		return NULL;
	grp = T32_AT(ops, group, void *);
	if (!grp)
		return NULL;
	return T32_AT(grp, fn, t32_sd_fn);
}

/* ------------------------------------------------------------------ */
/* sensor registration                                                */

static void t32_vi_release(struct t32_vi *vi)
{
	if (vi->sd && vi->registered)
		tx_isp_sinfo_sensor_unbind(vi->sd, vi->owner);
	if (vi->client)
		i2c_unregister_device(vi->client);
	memset(vi, 0, sizeof(*vi));
}

static int t32_register_sensor(struct t32_vi *vi, const struct t32_sensor_reginfo *info)
{
	struct i2c_board_info bi;
	struct i2c_adapter *adap;
	struct i2c_client *client;
	char chip[T32_CHIP_IDENT_SIZE];
	t32_sd_fn ident;
	void *sd;
	int ret;

	if (vi->registered) {
		if (!strncmp(vi->info.name, info->name, sizeof(info->name)))
			return 0;
		return -EBUSY;
	}
	if (info->cbus_type != 1) {
		isp_printf(2, "tx-isp-t32: sensor %.32s: only I2C sensors in S1 (cbus %u)\n",
			   info->name, info->cbus_type);
		return -EINVAL;
	}
	adap = i2c_get_adapter(info->i2c.i2c_adapter_id);
	if (!adap) {
		isp_printf(2, "tx-isp-t32: no i2c adapter %d\n", info->i2c.i2c_adapter_id);
		return -ENODEV;
	}
	memset(&bi, 0, sizeof(bi));
	strlcpy(bi.type, info->i2c.type, sizeof(bi.type));
	bi.addr = info->i2c.addr;
	core.pending_sd = NULL;
	client = i2c_new_device(adap, &bi);
	i2c_put_adapter(adap);
	if (!client) {
		isp_printf(2, "tx-isp-t32: cannot add i2c client %s@%#x\n", bi.type, bi.addr);
		return -EBUSY;
	}
	sd = i2c_get_clientdata(client);
	if (!sd || !client->dev.driver) {
		isp_printf(2, "tx-isp-t32: no driver bound to %s (sensor module loaded?)\n", bi.type);
		i2c_unregister_device(client);
		return -ENODEV;
	}
	vi->client = client;
	vi->sd = sd;
	vi->owner = client->dev.driver->owner;
	vi->info = *info;

	/* the sensor reads its wiring from its own copy of the registration */
	memcpy((char *)sd + T32_SENSOR_INFO, info, sizeof(*info));
	T32_AT(sd, T32_SENSOR_VIDEO + T32_VIDEO_INFO, void *) = (char *)sd + T32_SENSOR_INFO;

	ident = t32_sd_op(sd, T32_OPS_CORE, T32_CORE_G_CHIP_IDENT);
	memset(chip, 0, sizeof(chip));
	ret = ident ? ident(sd, chip) : -ENOIOCTLCMD;
	if (ret) {
		isp_printf(2, "tx-isp-t32: sensor %s not detected (%d)\n", bi.type, ret);
		vi->sd = NULL;
		t32_vi_release(vi);
		return -ENODEV;
	}
	vi->registered = 1;
	vi->width = T32_AT(sd, T32_SENSOR_VIDEO + T32_VIDEO_MBUS_WIDTH, u32);
	vi->height = T32_AT(sd, T32_SENSOR_VIDEO + T32_VIDEO_MBUS_HEIGHT, u32);
	tx_isp_sinfo_sensor_bind(sd, vi->owner);
	isp_printf(1, "tx-isp-t32: sensor %.32s registered (%s @ i2c%d 0x%02x, %ux%u)\n",
		   info->name, chip, info->i2c.i2c_adapter_id, info->i2c.addr,
		   vi->width, vi->height);
	return 0;
}

static int t32_sensor_stream(struct t32_vi *vi, int on)
{
	struct { s32 enable, vinum; } arg = { on, 0 };
	t32_sd_fn init, stream;
	int ret = 0;

	if (!vi->registered || !vi->sd)
		return -ENODEV;
	init = t32_sd_op(vi->sd, T32_OPS_CORE, T32_CORE_INIT);
	stream = t32_sd_op(vi->sd, T32_OPS_VIDEO, T32_VIDEO_S_STREAM);
	if (on) {
		if (init)
			ret = init(vi->sd, &arg);
		if (!ret && stream)
			ret = stream(vi->sd, &arg);
		if (!ret)
			t32_hw_stream_on();
	} else {
		t32_hw_stream_off();
		if (stream)
			ret = stream(vi->sd, &arg);
		if (init)
			init(vi->sd, &arg);
	}
	if (!ret)
		vi->streaming = on;
	return ret;
}

/* ------------------------------------------------------------------ */
/* MEMORY_MALLOC / FREE: physically contiguous buffers libimp maps     */
/* through /dev/mem (IQ bins for SET_TIZIANO_PAR)                      */

static struct t32_alloc *t32_alloc_find_kva(u32 kva)
{
	struct t32_alloc *a;

	list_for_each_entry(a, &core.allocs, node)
		if ((u32)(unsigned long)a->kva == kva)
			return a;
	return NULL;
}

static struct t32_alloc *t32_alloc_find_pa(u32 pa)
{
	struct t32_alloc *a;

	list_for_each_entry(a, &core.allocs, node)
		if (pa >= a->pa && pa < a->pa + a->size)
			return a;
	return NULL;
}

static int t32_malloc(struct t32_buf_info *bi)
{
	struct t32_alloc *a;
	unsigned long p;

	if (!bi->size || bi->size > (16U << 20))
		return -EINVAL;
	a = kzalloc(sizeof(*a), GFP_KERNEL);
	if (!a)
		return -ENOMEM;
	a->order = get_order(bi->size);
	p = __get_free_pages(GFP_KERNEL | __GFP_ZERO, a->order);
	if (!p) {
		kfree(a);
		return -ENOMEM;
	}
	a->kva = (void *)p;
	a->pa = virt_to_phys(a->kva);
	a->size = bi->size;
	list_add_tail(&a->node, &core.allocs);
	bi->word0 = (u32)p;
	bi->word1 = a->pa;
	return 0;
}

static int t32_free(const struct t32_buf_info *bi)
{
	struct t32_alloc *a = t32_alloc_find_kva(bi->word0);

	if (!a)
		return -EINVAL;
	if (core.tiziano_pa >= a->pa && core.tiziano_pa < a->pa + a->size)
		core.tiziano_pa = 0;
	list_del(&a->node);
	free_pages((unsigned long)a->kva, a->order);
	kfree(a);
	return 0;
}

static void t32_free_all(void)
{
	struct t32_alloc *a, *n;

	list_for_each_entry_safe(a, n, &core.allocs, node) {
		list_del(&a->node);
		free_pages((unsigned long)a->kva, a->order);
		kfree(a);
	}
	core.tiziano_pa = 0;
}

static int t32_set_tiziano_par(u32 pa)
{
	struct t32_alloc *a = t32_alloc_find_pa(pa);
	const u32 *w;

	if (!a)
		return -EINVAL;
	core.tiziano_pa = pa;
	/* libimp wrote the bin through an uncached /dev/mem mapping */
	w = (const u32 *)CKSEG1ADDR(pa);
	isp_printf(0, "tx-isp-t32: IQ parameters at pa %#x: %08x %08x %08x %08x \n",
		   pa, w[0], w[1], w[2], w[3]);
	return 0;
}

/* ------------------------------------------------------------------ */
/* /dev/tx-isp                                                        */

#define T32_GET(arg, var) (copy_from_user(&(var), (void __user *)(arg), sizeof(var)) ? -EFAULT : 0)
#define T32_PUT(arg, var) (copy_to_user((void __user *)(arg), &(var), sizeof(var)) ? -EFAULT : 0)

static long t32_isp_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct t32_vi *vi = &core.vi[0];
	struct t32_buf_info bi;
	struct t32_initarg ia;
	u32 v;
	long ret = 0;

	mutex_lock(&core.lock);
	core.ioctls++;
	switch (cmd) {
	case T32_IOC_DRIVER_VERSION: {
		char ver[64];

		memset(ver, 0, sizeof(ver));
		strlcpy(ver, driver_soc, 32);
		strlcpy(ver + 32, driver_version, 32);
		ret = T32_PUT(arg, ver);
		break;
	}
	case T32_IOC_REGISTER_SENSOR: {
		struct t32_sensor_reginfo info;

		ret = T32_GET(arg, info);
		if (!ret)
			ret = t32_register_sensor(vi, &info);
		break;
	}
	case T32_IOC_RELEASE_SENSOR:
		if (vi->streaming)
			t32_sensor_stream(vi, 0);
		t32_vi_release(vi);
		break;
	case T32_IOC_DEFAULT_BIN: {
		char *buf = kzalloc(T32_DEFAULT_BIN_SIZE, GFP_KERNEL);

		if (!buf) {
			ret = -ENOMEM;
			break;
		}
		strlcpy(buf + T32_DEFAULT_BIN_VER, bin_version,
			T32_DEFAULT_BIN_SOC - T32_DEFAULT_BIN_VER);
		strlcpy(buf + T32_DEFAULT_BIN_SOC, driver_soc,
			T32_DEFAULT_BIN_SIZE - T32_DEFAULT_BIN_SOC);
		ret = copy_to_user((void __user *)arg, buf, T32_DEFAULT_BIN_SIZE) ? -EFAULT : 0;
		kfree(buf);
		core.default_bin++;
		break;
	}
	case T32_IOC_MEMORY_MALLOC:
		ret = T32_GET(arg, bi);
		if (!ret)
			ret = t32_malloc(&bi);
		if (!ret)
			ret = T32_PUT(arg, bi);
		break;
	case T32_IOC_MEMORY_FREE:
		ret = T32_GET(arg, bi);
		if (!ret)
			ret = t32_free(&bi);
		break;
	case T32_IOC_SET_TIZIANO_PAR:
		ret = T32_GET(arg, v);
		if (!ret)
			ret = t32_set_tiziano_par(v);
		break;
	case T32_IOC_ENUMINPUT: {
		/* {index, name[32]}: libimp walks the inputs and matches the name */
		struct { u32 index; char name[32]; } in;

		ret = T32_GET(arg, v);
		if (ret)
			break;
		if (v >= T32_MAX_VI || !core.vi[v].registered) {
			ret = -EINVAL;
			break;
		}
		memset(&in, 0, sizeof(in));
		in.index = v;
		strlcpy(in.name, core.vi[v].info.name, sizeof(in.name));
		ret = T32_PUT(arg, in);
		break;
	}
	case T32_IOC_S_INPUT:
		ret = T32_GET(arg, ia);
		if (ret)
			break;
		if (ia.enable) {
			if (!vi->registered) {
				ret = -ENODEV;
				break;
			}
			vi->width = T32_AT(vi->sd, T32_SENSOR_VIDEO + T32_VIDEO_MBUS_WIDTH, u32);
			vi->height = T32_AT(vi->sd, T32_SENSOR_VIDEO + T32_VIDEO_MBUS_HEIGHT, u32);
			if (!vi->input_on) {
				void *attr = T32_AT(vi->sd, T32_SENSOR_VIDEO + T32_VIDEO_ATTR, void *);

				ret = attr ? t32_hw_input_setup(attr, vi->width, vi->height) : -ENODEV;
				if (ret)
					break;
			}
			vi->input_on = 1;
			ia.vinum = (s32)((vi->width << 16) | vi->height);
		} else {
			vi->input_on = 0;
			ia.vinum = 0;
		}
		ret = T32_PUT(arg, ia);
		break;
	case T32_IOC_GET_ISP_IPC_MEM_INFO:
		ret = T32_GET(arg, bi);
		if (!ret) {
			bi.size = 0;		/* no IPC (RISC-V) memory in S1 */
			ret = T32_PUT(arg, bi);
		}
		break;
	case T32_IOC_SET_ISP_IPC_MEM_INFO:
		ret = T32_GET(arg, bi);
		if (!ret) {
			vi->ipc_mem_pa = bi.word1;
			vi->ipc_mem_size = bi.size;
		}
		break;
	case T32_IOC_GET_ISP_MEM_INFO:
		ret = T32_GET(arg, bi);
		if (ret)
			break;
		if (!vi->width || !vi->height) {
			ret = -ENODEV;
			break;
		}
		bi.size = t32_isp_mem_size(vi->width, vi->height, isp_memopt, 0, 0);
		ret = bi.size ? T32_PUT(arg, bi) : -EINVAL;
		break;
	case T32_IOC_SET_ISP_MEM_INFO:
		ret = T32_GET(arg, bi);
		if (!ret) {
			vi->isp_mem_pa = bi.word1;
			vi->isp_mem_size = bi.size;
		}
		break;
	case T32_IOC_G_INPUT:
	case T32_IOC_CREATE_SUBDEV_LINKS:
	case T32_IOC_DESTROY_SUBDEV_LINKS:
		ret = T32_GET(arg, ia);
		break;
	case T32_IOC_LINKS_STREAMON:
	case T32_IOC_LINKS_STREAMOFF:
		/* the pipeline links come with the frame path (S2) */
		ret = T32_GET(arg, ia);
		if (!ret)
			ret = T32_PUT(arg, ia);
		break;
	case T32_IOC_STREAMON:
		ret = T32_GET(arg, ia);
		if (!ret)
			ret = t32_sensor_stream(vi, 1);
		break;
	case T32_IOC_STREAMOFF:
		ret = T32_GET(arg, ia);
		if (!ret && vi->streaming)
			ret = t32_sensor_stream(vi, 0);
		break;
	default:
		ret = -ENOTTY;
		break;
	}
	if (t32_trace || ret)
		isp_printf(ret ? 1 : 0, "tx-isp-t32: ioctl %#x -> %ld\n", cmd, ret);
	mutex_unlock(&core.lock);
	return ret;
}

static int t32_isp_release(struct inode *inode, struct file *file)
{
	return 0;
}

static const struct file_operations t32_isp_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = t32_isp_ioctl,
	.release = t32_isp_release,
};

static struct miscdevice t32_isp_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "tx-isp",
	.fops = &t32_isp_fops,
};

/* ------------------------------------------------------------------ */
/* /dev/isp-m0 (tuning), /dev/misc-ivdc, /dev/framechanN              */

/*
 * Sensor frame rate (isp-m0 tuning id 0x08000070, value num << 16 | den), as
 * the vendor tisp does it: GET answers the sensor's current rate, SET hands
 * the rate to the sensor driver (TX_ISP_EVENT_SENSOR_FPS), which reprograms
 * its frame length over I2C and updates video.fps.
 */
static long t32_sensor_fps_set(struct t32_vi *vi, u32 fps)
{
	struct { s32 vinum, value; } sv = { 0, (s32)fps };
	int (*ioctl)(void *sd, unsigned int cmd, void *arg);
	void *ops, *grp;
	long ret;

	if (!vi->registered || !vi->sd)
		return -ENODEV;
	if (!(fps >> 16) || !(fps & 0xffff))
		return -EINVAL;
	ops = T32_AT(vi->sd, T32_SD_OPS, void *);
	grp = ops ? T32_AT(ops, T32_OPS_SENSOR, void *) : NULL;
	ioctl = grp ? T32_AT(grp, T32_SENSOR_OPS_IOCTL, void *) : NULL;
	if (!ioctl)
		return -ENOIOCTLCMD;
	ret = ioctl(vi->sd, T32_EVENT_SENSOR_FPS, &sv);
	isp_printf(ret ? 2 : 1, "tx-isp-t32: sensor fps %u/%u -> %ld (now %#x)\n",
		   fps >> 16, fps & 0xffff, ret,
		   T32_AT(vi->sd, T32_SENSOR_VIDEO + T32_VIDEO_FPS, u32));
	return ret ? -EINVAL : 0;
}

/* sensor exposure (TX_ISP_EVENT_SENSOR_EXPO, T32 0x02000017): value =
 * analog gain index << 16 | integration time in lines, as tisp hands it */
int t32_core_sensor_expo(u32 packed)
{
	struct t32_vi *vi = &core.vi[0];
	struct { s32 vinum, value; } sv = { 0, (s32)packed };
	int (*ioctl)(void *sd, unsigned int cmd, void *arg);
	void *ops, *grp;

	if (!vi->registered || !vi->sd)
		return -ENODEV;
	ops = T32_AT(vi->sd, T32_SD_OPS, void *);
	grp = ops ? T32_AT(ops, T32_OPS_SENSOR, void *) : NULL;
	ioctl = grp ? T32_AT(grp, T32_SENSOR_OPS_IOCTL, void *) : NULL;
	if (!ioctl)
		return -ENOIOCTLCMD;
	return ioctl(vi->sd, T32_EVENT_SENSOR_EXPO, &sv);
}

/* the sensor's frame length (VTS) from its attributes, 0 when unknown */
u32 t32_core_sensor_vts(void)
{
	struct t32_vi *vi = &core.vi[0];
	void *attr;

	if (!vi->registered || !vi->sd)
		return 0;
	attr = T32_AT(vi->sd, T32_SENSOR_VIDEO + T32_VIDEO_ATTR, void *);
	return attr ? T32_AT(attr, T32_ATTR_TOTAL_HEIGHT, u16) : 0;
}

static long t32_m0_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct t32_vi *vi = &core.vi[0];
	u32 w[4];
	long ret = -ENOTTY;

	if (cmd == T32_IOC_TUNING_DEFAULT) {
		if (copy_from_user(w, (void __user *)arg, sizeof(w)))
			return -EFAULT;
		mutex_lock(&core.lock);
		if (w[2] == T32_TUNING_ID_SENSOR_FPS && w[1] == T32_TUNING_DIR_GET) {
			if (vi->registered && vi->sd) {
				w[3] = T32_AT(vi->sd, T32_SENSOR_VIDEO + T32_VIDEO_FPS, u32);
				ret = copy_to_user((void __user *)arg, w, sizeof(w)) ? -EFAULT : 0;
			} else {
				ret = -ENODEV;
			}
		} else if (w[2] == T32_TUNING_ID_SENSOR_FPS && w[1] == T32_TUNING_DIR_SET) {
			ret = t32_sensor_fps_set(vi, w[3]);
		}
		mutex_unlock(&core.lock);
		if (t32_trace || ret)
			isp_printf(ret ? 1 : 0, "tx-isp-t32: isp-m0 tuning %s id %#x %#x -> %ld\n",
				   w[1] ? "get" : "set", w[2], w[3], ret);
		return ret;
	}
	isp_printf(1, "tx-isp-t32: isp-m0 ioctl %#x not handled\n", cmd);
	return ret;
}

static const struct file_operations t32_m0_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = t32_m0_ioctl,
};

static struct miscdevice t32_m0_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "isp-m0",
	.fops = &t32_m0_fops,
};

static long t32_ivdc_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	u32 v = 0;

	if (cmd == T32_IOC_IVDC_GET_DIRECT)
		return copy_to_user((void __user *)arg, &v, sizeof(v)) ? -EFAULT : 0;
	isp_printf(1, "tx-isp-t32: misc-ivdc ioctl %#x not handled\n", cmd);
	return -ENOTTY;
}

static const struct file_operations t32_ivdc_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = t32_ivdc_ioctl,
};

static struct miscdevice t32_ivdc_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "misc-ivdc",
	.fops = &t32_ivdc_fops,
};

/* ------------------------------------------------------------------ */
/* /proc/jz/isp                                                       */

extern struct proc_dir_entry *jz_proc_mkdir(char *s);

static int t32_proc_show(struct seq_file *m, void *v)
{
	struct t32_vi *vi = &core.vi[0];

	seq_printf(m, "tx-isp-t32 (open, S3: frames on 3 channels, sensor fps, no tisp)\n");
	seq_printf(m, "sensor: %s registered %d input %d streaming %d %ux%u\n",
		   vi->registered ? vi->info.name : "-", vi->registered,
		   vi->input_on, vi->streaming, vi->width, vi->height);
	seq_printf(m, "isp mem pa %#x size %#x, iq pa %#x, ioctls %u, memopt %u\n",
		   vi->isp_mem_pa, vi->isp_mem_size, core.tiziano_pa, core.ioctls,
		   isp_memopt);
	seq_printf(m, "irqs isp %u vic %u frame ends %u stream ons %u\n",
		   t32_hw_stats.isp_irqs, t32_hw_stats.vic_irqs,
		   t32_hw_stats.frame_ends, t32_hw_stats.stream_ons);
	seq_printf(m, "statistics: inits %u, irqs ae %u ae-hist %u awb %u\n",
		   t32_hw_stats.stats_inits, t32_hw_stats.ae_irqs, t32_hw_stats.ae_hist_irqs,
		   t32_hw_stats.awb_irqs);
	seq_printf(m, "bring-up controller (not the vendor AE): steps %u, mean %u/16, it %u lines\n",
		   t32_hw_stats.bringup_steps, t32_hw_stats.bringup_mean16, t32_hw_stats.bringup_it);
	seq_printf(m, "sensor fps %#x, stream-on list runs %u (last %u words) timeouts %u\n",
		   t32_core_sensor_fps(), t32_rcfg_runs, t32_rcfg_last_len, t32_rcfg_timeouts);
	t32_fs_show(m);
	return 0;
}

u32 t32_core_sensor_fps(void)
{
	struct t32_vi *vi = &core.vi[0];

	if (!vi->registered || !vi->sd)
		return 0;
	return T32_AT(vi->sd, T32_SENSOR_VIDEO + T32_VIDEO_FPS, u32);
}

/* the IQ bin libimp loaded (SET_TIZIANO_PAR): uncached view and the bytes
 * up to the end of its buffer; -ENOENT when there is none */
int t32_core_iq_bin(const u8 **bin, u32 *bytes)
{
	struct t32_alloc *a;

	if (!core.tiziano_pa)
		return -ENOENT;
	list_for_each_entry(a, &core.allocs, node)
		if (core.tiziano_pa >= a->pa && core.tiziano_pa < a->pa + a->size) {
			*bin = (const u8 *)CKSEG1ADDR(core.tiziano_pa);
			*bytes = a->pa + a->size - core.tiziano_pa;
			return 0;
		}
	return -ENOENT;
}

/* the sensor's media bus code (input_mbus_fmt) of the running input */
int t32_core_sensor_mbus(u32 *code)
{
	struct t32_vi *vi = &core.vi[0];

	if (!vi->registered || !vi->input_on)
		return -ENODEV;
	*code = T32_AT(vi->sd, T32_SENSOR_VIDEO + T32_VIDEO_MBUS_CODE, u32);
	return 0;
}

/* the MSCA input: the sensor picture of the running input */
int t32_core_sensor_size(u32 *w, u32 *h)
{
	struct t32_vi *vi = &core.vi[0];

	if (!vi->registered || !vi->input_on || !vi->width || !vi->height)
		return -ENODEV;
	*w = vi->width;
	*h = vi->height;
	return 0;
}

/* the MDNS compression setting (1/1000) */
unsigned int t32_core_memopt(void)
{
	return isp_memopt;
}

static int t32_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, t32_proc_show, NULL);
}

static const struct file_operations t32_proc_fops = {
	.owner = THIS_MODULE,
	.open = t32_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};

/* ------------------------------------------------------------------ */

int tx_isp_t32_core_init(void)
{
	int ret, i;

	mutex_init(&core.lock);
	INIT_LIST_HEAD(&core.allocs);

	ret = misc_register(&t32_isp_misc);
	if (ret)
		return ret;
	ret = misc_register(&t32_m0_misc);
	if (ret)
		goto err_m0;
	ret = misc_register(&t32_ivdc_misc);
	if (ret)
		goto err_ivdc;
	ret = t32_fs_init();
	if (ret)
		goto err_fc;
	ret = t32_hw_init();
	if (ret)
		goto err_hw;
	core.proc = jz_proc_mkdir("isp");
	if (core.proc) {
		proc_create("isp-m0", 0444, core.proc, &t32_proc_fops);
		proc_create("isp-w02", 0444, core.proc, &t32_proc_fops);
	}
	pr_info("tx-isp-t32: open driver loaded (S3: 3 channels, sensor fps, no tisp) (memopt %u)\n", isp_memopt);
	return 0;

err_hw:
	t32_fs_exit();
err_fc:
	misc_deregister(&t32_ivdc_misc);
err_ivdc:
	misc_deregister(&t32_m0_misc);
err_m0:
	misc_deregister(&t32_isp_misc);
	return ret;
}

void tx_isp_t32_core_exit(void)
{
	int i;

	t32_fs_stop_all();
	mutex_lock(&core.lock);
	for (i = 0; i < T32_MAX_VI; i++) {
		if (core.vi[i].streaming)
			t32_sensor_stream(&core.vi[i], 0);
		t32_vi_release(&core.vi[i]);
	}
	t32_free_all();
	mutex_unlock(&core.lock);
	if (core.proc) {
		remove_proc_entry("isp-m0", core.proc);
		remove_proc_entry("isp-w02", core.proc);
		proc_remove(core.proc);
	}
	t32_hw_exit();
	t32_fs_exit();
	misc_deregister(&t32_ivdc_misc);
	misc_deregister(&t32_m0_misc);
	misc_deregister(&t32_isp_misc);
}
