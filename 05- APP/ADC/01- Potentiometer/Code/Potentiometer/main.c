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

	uint16 Local_u16AnalogValue = 0;
	uint16 Local_u16DigitalValue = 0;

	while(1){

		Local_u16AnalogValue = ADC_u16ReadValue(CHANNEL_A0);

		Local_u16DigitalValue  = (5 * Local_u16AnalogValue ) / 1023;

		LCD_voidClearScreen();
		LCD_voidSetPosition(0, 1);
		LCD_voidWriteNumber(Local_u16DigitalValue);

		_delay_ms(100);
	}
}
