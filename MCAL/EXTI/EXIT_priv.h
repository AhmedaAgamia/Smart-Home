/*
 * EXTI_priv.h
 *
 *  Created on: Feb 7, 2023
 *      Author: AgAmIa
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_



#define MCUCR_REG     (*((volatile u8*)0x55))   // control trigger
#define MCUCSR_REG    (*((volatile u8*)0x54))   // control trigger
#define GICR_REG      (*((volatile u8*)0x5B))   // control PIE for (INT
#define GUFR_REG


//MCUCR_REG bits
#define  ISC00_BIT  0
#define  ISC01_BIT  1
#define  ISC10_BIT  2
#define  ISC11_BIT  3



//MCUCSR_REG
#define ISC2_BIT    6


//GICR_REG
#define INT2_BIT    5
#define INT0_BIT    6
#define INT1_BIT    7


#define EXIT_INT0_TRIG_MASK        0b11111100 // 0xFC
#define EXIT_INT1_TRIG_MASK        0b11110011 // 0xF3

#define EXIT_INT1_TRIG_SHIFT   2
#define EXIT_INT2_TRIG_SHIFT   6

#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
