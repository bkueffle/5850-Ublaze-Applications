set_property SRC_FILE_INFO {cfile:C:/Users/Benjamin/Documents/Word-documents/CPP/ECE-5850/5850-Ublaze-Applications/src/constraints/fpga.xdc rfile:../../../../constraints/fpga.xdc id:1} [current_design]
set_property src_info {type:XDC file:1 line:11 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN E18   IOSTANDARD LVCMOS33 } [get_ports { led0 }]; #IO_L16N_T2_A27_15 Sch=led[2]
set_property src_info {type:XDC file:1 line:12 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN F13   IOSTANDARD LVCMOS33 } [get_ports { led1 }]; #IO_L17P_T2_A26_15 Sch=led[3]
set_property src_info {type:XDC file:1 line:13 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN E13   IOSTANDARD LVCMOS33 } [get_ports { led2 }]; #IO_L17N_T2_A25_15 Sch=led[4]
set_property src_info {type:XDC file:1 line:14 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN H15   IOSTANDARD LVCMOS33 } [get_ports { led3 }]; #IO_L18P_T2_A24_15 Sch=led[5]
set_property src_info {type:XDC file:1 line:17 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN H14   IOSTANDARD LVCMOS33 } [get_ports { sw0 }]; #IO_L20N_T3_A19_15 Sch=sw[0]
set_property src_info {type:XDC file:1 line:22 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict {PACKAGE_PIN R2 IOSTANDARD SSTL135} [get_ports sys_clk]
set_property src_info {type:XDC file:1 line:23 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN R2    IOSTANDARD SSTL135 } [get_ports { sys_clk }];
set_property src_info {type:XDC file:1 line:27 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict {PACKAGE_PIN C18 IOSTANDARD LVCMOS33} [get_ports reset_n]
set_property src_info {type:XDC file:1 line:30 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN R12   IOSTANDARD LVCMOS33 } [get_ports { uart_rxd }]; #IO_25_14 Sch=uart_rxd_out
set_property src_info {type:XDC file:1 line:31 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN V12   IOSTANDARD LVCMOS33 } [get_ports { uart_txd }]; #IO_L24N_T3_A00_D16_14 Sch=uart_txd_in
set_property src_info {type:XDC file:1 line:33 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN J15   IOSTANDARD LVCMOS33 } [get_ports { gpio_tri_o[0] }]; #IO_L23N_T3_FWE_B_15 Sch=led0_r
set_property src_info {type:XDC file:1 line:34 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN G17   IOSTANDARD LVCMOS33 } [get_ports { gpio_tri_o[1] }]; #IO_L14N_T2_SRCC_15 Sch=led0_g
set_property src_info {type:XDC file:1 line:35 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN F15   IOSTANDARD LVCMOS33 } [get_ports { gpio_tri_o[2] }]; #IO_L13N_T2_MRCC_15 Sch=led0_b
set_property src_info {type:XDC file:1 line:36 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN E15   IOSTANDARD LVCMOS33 } [get_ports { gpio_tri_o[3] }]; #IO_L15N_T2_DQS_ADV_B_15 Sch=led1_r
set_property src_info {type:XDC file:1 line:37 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN F18   IOSTANDARD LVCMOS33 } [get_ports { gpio_tri_o[4] }]; #IO_L16P_T2_A28_15 Sch=led1_g
set_property src_info {type:XDC file:1 line:38 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN E14   IOSTANDARD LVCMOS33 } [get_ports { gpio_tri_o[5] }]; #IO_L15P_T2_DQS_15 Sch=led1_b
