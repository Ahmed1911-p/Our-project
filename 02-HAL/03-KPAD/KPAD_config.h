/**************************************/
/******* Author : Ahmed Ashra         */
/******* Date   : 26 Sept 2020        */
/******* Version: V01                 */
/**************************************/

#ifndef KPAD_CONFIG_H
#define KPAD_CONFIG_H
/*No OF Coloums*/
#define NO_OFF_COLOUMS  4
/*No OF Rows*/
#define NO_OFF_ROW  4
/*PORT OF KEYPAD*/
#define  KEY_PAD_PORT   DIO_PORTD

/*Write PIN COLOUMS IN  PINX */
#define KPAD_COL1    DIO_PIN0
#define KPAD_COL2    DIO_PIN1
#define KPAD_COL3    DIO_PIN2
#define KPAD_COL4    DIO_PIN3

/*Write in pairs DIO_PORTX , PINX */
#define KPAD_ROW1     DIO_PIN4
#define KPAD_ROW2     DIO_PIN5
#define KPAD_ROW3     DIO_PIN6
#define KPAD_ROW4     DIO_PIN7



#endif