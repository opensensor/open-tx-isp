# open-tx-isp: where the driver differs from the vendor module

Items where the open kernel driver deliberately behaves differently from the
vendor `tx-isp-*.ko` (not bug fixes, which are in [CHANGELOG.md](../CHANGELOG.md)).
Each item names the switch that restores the vendor behaviour where one exists.

| Change | SoC | Default | Vendor behaviour back | Why | Status |
|---|---|---|---|---|---|
| No `dump_stack()` after level >= 2 ISP messages (`isp_printf`) | T21 | off | module parameter `warn_stack=1` (runtime, `/sys/module/tx_isp_t21/parameters/warn_stack`) | The vendor prints a full stack after every warning/error message: a console flood of about 100 ms per stack at 115200 baud, in ISP paths. The message itself is unchanged. | 2026-11-06, device A/B on cam-D (T21) |
| Bring-up trace parameters not built (`t20_trace`, `t20_runtime_trace` / `t10_runtime_trace`, `t20_trace_events`) | T10, T20 | not built | build with `TX_ISP_TRACE=y` | Not vendor parameters (our bring-up traces); about -10 KiB module RAM. Kernel 3.10 refuses to load a module given an unknown parameter, so no load script may pass them; none does (checked 2026-11-06: OpenIMP, the streamer, the thingino package and user overlay, `/etc/modules.d` on the T10/T20 test cameras). | 2026-11-06, device A/B on T10 and T20 |
| A tuning (IQ) bin is checked before it replaces the tables in use (version, header flags, both CRCs, tables in bounds, firmware table space; `tx-isp-param-validate.h`) | T10, T20 | on | none (no switch) | The vendor loader points the day/night tables into the new file before checking it, so a rejected or truncated file leaves tables that point into freed or bad data. Now a rejected file keeps the tables that were in use. Host test `tx_isp_t20_param_validate_test`. | 2026-11-07 (#231 L6), device re-init twice on T10 and T20 by runtime module swap |
