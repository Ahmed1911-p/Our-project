/*****************************/
/* Author : Ahmed Ashraf     */
/* Date   : 23 Sept 2020     */
/* Version: V01             */
/****************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*****************************************************/
/*Instruction Set D7 ->  D0*/
#define LCD_CLR 					     0x01
#define LCD_RETURN_CURSOR_HOME		     0x02
#define LCD_CURSOR_RIGHT_DIRECTION		 0x06
#define LCD_CURSOR_LEFT_DIRECTION        0x04
#define LCD_SHIFT_DISPLAY_LEFT			 0x07
#define LCD_SHIFT_DISPLAY_RIGHT          0x05
#define LCD_SHIFT_DISABLE				 0x04
#define LCD_DISPLAY_OPERATION_ON		 0x0C
#define LCD_DISPLAY_OPERATION_OFF		 0x08
#define LCD_CURSOR_DISPLAY_ON			 0x0E
#define LCD_CURSOR_DISPLAY_OFF	 		 0x0C
#define LCD_CURSOR_BLINK				 0x0F
#define LCD_SHIFT_CURSOR_LEFT			 0x10
#define LCD_SHIFT_CURSOR_RIGHT			 0x14
/*#define LCD_SHIFT_DISPLAY_LEFT			 0x18
#define LCD_SHIFT_DISPLAY_RIGHT			 0x1C
*/
#define LCD_8_BITS_TWO_LINE_SMALL     	 0x38
#define LCD_8_BITS_ONE_LINE_SMALL	     0x30
#define LCD_4_BITS_TWO_LINE_SMALL	     0x28
#define LCD_4_BITS_ONE_LINE_SMALL		 0x20

#define LCD_8_BITS_TWO_LINE_BIG     	 0x3C
#define LCD_8_BITS_ONE_LINE_BIG	         0x34
#define LCD_4_BITS_TWO_LINE_BIG	         0x2C
#define LCD_4_BITS_ONE_LINE_BIG  		 0x24
/*****************************************************/
/**********************/
/*LCD_ROWS*/
#define LCD_ROW1    0
#define LCD_ROW2    1
/**********************/
/**********/
/*LCD_COLums*/

#define LCD_COL1	0x00
#define LCD_COL2	0x01
#define LCD_COL3	0x02
#define LCD_COL4	0x03
#define LCD_COL5	0x04
#define LCD_COL6	0x05
#define LCD_COL7	0x06
#define LCD_COL8	0x07
#define LCD_COL9	0x08
#define LCD_COL10	0x09
#define LCD_COL11	0x0A
#define LCD_COL12	0x0B
#define LCD_COL13	0x0C
#define LCD_COL14	0x0D
#define LCD_COL15	0x0E
#define LCD_COL16	0x0F
/************/

//INITIATE Functions of LCD
/*
 * LCD OPERATION ON
 * LCD_8_BITS_TWO_LINE_SMALL
 * LCD_CURSOR_DISPLAY_ON
 * LCD_CURSOR_BLINK
 * LCD_CLR
 */
void LCD_voidInit(void);
/*
 * SEND INSTRUCTIONS FOR LCD CONTROLLER
 * */
void LCD_voidSendIns(u8 Copy_u8Ins);
/*
 * Write ONE CHARACTER TO DISPLAY
 * */
void LCD_voidDisplayChar (u8 Copy_u8Data);
/*
 * WRITE WORD TO LCD DISPLAY
 * */
void LCD_voidDisplayWord (u8 Copy_u8Data[]);
/*
 * MOVING ADRESS COUNTER TO DESIRED POSIOIN (CURSOR)
 * */
void LCD_voidPostionXY(u8 Copy_u8LCD_COL , u8 Copy_u8LCD_ROW);
/*
 * Write Number of 2 DIGIT IN LCD DISPLAY
 * */
void LCD_voidDiplayNumber(u16 Copy_u16Number);
void LCD_voidDiplaySinSoidal(u8 ARR2[]);
/*
 * Write WORK IN SIN WAVE SHAPE
 * A M D
 * 	H E
 * */

/*
 * Return ADRESS COUNTER POSTIOIN
 * */
u8 LCD_u8ReturnAdressCounter(void);

/*
 * Generate A new Char NOT RECORDED IN LCD*/

void LCD_voidWriteExtraChar(u8 Copy_u8LCD_ROW ,u8 Copy_u8LCD_COL);






#endif
