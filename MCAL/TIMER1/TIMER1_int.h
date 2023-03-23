/*
 * TIMER1_int.h
 *
 *  Created on: Feb 15, 2023
 *      Author: AgAmIa
 */

#ifndef MCAL_TIMER1_TIMER1_INT_H_
#define MCAL_TIMER1_TIMER1_INT_H_

#define TIMER1_ICU_FALL_TRIGG       0
#define TIMER1_ICU_RISING_TRIGG     1


void M_TIMER1_void_init(void);
void M_TIMER1_ICU_void_init(void);
void M_TIMER1_ICU_void_IntEnable(void);
void M_TIMER1_ICU_void_IntDisable(void);
void M_TIMER1_ICU_void_setTrigg(u8 copy_u8Trigg);
u16  M_TIMER1_ICU_u16_takeReading(void);
void M_TIMER1_ICU_void_setCallBack(void (*ptrfn)(void));



#endif /* MCAL_TIMER1_TIMER1_INT_H_ */
