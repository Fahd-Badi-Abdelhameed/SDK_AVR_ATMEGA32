/*****************************************************************************/
/* Title        	: 	I2C Driver		        							 */
/* File Name    	: 	I2C_config.h      		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	60/01/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

/******************************************************************************
* !comment  :  Select Bit Rate @ CLK 400kHZ .  								  *
******************************************************************************/

#define BIT_RATE     31


/******************************************************************************
* !comment  :  Select prescaler value option :	  	      					  *
*   		   PRESCALER_VALUE_1    									      *
*			   PRESCALER_VALUE_4                                              *
*			   PRESCALER_VALUE_16                                             *
*			   PRESCALER_VALUE_64                                             *
******************************************************************************/

#define PRESCALER     PRESCALER_VALUE_1

/******************************************************************************
* !comment  :  Select Acknowledge Bit option :	  	      					  *
*   		   ACK_DISABLE    									              *
*			   ACK_ENABLE                                                     *
******************************************************************************/

#define ACK_STATE     ACK_ENABLE

/******************************************************************************
* !comment  :  Select General Call Recognition option :	  	      			  *
*   		   GENERAL_CALL_DISABLE    									      *
*			   GENERAL_CALL_ENABLE                                            *
******************************************************************************/

#define GENERAL_CALL_STATE     GENERAL_CALL_DISABLE



#endif 
/*** !comment : End of gaurd [I2C_CONFIG_H] **********************************/
