// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.3 (win64) Build 2405991 Thu Dec  6 23:38:27 MST 2018
// Date        : Fri Apr  5 22:01:44 2019
// Host        : Drew running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub -rename_top base_mb_clk_wiz_1_0 -prefix
//               base_mb_clk_wiz_1_0_ base_mb_clk_wiz_1_0_stub.v
// Design      : base_mb_clk_wiz_1_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7s50csga324-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
module base_mb_clk_wiz_1_0(clkfb_in, clk_out1, clkfb_out, resetn, locked, 
  clk_in1)
/* synthesis syn_black_box black_box_pad_pin="clkfb_in,clk_out1,clkfb_out,resetn,locked,clk_in1" */;
  input clkfb_in;
  output clk_out1;
  output clkfb_out;
  input resetn;
  output locked;
  input clk_in1;
endmodule
