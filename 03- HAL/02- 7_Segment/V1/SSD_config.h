/*****************************************************************************/
/* Title        	: 	7-Segment Driver									 */
/* File Name    	: 	SSD_config.h      		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	10/10/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef SSD_CONFIG_H
#define SSD_CONFIG_H


/******************************************************************************
* !comment : Select 7-segment Type Option :  			         	          *
*		     SSD_CATHODE                                                      *
*            SSD_ANODE                                                        * 
******************************************************************************/

#define SSD_COMMON     SSD_CATHODE


/******************************************************************************
* !comment : Select PORT Data Option:  			         	                  *
*		     PORT_A                                  	                      *
*            PORT_B                                  	                      *
*			 PORT_C                                  	                      *
*			 PORT_D                                  	                      *
******************************************************************************/

#define SSD_PORT       PORT_D


#endif 
 /*** !comment : End of gaurd [SSD_CONFIG_H] *********************************/
