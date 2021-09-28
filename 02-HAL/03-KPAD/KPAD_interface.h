/**************************************/
/******* Author : Ahmed Ashra         */
/******* Date   : 26 Sept 2020        */
/******* Version: V01                 */
/**************************************/

#ifndef KPAD_INTERFACE_H
#define KPAD_INTERFACE_H

/********************* Macron ***************/
#define KPAD_SW1                   0
#define KPAD_SW2                   1
#define KPAD_SW3                   2
#define KPAD_SW4                   3
#define KPAD_SW5                   4
#define KPAD_SW6                   5
#define KPAD_SW7                   6
#define KPAD_SW8                   7
#define KPAD_SW9                   8
#define KPAD_SW10                  9
#define KPAD_SW11                  10
#define KPAD_SW12                  11
#define KPAD_SW13                  12
#define KPAD_SW14                  13
#define KPAD_SW15                  14
#define KPAD_SW16                  15
#define KPAD_NO_KPRESSED		   0xff

/****************************** FUNCTION ******/

void KPAD_voidInit(void);
u8   KPAD_GetKeyPressed(void);



#endif