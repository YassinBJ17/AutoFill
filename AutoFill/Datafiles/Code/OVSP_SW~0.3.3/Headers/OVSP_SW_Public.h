/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef OVSP_SW_PUBLIC_H
#define OVSP_SW_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define OVSP_SW_NULL_POINTER ((void*) 0UL)

#define OVSP_SW_NB_BYTE_IN_WORD 2UL
#define OVSP_SW_NB_BYTE_IN_LONG 4UL
#define OVSP_SW_NB_WORD_IN_LONG 2UL

#define OVSP_SW_BYTE_0 0UL
#define OVSP_SW_BYTE_1 1UL
#define OVSP_SW_BYTE_2 2UL
#define OVSP_SW_BYTE_3 3UL

#define OVSP_SW_WORD_0 0UL
#define OVSP_SW_WORD_1 1UL

#define OVSP_SW_LONG_0 0UL
#define OVSP_SW_LONG_1 1UL
#define OVSP_SW_LONG_2 2UL
#define OVSP_SW_LONG_3 3UL

#define OVSP_SW_BYTE_MIN ((uint8_t) 0x00)
#define OVSP_SW_BYTE_MAX ((uint8_t) 0xFF)

#define OVSP_SW_WORD_MIN ((uint16_t) 0x0000)
#define OVSP_SW_WORD_MAX ((uint16_t) 0xFFFF)

#define OVSP_SW_LONG_MIN 0x00000000UL
#define OVSP_SW_LONG_MAX 0xFFFFFFFFUL

#define OVSP_SW_FLOAT_EPS 0.0000001f

#define OVSP_SW_DEC_1BYTE   8UL
#define OVSP_SW_DEC_2BYTES 16UL
#define OVSP_SW_DEC_3BYTES 24UL

#define OVSP_SW_BYTE_MASK 0x000000FFUL
#define OVSP_SW_WORD_MASK 0x0000FFFFUL

#define OVSP_SW_RESULT_OK     0x00000000UL
#define OVSP_SW_RESULT_FAILED 0xFFFFFFFFUL

#define OVSP_SW_CARTRIDGE_STRING_SIZE 16UL


/* ---------- provided types: ----------------------------------------------- */
typedef union
{
   uint32_t U_Value_32BitUint;
   float32_t U_Value_32BitFloat;
} TU_OVSP_SW_Uint32_Float32;

typedef union
{
   uint32_t U_Value_32BitUint;
   uint16_t U_Array_16BitUint [OVSP_SW_NB_WORD_IN_LONG];
} TU_OVSP_SW_Uint32_Uint16;

typedef union
{
   uint32_t U_Value_32BitUint;
   uint8_t U_Array_8BitUint [OVSP_SW_NB_BYTE_IN_LONG];
} TU_OVSP_SW_Uint32_Uint8;

typedef union
{
   uint16_t U_Value_16BitUint;
   uint8_t U_Array_8BitUint [OVSP_SW_NB_BYTE_IN_WORD];
} TU_OVSP_SW_Uint16_Uint8;

typedef enum
{
   E_OVSP_SW_Cmd_Off = 0,
   E_OVSP_SW_Cmd_On = 1
} TE_OVSP_SW_Cmd;

typedef enum
{
   E_OVSP_SW_NotRequested = 0,
   E_OVSP_SW_Requested = 1
} TE_OVSP_SW_Request;

typedef enum
{
   E_OVSP_SW_NCD_Speed = 0,
   E_OVSP_SW_Low_Speed = 1,
   E_OVSP_SW_Running_Speed = 2,
   E_OVSP_SW_Overspeed = 3
} TE_OVSP_SW_Speed_Level;

typedef enum
{
   E_OVSP_SW_NotAuthorized = 0,
   E_OVSP_SW_Authorized = 1
} TE_OVSP_SW_OneSensor_Auth;

typedef struct
{
   uint8_t  S_Project_Name   [OVSP_SW_CARTRIDGE_STRING_SIZE];
   uint8_t  S_System_Name    [OVSP_SW_CARTRIDGE_STRING_SIZE];
   uint8_t  S_Software_Name  [OVSP_SW_CARTRIDGE_STRING_SIZE];
   uint8_t  S_SW_Part_Number [OVSP_SW_CARTRIDGE_STRING_SIZE];
   uint8_t  S_SW_Build_Desc  [OVSP_SW_CARTRIDGE_STRING_SIZE];
   uint32_t S_SW_Presence_Key;
   uint8_t  S_SW_Version_X;
   uint8_t  S_SW_Version_Y;
   uint8_t  S_SW_Version_Z;
   uint8_t  S_SW_CAN_CompatNb;
   uint32_t S_Cartridge_Spare [2];
} TS_OVSP_SW_Cartridge;


/* ---------- provided constants: ------------------------------------------- */
extern const TS_OVSP_SW_Cartridge C_OVSP_SW_Cartridge;


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
/* None */


#endif /* OVSP_SW_PUBLIC_H */
