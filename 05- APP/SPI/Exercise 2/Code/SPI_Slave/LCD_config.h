/*********************************************************************************/
/* Title        	: 	LCD Driver									             */
/* File Name    	: 	LCD_config.h                                             */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	16/10/2020                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H



#define  PORT_DATA   PORT_A

#define  RS	         PORT_B, PIN0
#define  RW          PORT_B, PIN1
#define  EN          PORT_B, PIN2


/* LCD Command  */
#define  FUNCTION_SET		0x38
#define  DISPLAY_ON_OFF     0x0E
#define  DISPLAY_CLEAR      0x01


/* Mode options :
	4_BIT_MODE
	8_BIT_MODE      */
#define  LCD_MODE    MODE_4_BIT

#endif 
