/*****************************************************************************/
/* Title        	: 	Software_ICU								         */
/* File Name    	: 	main.c   		                                     */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "DIO_interface.h"
#include "EXIT_interface.h"
#include "TIMER0_interface.h"
#include "TIMER1_interface.h"
#include "GIE_interface.h"

#include "LCD_interface.h"

static uint16 PeriodTicks = 0;
static uint16 OnTicks 	  = 0;

void ICU_SW(void);

int main(void){

	DIO_voidSetPinDirection(DIO_PINB3, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PIND2, DIO_INPUT );

	DIO_voidSetPinDirection(DIO_PIND0, DIO_OUTPUT);

	EXTI0_voidSetCallBack(&ICU_SW);
	EXIT0_voidEnable();
	EXIT0_voidTriggerEdge(RISING_EDGE);

	TIMER1_voidInit(TIMER1_NORMAL_MODE, TIMER1_SCALER_8);

	TIMER0_voidInit(TIMER0_FAST_PWM_MODE, TIMER0_SCALER_8);
	TIMER0_voidOutputCompareInit(TIMER0_OC0_NON_INVERTING_MODE);
	TIMER0_voidSetOutputCompareValue(64);



	LCD_voidInit();

	GIE_voidEnable();

	while(1){

		/* Wait until period ticks and on ticks are measured */
		while((PeriodTicks == 0)&&(OnTicks == 0));

		LCD_voidSetPosition(0, 0);
		LCD_voidWriteString("Period Time= ");
		LCD_voidWriteNumber(PeriodTicks);

		LCD_voidSetPosition(1, 0);
		LCD_voidWriteString("On Ticks = ");
		LCD_voidWriteNumber(OnTicks);

		_delay_ms(500);
	}

	return 0;
}



void ICU_SW(void){

	static uint8 Local_u8Counter = 0;
	Local_u8Counter++;

	if(1 == Local_u8Counter){

		/* First rising edge */
		TIMER1_voidSetTimerValue(0);
	}
	else if(2 == Local_u8Counter){

		PeriodTicks = TIMER1_voidReadTimerValue();

		/* Change trigger to falling edge */
		EXIT0_voidTriggerEdge(FALLING_EDGE);
	}
	else if(3 == Local_u8Counter){

		/* Timer reading now is period ticks + on ticks */
		OnTicks = TIMER1_voidReadTimerValue();
		OnTicks -= PeriodTicks;

		/* Disable INT0 interrupt */
		EXIT0_voidDisable();
	}

}
