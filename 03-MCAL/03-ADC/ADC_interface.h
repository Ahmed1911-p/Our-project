/***********************************/
/*  Author : Ahmed Ashraf		   */
/* 	DATE   : 13 OCT 2020    	   */
/*  Version: V01				   */
/***********************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/*Channels Single Ended*/
#define ADC_SINGLE_ENDED_ADC0		0x00
#define ADC_SINGLE_ENDED_ADC1		0x01
#define ADC_SINGLE_ENDED_ADC2		0x02
#define ADC_SINGLE_ENDED_ADC3		0x03
#define ADC_SINGLE_ENDED_ADC4		0x04
#define ADC_SINGLE_ENDED_ADC5		0x05
#define ADC_SINGLE_ENDED_ADC6		0x06
#define ADC_SINGLE_ENDED_ADC7		0x07

#define ADC_SINGLE_ENDED_0v			0x1F
#define ADC_SINGLE_ENDED_1_22v		0x0E

/*Channels Differnitail +ve input _-ve input */
#define ADC_DIFF_ADC0_ADC0_10x		0x08
#define ADC_DIFF_ADC1_ADC0_10x		0x09
#define ADC_DIFF_ADC0_ADC0_200x		0x0A
#define ADC_DIFF_ADC1_ADC0_200x		0x0B
#define ADC_DIFF_ADC2_ADC2_10x		0x0C
#define ADC_DIFF_ADC3_ADC2_10x		0x0D
#define ADC_DIFF_ADC2_ADC2_200x		0x0E
#define ADC_DIFF_ADC3_ADC2_200x		0x0F

#define ADC_DIFF_ADC0_ADC1_1x		0x10
#define ADC_DIFF_ADC1_ADC1_1x		0x11
#define ADC_DIFF_ADC2_ADC1_1x		0x12
#define ADC_DIFF_ADC3_ADC1_1x		0x13
#define ADC_DIFF_ADC4_ADC1_1x		0x14
#define ADC_DIFF_ADC5_ADC1_1x		0x15
#define ADC_DIFF_ADC6_ADC1_1x		0x16
#define ADC_DIFF_ADC7_ADC1_1x		0x17
#define ADC_DIFF_ADC0_ADC2_1x		0x18
#define ADC_DIFF_ADC1_ADC2_1x		0x19
#define ADC_DIFF_ADC2_ADC2_1x		0x1A
#define ADC_DIFF_ADC3_ADC2_1x		0x1B
#define ADC_DIFF_ADC4_ADC2_1x		0x1C
#define ADC_DIFF_ADC5_ADC2_1x		0x1D

/*Functions */
void ADC_voidInint(void);
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel);




#endif