#include "setting.h" 

uint16_t counter=0;
uint8_t flag = 0;

//produces a fight with the chatter for the button
uint8_t Good_Button(uint8_t nomber_button)
{
	  if (nomber_button==1)
		 {
			if (counter<1000)	
				{
				   counter++;
				}
		  else if(flag==0) 
				 {
					 return flag=1;
				 }
			 }
	  else if (counter!=0)
				{
				counter--;
					if (counter==1)
					{
						flag=0;
					}	
				}
}
//give a random number from 0 to 9
uint8_t Nomber_RNG()
{
	uint32_t Rand=RNG_GetRandomNumber();
	uint8_t d = 0x0B;
	uint8_t i;
	for (i = 9; i > 0; i--)
	{
		if((Rand<((OTREZOK)*(i)))&(Rand>((OTREZOK)*(i-1))))
		{
			d--;
			break;
		}
		d--;
	}
	return d;
}
//displays the results of the game on the screen
void Itog_Game(char all_nomber[100], char itog[13])
{
	uint8_t counter=0;

		delay(1000);
		LCD_SendCommand(0x01);
		delay(10);
		LCD_SendString(itog);
		delay(1000);
		LCD_SendCommand(0x01);
		while(all_nomber[counter]!=0)
		{
			all_nomber[counter]=0;
			counter++;
		}
}