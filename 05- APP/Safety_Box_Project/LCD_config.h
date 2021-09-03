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


/* Select LCD port data */
#define  LCD_PORT_DATA   PORT_A


/*                       port , pin     */
#define  LCD_RS_PIN	    PORT_B, PIN0
#define  LCD_RW_PIN     PORT_B, PIN1
#define  LCD_EN_PIN     PORT_B, PIN2



/* Select LCD mode options :
 * MODE_4_BIT
 * MODE_8_BIT
*/
#define  LCD_MODE    MODE_8_BIT



const uint8 ExtraChar[64]=
{
		0x02, 0x00, 0x17, 0x15, 0x1F, 0x00, 0x00, 0x00,   /* Char0 @ CGRAM */
		0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x0C, 0x18,   /* Char1 @ CGRAM */
		0x04, 0x0A, 0x00, 0x15, 0x1F, 0x00, 0x00, 0x00,   /* Char2 @ CGRAM */
		0x06, 0x0E, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00,   /* Char3 @ CGRAM */
		0x00, 0x00, 0x0E, 0x0A, 0x0E, 0x02, 0x04, 0x08,   /* Char4 @ CGRAM */
		0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x0C, 0x18,   /* Char5 @ CGRAM */
		0x00, 0x00, 0x04, 0x0A, 0x1B, 0x0A, 0x04, 0x00,   /* Char6 @ CGRAM */
		0x00, 0x00, 0x07, 0x04, 0x1F, 0x00, 0x00, 0x00,   /* Char7 @ CGRAM */
};


#endif 
