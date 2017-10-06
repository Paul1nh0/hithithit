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
	{ 0x56f9a4a9, __VMLINUX_SYMBOL_STR(vmbus_driver_unregister) },
	{ 0xd322853a, __VMLINUX_SYMBOL_STR(__vmbus_driver_register) },
	{ 0xd795224, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xb1f1cb8b, __VMLINUX_SYMBOL_STR(__uio_register_device) },
	{ 0xea67c59a, __VMLINUX_SYMBOL_STR(vmbus_connection) },
	{ 0x8ea0647f, __VMLINUX_SYMBOL_STR(vmbus_open) },
	{ 0x41ec4c1a, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x98ab5c8d, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x97a0c9c8, __VMLINUX_SYMBOL_STR(uio_event_notify) },
	{ 0xe84cb310, __VMLINUX_SYMBOL_STR(remap_pfn_range) },
	{ 0x7cd8d75e, __VMLINUX_SYMBOL_STR(page_offset_base) },
	{ 0x4c9d28b0, __VMLINUX_SYMBOL_STR(phys_base) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xe53d3e9f, __VMLINUX_SYMBOL_STR(vmbus_close) },
	{ 0xc483a55a, __VMLINUX_SYMBOL_STR(dev_set_drvdata) },
	{ 0x9c866019, __VMLINUX_SYMBOL_STR(uio_unregister_device) },
	{ 0x7cf5b2b3, __VMLINUX_SYMBOL_STR(dev_get_drvdata) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=hv_vmbus,uio";


MODULE_INFO(srcversion, "B8C4585E2D5741EF59DD188");
MODULE_INFO(rhelversion, "7.4");
