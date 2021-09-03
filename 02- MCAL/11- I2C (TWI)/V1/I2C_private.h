/*****************************************************************************/
/* Title        	: 	I2C Driver		     			         			 */
/* File Name    	: 	I2C_private.h      	                                 */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	06/01/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

/******************************************************************************
* !comment : I2C(TWI) Registers Addresses Definition.  			         	  *
******************************************************************************/

#define TWBR     *((volatile uint8 *) 0x20)
#define TWSR     *((volatile uint8 *) 0x21)
#define TWAR     *((volatile uint8 *) 0x22)
#define TWDR     *((volatile uint8 *) 0x23)
#define TWCR     *((volatile uint8 *) 0x56)

/******************************************************************************
* !comment : TWI Control Register (TWCR) PINS Definition.       	          *
******************************************************************************/

#define TWIE      (uint8)0
#define TWEN      (uint8)2
#define TWWC      (uint8)3
#define TWSTO     (uint8)4
#define TWSTA     (uint8)5
#define TWEA      (uint8)6
#define TWINT     (uint8)7

/******************************************************************************
* !comment : TWI Status Register (TWSR) PINS Definition.       	              *
******************************************************************************/

#define TWPS0     (uint8)0
#define TWPS1     (uint8)1

/******************************************************************************
* !comment : TWI (Slave) Address Register (TWAR) PINS Definition.             *
******************************************************************************/

#define TWGCE     (uint8)0

/******************************************************************************
* !comment : TWI Data Register(TWDR) PINS Definition.       	              *
******************************************************************************/

#define TWD0      (uint8)0

/******************************************************************************
* !comment : Prescaler Value option Definition.       	                      *
******************************************************************************/

#define PRESCALER_VALUE_1		(uint8)0
#define PRESCALER_VALUE_4		(uint8)1
#define PRESCALER_VALUE_16		(uint8)2
#define PRESCALER_VALUE_64		(uint8)3

/******************************************************************************
* !comment : Acknowledge Bit option Definition.       	                      *
******************************************************************************/

#define ACK_DISABLE				(uint8)0
#define ACK_ENABLE				(uint8)1

/******************************************************************************
* !comment : General Call Recognition option Definition.       	              *
******************************************************************************/

#define GENERAL_CALL_DISABLE	(uint8)0
#define GENERAL_CALL_ENABLE		(uint8)1

/******************************************************************************
* !comment : I2C(TWI) ISR attribute function.  			         	          *
******************************************************************************/

#define ISR(vector, ...)\
void vector (void) __attribute__((signal));\
void vector (void)

/******************************************************************************
* !comment : I2C(TWI) Interrupt Vectors Definition.  			              *
******************************************************************************/

#define I2C_VEC     __vector_19  



#endif 
/*** !comment : End of gaurd [I2C_PRIVATE_H] *********************************/
