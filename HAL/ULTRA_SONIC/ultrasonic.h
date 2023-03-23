/*
 * ultrasonic.h
 *
 *  Created on: Feb 20, 2023
 *      Author: mohamed
 */

#ifndef ULTRA_SONIC_ULTRASONIC_H_
#define ULTRA_SONIC_ULTRASONIC_H_

#include "STD_TYPES.h"

void ultrasonic_vinit(u8 triger_port,u8 triger_pin);
u16 ultrasonic_u16distance(u8 triger_port,u8 triger_pin);


#endif /* ULTRA_SONIC_ULTRASONIC_H_ */
