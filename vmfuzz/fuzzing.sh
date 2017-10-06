#! /bin/bash

num1=100
while [ $num1 -gt 0]
do
	num2=50
	while [ $num2 -gt 0]
	do
		insmod vmfuzz.ko
		rmmod vmfuzz
		num2=`expr $num2 - 1`
	done
	echo "" > /var/log/messages
	num1=`expr $num1 - 1`
done
reboot

#echo "6 4 6 7" > /proc/sys/kernel/printk
#dmesg
#echo "4 4 1 7" > /proc/sys/kernel/printk

