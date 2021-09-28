/**************************************/
/******* Author : Ahmed Ashra         */
/******* Date   : 26 Sept 2020        */
/******* Version: V01                 */
/**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "KPAD_interface.h"
#include "KPAD_private.h"
#include "KPAD_config.h"

#include "DIO_interface.h"
#include  <avr/delay.h>
u8 KPAD_Arrayu8Col[4] = {KPAD_COL1 ,KPAD_COL2 ,KPAD_COL3,KPAD_COL4};
u8 KPAD_Arrayu8Row[4] = {KPAD_ROW1 ,KPAD_ROW2 ,KPAD_ROW3,KPAD_ROW4};

void KPAD_voidInit(void)
{
	/*Set High To COLOUMS*/
	DIO_voidSetPinValue(KEY_PAD_PORT,KPAD_COL1,DIO_HIGH);
	DIO_voidSetPinValue(KEY_PAD_PORT,KPAD_COL2,DIO_HIGH);
	DIO_voidSetPinValue(KEY_PAD_PORT,KPAD_COL3,DIO_HIGH);
	DIO_voidSetPinValue(KEY_PAD_PORT,KPAD_COL4,DIO_HIGH);
	/*Set ROW TO PULL UP RESISTOR*/
	DIO_voidEnablePinPullUpResistor(KEY_PAD_PORT , KPAD_ROW1);
	DIO_voidEnablePinPullUpResistor(KEY_PAD_PORT ,KPAD_ROW2);
	DIO_voidEnablePinPullUpResistor(KEY_PAD_PORT ,KPAD_ROW3);
	DIO_voidEnablePinPullUpResistor(KEY_PAD_PORT ,KPAD_ROW4);

}



u8   KPAD_GetKeyPressed(void)
{

	u8 Loc_u8Cloop;
	u8 Loc_u8Rloop;
	for (Loc_u8Cloop=0 ; Loc_u8Cloop < 4 ; Loc_u8Cloop ++ )
	{
		DIO_voidSetPinValue(KEY_PAD_PORT , KPAD_Arrayu8Col[Loc_u8Cloop] , DIO_LOW);
		for (Loc_u8Rloop =0 ; Loc_u8Rloop < 4 ; Loc_u8Rloop ++)
		{
			if(DIO_u8GetPinValue(KEY_PAD_PORT , KPAD_Arrayu8Row[Loc_u8Rloop]) == 0)
			{
				while(DIO_u8GetPinValue(KEY_PAD_PORT , KPAD_Arrayu8Row[Loc_u8Rloop]) == 0);
				_delay_ms(10);
				DIO_voidSetPinValue(KEY_PAD_PORT , KPAD_Arrayu8Col[Loc_u8Cloop] , DIO_HIGH);
				return ((Loc_u8Rloop * 4 ) + Loc_u8Cloop);
			}
		}
		DIO_voidSetPinValue(KEY_PAD_PORT , KPAD_Arrayu8Col[Loc_u8Cloop] , DIO_HIGH);
	}
	return KPAD_NO_KPRESSED;
}


