/*
 * DIO_program.c
 *
 *  Created on: 8 Dec 2023
 *      Author: Ziad Yakoot
 */

#include "STD_types.h"
#include "bitMath.h"
#include "DIO_Reg.h"
#include "DIO_interface.h"

/*Set pin direction INPUT or OUTPUT*/
uint8 DIO_setPinDirection(uint8 copy_port ,uint8 copy_pin ,uint8 copy_direction )
{
	uint8 local_errorStatus=0;
	if(copy_pin <= PIN7)
	{
		if(copy_direction == OUTPUT)
		{
			switch(copy_port)
	       {
				case DIO_PORTA: SET_BIT(DDRA ,copy_pin); break;
				case DIO_PORTB: SET_BIT(DDRB ,copy_pin);break;
				case DIO_PORTC: SET_BIT(DDRC ,copy_pin);break;
                case DIO_PORTD: SET_BIT(DDRD ,copy_pin);break;
                default:local_errorStatus=1;break;
	       }
		}
		else if(copy_direction ==INPUT)
		{
                switch(copy_port)
                {
					case DIO_PORTA: CLR_BIT(DDRA ,copy_pin);break;
					case DIO_PORTB: CLR_BIT(DDRB ,copy_pin);break;
					case DIO_PORTC: CLR_BIT(DDRC ,copy_pin);break;
					case DIO_PORTD: CLR_BIT(DDRD ,copy_pin);break;
					default:local_errorStatus=1;break;
                }
		}
	}
	else
	{
		local_errorStatus=1;
	}

	return local_errorStatus;
}

/*Set pin Value LOW or HIGH*/
uint8 DIO_setPinValue(uint8 copy_port,uint8 copy_pin,uint8 copy_val)
{
	uint8 local_errorStatus=0;
		if(copy_pin <= PIN7)
		{
			if(copy_val == HIGH)
			{
				switch(copy_port)
				       {
							case DIO_PORTA: SET_BIT(PORTA ,copy_pin);break;
							case DIO_PORTB: SET_BIT(PORTB ,copy_pin);break;
							case DIO_PORTC: SET_BIT(PORTC ,copy_pin);break;
			                case DIO_PORTD: SET_BIT(PORTD ,copy_pin);break;
			                default:local_errorStatus=1;break;
				       }
			}
			else if(copy_val == LOW)
			{
			    switch(copy_port)
			                {
								case DIO_PORTA: CLR_BIT(PORTA ,copy_pin);break;
								case DIO_PORTB: CLR_BIT(PORTB ,copy_pin);break;
								case DIO_PORTC: CLR_BIT(PORTC ,copy_pin);break;
								case DIO_PORTD: CLR_BIT(PORTD ,copy_pin);break;
								default:local_errorStatus=1;break;
			                }
			}
			else
			{
				local_errorStatus=1;
			}
		}
		return local_errorStatus;

}
/*This Function Set PORT value to be INPUT or OUTPUT*/
uint8 DIO_setPortDirection(uint8 copy_port,uint8 copy_direction)
{
	uint8 local_errorStatus=0;
	if(copy_direction== OUTPUT)
	{
		switch(copy_port)
		{
		case DIO_PORTA:DDRA =0xff;break;
		case DIO_PORTB:DDRB =0xff;break;
		case DIO_PORTC:DDRC =0xff;break;
		case DIO_PORTD:DDRD =0xff;break;
		default:local_errorStatus=1;break;
		}
	}
	else if(copy_direction ==INPUT)
	{
		switch(copy_port)
			{
			case DIO_PORTA:DDRA =0x00;break;
			case DIO_PORTB:DDRB =0x00;break;
			case DIO_PORTC:DDRC =0x00;break;
			case DIO_PORTD:DDRD =0x00;break;
			default:local_errorStatus=1;break;
			}
	}
	else
	{
		local_errorStatus=1;
	}
	return local_errorStatus;
}
/*This Function Set PORT value to HIGH or LOW*/
uint8 DIO_uint8_setPortValue(uint8 copy_port,uint8 copy_val)
{
	uint8 local_errorStatus=0;
		if(copy_val== HIGH)
		{
			switch(copy_port)
			{
			case DIO_PORTA:PORTA =0xff;break;
			case DIO_PORTB:PORTB =0xff;break;
			case DIO_PORTC:PORTC =0xff;break;
			case DIO_PORTD:PORTD =0xff;break;
			default:local_errorStatus=1;break;
			}
		}
		else if(copy_val == LOW)
		{
			switch(copy_port)
				{
				case DIO_PORTA:PORTA =0x00;break;
				case DIO_PORTB:PORTB =0x00;break;
				case DIO_PORTC:PORTC =0x00;break;
				case DIO_PORTD:PORTD =0x00;break;
				default:local_errorStatus=1;break;
				}
		}
		else
		{
			local_errorStatus=1;
		}
		return local_errorStatus;
}

/*This function is to read from the PIN register is it HIGH or LOW USED WITH INPUTS*/
uint8 DIO_uint8_getPinValue(uint8 copy_port,uint8 copy_pin,uint8 *copy_pinValue)
{
	uint8 local_errorStatus=0;
	if(copy_pin <= PIN7)
	{
		switch(copy_port)
				 {
							case DIO_PORTA:*copy_pinValue=GET_BIT(PINA ,copy_pin);break;
							case DIO_PORTB:*copy_pinValue=GET_BIT(PINB ,copy_pin);break;
							case DIO_PORTC:*copy_pinValue=GET_BIT(PINC ,copy_pin);break;
							case DIO_PORTD:*copy_pinValue=GET_BIT(PIND ,copy_pin);break;
							default:local_errorStatus =1;break;
				 }
	}
	else
	{
		local_errorStatus =1;
	}




  return local_errorStatus;
}

uint8 DIO_TogPinValue(uint8 copy_port,uint8 copy_pin,uint8 copy_val)
{
	uint8 local_errorStatus=0;
	if(copy_pin <= PIN7)
	{
		switch(copy_port)
				 {
							case DIO_PORTA:TOG_BIT(PINA ,copy_pin);break;
							case DIO_PORTB:TOG_BIT(PINB ,copy_pin);break;
							case DIO_PORTC:TOG_BIT(PINC ,copy_pin);break;
							case DIO_PORTD:TOG_BIT(PIND ,copy_pin);break;
							default:local_errorStatus =1;break;
				 }
	}
	else
	{
		local_errorStatus =1;
	}
	return local_errorStatus;
}




void DIO_setInterrnalalPullup(uint8 copy_Port ,uint8 copy_pin)
{
  /*set pin as input*/
	DIO_setPinDirection(copy_Port ,copy_pin ,INPUT);
  /*output high*/
	DIO_setPinValue(copy_Port, copy_pin,HIGH);
}


uint8 DIO_setHighFourPins(uint8 copy_Port ,uint8 copy_val)
{
	uint8 local_errorStatus=0;
			if(copy_Port <= DIO_PORTD)
			{
		     copy_val=(copy_val<<4);
		     switch(copy_Port)
		     				 {
		     							case DIO_PORTA:PORTA&=0x0f; PORTA|=copy_val;break;
		     							case DIO_PORTB:PORTB&=0x0f; PORTB|=copy_val;break;
		     							case DIO_PORTC:PORTC&=0x0f; PORTC|=copy_val;break;
		     							case DIO_PORTD:PORTD&=0x0f; PORTD|=copy_val;break;
		     							default:local_errorStatus =1;break;
		     				 }

			}
			else
			{
				local_errorStatus =1;
			}

	return local_errorStatus;
}



