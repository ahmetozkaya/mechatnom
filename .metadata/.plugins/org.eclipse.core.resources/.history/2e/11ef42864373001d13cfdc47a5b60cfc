/*
 * functions.c
 *
 *  Created on: Dec 3, 2022
 *      Author: Ahmet
 */

#include "variables.h"


void led_kontrol (void)
{
	if (uart_echo==stop)
	{
		if (led_durum==0 && zaman>=1000)
		{
			led_durum=1;
			zaman=0;
		}
		else if(led_durum==1 && zaman>=1000)
		{
			led_durum=0;
			zaman=0;
		}
		led_On_Off;
	}
	else if (uart_echo==start)
	{
		if (led_durum==0 && zaman>=ledOff_sure)
		{
			led_durum=1;
			zaman=0;
		}
		else if(led_durum==1 && zaman>=ledOn_sure)
		{
			led_durum=0;
			zaman=0;
		}
		led_On_Off;

	}

}





