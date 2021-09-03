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
#include "ADC_interface.h"
#include "LCD_interface.h"
#include "GIE_interface.h"
#include <avr/delay.h>




void main(void){

	ADC_voidInit();
	LCD_voidInit();

	DIO_voidSetPinDirection(PORT_B, PIN7, OUTPUT);

	uint16 Local_u16AnalogValue = 0;
	uint16 Local_u16DigitalValue = 0;
	uint32 Local_u16Result = 0;

	LCD_voidClearScreen();

	while(1){

		Local_u16AnalogValue = ADC_u16ReadValue(CHANNEL_A0);

		Local_u16DigitalValue  = (5 * Local_u16AnalogValue ) / 1023;

		Local_u16Result = (1000 * Local_u16DigitalValue)/(5 - Local_u16DigitalValue);


		if(Local_u16Result >= 3000){

			DIO_voidSetPinValue(PORT_B, PIN7, HIGH);

		}
		else {

			DIO_voidSetPinValue(PORT_B, PIN7, LOW);
		}


		LCD_voidSetPosition(0, 1);
		LCD_voidWriteNumber(Local_u16Result);

		LCD_voidSetPosition(1, 1);
		LCD_voidWriteNumber(Local_u16DigitalValue);

		_delay_ms(300);


	}
}
