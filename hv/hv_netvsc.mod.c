#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x28950ef1, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0x262e1c2b, __VMLINUX_SYMBOL_STR(netdev_info) },
	{ 0x98ab5c8d, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x49c91259, __VMLINUX_SYMBOL_STR(ethtool_op_get_ts_info) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0xa675804c, __VMLINUX_SYMBOL_STR(utf8s_to_utf16s) },
	{ 0xfd96706c, __VMLINUX_SYMBOL_STR(node_to_cpumask_map) },
	{ 0x251a2d2f, __VMLINUX_SYMBOL_STR(skb_clone_tx_timestamp) },
	{ 0xca0a6dc8, __VMLINUX_SYMBOL_STR(__hv_pkt_iter_next) },
	{ 0xb07002fa, __VMLINUX_SYMBOL_STR(vmbus_establish_gpadl) },
	{ 0x784213a6, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0xb2be6e92, __VMLINUX_SYMBOL_STR(netdev_stats_to_stats64) },
	{ 0x4b7dcf38, __VMLINUX_SYMBOL_STR(_raw_qspin_lock) },
	{ 0x15692c87, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0xf8dab2e, __VMLINUX_SYMBOL_STR(netdev_notice) },
	{ 0xd93737a0, __VMLINUX_SYMBOL_STR(napi_disable) },
	{ 0x98a76ac3, __VMLINUX_SYMBOL_STR(napi_consume_skb) },
	{ 0xc483a55a, __VMLINUX_SYMBOL_STR(dev_set_drvdata) },
	{ 0xc8b57c27, __VMLINUX_SYMBOL_STR(autoremove_wake_function) },
	{ 0x79aa04a2, __VMLINUX_SYMBOL_STR(get_random_bytes) },
	{ 0x31e9790f, __VMLINUX_SYMBOL_STR(netdev_rx_handler_register) },
	{ 0xc7a4fbed, __VMLINUX_SYMBOL_STR(rtnl_lock) },
	{ 0x371f6d1b, __VMLINUX_SYMBOL_STR(vmbus_sendpacket_pagebuffer_ctl) },
	{ 0xe6d7097b, __VMLINUX_SYMBOL_STR(netif_carrier_on) },
	{ 0xc0a3d105, __VMLINUX_SYMBOL_STR(find_next_bit) },
	{ 0x6b06fdce, __VMLINUX_SYMBOL_STR(delayed_work_timer_fn) },
	{ 0xd2da1048, __VMLINUX_SYMBOL_STR(register_netdevice_notifier) },
	{ 0x3eff7be7, __VMLINUX_SYMBOL_STR(netif_carrier_off) },
	{ 0x88bfa7e, __VMLINUX_SYMBOL_STR(cancel_work_sync) },
	{ 0xf087137d, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0xd322853a, __VMLINUX_SYMBOL_STR(__vmbus_driver_register) },
	{ 0x8abb5b23, __VMLINUX_SYMBOL_STR(call_netdevice_notifiers) },
	{ 0xe1d1af76, __VMLINUX_SYMBOL_STR(__dev_kfree_skb_any) },
	{ 0x2ad57c72, __VMLINUX_SYMBOL_STR(vmbus_set_sc_create_callback) },
	{ 0x593a99b, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x797c8fa9, __VMLINUX_SYMBOL_STR(cancel_delayed_work_sync) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0x54efb5d6, __VMLINUX_SYMBOL_STR(cpu_number) },
	{ 0x97651e6c, __VMLINUX_SYMBOL_STR(vmemmap_base) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x81ad6f16, __VMLINUX_SYMBOL_STR(netif_napi_del) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xc9ec4e21, __VMLINUX_SYMBOL_STR(free_percpu) },
	{ 0xd8836e80, __VMLINUX_SYMBOL_STR(__dynamic_netdev_dbg) },
	{ 0x343a1a8, __VMLINUX_SYMBOL_STR(__list_add) },
	{ 0x9d0d6206, __VMLINUX_SYMBOL_STR(unregister_netdevice_notifier) },
	{ 0x27c33efe, __VMLINUX_SYMBOL_STR(csum_ipv6_magic) },
	{ 0x9436029f, __VMLINUX_SYMBOL_STR(vmbus_sendpacket_ctl) },
	{ 0xe0dbd0e4, __VMLINUX_SYMBOL_STR(__pskb_pull_tail) },
	{ 0xf432dd3d, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xfe7c4287, __VMLINUX_SYMBOL_STR(nr_cpu_ids) },
	{ 0xffab38ab, __VMLINUX_SYMBOL_STR(hv_pkt_iter_close) },
	{ 0x6d0aba34, __VMLINUX_SYMBOL_STR(wait_for_completion) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xbb400a5d, __VMLINUX_SYMBOL_STR(dev_set_mac_address) },
	{ 0x58c08cf3, __VMLINUX_SYMBOL_STR(netif_tx_wake_queue) },
	{ 0xd795224, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x8f64aa4, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0xb8c7ff88, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0xd58bf9d8, __VMLINUX_SYMBOL_STR(ethtool_op_get_link) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x4c9d28b0, __VMLINUX_SYMBOL_STR(phys_base) },
	{ 0x479c3c86, __VMLINUX_SYMBOL_STR(find_next_zero_bit) },
	{ 0x708b5f0c, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0xd7efe2ef, __VMLINUX_SYMBOL_STR(register_netdev) },
	{ 0xb341f035, __VMLINUX_SYMBOL_STR(netdev_upper_dev_unlink) },
	{ 0x5792f848, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0xf40262b1, __VMLINUX_SYMBOL_STR(dev_close) },
	{ 0x521445b, __VMLINUX_SYMBOL_STR(list_del) },
	{ 0x2a62b5bc, __VMLINUX_SYMBOL_STR(netif_set_real_num_rx_queues) },
	{ 0xf4f14de6, __VMLINUX_SYMBOL_STR(rtnl_trylock) },
	{ 0x5562fbb2, __VMLINUX_SYMBOL_STR(netif_set_real_num_tx_queues) },
	{ 0x8ea0647f, __VMLINUX_SYMBOL_STR(vmbus_open) },
	{ 0x8070df92, __VMLINUX_SYMBOL_STR(init_net) },
	{ 0xb0dc2829, __VMLINUX_SYMBOL_STR(__skb_get_hash) },
	{ 0x2e3d0c4c, __VMLINUX_SYMBOL_STR(dev_open) },
	{ 0xf11543ff, __VMLINUX_SYMBOL_STR(find_first_zero_bit) },
	{ 0xbd671048, __VMLINUX_SYMBOL_STR(__alloc_percpu_gfp) },
	{ 0x7cd8d75e, __VMLINUX_SYMBOL_STR(page_offset_base) },
	{ 0x3ff62317, __VMLINUX_SYMBOL_STR(local_bh_disable) },
	{ 0x423058c9, __VMLINUX_SYMBOL_STR(netif_device_attach) },
	{ 0xae250af1, __VMLINUX_SYMBOL_STR(napi_gro_receive) },
	{ 0x40a9b349, __VMLINUX_SYMBOL_STR(vzalloc) },
	{ 0x78764f4e, __VMLINUX_SYMBOL_STR(pv_irq_ops) },
	{ 0x618911fc, __VMLINUX_SYMBOL_STR(numa_node) },
	{ 0x2fa56500, __VMLINUX_SYMBOL_STR(netif_device_detach) },
	{ 0x61a6b5a2, __VMLINUX_SYMBOL_STR(eth_prepare_mac_addr_change) },
	{ 0xd17f4c5b, __VMLINUX_SYMBOL_STR(__napi_schedule) },
	{ 0xeeec26a7, __VMLINUX_SYMBOL_STR(queue_delayed_work_on) },
	{ 0xf0fdf6cb, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xc311ec22, __VMLINUX_SYMBOL_STR(cpu_possible_mask) },
	{ 0xb0d91372, __VMLINUX_SYMBOL_STR(netdev_rx_handler_unregister) },
	{ 0x5adedd06, __VMLINUX_SYMBOL_STR(skb_checksum_help) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xa202a8e5, __VMLINUX_SYMBOL_STR(kmalloc_order_trace) },
	{ 0x6b2dc060, __VMLINUX_SYMBOL_STR(dump_stack) },
	{ 0x799aca4, __VMLINUX_SYMBOL_STR(local_bh_enable) },
	{ 0x905307be, __VMLINUX_SYMBOL_STR(napi_complete_done) },
	{ 0xad480ea0, __VMLINUX_SYMBOL_STR(eth_type_trans) },
	{ 0xe1768727, __VMLINUX_SYMBOL_STR(netdev_notify_peers) },
	{ 0x826789e8, __VMLINUX_SYMBOL_STR(pskb_expand_head) },
	{ 0xafd969b3, __VMLINUX_SYMBOL_STR(netdev_upper_dev_link) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xd6967e61, __VMLINUX_SYMBOL_STR(netdev_err) },
	{ 0xc8341533, __VMLINUX_SYMBOL_STR(eth_commit_mac_addr_change) },
	{ 0x41ec4c1a, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xd94cc09, __VMLINUX_SYMBOL_STR(__per_cpu_offset) },
	{ 0xe53d3e9f, __VMLINUX_SYMBOL_STR(vmbus_close) },
	{ 0x9327f5ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0x384e70ae, __VMLINUX_SYMBOL_STR(__smp_mb__before_atomic) },
	{ 0xd633fe2b, __VMLINUX_SYMBOL_STR(unregister_netdevice_queue) },
	{ 0xcf21d241, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x7efd609f, __VMLINUX_SYMBOL_STR(__netif_napi_add) },
	{ 0x2931cd0f, __VMLINUX_SYMBOL_STR(netdev_warn) },
	{ 0xdec0caf5, __VMLINUX_SYMBOL_STR(eth_validate_addr) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xa75312bc, __VMLINUX_SYMBOL_STR(call_rcu_sched) },
	{ 0x5c8b5ce8, __VMLINUX_SYMBOL_STR(prepare_to_wait) },
	{ 0x297fdb9, __VMLINUX_SYMBOL_STR(hv_pkt_iter_first) },
	{ 0xdb1c0e0a, __VMLINUX_SYMBOL_STR(vmbus_teardown_gpadl) },
	{ 0x95c99546, __VMLINUX_SYMBOL_STR(vmbus_sendpacket) },
	{ 0x7628f3c7, __VMLINUX_SYMBOL_STR(this_cpu_off) },
	{ 0xfa66f77c, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x4cbbd171, __VMLINUX_SYMBOL_STR(__bitmap_weight) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0x4b06d2e7, __VMLINUX_SYMBOL_STR(complete) },
	{ 0x9e0c711d, __VMLINUX_SYMBOL_STR(vzalloc_node) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x85670f1d, __VMLINUX_SYMBOL_STR(rtnl_is_locked) },
	{ 0x42045456, __VMLINUX_SYMBOL_STR(__napi_alloc_skb) },
	{ 0x34c11ce1, __VMLINUX_SYMBOL_STR(dev_queue_xmit) },
	{ 0x22095d00, __VMLINUX_SYMBOL_STR(skb_tstamp_tx) },
	{ 0x2ac95217, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0x7cf5b2b3, __VMLINUX_SYMBOL_STR(dev_get_drvdata) },
	{ 0x6e720ff2, __VMLINUX_SYMBOL_STR(rtnl_unlock) },
	{ 0xf5cbcd90, __VMLINUX_SYMBOL_STR(dev_set_mtu) },
	{ 0x56f9a4a9, __VMLINUX_SYMBOL_STR(vmbus_driver_unregister) },
	{ 0x906ac89f, __VMLINUX_SYMBOL_STR(alloc_etherdev_mqs) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=hv_vmbus";

MODULE_ALIAS("vmbus:635161f83edfc546913ff2d2f965ed0e");

MODULE_INFO(srcversion, "0BAF77CD97DAB619FA828ED");
MODULE_INFO(rhelversion, "7.4");
