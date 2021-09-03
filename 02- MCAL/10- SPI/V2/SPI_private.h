/*****************************************************************************/
/* Title        	: 	SPI Driver					         				 */
/* File Name    	: 	SPI_private.h      	                         	     */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	2.0.0                                                */
/* Origin Date  	: 	08/05/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


/******************************************************************************
* !comment : SPI Registers Addresses Definition.  			         	      *
******************************************************************************/

#define SPCR     *((volatile uint8 *) 0x2D)
#define SPSR     *((volatile uint8 *) 0x2E)
#define SPDR     *((volatile uint8 *) 0x2F)


/******************************************************************************
* !comment : SPI Control Register (SPCR) PINS Definition.                     *
******************************************************************************/

#define SPR0	 (uint8)0
#define SPR1 	 (uint8)1
#define CPHA 	 (uint8)2
#define CPOL 	 (uint8)3
#define MSTR 	 (uint8)4
#define DORD 	 (uint8)5
#define SPE 	 (uint8)6
#define SPIE 	 (uint8)7


/******************************************************************************
* !comment : SPI Status Register (SPSR) PINS Definition.                      *
******************************************************************************/

#define SPI2X	 (uint8)0
#define WCOL 	 (uint8)6
#define SPIF 	 (uint8)7


/******************************************************************************
* !comment : ISR attribute function.  			             	              *
******************************************************************************/

#define ISR(vector)\
void vector (void) __attribute__((signal));\
void vector (void)


/******************************************************************************
* !comment : SPI Interrupt Vectors Definition.  			                  *
******************************************************************************/

#define SPI_STC_VECT     __vector_12

#endif 
/*** !comment : End of guard [SPI_PRIVATE_H] *********************************/
