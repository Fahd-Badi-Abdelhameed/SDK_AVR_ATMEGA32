/*********************************************************************************/
/* Title        	: 	SPI Driver									             */
/* File Name    	: 	SPI_program.c   		                                 */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	05/01/2021                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H


/* Data Order option:
 * LSB
 * MSB                       */
#define DARA_ORDER     MSB

/*
 * Select clock Polarity option:
 * Rising_Falling ---> Leading Edge - Trailing Edge
 * Falling_Rising ---> Leading Edge - Trailing Edge
*/
#define CLOCK_POLARITY     Rising_Falling

/*
 * Select clock Phase option:
 * Sample_Setup ---> Leading Edge - Trailing Edge
 * Setup_Sample ---> Leading Edge - Trailing Edge
*/
#define CLOCK_PHASE     Sample_Setup

/*
 * Select clock Rate option:
 * NORMAL_SPEED_DIV_4
 * NORMAL_SPEED_DIV_16
 * NORMAL_SPEED_DIV_64
 * NORMAL_SPEED_DIV_128
 * DOUBLE_SPEED_DIV_2
 * DOUBLE_SPEED_DIV_8
 * DOUBLE_SPEED_DIV_32
 * DOUBLE_SPEED_DIV_64
*/
#define CLOCK_RATE    NORMAL_SPEED_DIV_128


#endif 
