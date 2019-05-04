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

char* encrypt(char* encr_str, u32 len)
{
  char mod,modmult, newch;
  int num[100];

  // Setup encryption key
  for(u8 i=0;i<9;i++) num[i]=i;
  for(u8 i=9;i<26;i++) num[i]=i+5;
  for(u8 i=26;i<=61;i++) num[i]=i+7;
  for(u8 i=62;i<=87;i++) num[i]=i+35;

  for(int i=0; i < len; i++)
  {

    ////////////////////// START ENCRYPTING CHARACTERS //////////////////////
  
    //For Tab Key
    if (encr_str[i] == 9) newch = encr_str[i];
  
    //For Carriage REturn
    else if (encr_str[i] == 10 || encr_str[i] == 13) newch = encr_str[i];
  
    // Spaces
    else if (encr_str[i] == 32) newch = encr_str[i];
  
    //For Special Symbols
    else if (encr_str[i] >= 33 && encr_str[i] <= 47)
    {                                                    
      mod=encr_str[i] + 64;
      modmult = mod * 20;
      newch = modmult > 500 ? modmult : mod;
    }

    // Encrypt The Numbers
    else if (encr_str[i] >= 48 && encr_str[i] <= 57)
    {
      mod=num[encr_str[i] + 4];
      modmult = mod * 20;
      newch = modmult > 500 ? modmult : mod;
    }
    
    //For Special Symbols
    else if (encr_str[i] >= 58 && encr_str[i] <= 64)
    {
      mod=encr_str[i] + 54;
      modmult = mod * 20;
      newch = modmult > 500 ? modmult : mod;
    }

    //Encrypt The Capital Letters
    else if (encr_str[i] >= 65 && encr_str[i] <= 90)
    {
      mod=num[encr_str[i] - 39];
      modmult = mod * 20;
      newch = modmult > 500 ? modmult : mod;
    }
  
    //For Special Symbols
    else if (encr_str[i] >= 91 && encr_str[i] <= 96)
    {
      mod=encr_str[i] + 28;
      modmult = mod * 20;
      newch = modmult > 500 ? modmult : mod;
    }
  
    //Encrypt the lower case letters
    else if (encr_str[i] >= 97 && encr_str[i] <= 122)
    {
      mod=num[encr_str[i] - 97];
      modmult = mod * 20;
      newch = modmult > 500 ? modmult : mod;
    }
  
    //For Special Symbols
    else if (encr_str[i] >= 123 && encr_str[i] <= 126)
    {
      mod=encr_str[i] - 40;                                          
      modmult = mod * 20;
      newch = modmult > 500 ? modmult : mod;
    }

    encr_str[i] = newch;
  }
  return encr_str;
}

// Decrypts a character array
char* decrypt(char* encr_str, u32 len)
{
  char mod, newch;
  int num[100], flag;

  for(u8 i=0;i<9;i++) num[i]=i;

  for(u8 i=14;i<31;i++) num[i-5]=i;

  for(u8 i=33;i<=68;i++) num[i-7]=i;
  
  for(int i=0; i < len; i++)
  {
    flag = 0;
    ////////////////////// START DECRYPTING CHARACTERS //////////////////////
  
    for(u8 j=0; j<26; j++)
    {
      // Find lower case
      if(encr_str[i] == num[j])
      {
        mod = j + 97;
        encr_str[i] = mod;
        flag = 1;
        break;
      }
    }
  
    if (flag == 1) continue;
  
    for(u8 j=26; j<52; j++)
    {
      // Find capitals
        if(encr_str[i]==num[j])
        {
          mod=j + 39;
          encr_str[i] = mod;
          flag = 1;
          break;
        }
    }
  
    if (flag==1) continue;
  
    for(u8 j=52; j<62; j++)
    {
      // Find numbers
      if(encr_str[i]==num[j])
      {
        mod = j - 4;
        encr_str[i] = mod;
        flag = 1;
        break;
      }
    }

    if (flag==1) continue;
  
    // Find enter
    if (encr_str[i] == 10 || encr_str[i] == 13) newch = encr_str[i];
  
    // Spaces
    if (encr_str[i] == 32) newch = encr_str[i];
  
    // Tab
    if(encr_str[i] == 9) newch = encr_str[i];
  
    // Special symbols
    if(encr_str[i] >= 97 && encr_str[i] <= 111) newch = encr_str[i] - 64;
  
    // Special symbols
    if(encr_str[i] >= 112 && encr_str[i] <= 118) newch = encr_str[i] - 54;
  
    // Special symbols
    if(encr_str[i] >= 119 && encr_str[i] <= 124) newch = encr_str[i] - 28;
    
    // Special symbols
    if(encr_str[i] >= 83 && encr_str[i] <= 86) newch = encr_str[i] + 40;

    encr_str[i] = newch;
  }
  return encr_str;
}



