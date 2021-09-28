void ID_PASSWORD_DASHBOARD(void)
{
/*YOUR ID*/
	
		LCD_voidDisplayWord(" ID : ");
		//LOOP FOR TAKING 4 DIGITS OF ID
		while(1) 
		{

			KYPRESSED =KPAD_GetKeyPressed();
			if(KYPRESSED != KPAD_NO_KPRESSED)
			{

				LCD_voidDiplayNumber(KYPRESSED);
				/*STOR ID IN ARRAY OF 4 ELEMENT*/
				ID_ARR[counter]=KYPRESSED;
				
				counter ++;
			}

			/*CHECK FOR NUMBERING OF ID ONLY 4 ELEMENT*/
			if(counter==4)
			{
				break;

			}
		}
		/*READY FOR TAKING PASSWORD*/
		LCD_voidPostionXY(LCD_ROW2,LCD_COL1);
		LCD_voidDisplayWord("PASS : ");
		counter--;

}


