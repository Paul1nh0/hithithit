#! /bin/bash


echo "Mount Shared Disk"
mount /dev/sdb1 /root/share
tail -f /var/log/messages > /root/share/kern.log &
rmmod vmfuzz
echo "Check the collected packet"
python "crawler.py" &
#insmod vmfuzz.ko option=4
#rmmod vmfuzz
echo "Fuzzing..."
insmod vmfuzz.ko option=1
rmmod vmfuzz

#echo "6 4 6 7" > /proc/sys/kernel/printk
#dmesg
#echo "4 4 1 7" > /proc/sys/kernel/printk

