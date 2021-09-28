/***********************************/
/*  Author : Ahmed Ashraf		   */
/* 	DATE   : 13 OCT 2020    	   */
/*  Version: V01				   */
/***********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"		
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_voidInint(void)
{
	/*Choose REF VOLTAGE WHAT YOU NEED*/
	ADC_ADMUX_REG &= ~(0b11000000);
	ADC_ADMUX_REG |= ADC_REF_VOLTAGE;
	/*Select LEFT OR RIGHT ADUST*/
	#if		 ADC_ADJUST_CONTROL == ADC_LEFT_ADJUST
		SET_BIT(ADC_ADMUX_REG,ADC_ADJSTMENT_BIT);
	#else if  ADC_ADJUST_CONTROL == ADC_RIGHT_ADJUST
		CLR_BIT(ADC_ADMUX_REG,ADC_ADJSTMENT_BIT);
	#endif

	/*Auto Trigger*/
	#if 	   ADC_AUTO_TRIGGER == ADC_AUTO_TRIGGER_ON
		SET_BIT(ADC_ADSRA_REG,ADC_AUTO_TRIGGER_BIT);
	#else if	DC_AUTO_TRIGGER == ADC_AUTO_TRIGGER_OFF
		CLR_BIT(ADC_ADSRA_REG,ADC_AUTO_TRIGGER_BIT);
	#endif

	/*ADC PRESCALER*/
	ADC_ADSRA_REG &= ~(0b00000111);
	ADC_ADSRA_REG |= (ADC_PRESCALER_DIVISION);
	
	/*INTERRUPT*/
	#if 	ADC_INTERRUPT == ADC_INTERRUPT_DISABLE
		CLR_BIT(ADC_ADSRA_REG,ADC_INTERRUPT_BIT);
	#else if ADC_INTERRUPT == ADC_INTERRUPT_ENABLE
		SET_BIT(ADC_ADSRA_REG,ADC_INTERRUPT_BIT);
	#endif

	/*ADC ENABLE*/
	SET_BIT(ADC_ADSRA_REG,ADC_ENABLE_BIT);
}

u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
	u8 Loc_u8Result;
	/*Selection Channels*/
	ADC_ADMUX_REG &= ~(0b00011111);
	ADC_ADMUX_REG |= Copy_u8Channel;
	SET_BIT(ADC_ADSRA_REG,ADC_START_COVERSION_BIT);
	while (GET_BIT(ADC_ADSRA_REG,ADC_CONVERSIOM_FLAG_BIT) != 1);
	SET_BIT(ADC_ADSRA_REG,ADC_CONVERSIOM_FLAG_BIT);
	Loc_u8Result = ADC_ADHL_REG ;
	return Loc_u8Result;
}
