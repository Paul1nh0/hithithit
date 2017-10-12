#!/bin/bash

echo "Check the collected packet"
insmod vmfuzz.ko option=4
rmmod vmfuzz
dmesg | tail -n1