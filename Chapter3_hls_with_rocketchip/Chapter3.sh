#! /bin/sh
cp rocketchip_wrapper.bit.bin /lib/firmware/
echo 0 > /sys/class/fpga_manager/fpga0/flags
echo rocketchip_wrapper.bit.bin > /sys/class/fpga_manager/fpga0/firmware
