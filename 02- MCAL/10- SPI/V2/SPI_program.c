/*****************************************************************************/
/* Title        	: 	SPI Driver									         */
/* File Name    	: 	SPI_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	2.0.0                                                */
/* Origin Date  	: 	08/05/2021                                           */
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
****************************** Component DIRECTIVES ***************************
******************************************************************************/
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
	
/******************************************************************************
******************************** Global Variables ***************************** 
******************************************************************************/

SPI_ConfigStruct SPI0 = {.SPI_CallBack = NULL };

/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/

/******************************************************************************
* !comment  :  ISR Function SPI.  							 			      *   
******************************************************************************/

ISR( SPI_STC_VECT ){

	if(SPI0.SPI_CallBack != NULL){

		SPI0.SPI_CallBack();
	}

	else{ /* Return error */ }
}

	
/******************************************************************************
* Description 	: SPI Initializing Function .				                  *
******************************************************************************/

void SPI_voidInit(void){

	SPCR = 0x00;
	SPSR = 0x00;

	switch(SPI0.EnableControl){
		
		case SPI_DISABLE:	break;	
		
		case SPI_ENABLE:

			switch(SPI0.Mode){
				
				case SPI_MASTER:   SET_BIT(SPCR, MSTR);              break;
				case SPI_SLAVE :                                     break;
		        default:                                             break;
			}
			switch(SPI0.DataOrder){

				case SPI_LSB:  SET_BIT(SPCR, DORD);                  break;
				case SPI_MSB:                                        break;
		        default:                                             break;
			}
			switch(SPI0.InterruptState){
				
				case SPI_INTERRUPT_ENABLE :	 SET_BIT(SPCR, SPIE);	 break;
				case SPI_INTERRUPT_DISABLE:                          break;
		        default:                                             break;
			}
			switch(SPI0.ClockMode){
				
				case SPI_CLK_MODE0:	   	                             break;
				case SPI_CLK_MODE1:    SET_BIT(SPCR, CPHA);          break;
				case SPI_CLK_MODE2:	   SET_BIT(SPCR, CPOL);	         break;
				case SPI_CLK_MODE3:    SET_BIT(SPCR, CPHA);
									   SET_BIT(SPCR, CPOL);          break;
		        default:                                             break;
			}
			switch(SPI0.Freq){
				
				case SPI_FCPU_BY_2  :	SET_BIT(SPSR, SPI2X);  		 break;
				case SPI_FCPU_BY_4  :                        		 break;
				case SPI_FCPU_BY_8  :	SET_BIT(SPCR, SPR0 );
				                        SET_BIT(SPSR, SPI2X);        break;
				case SPI_FCPU_BY_16 :   SET_BIT(SPCR, SPR0 );        break;
				case SPI_FCPU_BY_32 :   SET_BIT(SPCR, SPR1 );
										SET_BIT(SPSR, SPI2X);   	 break;
				case SPI_FCPU_BY_64 :	SET_BIT(SPCR, SPR1 ); 	     break;
				case SPI_FCPU_BY_128:   SET_BIT(SPCR, SPR1 );
									    SET_BIT(SPCR, SPR0 );        break;
		        default:                                             break;
			}
			
		/* Enable SPI */	
		SET_BIT(SPCR, SPE );             break;
		default:                         break;		
	}
	
}



/******************************************************************************
* Description 	: SPI Send Char Blocking Function .				              *
******************************************************************************/

void SPI_voidSendChar(uint8 Copy_u8Data){

	/* Load data in data register */
	SPDR = Copy_u8Data;

	/* Wait till transmit is complete */
	while(0 == (GET_BIT(SPSR, SPIF)));

	/* Clear SPI interrupt flag */
	SET_BIT(SPSR, SPIF);

}



/******************************************************************************
* Description 	: SPI Receive Char Blocking Function .				          *
******************************************************************************/

uint8 SPI_u8ReceiveChar(void){

	uint8 Local_u8DummyData = 0x00;
	/* Load data in data register */
	SPDR = Local_u8DummyData;
	
	/* Wait till receive is complete */
	while(0 == (GET_BIT(SPSR, SPIF)));

	/* Clear SPI interrupt flag */
	SET_BIT(SPSR, SPIF);

	/* Return data */
	return SPDR;

}


/******************************************************************************
* Description 	: SPI Exchange Data Blocking Function .				          *
******************************************************************************/

uint8 SPI_u8ExchangeDataBlocking(uint8 Copy_u8Data){
	
	/* Transmit Data Using SPI Bus */
	SPDR = Copy_u8Data;
	
	/* Check if a Write Collison Error Occurred */ 
	if(0 != GET_BIT(SPSR, WCOL)){
		
		SPI0.Error = SPI_WRITE_COLLISON;
	}
	
	/* Block till the End Transmition */
	while(0 == (GET_BIT(SPSR, SPIF)));

	/* Return Rx Data From SPIN */
	return SPDR;	
	
}


/******************************************************************************
* Description 	: SPI Exchange Data Non Blocking Function .				      *
******************************************************************************/

uint8 SPI_u8ExchangeDataNonBlocking(uint8 Copy_u8Data){

	/* Transmit Data Using SPI Bus */
	SPDR = Copy_u8Data;
	
	/* Check if a Write Collison Error Occurred */ 
	if((SPSR & (1<<WCOL)) != 0){
		
		SPI0.Error = SPI_WRITE_COLLISON;
	}

	/* Return Rx Data From SPIN */
	return SPDR;	
	
}


/******************************************************************************
* Description 	: SPI Chip Select Control Function .				          *
******************************************************************************/

void SPI_voidChipSelectControl(uint8 Copy_u8State){

	switch(Copy_u8State){
	
		case 0 :    DIO_voidSetPinValue(DIO_PINB4, DIO_LOW );    break;
		case 1 :    DIO_voidSetPinValue(DIO_PINB4, DIO_HIGH);    break;
		default:                                                break;		
		
	}
}



/******************************************************************************
* Description 	: SPI Exchange Send String Blocking Function .				  *
******************************************************************************/
void SPI_voidSendStringBlocking(uint8 *Copy_u8Data){

	while(*Copy_u8Data != NULL){

		SPI_u8ExchangeDataBlocking(*Copy_u8Data);
		*Copy_u8Data++;
	}

}

/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/  
