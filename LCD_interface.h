/*
 * LCD_interface.h
 *
 *  Created on: 12 Dec 2023
 *      Author: Ziad Yakoot
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidinit                  (void);
void LCD_sendData                  (uint8 copy_Data);
void LCD_sendCommand               (uint8 copy_Command);
void LCD_SendFallingEdge            (void);

#endif /* LCD_INTERFACE_H_ */
