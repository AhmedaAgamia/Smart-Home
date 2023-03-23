/*
 * GIE_prg.c
 *
 *  Created on: Feb 7, 2023
 *      Author: AgAmIa
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GIE_priv.h"
#include "GIE_int.h"
#include "GIE_config.h"

void M_GIE_void_enable(void)
 {
	//method 1 :
	//  SET_BIT(SREG_REG,I_BIT);
	//METHOD 2:

	asm("SEI");

 }
void M_GIE_void_disable(void)
{
	//method 1 :
	//CLR_BIT(SREG_REG,I_BIT);

	//method 2:
	asm("CLI");
}
