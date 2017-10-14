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

char *buffer[10];

int vmfuzz_dumb(struct vmbus_channel *channel, void *buffer, u32 bufferlen)
{		
	struct vmpacket_descriptor desc;
	u32 packetlen = sizeof(struct vmpacket_descriptor) + bufferlen;
	u32 packetlen_aligned = ALIGN(packetlen, sizeof(u64));
	struct kvec bufferlist[3];
	u64 aligned_data = 0;

	/* Setup the descriptor */
	desc.type = VM_PKT_DATA_INBAND; /* VmbusPacketTypeDataInBand; */
	desc.flags = VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED; /* VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED; */
	/* in 8-bytes granularity */
	desc.offset8 = sizeof(struct vmpacket_descriptor) >> 3;
	desc.len8 = (u16)(packetlen_aligned >> 3);
	// requestid = random(u64) or just (u64)(buffer[])
	// get_random_bytes(&requestid, sizeof(u64));
	// desc.trans_id = requestid;
	desc.trans_id = (unsigned long)buffer;

	bufferlist[0].iov_base = &desc;
	bufferlist[0].iov_len = sizeof(struct vmpacket_descriptor);

	bufferlist[1].iov_base = buffer;
	bufferlist[1].iov_len = bufferlen;

	bufferlist[2].iov_base = &aligned_data;
	bufferlist[2].iov_len = (packetlen_aligned - packetlen);
	return hv_ringbuffer_write(channel, bufferlist, 3);
}

int vmfuzz(struct vmbus_channel *channel, int count)
{
	
	u32 bufferlen[10];
	int i, j;

	/* Make and log the 10 fuzzing inputs and then fuzz with the inputs */
	for(i=0; i<10; i++)
	{
		/* bufferlen = 16 bit random bytes */
		get_random_bytes(bufferlen+i, sizeof(u16));
		bufferlen[i] = bufferlen[i] % 112 + 16;
		/* buffer =  memory filled with random whose size of bufferlen */
		get_random_bytes(buffer[i], bufferlen[i]);
		*((char *)buffer[i] + bufferlen[i]) = 0;
		printk(KERN_INFO "Buffer input %d%d: ", count, i);
		for(j=0; j<bufferlen[i]; j++)	printk(KERN_CONT "%02X", (unsigned char)*(buffer[i]+j));
		printk(KERN_CONT "\n");
	}
	/*
	for(i=0; i<10; i++)
	{
		if(vmfuzz_dumb(channel, buffer[i], bufferlen[i])) {
			printk(KERN_ERR "hv_ringbuffer_write error\n");
			return -1;
		}
		//kfree(buffer[i]);
	}
	*/
	return 0;
}

int __init init_hello(void)
{	
	int count=(FUZZ_SCALE/2);
	u64 seed;
	u16 target1, target2;
	struct vmbus_channel *stor_channel;

	switch(option)
	{
		case 1: // Check Collection and Mutate collected packet
				//if(get_packet_count()<20000) break;
				start_fuzz();
				break;
		case 2: // Stop collecting packet, stop fuzz
				stop_fuzz();
				break;
		/*
				case 2: // Make Kernel Log
				printk(KERN_INFO "[vmfuzz]Make Kernel Log...\n");
				log_net_fuzz_input();
				break;
		*/
		case 4: // Check packet_count
				printk(KERN_INFO "[vmfuzz]packet_count: %d\n", get_packet_count());
				break;
		case 7: // Storage Fuzz
				stor_channel = get_stor_channel();
				vmfuzz(stor_channel, 10);
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


