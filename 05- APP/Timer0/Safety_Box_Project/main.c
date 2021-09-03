/*
 * main.c
 *
 *  Created on: Apr 25, 2021
 *      Author: Dell
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <stdio.h>
#include <util/delay.h>


#include "DIO_interface.h"
#include "KPD_interface.h"
#include "LCD_interface.h"
#include "SSD_interface.h"


void CorrectPassword(void);
void IncorrectPassword(void);


uint8 Global_u8Iteration = 0;
uint8 Global_u8Count = 0;
uint8 Global_u8Flag = 3;

int main(void){

	DIO_voidSetPinDirection(PORT_B, PIN3, OUTPUT);
	DIO_voidSetPinDirection(PORT_B, PIN4, OUTPUT);

	KPD_voidInit();
	LCD_voidInit();
	SSD_voidInit();

	/* LCD displays “Enter Your Password” @ Row_1 */
	LCD_voidWriteString("Enter Your Pass: ");
	LCD_voidSetPosition(1, 0);


	uint8 MyPassword[] = "0000";

	uint8 Local_u8KPDresult = 0;
	uint8 Local_u8Number = sizeof(MyPassword)-1;
	uint8 EnterPassword[sizeof(MyPassword)-1];

	SSD_voidDisplayNumber(Global_u8Flag);

	while(1){

		while(Global_u8Flag>0){

			Local_u8KPDresult = KPD_u8GetPressedKey(4,3);

			if((Local_u8KPDresult > NULL) && (Local_u8KPDresult != '#')){

				LCD_voidWriteData('*');
				EnterPassword[Global_u8Iteration] = Local_u8KPDresult;
				Global_u8Iteration++;

			}
			else if(Local_u8KPDresult == '#'){

				if(Global_u8Iteration == Local_u8Number){

					for(uint8 j=0; j<Local_u8Number; j++){

						if(EnterPassword[j] == MyPassword[j]){  Global_u8Count++;  }
					}

					if(Global_u8Count == Local_u8Number){  CorrectPassword();  }

					else{   IncorrectPassword();   }
			}
			else{  IncorrectPassword();  }
			}
		}

		Global_u8Flag = 3;
		SSD_voidDisplayNumber(Global_u8Flag);

	}

	return 0;
}






void CorrectPassword(void){

	LCD_voidClearScreen();
	LCD_voidSetPosition(0, 0);
	LCD_voidWriteString("Correct Password   ");

	SSD_voidDisplayNumber(0);

	/* Open the safey box */
	DIO_voidSetPinValue(PORT_B, PIN3, HIGH);
	_delay_ms(500);

	/* Back to All Default Value */
	DIO_voidSetPinValue(PORT_B, PIN3, LOW);
	Global_u8Iteration = 0;
	Global_u8Count = 0;
	LCD_voidSetPosition(0, 0);
	LCD_voidWriteString("Enter Your Pass: ");
	LCD_voidSetPosition(1, 0);
	Global_u8Flag = 3;
	SSD_voidDisplayNumber(Global_u8Flag);
}



void IncorrectPassword(void){

	LCD_voidClearScreen();
	LCD_voidSetPosition(0, 0);
	LCD_voidWriteString("Incorrect Pass   ");
	LCD_voidSetPosition(1, 0);
	LCD_voidWriteString("Try Again!            ");

	Global_u8Flag--;

	if(Global_u8Flag==0){

		SSD_voidDisplayNumber(Global_u8Flag);

		DIO_voidSetPinValue(PORT_B, PIN4, HIGH);

		LCD_voidClearScreen();
		LCD_voidSetPosition(0, 0);
		LCD_voidWriteString("Incorrect Pass 3 ");
		LCD_voidSetPosition(1, 0);
		LCD_voidWriteString("times wait 30 Sec");

		_delay_ms(3000);
		DIO_voidSetPinValue(PORT_B, PIN4, LOW);
	}
	else{

		SSD_voidDisplayNumber(Global_u8Flag);

	}

	_delay_ms(200);
	Global_u8Iteration = 0;
	Global_u8Count = 0;

	LCD_voidClearScreen();
	LCD_voidSetPosition(0, 0);
	LCD_voidWriteString("Enter Your Pass: ");

	LCD_voidSetPosition(1, 0);

}
