-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2018.3 (win64) Build 2405991 Thu Dec  6 23:38:27 MST 2018
-- Date        : Fri May  3 21:14:56 2019
-- Host        : Drew running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub -rename_top base_mb_clk_wiz_1_0 -prefix
--               base_mb_clk_wiz_1_0_ base_mb_clk_wiz_1_0_stub.vhdl
-- Design      : base_mb_clk_wiz_1_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7s50csga324-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity base_mb_clk_wiz_1_0 is
  Port ( 
    clkfb_in : in STD_LOGIC;
    clk_out1 : out STD_LOGIC;
    clkfb_out : out STD_LOGIC;
    resetn : in STD_LOGIC;
    locked : out STD_LOGIC;
    clk_in1 : in STD_LOGIC
  );

end base_mb_clk_wiz_1_0;

architecture stub of base_mb_clk_wiz_1_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "clkfb_in,clk_out1,clkfb_out,resetn,locked,clk_in1";
begin
end;
