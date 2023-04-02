#ifndef _BOOT_TYPES_
#define _BOOT_TYPES_

#include "LIBMCP_Types.h"
#include "LIBUTI_SHA.h"
#include "BOOT_Consts.h"

typedef struct{
   boolean_t PLD_WatchdogPBIT_Failed;
   boolean_t L2SRAM_PBIT_Failed;
   boolean_t L2SRAM_ECC_PBIT_Failed;
   boolean_t SDRAM_PBIT_Failed;
   boolean_t SDRAM_ECC_PBIT_Failed;
   boolean_t DecrementerIT_PBIT_Failed;
   boolean_t SchedulingIT_PBIT_Failed;
   boolean_t FPU_PBIT_Failed;
   boolean_t MMU_PBIT_Failed;
   boolean_t MRAM_PBIT_Failed;
   boolean_t PinProgAccessPBIT_Failed;
   boolean_t PinProgParityPBIT_Failed;
   boolean_t PinProgFlickeringPBIT_Failed;
   boolean_t PAR_PinProgFlickeringPBIT_Failed;
   boolean_t LABO_PinProgFlickeringPBIT_Failed;
   boolean_t DTL_PinProgFlickeringPBIT_Failed;
   boolean_t ID1_PinProgFlickeringPBIT_Failed;
   boolean_t ID2_PinProgFlickeringPBIT_Failed;
   boolean_t ConfRegPBIT_Failed;
   boolean_t Expander2AccessPBIT_Failed;
} ts_PBIT_Results;

typedef struct{
   boolean_t PAR;
   boolean_t LABO;
   boolean_t DTL;
   boolean_t ID1;
   boolean_t ID2;
} ts_PinProgrammingInputsValues;

typedef struct{
   uint8_t Name[C_BOOT_LOAD_NAME_MAX_LENGTH];
   uint16_t PartNumberSize;
   uint8_t PartNumber[C_BOOT_PN_LENGTH];
   boolean_t Corrupted;
   boolean_t OutOfOperationalCondition;
   boolean_t Incompatible;
   uint32_t CRC_32;
} ts_LoadStatus;

typedef struct 
{
   uint32_t size;
   ts_LIBUTI_SHA_SHA256 sha256;
} ts_BOOT_Data;

#endif