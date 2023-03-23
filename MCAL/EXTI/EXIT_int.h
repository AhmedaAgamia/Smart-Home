/*
 * EXIT_int.h
 *
 *  Created on: Feb 7, 2023
 *      Author: AgAmIa
 */

#ifndef MCAL_EXTI_EXIT_INT_H_
#define MCAL_EXTI_EXIT_INT_H_

//EXIT SENSE CONTROL TIGGER
#define EXIT_TRIG_LOW_LEVEL   0
#define EXIT_TRIG_ANY_CHANGE  1
#define EXIT_TRIG_FALL_EDGE   2
#define EXIT_TRIG_RAIS_EDGE   3

//
#define EXIT_INT0_ID  6
#define EXIT_INT1_ID  7
#define EXIT_INT2_ID  5

void M_EXIT_void_Enable(u8 copy_u8IntID, u8 copy_u8sense);
void M_EXIT_void_Disable(u8 copy_u8IntID);
void M_EXIT_void_setCallBack(void (*ptrfn) (void), u8 copy_u8IntID);
#endif /* MCAL_EXTI_EXIT_INT_H_ */
