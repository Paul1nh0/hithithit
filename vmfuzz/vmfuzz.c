#include <linux/kernel.h>
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

#include "include/linux/hyperv.h"
#include "hyperv_vmbus.h"

MODULE_LICENSE("GPL");

int vmfuzz_dumb(struct vmbus_channel *channel)
{
	void *buffer;
	u32 bufferlen;

	buffer = kmalloc(4096, GFP_ATOMIC);
	/* bufferlen = 16 bit random bytes */
	get_random_bytes(&bufferlen, sizeof(u16));
	bufferlen = bufferlen % 1024;

	struct vmpacket_descriptor desc;
	u32 packetlen = sizeof(struct vmpacket_descriptor) + bufferlen;
	u32 packetlen_aligned = ALIGN(packetlen, sizeof(u64));
	struct kvec bufferlist[3];
	u64 aligned_data = 0;
	u64 requestid;

	/* Setup the descriptor */
	desc.type = VM_PKT_DATA_INBAND; /* VmbusPacketTypeDataInBand; */
	desc.flags = VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED; /* VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED; */
	/* in 8-bytes granularity */
	desc.offset8 = sizeof(struct vmpacket_descriptor) >> 3;
	desc.len8 = (u16)(packetlen_aligned >> 3);
	// requestid = random(u64) or just (u64)(buffer[])
	get_random_bytes(&requestid, sizeof(u64));
	desc.trans_id = requestid;

	bufferlist[0].iov_base = &desc;
	bufferlist[0].iov_len = sizeof(struct vmpacket_descriptor);

	/* buffer =  memory filled with random whose size of bufferlen */
	get_random_bytes(buffer, bufferlen);
	bufferlist[1].iov_base = buffer;
	bufferlist[1].iov_len = bufferlen;

	bufferlist[2].iov_base = &aligned_data;
	bufferlist[2].iov_len = (packetlen_aligned - packetlen);
	printk(KERN_ALERT "3\n");
	return hv_ringbuffer_write(channel, bufferlist, 3);
}

int vmfuzz_stor()
{
	struct vmbus_channel *channel = get_stor_channel();
	if(channel != NULL)	return vmfuzz_dumb(channel);
	return -1;
}

int __init init_hello(void)
{
	printk(KERN_ALERT "[Module Message] Hello, VMFUZZ.\n");
	return vmfuzz_stor();

	//vmfuzz_dumb();
	//return vmfuzz_keyboard();
}

void __exit exit_hello(void)
{
	printk(KERN_ALERT "[Module Message] Bye, VMFUZZ\n");
}

module_init(init_hello);
module_exit(exit_hello);


