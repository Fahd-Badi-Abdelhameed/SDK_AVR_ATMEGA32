/*
 * main.c
 *
 *  Created on: Jan 26, 2021
 *      Author: Fahd Badi
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include "GIE_interface.h"

#include "LED_interface.h"
#include "LCD_interface.h"

#include "TIMER0_private.h"

#include <util/delay.h>


/******************************* TASK[1] Toggle led for 1ms *************************/


/******************************* TASK[2] Toggle led for 1ms *************************/

volatile uint8	C = 0;

void main(void){

	sei();

	uint32 x = 0, y=0;
	GIE_voidEnable();

	LCD_voidInit();
	LED_voidInit(PORT_B, PIN0);

	TIMER0_voidInit(TIMER0_NORMAL_MODE, TIMER0_SCALER_1);
	TIMER0_voidOVInterruptEnable();


	TCNT0 = 24;

	y = C;

	LCD_voidWriteNumber(x);

	LCD_voidSetPosition(1, 0);

	LCD_voidWriteNumber(y);

	while(1){


	}
}

ISR(TIMER0_OVF){

	C++;
	if(C == 4){

		LED_voidLedValue(PORT_B, PIN0, LED_TOG);
		TCNT0 = 24;
		C = 0;
	}
}

/******************************* TASK[3] PWM *************************/



/*
 * main.c
 * PWM Ton = 20%, Toff = 80%
 *  
 *      
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include "GIE_interface.h"

#include "LED_interface.h"
#include "LCD_interface.h"

#include "TIMER0_private.h"

#include <util/delay.h>

/* Toggle led for 1ms */

volatile uint8	C = 0;

void main(void){

	sei();

	uint32 x = 0, y=0;
	GIE_voidEnable();

	LCD_voidInit();
	DIO_voidSetPinDirection(PORT_B, PIN0, OUTPUT);

	TIMER0_voidInit(TIMER0_NORMAL_MODE, TIMER0_SCALER_8);
	TIMER0_voidOVInterruptEnable();


	TCNT0 = 56;

	y = C;

	LCD_voidWriteNumber(x);

	LCD_voidSetPosition(1, 0);

	LCD_voidWriteNumber(y);

	while(1){


	}
}



ISR(TIMER0_OVF){

	TCNT0 = 56;
	C++;
	if(C == 4){

		DIO_voidSetPinValue(PORT_B, PIN0, HIGH);
	}
	else if(C == 5){

		DIO_voidSetPinValue(PORT_B, PIN0, LOW);
		C = 0;
	}

}

/******************************* TASK[4] 3 PWM signal *************************/


/*
 * main.c
 *
 *  Created on: Jan 26, 2021
 *      Author: Fahd Badi
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include "GIE_interface.h"

#include "LED_interface.h"
#include "LCD_interface.h"

#include "TIMER0_private.h"

#include <util/delay.h>

/* Toggle led for 1ms */

static uint8 C , mili;

void main(void){

	sei();

	uint8 x = 0, y=0;
	GIE_voidEnable();

	LCD_voidInit();
	LED_voidInit(PORT_B, PIN0);
	LED_voidInit(PORT_B, PIN1);
	LED_voidInit(PORT_B, PIN2);

	TIMER0_voidInit(TIMER0_NORMAL_MODE, TIMER0_SCALER_8);
	TIMER0_voidOVInterruptEnable();


	TCNT0 = 56;

	y = C;

	LCD_voidWriteNumber(x);

	LCD_voidSetPosition(1, 0);

	LCD_voidWriteNumber(y);

	while(1){


	}
}



ISR(TIMER0_OVF){

	TCNT0 = 56;
	C++;
	if(C == 5){

		mili++;
		C=0;
		if(mili % 5 == 0){

			LED_voidLedValue(PORT_B, PIN0, LED_TOG);

		}
		if(mili % 10 == 0){

			LED_voidLedValue(PORT_B, PIN1, LED_TOG);

		}
		if(mili % 25 == 0){

			LED_voidLedValue(PORT_B, PIN2, LED_TOG);

		}
		if(mili == 50){

			mili = 0;
		}
	}

}


/******************************* TASK[4] 3 PWM signal *************************/








