#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/fcntl.h>
#include <linux/sched.h>
#include <linux/fs.h>
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

char *buffer[10];

static void read_file(char *filename)
{
	struct file *filp;
	struct inode *inode;
	mm_segment_t fs;
	off_t fsize;
	char *buf;
	unsigned long magic;
	filp=filp_open(filename, O_RDONLY, 0);
	inode = filp->f_dentry->d_inode;

	magic=inode->i_sb->s_magic;
	printk("<1>file system magic:%li \n", magic);
	printk("<1>super blocksize:%li \n", inode->i_sb->s_blocksize);
	fsize=inode->i_size;
	buf = (char *)kmalloc(fsize+1, GFP_ATOMIC);

	fs = get_fs();
	set_fs(KERNEL_DS);
	filp->f_op->read(filp,buf,fsize,&(filp->f_pos));
	set_fs(fs);

	buf[fsize]='\0';
	printk("<1>the file content is:\n");
	printk("<1>%s", buf);

	filp_close(filp, NULL);
}

static void write_file(char *filename, char *data)
{
	struct file *filp;
	mm_segment_t fs;
	filp = filp_open(filename, O_RDWR|O_APPEND, 0644);
	if(IS_ERR(filp))
	{
		printk("open error... \n");
		return;
	}

	fs = get_fs();
	set_fs(KERNEL_DS);
	filp->f_op->write(filp, data, strlen(data), &filp->f_pos);
	set_fs(fs);
	filp_close(filp, NULL);
}

int __init init_hello(void)
{	
	switch(option)
	{
		case 1: // Check Collection and Mutate collected packet
				//if(get_packet_count()<20000) break;
				start_fuzz();
				break;
		case 2: // Stop collecting packet, stop fuzz
				stop_fuzz();
				break;
		case 3: //File read
				read_file("/root/vmfuzz/vmfuzz/log.txt");
				break;
		case 4: // Check packet_count
				printk(KERN_INFO "[vmfuzz]packet_count: %d\n", get_packet_count());
				break;
		case 5: // File write
				write_file("/root/vmfuzz/vmfuzz/log.txt", "Hello, kernel test\n");
				break;

		default: break;
	}
	return 0;

	//return vmfuzz_keyboard();
}

void __exit exit_hello(void)
{
	//printk(KERN_INFO "[Module Message] Bye, VMFUZZ\n");
}

module_init(init_hello);
module_exit(exit_hello);


