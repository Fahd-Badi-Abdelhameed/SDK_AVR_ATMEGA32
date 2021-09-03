/*****************************************************************************/
/* Title        	: 	MCP2515(CAN External) Driver		        		 */
/* File Name    	: 	MCP2515_interface.h      		                     */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	26/04/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

#ifndef MCP2515_INTERFACE_H
#define MCP2515_INTERFACE_H


void MCP2515_voidReceiveMessage(void);
void MCP2515_voidReceiveInit(void);
void MCP2515_voidTransmitInit(void);
void MCP2515_voidSendMessage(uint8 Copy_u8BufIdx, uint32 Copy_u32MsgID, uint8 Copy_u8DLC, uint8 *Copy_u8Data);   



#endif
/*** End of File **************************************************************/
