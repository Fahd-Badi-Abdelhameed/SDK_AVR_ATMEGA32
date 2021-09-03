/*****************************************************************************/
/* Title        	: 	BLUETOOTH Driver									 */
/* File Name    	: 	BLUETOOTH_program.c   		                         */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	03/02/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
******************************* STD LIB DIRECTIVES ****************************
******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************************************************
********************************* DIO DIRECTIVES ******************************
******************************************************************************/
#include "DIO_interface.h"

/******************************************************************************
********************************* UART DIRECTIVES *****************************
******************************************************************************/
#include "UART_interface.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/
#include "BLUETOOTH_interface.h"
#include "BLUETOOTH_private.h"
#include "BLUETOOTH_config.h"


/******************************************************************************
***************************** Function Implementation *************************
******************************************************************************/

void BLUETOOTH_voidInit(void){

	/* RX Set the direction input for the Pin connected to the bluetooth */
	DIO_voidSetPinDirection(PORT_D, PIN0, INPUT);
	
	/* TX Set the direction output for the Pin connected to the bluetooth */
	DIO_voidSetPinDirection(PORT_D, PIN1, OUTPUT);

	/* init uart protocol */
	UART_voidInit();

}



uint8 BLUETOOTH_u8Receive(void){

	/* Receive data char */
	return UART_u8Receive();

}



void BLUETOOTH_voidSendChar(uint8 Copy_u8Data){

	/* Send data char */
	UART_voidSendChar(Copy_u8Data);

}



void BLUETOOTH_voidSendString(uint8 *Copy_u8Data){

	/* Send string data */
	UART_voidTransmitString(Copy_u8Data);

}



void BLUETOOTH_voidWriteNumber(uint32 Copy_u32Number){

	uint32 Local_u8Reversed = 1;

	if(0 == Copy_u32Number){

		BLUETOOTH_voidSendChar('0');
	}
	while(0 != Copy_u32Number){

		Local_u8Reversed = ((Local_u8Reversed * 10) + (Copy_u32Number % 10));
		Copy_u32Number /= 10;
	}
	while(1 != Local_u8Reversed){

		BLUETOOTH_voidSendChar((Local_u8Reversed % 10 ) + 48);
		Local_u8Reversed /= 10;
	}

}



/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/