/*****************************************************************************/
/* Title        	: 	EEPROM25AA010A Driver								 */
/* File Name    	: 	EEPROM25AA010A_private.h      	                     */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	07/05/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef EEPROM25AA010A_PRIVATE_H
#define EEPROM25AA010A_PRIVATE_H


/******************************************************************************
* !comment : List of EEPROM 25AA010A Control Commands.				          *
******************************************************************************/

#define WREN_OPCODE    0x06
#define WRITE_OPCODE   0x02
#define READ_OPCODE    0x03

/******************************************************************************
* !comment : Dummy Data Define.				                                  *
******************************************************************************/
#define DUMMY_DATA     0x00



#endif 
/*** !comment : End of gaurd [EEPROM25AA010A_PRIVATE_H] **********************/
