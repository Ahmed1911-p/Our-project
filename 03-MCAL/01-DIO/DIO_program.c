#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_private.h"
#include "DIO_interface.h"



void DIO_voidSetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Value)
{
	if(Copy_u8PortId <= DIO_PORTD &&Copy_u8PinId <= DIO_PIN7 )
	{
		if (Copy_u8Value == DIO_HIGH)
		{
			  switch(Copy_u8PortId)
			  {
			  case DIO_PORTA :  SET_BIT(DIO_PORTA_REG ,Copy_u8PinId); break;
			  case DIO_PORTB :	SET_BIT(DIO_PORTB_REG ,Copy_u8PinId); break;
			  case DIO_PORTC :	SET_BIT(DIO_PORTC_REG ,Copy_u8PinId); break;
			  case DIO_PORTD : 	SET_BIT(DIO_PORTD_REG ,Copy_u8PinId); break;
			  }
		}
		else if (Copy_u8Value == DIO_LOW)
		{
			 switch(Copy_u8PortId)
			  {
			   case DIO_PORTA : CLR_BIT(DIO_PORTA_REG ,Copy_u8PinId); break;
			   case DIO_PORTB :	CLR_BIT(DIO_PORTB_REG ,Copy_u8PinId); break;
			   case DIO_PORTC :	CLR_BIT(DIO_PORTC_REG ,Copy_u8PinId); break;
			   case DIO_PORTD : CLR_BIT(DIO_PORTD_REG ,Copy_u8PinId); break;
					  }
		}

		else
			{
			  	   /*ERROR*/
		 }
	}
	else
	{
		/*ERROR */
	}

}

void DIO_voidSetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Direction)
{
	if (Copy_u8PortId <= DIO_PORTD &&Copy_u8PinId <= DIO_PIN7 )
	{
		if (Copy_u8Direction == DIO_OUTPUT)
		{
			  switch(Copy_u8PortId)
			  {
			  case DIO_PORTA :  SET_BIT(DIO_DDRA_REG ,Copy_u8PinId); break;
			  case DIO_PORTB :	SET_BIT(DIO_DDRB_REG ,Copy_u8PinId); break;
			  case DIO_PORTC :	SET_BIT(DIO_DDRC_REG ,Copy_u8PinId); break;
			  case DIO_PORTD : 	SET_BIT(DIO_DDRD_REG ,Copy_u8PinId); break;
			  }
		}
		else if (Copy_u8Direction == DIO_LOW)
		{
			 switch(Copy_u8PortId)
			  {
			   case DIO_PORTA : CLR_BIT(DIO_DDRA_REG ,Copy_u8PinId); break;
			   case DIO_PORTB :	CLR_BIT(DIO_DDRB_REG ,Copy_u8PinId); break;
			   case DIO_PORTC :	CLR_BIT(DIO_DDRC_REG ,Copy_u8PinId); break;
			   case DIO_PORTD : CLR_BIT(DIO_DDRD_REG ,Copy_u8PinId); break;
					  }
		}

		else
		 {
			  	   /*ERROR*/
		 }
	}
	else
	{
		/*ERROR */
	}


}

u8 DIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId)
{
	u8 Loc_u8Result = 0 ;
	if (Copy_u8PortId <= DIO_PORTD &&Copy_u8PinId <= DIO_PIN7)
	{
		  switch(Copy_u8PortId)
		  {
		  case DIO_PORTA :  Loc_u8Result = GET_BIT(DIO_PINA_REG ,Copy_u8PinId); break;
		  case DIO_PORTB :	Loc_u8Result = GET_BIT(DIO_PINB_REG ,Copy_u8PinId); break;
		  case DIO_PORTC :	Loc_u8Result = GET_BIT(DIO_PINC_REG ,Copy_u8PinId); break;
		  case DIO_PORTD : 	Loc_u8Result = GET_BIT(DIO_PIND_REG ,Copy_u8PinId); break;
		  }

	}
	else
	{
		Loc_u8Result = 0xFF ;
	}
	return Loc_u8Result ;

}

void DIO_voidSetPortValue(u8 Copy_u8PortId,u8 Copy_u8Value)
{
	if(Copy_u8PortId <= DIO_PORTD  )
		{
				  switch(Copy_u8PortId)
				  {
				  case DIO_PORTA :  DIO_PORTA_REG = Copy_u8Value;  break;
				  case DIO_PORTB :	DIO_PORTB_REG = Copy_u8Value;  break;
				  case DIO_PORTC :	DIO_PORTC_REG = Copy_u8Value;  break;
				  case DIO_PORTD : 	DIO_PORTD_REG = Copy_u8Value;  break;
				  }
		}
		else
		{
				  	   /*ERROR*/
		}
}
void DIO_voidSetPortDirection(u8 Copy_u8PortId,u8 Copy_u8Direction)
{
	if(Copy_u8PortId <= DIO_PORTD  )
		{
				  switch(Copy_u8PortId)
				  {
				  case DIO_PORTA :  DIO_DDRA_REG = Copy_u8Direction;  break;
				  case DIO_PORTB :	DIO_DDRB_REG = Copy_u8Direction;  break;
				  case DIO_PORTC :	DIO_DDRC_REG = Copy_u8Direction;  break;
				  case DIO_PORTD : 	DIO_DDRD_REG = Copy_u8Direction;  break;
				  }
			}
		else
		{
				  	   /*ERROR*/
		}
}

void DIO_voidEnablePinPullUpResistor(u8 Copy_u8PortId ,u8 Copy_u8PinId)
{
	if(Copy_u8PortId <= DIO_PORTD &&Copy_u8PinId <= DIO_PIN7 )
		{
				  switch(Copy_u8PortId)
				  {
				  case DIO_PORTA :  SET_BIT(DIO_PORTA_REG ,Copy_u8PinId); break;
				  case DIO_PORTB :	SET_BIT(DIO_PORTB_REG ,Copy_u8PinId); break;
				  case DIO_PORTC :	SET_BIT(DIO_PORTC_REG ,Copy_u8PinId); break;
				  case DIO_PORTD : 	SET_BIT(DIO_PORTD_REG ,Copy_u8PinId); break;
				  }

		}
}
