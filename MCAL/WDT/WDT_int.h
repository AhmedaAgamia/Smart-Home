/*
 * WDT_int.h
 *
 *  Created on: Feb 15, 2023
 *      Author: aya_enan
 */

#ifndef WDT_WDT_INT_H_
#define WDT_WDT_INT_H_

#define WDT_TIMEOUT_16_3_MS       0 // 000
#define WDT_TIMEOUT_32_5_MS       1 // 001
#define WDT_TIMEOUT_65_MS         2 // 010
#define WDT_TIMEOUT_0_13_S        3
#define WDT_TIMEOUT_0_26_S        4
#define WDT_TIMEOUT_0_52_S        5
#define WDT_TIMEOUT_1_0_S         6
#define WDT_TIMEOUT_2_1_S         7

void M_WDT_void_enable(void);// turn on WDT
void M_WDT_void_disable(void);// turn off WDT
void M_WDT_void_sleep(u8 copy_timeOut );// timeout
void M_WDT_void_refersh(void);

#endif /* WDT_WDT_INT_H_ */
