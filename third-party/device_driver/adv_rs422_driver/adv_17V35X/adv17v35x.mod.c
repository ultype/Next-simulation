#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("pci:v000013FEd0000000Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd0000000Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd0000000Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd0000000Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd0000000Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00000009sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00000014sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00000015sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00000016sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd0000001Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00000018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00000019sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd0000001Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd0000001Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd0000001Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd0000001Dsv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "EE05AF3FD7B39A77F3497FB");
