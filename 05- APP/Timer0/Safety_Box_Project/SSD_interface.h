/*****************************************************************************/
/* Title        	: 	7-Segment Driver									 */
/* File Name    	: 	SSD_interface.h   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	10/10/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H


/******************************************************************************
* !comment : 7-Segment Counter Position Options:  			         	      *
******************************************************************************/

#define SSD_COUNT_UP	    1
#define SSD_COUNT_DOWN      0


/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/


/******************************************************************************
* Description 	: 7-Segment Initialization Function.				          *
* Parameters  	: none.   		                                    	 	  *
* Return type 	: void.                                                  	  *
*******************************************************************************
* Pre_condition : none.   							                          *
******************************************************************************/

void SSD_voidInit(void);

/******************************************************************************
* Description : 7-Segment Display Number Function.						      *
* Parameters  : Number (0 ---> F).           	                              *
* Return type : void                                                  	 	  *
*******************************************************************************
* Pre_condition : This function must be used after 7-Segment Initialization   *
* 				  function.				 									  *
******************************************************************************/

void SSD_voidDisplayNumber(uint8 Copy_u8Number);

/******************************************************************************
* Description : 7-Segment Display Counter Function.						      *
* Parameters  : Position( SSD_COUNT_UP, SSD_COUNT_DOWN ), Speed( ms ).        *
* Return type : void                                                  	 	  *
*******************************************************************************
* Pre_condition : This function must be used after 7-Segment Initialization   *
* 				  function.				 									  *
******************************************************************************/

void SSD_voidDisplayCounter(uint8 Copy_u8Position, uint8 Copy_u8Delay);

/******************************************************************************
* Description : 7-Segment Display Char Function.						      *
* Parameters  : Char( A --> H ).                                              *
* Return type : void                                                  	 	  *
*******************************************************************************
* Pre_condition : This function must be used after 7-Segment Initialization   *
* 				  function.				 									  *
******************************************************************************/

void SSD_voidDisplayExtraChar(uint8 Copy_u8Char);


#endif 
 /*** !comment : End of gaurd [SSD_INTERFACE_H] ******************************/
