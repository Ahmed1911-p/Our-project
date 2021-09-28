#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H
/*********************************************************/
/******                          PUBLIC MACROS           */
/********************************************************/
//PORT DEFINITIONS
#define DIO_PORTA       0
#define DIO_PORTB	    1
#define DIO_PORTC       3
#define DIO_PORTD	    4
//PIN DEFINTION
#define DIO_PIN0        0
#define DIO_PIN1        1
#define DIO_PIN2        2
#define DIO_PIN3        3
#define DIO_PIN4        4
#define DIO_PIN5        5
#define DIO_PIN6        6
#define DIO_PIN7        7
//DIGITAL VALUE
#define DIO_HIGH		1
#define DIO_LOW			0
// Direction Definition
#define DIO_INPUT       0
#define DIO_OUTPUT      1
//FOR ALL PORT
#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT  0x00
#define DIO_PORT_HIGH   0xff
#define DIO_PORT_LOW    0x00
/*********************************************************/
/******                PUBLIC FUNCTIONS                  */
/********************************************************/
// Determine value for pin for any port
void DIO_voidSetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Value);
//Derermine direction for pin for any port
void DIO_voidSetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Direction);
//Get Value of pin in any port
u8 DIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId);
//Determine ALL PORT VALUE
void DIO_voidSetPortValue(u8 Copy_u8PortId,u8 Copy_u8Value);
//Determine ALL PORT DIRECTION 1-> OutPut    0-> INPUT
void DIO_voidSetPortDirection(u8 Copy_u8PortId,u8 Copy_u8Direction);

/*Enable Pull Up Ressistor */
void DIO_voidEnablePinPullUpResistor(u8 Copy_u8PortId ,u8 Copy_u8PinId);
#endif
