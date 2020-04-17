/*
 * main.c
 *
 *  Created on: Jan 23, 2020
 *      Author: IOT scientist
 */
#include"avr\delay.h"
#include "STD_TYPES.H"
#include "DIO_int.h"
u8 u8_7Segment_arr[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void LED_SHIFTING(void);
void LED_SNACK_EFFECT(void);
void LED_CONVERGING(void);
void LED_DIVERSION(void);
void vd_7segment_print_numbers(void);
u8 u8counter = 0;
void main(void)
{
	DIO_vdSetPortDirection(PORTB,OUTPUT);
	while (1)
	{
		vd_7segment_print_numbers();

	}
}

void LED_SHIFTING(void)
{
	for (u8counter = 0; u8counter < 4; u8counter++)
	{
		DIO_vdSetPortValue(PORTB, (1 << u8counter));
		_delay_ms(50);

	}

	for (u8counter = 0; u8counter < 8; u8counter++)
	{
		DIO_vdSetPortValue(PORTB, (127 >> u8counter));
		_delay_ms(50);

	}
}

void LED_SNACK_EFFECT(void)
{
//	for (u8counter = 7; u8counter >= 0; u8counter--)
//	{
//		DIO_vdSetPinValue(PORTB, u8counter, HIGH);
//		_delay_ms(50);
//
//	}
//	for (u8counter = 7; u8counter >= 0; u8counter--)
//	{
//		DIO_vdSetPinValue(PORTB, u8counter, LOW);
//		_delay_ms(50);
//	}
	for (u8counter = 0; u8counter < 8; u8counter++)
	{
		DIO_vdSetPinValue(PORTB, u8counter, HIGH);
		_delay_ms(500);
	}
	for (u8counter = 0; u8counter < 8; u8counter++)
	{
		DIO_vdSetPinValue(PORTB, u8counter, LOW);
		_delay_ms(500);
	}

}
void LED_CONVERGING(void)
{
	u8 i=0;
	u8 j=7;
	for(i=3,j=4;i<8;i++,j--)
	{
		DIO_vdSetPinValue(PORTB,i,HIGH);
		DIO_vdSetPinValue(PORTB,j,HIGH);
		_delay_ms(500);
		DIO_vdSetPinValue(PORTB,i,LOW);
		DIO_vdSetPinValue(PORTB,j,LOW);
		_delay_ms(500);


	}

}
void LED_DIVERSION(void)
{
	u8 i=0;
	u8 j=7;
	for(i=0,j=7;i<8;i++,j--)
	{
		DIO_vdSetPinValue(PORTB,i,HIGH);
		DIO_vdSetPinValue(PORTB,j,HIGH);
		_delay_ms(500);
		DIO_vdSetPinValue(PORTB,i,LOW);
		DIO_vdSetPinValue(PORTB,j,LOW);
		_delay_ms(500);


	}

}
void vd_7segment_print_numbers(void)
{
	for(u8counter=0;u8counter<10;u8counter++)
	{
		DIO_vdSetPortValue(PORTB,~(u8_7Segment_arr[u8counter]));
		_delay_ms(500);
	}

}
