/*****************************************************************************/
/* Title        	: 	SPI Driver									         */
/* File Name    	: 	SPI_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	05/01/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/******************************************************************************
* !comment : Select SPI Data Order option:  			         	          *
*            LSB                                                              *
*            MSB                                                              *
******************************************************************************/

#define DARA_ORDER     MSB

/******************************************************************************
* !comment : Select SPI Clock Polarity Option:  			         	      *
*            Rising_Falling                                                   *
*            Falling_Rising                                                   *
******************************************************************************/

#define CLOCK_POLARITY     Rising_Falling

/******************************************************************************
* !comment : Select SPI Clock Phase Option:  			         	          *
*            Sample_Setup                                                     *
*            Setup_Sample                                                     *
******************************************************************************/

#define CLOCK_PHASE     Sample_Setup

/******************************************************************************
* !comment : Select SPI Clock Rate Option:  			         	          *
*            NORMAL_SPEED_DIV_4                                               *
*            NORMAL_SPEED_DIV_16                                              *
*            NORMAL_SPEED_DIV_64                                              *
*            NORMAL_SPEED_DIV_128                                             *
*            DOUBLE_SPEED_DIV_2                                               *
*            DOUBLE_SPEED_DIV_8                                               *
*            DOUBLE_SPEED_DIV_32                                              *
*            DOUBLE_SPEED_DIV_64                                              *
******************************************************************************/

#define CLOCK_RATE    NORMAL_SPEED_DIV_128


#endif 
/*** !comment : End of guard [SPI_CONFIG_H] **********************************/
