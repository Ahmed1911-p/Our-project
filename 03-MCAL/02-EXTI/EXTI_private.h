/*********************************/
/* Author : Ahmed Ashraf		 */
/* Date   : 6 Oct 2020  		 */
/* Version: V01					 */
/*********************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/*********************************************************/
/*DEFINE REGISTERS FOR EXTERNAL INTERRUPTS*/
#define EXTI_MCUCR_REG		*((volatile u8 *) 0x55)
#define EXTI_MCUCRSR_REG	*((volatile u8 *) 0x54)
#define EXTI_GICR_REG		*((volatile u8 *) 0x5B)
#define EXTI_GIFR_REG		*((volatile u8 *) 0x5A)
#define EXTI_SREG_REG		*((volatile u8 *) 0x5F)
/*********************************************************/


#endif
