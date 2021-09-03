/*****************************************************************************/
/* Title        	: 	MCP2515(CAN External) Driver		        		 */
/* File Name    	: 	MCP2515_private.h      		                         */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	26/04/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

#ifndef MCP2515_PRIVATE_H
#define MCP2515_PRIVATE_H


#define RX0IE				0
#define BUKT				2


/* SPI INSTRUCTION SET */

#define MCP2515_INST_RESET         0xC0
#define MCP2515_INST_WRITE         0x02
#define MCP2515_INST_READ          0x03
#define MCP2515_INST_MODIFY        0x05
#define MCP2515_INST_RTS_TXB0      0x81
#define MCP2515_INST_RTS_TXB1      0x82
#define MCP2515_INST_RTS_TXB2      0x84




/* CAN CONTROLLER REGISTER */

#define CNF1        (0x2A)
#define CNF2        (0x29)
#define CNF3        (0x28)
#define CANCTRL     (0x0F)
#define CANSTAT     (0x0E)
#define TXB0CTRL    (0x30)
#define RXB0CTRL    (0x60) 
#define RXB1CTRL    (0x70)
#define RXM0SIDH    (0x20)
#define RXM1SIDH    (0x24)
#define CANINTE     (0x2B)
#define CANINTF     (0x2C)



/* MODES OF OPERATION */

#define MCP2515_MODE_NORMAL          0x0		
#define MCP2515_MODE_SLEEP           0x1 		
#define MCP2515_MODE_LOOPBACK        0x2 		
#define MCP2515_MODE_LISTEN_ONLY     0x3 		
#define MCP2515_MODE_CONFIG          0x4 		


static void MCP2515_voidReset(void);
static void MCP2515_voidSetRollover(void);
static void MCP2515_voidSetMode(uint8 Copy_u8Mode);
static uint8 MCP2515_u8ReadRegister(uint8 Copy_u8AddressByte);
static void MCP2515_voidRequestToSend(uint8 Copy_u8BufferNumber);
static void MCP2515_voidWriteRegister(uint8 Copy_u8AddressByte, uint8 Copy_u8DataByte);
static void MCP2515_voidSetBitTiming(uint8 Copy_u8CNF1VAL, uint8 Copy_u8CNF2VAL, uint8 Copy_u8CNF3VAL);
static void MCP2515_voidBitModify(uint8 Copy_u8AddressByte, uint8 Copy_u8MaskByte, uint8 Copy_u8DataByte);
static void MCP2515_voidSetMask(uint8 Copy_u8MaskAddress, uint32 Copy_u32Value, uint8 Copy_u8Extended);


#endif
/*** End of File **************************************************************/
