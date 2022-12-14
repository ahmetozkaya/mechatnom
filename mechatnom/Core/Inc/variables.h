/*
 * variables.h
 *
 *  Created on: Dec 3, 2022
 *      Author: Ahmet
 */
#include "stdint.h"
#include "main.h"
#ifndef INC_VARIABLES_H_
#define INC_VARIABLES_H_


#define start 			0x01
#define stop 			0x02
#define ledOn_ayar 		0x03
#define ledOff_ayar		0x04
#define baudrate_ayar	0x05


#define led_On_Off 		HAL_GPIO_WritePin( LD6_GPIO_Port,LD6_Pin,led_durum)
uint8_t led_durum;

uint8_t RX_veri[10];
uint8_t TX_veri[10];

uint8_t komut;
uint8_t	veri_hb; // verinin high biti
uint8_t	veri_lb; // verinin low biti
uint16_t veri;
uint16_t ledOn_sure;
uint16_t ledOff_sure;
uint8_t uart_echo;
uint16_t zaman;
uint8_t IT_uart_3_kontrol; // veri setinin tamaminin alindiginin kontrolu icin
uint8_t uart_baglanti_hatasi; // uarttan alinan veri setinde anahtar uymuyorsa yanlis veri alındi diye uyari olusturabilmek icin


#endif /* INC_VARIABLES_H_ */
