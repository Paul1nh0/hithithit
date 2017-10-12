#! /bin/bash



tail -F /var/log/messages > kern.log &
rmmod vmfuzz
echo "Check the collected packet"
insmod vmfuzz.ko option=4
rmmod vmfuzz
#echo "Mutate fuzz input"
#insmod vmfuzz.ko option=1
#rmmod vmfuzz
echo "Logging fuzz input"
insmod vmfuzz.ko option=2
rmmod vmfuzz
echo "Fuzzing..."
#insmod vmfuzz.ko option=3
#rmmod vmfuzz

#echo "" > /var/log/messages


#echo "6 4 6 7" > /proc/sys/kernel/printk
#dmesg
#echo "4 4 1 7" > /proc/sys/kernel/printk

