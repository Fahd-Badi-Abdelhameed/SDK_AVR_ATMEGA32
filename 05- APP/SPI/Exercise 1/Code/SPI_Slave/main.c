/*********************************************************************************/
/* Title        	: 	SPI LED Application								         */
/* File Name    	: 	main.c   		                                		 */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	06/01/2021                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include <avr/delay.h>

#define PRESSED 		1
#define NOT_PRESSED 	0


void main(void){

	/******** Configure SPI Slave Pins *********
	 * SS  (PB4) --> Input
	 * MOSI(PB5) --> Input
	 * MISO(PB6) --> Output
	 * SCK (PB7) --> Input
	 ********************************************/

	DIO_voidSetPinDirection(PORT_B, PIN4, INPUT );
	DIO_voidSetPinDirection(PORT_B, PIN5, INPUT );
	DIO_voidSetPinDirection(PORT_B, PIN6, OUTPUT);
	DIO_voidSetPinDirection(PORT_B, PIN7, INPUT );



	/* Configure LEDs pins */
	DIO_voidSetPinDirection(PORT_A, PIN0, OUTPUT);
	DIO_voidSetPinDirection(PORT_A, PIN1, OUTPUT);

	/* SPI Enable as slave */
	SPI_voidInitSlave();

	uint8 Local_u8DataReceived = 0;

	while(1){

		Local_u8DataReceived = SPI_u8ReceiveChar();

		if(Local_u8DataReceived == PRESSED){

			DIO_voidSetPinValue(PORT_A, PIN0, HIGH);
			DIO_voidSetPinValue(PORT_A, PIN1, LOW);
		}

		else if(Local_u8DataReceived == NOT_PRESSED){

			DIO_voidSetPinValue(PORT_A, PIN0, LOW);
			DIO_voidSetPinValue(PORT_A, PIN1, HIGH);
		}

	}
}
