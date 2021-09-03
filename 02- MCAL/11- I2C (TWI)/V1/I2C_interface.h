/*****************************************************************************/
/* Title        	: 	I2C Driver									         */
/* File Name    	: 	I2C_interface.h   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	06/01/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

/******************************************************************************
***************************** Function Prototypes *****************************
******************************************************************************/

/******************************************************************************
* Description 	: I2C(TWI) master initialization Function.				      *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none                                                        *
******************************************************************************/

void I2C_voidMasterInit(void);

/******************************************************************************
* Description 	: I2C(TWI) slave initialization Function.				      *
* Parameters  	: My Device Address( --> ).    		                  	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none                                                        *
******************************************************************************/

void I2C_voidSlaveInit(uint8 Copy_u8MyAddress);

/******************************************************************************
* Description 	: I2C(TWI) start condition Function.				          *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after I2C(TWI) master            *
*                 initialization Function.                                    *
******************************************************************************/

void I2C_voidStartCondition(void);

/******************************************************************************
* Description 	: II2C(TWI) repeated start condition Function.				  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none                                                        *
******************************************************************************/

void I2C_voidRepeatedStartCondition(void);

/******************************************************************************
* Description 	: I2C(TWI) stop condition Function.				              *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none                                                        *
******************************************************************************/

void I2C_voidStopCondition(void);

/******************************************************************************
* Description 	: I2C(TWI) send slave address with write Function.		      *
* Parameters  	: Slave Address( --> )     		                  	 	      *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none                                                        *
******************************************************************************/

void I2C_voidSendSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress);

/******************************************************************************
* Description 	: I2C(TWI) send slave address with read Function.			  *
* Parameters  	: Slave Address     		                         	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none                                                        *
******************************************************************************/

void I2C_voidSendSlaveAddressWithRead(uint8 Copy_u8SlaveAddress);

/******************************************************************************
* Description 	: I2C(TWI) master send data byte Function .				      *
* Parameters  	: Data     		                  	 	                      *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none                                                        *
******************************************************************************/

void I2C_voidMasterSendDataByte(uint8 Copy_u8Data);

/******************************************************************************
* Description 	: I2C(TWI) master read data byte Function .				      *
* Parameters  	: none     		                  	 	                      *
* Return type 	: uint8                                                   	  *
*******************************************************************************
* Pre_condition : none                                                        *
******************************************************************************/

uint8 I2C_u8MasterReadDataByte(void);

/******************************************************************************
* Description 	: I2C(TWI) get status Function .				              *
* Parameters  	: none     		                  	 	                      *
* Return type 	: uint8                                                   	  *
*******************************************************************************
* Pre_condition : none                                                        *
******************************************************************************/

uint8 I2C_u8GetStatus(void);

/******************************************************************************
* Description 	: I2C(TWI) Interrupt Enable Function.				          *
* Parameters  	: none     		                  	 	                      *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none                                                        *
******************************************************************************/

void I2C_voidInterruptEnable(void);

/******************************************************************************
* Description 	: I2C(TWI) Interrupt Disable Function.				          *
* Parameters  	: none    		                  	 	                      *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none                                                        *
******************************************************************************/

void I2C_voidInterruptDisable(void);



#endif 
/*** !comment : End of gaurd [I2C_INTERFACE_H] *******************************/
