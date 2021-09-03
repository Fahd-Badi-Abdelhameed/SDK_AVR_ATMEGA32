/*********************************************************************************/
/* Title        	: 	LCD Driver											     */
/* File Name    	: 	LCD_program.c                                            */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	16/10/2020                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

#include <avr/delay.h>



void LCD_voidWriteData(uint8 Copy_u8Data){

	DIO_voidSetPinValue(RS, HIGH);
	DIO_voidSetPinValue(RW, LOW);

	if(LCD_MODE == MODE_8_BIT){
		
		DIO_voidSetPortValue(PORT_DATA, Copy_u8Data);
		
		DIO_voidSetPinValue(EN, HIGH);
		_delay_ms(1);
		
		DIO_voidSetPinValue(EN, LOW);
		_delay_ms(1);
		
	}
	
	else if(LCD_MODE == MODE_4_BIT){
	
		DIO_voidSetPortValue(PORT_DATA, Copy_u8Data & 0xF0);
		
		DIO_voidSetPinValue(EN, HIGH);
		_delay_ms(1);
		
		DIO_voidSetPinValue(EN, LOW);
		_delay_ms(1);
		
		DIO_voidSetPortValue(PORT_DATA, Copy_u8Data << 4);
		
		DIO_voidSetPinValue(EN, HIGH);
		_delay_ms(1);
		
		DIO_voidSetPinValue(EN, LOW);
		_delay_ms(1);
		
	}	
	
	else{   asm("NOP");  }
		
}


void LCD_voidSendCommand(uint8 Copy_u8Command){

	DIO_voidSetPinValue (RS, LOW);
	DIO_voidSetPinValue (RW, LOW);
	
	if(LCD_MODE == MODE_8_BIT){
		
		DIO_voidSetPortValue(PORT_DATA, Copy_u8Command);
		
		DIO_voidSetPinValue(EN, HIGH);
		_delay_ms(1);
		
		DIO_voidSetPinValue(EN, LOW);
		_delay_ms(1);
		
	}
	
	else if(LCD_MODE == MODE_4_BIT){

		DIO_voidSetPortValue(PORT_DATA, Copy_u8Command & 0xF0);
		
		DIO_voidSetPinValue(EN, HIGH);
		_delay_ms(1);
		
		DIO_voidSetPinValue(EN, LOW);
		_delay_ms(1);
	
		DIO_voidSetPortValue(PORT_DATA, Copy_u8Command << 4);
	
		DIO_voidSetPinValue(EN, HIGH);
		_delay_ms(1);
	
		DIO_voidSetPinValue(EN, LOW);
		_delay_ms(1);
		
	}	
	
	else{   asm("NOP");  }

}



void LCD_voidInit(void){

	/* set port data as output */
	DIO_voidSetPortDirection(PORT_DATA, 0xFF);
		
	/* set RS, RW, EN pins  as output */
	DIO_voidSetPinDirection(RS, OUTPUT);
	DIO_voidSetPinDirection(RW, OUTPUT);
	DIO_voidSetPinDirection(EN, OUTPUT);
		
	/* Init data port & EN by zero */
	DIO_voidSetPortValue(PORT_DATA, LOW);
	DIO_voidSetPinValue(EN, LOW);
    _delay_ms(40);
	
	
	#if LCD_MODE == MODE_8_BIT

		LCD_voidSendCommand(FUNCTION_SET);
		_delay_ms(1);

		LCD_voidSendCommand(DISPLAY_ON_OFF);
		_delay_ms(1);

		LCD_voidSendCommand(DISPLAY_CLEAR);
		_delay_ms(2);
		
	#elif LCD_MODE == MODE_4_BIT
		
		LCD_voidSendCommand(0x33);
		LCD_voidSendCommand(0x32);
		LCD_voidSendCommand(0x28);
		_delay_ms(1);
		
		LCD_voidSendCommand(DISPLAY_ON_OFF);
		_delay_ms(1);
		
		LCD_voidSendCommand(DISPLAY_CLEAR);
		_delay_ms(2);
		
		LCD_voidSendCommand(0x06);
		
	#else 
		#erroe("You Chosed Wrong LCD Mode")
	#endif
}



void LCD_voidClearScreen(void){

	LCD_voidSendCommand(DISPLAY_CLEAR);
	_delay_ms(2);
}



void LCD_voidWriteString(uint8 *Copy_u8Ptr){
	
	uint8 Local_u8Counter = 0;

	while(Copy_u8Ptr[Local_u8Counter] != 0){
	
		LCD_voidWriteData(Copy_u8Ptr[Local_u8Counter]);
		Local_u8Counter++;
	
	}

}



void LCD_voidSetPosition(uint8 Copy_u8Row, uint8 Copy_u8Col){

	if(0 == Copy_u8Row){

		/* set ddram */
		LCD_voidSendCommand(128 + Copy_u8Col);
	}

	else if(1 == Copy_u8Row){

		/* set ddram */
		LCD_voidSendCommand(128 + 64 + Copy_u8Col);
	}

	else{  asm("NOP"); }

}



void LCD_voidDisplayLoop(uint8 Copy_u8Row, uint8 Copy_u8Speed, uint8 *Copy_u8Ptr){

	for(uint8 i=0; i<15; i++){

		LCD_voidSetPosition(Copy_u8Row, i);

		LCD_voidWriteString(Copy_u8Ptr);
		_delay_ms(Copy_u8Speed);

		LCD_voidSendCommand(DISPLAY_CLEAR);
		_delay_ms(2);

	}
}


void LCD_voidSetCGRAMAdres(void){

	LCD_voidSendCommand(64);
	LCD_voidWriteData(0b00000011);
	LCD_voidWriteData(0b00000011);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000011);
	LCD_voidWriteData(0b00000101);
	LCD_voidWriteData(0b00001001);

	LCD_voidWriteData(0b00011000);
	LCD_voidWriteData(0b00011000);
	LCD_voidWriteData(0b00010000);
	LCD_voidWriteData(0b00010000);
	LCD_voidWriteData(0b00010000);
	LCD_voidWriteData(0b00011000);
	LCD_voidWriteData(0b00010100);
	LCD_voidWriteData(0b00010010);

	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000010);
	LCD_voidWriteData(0b00000100);
	LCD_voidWriteData(0b00000100);
	LCD_voidWriteData(0b00001100);

	LCD_voidWriteData(0b00010000);
	LCD_voidWriteData(0b00010000);
	LCD_voidWriteData(0b00010000);
	LCD_voidWriteData(0b00010000);
	LCD_voidWriteData(0b00001000);
	LCD_voidWriteData(0b00000100);
	LCD_voidWriteData(0b00000100);
	LCD_voidWriteData(0b00000110);

	LCD_voidWriteData(0b00011111);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);

	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00011111);

	LCD_voidWriteData(0b00010000);
	LCD_voidWriteData(0b00010010);
	LCD_voidWriteData(0b00010000);
	LCD_voidWriteData(0b00010000);
	LCD_voidWriteData(0b00001000);
	LCD_voidWriteData(0b00000100);
	LCD_voidWriteData(0b00000010);
	LCD_voidWriteData(0b00000000);

	LCD_voidWriteData(0b00000001);
	LCD_voidWriteData(0b00000000);
	LCD_voidWriteData(0b00000000);
	LCD_voidWriteData(0b00000000);
	LCD_voidWriteData(0b00000000);
	LCD_voidWriteData(0b00000000);
	LCD_voidWriteData(0b00000000);
	LCD_voidWriteData(0b00000000);
}


void LCD_voidWriteNumber(uint8 Copy_u8Value){


	LCD_voidReverceNumber(Copy_u8Value);

}



void LCD_voidReverceNumber(uint8 Copy_u8Value){

	uint8 Local_u8Number = 0;

	if(0 == Copy_u8Value){

		LCD_voidWriteData('0');
	}

	else{

		while(Copy_u8Value > 0){

			Local_u8Number = (Local_u8Number * 10) + (Copy_u8Value % 10);
			Copy_u8Value = (Copy_u8Value / 10);

		}

		LCD_voidDetachNumber(Local_u8Number);
	}

}



void LCD_voidDetachNumber(uint8 Copy_u8Value){

	uint8 Local_u8Number = 0;

	while(Copy_u8Value > 0){

		Local_u8Number = (Copy_u8Value % 10);
		LCD_voidWriteData(Local_u8Number + 48);
		Copy_u8Value = (Copy_u8Value / 10);
	}

}
