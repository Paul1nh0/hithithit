#!/bin/bash

echo "Stop Fuzzing"
insmod vmfuzz.ko option=6
rmmod vmfuzz