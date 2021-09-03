/*****************************************************************************/
/* Title        	: 	EEPROM Driver										 */
/* File Name    	: 	EEPROM_private.h      	                 	         */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	10/05/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/
#ifndef EEPROM_PRIVATE_H
#define EEPROM_PRIVATE_H


/******************************************************************************
* !comment : Internal EEPROM Registers Addresses Definition.  			      *
******************************************************************************/

#define EEARH     *((volatile uint8 *) 0x3F)
#define EEARL     *((volatile uint8 *) 0x3E)
#define EEDR      *((volatile uint8 *) 0x3D)
#define EECR      *((volatile uint8 *) 0x3C)

#define EEAR      *((volatile uint16 *) 0x3E)


/******************************************************************************
* !comment : The EEPROM Control Register(EECR) PINS Definition.               *
******************************************************************************/

#define EERE       0
#define EEWE       1
#define EEMWE      2
#define EERIE      3


/******************************************************************************
* !comment : EEPROM ISR attribute function.  			             	      *
******************************************************************************/

#define ISR(vector, ...)\
void vector (void) __attribute__((signal));\
void vector (void)

/******************************************************************************
* !comment : EEPROM Interrupt Vectors Definition.  			                  *
******************************************************************************/

#define EEPROM_RDY_VECT      __vector_17




#endif 
/*** !comment : End of gaurd [EEPROM_PRIVATE_H] *********************************/