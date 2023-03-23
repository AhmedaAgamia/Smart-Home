/*
 * ADC_int.h
 *
 *  Created on: Feb 16, 2023
 *      Author: aya_enan
 */

#ifndef ADC_ADC_INT_H_
#define ADC_ADC_INT_H_

typedef enum {
      prescaler_2 = 1, // 1
	  prescaler_4, //2
	  prescaler_8,
	  prescaler_16,
	  prescaler_32,
	  prescaler_64,
	  prescaler_128

}prescaler_t;

typedef enum{
   vref_AREF ,
   vref_AVCC,
   vref_Internal = 3 // 2.56 volt
}vref_t;

typedef enum{
   channel_0,//temp sensor
   channel_1,//smock
   channel_2,
   channel_3,
   channel_4,
   channel_5,
   channel_6,
   channel_7,
}channel_t;

void M_ADC_void_Init(prescaler_t copy_prescaler ,vref_t  copy_vref );
u16 M_ADC_u16_adcRead(channel_t copy_channel );

#endif /* ADC_ADC_INT_H_ */
