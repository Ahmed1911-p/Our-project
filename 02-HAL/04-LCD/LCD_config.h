/*****************************/
/* Author : Ahmed Ashraf     */
/* Date   : 23 Sept 2020     */
/* Version: V01             */
/****************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

//Define Registers
#define INS_REGISTER                    DIO_PORTC
#define DATA_REGISTER					DIO_PORTC

// write PORT pair pin ex: DIO_PORT , PIN
#define LCD_ENABLE						DIO_PORTA,DIO_PIN1
#define LCD_RS							DIO_PORTA,DIO_PIN0
/* 0 -> WRITE    1 -> READ*/
#define LCD_READ_WRITE					DIO_PORTA,DIO_PIN2



/*
 * LCD_DISPLAY_OPERATION_ON
 * OR
 *  LCD_DISPLAY_OPERATION_FF*/
#define LCD_OPERATION			LCD_DISPLAY_OPERATION_ON
/*OPTIONS
 * LCD_8_BITS_TWO_LINE_SMALL
 * LCD_8_BITS_ONE_LINE_SMALL
 * LCD_4_BITS_TWO_LINE_SMALL
 * LCD_4_BITS_ONE_LINE_SMALL
 * LCD_8_BITS_TWO_LINE_BIG
 * LCD_8_BITS_ONE_LINE_BIG
 * LCD_4_BITS_TWO_LINE_BIG
 * LCD_4_BITS_ONE_LINE_BIG

 * */
#define LCD_FUNC_SET		LCD_8_BITS_TWO_LINE_SMALL
/*LCD_CURSOR_DISPLAY_ON
 * LCD_CURSOR_DISPLAY_OFF
 * */
#define CURSOR_DISPLAY		LCD_CURSOR_DISPLAY_ON

/*
 * OPTIONS
 * LCD_CURSOR_RIGHT_DIRECTION
 * LCD_CURSOR_LEFT_DIRECTION
 * */
#define CURSOR_DIRECTION   LCD_CURSOR_RIGHT_DIRECTION



/******************Extra Char *************************/
/* Write 8 Char Each char 1 byte					*/
ExtreChar[64] = {0x02, 0x00, 0x17, 0x15, 0x1F, 0x00, 0x00, 0x00







				};




#endif
