/*********************************************************************************/
/* Title        	: 	EXIT Driver		        							     */
/* File Name    	: 	EXIT_config.h      		                                 */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	30/10/2020                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#ifndef EXIT_CONFIG_H
#define EXIT_CONFIG_H

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/* EXTI0 & EXTI1 Sense Mode Opetions:
    LOW_LEVEL    
	ON_CHANGE 
	FALLING_EDGE
	RISING_EDGE             */
	
#define EXTI0_SENSE_MODE    FALLING_EDGE  
#define EXTI1_SENSE_MODE    FALLING_EDGE 
 
/* EXTI2 Sense Mode Opetions:
	FALLING_EDGE
	RISING_EDGE             */ 
#define EXTI2_SENSE_MODE    FALLING_EDGE  


/* Interrupt Vector Option                  */
#define INT_VECTOR0     INT0
#define INT_VECTOR1     INT1
#define INT_VECTOR2     INT2


#endif 
/*** End of File **************************************************************/