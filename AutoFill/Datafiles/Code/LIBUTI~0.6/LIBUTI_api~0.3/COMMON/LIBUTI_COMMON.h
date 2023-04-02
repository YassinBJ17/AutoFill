#ifndef _LIBUTI_COMMON_
#define _LIBUTI_COMMON_

#if defined(__RTRT__)
#define __attribute__(x_dummy)
#endif

#include "LIBMCP_Types.h"
#include "LIBUTI_ARINC_665.h"

#include "LIBUTI_SHA.h"



#define C_FILE_NAME_MAX_LENGTH 60
#define C_LOAD_NAME_MAX_LENGTH 60
#define C_AMENDMENT_INFO_MAX_LENGTH 20

#define C_HIGHEST_RELATIVE_PRIORITY 0x00000000
#define C_LOWEST_RELATIVE_PRIORITY 0x00000009

typedef struct{
    uint8_t TargetName[C_FILE_NAME_MAX_LENGTH];
    uint32_t RelativePriority;
    uint32_t Version;
    uint32_t Revision;
}__attribute__((packed)) TS_CompatibilityRule;

typedef struct{
    TS_ARINC_665_FileInfo* ARINC_665_FileInfo;
    uint8_t* Address;
    boolean_t Encrypted;
    uint16_t ExpectedCRC16;

    ts_LIBUTI_SHA_SHA256 ExpectedSHA256;

    uint16_t FileID;
}TS_FileInfo;

typedef struct{
    uint8_t Name[C_LOAD_NAME_MAX_LENGTH];
    uint8_t* FlashAddress;
    uint32_t FlashSectionLength;
    uint8_t* SIF_HeaderENVM_Address;
}__attribute__((packed)) TS_SecondaryLoadInfo;

void LIBUTI_CMN_IdentifySupportFiles
(
/*IN*/
    const uint32_t NumberOfSupportFiles,
    const TS_FileInfo* const SupportFilesInfo,
/*OUT*/
    boolean_t* const CMP_FileFound,
    const TS_FileInfo** const CMP_FileInfo,
    boolean_t* const SUP_FileFound,
    const TS_FileInfo** const SUP_FileInfo,
    boolean_t* const LUD_FileFound,
    const TS_FileInfo** const LUD_FileInfo,
    boolean_t* const SIF_FileFound,
    const TS_FileInfo** const SIF_FileInfo,
    boolean_t* const SKF_FileFound,
    const TS_FileInfo** const SKF_FileInfo,
    boolean_t* const OutOfOperationalConditionLoad
);

void LIBUTI_CMN_ParseCMP
(
/*IN*/
    const uint8_t* const CMP_Address,
    const uint32_t MaxNumberOfCompatibilityRules,
/*OUT*/
    uint8_t* const LoadName,
    uint32_t* const NumberOfCompatibilityRules,
    TS_CompatibilityRule* const CompatibilityRules,
    boolean_t* const LoadLoadedByBoot,
    boolean_t* const LoadCheckedByBootInFlash,
    uint8_t* const AmendmentInfo,   /*20B*/
    uint32_t* const Destination,
    uint32_t* const LoadType,
    boolean_t* const OutOfOperationalConditionCMP
);

void LIBUTI_CMN_TestCompatibilityBetweenLoads
(
/*IN*/
    const uint8_t* const FirstLoadName,
    const uint32_t FirstLoadNumberOfCompatibilityRules,
    const TS_CompatibilityRule* const FirstLoadCompatibilityRules,
    const uint8_t* const SecondLoadName,
    const uint32_t SecondLoadNumberOfCompatibilityRules,
    const TS_CompatibilityRule* const SecondLoadCompatibilityRules,
/*OUT*/
    boolean_t* const LoadsAreIncompatible
);

void LIBUTI_CMN_ParseSUP
(
/*IN*/
    const uint8_t* const SUP_Address,
    const uint32_t NumberOfDataFiles,
/*INOUT*/
    TS_FileInfo* const DataFilesInfo,
/*OUT*/
    boolean_t* const LaunchAddressFound,
    uint8_t** const LaunchAddress,
    boolean_t* const OutOfOperationalConditionSUP
);

void LIBUTI_CMN_ParseLUD
(
/*IN*/
    const uint8_t* const LUD_Address,
    const uint32_t MaxNumberOfSecondaryLoads,
/*OUT*/
    uint32_t* const NumberOfSecondaryLoads,
    TS_SecondaryLoadInfo* SecondaryLoadsInfo,
    boolean_t* const OutOfOperationalConditionLUD
);


#endif