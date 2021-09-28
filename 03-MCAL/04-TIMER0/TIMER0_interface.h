/*****************************************/
/**   Author : Ahmed Ashraf				*/
/**   DATE   : 16 OCT 2020              */
/**   Version: V01						*/
/****************************************/
#ifndef		TIMER0_INTERFACE_H
#define     TIMER0_INTERFACE_H

void TIMER0_voidInit(void);
void TIMER0_voidSetTimerCountVal(u8 Copy_u8TimeVal);
void TIMER0_voidSetTimeOcVal(u8 Copy_u8TimeVal);
void TIMER0_voidSetOvfAction(void (*ptr) (void));
void TIMER0_voidSetOcAction(void (*ptr) (void));



#endif
