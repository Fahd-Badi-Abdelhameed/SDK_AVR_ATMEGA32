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

	LCD_voidClearScreen();

	DIO_voidSetPinDirection(PORT_B, PIN7, OUTPUT);
	DIO_voidSetPinDirection(PORT_B, PIN6, OUTPUT);

	//uint16 Local_u16DigitalValue = 0;
	uint16 Local_u16AnalogValue = 0;
	uint16 Local_u16Temp = 0;

	LCD_voidSetPosition(0, 0);
	LCD_voidWriteString("Day Temperature: ");

	LCD_voidSetPosition(1, 4);
	LCD_voidWriteString(" C");

	while(1){

		Local_u16AnalogValue = ADC_u16ReadValue(CHANNEL_A0);

		Local_u16Temp = (Local_u16AnalogValue*150*5)/(1023*1.5);

		if(Local_u16Temp < 25){

			DIO_voidSetPinValue(PORT_B, PIN7, HIGH);
			DIO_voidSetPinValue(PORT_B, PIN6, LOW );

		}
		else {

			DIO_voidSetPinValue(PORT_B, PIN7, LOW);
			DIO_voidSetPinValue(PORT_B, PIN6, HIGH );

		}


		LCD_voidSetPosition(1, 1);
		LCD_voidWriteNumber(Local_u16Temp);
		LCD_voidWriteString(" ");

		_delay_ms(300);
	}
}
