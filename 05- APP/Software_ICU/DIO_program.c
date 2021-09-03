/*****************************************************************************/
/* Title        	: 	DIO Driver								 			 */
/* File Name   		: 	DIO_program.c                                        */
/* Author       	: 	Fahd Badi                                            */
/* Version          : 	2.0.0                                                */
/* Origin Date  	: 	15/11/2020                                           */
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

void DIO_voidSetPinDirection(uint8 Copy_u8Pin, uint8 Copy_u8Mode){

	if(DIO_OUTPUT == Copy_u8Mode){
	
		if((Copy_u8Pin >= 0) && (Copy_u8Pin <= 7)){

			SET_BIT(DDRA, Copy_u8Pin);
		}

		else if((Copy_u8Pin >= 8) && (Copy_u8Pin <= 15)){

			SET_BIT(DDRB, (Copy_u8Pin-8));
		}

		else if((Copy_u8Pin >= 16) && (Copy_u8Pin <= 23)){

			SET_BIT(DDRC, (Copy_u8Pin-16));
		}
		
		else if((Copy_u8Pin >= 24) && (Copy_u8Pin <= 31)){

			SET_BIT(DDRD, (Copy_u8Pin-24));
		}

		else{    /* return error  */   }

	}
	
	else if(DIO_INPUT == Copy_u8Mode){
	
		if((Copy_u8Pin >= 0) && (Copy_u8Pin <= 7)){

			CLR_BIT(DDRA, Copy_u8Pin);
		}

		else if((Copy_u8Pin >= 8) && (Copy_u8Pin <= 15)){

			CLR_BIT(DDRB, (Copy_u8Pin-8));
		}

		else if((Copy_u8Pin >= 16) && (Copy_u8Pin <= 23)){

			CLR_BIT(DDRC, (Copy_u8Pin-16));
		}
		
		else if((Copy_u8Pin >= 24) && (Copy_u8Pin <= 31)){

			CLR_BIT(DDRD, (Copy_u8Pin-24));
		}

		else{    /* return error  */   }
	}
	
	else{    /* return error  */   }

}


void DIO_voidSetPinValue(uint8 Copy_u8Pin, uint8 Copy_u8Value){

	if(DIO_HIGH == Copy_u8Value){
	
		if((Copy_u8Pin >= 0) && (Copy_u8Pin <= 7)){

			SET_BIT(PORTA, Copy_u8Pin);
		}

		else if((Copy_u8Pin >= 8) && (Copy_u8Pin <= 15)){

			SET_BIT(PORTB, (Copy_u8Pin-8));
		}

		else if((Copy_u8Pin >= 16) && (Copy_u8Pin <= 23)){

			SET_BIT(PORTC, (Copy_u8Pin-16));
		}
		
		else if((Copy_u8Pin >= 24) && (Copy_u8Pin <= 31)){

			SET_BIT(PORTD, (Copy_u8Pin-24));
		}

		else{    /* return error  */   }
	}
	
	else if(DIO_LOW == Copy_u8Value){

		if((Copy_u8Pin >= 0) && (Copy_u8Pin <= 7)){

			CLR_BIT(PORTA, Copy_u8Pin);
		}

		else if((Copy_u8Pin >= 8) && (Copy_u8Pin <= 15)){

			CLR_BIT(PORTB, (Copy_u8Pin-8));
		}

		else if((Copy_u8Pin >= 16) && (Copy_u8Pin <= 23)){

			CLR_BIT(PORTC, (Copy_u8Pin-16));
		}
		
		else if((Copy_u8Pin >= 24) && (Copy_u8Pin <= 31)){

			CLR_BIT(PORTD, (Copy_u8Pin-24));
		}

		else{    /* return error  */   }

	}
	
	else{    /* return error  */   }

}


uint8 DIO_u8GetPinValue(uint8 Copy_u8Pin){

	uint8 Local_u8Result = 0; 

	if((Copy_u8Pin >= 0) && (Copy_u8Pin <= 7)){

		Local_u8Result = GET_BIT(PINA, Copy_u8Pin);
	}
	else if((Copy_u8Pin >= 8) && (Copy_u8Pin <= 15)){

		Local_u8Result = GET_BIT(PINB, Copy_u8Pin);
	}
	else if((Copy_u8Pin >= 16) && (Copy_u8Pin <= 23)){

		Local_u8Result = GET_BIT(PINC, Copy_u8Pin);
	}
	else if((Copy_u8Pin >= 24) && (Copy_u8Pin <= 31)){
		
		Local_u8Result = GET_BIT(PIND, Copy_u8Pin);
	}

	return Local_u8Result;
}


void DIO_voidSetPortDirection(uint8 Copy_u8Port, uint8 Copy_u8Mode){
	
	switch(Copy_u8Port){ 
	
		case DIO_PORTA:		DDRA = Copy_u8Mode;		break;
		case DIO_PORTB:		DDRB = Copy_u8Mode;		break;
		case DIO_PORTC:		DDRC = Copy_u8Mode;		break;
		case DIO_PORTD:		DDRD = Copy_u8Mode;		break;
		
	}
	
}


void DIO_voidSetPortValue(uint8 Copy_u8Port, uint8 Copy_u8Value){

	switch(Copy_u8Port){ 
	
		case DIO_PORTA:		PORTA = Copy_u8Value;		break;
		case DIO_PORTB:		PORTB = Copy_u8Value;		break;
		case DIO_PORTC:		PORTC = Copy_u8Value;		break;
		case DIO_PORTD:		PORTD = Copy_u8Value;		break;
			
	}
	
}


void DIO_voidTogglePin(uint8 Copy_u8Pin){

	if((Copy_u8Pin >= 0) && (Copy_u8Pin <= 7)){

		TOG_BIT(PORTA, Copy_u8Pin);
	}

	else if((Copy_u8Pin >= 8) && (Copy_u8Pin <= 15)){

		TOG_BIT(PORTB, (Copy_u8Pin-8));
	}

	else if((Copy_u8Pin >= 16) && (Copy_u8Pin <= 23)){

		TOG_BIT(PORTC, (Copy_u8Pin-16));
	}
	
	else if((Copy_u8Pin >= 24) && (Copy_u8Pin <= 31)){

		TOG_BIT(PORTD, (Copy_u8Pin-24));
	}

	else{    /* return error  */   }

}

uint8 DIO_u8GetPortValue(uint8 Copy_u8Port){

	uint8 Local_u8Result = 0x00;

	switch(Copy_u8Port){

		case DIO_PORTA:		Local_u8Result = PINA;		break;
		case DIO_PORTB:		Local_u8Result = PINB;		break;
		case DIO_PORTC:		Local_u8Result = PINC;		break;
		case DIO_PORTD:		Local_u8Result = PIND;		break;

	}

	return Local_u8Result;
}
/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/
