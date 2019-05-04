/*
 * Header file for Ublaze Application
 *
 *  Created on: Apr 20, 2019
 *      Author: Benjamin Kueffler
 */
#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_io.h"
#include "sleep.h"
#include "ublaze_app_functions.h"

int main()
{
    // The desired time to read a file/string before timeout in microseconds
    const int EOS_TIMEOUT_US = 100000;

    // Enable printing the result
    const u8 RESULT_EN = 1;

    init_platform();

    print("Select a file 32kB or less to encrypt \n\r");

    // UART TX -> RX Loop forever example
    char uart_rx = 0;
    char word_to_encrypt[32768] = {};
    int char_ptr = 0;

    // The timeout looks for a break in the transmission to find the end of file
    int timeout = 0;

    // Indicates the first character was received over uart
    char rx_first_char = 0;

    while(1)
    {
    	// Loop forever
    	uart_rx = 0;
    	while(uart_rx == 0){
    		// Loop until the RX FIFO is not empty

    		// Sleep for 1 us
    		usleep(1);


			// Check to see if the RX FIFO is empty
			uart_rx = Xil_In32(XPAR_AXI_UARTLITE_0_BASEADDR + 0x08) & 0x01;

			if (uart_rx == 1){
				timeout = 0;
				rx_first_char = 1;
			}
			else if ((timeout++ >= EOS_TIMEOUT_US) && (rx_first_char > 0))
			{
				break;
			}


    	};
    	if (timeout >= EOS_TIMEOUT_US) break;

    	// Read the RX register
    	uart_rx = Xil_In32(XPAR_AXI_UARTLITE_0_BASEADDR + 0x00);
    	word_to_encrypt[char_ptr++] = uart_rx;
	};

    xil_printf("Starting Encrypt/Decrypt on file...\n\r");

    // Initialize the timer
    init_64b_timer(0,0);

    ///////////////////////////////////////////////////////////////////////
    // Process encrypting and decrypting

    char *processed_word = encrypt(word_to_encrypt, char_ptr * sizeof(char));
    //xil_printf("Result is : %s\n\r", encrypted_word);

    processed_word = decrypt(processed_word, char_ptr * sizeof(char));

    ///////////////////////////////////////////////////////////////////////

    // Get the time right after the algorithm
    u64 total_cycles = get_64b_time();

    // If the user enabled looking at the decryption result, print that result
    if (RESULT_EN == 1) xil_printf("Result is : %s\n\r", processed_word);

    // Report the time the algorithm took
    xil_printf("Total cycles: %d\n\r", total_cycles);

    double raw_exe_time;

    // Computes the execution time in seconds
    if (total_cycles < XPAR_TMRCTR_0_CLOCK_FREQ_HZ / 100) raw_exe_time = 0;
    else raw_exe_time = (double) total_cycles / XPAR_TMRCTR_0_CLOCK_FREQ_HZ;

    // Computes the minutes
    int exe_time_min = ((int) raw_exe_time / 60) % 60;

    // Computes the hours
    int exe_time_hr = (raw_exe_time / 3600);

    // Computes the integer number of seconds
    int whole_sec = raw_exe_time - exe_time_min*60 - exe_time_hr*3600;

    // Computes the thousands value
    double whole_sec_doub = raw_exe_time - exe_time_min*60 - exe_time_hr*3600;
    int thousands_sec = (whole_sec_doub - whole_sec) * 1000;

    xil_printf("The execution time was %d hours, %d minutes, and %d.%d seconds!\n\r", exe_time_hr, exe_time_min, whole_sec, thousands_sec);

    cleanup_platform();
    return 0;
}
