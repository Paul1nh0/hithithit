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
	{ 0xb2d307de, __VMLINUX_SYMBOL_STR(param_ops_short) },
	{ 0x5c7277dc, __VMLINUX_SYMBOL_STR(net_fuzzing) },
	{ 0x3a26f291, __VMLINUX_SYMBOL_STR(log_net_fuzz_input) },
	{ 0x14c163f7, __VMLINUX_SYMBOL_STR(mutation_fuzz_net) },
	{ 0xd90f7c58, __VMLINUX_SYMBOL_STR(get_packet_count) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x79aa04a2, __VMLINUX_SYMBOL_STR(get_random_bytes) },
	{ 0xf0fdf6cb, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x18a3e549, __VMLINUX_SYMBOL_STR(hv_ringbuffer_write) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=hv_netvsc,hv_vmbus";


MODULE_INFO(srcversion, "EB272347706BDD7E07FB7DF");
MODULE_INFO(rhelversion, "7.4");
