/*
 * DIO_interface.h
 *
 *  Created on: 8 Dec 2023
 *      Author: Ziad Yakoot
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0


/*Functions*/
uint8 DIO_setPinDirection(uint8 copy_Port ,uint8 copy_pin ,uint8 copy_direction );
uint8 DIO_setPinValue(uint8 copy_port,uint8 copy_pin,uint8 copy_val);
uint8 DIO_setPortDirection(uint8 copy_port,uint8 copy_direction);
uint8 DIO_uint8_setPortValue(uint8 copy_port,uint8 copy_val);
uint8 DIO_uint8_getPinValue(uint8 copy_port,uint8 copy_pin,uint8 *copy_pinValue);
void DIO_setInterrnalalPullup(uint8 copy_Port ,uint8 copy_pin);
uint8 DIO_TogPinValue(uint8 copy_port,uint8 copy_pin,uint8 copy_val);
uint8 DIO_setHighFourPins(uint8 copy_Port ,uint8 copy_val);


#endif /* DIO

INTERFACE_H_ */
