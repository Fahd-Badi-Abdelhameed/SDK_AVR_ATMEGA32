/*****************************************************************************/
/* Title        	: 	WDT Driver								             */
/* File Name    	: 	WDT_interface.h   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	20/11/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

/******************************************************************************
* !comment :  Watchdog Timer Prescale Select options:  			              *
******************************************************************************/
			/**************************************************
			*   Typical Time-out at *  VCC=5.0V  *  VCC=3.0V  *
			***************************************************
			*  WDT_PRESCALER_16K    *  16.3 ms   *  17.1 ms   *
			*  WDT_PRESCALER_32K    *  32.5 ms   *  34.3 ms   *
			*  WDT_PRESCALER_64K    *  65   ms   *  68.5 ms   *
			*  WDT_PRESCALER_128K   *  0.13 s    *  0.14 s    *
			*  WDT_PRESCALER_256K   *  0.26 s    *  0.27 s    *
			*  WDT_PRESCALER_512K   *  0.52 s    *  0.55 s    *
			*  WDT_PRESCALER_1024K  *  1.0  s    *  1.1  s    *
			*  WDT_PRESCALER_2048K  *  2.1  s    *  2.2  s    *
			**************************************************/  

#define WDT_PRESCALER_16K       0	    
#define WDT_PRESCALER_32K       1
#define WDT_PRESCALER_64K       2
#define WDT_PRESCALER_128K      3
#define WDT_PRESCALER_256K      4
#define WDT_PRESCALER_512K      5
#define WDT_PRESCALER_1024K     6
#define WDT_PRESCALER_2048K     7


/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/


/******************************************************************************
* Description : Watchdog Timer Initialization Function.			              *
* Parameters  : none.                                                         *
* Return type : void.                                                  	 	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void WDT_voidSleep(uint8 Copy_u8SleepTime);

/******************************************************************************
* Description : Watchdog Timer Enable Function.			                      *
* Parameters  : none.                                                         *
* Return type : void.                                                  	 	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void WDT_voidEnable(void);

/******************************************************************************
* Description : Watchdog Timer Disable Function.			                  *
* Parameters  : none.                                                         *
* Return type : void.                                                  	 	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void WDT_voidDisable(void);

/******************************************************************************
* Description : Watchdog Timer Refresh Function.			                  *
* Parameters  : none.                                                         *
* Return type : void.                                                  	 	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void WDT_voidRefresh(void);


#endif 
/*** !comment : End of gaurd [WDT_INTERFACE_H] *******************************/