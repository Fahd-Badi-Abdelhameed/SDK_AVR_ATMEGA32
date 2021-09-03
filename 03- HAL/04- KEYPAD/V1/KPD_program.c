/*****************************************************************************/
/* Title        	: 	Keypad Driver									     */
/* File Name    	: 	KPD_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	23/10/2020                                           */
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
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

/******************************************************************************
***************************** Function Implementation *************************
******************************************************************************/


/******************************************************************************
* Description 	: KPD Initialization Function.						          *
******************************************************************************/

void KPD_voidInit(void){

	/* Set direction rows input */
	DIO_voidSetPinDirection( KPD_PORT, KPD_ROW1, INPUT );
	DIO_voidSetPinDirection( KPD_PORT, KPD_ROW2, INPUT );
	DIO_voidSetPinDirection( KPD_PORT, KPD_ROW3, INPUT );
	DIO_voidSetPinDirection( KPD_PORT, KPD_ROW4, INPUT );
	
	/* Set direction columns output */
	DIO_voidSetPinDirection( KPD_PORT, KPD_COL1, OUTPUT );
	DIO_voidSetPinDirection( KPD_PORT, KPD_COL2, OUTPUT );
	DIO_voidSetPinDirection( KPD_PORT, KPD_COL3, OUTPUT );
	DIO_voidSetPinDirection( KPD_PORT, KPD_COL4, OUTPUT );
	
	/* Set values rows high */
	DIO_voidSetPinValue( KPD_PORT, KPD_ROW1, HIGH );
	DIO_voidSetPinValue( KPD_PORT, KPD_ROW2, HIGH );
	DIO_voidSetPinValue( KPD_PORT, KPD_ROW3, HIGH );
	DIO_voidSetPinValue( KPD_PORT, KPD_ROW4, HIGH );
	
	/* Set values columns high */
	DIO_voidSetPinValue( KPD_PORT, KPD_COL1, HIGH );
	DIO_voidSetPinValue( KPD_PORT, KPD_COL2, HIGH );
	DIO_voidSetPinValue( KPD_PORT, KPD_COL3, HIGH );
	DIO_voidSetPinValue( KPD_PORT, KPD_COL4, HIGH );

}


/******************************************************************************
* Description 	: KPD Get Pressed Key Function.						          *
******************************************************************************/

uint8 KPD_u8GetPressedKey(uint8 Copy_u8RowFinal, uint8 Copy_u8ColumnFinal){

	uint8 Local_u8Column;
	uint8 Local_u8Row;
	uint8 Local_u8Return = 0;

	/* Looping on columns of the KeyPad */
	for(Local_u8Column = 0; Local_u8Column < Copy_u8ColumnFinal; Local_u8Column++){

		/* Activate the Column */
		DIO_voidSetPinValue(KPD_PORT, Local_u8Column + 4, LOW);

		/* Loop on the rows of the KeyPad */
		for(Local_u8Row = 0; Local_u8Row < Copy_u8RowFinal; Local_u8Row++){

			/* Check the status of the switch */
			if(0 == DIO_u8GetPinValue(KPD_PORT, Local_u8Row)){

				/* Get the value of the currently pressed switch */
				Local_u8Return = KPD_Number[Local_u8Row][Local_u8Column];

				/* Wait until the switch is released (Single Press) */
				while(0 == DIO_u8GetPinValue(KPD_PORT, Local_u8Row));

		        /* Delay to avoid bouncing */
		        _delay_ms(10);
			}
		}

		/* Deactivate the Column */
		DIO_voidSetPinValue(KPD_PORT, Local_u8Column + 4, HIGH);
	}
	return Local_u8Return;
}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/
