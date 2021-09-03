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
#include "TIMER0_interface.h"
#include "TIMER1_interface.h"
#include "GIE_interface.h"

#include "LCD_interface.h"

static uint16 PeriodTicks = 0;
static uint16 OnTicks = 0;

void ICU_HW(void);

int main(void){

	DIO_voidSetPinDirection(DIO_PINB3, DIO_OUTPUT);     /* OC0 PIN */
	DIO_voidSetPinDirection(DIO_PIND6, DIO_INPUT ); 	/* ICU PIN */

	TIMER1_voidInputCaptureSetCallBack(&ICU_HW);
	ICU1_voidInit();

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



void ICU_HW(void){

	static uint16 Reading1, Reading2, Reading3;
	static uint8 Counter = 0;
	Counter++;

	if(Counter == 1){

		Reading1 = ICU1_u16ReadInputCapture();
	}
	else if(Counter == 2){

		Reading2 = ICU1_u16ReadInputCapture();
		PeriodTicks = Reading2 - Reading1;
		ICU1_voidSetTriggerEdge(ICU_FALLING_EDGE);
	}
	else if(Counter == 3){

		Reading3 = ICU1_u16ReadInputCapture();
		OnTicks = Reading3 - Reading2;
		TIMER1_voidInputCaptureInterruptDisable();

	}

}
