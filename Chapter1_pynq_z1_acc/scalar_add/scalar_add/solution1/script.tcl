############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project scalar_add
set_top add
add_files add.cpp
open_solution "solution1" -flow_target vivado
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
config_export -display_name Scalar_add -format ip_catalog -output /home/hs/scalar_add/add.zip -rtl verilog -vendor nobody -version 1.0
source "./scalar_add/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -rtl verilog -format ip_catalog -vendor "nobody" -display_name "Scalar_add" -output /home/hs/scalar_add/add.zip
