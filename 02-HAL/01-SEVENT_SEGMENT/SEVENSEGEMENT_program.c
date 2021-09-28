/**********************************/
/* Author :Ahmed Ashraf			  */
/* Date   :17 Sept 2020			  */
/* Versio :V01					  */
/**********************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include  <avr/delay.h>
#include  <avr/io.h>
#include  "DIO_interface.h"

#include "SEVENSEGEMENT_interface.h"
#include "SEVENSEGEMENT_private.h"
#include "SEVENSEGEMENT_config.h"


/*Number In orders from 0 to 9  */
static u8 arr[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,
		0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
/*Numbers in non-order from 9-0 */
static u8 arr2[10] = {0b01101111 ,0b01111111, 0b00000111,0b01111101,0b01101101,
						0b01100110,0b01001111,0b01011011,0b00000110,0b00111111};
void HSEVENSEGMENT_voidDisplayDigit(u8 Copy_u8Port , u8 Copy_u8SegType,u8 Copy_u8Number)
{
	if (Copy_u8SegType == COMMON_CATHOD)
	{
		switch (Copy_u8Port)
		{
			case PortA : PORTA |= arr[Copy_u8Number]; break;
			case PortB : PORTB |= arr[Copy_u8Number]; break;
			case PortC : PORTC |= arr[Copy_u8Number]; break;
			case PortD : PORTD |= arr[Copy_u8Number]; break;
			default :  break;
		}
	}
	else if (Copy_u8SegType ==COMMON_ANODE )
	{
		switch (Copy_u8Port)
		{
			case PortA : PORTA |= ~(arr[Copy_u8Number]); break;
			case PortB : PORTB |= ~(arr[Copy_u8Number]); break;
			case PortC : PORTC |= ~(arr[Copy_u8Number]); break;
			case PortD : PORTD |= ~(arr[Copy_u8Number]); break;
			default :  break;
		}
	}
	
	
}

void HSEVENSEGMENT_voidCounterDownOneSegment(u8 Copy_u8Port , u8 Copy_u8SegType,u8 Copy_u8EndNumber)
{
	if (Copy_u8SegType== COMMON_CATHOD)
	{
		switch(Copy_u8Port)
		{
		case PortA :
				for (u8 i =0 ; i<Copy_u8EndNumber ; i++)
				{
					PORTA=0;
					PORTA |= arr[i];
					_delay_ms(1000);
				}
				break;
		case PortB :
				for (u8 i =0 ; i<Copy_u8EndNumber ; i++)
				{
					PORTB=0;
					PORTB |= arr[i];
					_delay_ms(1000);
				}
				break;

		case PortC :
				for (u8 i =0 ; i<Copy_u8EndNumber ; i++)
				{
					PORTC=0;
					PORTC |= arr[i];
					_delay_ms(1000);
				}
				break;
		case PortD :
				for (u8 i =0 ; i<Copy_u8EndNumber ; i++)
				{
					PORTD=0;
					PORTD |= ~arr[i];
					_delay_ms(1000);
				}
				break;
		default   :  break;
		}

	}
	else if (Copy_u8SegType== COMMON_ANODE)
	{
		switch(Copy_u8Port)
		{
		case PortA :
				for (u8 i= Copy_u8EndNumber ; i>=0 ; i--)
				{

					PORTA = ~arr[i];
					_delay_ms(1000);
					if(i==0)
					{
						break;
					}
				}
				break;
		case PortB :
				for (u8 i =0 ; i<=Copy_u8EndNumber ; i++)
				{
					PORTB=0;
					PORTB |= ~arr2[i];
					_delay_ms(1000);
				}
				break;

		case PortC :
				for (u8 i =0 ; i<=Copy_u8EndNumber ; i++)
				{
					PORTC=0;
					PORTC |= ~arr2[i];
					_delay_ms(1000);
				}
				break;
		case PortD :
				for (u8 i =0 ; i<=Copy_u8EndNumber ; i++)
				{
					PORTD=0;
					PORTD |= ~arr2[i];
					_delay_ms(1000);
				}
				break;
		default   :  break;
		}
	}

}

void HSEVENSEGMENT_voidCounterDownTwoSevenSegements(u8 Copy_u8SegsType ,u8 Copy_u8EndNumberSegmentOne , u8 Copy_u8EndNumberSegmentTwo)
{
	PORTA= ~arr[Copy_u8EndNumberSegmentTwo];

	if (Copy_u8SegsType ==COMMON_ANODE)
	{
		if (Copy_u8EndNumberSegmentOne == 0 )
		{
			PORTB = ~arr[1];
			PORTA = ~arr[0];
			_delay_ms(1000);
			PORTB = ~arr[0];
			for (u8 j = Copy_u8EndNumberSegmentOne ;j >= 0 ; j--)
			{

				PORTB = ~arr[j];

				for (u8 i = 0 ; i<=Copy_u8EndNumberSegmentTwo ; i++)
				{

					PORTA = ~arr2[i];
					_delay_ms(1000);
				}
				if (j==0)
				{
					break;
				}

			 }
		}

		else {

			for (u8 j = Copy_u8EndNumberSegmentOne ;j >= 0 ; j--)
				{
					PORTA = ~arr[Copy_u8EndNumberSegmentTwo];
					PORTB = ~arr[j];
					_delay_ms(1000);
					if (Copy_u8EndNumberSegmentTwo == 9)
					{
						for (u8 i = 0 ; i<=Copy_u8EndNumberSegmentTwo ; i++)
					{

						PORTA = ~arr2[i];
						_delay_ms(1000);
					}
					else if (Copy_u8EndNumberSegmentTwo != 9)
					{
						HSEVENSEGMENT_voidCounterDownOneSegment(PortA,COMMON_ANODE,Copy_u8EndNumberSegmentTwo);
					}
					}
					
					
					if (j==0)
					{
								break;
					}

					}
		}

	}

}
