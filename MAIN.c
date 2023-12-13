/*
 * MAIN.c
 *
 *  Created on: 12 Dec 2023
 *      Author: Ziad Yakoot
 */
#include<util/delay.h>
#include "STD_types.h"
#include "bitMath.h"
#include "DIO_interface.h"
#include "LCD_interface.h"

int main(void)
{
		LCD_voidinit();
		_delay_ms(100);
		LCD_sendData('Z');
		LCD_sendData('I');
		LCD_sendData('A');
		LCD_sendData('D');
		LCD_sendData(' ');
		LCD_sendData('Y');
		LCD_sendData('A');
		LCD_sendData('K');
		LCD_sendData('O');
		LCD_sendData('O');
		LCD_sendData('T');

}


