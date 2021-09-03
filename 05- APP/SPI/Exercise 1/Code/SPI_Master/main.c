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


	/******** Configure SPI Master Pins *********
	 * SS  (PB4) --> Output
	 * MOSI(PB5) --> Output
	 * MISO(PB6) --> Input
	 * SCK (PB7) --> Output
	 ********************************************/

	DIO_voidSetPinDirection(PORT_B, PIN4, OUTPUT);
	DIO_voidSetPinDirection(PORT_B, PIN5, OUTPUT);
	DIO_voidSetPinDirection(PORT_B, PIN6, INPUT );
	DIO_voidSetPinDirection(PORT_B, PIN7, OUTPUT);

	/* Enable SPI as master */
	SPI_voidInitMaster();

	/* Configure switch Pin*/

	DIO_voidSetPinDirection(PORT_D, PIN3, INPUT);
	DIO_voidSetPinValue(PORT_D, PIN3, LOW);

	while(1){

		if(DIO_u8GetPinValue(PORT_D, PIN3) == PRESSED){

			SPI_voidSendChar(PRESSED);
		}
		else if(DIO_u8GetPinValue(PORT_D, PIN3)== NOT_PRESSED){

			SPI_voidSendChar(NOT_PRESSED);
		}
	}
}
