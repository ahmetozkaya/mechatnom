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

/*
 * @brief Uart iletişimi için buffer yapısı
 * @param
 *		__[16bit]__[__8bit__]__[__8bit__]___[8bit]____[8bit]_
 *		_Anahtar___Komut_______veri_hb______veri_lb___check__
 *		anahtar 0x3641 olarak belirlendi
 *		komut 0x01 ise uart veri gonderimini baslatir
 *		komut 0x02 ise uart veri gonderimini durdurur
 *		komut 0x03 ise LedOn suresinin degerini ayarlar
 *		komut 0x04 ise LedOff suresinin degerini ayarlar
 *		sure degerleri veri_hb ve veri_lb nin 16 bit veriye donusturulmesi ile elde e#dilir.
 */

void uart_veri_oku(void)
{
	IT_uart_3_kontrol++;

	if(IT_uart_3_kontrol == sizeof(RX_veri))
	{
		IT_uart_3_kontrol = 0;
		for (uint8_t i=0; i<sizeof(RX_veri); i++)
		{
			if((RX_veri[i] == 0x36) && (RX_veri[i + 1] == 0x41))
			{
				komut = RX_veri[i+2];
				veri_hb = RX_veri[i+3];
				veri_lb = RX_veri[i+4];

				veri= ((RX_veri[i+3] & 0x00FF) << 8) | (RX_veri[i+4] & 0x00FF);

				uart_baglanti_hatasi = 0;// uarttan alinan veri setinde anahtar uymuyorsa yanlis veri alındi diye uyari olusturulabilir

				i = sizeof(RX_veri);
			}
			else
				uart_baglanti_hatasi = 1;
		}
	}
}





