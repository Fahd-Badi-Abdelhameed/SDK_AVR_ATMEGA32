/*****************************************************************************/
/* Title        	: 	SPI Driver									         */
/* File Name    	: 	SPI_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	05/01/2021                                           */
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
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
	

/******************************************************************************
* !comment  :  Pointer to function for callback.  							  *
******************************************************************************/

static void (*SPI_CallBack)(void) = NULL;



/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/

	
/******************************************************************************
* Description 	: SPI Master Initializing Function .				          *
******************************************************************************/

void SPI_voidInitMaster(void){

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



/******************************************************************************
* Description 	: SPI Slave Initializing Function .				              *
******************************************************************************/

void SPI_voidInitSlave(void){

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

	uint8 Local_u8Dummy = 0x00;
	/* Load data in data register */
	SPDR = Local_u8Dummy;
	
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

uint8 SPI_u8ExchangeData(uint8 Copy_u8Data){ 

	/* Load data in data register */
	SPDR = Copy_u8Data;
	
	/* Wait till receive is complete */
	while(0 == (GET_BIT(SPSR, SPIF)));

	/* Clear SPI interrupt flag */
	SET_BIT(SPSR, SPIF);

	/* Return data */
	return SPDR;

}



/******************************************************************************
* Description 	: SPI Send String Blocking Function .				          *
******************************************************************************/

void SPI_voidSendStringBlocking(uint8 *Copy_u8Data){

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



/******************************************************************************
* Description 	: SPI Interrupt Enable Function.				          	  *
******************************************************************************/

void SPI_voidEnableInterrupt(void){

	SET_BIT(SPCR, SPIE);

}



/******************************************************************************
* Description 	: SPI Interrupt Disable Function.				          	  *
******************************************************************************/

void SPI_voidDisableInterrupt(void){

	CLR_BIT(SPCR, SPIE);

}



/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function SPI) -                          *
*		          [ Layer Architecture Problem Solved ].                      *
******************************************************************************/

void SPI_voidSetCallBack(void(*Local_ptr)(void)){

	SPI_CallBack = Local_ptr;

}


/******************************************************************************
* !comment  :  ISR Function SPI.  							 			      *   
******************************************************************************/

ISR( SPI_STC ){

	if(SPI_CallBack != NULL){

		SPI_CallBack();
	}

	else{ /* Return error */ }
}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/  