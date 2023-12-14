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
	LCD_voidString("Hello World !");
	_delay_ms(1000);
	LCD_ClearScreen();
	LCD_voidString("Ziad Yakoot");

}


