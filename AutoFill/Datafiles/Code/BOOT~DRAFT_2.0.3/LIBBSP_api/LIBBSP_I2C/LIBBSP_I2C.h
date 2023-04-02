/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_I2C_H
#define LIBBSP_I2C_H

#include "LIBMCP_Types.h"
#include "kcg_types.h"

/*==== Definitions =====================================================================*/
#define C_I2C_150_MICRO_S (15ul)
#define C_I2C_NB_BYTE_MAX (50ul)
#define C_I2C_UNUSED_REG_SIZE (58)

/*==== Types ===========================================================================*/

/* Devices according GANAV board */
//typedef enum {
//	E_LIBBSP_I2C_BUS_1 = 0,
//	E_LIBBSP_I2C_BUS_2 = 1,
//	E_LIBBSP_I2C_NB_I2C_BUS = 2
//} TE_LIBBSP_I2C_Bus;
// TE_LIBBSP_I2C_Bus defined scade code


/*typedef enum { */
/*	E_LIBBSP_I2C_IDLE, */
/*	E_LIBBSP_I2C_WAIT_FOR_SLV_CMD_W_ACK, */
/*	E_LIBBSP_I2C_WAIT_FOR_SLV_W_ACK, */
/*	E_LIBBSP_I2C_WAIT_FOR_SLV_CMD_R_ACK, */
/*	E_LIBBSP_I2C_WAIT_FOR_SLV_R_DATA, */
/*	E_LIBBSP_I2C_DATA_WRITTEN, */
/*	E_LIBBSP_I2C_DATA_READ */
/*} TE_LIBBSP_I2C_CurrentStep; */
/* defined in kcg_types.h */

/*typedef enum { */
/*	E_LIBBSP_I2C_COMMAND_TAKEN,*/
/*	E_LIBBSP_I2C_COMMAND_NOT_TAKEN,*/
/*	E_LIBBSP_I2C_COMMAND_ERROR,*/
/*	E_LIBBSP_I2C_WRITE_OVERSIZED,*/
/*	E_LIBBSP_I2C_READ_OVERSIZED*/
/*} TE_LIBBSP_I2C_ErrorCode;*/
/* defined in kcg_types.h */

typedef enum {
	E_LIBBSP_I2C_VALID_ADDRESS,
	E_LIBBSP_I2C_INVALID_ADDRESS
} TE_LIBBSP_I2C_AddrStatus;

typedef enum {
	E_LIBBSP_I2C_BUS_CLOSED = 0,
	E_LIBBSP_I2C_BUS_OPEN = 1
} TE_LIBBSP_I2C_DeviceState;


/* Return codes of I2C layer */
/*typedef enum {*/
/*    E_LIBBSP_I2C_OK                  = 0,*/
/*    E_LIBBSP_I2C_INVALID_ID           = 1,*/
/*    E_LIBBSP_I2C_ARBITRATION_LOST     = 2,*/
/*    E_LIBBSP_I2C_NO_ACK               = 3,*/
/*    E_LIBBSP_I2C_BUS_BUSY             = 4,*/
/*    E_LIBBSP_I2C_TIMEOUT             = 5,*/
/*	E_LIBBSP_I2C_CLOSED*/
/*} TE_LIBBSP_I2C_Code;*/
/* defined in kcg_types.h */

/* Frequency divider values */
typedef enum
{
    E_LIBBSP_I2C_DIV_384 = 0,
    E_LIBBSP_I2C_DIV_416,
    E_LIBBSP_I2C_DIV_480,
    E_LIBBSP_I2C_DIV_576,
    E_LIBBSP_I2C_DIV_640,
    E_LIBBSP_I2C_DIV_704,
    E_LIBBSP_I2C_DIV_832,
    E_LIBBSP_I2C_DIV_1024,
    E_LIBBSP_I2C_DIV_1152,
    E_LIBBSP_I2C_DIV_1280,
    E_LIBBSP_I2C_DIV_1536,
    E_LIBBSP_I2C_DIV_1920,
    E_LIBBSP_I2C_DIV_2304,
    E_LIBBSP_I2C_DIV_2560,
    E_LIBBSP_I2C_DIV_3072,
    E_LIBBSP_I2C_DIV_3840,
    E_LIBBSP_I2C_DIV_4608,
    E_LIBBSP_I2C_DIV_5120,
    E_LIBBSP_I2C_DIV_6144,
    E_LIBBSP_I2C_DIV_7680,
    E_LIBBSP_I2C_DIV_9216,
    E_LIBBSP_I2C_DIV_10240,
    E_LIBBSP_I2C_DIV_12288,
    E_LIBBSP_I2C_DIV_15360,
    E_LIBBSP_I2C_DIV_18432,
    E_LIBBSP_I2C_DIV_20480,
    E_LIBBSP_I2C_DIV_24576,
    E_LIBBSP_I2C_DIV_30720,
    E_LIBBSP_I2C_DIV_36864,
    E_LIBBSP_I2C_DIV_40960,
    E_LIBBSP_I2C_DIV_49152,
    E_LIBBSP_I2C_DIV_61440,
    E_LIBBSP_I2C_DIV_256,
    E_LIBBSP_I2C_DIV_288,
    E_LIBBSP_I2C_DIV_320,
    E_LIBBSP_I2C_DIV_352,
    E_LIBBSP_I2C_DIV_384B,
    E_LIBBSP_I2C_DIV_448,
    E_LIBBSP_I2C_DIV_512,
    E_LIBBSP_I2C_DIV_576B,
    E_LIBBSP_I2C_DIV_640B,
    E_LIBBSP_I2C_DIV_768,
    E_LIBBSP_I2C_DIV_896,
    E_LIBBSP_I2C_DIV_1024B,
    E_LIBBSP_I2C_DIV_1280B,
    E_LIBBSP_I2C_DIV_1536B,
    E_LIBBSP_I2C_DIV_1792,
    E_LIBBSP_I2C_DIV_2048,
    E_LIBBSP_I2C_DIV_2560B,
    E_LIBBSP_I2C_DIV_3072B,
    E_LIBBSP_I2C_DIV_3584,
    E_LIBBSP_I2C_DIV_4096,
    E_LIBBSP_I2C_DIV_5120B,
    E_LIBBSP_I2C_DIV_6144B,
    E_LIBBSP_I2C_DIV_7168,
    E_LIBBSP_I2C_DIV_8192,
    E_LIBBSP_I2C_DIV_10240B,
    E_LIBBSP_I2C_DIV_12288B,
    E_LIBBSP_I2C_DIV_14336,
    E_LIBBSP_I2C_DIV_16384,
    E_LIBBSP_I2C_DIV_20480B,
    E_LIBBSP_I2C_DIV_24576B,
    E_LIBBSP_I2C_DIV_28672,
    E_LIBBSP_I2C_DIV_32768
} TE_LIBBSP_I2C_FreqDiv;


/* Registers of I2C P1011 interface */
typedef union
{
    uint32_t R;
    struct                      /* ADR I2C Register */
    {
        uint8_t ADDR:7;   /* Slave address */
        uint8_t :1;       /* Reserved */
		uint32_t :24;      /* 4-bytes alignment */
    } I2CADR;
    struct                      /* Frequency Divider I2C Register */
    {
        uint8_t :2;       /* Reserved */
        uint8_t FDR:6;    /* Frequency divider ratio */
		uint32_t :24;      /* 4-bytes alignment */
    } I2CFDR;
    struct                      /* Control I2C Register */
    {
        uint8_t MEN:1;    /* Module ENable */
        uint8_t MIEN:1;   /* Module Interrupt ENable */
        uint8_t MSTA:1;   /* Master/Slave mode STAR T*/
        uint8_t MTX:1;    /* Transmit/receive Mode */
        uint8_t TXAK:1;   /* Transfer acknowledge */
        uint8_t RSTA:1;   /* Repeated START */
        uint8_t :1;       /* Reserved */
        uint8_t BCST:1;   /* Broadcast */
		uint32_t :24;      /* 4-bytes alignment */
    } I2CCR;
    struct                      /* Status I2C Register */
    {
        uint8_t MCF:1;    /* Data transfer */
        uint8_t MAAS:1;   /* Addressed As A Slave */
        uint8_t MBB:1;    /* Bus Busy */
        uint8_t MAL:1;    /* Arbitration Lost */
        uint8_t BCSTM:1;  /* Broadcast match */
        uint8_t SRW:1;    /* Slave Read/Write */
        uint8_t MIF:1;    /* Module interrupt */
        uint8_t RXAK:1;   /* Received acknowledge */
		uint32_t :24;      /* 4-bytes alignment */
    } I2CSR;
    struct                      /* Data I2C Register */
    {
        uint8_t DATA:8;   /* Transmission data */
		uint32_t :24;      /* 4-bytes alignment */
    } I2CDR;
    struct                      /* Digital Filter Sampling Rate I2C Register */
    {
        uint8_t :2;       /* Reserved */
        uint8_t DFSR:6;   /* Digital filter sampling rate */
		uint32_t :24;      /* 4-bytes alignment */
    } I2CDFSRR;
	union {
        uint32_t       u32;
        uint16_t      u16;
        uint8_t       u8;
    } I2CREG;
} TS_LIBBSP_I2C_Register;


/* Mapping of I2C registers*/
typedef struct {
    volatile TS_LIBBSP_I2C_Register i2cadr;        /* 0x30x0 ADR I2C Register */
    volatile TS_LIBBSP_I2C_Register i2cfdr;        /* 0x30x4 Frequency Divider I2C Register */
    volatile TS_LIBBSP_I2C_Register i2ccr;         /* 0x30x8 Control I2C Register*/
    volatile TS_LIBBSP_I2C_Register i2csr;         /* 0x30xC Status I2C Register */
    volatile TS_LIBBSP_I2C_Register i2cdr;         /* 0x30x0 Data I2C Register */
    volatile TS_LIBBSP_I2C_Register i2cdfsrr;      /* 0x30x4 Digital Filter Sampling Rate I2C Register */
    volatile TS_LIBBSP_I2C_Register i2cunused[C_I2C_UNUSED_REG_SIZE]; /* Unused*/
} TS_LIBBSP_I2C_RegisterSet;


/*==== Variables========================================================================*/

extern TE_LIBBSP_I2C_DeviceState V_I2C_State[E_LIBBSP_I2C_NB_I2C_BUS];
extern volatile TS_LIBBSP_I2C_RegisterSet* const P_I2C_RegAddress;

extern uint8_t V_I2C_BuffWrite[E_LIBBSP_I2C_NB_I2C_BUS][C_I2C_NB_BYTE_MAX];
extern uint8_t V_I2C_BuffRead[E_LIBBSP_I2C_NB_I2C_BUS][C_I2C_NB_BYTE_MAX];
extern uint32_t V_I2C_WriteSize[E_LIBBSP_I2C_NB_I2C_BUS];
extern uint32_t V_I2C_ReadSize[E_LIBBSP_I2C_NB_I2C_BUS];
extern uint32_t V_I2C_WriteIndex[E_LIBBSP_I2C_NB_I2C_BUS];
extern uint32_t V_I2C_ReadIndex[E_LIBBSP_I2C_NB_I2C_BUS];
/*extern uint8_t cntstep[20]; debug*/

/*==== Services ========================================================================*/

extern TE_LIBBSP_I2C_Code LIBBSP_I2C_Close(const TE_LIBBSP_I2C_Bus v_devID);
extern TE_LIBBSP_I2C_ErrorCode LIBBSP_I2C_GetReadData(	const TE_LIBBSP_I2C_Bus v_devID,
					const uint32_t v_size,
					uint8_t * const pa_buffer);
extern TE_LIBBSP_I2C_Code LIBBSP_I2C_Initialize(void);
extern TE_LIBBSP_I2C_Code LIBBSP_I2C_Open(const TE_LIBBSP_I2C_Bus v_devID,
				const uint8_t v_digital_filter,
				const TE_LIBBSP_I2C_FreqDiv v_divider );
extern TE_LIBBSP_I2C_Code LIBBSP_I2C_Read(const TE_LIBBSP_I2C_Bus v_devID,
									const uint8_t v_slave_adress,
									const uint32_t v_size,
									uint8_t * const pa_buffer);
extern TE_LIBBSP_I2C_ErrorCode LIBBSP_I2C_ReadNoWait(	const TE_LIBBSP_I2C_Bus v_devID,
					const uint8_t v_slave_adress,
					const uint32_t v_size,
				    TE_LIBBSP_I2C_CurrentStep* const v_step);
extern TE_LIBBSP_I2C_ErrorCode LIBBSP_I2C_Step(	const TE_LIBBSP_I2C_Bus v_devID,
											TE_LIBBSP_I2C_CurrentStep* const v_step);
extern TE_LIBBSP_I2C_Code LIBBSP_I2C_Write(	const TE_LIBBSP_I2C_Bus v_devID,
					const uint8_t v_slave_adress,
					const uint32_t v_size,
					const uint8_t * const p_buffer );
extern TE_LIBBSP_I2C_ErrorCode LIBBSP_I2C_WriteNoWait(	const TE_LIBBSP_I2C_Bus v_devID,
					const uint8_t v_slave_adress,
					const uint32_t v_size,
					const uint8_t * const p_buffer,
					TE_LIBBSP_I2C_CurrentStep* const v_step);
extern TE_LIBBSP_I2C_Code LIBBSP_I2C_Reset(const TE_LIBBSP_I2C_Bus v_devID);

/*==== END =============================================================================*/
#endif
