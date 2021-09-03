/*****************************************************************************/
/* Title        	: 	ADC Driver		      					     		 */
/* File Name    	: 	ADC_config.h      		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	06/11/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H


/******************************************************************************
* !comment : ADC Voltage Reference options:							          *
*			 AREF                                                             *
*	         AVCC                                                             *
*            INTERNAL   			         	      			              *
******************************************************************************/

#define VOLTAGE_REF        AVCC

/******************************************************************************
* !comment : ADC Adjust Result options:							              *
*			 LEFT_ADJUST                                                      *
*            RIGHT_ADJUST                			         	      		  *
******************************************************************************/

#define ADJUST_RESULT      RIGHT_ADJUST

/******************************************************************************
* !comment : ADC Prescaler Selections options:						          *
*			 DIV_FACTOR_2                                                     *
*            DIV_FACTOR_4                                                     *
*            DIV_FACTOR_8                                                     *
*            DIV_FACTOR_16                                                    *
*            DIV_FACTOR_32                                                    *
*            DIV_FACTOR_64                                                    *
*            DIV_FACTOR_128    				                                  *
******************************************************************************/

#define PRESCALER       DIV_FACTOR_8

/******************************************************************************
* !comment : ADC Auto Trigger options:							              *
*			 AUTO_TRIGGER_ENABLE                                              *
*            AUTO_TRIGGER_DISABLE    					                      *
******************************************************************************/

#define AUTO_TRIGGER      AUTO_TRIGGER_DISABLE

/******************************************************************************
* !comment : ADC Auto Trigger Source options:						          *
*			 FREE_RUNNING                                                     *
*            ANALOG_COMPARATOR                                                *
*            EXTERNAL_INTERRUPT_REQUEST0                                      *
*            TIMER0_COMPARE_MATCH                                             *
*            TIMER0_OVERFLOW                                                  *
*            TIMER_COMPARE_MATCH_B                                            *
*            TIMER1_OVERFLOW                                                  *
*            TIMER1_CAPTURE_EVENT  					                          *
******************************************************************************/

#define AUTO_TRIGGER_SOURCE		FREE_RUNNING


#endif 
/*** !comment : End of gaurd [ADC_CONFIG_H] **********************************/
