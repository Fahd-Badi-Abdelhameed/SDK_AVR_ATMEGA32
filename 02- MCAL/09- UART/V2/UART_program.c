/*****************************************************************************/
/* Title        	: 	UART Driver									         */
/* File Name    	: 	UART_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	2.0.0                                                */
/* Origin Date  	: 	05/04/2021                                           */
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
******************************** Global Variables ***************************** 
******************************************************************************/

USART_SConfiguration UART0 = 
{
	0,
    .RXC_InterruptCall = NULL,
	.TXC_InterruptCall = NULL,
	.UDRE_InterruptCall= NULL
	
};


/******************************************************************************
***************************** Function Implementation *************************
******************************************************************************/

ISR(USART_RXC){

	if(UART0.RXC_InterruptCall != NULL){
	
		UART0.RXC_InterruptCall();
	}
	else{
		/* Handle Error Using Error Handling Function */
	}
}


ISR(USART_TXC){

	if(UART0.TXC_InterruptCall != NULL){
	
		UART0.TXC_InterruptCall();
	}
	else{
		/* Handle Error Using Error Handling Function */
	}
}


ISR(USART_UDRE){

	if(UART0.UDRE_InterruptCall != NULL){
	
		UART0.UDRE_InterruptCall();
	}
	else{
		/* Handle Error Using Error Handling Function */
	}
}


void USART_voidInit(void){

	uint8 Local_u8HelpUCSRA   = 0;
	uint8 Local_u8HelpUCSRB   = 0;
	uint8 Local_u8HelpUCSRC   = 0;
	float32 Local_f32HelpUBRR = 0;
	
	switch(UART0.EnableMode){
		
		case USART_Disable:                                       			break;
		case USART_TX_Only:    Local_u8HelpUCSRB |= (1<<TXEN);    			break;
		case USART_RX_Only:    Local_u8HelpUCSRB |= (1<<RXEN);    			break;
		case USART_TX_RX  :    Local_u8HelpUCSRB |= (1<<RXEN)|(1<<TXEN);    break;
		default:                                                            break;
	}   
	
	switch(UART0.CommunicationMode){
		
		case USART_Async_NormalSpeed:
			Local_f32HelpUBRR = (((float32)F_CPU)/(16.0 * UART0.BaudRate))-0.5;
		break;
		
		case USART_Async_DoubleSpeed:
			Local_u8HelpUCSRA |= (1<<U2X);
			Local_f32HelpUBRR = (((float32)F_CPU)/(8.0 * UART0.BaudRate))-0.5;
		break;
		
		case USART_Sync:
			Local_u8HelpUCSRC |= (1<<UMSEL);
			Local_f32HelpUBRR = (((float32)F_CPU)/(2.0 * UART0.BaudRate))-0.5;
			
			switch(UART0.ClockPolarity){
			
				case USART_SampleOnFalling:                                      break;
				case USART_SampleOnRising :    Local_u8HelpUCSRC |= (1<<UCPOL);  break;
				default:                                                         break;
			}	
		break;
		default:  
		break;
		
	}
	    
	switch(UART0.CommunicationTerminal){
	
		case USART_SingleProcessor:                                      break;
		case USART_MultiProcessor :    Local_u8HelpUCSRA |= (1<<MPCM);   break;
		default:                                                         break;
	
	}	
	
	switch(UART0.InterruptSource){
		
		case USART_InterruptDisable:
		break;
		case USART_RxCompEnable:
			Local_u8HelpUCSRB |= (1<<RXCIE);
		break;
		case USART_TxCompEnable:
			Local_u8HelpUCSRB |= (1<<TXCIE);
		break;
		case USART_UDREmptyEnable:
			Local_u8HelpUCSRB |= (1<<UDRE);
		break;
		case USART_RxCompTxCompEnable:
			Local_u8HelpUCSRB |= (1<<TXCIE)|(1<<RXCIE);
		break;
		case USART_RxCompUDREmptyEnable:
			Local_u8HelpUCSRB |= (1<<UDRE)|(1<<RXCIE);
		break;
		case USART_TxCompUDREmptyEnable:
			Local_u8HelpUCSRB |= (1<<UDRE)|(1<<TXCIE);
		break;
		case USART_RxCompTxCompUDREmptyEnable:
			Local_u8HelpUCSRB |= (1<<UDRE)|(1<<TXCIE)|(1<<RXCIE);
		break;
		default:  
		break;
		
	}
	
	switch(UART0.DataFrame){
	
		case USART_5BitData:
		break;
		case USART_6BitData:
			Local_u8HelpUCSRC |= (1<<UCSZ0);
		break;
		case USART_7BitData:
			Local_u8HelpUCSRC |= (1<<UCSZ1);
		break;
		case USART_8BitData:
			Local_u8HelpUCSRC |= (1<<UCSZ0)|(1<<UCSZ1);
		break;
		case USART_9BitData:
			Local_u8HelpUCSRC |= (1<<UCSZ0)|(1<<UCSZ1);
			Local_u8HelpUCSRB |= (1<<UCSZ2);
		break;
		default:  
		break;
	
	}
	
	switch(UART0.ControlFrame){
	
		case USART_ParityDisable_1BitStop:
		break;
		case USART_ParityDisable_2BitStop:
			Local_u8HelpUCSRC |= (1<<USBS);
		break;
		case USART_ParityEven_1BitStop:
			Local_u8HelpUCSRC |= (1<<UPM1);
		break;
		case USART_ParityEven_2BitStop:
			Local_u8HelpUCSRC |= (1<<USBS)|(1<<UPM1);
		break;
		case USART_ParityOdd_1BitStop:
			Local_u8HelpUCSRC |= (1<<UPM0)|(1<<UPM1);
		break;
		case USART_ParityOdd_2BitStop:
			Local_u8HelpUCSRC |= (1<<USBS)|(1<<UPM0)|(1<<UPM1);
		break;
		default:  
		break;
	
	}
	
	
	UBRRH = ((uint16)Local_f32HelpUBRR) >> 8;
	UBRRL = ((uint8 )Local_f32HelpUBRR);
	UCSRA = Local_u8HelpUCSRA;
	UCSRC = Local_u8HelpUCSRC;
	UCSRB = Local_u8HelpUCSRB;
}



void USART_voidSensByteBlocking(uint16 Copy_u8Data){

	/* Polls UDRE Flag to Check if TX Register UDR Can be Written */
	while((UCSRA & (1<<UDRE))==0){ /* Do Nothing */ }
	
	if(UART0.DataFrame == USART_9BitData){
			
		UCSRB = (UCSRB & 0xFE)|((Copy_u8Data & (1<<8)) >> 8);
	}
	/* Assigne Data to UDR Register to be Sent using UART */
	UDR = (uint8)Copy_u8Data;
	
}


void USART_voidSensByteNonBlocking(uint16 Copy_u8Data){

	/* Polls UDRE Flag to Check if TX Register UDR Can be Written */
	if((UCSRA & (1<<UDRE))!= 0){ 
	
		if(UART0.DataFrame == USART_9BitData){
		
			UCSRB = (UCSRB & 0xFE)|((Copy_u8Data & (1<<8)) >> 8);
		}
		/* Assigne Data to UDR Register to be Sent using UART */
		UDR = (uint8)Copy_u8Data;
	}	
}



	
uint16 USART_u16ReadByteBlocking(void){
	
	uint16 Local_u16Data = 0;
	
	/* Polls RXC Flag to Check if RX Register UDR Can be Read for New Incoming Data */
	while((UCSRA & (1<<RXC))==0){ /* Do Nothing */ }
	
	if(UCSRA & ((1<<FE)|(1<<DOR)|(1<<PE))){
	
		/* Error: You Should Handle it as you Wish */
		if(UCSRA & (1<<FE)){
			
			UART0.ReadMasError = USART_FrameError;
		}
		else if(UCSRA & (1<<DOR)){
		
			UART0.ReadMasError = USART_OverRunError;
		}
		else{
		
			UART0.ReadMasError = USART_ParityError;
		}
	}
	
	if(UART0.DataFrame == USART_9BitData){
	
		Local_u16Data = (UCSRB & (1<<RXB8)) << 7;
	}
	
	Local_u16Data |= UDR;
	
	return Local_u16Data;
	
}



uint16 USART_u16ReadByteNonBlocking(void){
	
	uint16 Local_u16Data = 0;
	
	/* Polls RXC Flag to Check if RX Register UDR Can be Read for New Incoming Data */
	if((UCSRA & (1<<RXC)) != 0){ 
	
		if(UCSRA & ((1<<FE)|(1<<DOR)|(1<<PE))){
	
			/* Error: You Should Handle it as you Wish */
			if(UCSRA & (1<<FE)){
			
				UART0.ReadMasError = USART_FrameError;
			}
			else if(UCSRA & (1<<DOR)){
		
				UART0.ReadMasError = USART_OverRunError;
			}
			else{
		
				UART0.ReadMasError = USART_ParityError;
			}
		}
	
		if(UART0.DataFrame == USART_9BitData){
	
			Local_u16Data = (UCSRB & (1<<RXB8)) << 7;
		}
	
		Local_u16Data |= UDR;
	}	
	
	return Local_u16Data;
}



void USART_voidSensStringBlocking(uint8 *Copy_u8Data){

	while(*Copy_u8Data != NULL){
		
		USART_voidSensByteBlocking(*Copy_u8Data);
		*Copy_u8Data++;
	}
	
}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/  
