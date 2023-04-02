/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef _LIBUTI_COMMON_
#define _LIBUTI_COMMON_

#include "CMN_TYPES_common.h"
#include "LIBUTI_ARINC_665.h"

#define K_FILE_NAME_MAX_LENGTH      (uint32_t)60
#define K_LOAD_NAME_MAX_LENGTH      (uint32_t)60
#define K_LOAD_NAME_MAX_LENGTH_CMP  (uint32_t)32
#define K_AMENDMENT_INFO_MAX_LENGTH (uint32_t)20

#define K_HIGHEST_RELATIVE_PRIORITY 0x00000000
#define K_LOWEST_RELATIVE_PRIORITY 0x00000009

typedef struct
{
   uint8_t  TargetName[K_LOAD_NAME_MAX_LENGTH_CMP];
   uint32_t Major;
   uint32_t Minor;
}
__attribute__((packed)) TS_CompatibilityRule;

typedef struct
{
   TS_ARINC_665_FileInfo * ARINC_665_FileInfo;
   uint8_t *               Address;
   te_CMN_FLAG_QUESTION    Encrypted;
   uint16_t                ExpectedCRC16;
   uint8_t                 ExpectedSHA256[32];
   uint8_t                 ExpectedSHA512[64];
   uint16_t                FileID;
}
TS_FileInfo;

typedef struct
{
   uint8_t     Name[K_LOAD_NAME_MAX_LENGTH];
   uint8_t *   FlashAddress;
   uint32_t    FlashSectionLength;
   uint8_t *   SIF_HeaderENVM_Address;
}
__attribute__((packed)) TS_SecondaryLoadInfo;

extern void LIBUTI_CMN_IdentifySupportFiles
(
   /*IN*/
      const uint32_t                NumberOfSupportFiles,
      const TS_FileInfo *    const  SupportFilesInfo,
   /*OUT*/
      te_CMN_FLAG_QUESTION * const  CMP_FileFound,
      const TS_FileInfo **   const  CMP_FileInfo,
      te_CMN_FLAG_QUESTION * const  SUP_FileFound,
      const TS_FileInfo **   const  SUP_FileInfo,
      te_CMN_FLAG_QUESTION * const  LUD_FileFound,
      const TS_FileInfo **   const  LUD_FileInfo,
      te_CMN_FLAG_QUESTION * const  SIF_FileFound,
      const TS_FileInfo **   const  SIF_FileInfo,
      te_CMN_FLAG_QUESTION * const  SKF_FileFound,
      const TS_FileInfo **   const  SKF_FileInfo,
      te_CMN_FLAG_QUESTION * const  OutOfOperationalConditionLoad
);

extern void LIBUTI_CMN_ParseCMP
(
   /*IN*/
      const uint8_t *        const  CMP_Address,
      const uint32_t                MaxNumberOfCompatibilityRules,
   /*OUT*/
      uint8_t *              const  LoadName,
      uint32_t *             const  NumberOfCompatibilityRules,
      TS_CompatibilityRule * const  CompatibilityRules,
      te_CMN_FLAG_QUESTION * const  OutOfOperationalConditionCMP
);

extern void LIBUTI_CMN_TestCompatibilityBetweenLoads
(
   /*IN*/
      const uint8_t * const               FirstLoadName,
      const uint32_t                      FirstLoadNumberOfCompatibilityRules,
      const TS_CompatibilityRule * const  FirstLoadCompatibilityRules,
      const uint8_t * const               SecondLoadName,
      const uint32_t                      SecondLoadNumberOfCompatibilityRules,
      const TS_CompatibilityRule * const  SecondLoadCompatibilityRules,
   /*OUT*/
      te_CMN_FLAG_QUESTION * const        LoadsAreIncompatible
);

extern void LIBUTI_CMN_ParseSUP
(
   /*IN*/
      const uint8_t * const         SUP_Address,
      const uint32_t                NumberOfDataFiles,
   /*INOUT*/
      TS_FileInfo * const           DataFilesInfo,
   /*OUT*/
      te_CMN_FLAG_QUESTION * const  LaunchAddressFound,
      uint8_t ** const              LaunchAddress,
      te_CMN_FLAG_QUESTION * const  LoadLoadedByBoot,
      te_CMN_FLAG_QUESTION * const  LoadCheckedByBootInFlash,
      uint8_t * const               AmendmentInfo,
      uint32_t * const              Destination,
      uint32_t * const              LoadType,
      te_CMN_FLAG_QUESTION * const  OutOfOperationalConditionSUP
);

extern void LIBUTI_CMN_ParseLUD
(
   /*IN*/
      const uint8_t * const         LUD_Address,
      const uint32_t                MaxNumberOfSecondaryLoads,
   /*OUT*/
      uint32_t * const              NumberOfSecondaryLoads,
      TS_SecondaryLoadInfo *        SecondaryLoadsInfo,
      te_CMN_FLAG_QUESTION * const  OutOfOperationalConditionLUD
);

#endif