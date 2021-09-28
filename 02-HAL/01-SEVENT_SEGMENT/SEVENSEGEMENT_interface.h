/**********************************/
/* Author :Ahmed Ashraf			  */
/* Date   :17 Sept 2020			  */
/* Versio :V01					  */
/**********************************/

#ifndef SEVENSEGMENT_INTERFACE_H
#define SEVENSEGMENT_INTERFACE_H

#define  COMMON_ANODE   0
#define	 COMMON_CATHOD  1

#define ONE		 0b00111111
#define TWO		 0b00000110
#define THREE 	 0b01001111
#define FOUR	 0b01100110
#define FIVE     0b01101101
#define SIX		 0b01111101
#define SEVENN	 0b00000111
#define EIGHT    0b01111111
#define NINE	 0b01101111



void HSEVENSEGMENT_voidDisplayDigit(u8 Copy_u8Port , u8 Copy_u8SegType,u8 Copy_u8Number);
void HSEVENSEGMENT_voidCounter(u8 Copy_u8Port , u8 Copy_u8SegType,u8 Copy_u8EndNumber);	

#endif