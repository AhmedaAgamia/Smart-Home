/*
 * ADC_priv.h
 *
 *  Created on: Feb 16, 2023
 *      Author: aya_enan
 */

#ifndef ADC_ADC_PRIV_H_
#define ADC_ADC_PRIV_H_

#define  ADC_POLLING  0
#define  ADC_INT      1

#define ADMUX_REG   (*((volatile u8*)0x27))  // select channel , left adjust , Vref
#define ADCSRA_REG   (*((volatile u8 *)0x26)) // select prescaler , Interrupt Enable

#define ADC_REG      (*((volatile u16 *)0x24))
#define SFIOR_REG    (*((volatile u8 *)0x50))

// ADMUX_REG
#define ADLAR_BIT    5 // left adjust

// ADCSRA_REG
#define ADIE_BIT    3 // Interrupt Enable
#define ADIF_BIT    4 // Interrupt flag
#define ADATE_BIT   5 // auto trigger
#define ADSC_BIT    6 // start conversion
#define ADEN_BIT    7 // ADC Enable

#define ADC_PRESCALER_MASK  0b11111000 // 0xF8
#define ADC_CHANNEL_MASK    0b11100000 //0xE0
#define ADC_VREF_MASK       0b00111111 //0x3F


#define ADC_VREF_SHIFT    6
#endif /* ADC_ADC_PRIV_H_ */
