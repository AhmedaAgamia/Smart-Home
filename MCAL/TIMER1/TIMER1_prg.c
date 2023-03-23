/*
 * TIMER1_prg.c
 *
 *  Created on: Feb 15, 2023
 *      Author: AgAmIa
 */

#include   <avr/interrupt.h>
#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include   "TIMER1_priv.h"
#include   "TIMER1_config.h"
#include   "TIMER1_int.h"



static void (*ICU_CallBackPtr)(void) = NULL;
void M_TIMER1_void_init(void)
{
	//step one set normal mode
	CLR_BIT(TCCR1A_REG , WGM10_BIT);
	CLR_BIT(TCCR1A_REG , WGM11_BIT);

	CLR_BIT(TCCR1B_REG , WGM12_BIT);
	CLR_BIT(TCCR1B_REG , WGM13_BIT);

	//step2 :set prescaler as 256
	CLR_BIT(TCCR1B_REG , CS10_BIT);
	CLR_BIT(TCCR1B_REG , CS11_BIT);
	SET_BIT(TCCR1B_REG , CS12_BIT);



}
void M_TIMER1_ICU_void_init(void) //setup initial trigger for ICU
{
	//set initial trigger as rising rdge
	SET_BIT(TCCR1B_REG , ICES1_BIT);

}
void M_TIMER1_ICU_void_IntEnable(void)
{
	//enable interrupt
	SET_BIT(TIMSK_REG , TICIE1_BIT);
}
void M_TIMER1_ICU_void_IntDisable(void)
{
	//disable interrupt
	CLR_BIT(TIMSK_REG , TICIE1_BIT);
}
void M_TIMER1_ICU_void_setTrigg(u8 copy_u8Trigg)
{
	switch(copy_u8Trigg)
	{
	case  TIMER1_ICU_FALL_TRIGG  :
		CLR_BIT(TCCR1B_REG , ICES1_BIT);
	break;
	case  TIMER1_ICU_RISING_TRIGG :
	     SET_BIT(TCCR1B_REG , ICES1_BIT);
	break;
	}
}
void M_TIMER1_ICU_void_setCallBack(void (*ptrfn)(void))
{
	if(ptrfn != NULL)
	{
		ICU_CallBackPtr = ptrfn;
	}
}
ISR(TIMER1_CAPT_vect)
{
	if(ICU_CallBackPtr != NULL)
	{
		ICU_CallBackPtr();
	}
}

u16  M_TIMER1_ICU_u16_takeReading(void)
{
	return ICR1_REG;
}
