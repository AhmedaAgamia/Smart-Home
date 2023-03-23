/*
 * TIMER_priv.h
 *
 *  Created on: Feb 8, 2023
 *      Author: AgAmIa
 */

#ifndef MCAL_TIMER_TIMER_PRIV_H_
#define MCAL_TIMER_TIMER_PRIV_H_



#define TCNT0_REG        (*((volatile u8 *)0x52))    //counter register
#define TCCR0_REG        (*((volatile u8 *)0x53))    //compare match register
#define OCR0_REG         (*((volatile u8 *)0x5C))

#define TIMSK_REG        (*((volatile u8 *)0x59))  //PIE
#define TIFR_REG         (*((volatile u8 *)0x58))  //flags



// registers bits
//TCCR0_REG


#define WGM01_BIT     3
#define WGM00_BIT     6

//TIMSK_REG
#define TOIE0_BIT     0              //overflow interrupt enable
#define OCIE0_BIT     1              // compare match interrupt Enable


//
#define  TIMER0_PRESCALER_MASK   0b11111000  //0xF8
#define  TIMER0_OC0_MASK          0b11001111   //0xCF
#define  TIMER0_OC0_SHIFT          4


//timer modes
#define  TIMER0_NORMAL_MODE                        0
#define  TIMER0_CTC_MODE                           1
#define  TIMER0_FAST_PWM_MODE                      2
#define  TIMER0_PHASECORRECT_MODE                  3


//prescaler options
#define  TIMER0_PRESCALER_NO_CLOCK                 0
#define  TIMER0_PRESCALER_NO_PRESCALER             1
#define  TIMER0_PRESCALER_8                        2
#define  TIMER0_PRESCALER_64                       3
#define  TIMER0_PRESCALER_256                      4
#define  TIMER0_PRESCALER_1024                     5
#define  TIMER0_PRESCALER_EXTCLK_FALL_EDGE         6
#define  TIMER0_PRESCALER_EXTCLK_RAIS_EDGE         7


//OC0 pin mode options for non PWM
#define  TIMER0_OC0_MODE_DISSCONECTED              0
#define  TIMER0_OC0_MODE_TOGGLE                    1
#define  TIMER0_OC0_MODE_CLEAR                     2
#define  TIMER0_OC0_MODE_SET                       3


#endif /* MCAL_TIMER_TIMER_PRIV_H_ */
