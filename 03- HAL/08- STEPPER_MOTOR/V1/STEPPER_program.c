/*****************************************************************************/
/* Title        	: 	STEPPER Driver									     */
/* File Name    	: 	STEPPER_program.c   		                         */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	02/02/2021                                           */
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
********************************* Delay DIRECTIVES ****************************
******************************************************************************/
#include <util/delay.h>

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/
#include "STEPPER_interface.h"
#include "STEPPER_private.h"
#include "STEPPER_config.h"


/******************************************************************************
***************************** Function Implementation *************************
******************************************************************************/


void STEPPER_voidInit(void){

	/* Set the direction output for the Pins connected to the Stepper Motor */
	DIO_voidSetPinDirection(STEPPER_COIL1_PIN, OUTPUT);
	DIO_voidSetPinDirection(STEPPER_COIL2_PIN, OUTPUT);
	DIO_voidSetPinDirection(STEPPER_COIL3_PIN, OUTPUT);
	DIO_voidSetPinDirection(STEPPER_COIL4_PIN, OUTPUT);
	
}



void STEPPER_voidRotateCW(Stepper_Mode_t Mode, uint8 Copy_u8Speed){

	switch(Mode){

		case STEPPER_FULL_STEP_MODE:

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, HIGH);
			_delay_ms(Copy_u8Speed);

		break;

		case STEPPER_HALF_STEP_MODE:

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, HIGH);
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, HIGH);
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, HIGH);
			_delay_ms(Copy_u8Speed);

		break;

		default:  break;
	}

}




void STEPPER_voidRotateACW(Stepper_Mode_t Mode, uint8 Copy_u8Speed){

	switch(Mode){

		case STEPPER_FULL_STEP_MODE:

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, HIGH);
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

		break;

		case STEPPER_HALF_STEP_MODE:

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, HIGH);
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, HIGH);
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, LOW );
			_delay_ms(Copy_u8Speed);

			DIO_voidSetPinValue(STEPPER_COIL1_PIN, HIGH);
			DIO_voidSetPinValue(STEPPER_COIL2_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL3_PIN, LOW );
			DIO_voidSetPinValue(STEPPER_COIL4_PIN, HIGH);
			_delay_ms(Copy_u8Speed);

		break;

		default:  break;
	}

}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/