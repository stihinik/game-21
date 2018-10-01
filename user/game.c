#include "setting.h" 

//words for the winner and the loser	
	char bad[13]={0x42,0xAE,0x10,0xA8,0x50,0x4F,0xB8,0xA1,0x50,0x41,0xA7,0xB8};
  char good[13]={0x10,0x42,0xAE,0x10,0x42,0xAE,0xB8,0xA1,0x50,0x41,0xA7,0xB8};
	
int main(void)
{
	//words for the winner and the loser	
	char bad[13]={0x42,0xAE,0x10,0xA8,0x50,0x4F,0xB8,0xA1,0x50,0x41,0xA7,0xB8};
  char good[13]={0x10,0x42,0xAE,0x10,0x42,0xAE,0xB8,0xA1,0x50,0x41,0xA7,0xB8};
	
	uint8_t first_gnd = 0, second_gnd = 0;
	uint32_t sum = 0;
	char nomber_player[100];
	char nomber_enemy[100];
	uint8_t cat=0;

	main_nastroika();

	delay(1000);
	LCD_Setting(); 
	delay(10);

	while(1)
	{
	//nachalo work 
		if (sum > 0x15)
		{
			Itog_Game(nomber_player, bad);
			sum = 0;
		}
	// work first button 
		if  (Good_Button(FIRST_BUTTON) == 1)
		{
	// nomber RND		
			first_gnd = Nomber_RNG();
			second_gnd = Nomber_RNG();
	// save point		
			cat=cat+second_gnd;
			sum=sum+first_gnd;
	//withdrawal of your points		
			sprintf(nomber_player,"%d ", first_gnd);
			LCD_SendString(nomber_player);
		}
						
	// work second button			
		if (Good_Button(SECOND_BUTTON) == 1)
			 {
				sprintf(nomber_enemy,"%d", cat);
				 
				//withdrawal of enemy points 
				Vivod_LCD(nomber_enemy); 
				delay(1000);
				 
				//withdrawal of player points
				Vivod_LCD(nomber_player);
				delay(1000);
				//decision who won			 
				if (sum > cat)
				{
					Itog_Game(nomber_player,good);
				}
				else
				{
					Itog_Game(nomber_player, bad);
					sum=0;						
				}	
			}
		}
}
