#ifndef BOOT_PBIT_private_H
#define BOOT_PBIT_private_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"
#include "CMN_CARTRIDGE_public.h"

#include "LIBUTI_COMMON.h"
#include "LIBUTI_SHA.h"
#include "LIBUTI_ARINC_665.h"
#include "LIBUTI_AES.h"
#include "LIBUTI_SIF.h"

#include "BOOT_LIBMEM_public.h"
#include "BOOT_LIBCHK_public.h"

/* ---------- internal define constants: ------------------------------------ */

#define K_CCSR_SPI_BASE_ADDRESS              0xFF707000

#define K_MAX_NUMBER_OF_SECONDARY_LOAD         10 // Add from BOOT_Consts.h
#define K_LOAD_NAME_MAX_LENGTH                 (uint32_t)60 // Add from BOOT_Types.h
#define K_LOAD_PN_LENGTH                       15 // Add from BOOT_Consts.h
#define K_MAX_NUMBER_OF_DATA_FILES             50
#define K_MAX_NUMBER_OF_SUPPORT_FILES          10
#define K_MAX_NUMBER_OF_FILES                  ( K_MAX_NUMBER_OF_DATA_FILES + K_MAX_NUMBER_OF_SUPPORT_FILES + 1 ) /*+1 for the LUH*/
#define K_MAX_NUMBER_OF_COMPAT_RULES           10
#define K_MAX_NUMBER_OF_TARGET_HW_IDS          10

#define K_LUH_MAX_LENGTH                  25374
#define K_SIF_HEADER_MAX_LENGTH           0x2000
#define K_AES_KEY_MAX_LENGTH              0x100
#define K_CMP_MAX_LENGTH                  ( 104 + K_MAX_NUMBER_OF_COMPAT_RULES * 72 )
#define K_SUP_MAX_LENGTH                  ( 6 + K_MAX_NUMBER_OF_DATA_FILES * 74 )
#define K_LUD_MAX_LENGTH                  ( 8 + K_MAX_NUMBER_OF_SECONDARY_LOAD * 72 )
#define FLASH_INTEGRITY_CHECK_LUP_BUFFER_SIZE   0x4000
#define K_MRAM_AESKEY_ZONE_OFFSET         0x00040000
#define K_MRAM_LOG_SIZE (sizeof(TS_BOOT_MRAM_LogHW_Word) + sizeof(TS_BOOT_LogLoadsStatus) + sizeof(uint32_t))

/*TEMPORARY*/
#define TEMPORARY_RAM_PLD_SIM_ZONE_FLASH_OFFSET 0x03FE0000
#define TEMPORARY_RAM_PLD_SIM_AES_MASK_OFFSET 0xDC00
/*\TEMPORARY*/

/* ---------- internal types: ----------------------------------------------- */

/* Structure of an MPU entry */
typedef struct
{
   uint32_t s_mas0;
   uint32_t s_mas1;
   uint32_t s_mas2;
   uint32_t s_mas3;
} ts_MPU_ENTRY;

/* Structure defining the status of a primary or secondary load */
typedef struct
{
   uint8_t                 Name[K_LOAD_NAME_MAX_LENGTH];
   uint8_t                 PartNumberSize;
   uint8_t                 PartNumber[K_LOAD_PN_LENGTH];
   te_CMN_FLAG_QUESTION    Corrupted;
   te_CMN_FLAG_QUESTION    OutOfOperationalCondition;
   te_CMN_FLAG_QUESTION    Incompatible;
   uint32_t                CRC_32;
}
TS_LoadStatus;

typedef struct
{
   uint32_t Corrupted                 : 1;
   uint32_t OutOfOperationalCondition : 1;
   uint32_t Incompatible              : 1;
   uint32_t                           : 29;
}__attribute__((packed)) TS_BOOT_LogLoadStatusBitField;

typedef struct
{
   uint8_t                       Name[K_LOAD_NAME_MAX_LENGTH];
   uint8_t                       PartNumberSize;
   uint8_t                       PartNumber[K_LOAD_PN_LENGTH];
   TS_BOOT_LogLoadStatusBitField BitField;
   uint32_t                      CRC_32;
}__attribute__((packed)) TS_BOOT_LogLoadStatus;

typedef struct
{
   TS_BOOT_LogLoadStatus   PrimaryLoadStatus;
   uint32_t                NumberOfSecondaryLoads;
   TS_BOOT_LogLoadStatus   SecondaryLoadsStatus[K_MAX_NUMBER_OF_SECONDARY_LOAD];
}__attribute__((packed)) TS_BOOT_LogLoadsStatus;

typedef struct
{
   TS_BOOT_LogLoadsStatus LoadsStatus;
   /* [TODO] add a field for CMPU check status (one subfield per core)*/
   /* [TODO] add a field for BIST */
}__attribute__((packed)) TS_BOOT_SDRAM_Log;

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal datas: ----------------------------------------------- */
extern uint8_t * LUH_Buffer;
extern uint8_t * SIF_HeaderBuffer;
extern uint8_t * FlashIntegrityCheckLUP_Buffer;
extern uint8_t * AES_KeyBuffer;
extern uint8_t * AES_MaskBuffer;

extern TS_ARINC_665_FileInfo ARINC_665_FilesInfoBuffer[K_MAX_NUMBER_OF_FILES];
extern TS_FileInfo FilesInfoBuffer[K_MAX_NUMBER_OF_FILES];

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */

extern void BOOT_PBIT_SW_SELF_INTEGRITY (void);

extern void BOOT_PBIT_SW_SELECT_LOAD(
   /*OUT*/
   te_CMN_FLAG_QUESTION *  LoadFailed,
   te_CMN_FLAG_QUESTION *  FlashReadFailed,
   uint8_t **              LoadedSoftwareLaunchAddress,
   TS_LoadStatus *         PrimaryLoadStatus,
   uint32_t *              NumberOfSecondaryLoads,
   TS_LoadStatus*          SecondaryLoadsStatus
);

extern void BOOT_PBIT_SW_LOAD(
   /*IN*/
   uint8_t *               BOOT_Name,
   uint32_t                BOOT_NumberOfCompatibilityRules,
   TS_CompatibilityRule *  BOOT_CompatibilityRules,
   uint8_t *               PrimaryLoadLUH_FlashAddress,
   uint8_t *               PrimaryLoadSIF_HeaderENVM_Address,
   /*OUT*/
   te_CMN_FLAG_QUESTION *  LoadFailed,
   te_CMN_FLAG_QUESTION *  FlashReadFailed,
   uint8_t **              LoadedSoftwareLaunchAddress,
   TS_LoadStatus *         PrimaryLoadStatus,
   uint32_t *              NumberOfSecondaryLoads,
   TS_LoadStatus *         SecondaryLoadsStatus
);

extern void BOOT_PBIT_SW_PrimaryLoad(
   /*IN*/
   uint8_t *               BOOT_Name,
   uint32_t                BOOT_NumberOfCompatibilityRules,
   TS_CompatibilityRule *  BOOT_CompatibilityRules,
   uint8_t *               PrimaryLoadLUH_FlashAddress,
   uint8_t *               PrimaryLoadSIF_HeaderENVM_Address,
   /*OUT*/
   uint8_t *               PrimaryLoadName,
   uint32_t *              PrimaryLoadNumberOfCompatibilityRules,
   TS_CompatibilityRule *  PrimaryLoadCompatibilityRules,
   uint32_t *              NumberOfSecondaryLoads,
   TS_SecondaryLoadInfo *  SecondaryLoadsInfo,
   te_CMN_FLAG_QUESTION *  LoadFailed,
   te_CMN_FLAG_QUESTION *  FlashReadFailed,
   uint8_t **              LoadedSoftwareLaunchAddress,
   TS_LoadStatus *         PrimaryLoadStatus
);

void BOOT_PBIT_SW_SecondaryLoad(
   /*IN*/
   uint8_t *               PrimaryLoadName,
   uint32_t                PrimaryLoadNumberOfCompatibilityRules,
   TS_CompatibilityRule *  PrimaryLoadCompatibilityRules,
   TS_SecondaryLoadInfo *  LoadInfo,
   /*OUT*/
   te_CMN_FLAG_QUESTION *  FlashReadFailed,
   TS_LoadStatus *         LoadStatus
);

extern void BOOT_PBIT_SW_RECORD(
   /*OUT*/
   TS_LoadStatus *      PrimaryLoadStatus,
   /*IN*/
   uint32_t             NumberOfSecondaryLoads,
   /*OUT*/
   TS_LoadStatus *      SecondaryLoadsStatus
);

extern void BOOT_PBIT_SW_GetFilesHASH_FromSIF_Header(
   /*IN*/
   const uint8_t * const         SIF_HeaderAddress,
   const uint32_t                NumberOfFiles,
   const te_CMN_FLAG_QUESTION    SIF_FileFound,
   const TS_FileInfo * const     SIF_FileInfo,
   /*INOUT*/
   TS_FileInfo * const           FilesInfo,
   /*OUT*/
   te_CMN_FLAG_QUESTION * const  OutOfOperationalConditionSIF,
   TE_LIBUTI_SIF_check_algorithm * p_SIF_hashmode
);

extern te_CMN_FLAG_QUESTION BOOT_PBIT_ComputeHash(
   /* Input(s) parameter(s) */
   const TE_LIBUTI_SIF_check_algorithm * const p_SIF_hash_algo,
   /* InputOutput(s) parameter(s) */
   TS_FileInfo * const                         p_FileInfo,
   /* Output(s) parameter(s) */
   TS_LoadStatus *                             p_LoadStatus
);

extern te_CMN_FLAG_QUESTION BOOT_PBIT_ComputeCRC32(
   /* InputOutput(s) parameter(s) */
   TS_FileInfo * const                         p_FileInfo,
   /* Output(s) parameter(s) */
   TS_LoadStatus *                             p_LoadStatus
);


#endif /* BOOT_PBIT_private_H */
