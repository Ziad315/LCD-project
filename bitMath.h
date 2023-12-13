/*
 * BITMATH.h
 *
 *  Created on: 7 Dec 2023
 *      Author: User
 */

#ifndef AVR_DRIVER_LIB_BITMATH_H_
#define AVR_DRIVER_LIB_BITMATH_H_

#define CLR_BIT(VAR,BITNO) VAR &=~(1<<BITNO)
#define SET_BIT(VAR,BITNO)   VAR |=(1<<BITNO)
#define TOG_BIT(VAR,BITNO)   VAR ^=(1<<BITNO)
#define GET_BIT(VAR,BITNO)  (VAR>>BITNO)&1

#endif /* AVR_DRIVER_LIB_BITMATH_H_ */

