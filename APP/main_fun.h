/*
 * main_fun.h
 *
 *  Created on: Feb 23, 2023
 *      Author: AgAmIa
 */

#ifndef APP_MAIN_FUN_H_
#define APP_MAIN_FUN_H_


#include "STD_TYPES.h"

#define FAIL  0
#define PASS  1

void Init_system(void);         // initialize  system

void wlcome_screen(void);       //welcome screen before while

void update_US_read(void);         //get  ultrasonic read
u8 Take_action(void);
/*
 * 1- take password and check
 * 2- stop system of u try more than 3 times
 * 3- show the range of ultrasonic
 * 4- show the temp of room to know switch on or off of dc
 * 5- at the end this func return check
 */
void ALL_LEDS_ON(void);
void ALL_LEDS_OFF(void);
void DC_MOTOR(void) ;          // dc motor on and of and show temp




#endif /* APP_MAIN_FUN_H_ */
