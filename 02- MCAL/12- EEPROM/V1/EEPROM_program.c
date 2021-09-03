/*****************************************************************************/
/* Title        	: 	EEPROM Driver									     */
/* File Name    	: 	EEPROM_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	10/05/2021                                           */
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
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"

/******************************************************************************
* !comment  :  Pointer to function for callback.  							  *
******************************************************************************/

static void (*EEPROM_CallBack)(void) = NULL;


/******************************************************************************
***************************** Function Implementation *************************
******************************************************************************/


uint8 EEPROM_u8ReadByte(uint16 Copy_u16Address){

	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	
	/* Set up address register */
	EEAR = Copy_u16Address;
	
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	
	/* Return data from data register */
	return EEDR;

}


void EEPROM_voidReadeBlock(uint16 Copy_u16Address, uint8 *Ptr_u8Return, uint16 Copy_u16Size){

	uint16 Local_u16ByteCounter = 0;
	
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	
	while(Local_u16ByteCounter < Copy_u16Size){
	
		/* Set up address register */
		EEAR = Copy_u16Address + Local_u16ByteCounter;
		
		/* Start eeprom read by writing EERE */
		EECR |= (1<<EERE);
		
		/* move data form data register to the array */
		*(Ptr_u8Return + Local_u16ByteCounter) = EEDR;
		
		/* increase the bytes counter */
		Local_u16ByteCounter++;
	
	}

}


void EEPROM_voidWriteByte(uint16 Copy_u16Address, uint8 Copy_u8Data){

	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	
	/* Set up address register */
	EEAR = Copy_u16Address;
	
	/* Read the byte in the address of EEAR */
	EECR |= (1<<EERE);
	
	/* Compare the value read to value to be written */
	if(EEDR != Copy_u8Data){
		
		/* if they are not equal then write the data */
		/* Set up data registers */
		EEDR = Copy_u8Data;
		
		/* Write logical one to EEMWE */
		EECR |= (1<<EEMWE);
		
		/* Start eeprom write by setting EEWE */
		EECR |= (1<<EEWE);
	}
	
	else{    /* return error */    }
	
}




void EEPROM_voidWriteBlock(uint16 Copy_u16Address, uint8 *Copy_u8Data, uint16 Copy_u16Size){
	
	uint16 Local_u16ByteCounter = 0;
	
	while(Local_u16ByteCounter < Copy_u16Size){
		
		/* Wait for completion of previous write */
		while(EECR & (1<<EEWE));
		
		/* Set up address register */
		EEAR = Copy_u16Address + Local_u16ByteCounter;
		
		/* Read the byte in the address of EEAR */
		EECR |= (1<<EERE);
		
		/* Compare the value read to value to be written */
		if(EEDR != (*(Copy_u8Data + Local_u16ByteCounter))){
		
			/* if they are not equal then write the data */
			/* Set up data registers */
			EEDR = *(Copy_u8Data + Local_u16ByteCounter);
			
			/* Write logical one to EEMWE */
			EECR |= (1<<EEMWE);
		
			/* Start eeprom write by setting EEWE */
			EECR |= (1<<EEWE);
			
		}
			
		else{    /* return error */    }
		
		/* increase the bytes counter */
		Local_u16ByteCounter++;
	}
	
}



void EEPROM_voidReadyInterruptEnable(void){

	SET_BIT(EECR, EERIE);
}



void EEPROM_voidReadyInterruptDisable(void){

	CLR_BIT(EECR, EERIE);
}



/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function EEPROM) -                       *
*		          [ Layer Architecture Problem Solved ].                      *
******************************************************************************/

void EEPROM_voidSetCallBack(void(*Local_ptr)(void)){

	EEPROM_CallBack = Local_ptr;

}


/******************************************************************************
* !comment  :  ISR Function EEPROM.  							 			  *   
******************************************************************************/

ISR(EEPROM_RDY_VECT){

	if(EEPROM_CallBack != NULL){

		EEPROM_CallBack();
	}

	else{ /* Return error */ }
}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/  