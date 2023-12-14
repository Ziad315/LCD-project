/*
 * LCD_cgf.h
 *
 *  Created on: 12 Dec 2023
 *      Author: Ziad Yakoot
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_Mode                            4                       /*SET LCD Mode ( 4 bits , 8 bits)*/


#define LCD_CONTROL_PORT                 DIO_PORTB
/*RS RW EN*/

#define LCD_DATA_PORT                    DIO_PORTA

/*LCD Commands*/
#define SET_HOME        	             0x02
#define Four_bits            	       	 0x28
#define DISPLAY_ON_CURSOR_OFF   	     0x0c
#define DISPLAY_CLEAR               	 0x01
#define ENTRY_MODE                  	 0x06


/*Control Pins*/
#define LCD_RS                     	 	 PIN1
#define LCD_RW                      	 PIN2
#define LCD_EN                      	 PIN3

#endif /* LCD_CFG_H_ */
