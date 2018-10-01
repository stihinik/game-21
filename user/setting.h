#ifndef SETTING_H
#define SETTING_H 

	#include "stm32f4xx.h"
	#include "stm32f4xx_gpio.h"
	#include "stdio.h"

// GPIO LCD
	#define EN(a)	GPIO_WriteBit(GPIOB, GPIO_Pin_2, (BitAction)a)
	#define RW(a)	GPIO_WriteBit(GPIOB, GPIO_Pin_0, (BitAction)a)
	#define RS(a)	GPIO_WriteBit(GPIOB, GPIO_Pin_1, (BitAction)a)	

	#define DB7(a)	GPIO_WriteBit(GPIOB, GPIO_Pin_10, (BitAction)a)
	#define DB6(a)	GPIO_WriteBit(GPIOB, GPIO_Pin_3, (BitAction)a)
	#define DB5(a)	GPIO_WriteBit(GPIOB, GPIO_Pin_5, (BitAction)a)
	#define DB4(a)	GPIO_WriteBit(GPIOB, GPIO_Pin_4, (BitAction)a)
	#define DB3(a)	GPIO_WriteBit(GPIOB, GPIO_Pin_7, (BitAction)a)
	#define DB2(a)	GPIO_WriteBit(GPIOB, GPIO_Pin_6, (BitAction)a)
	#define DB1(a)	GPIO_WriteBit(GPIOB, GPIO_Pin_9, (BitAction)a)
	#define DB0(a)	GPIO_WriteBit(GPIOB, GPIO_Pin_8, (BitAction)a)
//Button	
	#define FIRST_BUTTON GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)
  #define SECOND_BUTTON GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1)
//GND Otrezok
	#define MAX_NOMBER  0x100000000
	#define OTREZOK     0x100000000/10
//setting_main_and_delay
	void delay(uint16_t a);
	void main_nastroika(void);
//LCD_Functions	
	void write_data(uint8_t data);
	void LCD_SendCommand(uint8_t Command);
	void LCD_SendData(uint8_t Command);
	void LCD_SendString(char *std1);
	void LCD_Setting();
	void Vivod_LCD(char what[100]);
//game_and_button
	uint8_t Good_Button(uint8_t nomber_button);
	uint8_t Nomber_RNG();
	void Itog_Game(char all_nomber[100], char itog[13]);
#endif

