/*
 * WDT_priv.h
 *
 *  Created on: Feb 15, 2023
 *      Author: aya_enan
 */

#ifndef WDT_WDT_PRIV_H_
#define WDT_WDT_PRIV_H_

//registers
#define WDTCR_REG (*((volatile u8*)0x41 ))

// bits

#define WDE_BIT    3  // watch dog Enable
#define WDTOE_BIT  4  //Watchdog Turn-off Enable

// WDT prescaler
#define WDT_PRESCALER_MASK  0b11111000 // 0xF8
#endif /* WDT_WDT_PRIV_H_ */
