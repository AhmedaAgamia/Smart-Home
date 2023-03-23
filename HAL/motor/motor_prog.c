/*
 * motor_prog.c
 *
 *  Created on: Feb 22, 2023
 *      Author: mohamed
 */
#include "STD_TYPES.h"
#include "Dio_int.h"


void H_DcMotor_void_init(void)
{
	M_Dio_void_setPinDir(PORTB_ID ,PIN0_ID ,OUPUT);
}
void H_DcMotor_void_ON(void)
{
	M_Dio_void_setPinValue(PORTB_ID,PIN0_ID,HIGH);
}
void H_DcMotor_void_OF(void)
{
	M_Dio_void_setPinValue(PORTB_ID,PIN0_ID,LOW);
}
