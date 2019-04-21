/*
 * Header file for Ublaze Application
 *
 *  Created on: Apr 20, 2019
 *      Author: Benjamin Kueffler
 */

#include "xtmrctr.h"

#ifndef UBLAZE_APP_FUNCTIONS_H_
#define UBLAZE_APP_FUNCTIONS_H_

// Enables the timer and resets the inital timer value to the parameters
void init_64b_timer(u32 t0_value, u32 t1_value);

// Gets the 64 bit time, where each timer represents 32 bits
u64 get_64b_time();

#endif /* UBLAZE_APP_H_ */
