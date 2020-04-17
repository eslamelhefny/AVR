/*
 * main.c
 *
 *  Created on: Mar 25, 2020
 *      Author: IOT scientist
 */
#include"avr/delay.h"
#include"../BIT_math.h"
#include"../STD_TYPES.h"
#include "DIO_int.h"
#include "INTERRUPT_int.h"

#define F_CPU 16000000ul
void led_on(void);
void main (void)
{
	DIO_vdSetPortDirection(PORTB,OUTPUT);
	DIO_vdSetPinDirection(PORTD,PIN2,INPUT);
	DIO_vdEnablePullUpRes(PORTD,PIN2);
	EXINT_vdSetExternalInterrupt(INT0,FALLING_EDGE);
	EXINT_vdSetCallBack(led_on);
	EXINT_vdEnableGlobalInt();

	while(1)
	{
		DIO_vdSetPinValue(PORTB,PIN0,HIGH);
		_delay_ms(500);
		DIO_vdSetPinValue(PORTB,PIN0,LOW);
		_delay_ms(500);

	}

}
void led_on(void)
{
	u8 i=0;
	for(i=0;i<10;i++)
		{
			DIO_vdSetPinValue(PORTB,PIN0,HIGH);
			_delay_ms(50);
			DIO_vdSetPinValue(PORTB,PIN0,LOW);
			_delay_ms(50);

		}

}
