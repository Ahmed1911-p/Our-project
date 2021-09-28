/***********************************/
/*  Author : Ahmed Ashraf		   */
/* 	DATE   : 13 OCT 2020    	   */
/*  Version: V01				   */
/***********************************/

#include "STD_TYPES.h"
#include "BIT_MATCH.h"

#include "DAC_interface.h"		
#include "DAC_private.h"
#include "DAC_config.h"

#include "DIO_interface.h"



void DAC_voidSetAnalogVolt(u16 Copy_u16Analog)
{
		u8 Loc_u8Digital ;
		u8 Loc_u8StepSize = DAC_u8ReturnStep() ;
		Loc_u8Digital = Copy_u16Analog / Loc_u8StepSize ;
		DIO_SetPortValue(DAC_PORT,Loc_u8Digital);
}

static u8 DAC_u8ReturnStep(void)
{
	u8 Loc_u8Counter = DAC_RESOLUTION;
	u8 Loc_u8Step = 1 ;
	while (Loc_u8Counter != 0)
	{
		Loc_u8Step = Loc_u8Step * 2;
		Loc_u8Counter--; 
	}
	return Loc_u8Step;
}