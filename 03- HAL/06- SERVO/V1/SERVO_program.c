/*****************************************************************************/
/* Title        	: 	SERVO Driver									     */
/* File Name    	: 	SERVO_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	30/01/2021                                           */
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
******************************** TIMER1 DIRECTIVES ****************************
******************************************************************************/
#include "TIMER1_interface.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/
#include "SERVO_interface.h"
#include "SERVO_private.h"
#include "SERVO_config.h"


/******************************************************************************
***************************** Function Implementation *************************
******************************************************************************/

void SERVO_voidInit(void){

	/* set timer 1 prescaler to 8to get 1us tick time
	 * use fast mode with top value at OCRA reg to set the freq of servo
	 * diconnect OC1A PIN ,and generate the PWM on OC1B PIN with non inverting mode
	 * to use OCR1B reg as the ton value 
	 */

	TIMER1_voidInit(TIMER1_CTC_OCR1A_MODE, TIMER1_SCALER_8);
	TIMER1_voidOutputCompareInit(TIMER1_OC1_DISCONNECTED_MODE ,TIMER1_OCR1A);
	TIMER1_voidOutputCompareInit(TIMER1_OC1_NON_INVERTING_MODE ,TIMER1_OCR1B);

	/* 20000us to get 50hz */
	TIMER1_voidSetOCR1A(20000);
	/* 2000us Ton to get angle zero */
	TIMER1_voidSetOCR1B(1000);
}



void SERVO_voidSetAngle(uint8 Copy_u8Angle){

	uint16 Local_u16Result = (((uint32)Copy_u8Angle * 1000) / 180) + 1000;
	TIMER1_voidSetOCR1B(Local_u16Result);
}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/
