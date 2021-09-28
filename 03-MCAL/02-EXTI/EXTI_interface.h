/*********************************/
/* Author : Ahmed Ashraf		 */
/* Date   : 6 Oct 2020  		 */
/* Version: V01					 */
/*********************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/*************************************************/
/*EXTI LINES */
#define EXTI_LINE0     0
#define EXTI_LINE1     1
#define EXTI_LINE2     2
/***********************************************/
/*Sense Mode */
#define		  EXTI_RISING_EDGE			0
#define       EXTI_FALLING_EDGE			1
#define       EXTI_ON_CHANGE  			2
#define       EXTI_LOW_LEVEL			3
/***********************************************************/
/***********************************************************/
/*BITS*/
#define GLOBAL_INTERRUPT_ENABLE			7

#define EXTERNAL_INTERRUPT_0_ENABLE		6
#define EXTERNAL_INTERRUPT_1_ENABLE		7
#define EXTERNAL_INTERRUPT_2_ENABLE		5

#define EXTI_2_SENSE_MODE				6


/*************************************************************/
/*Functions*/
/*ENABLE */
void EXTI_voidInit(void);
/*Set Signal Mode */
void EXTI_voidSetSignalLatch(u8 Copy_u8EXTILINE , u8 Copy_u8SenseMode);
/*Enable EXTERNAL INTERRUPTS*/
void EXTI_voidEnableEXTI(u8 Copy_u8EXTILINE);
/*Disable EXTERNAL INTERRUPTS*/
void EXTI_voidDisableEXTI(u8 Copy_u8EXTILINE);
/*Save CALL BACK FUNCTIONS*/
void EXTI_voidSetCallBack(u8 Copy_u8EXTI_LINE,void (* ptr) (void));
/***************************************************************/

#endif
