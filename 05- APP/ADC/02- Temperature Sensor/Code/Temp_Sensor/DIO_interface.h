/*********************************************************************************/
/* Title        	: 	DIO Driver												 */
/* File Name    	: 	DIO_interface.h                                          */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	10/10/2020                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* Port options */
#define  PORT_A     0
#define  PORT_B     1
#define  PORT_C     2
#define  PORT_D     3

/* Mode options */
#define  INPUT      0
#define  OUTPUT     1

/* Value options */
#define  LOW        0
#define  HIGH       1

/* Pins options */
#define  PIN0       0
#define  PIN1       1
#define  PIN2       2
#define  PIN3       3
#define  PIN4       4
#define  PIN5       5
#define  PIN6       6
#define  PIN7       7



void  DIO_voidSetPinDirection (uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Mode );
void  DIO_voidSetPinValue     (uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Value);
void  DIO_voidSetPortDirection(uint8 Copy_u8Port, uint8 Copy_u8Mode );
void  DIO_voidSetPortValue    (uint8 Copy_u8Port, uint8 Copy_u8Value);
void  DIO_voidTogglePin       (uint8 Copy_u8Port, uint8 Copy_u8Pin  );
uint8 DIO_u8GetPinValue       (uint8 Copy_u8Port, uint8 Copy_u8Pin  );

#endif 

