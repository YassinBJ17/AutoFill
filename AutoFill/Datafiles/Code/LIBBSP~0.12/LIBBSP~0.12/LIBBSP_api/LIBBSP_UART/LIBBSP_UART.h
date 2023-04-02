/****************************************************************************************/

/*                                                                                      */

/*--------------------------------------------------------------------------------------*/

/* Copyright (c) 2019                                                                   */

/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */

/****************************************************************************************/
#include "LIBMCP_Types.h"
#include "kcg_types.h"

/*==== Definitions =====================================================================*/
#ifndef LIBBSP_UART_H
#define LIBBSP_UART_H

#define C_UART_DEVICES_COUNT 8ul
#define C_UART_MEGATICE_BLOCK_SIZE 1024 
#define C_UART_RX_USED_SIZE 3
#define C_UART_TX_USED_SIZE 4
#define C_UART_FIFO_SIZE 2048ul


/* TE_LIBBSP_UART_Dev Moved to kcg_types.h*/

/* TE_LIBBSP_UART_Speed Moved to kcg_types.h*/

/* TE_LIBBSP_UART_Parity Moved to kcg_types.h*/

/* TE_LIBBSP_UART_StopBits Moved to kcg_types.h*/

/* Enable UART */
typedef enum {
    E_LIBBSP_UART_DISABLE	          = 0,
	E_LIBBSP_UART_ENABLE		      = 1
} TE_LIBBSP_UART_Enable;



typedef enum {
	E_LIBBSP_UART_VALID_ADDR  = 0,
	E_LIBBSP_UART_INVALID_ADDR= 1
} TE_LIBBSP_UART_AddrStatus;

typedef union
{
    uint32_t R;
    struct                      /* RX Status */
    {
		uint32_t 					:16;   			/* Reserved */
        uint32_t RXVLDBYTES        	:3;            	/* No. of valid bytes in last read access of UARTx_RX_FIFO register, 0x3:4, 0x2:3, 0x1:2, 0x0:1 */
		uint32_t RXRAMFLUSHDONE		:1;         	/* RAM flush done */
		uint32_t RXERRPARITY		:1;         	/* Parity error 0: no error, 1: one error at least */
        uint32_t RXERRSTOP			:1;         	/* Stop error 0: no error, 1: one error at least */
		uint32_t RXBUFROLLOVER		:2;  		    /* Incremented at 0 transitions of buffer */
		uint32_t RXERRCOUNT			:8;   			/* Error counter (stop + parity) */
    } RXSTAT;
} TU_LIBBSP_UART_RxState;


typedef union
{
    uint32_t R;
    struct                      /* TX Status */
    {
        uint32_t  					:21;           	/* Reserved */
		uint32_t TXSTATE			:1;             /* Transmisson in progress 0: no frame, 1: in progress */
		uint32_t TXOVFFIFO			:1;            	/* Transmit FIFO overflow, 0: no error, 1: one error at least */
		uint32_t TXOVFCMD			:1;            	/* Transmit command while transmit 0: no error, 1: one error at least */
		uint32_t TXERRCOUNT			:8;  	        /* Error counter of overflows (Cmd + FIFO) */
    } TXSTAT;
} TU_LIBBSP_UART_TxState;


/* Registers of Megatice UART interface */
typedef union
{
    uint32_t R;
    struct                      /* TX Command Register */
    {
		uint32_t                 	:5;	            /* Reserved */
        uint32_t TXVLDBYTES        	:2;            	/* No. of valid bytes in last write access of UARTx_TX_FIFO register, 0x3:4, 0x2:3, 0x1:2, 0x0:1 */
		uint32_t TXCOMMAND          :1;	            /* Reserved */
        uint32_t TXENABLE        	:1;            	/* Enable UART, 0: disabled, 1: enabled */
        uint32_t TXNBBITSTOP       	:1;            	/* Number of stop bits of a frame, 0: 2 stop bits 1: 1 stop bit */
        uint32_t TXPARITYTYPE      	:2;            	/* Parity type computed/checked, 0x0: No parity 0x1: Odd parity 0x2: Even parity 0x3: No parity */
		uint32_t TXBAUDRATE	      	:20;          	/* UART transmission/reception speed, Baud Rate = Fclk / (2 x uart_speed) */
    } TXCOM;

    struct                      /* TX Status */
    {
        uint32_t  					:21;           	/* Reserved */
		uint32_t TXSTATE			:1;             /* Transmisson in progress 0: no frame, 1: in progress */
		uint32_t TXOVFFIFO			:1;            	/* Transmit FIFO overflow, 0: no error, 1: one error at least */
		uint32_t TXOVFCMD			:1;            	/* Transmit command while transmit 0: no error, 1: one error at least */
		uint32_t TXERRCOUNT			:8;  	        /* Error counter of overflows (Cmd + FIFO) */
    } TXSTAT;

    struct                      /* TX WORD IN FIFO/ TX FIFO CNT */
    {
        uint32_t  					:20;           	/* Reserved */	
		uint32_t TXWRDCNT			:12;            /* Bytes to transmit in FIFO 0x000: 0 byte,0x001: 1 byte...0x200: 512 bytes*/
    } TXFIFOCNT;

    struct                      /* TX FIFO */
    {
        uint8_t TXBYTE3			    :8;            /* 4th byte to transmit  */
        uint8_t TXBYTE2			    :8;            /* 3rd byte to transmit  */
        uint8_t TXBYTE1			    :8;            /* 2nd byte to transmit  */
        uint8_t TXBYTE0			    :8;            /* 1st byte to transmit  */
    } TXFIFO;

    struct                      /* RX Command Register */
    {
		uint32_t 					:9;          	/* Reserved */
        uint32_t RXPARITYTYPE      	:2;            	/* Parity type computed/checked, 0x0: No parity 0x1: Odd parity 0x2: Even parity 0x3: No parity */		
        uint32_t RXENABLE			:1;     	    /* Enable port 0: disabled, 1: enabled */
		uint32_t RXBAUDRATE			:20;   	    	/* UART transmission/reception speed, Baud Rate = Fclk / (2 x uart_speed) */
    } RXCOM;

    struct                      /* RX Status */
    {
		uint32_t 					:16;   			/* Reserved */
        uint32_t RXVLDBYTES        	:3;            	/* No. of valid bytes in last read access of UARTx_RX_FIFO register, 0x3:4, 0x2:3, 0x1:2, 0x0:1 */
		uint32_t RXRAMFLUSHDONE		:1;         	/* RAM flush done */
		uint32_t RXERRPARITY		:1;         	/* Parity error 0: no error, 1: one error at least */
        uint32_t RXERRSTOP			:1;         	/* Stop error 0: no error, 1: one error at least */
		uint32_t RXBUFROLLOVER		:2;  		    /* Incremented at 0 transitions of buffer */
		uint32_t RXERRCOUNT			:8;   			/* Error counter (stop + parity) */
    } RXSTAT;

    struct                      /* RX REC ADDR / RX BUFF COUNT / RX FIFO COUNT */
    {
		uint32_t RXWRDCNT			:32;            /* Number of bytes received in the RX FIFO/Write address pointer */
    } RXFIFOCNT;

    struct                      /* RX Circular Buffer */
    {
        uint8_t RXBYTE3	    		:8;            /* 4th received byte in Circular Buffer  */
        uint8_t RXBYTE2	    		:8;            /* 3rd received byte in Circular Buffer  */
        uint8_t RXBYTE1	    		:8;            /* 2nd received byte in Circular Buffer  */
        uint8_t RXBYTE0	    		:8;            /* 1st received byte in Circular Buffer  */
    } RXCIRBUFF;
    
    struct                      /* RX Circular Buffer */
    {
        uint8_t RXBYTE[4];
    } RXCIRBUFF_TAB;
} TU_LIBBSP_UART_Register;



/* Megatice blocks of functionnal interface */
typedef union
{
    TU_LIBBSP_UART_Register mRegister[C_UART_MEGATICE_BLOCK_SIZE]; 
    struct                      /* UART Receive Controller registers */
    {
        TU_LIBBSP_UART_Register rxCommand;             /* Command register */
        TU_LIBBSP_UART_Register rxStatus;              /* Status register */
        TU_LIBBSP_UART_Register rxBuffercount;    /* Number of bytes received in the RX FIFO/Write address pointer */ 
        TU_LIBBSP_UART_Register rxUnused1[C_UART_MEGATICE_BLOCK_SIZE-C_UART_RX_USED_SIZE]; /* Unused */
    } RXUART;

    struct        				/* UART Tramsmit Controller registers */
    {
        TU_LIBBSP_UART_Register txCommand;             /* Command register */
        TU_LIBBSP_UART_Register txStatus;              /* Status register */
		TU_LIBBSP_UART_Register txFIFOcount;           /* FIFO count registers, 0x000: 0 byte to transmit (TX FIFO is empty), 0x200: 512 bytes to transmit (TX FIFO is full) */
        TU_LIBBSP_UART_Register txFIFO;
        TU_LIBBSP_UART_Register txUnused1[C_UART_MEGATICE_BLOCK_SIZE-C_UART_TX_USED_SIZE]; /* Unused */
    } TXUART;
} TU_LIBBSP_UART_MegaticeBlock;


typedef union
{
    struct {
        volatile TU_LIBBSP_UART_MegaticeBlock uartController[C_UART_DEVICES_COUNT];   /* Blocks of all Controllers */
    } ALLCTL;
} TU_LIBBSP_UART_Registers;



/*==== Variables =======================================================================*/

// extern volatile TU_LIBBSP_UART_Registers * const V_UARTRegs;
// extern uint32_t V_UARTPointers[C_UART_DEVICES_COUNT];
// extern uint32_t V_UARTSubPointers[C_UART_DEVICES_COUNT];
// extern TU_LIBBSP_UART_Register * V_UARTReceiveBuffers[C_UART_DEVICES_COUNT];

/*==== Services ========================================================================*/

extern TE_LIBBSP_UART_TxErrorCode LIBBSP_UART_InitOutputLink(const TE_LIBBSP_UART_Dev v_DevID, const TE_LIBBSP_UART_Speed v_BaudRate,const TE_LIBBSP_UART_Parity v_Parity, const TE_LIBBSP_UART_StopBits v_StopBits);
extern TE_LIBBSP_UART_RxErrorCode LIBBSP_UART_InitInputLink(const TE_LIBBSP_UART_Dev v_DevID, const uint32_t * const v_RxBuffer, const TE_LIBBSP_UART_Speed v_BaudRate,const TE_LIBBSP_UART_Parity v_Parity);
extern TE_LIBBSP_UART_RxErrorCode LIBBSP_UART_ActivateRead(const TE_LIBBSP_UART_Dev v_DevID, const boolean_t v_Enable);
extern TE_LIBBSP_UART_TxErrorCode LIBBSP_UART_ActivateWrite(const TE_LIBBSP_UART_Dev v_DevID, const boolean_t v_Enable);
extern void LIBBSP_UART_Read(const TE_LIBBSP_UART_Dev v_DevID, const uint32_t v_ToRead, uint8_t * const pa_Buffer, uint32_t * const pa_Read, TU_LIBBSP_UART_RxState * const pa_ErrorState, TE_LIBBSP_UART_RxErrorCode * const pa_Status);
extern void LIBBSP_UART_Write(const TE_LIBBSP_UART_Dev v_DevID, const uint32_t v_Size, const uint8_t * const p_Buffer, uint32_t * const pa_Written, TU_LIBBSP_UART_TxState * const pa_ErrorState, TE_LIBBSP_UART_TxErrorCode * const pa_Status);
extern void LIBBSP_UART_Launch(const TE_LIBBSP_UART_Dev v_DevID, TU_LIBBSP_UART_TxState * const pa_ErrorState, TE_LIBBSP_UART_TxErrorCode * const pa_Status);

/*==== END =============================================================================*/

#endif

