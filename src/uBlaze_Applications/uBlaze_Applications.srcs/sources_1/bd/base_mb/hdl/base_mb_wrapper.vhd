--Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2018.3 (win64) Build 2405991 Thu Dec  6 23:38:27 MST 2018
--Date        : Fri Apr  5 13:03:04 2019
--Host        : Drew running 64-bit major release  (build 9200)
--Command     : generate_target base_mb_wrapper.bd
--Design      : base_mb_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity base_mb_wrapper is
  port (
    gpio_tri_o : out STD_LOGIC_VECTOR ( 5 downto 0 );
    reset_n : in STD_LOGIC;
    sys_clk : in STD_LOGIC;
    uart_rxd : in STD_LOGIC;
    uart_txd : out STD_LOGIC
  );
end base_mb_wrapper;

architecture STRUCTURE of base_mb_wrapper is
  component base_mb is
  port (
    reset_n : in STD_LOGIC;
    uart_rxd : in STD_LOGIC;
    uart_txd : out STD_LOGIC;
    sys_clk : in STD_LOGIC;
    gpio_tri_o : out STD_LOGIC_VECTOR ( 5 downto 0 )
  );
  end component base_mb;
begin
base_mb_i: component base_mb
     port map (
      gpio_tri_o(5 downto 0) => gpio_tri_o(5 downto 0),
      reset_n => reset_n,
      sys_clk => sys_clk,
      uart_rxd => uart_rxd,
      uart_txd => uart_txd
    );
end STRUCTURE;
