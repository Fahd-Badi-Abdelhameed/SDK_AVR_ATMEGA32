/*********************************************************************************/
/* Title        	: 	SPI Driver					         					 */
/* File Name    	: 	SPI_private.h      	                         	         */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	05/01/2021                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


/* UART registers definition */
#define SPCR     *((volatile uint8 *) 0x2D)
#define SPSR     *((volatile uint8 *) 0x2E)
#define SPDR     *((volatile uint8 *) 0x2F)



/* SPI Control Register (SPCR) pins definition */
#define SPR0	 0
#define SPR1 	 1
#define CPHA 	 2
#define CPOL 	 3
#define MSTR 	 4
#define DORD 	 5
#define SPE 	 6
#define SPIE 	 7



/* SPI Status Register (SPSR) pins definition */
#define SPI2X	 0
#define WCOL 	 6
#define SPIF 	 7



/* Data Order option */
#define LSB     0
#define MSB     1


/* Clock Polarity option */
#define Rising_Falling     0
#define Falling_Rising     1


/* Clock Phase option */
#define Sample_Setup     0
#define Setup_Sample     1


/* SPI Clock Rate option */
#define NORMAL_SPEED_DIV_4       0
#define NORMAL_SPEED_DIV_16      1
#define NORMAL_SPEED_DIV_64      2
#define NORMAL_SPEED_DIV_128     3
#define DOUBLE_SPEED_DIV_2       4
#define DOUBLE_SPEED_DIV_8       5
#define DOUBLE_SPEED_DIV_32      6
#define DOUBLE_SPEED_DIV_64      7



/* ISR function prototype */
#define ISR(vector)\
void vector (void) __attribute__((signal));\
void vector (void)


/* SPI Interrupt Vectors */
#define SPI_STC     __vector_12

#endif 
