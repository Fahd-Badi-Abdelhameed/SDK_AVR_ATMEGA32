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


int main(void){

	DIO_voidSetPinDirection(PORT_D, PIN0, OUTPUT);

	KPD_voidInit();
	LCD_voidInit();

	/* LCD displays “Enter Your Password” @ Row_1 */
	LCD_voidWriteString("Enter Your Pass: ");
	LCD_voidSetPosition(1, 0);


	uint8 StorePass[] = "1234";

	uint8 Key = 0, i = 0, Count = 0;
	uint8 Number = sizeof(StorePass)-1;
	uint8 Pass[sizeof(StorePass)-1];

	while(1){

		Key = KPD_u8GetPressedKey(4,4);

		if((Key > '0') && (Key != '9')){

			LCD_voidWriteData('*');
			Pass[i] = Key;
			i++;

		}
		else if(Key == '9'){

			if(i == Number){

				for(uint8 j=0; j<Number; j++){

					if(Pass[j] == StorePass[j]){

						Count++;
					}
				}
				if(Count == Number){

					LCD_voidClearScreen();
					//DIO_voidSetPinValue(PORT_D, PIN0, HIGH);
					LCD_voidSetPosition(0, 0);
					LCD_voidWriteString("Correct Pass:        ");
					_delay_ms(2000);
					i = 0;
					Count = 0;

					LCD_voidSetPosition(0, 0);
					LCD_voidWriteString("Enter Your Pass: ");

					LCD_voidSetPosition(1, 0);
				}
				else{

					LCD_voidClearScreen();
					//DIO_voidSetPinValue(PORT_D, PIN0, LOW);
					LCD_voidSetPosition(0, 0);
					LCD_voidWriteString("Wrong Pass:        ");
					_delay_ms(2000);
					i = 0;
					Count = 0;

					LCD_voidSetPosition(0, 0);
					LCD_voidWriteString("Enter Your Pass: ");

					LCD_voidSetPosition(1, 0);

				}

			}
			else{

				LCD_voidClearScreen();
				//DIO_voidSetPinValue(PORT_D, PIN0, LOW);
				LCD_voidSetPosition(0, 0);
				LCD_voidWriteString("Wrong Pass:        ");
				_delay_ms(2000);
				i = 0;
				Count = 0;

				LCD_voidSetPosition(0, 0);
				LCD_voidWriteString("Enter Your Pass: ");

				LCD_voidSetPosition(1, 0);

			}

		}

	}

	return 0;
}
