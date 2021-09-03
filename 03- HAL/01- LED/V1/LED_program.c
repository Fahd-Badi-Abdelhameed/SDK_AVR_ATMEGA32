/********************************************************************************/
/* Title        	: 	LED Driver											    */
/* File Name    	: 	LED_program.c   		                                */
/* Author       	: 	Fahd Badi                                               */
/* Version      	: 	1.0.0                                                   */
/* Origin Date  	: 	09/10/2020                                              */
/* Notes        	: 	None                                                    */
/********************************************************************************/

/*********************************************************************************
******************************* STD LIB DIRECTIVES *******************************
*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*********************************************************************************
********************************* DIO DIRECTIVES *********************************
*********************************************************************************/

#include "DIO_interface.h"

/*********************************************************************************
****************************** Component DIRECTIVES ******************************
*********************************************************************************/

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


/*********************************************************************************
***************************** Function Implementation ****************************
*********************************************************************************/


/*********************************************************************************
* Description 	: Configuring an LED as output.						        	 *
* Parameters  	: none   		                                    	 		 *
* Return type 	: void                                                  	 	 *
*********************************************************************************/

void LED_voidInit(uint8 Copy_u8PortID, uint8 Copy_u8PinNumber){

	/* Setting the pin as output */
	DIO_voidSetPinDirection(Copy_u8PortID, Copy_u8PinNumber, OUTPUT);
	
	/* Setting the initial value as low */
	DIO_voidSetPinValue(Copy_u8PortID, Copy_u8PinNumber, LOW);

}


/*********************************************************************************
* Description 	: Control the state of an LED.							         *
* Parameters  	: PORT number(PORT_A -> PORT_D), PIN number(PIN0 -> PIN7),       *
*				  LED Value (LED_ON, LED_OFF, LED_TOG).     				     *
* Return type 	: void.                                                    	 	 *
**********************************************************************************
* Pre_condition : This function must be used after LED initialized.              *
*********************************************************************************/

void LED_voidLedValue(uint8 Copy_u8PortID, uint8 Copy_u8PinNumber, uint8 Copy_u8State){

	switch(Copy_u8State){

		case LED_ON :
			/* Setting the pin value as high */
			DIO_voidSetPinValue(Copy_u8PortID, Copy_u8PinNumber, LED_MODE);
	    break;

		case LED_OFF:
			/* Setting the pin value as low */
			DIO_voidSetPinValue(Copy_u8PortID, Copy_u8PinNumber, !(LED_MODE));
		break;

		case LED_TOG:
			/* Setting the pin value as toggle */
			DIO_voidTogglePin(Copy_u8PortID, Copy_u8PinNumber);
		break;

	}

}


/*********************************************************************************
********************************* END OF PROGRAM *********************************
*********************************************************************************/
