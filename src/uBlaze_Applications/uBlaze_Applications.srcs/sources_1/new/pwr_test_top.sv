//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Benjamin Kueffler
// 
// Create Date: 07/13/2019 07:34:22 PM
// Design Name: 
// Module Name: pwr_test_top
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description:
// Includes several inputs and outputs to test the system power draw of an FPGA with
// similar IO
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module pwr_test_top(
  input logic sys_clk,
  input logic reset_n,
  input logic uart_rxd,
  input logic sw0,
  output logic uart_txd,
  output logic led0,
  output logic led1,
  output logic led2,
  output logic led3
  );

  assign uart_txd = uart_rxd;
  assign led0 = sys_clk;
  assign led1 = reset_n;
  assign led2 = ~reset_n;
  assign led3 = sw0;
endmodule
