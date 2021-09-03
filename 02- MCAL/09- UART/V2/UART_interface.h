/*****************************************************************************/
/* Title        	: 	UART Driver									         */
/* File Name    	: 	UART_interface.h   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	2.0.0                                                */
/* Origin Date  	: 	05/04/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H


/******************************************************************************
************************************ Typedef ********************************** 
******************************************************************************/

typedef enum{

	USART_SingleProcessor,
	USART_MultiProcessor,

}USART_CommunicationTerminal;


typedef enum{

	USART_Async_NormalSpeed,
	USART_Async_DoubleSpeed,
	USART_Sync,

}USART_CommunicationMode;


typedef enum{

	USART_Disable,
	USART_TX_Only,
	USART_RX_Only,
	USART_TX_RX,
	
}USART_Enable;


typedef enum{

	USART_InterruptDisable,
	USART_RxCompEnable,
	USART_TxCompEnable,
	USART_UDREmptyEnable,
	USART_RxCompTxCompEnable,
	USART_RxCompUDREmptyEnable,
	USART_TxCompUDREmptyEnable,
	USART_RxCompTxCompUDREmptyEnable,

}USART_Interrupt;


typedef enum{

	USART_5BitData,
	USART_6BitData,
	USART_7BitData,
	USART_8BitData,
	USART_9BitData,
	
}USART_DataFrame;


typedef enum{

	USART_ParityDisable_1BitStop,
	USART_ParityDisable_2BitStop,
	USART_ParityEven_1BitStop,
	USART_ParityEven_2BitStop,
	USART_ParityOdd_1BitStop,
	USART_ParityOdd_2BitStop,

}USART_ControlFrame;


typedef enum{

	USART_SampleOnFalling,
	USART_SampleOnRising,

}USART_ClockPolarity;


typedef enum{

	USART_NoError,
	USART_ParityError,
	USART_OverRunError,
	USART_FrameError,

}USART_ErrorType;


typedef struct{

	/* Please Refere to Upper Enum For Details on What to Select */	
	USART_Enable	              EnableMode;
	USART_CommunicationMode		  CommunicationMode;
	USART_CommunicationTerminal   CommunicationTerminal;
	USART_Interrupt				  InterruptSource;
	USART_DataFrame               DataFrame;
	USART_ControlFrame            ControlFrame;
	/* Assign the Option Only When Working in Sync Mode */
	USART_ClockPolarity           ClockPolarity;
	uint32                        BaudRate;
	/* Read this Flag Before Using Data Returned by Read Function, Clear Flag Your Self */
	USART_ErrorType               ReadMasError;
	/* Call Back Members */
	/* Make the Pointer Points to a Function you Wish to by Called by RXC Interrupt */
	void (*RXC_InterruptCall)(void);
	/* Make the Pointer Points to a Function you Wish to by Called by TXC Interrupt */	
	void (*TXC_InterruptCall)(void);
		/* Make the Pointer Points to a Function you Wish to by Called by UDRE Interrupt */
	void (*UDRE_InterruptCall)(void);
	
}USART_SConfiguration;

extern USART_SConfiguration UART0;


/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/

void USART_voidInit(void);
void USART_voidSensByteBlocking(uint16 Copy_u16Data);
void USART_voidSensByteNonBlocking(uint16 Copy_u16Data);
void USART_voidSensStringBlocking(uint8 *Copy_u8Data);
uint16 USART_u16ReadByteBlocking(void);
uint16 USART_u16ReadByteNonBlocking(void);


#endif 
/*** !comment : End of guard [UART_INTERFACE_H] ******************************/
