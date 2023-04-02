/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVGPIO_PRIVATE_H
#define DRVGPIO_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVGPIO_MAX_PORTS_NB            5UL

#define DRVGPIO_PORT_A_ID               0UL
#define DRVGPIO_PORT_B_ID               1UL
#define DRVGPIO_PORT_C_ID               2UL
#define DRVGPIO_PORT_D_ID               3UL
#define DRVGPIO_PORT_E_ID               4UL

#define DRVGPIO_PORT_A_ADDRESS          0x400FF000UL
#define DRVGPIO_PORT_B_ADDRESS          0x400FF040UL
#define DRVGPIO_PORT_C_ADDRESS          0x400FF080UL
#define DRVGPIO_PORT_D_ADDRESS          0x400FF0C0UL
#define DRVGPIO_PORT_E_ADDRESS          0x400FF100UL


#define DRVGPIO_PORT_A_PDDR_CONFIG_HS   0x0000480CUL
#define DRVGPIO_PORT_A_PIDR_CONFIG_HS   0x00023300UL
#define DRVGPIO_PORT_B_PDDR_CONFIG_HS   0x00000024UL
#define DRVGPIO_PORT_B_PIDR_CONFIG_HS   0x000000D0UL
#define DRVGPIO_PORT_C_PDDR_CONFIG_HS   0x0000BCC8UL
#define DRVGPIO_PORT_C_PIDR_CONFIG_HS   0x00034007UL
#define DRVGPIO_PORT_D_PDDR_CONFIG_HS   0x00010008UL
#define DRVGPIO_PORT_D_PIDR_CONFIG_HS   0x00001080UL
#define DRVGPIO_PORT_E_PDDR_CONFIG_HS   0x00000542UL
#define DRVGPIO_PORT_E_PIDR_CONFIG_HS   0x00018100UL

#define DRVGPIO_PORT_A_PDDR_CONFIG_LS   0x0000480CUL
#define DRVGPIO_PORT_A_PIDR_CONFIG_LS   0x00023300UL
#define DRVGPIO_PORT_B_PDDR_CONFIG_LS   0x00000024UL
#define DRVGPIO_PORT_B_PIDR_CONFIG_LS   0x000000D0UL
#define DRVGPIO_PORT_C_PDDR_CONFIG_LS   0x0000BCC8UL
#define DRVGPIO_PORT_C_PIDR_CONFIG_LS   0x00034007UL
#define DRVGPIO_PORT_D_PDDR_CONFIG_LS   0x00018008UL
#define DRVGPIO_PORT_D_PIDR_CONFIG_LS   0x00001080UL
#define DRVGPIO_PORT_E_PDDR_CONFIG_LS   0x00000142UL
#define DRVGPIO_PORT_E_PIDR_CONFIG_LS   0x00018100UL


#define DRVGPIO_PIN_00_MASK             0x00000001UL
#define DRVGPIO_PIN_01_MASK             0x00000002UL
#define DRVGPIO_PIN_02_MASK             0x00000004UL
#define DRVGPIO_PIN_03_MASK             0x00000008UL
#define DRVGPIO_PIN_04_MASK             0x00000010UL
#define DRVGPIO_PIN_05_MASK             0x00000020UL
#define DRVGPIO_PIN_06_MASK             0x00000040UL
#define DRVGPIO_PIN_07_MASK             0x00000080UL
#define DRVGPIO_PIN_08_MASK             0x00000100UL
#define DRVGPIO_PIN_09_MASK             0x00000200UL
#define DRVGPIO_PIN_10_MASK             0x00000400UL
#define DRVGPIO_PIN_11_MASK             0x00000800UL
#define DRVGPIO_PIN_12_MASK             0x00001000UL
#define DRVGPIO_PIN_13_MASK             0x00002000UL
#define DRVGPIO_PIN_14_MASK             0x00004000UL
#define DRVGPIO_PIN_15_MASK             0x00008000UL
#define DRVGPIO_PIN_16_MASK             0x00010000UL
#define DRVGPIO_PIN_17_MASK             0x00020000UL


#define DRVGPIO_STATE_LOW               0UL
#define DRVGPIO_STATE_HIGH              1UL


#define DRVGPIO_OVSP_HS_ID              0UL
#define DRVGPIO_OVSP_LS_ID              1UL
#define DRVGPIO_OVSP_SIDE_NB            2UL

#define DRVGPIO_IO_MAX_NB               12UL

#define DRVGPIO_FIRST_INPUT             DRVGPIO_IN_DININHIB
#define DRVGPIO_LAST_INPUT              DRVGPIO_IN_OSARM_FB

#define DRVGPIO_FIRST_OUTPUT            DRVGPIO_OUT_CAM_CMD1
#define DRVGPIO_LAST_OUTPUT             DRVGPIO_OUT_DISCRETE_TEST


#define DRVGPIO_BIT_0_MASK              0x00000001UL


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t S_PDOR;
   uint32_t S_PSOR;
   uint32_t S_PCOR;
   uint32_t S_PTOR;
   uint32_t S_PDIR;
   uint32_t S_PDDR;
   uint32_t S_PIDR;
} TS_DrvGPIO_Registers;

typedef struct
{
   uint32_t S_PDDR_Config;
   uint32_t S_PIDR_Config;
} TS_DrvGPIO_Port_Config;

typedef struct
{
   uint32_t S_Port_Id;
   uint32_t S_Pin_Number;
   uint32_t S_Pin_Mask;
   uint32_t S_Idle_State;
   uint32_t S_Active_State;
} TS_DrvGPIO_IO_Config;


/* ---------- provided constants: ------------------------------------------- */
extern TS_DrvGPIO_Registers * const C_DrvGPIO_Registers [DRVGPIO_MAX_PORTS_NB];

extern const TS_DrvGPIO_Port_Config C_DrvGPIO_Port_Config [DRVGPIO_OVSP_SIDE_NB] [DRVGPIO_MAX_PORTS_NB];

extern const TS_DrvGPIO_IO_Config C_DrvGPIO_IO_Config [DRVGPIO_IO_MAX_NB];


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
/* None */


#endif /* DRVGPIO_PRIVATE_H */
