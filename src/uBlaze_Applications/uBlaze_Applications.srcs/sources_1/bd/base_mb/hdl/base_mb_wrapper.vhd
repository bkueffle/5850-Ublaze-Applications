--Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2018.3 (win64) Build 2405991 Thu Dec  6 23:38:27 MST 2018
--Date        : Sat May  4 09:11:24 2019
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
    gpio_tri_io : inout STD_LOGIC_VECTOR ( 5 downto 0 );
    led0 : out STD_LOGIC_VECTOR ( 0 to 0 );
    led1 : out STD_LOGIC_VECTOR ( 0 to 0 );
    led2 : out STD_LOGIC;
    led3 : out STD_LOGIC;
    reset_n : in STD_LOGIC;
    sw0 : in STD_LOGIC;
    sys_clk : in STD_LOGIC;
    uart_rxd : in STD_LOGIC;
    uart_txd : out STD_LOGIC
  );
end base_mb_wrapper;

architecture STRUCTURE of base_mb_wrapper is
  component base_mb is
  port (
    reset_n : in STD_LOGIC;
    sys_clk : in STD_LOGIC;
    led0 : out STD_LOGIC_VECTOR ( 0 to 0 );
    led1 : out STD_LOGIC_VECTOR ( 0 to 0 );
    led2 : out STD_LOGIC;
    led3 : out STD_LOGIC;
    sw0 : in STD_LOGIC;
    uart_rxd : in STD_LOGIC;
    uart_txd : out STD_LOGIC;
    gpio_tri_i : in STD_LOGIC_VECTOR ( 5 downto 0 );
    gpio_tri_o : out STD_LOGIC_VECTOR ( 5 downto 0 );
    gpio_tri_t : out STD_LOGIC_VECTOR ( 5 downto 0 )
  );
  end component base_mb;
  component IOBUF is
  port (
    I : in STD_LOGIC;
    O : out STD_LOGIC;
    T : in STD_LOGIC;
    IO : inout STD_LOGIC
  );
  end component IOBUF;
  signal gpio_tri_i_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal gpio_tri_i_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal gpio_tri_i_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal gpio_tri_i_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal gpio_tri_i_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal gpio_tri_i_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal gpio_tri_io_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal gpio_tri_io_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal gpio_tri_io_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal gpio_tri_io_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal gpio_tri_io_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal gpio_tri_io_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal gpio_tri_o_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal gpio_tri_o_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal gpio_tri_o_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal gpio_tri_o_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal gpio_tri_o_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal gpio_tri_o_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal gpio_tri_t_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal gpio_tri_t_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal gpio_tri_t_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal gpio_tri_t_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal gpio_tri_t_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal gpio_tri_t_5 : STD_LOGIC_VECTOR ( 5 to 5 );
begin
base_mb_i: component base_mb
     port map (
      gpio_tri_i(5) => gpio_tri_i_5(5),
      gpio_tri_i(4) => gpio_tri_i_4(4),
      gpio_tri_i(3) => gpio_tri_i_3(3),
      gpio_tri_i(2) => gpio_tri_i_2(2),
      gpio_tri_i(1) => gpio_tri_i_1(1),
      gpio_tri_i(0) => gpio_tri_i_0(0),
      gpio_tri_o(5) => gpio_tri_o_5(5),
      gpio_tri_o(4) => gpio_tri_o_4(4),
      gpio_tri_o(3) => gpio_tri_o_3(3),
      gpio_tri_o(2) => gpio_tri_o_2(2),
      gpio_tri_o(1) => gpio_tri_o_1(1),
      gpio_tri_o(0) => gpio_tri_o_0(0),
      gpio_tri_t(5) => gpio_tri_t_5(5),
      gpio_tri_t(4) => gpio_tri_t_4(4),
      gpio_tri_t(3) => gpio_tri_t_3(3),
      gpio_tri_t(2) => gpio_tri_t_2(2),
      gpio_tri_t(1) => gpio_tri_t_1(1),
      gpio_tri_t(0) => gpio_tri_t_0(0),
      led0(0) => led0(0),
      led1(0) => led1(0),
      led2 => led2,
      led3 => led3,
      reset_n => reset_n,
      sw0 => sw0,
      sys_clk => sys_clk,
      uart_rxd => uart_rxd,
      uart_txd => uart_txd
    );
gpio_tri_iobuf_0: component IOBUF
     port map (
      I => gpio_tri_o_0(0),
      IO => gpio_tri_io(0),
      O => gpio_tri_i_0(0),
      T => gpio_tri_t_0(0)
    );
gpio_tri_iobuf_1: component IOBUF
     port map (
      I => gpio_tri_o_1(1),
      IO => gpio_tri_io(1),
      O => gpio_tri_i_1(1),
      T => gpio_tri_t_1(1)
    );
gpio_tri_iobuf_2: component IOBUF
     port map (
      I => gpio_tri_o_2(2),
      IO => gpio_tri_io(2),
      O => gpio_tri_i_2(2),
      T => gpio_tri_t_2(2)
    );
gpio_tri_iobuf_3: component IOBUF
     port map (
      I => gpio_tri_o_3(3),
      IO => gpio_tri_io(3),
      O => gpio_tri_i_3(3),
      T => gpio_tri_t_3(3)
    );
gpio_tri_iobuf_4: component IOBUF
     port map (
      I => gpio_tri_o_4(4),
      IO => gpio_tri_io(4),
      O => gpio_tri_i_4(4),
      T => gpio_tri_t_4(4)
    );
gpio_tri_iobuf_5: component IOBUF
     port map (
      I => gpio_tri_o_5(5),
      IO => gpio_tri_io(5),
      O => gpio_tri_i_5(5),
      T => gpio_tri_t_5(5)
    );
end STRUCTURE;
