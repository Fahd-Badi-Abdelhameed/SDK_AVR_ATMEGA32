/*****************************************************************************/
/* Title        	: 	LCD Driver											 */
/* File Name    	: 	LCD_program.c                                        */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	16/10/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
******************************* STD LIB DIRECTIVES ****************************
******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************************************************
********************************* Delay DIRECTIVES ****************************
******************************************************************************/
#include <util/delay.h>

/******************************************************************************
********************************* DIO DIRECTIVES ******************************
******************************************************************************/
#include "DIO_interface.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"


/******************************************************************************
***************************** Function Implementation *************************
******************************************************************************/


/******************************************************************************
* Description 	: LCD Display Char on LCD Function.						      *
******************************************************************************/

void LCD_voidWriteData(uint8 Copy_u8Data)
{
	DIO_voidSetPinValue(LCD_RS_PIN, DIO_HIGH);
	DIO_voidSetPinValue(LCD_RW_PIN, DIO_LOW );

	#if (LCD_MODE == MODE_8_BIT)
		
		DIO_voidSetPinValue(LCD_D0_PIN, GET_BIT(Copy_u8Data, 0));
		DIO_voidSetPinValue(LCD_D1_PIN, GET_BIT(Copy_u8Data, 1));
		DIO_voidSetPinValue(LCD_D2_PIN, GET_BIT(Copy_u8Data, 2));
		DIO_voidSetPinValue(LCD_D3_PIN, GET_BIT(Copy_u8Data, 3));
		DIO_voidSetPinValue(LCD_D4_PIN, GET_BIT(Copy_u8Data, 4));
		DIO_voidSetPinValue(LCD_D5_PIN, GET_BIT(Copy_u8Data, 5));
		DIO_voidSetPinValue(LCD_D6_PIN, GET_BIT(Copy_u8Data, 6));
		DIO_voidSetPinValue(LCD_D7_PIN, GET_BIT(Copy_u8Data, 7));
		
		LCD_voidLatchEnable();

	#elif (LCD_MODE == MODE_4_BIT)

		DIO_voidSetPinValue(LCD_D4_PIN, GET_BIT(Copy_u8Data, 4));
		DIO_voidSetPinValue(LCD_D5_PIN, GET_BIT(Copy_u8Data, 5));
		DIO_voidSetPinValue(LCD_D6_PIN, GET_BIT(Copy_u8Data, 6));
		DIO_voidSetPinValue(LCD_D7_PIN, GET_BIT(Copy_u8Data, 7));
		
		LCD_voidLatchEnable();

		DIO_voidSetPinValue(LCD_D4_PIN, GET_BIT(Copy_u8Data, 0));
		DIO_voidSetPinValue(LCD_D5_PIN, GET_BIT(Copy_u8Data, 1));
		DIO_voidSetPinValue(LCD_D6_PIN, GET_BIT(Copy_u8Data, 2));
		DIO_voidSetPinValue(LCD_D7_PIN, GET_BIT(Copy_u8Data, 3));
		
		LCD_voidLatchEnable();
	
	#endif
	
}

/******************************************************************************
* Description 	: LCD Initialization Function.						          *
******************************************************************************/

void LCD_voidInit(void)
{
	/* set lcd pins data as output */
	DIO_voidSetPinDirection(LCD_D4_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_D5_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_D6_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_D7_PIN, DIO_OUTPUT);
		
	/* set RS, RW, EN pins  as output */
	DIO_voidSetPinDirection(LCD_RS_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_RW_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_EN_PIN, DIO_OUTPUT);
		
	/* Init data port & EN by zero */
	DIO_voidSetPinValue(LCD_EN_PIN, DIO_LOW);
	
	/* Delay 30ms to ensure the initialization of the LCD driver */
    _delay_ms(30);

	#if (LCD_MODE == MODE_8_BIT)

		DIO_voidSetPinDirection(LCD_D0_PIN, DIO_OUTPUT);
		DIO_voidSetPinDirection(LCD_D1_PIN, DIO_OUTPUT);
		DIO_voidSetPinDirection(LCD_D2_PIN, DIO_OUTPUT);
		DIO_voidSetPinDirection(LCD_D3_PIN, DIO_OUTPUT);
		_delay_ms(30);

		LCD_voidSendCommand(FUNCTION_SET_8BIT);
		_delay_ms(1);
		LCD_voidSendCommand(DISPLAY_ON_OFF);
		_delay_ms(1);
		LCD_voidSendCommand(DISPLAY_CLEAR);
		_delay_ms(2);
		
	#elif (LCD_MODE == MODE_4_BIT)
		
		LCD_voidSendCommand(0x33);
		LCD_voidSendCommand(0x32);
		LCD_voidSendCommand(0x28);
		_delay_ms(1);
		
		LCD_voidSendCommand(DISPLAY_ON_OFF);
		_delay_ms(1);
		LCD_voidSendCommand(DISPLAY_CLEAR);
		_delay_ms(2);
		LCD_voidSendCommand(ENTRY_MODE);
		
	#else 
		#erroe("You Chosed Wrong LCD Mode")
	#endif
}


/******************************************************************************
* Description 	: LCD Clear Screen Function.						          *
******************************************************************************/

void LCD_voidClearScreen(void)
{
	LCD_voidSendCommand(DISPLAY_CLEAR);
	_delay_ms(2);
}

/******************************************************************************
* Description 	: LCD Cursor OFF Function.						              *
******************************************************************************/

void LCD_voidCursorOff(void)
{
	LCD_voidSendCommand(CURSOR_OFF);
	_delay_ms(2);
}

/******************************************************************************
* Description 	: LCD Cursor ON Function.						              *
******************************************************************************/

void LCD_voidCursorOn(void)
{
	LCD_voidSendCommand(CURSOR_ON);
	_delay_ms(2);
}

/******************************************************************************
* Description 	: LCD Write String Function.						          *
******************************************************************************/

void LCD_voidWriteString(char *Copy_cPtrData)
{
	uint8 Local_u8Counter = 0;

	while(0 != Copy_cPtrData[Local_u8Counter])
	{
		LCD_voidWriteData(Copy_cPtrData[Local_u8Counter]);
		Local_u8Counter++;
	}
}

/******************************************************************************
* Description 	: LCD Set Cursor Function.						              *
******************************************************************************/

void LCD_voidSetPosition(uint8 Copy_u8Row, uint8 Copy_u8Col)
{
	if(0 == Copy_u8Row)
	{
		/* set ddram */
		LCD_voidSendCommand(LCD_SET_DDRAM_ROW0 + Copy_u8Col);
	}
	else if(1 == Copy_u8Row)
	{
		/* set ddram */
		LCD_voidSendCommand(LCD_SET_DDRAM_ROW1 + Copy_u8Col);
	}
	else{  /* return error */ }

}


/******************************************************************************
* Description 	: LCD Display Loop String or Char on lcd Function             *
******************************************************************************/

void LCD_voidDisplayLoop(uint8 Copy_u8Row, uint8 Copy_u8Speed, char *Copy_cPtr)
{
	uint8 Local_u8Counter = 0;

	for(Local_u8Counter=0; Local_u8Counter<15; Local_u8Counter++)
	{
		LCD_voidSetPosition(Copy_u8Row, Local_u8Counter);

		LCD_voidWriteString(Copy_cPtr);
		_delay_ms(Copy_u8Speed);

		LCD_voidSendCommand(DISPLAY_CLEAR);
		_delay_ms(2);

	}
}


/******************************************************************************
* Description 	: LCD Write Number on lcd Function.                           *
******************************************************************************/

void LCD_voidWriteNumber(uint16 Copy_u16Number)
{
	uint8 Local_u8Counter = 0, Local_u8Digits = 0, Local_u8Current;
	uint16 Local_u16CopyNumber = Copy_u16Number;

	if(0 == Copy_u16Number)
	{
		LCD_voidWriteData('0');
	}
	else
	{
		while(Local_u16CopyNumber)
		{
			Local_u16CopyNumber /= 10;
			Local_u8Digits++;
		}
		Local_u16CopyNumber = Copy_u16Number;

		for(Local_u8Counter = 0; Local_u8Counter < Local_u8Digits; Local_u8Counter++)
		{
			Local_u8Current = Local_u16CopyNumber / (Private_u16GetPower(10, Local_u8Digits - 1 - Local_u8Counter));
			LCD_voidWriteData(Local_u8Current + '0');
			Local_u16CopyNumber %= (Private_u16GetPower(10, Local_u8Digits - 1 - Local_u8Counter));
		}
	}
}


/******************************************************************************
* Description 	: LCD Writr Char (CGRAM) Function                             *
******************************************************************************/

void LCD_voidWriteExtraChar(uint8 Copy_u8Row, uint8 Copy_u8Col, char *Copy_PtrData)
{
	uint8 Local_u8Iteration1, Local_u8Iteration2;

	/*DDRAM-->CGRAM*/
	LCD_voidSendCommand(DDRAM_TO_CGRAM);

	for(Local_u8Iteration1 = 0 ; Local_u8Iteration1 < 64; Local_u8Iteration1++)
	{
		LCD_voidWriteData(Copy_PtrData[Local_u8Iteration1]);
	}

	/*CGRAM-->DDRAM*/
	LCD_voidSendCommand(CGRAM_TO_DDRAM);
	LCD_voidSetPosition(Copy_u8Row, Copy_u8Col);

	/*First eight character which saved at CGRAM*/
	for (Local_u8Iteration2 = 0; Local_u8Iteration2 <= 7; Local_u8Iteration2++)
	{
		/* Write bytes of DDRAM */
		LCD_voidWriteData(Local_u8Iteration2);
		_delay_ms(5);
	}
}


/******************************************************************************
************************ Private Functions Implementation *********************
******************************************************************************/

/******************************************************************************
* Description 	: LCD Send Command Function.						          *
******************************************************************************/

static void LCD_voidSendCommand(uint8 Copy_u8Command)
{
	DIO_voidSetPinValue (LCD_RS_PIN, DIO_LOW);
	DIO_voidSetPinValue (LCD_RW_PIN, DIO_LOW);

	#if (LCD_MODE == MODE_8_BIT)

		DIO_voidSetPinValue(LCD_D0_PIN, GET_BIT(Copy_u8Command, 0));
		DIO_voidSetPinValue(LCD_D1_PIN, GET_BIT(Copy_u8Command, 1));
		DIO_voidSetPinValue(LCD_D2_PIN, GET_BIT(Copy_u8Command, 2));
		DIO_voidSetPinValue(LCD_D3_PIN, GET_BIT(Copy_u8Command, 3));
		DIO_voidSetPinValue(LCD_D4_PIN, GET_BIT(Copy_u8Command, 4));
		DIO_voidSetPinValue(LCD_D5_PIN, GET_BIT(Copy_u8Command, 5));
		DIO_voidSetPinValue(LCD_D6_PIN, GET_BIT(Copy_u8Command, 6));
		DIO_voidSetPinValue(LCD_D7_PIN, GET_BIT(Copy_u8Command, 7));

		LCD_voidLatchEnable();

	#elif (LCD_MODE == MODE_4_BIT)

		DIO_voidSetPinValue(LCD_D4_PIN, GET_BIT(Copy_u8Command, 4));
		DIO_voidSetPinValue(LCD_D5_PIN, GET_BIT(Copy_u8Command, 5));
		DIO_voidSetPinValue(LCD_D6_PIN, GET_BIT(Copy_u8Command, 6));
		DIO_voidSetPinValue(LCD_D7_PIN, GET_BIT(Copy_u8Command, 7));

		LCD_voidLatchEnable();

		DIO_voidSetPinValue(LCD_D4_PIN, GET_BIT(Copy_u8Command, 0));
		DIO_voidSetPinValue(LCD_D5_PIN, GET_BIT(Copy_u8Command, 1));
		DIO_voidSetPinValue(LCD_D6_PIN, GET_BIT(Copy_u8Command, 2));
		DIO_voidSetPinValue(LCD_D7_PIN, GET_BIT(Copy_u8Command, 3));

		LCD_voidLatchEnable();

	#endif

}

/******************************************************************************
* Description 	: Get Power Private Function.					              *
******************************************************************************/

static uint16 Private_u16GetPower(uint8 Copy_u8Number1, uint8 Copy_u8Number2)
{
	uint16 Local_u16Result = 1;
	uint8 Local_u8Counter = 0;

	for(Local_u8Counter = 0; Local_u8Counter < Copy_u8Number2; Local_u8Counter++)
	{
		Local_u16Result *= Copy_u8Number1;
	}
	return Local_u16Result;
}

/******************************************************************************
* Description 	: Function to send High to Low enable pulse to lcd.			  *
******************************************************************************/

static void LCD_voidLatchEnable(void)
{
	DIO_voidSetPinValue(LCD_EN_PIN, DIO_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_EN_PIN, DIO_LOW);
	_delay_ms(1);
}

/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/
