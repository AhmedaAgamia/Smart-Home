/*
 * TIMER_prg.c
 *
 *  Created on: Feb 8, 2023
 *      Author: AgAmIa
 */
#include <avr/interrupt.h>
#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "TIMER_priv.h"
#include  "TIMER_config.h"
#include  "TIMER_int.h"

//static u32  NoOFDesiredTicks   = 0;
 static u32  NumberOFOverflows        = 0;
 static u32  NumberOFRemainingTicks   = 0;
 static void (*Arr_CallBack[2])(void)={NULL,NULL};
void M_TIMER0_void_Init(void)   //set timer mode , set Oc0 pin mode
{
	//step 1 : configer timer mode


#if(TIMER0_MODE== TIMER0_NORMAL_MODE)
		CLR_BIT(TCCR0_REG,WGM00_BIT);
		CLR_BIT(TCCR0_REG,WGM01_BIT);

	// step 2 :choose OC0 mode

      #if(TIMER0_OC0_MODE >= TIMER0_OC0_MODE_DISSCONECTED && TIMER0_OC0_MODE <= TIMER0_OC0_MODE_SET)
		//step 1  apply mask
	TCCR0_REG	&= TIMER0_OC0_MASK ;
	    //step 2 insert value
	TCCR0_REG   |=  (TIMER0_OC0_MODE <<	TIMER0_OC0_SHIFT);
      #else
         #error ("Wrong OC0 Mode")
      #endif


#elif(TIMER0_MODE ==	TIMER0_CTC_MODE )
		CLR_BIT(TCCR0_REG,WGM00_BIT);
		SET_BIT(TCCR0_REG,WGM01_BIT);

		// step 2 :choose OC0 mode

		      #if(TIMER0_OC0_MODE >= TIMER0_OC0_MODE_DISSCONECTED && TIMER0_OC0_MODE <= TIMER0_OC0_MODE_SET)
				//step 1  apply mask
			TCCR0_REG	&= TIMER_OC0_MASK ;
			    //step 2 insert value
			TCCR0_REG   |=  (TIMER_OC0_MODE <<	TIMER0_OC0_SHIFT);
		      #else
		         #error ("Wrong OC0 Mode")
		      #endif

#elif(TIMER0_MODE== TIMER0_FAST_PWM_MODE )
		SET_BIT(TCCR0_REG,WGM00_BIT);
		SET_BIT(TCCR0_REG,WGM01_BIT);

#elif(TIMER0_MODE== TIMER0_PHASECORRECT_MODE )
		SET_BIT(TCCR0_REG,WGM01_BIT);
		CLR_BIT(TCCR0_REG,WGM01_BIT);

#else
#error ("wrong timer Mode")

#endif


	// step 2 : under each mode configer OC0 mode pin mode
#if(TIMER0_OC0_MODE == TIMER0_OC0_MODE_DISSCONECTED)
		CLR_BIT(TCCR0_REG,WGM00_BIT);
		CLR_BIT(TCCR0_REG,WGM01_BIT);
	// step 2 :choose OC0 mode
#elif(TIMER0_MODE ==	TIMER0_CTC_MODE )
		CLR_BIT(TCCR0_REG,WGM00_BIT);
		SET_BIT(TCCR0_REG,WGM01_BIT);

#elif(TIMER0_MODE== TIMER0_FAST_PWM_MODE )
		SET_BIT(TCCR0_REG,WGM00_BIT);
		CLR_BIT(TCCR0_REG,WGM01_BIT);

#elif(TIMER0_MODE== TIMER0_PHASECORRECT_MODE )
		SET_BIT(TCCR0_REG,WGM01_BIT);
		CLR_BIT(TCCR0_REG,WGM01_BIT);

#else
#error ("wrong timer Mode")

#endif
}
void M_TIMER0_void_start(void) //set clock prescaler
{
#if(TIMER0_PRESCALER >=TIMER0_PRESCALER_NO_CLOCK && TIMER0_PRESCALER <= TIMER0_PRESCALER_EXTCLK_RAIS_EDGE )
	//step1  :apply mask
	TCCR0_REG &= TIMER0_PRESCALER_MASK ;

	//step 2 :insert value
	TCCR0_REG |=  TIMER0_PRESCALER;

#else
#error ("wrong")
#endif

}
void M_TIMER0_void_stop(void)  //no clock
{
	//step1  :apply mask
		TCCR0_REG &= TIMER0_PRESCALER_MASK ;

	//step 2 :insert value
	//	TCCR0_REG =  TIMER0_PRESCALER_NO_CLOCK

}
void M_TIMER0_void_setTime(u32 copy_u32timeMS)  //time in millie sec
{
	u32 Loc_prescalerArr[]={1,8,64,256,1024} ;
	f32 Loc_TickTime = (f32)Loc_prescalerArr[TIMER0_PRESCALER-1]  / FCPU ;
	u32 NoOFDesiredTicks = (copy_u32timeMS * 1000)/Loc_TickTime;
#if(TIMER0_MODE  ==  TIMER0_NORMAL_MODE)
	NumberOFOverflows = NoOFDesiredTicks/256 ;
	NumberOFRemainingTicks =NoOFDesiredTicks % 256 ;
	if(NumberOFRemainingTicks != 0)
	{
		TCNT0_REG = 256 - NumberOFRemainingTicks;
		NumberOFOverflows++;
	}
#elif(TIMER0_MODE ==  TIMER0_CTC_MODE)
#endif

}
void M_TIMER0_void_EnableInt(u8 copy_u8IntID)
{
	//method 1
	/*switch(copy_u8IntID)
	{
	case  TIMER0_OVF_INT_ID:
		SET_BIT(TIMSK_REG,TOIE0_BIT);
		break;

	case  TIMER0_CMP_INT_ID:
	    SET_BIT(TIMSK_REG,OCIE0_BIT);
	    break;
	}*/
	//method 2
	SET_BIT(TIMSK_REG,copy_u8IntID);

}
void M_TIMER0_void_DisableInt(u8 copy_u8IntID)
{
	//method 1
	switch(copy_u8IntID)
		{
		case  TIMER0_OVF_INT_ID:
			CLR_BIT(TIMSK_REG,TOIE0_BIT);
			break;

		case  TIMER0_CMP_INT_ID:
		    CLR_BIT(TIMSK_REG,OCIE0_BIT);
		    break;
		}
	//method 2
		CLR_BIT(TIMSK_REG,copy_u8IntID);

}
void M_TIMER0_void_setCallBack(void (*ptrfn)(void),u8 copy_u8IntID)
{
	//method 1
	switch(copy_u8IntID)
	{
	case   TIMER0_OVF_INT_ID:
		Arr_CallBack[0]=ptrfn;
		break;
	case   TIMER0_CMP_INT_ID:
		Arr_CallBack[1]=ptrfn;

		break;

	}

	//method 2
	Arr_CallBack[copy_u8IntID]=ptrfn;


}

ISR(TIMER0_OVF_vect)
{
	static u32 Loc_OVFCounter = 0;
	Loc_OVFCounter++;
	if(Loc_OVFCounter == NumberOFOverflows)
	{
		//
		TCNT0_REG = 256 - NumberOFRemainingTicks;
		//counter = 0
		Loc_OVFCounter = 0;
		//taeke action
	}

	if(Arr_CallBack[TIMER0_OVF_INT_ID]  != NULL)
	Arr_CallBack[TIMER0_OVF_INT_ID]() ;
}

ISR(TIMER0_COMP_vect)
{
	Arr_CallBack[TIMER0_OVF_INT_ID];

}

