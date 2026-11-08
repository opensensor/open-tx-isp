/*
 * The only symbols tx-isp-t31.ko exports (size: every other EXPORT_SYMBOL in
 * the driver is a no-op, see include/tx_isp_kernel_compat.h, so
 * --gc-sections drops what nothing else references).
 *
 * The list is driver/isp_imports.txt for t31: what the sensor drivers and
 * the other kernel modules (avpu, audio, motor, ...) of thingino and the
 * ingenic-sdk import.  tests/check_isp_exports.sh fails the build when a
 * known importer needs a symbol that is missing here.  Add a symbol here
 * (and to driver/isp_imports.txt) before a new module may use it.
 * TX_ISP_T31_EXPORT_ALL=y builds the old full export table.
 */
TX_ISP_T31_EXPORT(isp_printf)
TX_ISP_T31_EXPORT(private_capable)
TX_ISP_T31_EXPORT(private_clk_disable)
TX_ISP_T31_EXPORT(private_clk_enable)
TX_ISP_T31_EXPORT(private_clk_get)
TX_ISP_T31_EXPORT(private_clk_put)
TX_ISP_T31_EXPORT(private_clk_set_rate)
TX_ISP_T31_EXPORT(private_driver_get_interface)
TX_ISP_T31_EXPORT(private_gpio_direction_output)
TX_ISP_T31_EXPORT(private_gpio_free)
TX_ISP_T31_EXPORT(private_gpio_request)
TX_ISP_T31_EXPORT(private_i2c_add_driver)
TX_ISP_T31_EXPORT(private_i2c_add_driver_addr)
TX_ISP_T31_EXPORT(private_i2c_del_driver)
TX_ISP_T31_EXPORT(private_i2c_get_clientdata)
TX_ISP_T31_EXPORT(private_i2c_set_clientdata)
TX_ISP_T31_EXPORT(private_i2c_transfer)
TX_ISP_T31_EXPORT(private_jzgpio_set_func)
TX_ISP_T31_EXPORT(private_msleep)
TX_ISP_T31_EXPORT(sensor_init)
TX_ISP_T31_EXPORT(tx_isp_handle_sync_sensor_attr_event)
TX_ISP_T31_EXPORT(tx_isp_register_sensor_subdev)
TX_ISP_T31_EXPORT(tx_isp_sinfo_driver_add)
TX_ISP_T31_EXPORT(tx_isp_sinfo_driver_del)
/*
 * Older sensor modules (thingino master's ingenic-sdk pin, d93ddb9) call
 * tx_isp_sinfo_sensor_bind/unbind themselves from their
 * tx_isp_subdev_init/deinit wrappers (isp/t31/include/sensor-common.h).
 * Newer ones leave that to tx_isp_register_sensor_subdev().  Both calls are
 * idempotent (a slot already holding the subdev is reused, a second unbind
 * only logs "unmatched"), so exporting them lets both generations load.
 * T10/T20/T21/T23/T41 export them already (no whitelist there).
 */
TX_ISP_T31_EXPORT(tx_isp_sinfo_sensor_bind)
TX_ISP_T31_EXPORT(tx_isp_sinfo_sensor_unbind)
TX_ISP_T31_EXPORT(tx_isp_subdev_deinit)
TX_ISP_T31_EXPORT(tx_isp_subdev_init)
TX_ISP_T31_EXPORT(tx_isp_unregister_sensor_subdev)
