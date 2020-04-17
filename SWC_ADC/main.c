/*
 * main.c
 *
 *  Created on: Mar 27, 2020
 *      Author: IOT scientist
 */
#include"avr/delay.h"
#include"../STD_TYPES.h"
#include"../BIT_math.h"
#include"DIO_int.h"
#include"LCD_int.h"
//#include"../SWC_LCD_ES/LCD_cfg.h"
#include"ADC_int.h"
int main()
{
	u32 ADC_result ;
	u16 u16Volt_Val;
	DIO_vdSetPortDirection(PORTA,INPUT);
	DIO_vdSetPortDirection(PORTB,OUTPUT);
	DIO_vdSetPortDirection(PORTD,OUTPUT);
	LCD_vdInit();
	ADC_vdIntialize();
	while(1)
	{
		LCD_vdClearDisplay();
		ADC_result = ADC_u16GetADC_Value(CHANNEL1);
		u16Volt_Val = (ADC_result * 5);
		LCD_vdWriteNumber(u16Volt_Val);


		_delay_ms(1000);
	}


	return 0;
}
