#include "setting.h"

uint16_t count = 0;
void SysTick_Handler(void)
		{
			if (count>0)
			{
				count--;
			}
		}	
void delay(uint16_t a)
		{
			count=a;
			while (count>0){}	
		}


	
void main_nastroika(void)
{
	
	GPIO_InitTypeDef GPIO_struct_PB;
	GPIO_InitTypeDef GPIO_struct_LED;
	GPIO_InitTypeDef GPIO_struct_Button;
	GPIO_InitTypeDef GPIO_str_usart_2;
	USART_InitTypeDef Usart_str;
	
//nastroika Buttons 	
	//1 Button
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_struct_Button. GPIO_Pin =  GPIO_Pin_0;
	GPIO_struct_Button. GPIO_Mode = GPIO_Mode_IN;
	GPIO_struct_Button. GPIO_Speed = GPIO_Medium_Speed;
	GPIO_struct_Button. GPIO_OType = GPIO_OType_PP;
	GPIO_struct_Button. GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA, &GPIO_struct_Button);
	
	//2 Button
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	
	GPIO_struct_Button. GPIO_Pin = GPIO_Pin_1;
	GPIO_struct_Button. GPIO_Mode = GPIO_Mode_IN;
	GPIO_struct_Button. GPIO_Speed = GPIO_Medium_Speed;
	GPIO_struct_Button. GPIO_OType = GPIO_OType_PP;
	GPIO_struct_Button. GPIO_PuPd = GPIO_PuPd_DOWN;
	
	GPIO_Init(GPIOC, &GPIO_struct_Button);
	
//nastroika LED	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_struct_LED. GPIO_Pin =  GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_struct_LED. GPIO_Mode = GPIO_Mode_OUT;
	GPIO_struct_LED. GPIO_Speed = GPIO_Low_Speed;
	GPIO_struct_LED. GPIO_OType = GPIO_OType_PP;
	GPIO_struct_LED. GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_struct_LED);

// nastroika portov LCD
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	GPIO_struct_PB. GPIO_Pin =  GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10;
	GPIO_struct_PB. GPIO_Mode = GPIO_Mode_OUT;
	GPIO_struct_PB. GPIO_Speed = GPIO_High_Speed;
	GPIO_struct_PB. GPIO_OType = GPIO_OType_PP;
	GPIO_struct_PB. GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_struct_PB);
	
// nastroiki GPIO for UART		
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_str_usart_2.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_str_usart_2.GPIO_Mode = GPIO_Mode_AF;
	GPIO_str_usart_2.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_str_usart_2.GPIO_OType = GPIO_OType_PP;
	GPIO_str_usart_2.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOA, &GPIO_str_usart_2);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
	
// nastroiki UART 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

	Usart_str.USART_BaudRate = 9600;
	Usart_str.USART_WordLength = USART_WordLength_8b;
	Usart_str.USART_StopBits = USART_StopBits_1;
	Usart_str.USART_Parity = USART_Parity_No;
	Usart_str.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	Usart_str.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

	USART_Init(USART2, &Usart_str);
	USART_Cmd(USART2, ENABLE);
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	NVIC_EnableIRQ(USART2_IRQn);
	
// nastroika RNG
	RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_RNG, ENABLE);		
	RNG_Cmd(ENABLE);
	
	SysTick_Config(SystemCoreClock/1000);
	
}