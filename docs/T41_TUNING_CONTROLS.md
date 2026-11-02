# T41 tuning controls (isp-m0, envelope `{channel, is_get, id, ptr}`)

Controls added on top of the AE/AWB/BCSH/flip set. Stock reference:
`tx_isp_core_ops_s_ctrl` / `g_ctrl` of the vendor `tx-isp-t41.ko`; the wire
structures below are what that module copies from user space. OpenIMP builds
them (`src/t40/openimp_p3_controls.c`); the vendor libimp 1.2.5/1.2.6 sends a
different CCM/CSC payload (Q10/10-bit words, 12-word CSC) than this kernel
reads (Q16 words, 92-byte CSC table), so for those two the module follows the
kernel, not the library.

| id | function | wire | notes |
|---|---|---|---|
| 0x08000072 | Set/GetModuleControl | u32 key | 25-bit TOP bypass word, 1 = bypass. Bits kept: the upper 7 reserved bits. Accepted: LSC 1, DPC 4, ADR 7, CCM 9, GAMMA 10, DEFOG 11, MDNS 13, YDNS 14, BCSH 15, YSP 17, SDNS 18; a key that changes any other bit gets -EOPNOTSUPP. A bit that differs from the calibrated bypass byte is an override that the modules' own calibration restore keeps (`t41_modctl_mask/value`). MDNS leaves bypass only when its buffers exist. DEFOG may only be bypassed (clearing bit 11 gets -EOPNOTSUPP: the per-frame defog algorithm is not recovered and the block stays bypassed since init). |
| 0x08000025 | Set/GetGammaAttr | u32 type + u16[129] (264 B) | type 0 = exposure-driven calibration curve, 1 sRGB, 2 Rec709, 3 HDR, 4 user (points <= 4095). Types 1..4 fix the curve (strength 255, tone worker leaves it alone); get returns the stored request with the live curve. |
| 0x08000080 | Set/GetCCMAttr | u8 manual, u8 sat, 2 pad, s32[9] Q16 (40 B) | ManualEn replaces the selected matrix with the rounded Q10 user matrix; SatEn = 0 skips the saturation transform. The matrix is applied in the CCM block and in the BCSH matrix (the shipped calibrations may carry the colour correction in BCSH; stock `tisp_bcsh_api_set_ccm` only stores it). |
| 0x08000096 | Set/GetISPCSCAttr | s32 version + s32[9] RGB->YUV Q16 + 2 byte words + s32[9] YUV->RGB Q16 + 2 words (92 B) | versions 0..5 presets (BT601 full/limited, BT709 full/limited, BT2020 full/limited), 6 = user table. Re-programs the CSC registers and refreshes CCM and BCSH. |
| 0x080000a4 | Set/GetModule_Ratio | 16 x {u32 en, u8 ratio} | SINTER, TEMPER as before; DRC (scales the ADR strength fields from the pristine copy), DPC (long-bank thresholds). DEFOG is still -EOPNOTSUPP for a non-neutral request. |
| 0x08000023 | Set/GetAeExprInfo | 232 B | additionally: AeMode (freeze), manual integration time (lines or microseconds, unit field) and manual analog gain (x1024), sensor digital gain cap (accepted and reported; the open AE only allocates the sensor analog gain). Manual sensor/ISP digital gain and minimum caps stay -EOPNOTSUPP. |

| 0x08000077 | Set/GetAutoZoom | s32 en[3], left[3], top[3], width[3], height[3] (60 B) | input crop window per output (stock `tisp_s_autozoom_control`); enabled windows outside the sensor are -EINVAL. Streaming outputs are only reprogrammed with `t41_msca_cfg_update=2` + `stop_disable=1` and output <= 768x432, otherwise stored for the next start. Branch `claude/t41-zoom-mask`, see `driver/t41/README.md` "MSCA zoom, mask and scaler level". |
| 0x08000074 | Set/GetMaskBlock | u8 chx, pinum, en, pad, u16 top, left, w, h, s32 type, rgb, yuv (24 B) | 3 x 4 blocks, written through the MSCA shadow port like stock `tisp_msca_set_mask`; same live/stored rule. GET reports en 0 (stock). |
| 0x080000a6 | SetScalerLv | u8 chx, s32 mode, u8 level (12 B) | FIXED_WEIGHT / FITTING_CURVE level 0..128 (`0xf0708 + ch * 8`); the level is kept across reloads (stock drops it). Same live/stored rule. |
| 0x08000016 | Set/GetAwbConvergeStep | u32 awb_step[5] (20 B) | native AWB params: step 0 (1..15, else -EINVAL) at +0xcd6, steps 1..4 at +0x0c..+0x18 (stock `tisp_awb_set/get_converge_step`). Used by the open AWB. |
| 0x08000015 | Set/GetAwbCtTrendOffset | u16 thres_hm, thres_lm, 3 x {u32 rgain, bgain} (28 B) | native AWB params +0xc0c/+0xc10 and +0xbf4..+0xc0b, AWB refresh flag set (stock `tisp_awb_api_set/get_ct_trend_offset`). |
| 0x08000028 | Set/GetAeConvergeStep | u16 ae_step[4] (8 B) | AE params +0x664/+0x668 (u32) and +0x75c/+0x75e (u16) like stock `tisp_ae_set/get_converge_step`; a zero step is -EINVAL. Only the recovered stock AE (`t41_safe_ae_controller=0`) reads them; the default bounded AE keeps its own step (stored value). |
| 0x08000038 | GetAeEvList | u32 enable, pad, u64 ev[15] (128 B) | EV knots of the AE params (+0x5d0), the table the open AE target interpolation uses; enable reported as 1 (stock: uninitialised stack). |
| 0x08000039 | GetAeAtList | u32 enable, pad, u64 at[15] (128 B) | target luma per EV knot (AE params +0x76e, u16), as above. |
| 0x08000063 | Set/GetTmoCurve | u8 transfer_flag, u8 id, u16 value[201] (404 B) | curve id 0..9 of the TMO params (the curves the per-frame TMO map interpolates); values > 8191 or id >= 10 are -EINVAL. Set takes effect at the next mapped frame (stock rebuilt the TMO registers at once). GET uses the caller's id (stock read it from uninitialised stack). |
| 0x08000000 | Set/GetStatisConfig | AE 24 B, AWB 20 B, AF 28 B (72 B) | record at `tisp_tattr`+568 (stock defaults). SET: an enabled AWB part moves the AWB zone grid through the native AWB (location check, -EBUSY for a geometry change while streaming); the AE histogram thresholds and the AF part are stored only (stock reprogrammed the global-statistics block from an uninitialised buffer; no AF on this build). Enables > 1 are -EINVAL. |
| 0x08000091 | WaitFrameDone | u32 timeout, pad, u64 cnt, u32 irqtype, pad (24 B), get | waits for the next ch0 frame done (`isp_frame_done_wait`) and returns the frame counter; as stock the timeout is in jiffies (10 ms at HZ=100); beyond stock a timeout returns -ETIMEDOUT and a signal -ERESTARTSYS (stock returns 0 for both), the counter is filled in every case; capped at 60 s; runs without the tuning mutex. Frames are only counted while channel 0 runs: a streamer that stops its main channel when no client is connected (the application) makes every wait time out. |

Not routed yet (-EOPNOTSUPP): WdrOutputMode (0x08000054). Not implemented (-EPERM): GetAeBv (0x080000b3) and GetAEFlickerFlag (0x0800003a): both report vendor-AE internal state (BV from the stock AE zone math, the stock flicker detector) that the default open AE does not maintain.
