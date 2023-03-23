/*
 * EXTI_prg.c
 *
 *  Created on: Feb 7, 2023
 *      Author: AgAmIa
 */
#include "avr/interrupt.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXIT_priv.h"
#include "EXIT_int.h"
#include "EXIT_config.h"

//ARRAY of 3 pointers to functions (Call_Back_fn
static void(*Arr_CallBack[3]) (void)={NULL,NULL,NULL};

void M_EXIT_void_Enable(u8 copy_u8IntID, u8 copy_u8Sense)
{
    //STEP 1 : CONFIG SENSE
	if(copy_u8Sense < EXIT_TRIG_LOW_LEVEL || copy_u8Sense >EXIT_TRIG_FALL_EDGE )
	{
		return ;
	}

	switch (copy_u8IntID)
		  {
		     case EXIT_INT0_ID:
		    	 //step 1 : applyt mask
		    	 MCUCR_REG &= EXIT_INT0_TRIG_MASK;
		    	 //step 2 : insert value
				 MCUCR_REG |= copy_u8Sense;
                  break ;
		     case EXIT_INT1_ID:
		    	 //step 1 : applyt mask
		    	 	MCUCR_REG &= EXIT_INT1_TRIG_MASK;
		       	 //step 2 : insert value
					MCUCR_REG |= copy_u8Sense << EXIT_INT1_TRIG_SHIFT ;
					break;
		     case EXIT_INT2_ID:
		    	 //step 1 : applyt mask
		    	 CLR_BIT(MCUCSR_REG , ISC2_BIT);
		    	 //step 2 : insert value
		    	   //  (reg |= 1 <<(bit));
		    	 MCUCSR_REG |= (GET_BIT(copy_u8Sense , 0))<< EXIT_INT2_TRIG_SHIFT;
		    	 break;
		  }


	//STEP 2 : ENABLE PIE
		    	 if (copy_u8IntID>=EXIT_INT2_ID && copy_u8IntID <= EXIT_INT1_ID)
		    	 		SET_BIT(GICR_REG , copy_u8IntID);

}


void M_EXIT_void_Disable(u8 copy_u8IntID)
 {
	//method 1
	/* switch (u8 copy_u8IntID)
	 * {
	 *    case EXIT_INT0_ID:
	 *        CLR_BIT(GICR_REG , INT0_BIT)
	 *        break;
	 *     case EXIT_INT1_ID:
	 *        CLR_BIT(GICR_REG , INT1_BIT)
	 *        break;
	 *
	 *     case EXIT_INT2_ID:
	 *        CLR_BIT(GICR_REG , INT2_BIT)
	 *        break;
 	 * }
	 */
	//method 2
	if (copy_u8IntID>=EXIT_INT2_ID && copy_u8IntID <= EXIT_INT1_ID)
		CLR_BIT(GICR_REG , copy_u8IntID);
 }


void M_EXIT_void_setCallBack(void (*ptrfn) (void), u8 copy_u8IntID)
{
	switch (copy_u8IntID)
	{
     case EXIT_INT0_ID:
    	 Arr_CallBack[0] = ptrfn;
    	 break;
     case EXIT_INT1_ID:
          Arr_CallBack[1] = ptrfn;
       	 break;
     case EXIT_INT2_ID:
       	 Arr_CallBack[2] = ptrfn;
       	 break;
	}
}

ISR(INT0_vect)
{
	if(Arr_CallBack[0]  !=NULL )
	{
		Arr_CallBack[0]();
	}
}

ISR(INT1_vect)
{
	if(Arr_CallBack[1]  !=NULL )
		{
			Arr_CallBack[1]();
		}
}
ISR(INT2_vect)
{
	if(Arr_CallBack[2]  !=NULL )
		{
			Arr_CallBack[2]();
		}
}
