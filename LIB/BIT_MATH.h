/*
 * BIT_MATH.h
 *
 *  Created on: Jan 30, 2023
 *  Author: Ahmed Tarek Youssef
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)  (  reg |= (1<<(bit))  )

#define CLR_BIT(reg,bit)  (  reg &= ~(1<<(bit)) )

#define TOG_BIT(reg,bit)  (  reg ^= (1<<(bit))  )

#define GET_BIT(reg,bit)  ( (reg>>(bit)) & 0x01 )

#endif /* BIT_MATH_H_ */
