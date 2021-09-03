/*
 * main.c
 *
 *  Created on: Nov 8, 2020
 *      Author: almasry.net
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "LCD_interface.h"
#include <avr/delay.h>


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


	/* SPI Enable as slave */
	SPI_voidInitSlave();

	LCD_voidInit();

	uint8 Local_u8DataReceived = 0;

	LCD_voidClearScreen();
	LCD_voidSetPosition(0, 1);



	while(1){

		Local_u8DataReceived = SPI_u8ReceiveChar();
		_delay_ms(20);

		LCD_voidWriteData(Local_u8DataReceived);

	}
}
