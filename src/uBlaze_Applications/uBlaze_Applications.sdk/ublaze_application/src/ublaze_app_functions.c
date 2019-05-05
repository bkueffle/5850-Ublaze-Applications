/*
 * ublaze_app_functions.c
 *
 * Declares functions relating the ublaze applications project
 *
 *  Created on: Apr 20, 2019
 *      Author: Benjamin Kueffler
 */

#include "ublaze_app_functions.h"
#include "xtmrctr.h"
#include "xil_printf.h"
#include "math.h"

void init_64b_timer(u32 t0_value, u32 t1_value)
{
  // Control for Timer 0
  const u8 TCSR0 = 0x00;

  // The load register for timer 0
  const u8 TLR0  = 0x04;

  // Control for Timer 1
  const u8 TCSR1 = 0x10;

  // The load register for timer1
  const u8 TLR1 = 0x14;

  // Disable all the timers
  Xil_Out32(XPAR_AXI_TIMER_0_BASEADDR + TCSR0, 0x00000000);
  Xil_Out32(XPAR_AXI_TIMER_0_BASEADDR + TCSR1, 0x00000000);

  // Write the initial values in the load register
  Xil_Out32(XPAR_AXI_TIMER_0_BASEADDR + TLR0, t0_value);
  Xil_Out32(XPAR_AXI_TIMER_0_BASEADDR + TLR1, t1_value);

  // Set the initial value via the load ctrl register
  Xil_Out32(XPAR_AXI_TIMER_0_BASEADDR + TCSR1, 0x00000020);
  Xil_Out32(XPAR_AXI_TIMER_0_BASEADDR + TCSR0, 0x00000020);

  // Set cascade to enable 64 bit time [11]
  // Enable the timers [10]
  Xil_Out32(XPAR_AXI_TIMER_0_BASEADDR + TCSR1, 0x00000800);
  Xil_Out32(XPAR_AXI_TIMER_0_BASEADDR + TCSR0, 0x00000c00);

}

u64 get_64b_time()
{
  // The counter register for timer 0
  const u8 TCR0  = 0x08;

  // The counter register for timer 1
  const u8 TCR1  = 0x18;

  // Upper 32 bytes of the timer
  u64 msb = Xil_In32(XPAR_AXI_TIMER_0_BASEADDR + TCR1);

  // Lower 32 bytes of the timer
  u64 lsb = Xil_In32(XPAR_AXI_TIMER_0_BASEADDR + TCR0);

  // Re-read upper 32 bytes of the timer
  u64 curr_msb = Xil_In32(XPAR_AXI_TIMER_0_BASEADDR + TCR1);

  // If the upper 32 bytes have changed since the last time we read
  // Then there was a 32-bit rollover, so we need to read the LSB again
  if (curr_msb != msb) lsb = Xil_In32(XPAR_AXI_TIMER_0_BASEADDR + TCR0);

  return (curr_msb << 32) | lsb;
}

// Returns true if the number is prime
int is_prime(int num)
{
  for(u32 i = 2; i <= sqrt(num); i++)
  {
    if(num % i == 0) return 0;
  }
  return 1;
}

// Calculates result of key and totient
int cd(int key, u32 totient)
{
  int i = 1;
  while(1)
  {
    i += totient;
    if(i % key == 0) return(i / key);
  }
}

// Encrypts the input message
char* encrypt(char* encr_str, u32 len, u32 key, u32 n)
{
  int k;
  for(int i=0; i < len; i++)
  {
    k = 1;
    for(int j=0; j < key; j++)
    {
      k *= encr_str[i];
      k %= n;
    }
    encr_str[i] = k;
  }
  return encr_str;
}

// Decrypts the encoded string
char* decrypt(char* encr_str, u32 len, u32 key, u32 n)
{
  int k;
  unsigned char ch;
  for(int i=0; i < len; i++)
  {
    k = 1;
    ch = encr_str[i];
    for(int j=0; j < key; j++)
    {
      k *= ch;
      k %= n;
    }
    encr_str[i] = k;
  }
  return encr_str;
}
