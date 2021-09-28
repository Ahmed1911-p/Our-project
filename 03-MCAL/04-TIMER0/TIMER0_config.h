/*****************************************/
/**   Author : Ahmed Ashraf				*/
/**   DATE   : 16 OCT 2020              */
/**   Version: V01						*/
/****************************************/
#ifndef		TIMER0_CONFIG_H
#define     TIMER0_CONFIG_H

/*************************************************************************************************/
/*						<---------------- MODE OF TIMER -------->
/*
OPTIONS:
NORMAL_TIME_MODE
CTC_MODE
FAST_PWM_MODE
PHASE_CORRECT_PWM
*/
#define TIMER0_MODE_OF_OPERATION								NORMAL_TIME_MODE

/**************************************************************************************************/

/*							<--------   	OCR PIN  (PORT B PIN 3 )	---------->								*/

/*
Options :
NORMAL_PORT_OPERATION
TOGGLE_OC0_COMPARE_MATCH
SET_OC0_COMPARE_MATCH
CLR_OC0_COMPARE_MATCH
*/
#define TIMER0_COMPARE_MATCH_OUTPUT_MODE_NOMAL_CTC_MODE			NORMAL_PORT_OPERATION



/*
Options :
NORMAL_PORT_OPERATION
SET_OC0_COMPARE_MATCH_CLR_OVF
CLR_OC0_COMPARE_MATCH_SET_OVF
*/



#define TIMER0_COMPARE_MATCH_OUTPUT_MODE_FAST_PMW				NORMAL_PORT_OPERATION

/*
Options :
NORMAL_PORT_OPERATION
SET_OC0_COMPARE_MATCH_CLR_OVF
CLR_OC0_COMPARE_MATCH_SET_OVF
*/



#define TIMER0_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT			 NORMAL_PORT_OPERATION

/**********************************************************************************************************/

/*		<------------ TIMER0 PRESCALER ------------------>												*/
/*
TIMER FREQUENCY = 8MHZ /PRESCALER 
Options : 
TIMER0_COUNTER_STOPPED
TIMER0_NO_PRESCALLER
TIMER0_8_PRESCALER
TIMER0_64_PRESCALER
TIMER0_256_PRESCALER
TIMER0_1024_PRESCALER
TIMER0_EXTERNAL_CLOCK_ON_T0_PIN_FALLING_EDGE
TIMER0_EXTERNAL_CLOCK_ON_T0_PIN_RISING_EDGE
*/
#define TIMER0_CLOCK_SELECT										TIMER0_8_PRESCALER		
/************************************************************************************************************/		
/*			<--------  TIMER0   INTERRUPT	--------------------------->									*/
/*
Options : 
TIMER0_INTERRUPT_ENABLE
TIMER0_INTERRUPT_DISABLE
*/
#define TIMER0_INTERRUPT_STATE									TIMER0_INTERRUPT_ENABLE	
/*
Options : 
TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT_ENABLE
TIMER0_OVERFLOW_INTERRUPT_ENABLE
TIMER0_OVF_AND_COMP_ENTERRUPT
*/
#define TIMER0_INTERRUPT										TIMER0_OVERFLOW_INTERRUPT_ENABLE
#endif
