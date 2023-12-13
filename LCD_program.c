/*
 * LCD_program.c
 *
 *  Created on: 12 Dec 2023
 *      Author: Ziad Yakoot
 */

#ifndef LCD_PROGRAM_C_
#define LCD_PROGRAM_C_
#include<util/delay.h>
#include "STD_types.h"
#include "bitMath.h"
#include "DIO_interface.h"
#include "LCD_cfg.h"
#include "LCD_interface.h"



void LCD_voidinit                  (void)
{
#if  LCD_Mode == 4

	_delay_ms(50);
	DIO_setPinDirection(LCD_DATA_PORT ,PIN4 ,OUTPUT);
	DIO_setPinDirection(LCD_DATA_PORT ,PIN5 ,OUTPUT);
	DIO_setPinDirection(LCD_DATA_PORT ,PIN6 ,OUTPUT);
	DIO_setPinDirection(LCD_DATA_PORT ,PIN7 ,OUTPUT);

	DIO_setPinDirection(LCD_CONTROL_PORT ,LCD_RS ,OUTPUT);
	DIO_setPinDirection(LCD_CONTROL_PORT ,LCD_RW ,OUTPUT);
	DIO_setPinDirection(LCD_CONTROL_PORT ,LCD_EN ,OUTPUT);

	LCD_sendCommand(SET_HOME);                     //Set Home
	_delay_ms(30);
	LCD_sendCommand(Four_bits);                    //Function set
	_delay_ms(1);
	LCD_sendCommand(DISPLAY_ON_CURSOR_OFF);        //display ON
	_delay_ms(1);
	LCD_sendCommand(DISPLAY_CLEAR);                //Display clear
	_delay_ms(10);
	LCD_sendCommand(ENTRY_MODE);                   //Entry Mode
	_delay_ms(1);

#endif
}



void LCD_sendData                  (uint8 copy_Data)
{
#if LCD_Mode == 4
	DIO_setPinValue(LCD_CONTROL_PORT ,LCD_RS,HIGH);
	DIO_setPinValue(LCD_CONTROL_PORT ,LCD_RW ,LOW);
	DIO_setHighFourPins(LCD_DATA_PORT,(copy_Data>>4));
	LCD_SendFallingEdge();
	DIO_setHighFourPins(LCD_DATA_PORT,copy_Data);
	LCD_SendFallingEdge();
#endif
}


void LCD_sendCommand                 (uint8 copy_Data)
{
#if LCD_Mode == 4
	DIO_setPinValue(LCD_CONTROL_PORT ,LCD_RS,LOW);
	DIO_setPinValue(LCD_CONTROL_PORT ,LCD_RW ,LOW);
	DIO_setHighFourPins(LCD_DATA_PORT,(copy_Data>>4));
	LCD_SendFallingEdge();
	DIO_setHighFourPins(LCD_DATA_PORT,copy_Data);
	LCD_SendFallingEdge();
#endif
}

void LCD_SendFallingEdge (void)
{
	DIO_setPinValue(LCD_CONTROL_PORT ,LCD_EN ,HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CONTROL_PORT ,LCD_EN ,LOW);
	_delay_ms(1);
}
#endif /* LCD_PROGRAM_C_ */
