/**********************************/
/* Author :Ahmed Ashraf			  */
/* Date   :9 Sept 2020			  */
/* Versio :V01					  */
/**********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include  <avr/delay.h>

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

void HLEDMRX_voidInit(void)
{
	/*Set ROW PINS */
	MDIO_voidSetDirection(LEDMRX_ROW0_PIN,OUTPUT);
	MDIO_voidSetDirection(LEDMRX_ROW1_PIN,OUTPUT);
	MDIO_voidSetDirection(LEDMRX_ROW2_PIN,OUTPUT);
	MDIO_voidSetDirection(LEDMRX_ROW3_PIN,OUTPUT);
	MDIO_voidSetDirection(LEDMRX_ROW4_PIN,OUTPUT);
	MDIO_voidSetDirection(LEDMRX_ROW5_PIN,OUTPUT);
	MDIO_voidSetDirection(LEDMRX_ROW6_PIN,OUTPUT);
	MDIO_voidSetDirection(LEDMRX_ROW7_PIN,OUTPUT);
	/*Set Column PINS */
	MDIO_voidSetDirection(LEDMRX_COL0_PIN,OUTPUT);
	MDIO_voidSetDirection(LEDMRX_COL1_PIN,OUTPUT);
	MDIO_voidSetDirection(LEDMRX_COL2_PIN,OUTPUT);
	MDIO_voidSetDirection(LEDMRX_COL3_PIN,OUTPUT);
	MDIO_voidSetDirection(LEDMRX_COL4_PIN,OUTPUT);
	MDIO_voidSetDirection(LEDMRX_COL5_PIN,OUTPUT);
	MDIO_voidSetDirection(LEDMRX_COL6_	PIN,OUTPUT);
	MDIO_voidSetDirection(LEDMRX_COL7_PIN,OUTPUT);
}

void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{
	while(1){
	/*Column 0 */
	/*Disable All Rows */
	 HLEDMRX_voidDisbleAllRows();
	 /*See Values of column */
	HLEDMRX_voidSetColoumnValues(Copy_u8Data[0]);
	/*Enable ROW 0 */
	MDIO_voidSetPinValue(LEDMRX_ROW0_PIN,LOW);
	/*Delay */
	_delay_ms(2.5); // 2.5mSec
	
	/*Column 1 */
	/*Disable All Rows */
	 HLEDMRX_voidDisbleAllRows();
	 /*See Values of Coloumn */
	HLEDMRX_voidSetColoumnValues(Copy_u8Data[1]);
	/*Enable ROW 1*/
	MDIO_voidSetPinValue(LEDMRX_ROW1_PIN,LOW);
	/*Delay */
	_delay_ms(2.5); // 2.5mSec
	
	/*Column 2 */
	/*Disable All Rows */
	 HLEDMRX_voidDisbleAllRows();
	 /*See Values of Coloumn */
	HLEDMRX_voidSetColoumnValues(Copy_u8Data[2]);
	/*Enable ROW 2 */
	MDIO_voidSetPinValue(LEDMRX_ROW2_PIN,LOW);
	/*Delay */
	_delay_ms(2.5); // 2.5mSec
	
	/*Column 3 */
	/*Disable All Rows */
	 HLEDMRX_voidDisbleAllRows();
	 /*See Values of Coloumn */
	HLEDMRX_voidSetColoumnValues(Copy_u8Data[3]);
	/*Enable ROW 3 */
	MDIO_voidSetPinValue(LEDMRX_ROW3_PIN,LOW);
	/*Delay */
	_delay_ms(2.5); // 2.5mSec
	
	
	/*Column 4 */
	/*Disable All Rows */
	 HLEDMRX_voidDisbleAllRows();
	 /*See Values of Coloumn */
	HLEDMRX_voidSetColoumnValues(Copy_u8Data[4]);
	/*Enable ROW 4 */
	MDIO_voidSetPinValue(LEDMRX_ROW4_PIN,LOW);
	/*Delay */
	_delay_ms(2.5); // 2.5mSec
	
	/*Column 5 */
	/*Disable All Rows */
	 HLEDMRX_voidDisbleAllRows();
	 /*See Values of Coloumn */
	HLEDMRX_voidSetColoumnValues(Copy_u8Data[5]);
	/*Enable ROW 5 */
	MDIO_voidSetPinValue(LEDMRX_ROW5_PIN,LOW);
	/*Delay */
	_delay_ms(2.5); // 2.5mSec
	
	/*Column 6 */
	/*Disable All Rows */
	 HLEDMRX_voidDisbleAllRows();
	 /*See Values of Coloumn */
	HLEDMRX_voidSetColoumnValues(Copy_u8Data[0]);
	/*Enable ROW 6 */
	MDIO_voidSetPinValue(LEDMRX_ROW6_PIN,LOW);
	/*Delay */
	_delay_ms(2.5); // 2.5mSec
	
	/*Column 7 */
	/*Disable All Rows */
	 HLEDMRX_voidDisbleAllRows();
	 /*See Values of Coloumn */
	HLEDMRX_voidSetColoumnValues(Copy_u8Data[7]);
	/*Enable ROW 7 */
	MDIO_voidSetPinValue(LEDMRX_ROW7_PIN,LOW);
	/*Delay */
	_delay_ms(2.5); // 2.5mSec

	
	
	}
}

static void  HLEDMRX_voidDisbleAllRows(void)
{
	MDIO_voidSetPinValue(LEDMRX_ROW0_PIN,HIGH);
	MDIO_voidSetPinValue(LEDMRX_ROW1_PIN,HIGH);
	MDIO_voidSetPinValue(LEDMRX_ROW2_PIN,HIGH);
	MDIO_voidSetPinValue(LEDMRX_ROW3_PIN,HIGH);
	MDIO_voidSetPinValue(LEDMRX_ROW4_PIN,HIGH);
	MDIO_voidSetPinValue(LEDMRX_ROW5_PIN,HIGH);
	MDIO_voidSetPinValue(LEDMRX_ROW6_PIN,HIGH);
	MDIO_voidSetPinValue(LEDMRX_ROW7_PIN,HIGH);
}
static void HLEDMRX_voidSetColoumnValues(u8 Copy_u8Value)
{
	u8 Local_u8Bit = 0;
	Local_u8Bit = GET_BIT(Copy_u8Value,0);
	MDIO_voidSetPinValue(LEDMRX_COL0_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,1);
	MDIO_voidSetPinValue(LEDMRX_COL1_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,2);
	MDIO_voidSetPinValue(LEDMRX_COL2_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,3);
	MDIO_voidSetPinValue(LEDMRX_COL3_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,4);
	MDIO_voidSetPinValue(LEDMRX_COL4_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,5);
	MDIO_voidSetPinValue(LEDMRX_COL5_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,6);
	MDIO_voidSetPinValue(LEDMRX_COL6_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,7);
	MDIO_voidSetPinValue(LEDMRX_COL7_PIN,Local_u8Bit);
}