obj-m	+= vmfuzz.o
ccflags-y += -I$(M)/include/ -I$(M)/arch/$(ARCH)/include -I$(M)/arch/$(ARCH)/include/uapi

default:
	cp ../hv/include/linux/hyperv.h include/linux/hyperv.h
	cp ../hv/hyperv_vmbus.h hyperv_vmbus.h
	cp ../hv/hyperv_net.h hyperv_net.h
	cp ../hv/modules.order modules.order
	cp ../hv/Module.symvers Module.symvers 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
