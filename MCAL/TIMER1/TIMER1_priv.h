/*
 * TIMER1_priv.h
 *
 *  Created on: Feb 15, 2023
 *      Author: AgAmIa
 */

#ifndef MCAL_TIMER1_TIMER1_PRIV_H_
#define MCAL_TIMER1_TIMER1_PRIV_H_


#define TCCR1A_REG     (*((volatile u8 *)0x4F))
#define TCCR1B_REG     (*((volatile u8 *)0x4E))

#define ICR1_REG       (*((volatile u16 *)0x46))

#define TIMSK_REG      (*((volatile u8 *)0x59))  //PIEs

//TCCR1A_REG

#define   WGM10_BIT   0
#define   WGM11_BIT   1
//TCCR1B_REG
//RESCALER BITS
#define   CS10_BIT    0
#define   CS11_BIT    1
#define   CS12_BIT    2

//mode bits
#define   WGM12_BIT   3
#define   WGM13_BIT   4

//ICU bits
#define   ICES1_BIT     6 //eddge select
#define   ICNC1_BIT     7 //noise canceler

//TIMSK_REG
#define  TICIE1_BIT     5


#endif /* MCAL_TIMER1_TIMER1_PRIV_H_ */
