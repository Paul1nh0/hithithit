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
#include <linux/init.h>
#include <linux/export.h>
#include <linux/random.h>
#include <asm/io.h>
#include <asm/uaccess.h>

#include "include/linux/hyperv.h"
#include "hyperv_vmbus.h"

MODULE_LICENSE("GPL");

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
	return 0;
	//return hv_ringbuffer_write(channel, bufferlist, 3);
}

int vmfuzz_stor(void)
{
	char *buffer[10];
	u32 bufferlen[10];
	int i, j;

	/* Logging 10 fuzzing input and then fuzz with that inputs */
	for(i=0; i<10; i++)
	{
		buffer[i] = kmalloc(128, GFP_ATOMIC);
		/* bufferlen = 16 bit random bytes */
		get_random_bytes(bufferlen+i, sizeof(u16));
		bufferlen[i] = bufferlen[i] % 112 + 16;
		/* buffer =  memory filled with random whose size of bufferlen */
		get_random_bytes(buffer[i], bufferlen[i]);
		*((char *)buffer[i] + bufferlen[i]) = 0;
		printk(KERN_ERR "Buffer input %d: ", i);
		for(j=0; j<bufferlen[i]; j++)	printk(KERN_CONT "%02X", (unsigned char)*(buffer[i]+j));
		printk(KERN_CONT "\n");
	}
	
	struct vmbus_channel *channel = get_stor_channel();
	if(channel == NULL)
	{
		printk(KERN_ERR "Channel is empty\n"); 
		return -1;	
	}

	for(i=0; i<10; i++)
	{
		if(vmfuzz_dumb(channel, buffer[i], bufferlen[i])) {
			printk(KERN_ERR "hv_ringbuffer_write error\n");
			return -1;
		}
		kfree(buffer[i]);
	}
	return 0;
}

int __init init_hello(void)
{	
	int i;
	printk(KERN_ALERT "[Module Message] Hello, VMFUZZ.\n");

	//for(i=0; i<1000; i++) vmfuzz_stor();
	vmfuzz_stor();
	return 0;

	//vmfuzz_dumb();
	//return vmfuzz_keyboard();
}

void __exit exit_hello(void)
{
	printk(KERN_ALERT "[Module Message] Bye, VMFUZZ\n");
}

module_init(init_hello);
module_exit(exit_hello);


