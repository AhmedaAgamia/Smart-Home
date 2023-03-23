/*
 * ADC_prg.c
 *
 *  Created on: Feb 16, 2023
 *      Author: aya_enan
 */
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_priv.h"
#include "ADC_config.h"
#include "ADC_int.h"

u16 gADC_value = 0;
void M_ADC_void_Init(prescaler_t copy_prescaler ,vref_t  copy_vref )
{
  // step 1 : config prescaler
    // step : apply mask
	ADCSRA_REG &= ADC_PRESCALER_MASK;

	// step :insert value
	ADCSRA_REG |=  copy_prescaler;

  // step 3 : config right adjust
    CLR_BIT(ADMUX_REG,ADLAR_BIT);

#if (ADC_TYPE == ADC_POLLING)
    //step 2 : Disable Interrupt
    	CLR_BIT(ADCSRA_REG,ADIE_BIT);
    // step 4 : disable auto trigger
    CLR_BIT(ADCSRA_REG , ADATE_BIT);
#elif (ADC_TYPE == ADC_INT)
    // step 4 : Enable auto trigger
    SET_BIT(ADCSRA_REG,ADATE_BIT);
    //(start conversion )
    SET_BIT(ADCSRA_REG , ADSC_BIT);
    SET_BIT(ADCSRA_REG,3);// Interrupt Enable
#endif
  // step 5 : chose vref
	// step : apply mask
    ADMUX_REG &= ADC_VREF_MASK;
	// step :insert value
    ADMUX_REG |= copy_vref << ADC_VREF_SHIFT;
  // step 6 : Enable ADC
    SET_BIT(ADCSRA_REG , ADEN_BIT);
}
#if (ADC_TYPE == ADC_POLLING)
u16 M_ADC_u16_adcRead(channel_t copy_channel )
{

	// step 1 : config channel
	     // step : apply mask
	     ADMUX_REG  &= ADC_CHANNEL_MASK;
		// step :insert value
	     ADMUX_REG  |= copy_channel;
	// step 2 : for single Conversion (start conversion )
      SET_BIT(ADCSRA_REG , ADSC_BIT);
	// step 3 : polling wait until conversion is done
      while((GET_BIT(ADCSRA_REG , ADIF_BIT))== 0);
    //  while(SET_BIT(ADCSRA_REG , ADSC_BIT)== 0);
     // SET_BIT(ADCSRA_REG , ADIF_BIT);
	// step 4 : return digital value
    return ADC_REG;
}
#elif  (ADC_TYPE == ADC_INT)
   ISR(ADC_vect)
   {
	   SET_BIT(ADCSRA_REG,ADSC_BIT);

	   	// put adc reading in a global variable
	   	gADC_value = ADC_REG;
   }
#endif
