/*****************************/
/* Author : Ahmed Ashraf     */
/* Date   : 23 Sept 2020     */
/* Version: V01             */
/****************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define F_cpu 8000000ul
#include "avr/delay.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"


void LCD_voidInit(void)
{
	_delay_ms(30);
	LCD_voidSendIns(LCD_OPERATION);
	_delay_ms(1);
	LCD_voidSendIns(LCD_FUNC_SET);
	_delay_ms(1);
	LCD_voidSendIns(CURSOR_DISPLAY);
	_delay_ms(1);
	LCD_voidSendIns(CURSOR_DIRECTION);
	_delay_ms(1);
	LCD_voidSendIns(LCD_CURSOR_BLINK);
	_delay_ms(1);
	LCD_voidSendIns(LCD_CLR);
	_delay_ms(1);


}
void LCD_voidSendIns(u8 Copy_u8Ins)
{
	DIO_voidSetPinValue(LCD_RS,DIO_LOW);
	DIO_voidSetPinValue(LCD_READ_WRITE,DIO_LOW);
	DIO_voidSetPinValue(LCD_ENABLE , DIO_HIGH);
	DIO_voidSetPortValue(INS_REGISTER,Copy_u8Ins);
	DIO_voidSetPinValue(LCD_ENABLE , DIO_LOW);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_ENABLE , DIO_HIGH);
}
void LCD_voidDisplayChar (u8 Copy_u8Data)
{

	DIO_voidSetPinValue(LCD_RS,DIO_HIGH);
	DIO_voidSetPinValue(LCD_READ_WRITE,DIO_LOW);
	DIO_voidSetPinValue(LCD_ENABLE , DIO_HIGH);
	DIO_voidSetPortValue(DATA_REGISTER,Copy_u8Data);
	DIO_voidSetPinValue(LCD_ENABLE , DIO_LOW);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_ENABLE , DIO_HIGH);
}
void LCD_voidDisplayWord (u8 ARR[])
{
	u8 loopCrt =0 ;
	while( ARR[loopCrt] != '\0')
	{
		if (loopCrt == 16)
		{
			LCD_voidPostionXY(LCD_ROW2,LCD_COL1);
		}
		LCD_voidDisplayChar(ARR[loopCrt]);
		loopCrt++;

	}

}
void LCD_voidPostionXY( u8 Copy_u8LCD_ROW ,u8 Copy_u8LCD_COL)
{
	u8 Loc_u8Adress = 0x80 ;
	if (Copy_u8LCD_ROW == LCD_ROW2)
	{	Loc_u8Adress |= 0x40 ; }

	Loc_u8Adress |= Copy_u8LCD_COL;
	LCD_voidSendIns(Loc_u8Adress);
}
void LCD_voidDiplayNumber(u16 Copy_u16Number)
{
	if(Copy_u16Number != 0)
	{
	u8 Loc_u8counter = 1;
	u8 Loc_u8DiplayArr[6];
	while(Copy_u16Number != 0)
	{
		Loc_u8DiplayArr[Loc_u8counter] =( Copy_u16Number % 10) ;
		Loc_u8counter ++ ;
		Copy_u16Number =  Copy_u16Number /10 ;
	}
	Loc_u8counter--;
	while(Loc_u8counter !=0)
	{
		u8 display = Loc_u8DiplayArr[Loc_u8counter] + 48;
		LCD_voidDisplayChar(display);
		Loc_u8counter -- ;
	}
	}
	else
	{
		LCD_voidDisplayChar('0');
	}
}
void LCD_voidDiplaySinSoidal(u8 ARR2[])
{

	u8 loopCrt =0 ;
	u8 LCD_COL [16] = {LCD_COL1,LCD_COL2,LCD_COL3,LCD_COL4,LCD_COL5,LCD_COL6,LCD_COL7,LCD_COL8,LCD_COL9,LCD_COL10,LCD_COL11,LCD_COL12,LCD_COL13,LCD_COL14,LCD_COL15,LCD_COL16};
	u8 LocLCD_ROWShift = 0;
	u8 LocLCD_COLShift = 0;

		while( ARR2[loopCrt] != '\0')
		{

			 LCD_voidPostionXY(LocLCD_ROWShift ,LCD_COL[LocLCD_COLShift]);
			 LCD_voidDisplayChar(ARR2[loopCrt]);
			 loopCrt++;
			 LocLCD_COLShift++;
			 if(LocLCD_ROWShift ==0)
			 { LocLCD_ROWShift=1;}
			 else
			 { LocLCD_ROWShift =0;}


		}

}
u8 LCD_u8ReturnAdressCounter(void)
{
	u8 Loc_u8Res;
	u8 i0;
	u8 i1;
	u8 i2;
	u8 i3;
	u8 i4;
	u8 i5;
	u8 i6;
	u8 i7;
	DIO_voidSetPinValue(LCD_RS,DIO_LOW);
	DIO_voidSetPinValue(LCD_READ_WRITE,DIO_HIGH);
	DIO_voidSetPortDirection(DATA_REGISTER , DIO_PORT_INPUT);
	i0 =DIO_u8GetPinValue(DATA_REGISTER,DIO_PIN0);
	i1 =DIO_u8GetPinValue(DATA_REGISTER,DIO_PIN1);
	i2 =DIO_u8GetPinValue(DATA_REGISTER,DIO_PIN2);
	i3 =DIO_u8GetPinValue(DATA_REGISTER,DIO_PIN3);
	i4 =DIO_u8GetPinValue(DATA_REGISTER,DIO_PIN4);
	i5 =DIO_u8GetPinValue(DATA_REGISTER,DIO_PIN5);
	i6 =DIO_u8GetPinValue(DATA_REGISTER,DIO_PIN6);
	i7 =DIO_u8GetPinValue(DATA_REGISTER,DIO_PIN7);
	Loc_u8Res = i0*1 + i1*2 +i2*4 + i3*8 + i4*16 + i5*32 + i6*128 +i7 *256;
	DIO_voidSetPortDirection(DATA_REGISTER , DIO_PORT_OUTPUT);
	return Loc_u8Res;
}
void LCD_voidWriteExtraChar(u8 Copy_u8LCD_ROW ,u8 Copy_u8LCD_COL)
{
	LCD_voidSendIns(0x40);
	u8 Loc_counter ;
	for (Loc_counter=0 ; Loc_counter <= 63  ; Loc_counter++)
	{
		LCD_voidDisplayChar(ExtreChar[Loc_counter]);
	}
	LCD_voidSendIns(0x80);
	LCD_voidPostionXY(Copy_u8LCD_ROW,Copy_u8LCD_COL);
	for(Loc_counter=0 ; Loc_counter <= 7  ; Loc_counter++)
			{
			LCD_voidDisplayChar(Loc_counter);
			_delay_ms(5);
			}

}
