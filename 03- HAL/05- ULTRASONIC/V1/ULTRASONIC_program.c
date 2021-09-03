/*****************************************************************************/
/* Title        	: 	ULTRASONIC Driver									 */
/* File Name    	: 	ULTRASONIC_program.c   		                         */
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
******************************** Delay DIRECTIVES *****************************
******************************************************************************/
#include <util/delay.h>

/******************************************************************************
********************************* DIO DIRECTIVES ******************************
******************************************************************************/
#include "DIO_interface.h"

/******************************************************************************
******************************* Timer1 DIRECTIVES *****************************
******************************************************************************/
#include "Timer1_interface.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/
#include "ULTRASONIC_interface.h"
#include "ULTRASONIC_private.h"
#include "ULTRASONIC_config.h"


/******************************************************************************
******************************** Global Variables *****************************
******************************************************************************/

static volatile uint16 Global_u16Time1;
static volatile uint16 Global_u16Time2;
static volatile uint16 Global_u16Flag = 0;
static volatile uint16 Global_u16Counter = 0;

/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/

void ULTRASONIC_voidInit(void){
	
	TIMER1_voidInit(TIMER1_NORMAL_MODE, TIMER1_SCALER_8);
	TIMER1_voidOutputCompareInit(TIMER1_OC1_DISCONNECTED_MODE, TIMER1_OCR1A);
	TIMER1_voidOutputCompareInit(TIMER1_OC1_DISCONNECTED_MODE, TIMER1_OCR1B);

	TIMER1_voidICU_SetCallBack(ICU_InterruptAction);
	TIMER1_voidOVF_SetCallBack(OVF_InterruptAction);

}



uint8 ULTRASONIC_voidGetDistance(uint8 Copy_u8TriggerPort, uint8 Copy_u8TriggerPin){

	uint8 Local_u8Distance;
	uint16 Local_u16Time;
	Global_u16Counter = 0;
	Global_u16Flag = 0;

	DIO_voidSetPinValue(Copy_u8TriggerPort, Copy_u8TriggerPin, HIGH);
	_delay_us(10);
	DIO_voidSetPinValue(Copy_u8TriggerPort, Copy_u8TriggerPin, LOW);

	TIMER1_voidInputCaptureEdge(ICU_RISING_EDGE);

	TIMER1_voidICU_InterruptEnable();

	while(Global_u16Flag < 2);

	Local_u16Time = ((Global_u16Time2 - Global_u16Time1) + ((uint32)Global_u16Counter * 65535));

	Local_u8Distance = Local_u16Time / 58;

	TIMER1_voidICU_InterruptDisable();

	return Local_u8Distance;

}




static void OVF_InterruptAction(void){

	Global_u16Counter++;

}



static void ICU_InterruptAction(void){

	if(0 == Global_u16Flag){

		Global_u16Counter = 0;
		Global_u16Time1 = TIMER1_u16Get_ICR1();
		Global_u16Flag = 1;
		TIMER1_voidInputCaptureEdge(ICU_FALLING_EDGE);
	}
	else if(1 == Global_u16Flag){

		Global_u16Time2 = TIMER1_u16Get_ICR1();
		Global_u16Flag = 2;
		TIMER1_voidInputCaptureEdge(ICU_RISING_EDGE);
		TIMER1_voidICU_InterruptDisable();
		TIMER1_voidOVF_InterruptDisable();
	}
}




void ULTRASONIC_voidStart(uint8 Copy_u8TriggerPort, uint8 Copy_u8TriggerPin){

	if(0 == Global_u16Flag){

		DIO_voidSetPinValue(Copy_u8TriggerPort, Copy_u8TriggerPin, HIGH);
		_delay_us(10);
		DIO_voidSetPinValue(Copy_u8TriggerPort, Copy_u8TriggerPin, LOW);

		TIMER1_voidInputCaptureEdge(ICU_RISING_EDGE);

		TIMER1_voidICU_InterruptEnable();
		TIMER1_voidOVF_InterruptEnable();
	}

}


uint8 ULTRASONIC_voidGetDistanceNoBlock(uint8 *ReturnDistance){

	uint8 Local_u8Distance;
	uint16 Local_u16Time;

	if(Global_u16Flag == 2){

	Local_u16Time = ((Global_u16Time2 - Global_u16Time1) + ((uint32)Global_u16Counter * 65535));

	Local_u8Distance = Local_u16Time / 58;

	*ReturnDistance = Local_u8Distance;

	TIMER1_voidOVF_InterruptEnable();

	Global_u16Flag = 0;
	return 1;

	}
	return 0;
}



/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/  
