/*
 * DIO_Reg.h
 *
 *  Created on: 8 Dec 2023
 *      Author: Ziad Yakoot
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_


#define DDRA      (*(volatile uint8*)0x3a)
#define DDRB      (*(volatile uint8*)0x37)
#define DDRC      (*(volatile uint8*)0x34)
#define DDRD      (*(volatile uint8*)0x31)

#define PORTA     (*(volatile uint8*)0x3b)
#define PORTB     (*(volatile uint8*)0x38)
#define PORTC     (*(volatile uint8*)0x35)
#define PORTD     (*(volatile uint8*)0x32)


#define PINA     (*(volatile uint8*)0x39)
#define PINB     (*(volatile uint8*)0x36)
#define PINC     (*(volatile uint8*)0x33)
#define PIND     (*(volatile uint8*)0x30)




#endif /* DIO_REG_H_ */
