#! /bin/sh
cp pynq_z1_wrapper.bit.bin /lib/firmware/
echo 0 > /sys/class/fpga_manager/fpga0/flags
echo pynq_z1_wrapper.bit.bin > /sys/class/fpga_manager/fpga0/firmware
