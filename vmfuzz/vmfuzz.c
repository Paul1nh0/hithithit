#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/fcntl.h>
#include <linux/sched.h>
#include <linux/wait.h>
#include <linux/delay.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/export.h>
#include <linux/random.h>
#include <linux/delay.h>
#include <linux/timer.h>
#include <asm/io.h>
#include <asm/uaccess.h>

#include "include/linux/hyperv.h"
#include "hyperv_vmbus.h"
#include "hyperv_net.h"

MODULE_LICENSE("GPL");
static short int option;
module_param(option, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

int __init init_hello(void)
{	
	switch(option)
	{
		case 1: // Check Collection and Mutate collected packet
				start_fuzz();
				break;
		case 2: // Stop collecting packet, stop fuzz
				stop_fuzz();
				break;
		case 4: // Check packet_count
				printk(KERN_INFO "[vmfuzz]packet_count: %d\n", get_packet_count());
				break;
		default: break;
	}
	return 0;
}

void __exit exit_hello(void)
{
	//printk(KERN_INFO "[Module Message] Bye, VMFUZZ\n");
}

module_init(init_hello);
module_exit(exit_hello);


