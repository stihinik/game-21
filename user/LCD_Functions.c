#include "setting.h" 

void write_data(uint8_t data)
{
		if (((data>>7)&0x01) == 0x01){DB7(1);} else {DB7(0);}
		if (((data>>6)&0x01) == 0x01){DB6(1);} else {DB6(0);}
		if (((data>>5)&0x01) == 0x01){DB5(1);} else {DB5(0);}
		if (((data>>4)&0x01) == 0x01){DB4(1);} else {DB4(0);}
	
		if (((data>>3)&0x01) == 0x01){DB3(1);} else {DB3(0);}
		if (((data>>2)&0x01) == 0x01){DB2(1);} else {DB2(0);}
		if (((data>>1)&0x01) == 0x01){DB1(1);} else {DB1(0);}
		if (((data>>0)&0x01) == 0x01){DB0(1);} else {DB0(0);}
}

void LCD_SendCommand(uint8_t Command)
{
		uint16_t i;
	
		RS(0);
		write_data(Command);
		EN(1);
		for (i=0;i<1000;i++){}
		EN(0);
}

void LCD_SendData(uint8_t Command)
{
		uint16_t i;
	
		RS(1);
		write_data(Command);
		EN(1);
		for (i=0;i<1000;i++){}
		EN(0);
}
void LCD_SendString(char *std1)
{
		uint8_t i=0;
	
		while(std1[i] != 0)
		{
			LCD_SendData(std1[i]);
			delay(3);
			i++;
		}
}
void LCD_Setting()
{
	delay(1000);
	RW(0);
  LCD_SendCommand(0x30);
  delay(5);
	LCD_SendCommand(0x30);
  delay(1);
	LCD_SendCommand(0x30);
  delay(1);
	LCD_SendCommand(0x38);
  delay(1);
	LCD_SendCommand(0x0F);
  delay(1);
	LCD_SendCommand(0x01);
  delay(1);
	LCD_SendCommand(0x06);
  delay(1);
	LCD_SendCommand(0x02);
  delay(1);

}

void Vivod_LCD(char what[100])
{
	LCD_SendCommand(0x01);
	delay(10);
	LCD_SendString(what);
}