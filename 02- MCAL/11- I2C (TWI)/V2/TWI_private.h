/*********************************************************************************/
/* Title        	: 	TWI Driver									             */
/* File Name    	: 	TWI_private.h      	                 	                 */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	07/05/2021                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H

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


#endif 
