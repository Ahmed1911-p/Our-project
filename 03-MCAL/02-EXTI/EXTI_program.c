/*********************************/
/* Author : Ahmed Ashraf		 */
/* Date   : 6 Oct 2020  		 */
/* Version: V01					 */
/*********************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#include "DIO_interface.h"
#include "avr/interrupt.h"

/***************************************************/
/*Pointer TO FUNCTION TO SAVE ADRESS OF FUNCTION WHICH NEEDED TO EXECTUE WHEN EXTI INTERRUPT OCCUR */

static void (*EXTI_CallBack[3]) (void) = {0,0,0} ;
/*************************************************/
/***************************************************/
/*ENABLE GLOBAL INTERRUPT */
void EXTI_voidInit(void)
{
	/*Enable Global INTERRUPT*/

	SET_BIT(EXTI_SREG_REG,GLOBAL_INTERRUPT_ENABLE);

}
/*****************************************************************/
/********************************************************************************/
/*Set Signal MODE FOR EXTERNAL INTERRUPTS*/
void EXTI_voidSetSignalLatch(u8 Copy_u8EXTILINE , u8 Copy_u8SenseMode)
{
	if(Copy_u8EXTILINE == EXTI_LINE0 || Copy_u8EXTILINE == EXTI_LINE1)
	{
	switch(Copy_u8SenseMode)
	{
		case EXTI_RISING_EDGE    : EXTI_MCUCR_REG &= ~(0b11 << (Copy_u8EXTILINE *2));
								   EXTI_MCUCR_REG |= (0b11 << (Copy_u8EXTILINE *2));
								break;
		case EXTI_FALLING_EDGE   :	EXTI_MCUCR_REG &= ~(0b11 << (Copy_u8EXTILINE *2));
								    EXTI_MCUCR_REG |= (0b10 << (Copy_u8EXTILINE *2));
								break;
		case EXTI_ON_CHANGE      :	EXTI_MCUCR_REG &= ~(0b11 << (Copy_u8EXTILINE *2));
									EXTI_MCUCR_REG |= (0b01 << (Copy_u8EXTILINE *2));
								break;
		case EXTI_LOW_LEVEL      :	EXTI_MCUCR_REG &= ~(0b11 << (Copy_u8EXTILINE *2));  ;
									EXTI_MCUCR_REG |= (0b00 << (Copy_u8EXTILINE *2));
								break;
	}
	}
	else if (Copy_u8EXTILINE == EXTI_LINE2)
	{
		if(Copy_u8SenseMode == EXTI_RISING_EDGE )
		{
			SET_BIT(EXTI_MCUCRSR_REG,EXTI_2_SENSE_MODE);
		}
		
		else if (Copy_u8SenseMode == EXTI_FALLING_EDGE)
		{
			CLR_BIT(EXTI_MCUCRSR_REG,EXTI_2_SENSE_MODE);
		}
		else
		{
		/*ERROR*/	
		}
	}
		
	else
	{
		/*ERROR*/
	}
}
/***************************************************************/
/***************************************************************/
/*ENABLE EXTERNAL INTERRUPTS*/
void EXTI_voidEnableEXTI(u8 Copy_u8EXTI_LINE)
{
	if( Copy_u8EXTI_LINE == EXTI_LINE0)
	{
		SET_BIT(EXTI_GICR_REG ,EXTERNAL_INTERRUPT_0_ENABLE);
	}
	else if( Copy_u8EXTI_LINE == EXTI_LINE1)
	{
		SET_BIT(EXTI_GICR_REG ,EXTERNAL_INTERRUPT_1_ENABLE);
	}
	else if( Copy_u8EXTI_LINE == EXTI_LINE2)
	{
		SET_BIT(EXTI_GICR_REG ,EXTERNAL_INTERRUPT_2_ENABLE);
	}
	else
	{
		/*ERROR*/
	}
}
/**********************************************************/

/************************************************************/
/*Disable EXTERNAL INTERRUPTS*/
void EXTI_voidDisableEXTI(u8 Copy_u8EXTI_LINE)
{
	if( Copy_u8EXTI_LINE == EXTI_LINE0)
	{
		CLR_BIT(EXTI_GICR_REG ,EXTERNAL_INTERRUPT_0_ENABLE);
	}
	else if( Copy_u8EXTI_LINE == EXTI_LINE1)
	{
		CLR_BIT(EXTI_GICR_REG ,EXTERNAL_INTERRUPT_1_ENABLE);
	}
	else if( Copy_u8EXTI_LINE == EXTI_LINE2)
	{
		CLR_BIT(EXTI_GICR_REG ,EXTERNAL_INTERRUPT_2_ENABLE);
	}
	else
	{
		/*ERROR*/
	}
}
/*******************************************************************/

/*****************************************************************/
/*SAVE CALL BACK TO ISR*/
void EXTI_voidSetCallBack(u8 Copy_u8EXTI_LINE ,void (* ptr) (void))
{
	if( Copy_u8EXTI_LINE == EXTI_LINE0)
	{
		EXTI_CallBack[0] = ptr;
	}
	else if( Copy_u8EXTI_LINE == EXTI_LINE1)
	{
		EXTI_CallBack[1] = ptr;
	}
	else if( Copy_u8EXTI_LINE == EXTI_LINE2)
	{
		EXTI_CallBack[2] = ptr;
	}
	else
	{
		/*ERROR*/
	}
}
/*****************************************************************/

/******************************************************************/
/*INTERRUPT SERVICE ROUTINE*/
ISR (INT0_vect)
{
	EXTI_CallBack[0]();
	
}

ISR (INT1_vect)
{
	EXTI_CallBack[1]();

}

ISR (INT2_vect)
{
	EXTI_CallBack[2]();

}
/************************************************************************/


	
