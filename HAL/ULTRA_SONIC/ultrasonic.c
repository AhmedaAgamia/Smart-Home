/*
 * ultrasonic.c
 *
 *  Created on: Feb 20, 2023
 *      Author: mohamed
 */
#include<util/delay.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "Dio_int.h"

#define TCCR1A  (*((volatile u8*)0x4F))
#define TCCR1B  (*((volatile u8*)0x4E))


#define TIFR  (*((volatile u8*)0x58))

#define TCNT1  (*((volatile u16*)0x4c))

#define ICR1  (*((volatile u16*)0x46))

#define ICF1	5




void ultrasonic_vinit(u8 triger_port,u8 triger_pin)
{
	M_Dio_void_setPinDir(triger_port,triger_pin,OUPUT);
}

u16 ultrasonic_u16distance(u8 triger_port,u8 triger_pin)
{
	u16 a , b , high , distance;
	TCCR1A = 0;
	//TIFR = (1<<ICF1);
	SET_BIT(TIFR,ICF1);
	M_Dio_void_setPinValue(triger_port,triger_pin,HIGH);
	_delay_us(50);
	M_Dio_void_setPinValue(triger_port,triger_pin,LOW);

	TCCR1B = 0XC1;
	while(0 == GET_BIT(TIFR,ICF1));
	a = ICR1;
	//TIFR = (1<<ICF1);
	SET_BIT(TIFR,ICF1);
	TCCR1B = 0X81;
	while(0 == GET_BIT(TIFR,ICF1));
	b = ICR1;
	//TIFR = (1<<ICF1);
	SET_BIT(TIFR,ICF1);
	TCNT1 = (u16)0;
	TCCR1B = 0;
	high = b - a;
	distance = ((f32)(high*34600)/(16000000UL*2));
	return distance;
}
