/*****************************************************************************/
/* Title        	: 	UART Driver					         				 */
/* File Name    	: 	UART_private.h      	                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	2.0.0                                                */
/* Origin Date  	: 	05/04/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H


/******************************************************************************
* !comment : UART Registers Addresses Definition.  			         	      *
******************************************************************************/

#define UDR       *((volatile uint8 *) 0x2C)
#define UCSRA     *((volatile uint8 *) 0x2B)
#define UCSRB     *((volatile uint8 *) 0x2A)
#define UBRRL     *((volatile uint8 *) 0x29)
#define UCSRC     *((volatile uint8 *) 0x40)
#define UBRRH     *((volatile uint8 *) 0x40)


/******************************************************************************
* !comment : Control and Status Register-A (UCSRA) PINS Definition.           *
******************************************************************************/

#define MPCM     0
#define U2X      1
#define PE       2
#define DOR      3
#define FE       4
#define UDRE     5
#define TXC      6
#define RXC      7


/******************************************************************************
* !comment : Control and Status Register-B (UCSRB) PINS Definition.       	  *
******************************************************************************/

#define TXB8     0
#define RXB8     1
#define UCSZ2    2
#define TXEN     3
#define RXEN     4
#define UDRIE    5
#define TXCIE    6
#define RXCIE    7


/******************************************************************************
* !comment : Control and Status Register-C (UCSRC) PINS Definition.       	  *
******************************************************************************/

#define UCPOL    0
#define UCSZ0    1
#define UCSZ1    2
#define USBS     3
#define UPM0     4
#define UPM1     5
#define UMSEL    6
#define URSEL    7


/******************************************************************************
* !comment : Baud Rate Registers (UBRRL) and (UBRRH) PINS Definition.         *
******************************************************************************/

#define URSEL2   15


/******************************************************************************
* !comment : UART ISR attribute function.  			             	          *
******************************************************************************/

#define ISR(vector, ...)\
void vector (void) __attribute__((signal));\
void vector (void)

/******************************************************************************
* !comment : UART Interrupt Vectors Definition.  			                  *
******************************************************************************/

#define USART_RXC      __vector_13
#define USART_UDRE     __vector_14
#define USART_TXC      __vector_15



#endif 
/*** !comment : End of guard [UART_PRIVATE_H] ********************************/
