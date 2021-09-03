/*********************************************************************************/
/* Title        	: 	SPI Driver									             */
/* File Name    	: 	SPI_program.c   		                                 */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	05/01/2021                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
	

static void (*SPI_CallBack)(void) = NULL;

	
/******************* SPI master initializing function  *******************/

void  SPI_voidInitMaster(void){

	/*

	SPCR = 0x53;
	SPSR = 0x00;

	*/

	uint8 Local_u8Help = 0;

	/* SPI Enable */
	SET_BIT(Local_u8Help, SPE);

	/* SPI Master */
	SET_BIT(Local_u8Help, MSTR);

	/* SPI Data Order */
	#if DARA_ORDER == MSB

		/* The MSB of the data word is transmitted first */
		CLR_BIT(Local_u8Help, DORD);

	#elif DARA_ORDER == LSB

		/* The LSB of the data word is transmitted first */
		SET_BIT(Local_u8Help, DORD);

	#else
		#error("You Chose Wrong SPI Data Order Option!")
	#endif
	

	/* SPI Clock Polarity */
	#if CLOCK_POLARITY == Rising_Falling

		 /* Rising - Falling ---> Leading Edge - Trailing Edge */
		CLR_BIT(Local_u8Help, CPOL);

	#elif CLOCK_POLARITY == Falling_Rising

		/* Falling - Rising ---> Leading Edge - Trailing Edge */
		SET_BIT(Local_u8Help, CPOL);

	#else
		#error("You Chose Wrong SPI Clock Polarity Option!")
	#endif
	

	/* SPI Clock Phase  */
	#if CLOCK_PHASE == Sample_Setup

		/* Sample - Setup ---> Leading Edge - Trailing Edge */
		CLR_BIT(Local_u8Help, CPHA);

	#elif CLOCK_PHASE == Setup_Sample

		/* Setup - Sample ---> Leading Edge - Trailing Edge */
		SET_BIT(Local_u8Help, CPHA);

	#else
		#error("You Chose Wrong SPI Clock Phase Option!")
	#endif
	

	/* SPI Clock Rate  */
	#if CLOCK_RATE == NORMAL_SPEED_DIV_4

		/* Clock Rate --> Normal speed f/4 */
		CLR_BIT(Local_u8Help, SPR0);
		CLR_BIT(Local_u8Help, SPR1);
		CLR_BIT(SPSR, SPI2X);

	#elif CLOCK_RATE == NORMAL_SPEED_DIV_16

		/* Clock Rate --> Normal speed f/16 */
		SET_BIT(Local_u8Help, SPR0);
		CLR_BIT(Local_u8Help, SPR1);
		CLR_BIT(SPSR, SPI2X);

	#elif CLOCK_RATE == NORMAL_SPEED_DIV_64

		/* Clock Rate --> Normal speed f/64 */
		CLR_BIT(Local_u8Help, SPR0);
		SET_BIT(Local_u8Help, SPR1);
		CLR_BIT(SPSR, SPI2X);

	#elif CLOCK_RATE == NORMAL_SPEED_DIV_128

		/* Clock Rate --> Normal speed f/128 */
		SET_BIT(Local_u8Help, SPR0);
		SET_BIT(Local_u8Help, SPR1);
		CLR_BIT(SPSR, SPI2X);

	#elif CLOCK_RATE == DOUBLE_SPEED_DIV_2

		/* Clock Rate --> Double speed f/2 */
		CLR_BIT(Local_u8Help, SPR0);
		CLR_BIT(Local_u8Help, SPR1);
		SET_BIT(SPSR, SPI2X);

	#elif CLOCK_RATE == DOUBLE_SPEED_DIV_8

		/* Clock Rate --> Double speed f/8 */
		SET_BIT(Local_u8Help, SPR0);
		CLR_BIT(Local_u8Help, SPR1);
		SET_BIT(SPSR, SPI2X);

	#elif CLOCK_RATE == DOUBLE_SPEED_DIV_32

		/* Clock Rate --> Double speed f/32 */
		CLR_BIT(Local_u8Help, SPR0);
		SET_BIT(Local_u8Help, SPR1);
		SET_BIT(SPSR, SPI2X);

	#elif CLOCK_RATE == DOUBLE_SPEED_DIV_64

		/* Clock Rate --> Double speed f/64 */
		SET_BIT(Local_u8Help, SPR0);
		SET_BIT(Local_u8Help, SPR1);
		SET_BIT(SPSR, SPI2X);

	#else
		#error("You Chose Wrong SPI Clock Rate Option!")
	#endif


	/* Load direct  */
	SPCR = Local_u8Help;

}



/******************* SPI slave initializing function  *******************/

void  SPI_voidInitSlave(void){

	uint8 Local_u8Help = 0;

	/* SPI Enable */
	SET_BIT(Local_u8Help, SPE);

	/* SPI Slave */
	CLR_BIT(Local_u8Help, MSTR);

	/* SPI Data Order */
	#if DARA_ORDER == MSB

		/* The MSB of the data word is transmitted first */
		CLR_BIT(Local_u8Help, DORD);

	#elif DARA_ORDER == LSB

		/* The LSB of the data word is transmitted first */
		SET_BIT(Local_u8Help, DORD);

	#else
		#error("You Chose Wrong SPI Data Order Option!")
	#endif


	/* SPI Clock Polarity */
	#if CLOCK_POLARITY == Rising_Falling

		 /* Rising - Falling ---> Leading Edge - Trailing Edge */
		CLR_BIT(Local_u8Help, CPOL);

	#elif CLOCK_POLARITY == Falling_Rising

		/* Falling - Rising ---> Leading Edge - Trailing Edge */
		SET_BIT(Local_u8Help, CPOL);

	#else
		#error("You Chose Wrong SPI Clock Polarity Option!")
	#endif


	/* SPI Clock Phase  */
	#if CLOCK_PHASE == Sample_Setup

		/* Sample - Setup ---> Leading Edge - Trailing Edge */
		CLR_BIT(Local_u8Help, CPHA);

	#elif CLOCK_PHASE == Setup_Sample

		/* Setup - Sample ---> Leading Edge - Trailing Edge */
		SET_BIT(Local_u8Help, CPHA);

	#else
		#error("You Chose Wrong SPI Clock Phase Option!")
	#endif

	SPCR = Local_u8Help;

}



/******************* Polling send char function *******************/

void SPI_voidSendChar(uint8 Copy_u8Data){

	/* Load data in data register */
	SPDR = Copy_u8Data;

	/* Wait till transmit is complete */
	while(0 == (GET_BIT(SPSR, SPIF)));

	/* Clear SPI interrupt flag */
	SET_BIT(SPSR, SPIF);

}



/******************* Polling receive char function *******************/

uint8 SPI_u8ReceiveChar(void){

	/* Wait till receive is complete */
	while(0 == (GET_BIT(SPSR, SPIF)));

	/* Clear SPI interrupt flag */
	SET_BIT(SPSR, SPIF);

	/* Return data */
	return SPDR;

}



/******************* Polling transmit string function *******************/

void SPI_voidTransmitString(uint8 *Copy_u8Data){

	uint8 Local_u8Counter = 0;

	/* Verify that the data is not equal to Null */
	while('\0' != Copy_u8Data[Local_u8Counter]){

		/* Load data in data register */
		SPDR = Copy_u8Data[Local_u8Counter];

		/* Wait till transmit is complete */
		while(0 == (GET_BIT(SPSR, SPIF)));

		/* Clear SPI interrupt flag */
		SET_BIT(SPSR, SPIF);

		Local_u8Counter ++;
	}
}



/******************* Polling receive string function *******************/

uint8 SPI_u8ReceiveString(void){

	uint16 Local_u16TimeOut = 0;
	uint8 Local_u8ReceivedData = 0;

	/* Wait till receive is complete */
	while(0 == (GET_BIT(SPSR, SPIF))){

		Local_u16TimeOut ++;

		if(10000 == Local_u16TimeOut){

			Local_u8ReceivedData = 255;
			break;
		}
	}

	if(0 == Local_u8ReceivedData){

		Local_u8ReceivedData = SPDR;
	}


	/* Clear SPI interrupt flag */
	SET_BIT(SPSR, SPIF);

	/* Return data  */
	return Local_u8ReceivedData;

}


/************************* SPI callback function **********************/

void SPI_voidSetCallBack(void(*Local_ptr)(void)){

	SPI_CallBack = Local_ptr;

}



/******************* SPI enable interrupt function *******************/

void SPI_voidEnableInterrupt(void){

	SET_BIT(SPCR, SPIE);

}



/******************* SPI disable interrupt function *******************/

void SPI_voidDisableInterrupt(void){

	CLR_BIT(SPCR, SPIE);

}



/************************* SPI ISR Function *************************/

ISR( SPI_STC ){

	if(SPI_CallBack != NULL){

		SPI_CallBack();
	}

	else{ /* Return error */ }
}



/******************* SPI send receive synchronous function *******************/

uint8 SPI_u8SendReceiveSynch(uint8 Copy_u8DataTransmit){

	asm("NOP");

}



/******************* SPI send receive synchronous function *******************/

void SPI_voidSendReceiveSynch(uint8 Copy_u8DataTransmit, uint8 *Copy_u8DataReceive){

	asm("NOP");

}



/******************* SPI send receive asynchronous function *******************/

void SPI_voidSendReceiveASynch(uint8 Copy_u8DataTransmit, void(*CallBack)(uint8)){

	asm("NOP");

}


