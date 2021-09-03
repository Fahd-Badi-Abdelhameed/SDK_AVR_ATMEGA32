/*****************************************************************************/
/* Title        	: 	DIO Driver								 			 */
/* File Name   		: 	DIO_program.c                                        */
/* Author       	: 	Fahd Badi                                            */
/* Version          : 	1.0.0                                                */
/* Origin Date  	: 	10/10/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
******************************* STD LIB DIRECTIVES ****************************
******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/

void DIO_voidSetPinDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Mode){

	if(OUTPUT == Copy_u8Mode){
	
		switch(Copy_u8Port){
		
			case PORT_A:	SET_BIT(DDRA, Copy_u8Pin);		break;
			case PORT_B:	SET_BIT(DDRB, Copy_u8Pin);		break;
			case PORT_C:	SET_BIT(DDRC, Copy_u8Pin);		break;
			case PORT_D:	SET_BIT(DDRD, Copy_u8Pin);		break;
			
		}
	}
	
	else if(INPUT == Copy_u8Mode){
	
		switch(Copy_u8Port){
		
			case PORT_A:	CLR_BIT(DDRA, Copy_u8Pin);		break;
			case PORT_B:	CLR_BIT(DDRB, Copy_u8Pin);		break;
			case PORT_C:	CLR_BIT(DDRC, Copy_u8Pin);		break;
			case PORT_D:	CLR_BIT(DDRD, Copy_u8Pin);		break;
			
		}
	}
	
	else{    /* return error  */   }
	
}


void DIO_voidSetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Value){

	if(HIGH == Copy_u8Value){
	
		switch(Copy_u8Port){
		
			case PORT_A:	SET_BIT(PORTA, Copy_u8Pin);		break;
			case PORT_B:	SET_BIT(PORTB, Copy_u8Pin);		break;
			case PORT_C:	SET_BIT(PORTC, Copy_u8Pin);		break;
			case PORT_D:	SET_BIT(PORTD, Copy_u8Pin);		break;
			
		}
	}
	
	else if(LOW == Copy_u8Value){
	
		switch(Copy_u8Port){
		
			case PORT_A:	CLR_BIT(PORTA, Copy_u8Pin);		break;
			case PORT_B:	CLR_BIT(PORTB, Copy_u8Pin);		break;
			case PORT_C:	CLR_BIT(PORTC, Copy_u8Pin);		break;
			case PORT_D:	CLR_BIT(PORTD, Copy_u8Pin);		break;
			
		}
	}
	
	else{    /* return error  */   }
	
}


uint8 DIO_u8GetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin){

	uint8 Local_u8Result = 0; 

	switch(Copy_u8Port){ 
	
		case PORT_A:	Local_u8Result = GET_BIT(PINA, Copy_u8Pin);    break;
		case PORT_B:	Local_u8Result = GET_BIT(PINB, Copy_u8Pin);    break;
		case PORT_C:	Local_u8Result = GET_BIT(PINC, Copy_u8Pin);    break;	
		case PORT_D:    Local_u8Result = GET_BIT(PIND, Copy_u8Pin);    break;
		
	}
	return Local_u8Result;
}


void DIO_voidSetPortDirection(uint8 Copy_u8Port, uint8 Copy_u8Mode){
	
	switch(Copy_u8Port){ 
	
		case PORT_A:	DDRA = Copy_u8Mode;		break;
		case PORT_B:	DDRB = Copy_u8Mode;		break;
		case PORT_C:	DDRC = Copy_u8Mode;		break;
		case PORT_D:	DDRD = Copy_u8Mode;		break;
		
	}
	
}


void DIO_voidSetPortValue(uint8 Copy_u8Port, uint8 Copy_u8Value){

	switch(Copy_u8Port){ 
	
		case PORT_A:	PORTA = Copy_u8Value;		break;
		case PORT_B:	PORTB = Copy_u8Value;		break;
		case PORT_C:	PORTC = Copy_u8Value;		break;
		case PORT_D:	PORTD = Copy_u8Value;		break;
			
	}
	
}


void DIO_voidTogglePin(uint8 Copy_u8Port, uint8 Copy_u8Pin){

	switch(Copy_u8Port){ 
	
		case PORT_A:  TOG_BIT(PORTA, Copy_u8Pin);    break;
		case PORT_B:  TOG_BIT(PORTB, Copy_u8Pin);    break;
		case PORT_C:  TOG_BIT(PORTC, Copy_u8Pin);    break;
		case PORT_D:  TOG_BIT(PORTD, Copy_u8Pin);    break;
		
	}

}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/
