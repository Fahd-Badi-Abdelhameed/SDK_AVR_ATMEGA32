/*****************************************************************************/
/* Title        	: 	UART Driver					         				 */
/* File Name    	: 	UART_private.h      	                         	 */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	04/12/2020                                           */
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

#define MPCM     (uint8)0
#define U2X      (uint8)1
#define PE       (uint8)2
#define DOR      (uint8)3
#define FE       (uint8)4
#define UDRE     (uint8)5
#define TXC      (uint8)6
#define RXC      (uint8)7

/******************************************************************************
* !comment : Control and Status Register-B (UCSRB) PINS Definition.       	  *
******************************************************************************/

#define TXB8     (uint8)0
#define RXB8     (uint8)1
#define UCSZ2    (uint8)2
#define TXEN     (uint8)3
#define RXEN     (uint8)4
#define UDRIE    (uint8)5
#define TXCIE    (uint8)6
#define RXCIE    (uint8)7

/******************************************************************************
* !comment : Control and Status Register-C (UCSRC) PINS Definition.       	  *
******************************************************************************/

#define UCPOL    (uint8)0
#define UCSZ0    (uint8)1
#define UCSZ1    (uint8)2
#define USBS     (uint8)3
#define UPM0     (uint8)4
#define UPM1     (uint8)5
#define UMSEL    (uint8)6
#define URSEL    (uint8)7

/******************************************************************************
* !comment : Baud Rate Registers (UBRRL) and (UBRRH) PINS Definition.         *
******************************************************************************/

#define URSEL2   (uint8)15

/******************************************************************************
* !comment : UART Mode Option Definition.       	                          *
******************************************************************************/

#define ASYNCHRONOUS	0
#define SYNCHRONOUS		1

/******************************************************************************
* !comment : Parity Mode Option Definition.       	                          *
******************************************************************************/

#define DISABLE         0
#define EVEN_PARITY     1
#define ODD_PARITY      2

/******************************************************************************
* !comment : Stop Bit Option Definition.       	                              *
******************************************************************************/

#define ONE_BIT  	    0
#define TWO_BIT         1

/******************************************************************************
* !comment : Data Size Option Definition.       	                          *
******************************************************************************/

#define FIVE_BIT        5
#define SIX_BIT         6
#define SEVEN_BIT       7
#define EIGHT_BIT       8
#define NINE_BIT        9

/******************************************************************************
* !comment : UART ISR function prototype.  			             	          *
******************************************************************************/

#define ISR(vector, ...)\
void vector (void) __attribute__((signal));\
void vector (void)

/******************************************************************************
* !comment : UART Interrupt Vectors Definition.  			                  *
******************************************************************************/

#define USART_TX     __vector_15
#define USART_RX     __vector_13


#endif 
/*** !comment : End of gaurd [UART_PRIVATE_H] ********************************/
