/*****************************************/
/**   Author : Ahmed Ashraf				*/
/**   DATE   : 16 OCT 2020              */
/**   Version: V01						*/
/****************************************/
#ifndef		TIMER0_PRIVATE_H
#define     TIMER0_PRIVATE_H
/*MODE OF OPERATIONS*/
#define NORMAL_TIME_MODE									0b00000000
#define CTC_MODE											0b00001000
#define FAST_PWM_MODE										0b01001000
#define PHASE_CORRECT_PWM									0b01000000
/************************************************************************************/
/*			<------------------   OCR PIN       ----------------->			*/
//FOR NORMAL AND CTC MODE
#define	NORMAL_PORT_OPERATION								0b00000000
#define TOGGLE_OC0_COMPARE_MATCH							0b00010000
#define	SET_OC0_COMPARE_MATCH								0b00110000
#define CLR_OC0_COMPARE_MATCH								0b00100000
//FOR FAST PWM
#define	NORMAL_PORT_OPERATION								0b00000000
#define	SET_OC0_COMPARE_MATCH_CLR_OVF						0b00110000
#define CLR_OC0_COMPARE_MATCH_SET_OVF						0b00100000

//FOR PHASE CORRECT
#define	NORMAL_PORT_OPERATION								0b00000000
#define	SET_OC0_COMPARE_MATCH_CLR_OVF						0b00110000
#define CLR_OC0_COMPARE_MATCH_SET_OVF						0b00100000

/**************************************************************************************************/
							
/*CLOCK SELECT FOR TIMER*/
#define     TIMER0_COUNTER_STOPPED							0b00000000
#define     TIMER0_NO_PRESCALLER							0b00000001
#define     TIMER0_8_PRESCALER								0b00000010
#define     TIMER0_64_PRESCALER								0b00000011
#define     TIMER0_256_PRESCALER							0b00000100
#define     TIMER0_1024_PRESCALER							0b00000101
#define		TIMER0_EXTERNAL_CLOCK_ON_T0_PIN_FALLING_EDGE	0b00000110   
#define		TIMER0_EXTERNAL_CLOCK_ON_T0_PIN_RISING_EDGE		0b00000111
/*INTERRUPT*/
#define  TIMER0_INTERRUPT_ENABLE									1
#define  TIMER0_INTERRUPT_DISABLE								0
#define  TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT_ENABLE		0b00000010
#define  TIMER0_OVERFLOW_INTERRUPT_ENABLE					0b00000001
#define	 TIMER0_OVF_AND_COMP_ENTERRUPT						0b00000011
/*BITS*/
#define GLOBAL_INTERRUPT_ENABLE								7
/*REGISTERS*/
#define TIMER0_TCCR0_REG  									*((volatile u8*) 0x53)
#define TIMER0_TCNT0_REG  									*((volatile u8*) 0x52)
#define TIMER0_OCR0_REG  									*((volatile u8*) 0x5C)
#define TIMER0_TIMSK_REG  									*((volatile u8*) 0x59)
#define SREG_REG											*((volatile u8 *) 0x5F)


static void (*TIMER0_CallBack[2]) (void) = {0,0};
#endif
