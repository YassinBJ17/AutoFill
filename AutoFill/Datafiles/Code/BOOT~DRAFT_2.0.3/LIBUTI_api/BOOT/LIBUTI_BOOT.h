/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_BOOT.h
 * CSC name   :
 *
 * Description:
 *
 * Configuration management identification:
 *    %full_name:  sknNEXT#1/incl/LIBUTI_BOOT.h/5 %
 *    Creation: FT131472            on Tue May 25 17:36:03 CEST 2021
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/


#ifndef _LIBUTI_BOOT_H_
#define _LIBUTI_BOOT_H_

#if defined(__RTRT__)
#define __attribute__(x_dummy)
#endif

/* ---------- DLD symbol ---------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "LIBMCP_Types.h"
#include "LIBUTI_COMMON.h"
/* ---------- provided define constants: ------------------------------------ */
#define BOOT_LOG_ADDRESS 0x00000008ul
#define BOOT_DESC_ADDRESS 0x00001000ul

#define C_BOOT_MRAM_LOG_COUNTER_ADDRESS       0x00000000ul
#define C_BOOT_MRAM_LOG_SLOTS_BASE_ADDRESS    0x00000400ul
#define C_BOOT_MRAM_LOG_SLOTS_SIZE            0x00000400ul
#define C_BOOT_MRAM_LOG_MAX_NUMBER_OF_SLOTS   8

#define C_LOAD_NAME_MAX_LENGTH 60
#define C_MAX_NUMBER_OF_SECONDARY_LOAD 10
#define C_LOAD_PN_LENGTH 15


#define C_MAX_BOOT_DESCRIPTOR_NUMBER_OF_COMPAT_CRIT 10 
#define C_BOOT_DESCRIPTOR_MAX_NAME_SIZE 60 
#define C_BOOT_DESCRIPTOR_PART_NUMBER_SIZE 15
/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

typedef union
{
      uint32_t HW_WordValue;
      struct{
            uint32_t MRAM_PBIT_Failed                   : 1;
            uint32_t PinProgAccessPBIT_Failed           : 1;
            uint32_t PinProgParityPBIT_Failed           : 1;
            uint32_t PAR_PinProgFlickeringPBIT_Failed   : 1;
            uint32_t LABO_PinProgFlickeringPBIT_Failed  : 1;
            uint32_t DTL_PinProgFlickeringPBIT_Failed   : 1;
            uint32_t ID1_PinProgFlickeringPBIT_Failed   : 1;
            uint32_t ID2_PinProgFlickeringPBIT_Failed   : 1;
            uint32_t Expander2AccessPBIT_Failed         : 1;
            uint32_t                                    : 23;
      }__attribute__((packed)) HW_WordBitField;
} TU_BOOT_SDRAM_LogHW_Word;

typedef union
{
      uint32_t PinProgValue;
      struct{
            uint32_t PAR    : 1;
            uint32_t LABO   : 1;
            uint32_t DTL    : 1;
            uint32_t ID1    : 1;
            uint32_t ID2    : 1;
            uint32_t        : 27;
      }__attribute__((packed)) PinProgBitField;
} TU_BOOT_SDRAM_LogPinProg;

typedef union
{
      uint32_t LoadStatusValue;
      struct{
            uint32_t Corrupted                  : 1;
            uint32_t OutOfOperationalCondition  : 1;
            uint32_t Incompatible               : 1;
            uint32_t                            : 29;
      }__attribute__((packed)) LoadStatusBitField;
} TU_BOOT_LogLoadStatusBitField;

typedef struct
{
    uint8_t Name[C_LOAD_NAME_MAX_LENGTH];
    uint8_t  PartNumberSize;
    uint8_t  PartNumber[C_LOAD_PN_LENGTH];
    TU_BOOT_LogLoadStatusBitField LoadStatus;
    uint32_t CRC_32;
}__attribute__((packed)) TS_BOOT_LogLoadStatus;

typedef struct
{
    TS_BOOT_LogLoadStatus PrimaryLoadStatus;
    uint32_t NumberOfSecondaryLoads;
    TS_BOOT_LogLoadStatus SecondaryLoadsStatus[C_MAX_NUMBER_OF_SECONDARY_LOAD];
}__attribute__((packed)) TS_BOOT_LogLoadsStatus;

typedef struct
{
    TU_BOOT_SDRAM_LogHW_Word HW_Word;
    TU_BOOT_SDRAM_LogPinProg PinProg;
    TS_BOOT_LogLoadsStatus LoadsStatus;
}__attribute__((packed)) TS_BOOT_SDRAM_Log;

typedef union
{
      uint32_t HW_Word_value;
      struct{
            uint32_t SDRAM_ECC_PBIT_Failed              : 1;
            uint32_t L2SRAM_ECC_PBIT_Failed             : 1;
            uint32_t SDRAM_PBIT_Failed                  : 1;
            uint32_t L2SRAM_PBIT_Failed                 : 1;
            uint32_t PLD_WatchdogPBIT_Failed            : 1;
            uint32_t DecrementerIT_PBIT_Failed          : 1;
            uint32_t SchedulingIT_PBIT_Failed           : 1;
            uint32_t FPU_PBIT_Failed                    : 1;
            uint32_t MMU_PBIT_Failed                    : 1;
            uint32_t PinProgAccessPBIT_Failed           : 1;
            uint32_t PinProgParityPBIT_Failed           : 1;
            uint32_t PinProgFlickeringPBIT_Failed       : 1;
            uint32_t PAR_PinProgFlickeringPBIT_Failed   : 1;
            uint32_t LABO_PinProgFlickeringPBIT_Failed  : 1;
            uint32_t DTL_PinProgFlickeringPBIT_Failed   : 1;
            uint32_t ID1_PinProgFlickeringPBIT_Failed   : 1;
            uint32_t ID2_PinProgFlickeringPBIT_Failed   : 1;
            uint32_t FlashReadFailed                    : 1;
            uint32_t ConfRegPBIT_Failed                 : 1;
            uint32_t Expander2AccessPBIT_Failed         : 1;
            uint32_t Spare                              : 12;
      }__attribute__((packed)) HW_WordBitField;
} TU_BOOT_MRAM_LogHW_Word;


typedef struct
{
    TU_BOOT_MRAM_LogHW_Word HW_Word;
    TS_BOOT_LogLoadsStatus LoadsStatus;
    uint32_t Log_Counter;
    uint16_t CRC_16;
}__attribute__((packed)) TS_BOOT_MRAM_Log;


typedef struct{
    uint32_t DescriptorLength;
    uint32_t DescriptorVersion;
    uint32_t DescriptorRevision;
    uint8_t  PartNumberSize;
    uint8_t  PartNumber[C_BOOT_DESCRIPTOR_PART_NUMBER_SIZE];
    uint8_t  HardwareCompatibilityID[C_BOOT_DESCRIPTOR_MAX_NAME_SIZE];
    uint32_t BOOT_CRC32;
    uint8_t* DTL_LoadFlashAddress;
    uint8_t* DTL_LoadSIF_HeaderENVM_Address;
    uint8_t* OpeLoadFlashAddress;
    uint8_t* OpeLoadSIF_HeaderENVM_Address;
    uint32_t NumberOfCompatibilityCriteria;
    TS_CompatibilityRule CompatibilityCriterias[C_MAX_BOOT_DESCRIPTOR_NUMBER_OF_COMPAT_CRIT];
}__attribute__((packed)) TS_BOOT_BootDescriptor;



/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

#endif /* _LIBUTI_BOOT_H_ */ 




