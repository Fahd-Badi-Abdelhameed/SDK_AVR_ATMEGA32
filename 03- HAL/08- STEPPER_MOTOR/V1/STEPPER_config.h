/*****************************************************************************/
/* Title        	: 	STEPPER Driver									     */
/* File Name    	: 	STEPPER_config.h      		                         */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	02/02/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef STEPPER_CONFIG_H
#define STEPPER_CONFIG_H

/******************************************************************************
* !comment : Please write pair  PORT , PIN.  			         	          *
******************************************************************************/

#define STEPPER_COIL1_PIN		PORT_A, PIN0
#define STEPPER_COIL2_PIN		PORT_A, PIN1
#define STEPPER_COIL3_PIN		PORT_A, PIN2
#define STEPPER_COIL4_PIN		PORT_A, PIN3


#endif 
/*** !comment : End of gaurd [STEPPER_CONFIG_H] ******************************/
