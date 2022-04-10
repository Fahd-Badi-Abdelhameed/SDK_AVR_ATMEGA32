/*****************************************************************************/
/* Title        	: 	LCD Driver				     */
/* File Name    	: 	LCD_config.h                                 */
/* Author       	: 	Fahd Badi                                    */
/* Version      	: 	1.0.0                                        */
/* Origin Date  	: 	16/10/2020                                   */
/* Notes        	: 	None                                         */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 		      *
*                 than one time.                               	 	      *
******************************************************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/******************************************************************************
* !comment : LCD Select Mode Options.  			         	      *
*            MODE_4_BIT                                                       *
*            MODE_8_BIT                                                       *
******************************************************************************/
#define  LCD_MODE    MODE_4_BIT

/******************************************************************************
* !comment : LCD PINs Definition, Select PINs Options:   		      *
* 		   	 DIO_PINA0 - DIO_PINA7                                *
* 		   	 DIO_PINB0 - DIO_PINB7                                *
* 		   	 DIO_PINC0 - DIO_PINC7                                *
* 		   	 DIO_PIND0 - DIO_PIND7                                *
******************************************************************************/
#if (LCD_MODE == MODE_8_BIT)
#define LCD_D0_PIN       DIO_PINA0
#define LCD_D1_PIN       DIO_PINA1
#define LCD_D2_PIN       DIO_PINA2
#define LCD_D3_PIN       DIO_PINA3
#define LCD_D4_PIN       DIO_PINA4
#define LCD_D5_PIN       DIO_PINA5
#define LCD_D6_PIN       DIO_PINA6
#define LCD_D7_PIN       DIO_PINA7

#elif (LCD_MODE == MODE_4_BIT)
#define LCD_D4_PIN       DIO_PINA0
#define LCD_D5_PIN       DIO_PINB1
#define LCD_D6_PIN       DIO_PINC3
#define LCD_D7_PIN       DIO_PIND5

#endif

/* LCD Control Pins */
#define LCD_RS_PIN	    DIO_PINA4
#define LCD_RW_PIN      DIO_PINA5
#define LCD_EN_PIN      DIO_PINA6




#endif 
/*** !comment : End of gaurd [LCD_CONFIG_H] **********************************/
