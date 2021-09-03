/*********************************************************************************/
/* Title        	: 	SPI Driver									             */
/* File Name    	: 	SPI_program.c   		                                 */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	05/01/2021                                               */
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

	uint8 Local_u8Count;
	uint8 StrData[15] = " I'am Micro1";

	for(Local_u8Count=0; Local_u8Count < 13; Local_u8Count++){

		SPI_voidSendChar(StrData[Local_u8Count]);
		_delay_ms(100);

	}


	while(1){ }
}
