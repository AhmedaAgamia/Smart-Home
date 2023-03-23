/*
 * WDT_prg.c
 *
 *  Created on: Feb 15, 2023
 *      Author: aya_enan
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDT_priv.h"
#include "WDT_config.h"
#include "WDT_int.h"
void M_WDT_void_enable(void)// turn on WDT
{
   SET_BIT(WDTCR_REG ,WDE_BIT);
}
void M_WDT_void_disable(void)// turn off WDT
{
	WDTCR_REG |= (1<<WDTOE_BIT) | (1<<WDE_BIT);
	/* Turn off WDT */
	WDTCR_REG = 0x00;
}
void M_WDT_void_sleep(u8 copy_timeOut )// timeout
{
	if (copy_timeOut >= WDT_TIMEOUT_16_3_MS && copy_timeOut <= WDT_TIMEOUT_2_1_S)
	{
		// step 1 : apply mask
			WDTCR_REG &= WDT_PRESCALER_MASK;
		// step 2 : insert value
			WDTCR_REG |= copy_timeOut;
	}

}
void M_WDT_void_refersh(void)
{
   asm("WDR");
}
