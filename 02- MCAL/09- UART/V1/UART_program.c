/*****************************************************************************/
/* Title        	: 	UART Driver									         */
/* File Name    	: 	UART_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	04/12/2020                                           */
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

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"
	
/******************************************************************************
* !comment  :  Pointer to function for callback.  							  *
******************************************************************************/

static void (*UART_TX_CallBack)(void) = NULL;	
static void (*UART_RX_CallBack)(void) = NULL;
	
	
/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/

/******************************************************************************
* Description 	: UART initialization Function.				                  *
******************************************************************************/

void UART_voidInit(void){

	uint8 Local_u8Help = 0;

	/* Set baud rate value */
	UBRRL = BAUD_RATE_VALUE;
	UBRRH =  0;
	
	/* enable RX */
	SET_BIT(UCSRB, RXEN);

	/* enable TX */
	SET_BIT(UCSRB, TXEN);

	/* Select UCSRC register */
	SET_BIT(Local_u8Help, URSEL);

	#if UART_MODE == ASYNCHRONOUS

		/* Asynchronous Mode */
		CLR_BIT(Local_u8Help, UMSEL);

	#elif UART_MODE == SYNCHRONOUS

		/* Synchronous Mode */
		SET_BIT(Local_u8Help, UMSEL);

	#else
		#error("You Chosed Wrong UART Mode!")
	#endif


	#if PARITY_MODE == DISABLE

		/* Disabl Parity Mode */
		CLR_BIT(Local_u8Help, UPM0);
		CLR_BIT(Local_u8Help, UPM1);

	#elif PARITY_MODE == EVEN_PARITY

		/* Parity Mode Even */
		CLR_BIT(Local_u8Help, UPM0);
		SET_BIT(Local_u8Help, UPM1);

	#elif PARITY_MODE == ODD_PARITY

		/* Parity Mode Odd */
		SET_BIT(Local_u8Help, UPM0);
		SET_BIT(Local_u8Help, UPM1);

	#else
		#error("You Chosed Wrong UART Parity Mode!")
	#endif


	#if STOP_BIT == ONE_BIT

		/* 1-bit stop */
		CLR_BIT(Local_u8Help, USBS);

	#elif STOP_BIT == TWO_BIT

		/* 2-bit stop */
		SET_BIT(Local_u8Help, USBS);

	#else
		#error("You Chosed Wrong UART Stop Bit Option!")
	#endif
	

	#if	DATA_SIZE == FIVE_BIT

		/* Data size 5-bit */
		CLR_BIT(Local_u8Help, UCSZ0);
		CLR_BIT(Local_u8Help, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);

	#elif	DATA_SIZE == SIX_BIT

		/* Data size 6-bit */
		SET_BIT(Local_u8Help, UCSZ0);
		CLR_BIT(Local_u8Help, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);

	#elif	DATA_SIZE == SEVEN_BIT

		/* Data size 7-bit */
		CLR_BIT(Local_u8Help, UCSZ0);
		SET_BIT(Local_u8Help, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);

	#elif	DATA_SIZE == EIGHT_BIT

		/* Data size 8-bit */
		SET_BIT(Local_u8Help, UCSZ0);
		SET_BIT(Local_u8Help, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);

	#elif	DATA_SIZE == NINE_BIT

		/* Data size 9-bit */
		SET_BIT(Local_u8Help, UCSZ0);
		SET_BIT(Local_u8Help, UCSZ1);
		SET_BIT(UCSRB, UCSZ2);

	#else
		#error("You Chosed Wrong UART data size option!")
	#endif

	UCSRC = Local_u8Help;
	
}



/******************************************************************************
* Description 	: UART Send Char Blocking Function.		                      *
******************************************************************************/

void UART_voidSendByte(uint8 Copy_u8Data){

	/* wait till UDR is Empty */
	while(0 == GET_BIT(UCSRA, UDRE));

	/* Load data in data register */
	UDR = Copy_u8Data;

}


/******************************************************************************
* Description 	: UART Receive Byte Blocking Function.		                  *
******************************************************************************/
	
uint8 UART_u8ReceiveByte(void){

	while (GET_BIT(UCSRA, RXC) == 0);

	return UDR;
}



/******************************************************************************
* Description 	: UART Send String Blocking Function.                         *
******************************************************************************/

void UART_voidSendStringBlocking(uint8 *Copy_u8Data){

	while(*Copy_u8Data != NULL){

		UART_voidSendByte(*Copy_u8Data);
		*Copy_u8Data++;
	}

}


/******************************************************************************
* Description 	: UART Write Decimal Number Blocking Function.                *
******************************************************************************/


void UART_voidWriteDecimalNumber(uint32 Copy_u32Number){

	uint32 Local_u8Reversed = 1;

	if(0 == Copy_u32Number){

		UART_voidSendByte('0');
	}
	while(0 != Copy_u32Number){

		Local_u8Reversed = ((Local_u8Reversed * 10) + (Copy_u32Number % 10));
		Copy_u32Number /= 10;
	}
	while(1 != Local_u8Reversed){

		UART_voidSendByte((Local_u8Reversed % 10 ) + 48);
		Local_u8Reversed /= 10;
	}

}


/******************************************************************************
* Description 	: UART Write Hexadecimal Number Blocking Function.            *
******************************************************************************/


void UART_voidWriteHexadecimalNumber(uint32 Copy_u32DecimalNumber){

	uint32 quotient;
	uint8 i=1, j, temp;

	uint8 HexadecimalNumber[100];

	quotient = Copy_u32DecimalNumber;

	if(quotient == 0){  UART_voidSendByte('0');  }

	else{

		while(quotient != 0){

			temp = quotient % 16;

			if(temp < 10){  temp = temp + 48;  }
			else{  temp = temp + 55;  }

			HexadecimalNumber[i++] = temp;

			quotient = quotient / 16;

		}

		for(j=i-1; j>0; j--){

			UART_voidSendByte(HexadecimalNumber[j]);
		}
	}

}


/******************************************************************************
* Description 	: UART Send Byte Function, Used using interrupt.              *
******************************************************************************/

void UART_voidSendByteNoBlock(uint8 Copy_u8Data){

	UDR = Copy_u8Data;
}


/******************************************************************************
* Description 	: UART Receive Byte Function, Used using interrupt.           *
******************************************************************************/

uint8 UART_u8ReceiveByteNoBlock(void){

	return UDR;
}


/******************************************************************************
* Description 	: UART RX Interrupt Enable Function.			              *
******************************************************************************/

void UART_voidEnableInterrupt_RX(void){

	SET_BIT(UCSRB, RXCIE);
}


/******************************************************************************
* Description 	: UART RX Interrupt Disable Function.			              *
******************************************************************************/

void UART_voidDisableInterrupt_RX(void){

	CLR_BIT(UCSRB, RXCIE);
}


/******************************************************************************
* Description 	: UART TX Interrupt Enable Function.			              *
******************************************************************************/

void UART_voidEnableInterrupt_TX(void){

	SET_BIT(UCSRB, TXCIE);
}


/******************************************************************************
* Description 	: UART TX Interrupt Disable Function.			              *
******************************************************************************/

void UART_voidDisableInterrupt_TX(void){

	CLR_BIT(UCSRB, TXCIE);
}


/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function UART TX) -                      *
*		          [ Layer Architecture Problem Solved ].                      *
******************************************************************************/

void UART_voidSetCallBack_TX(void(*Local_ptr)(void)){

	UART_TX_CallBack = Local_ptr;

}


/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function UART RX) -                      *
*		          [ Layer Architecture Problem Solved ].                      *
******************************************************************************/

void UART_voidSetCallBack_RX(void(*Local_ptr)(void)){

	UART_RX_CallBack = Local_ptr;

}


/******************************************************************************
* !comment  :  ISR Function UART TX interrupt.  						      *
******************************************************************************/

ISR( USART_TX ){

	if(UART_TX_CallBack != NULL){

		UART_TX_CallBack();
	}

	else{/* Return error */}
}


/******************************************************************************
* !comment  :  ISR Function UART RX interrupt.  						      *
******************************************************************************/

ISR( USART_RX ){

	if(UART_RX_CallBack != NULL){

		UART_RX_CallBack();
	}

	else{/* Return error */}
}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/



