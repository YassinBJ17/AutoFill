#ifndef _BOOT_CLSW_GET_FILES_SHA256_FROM_SIF_HEADER_
#define _BOOT_CLSW_GET_FILES_SHA256_FROM_SIF_HEADER_

#include "BOOT_Consts.h"
#include "LIBUTI_COMMON.h"

void BOOT_CLSW_GetFilesSHA256_FromSIF_Header
(
/*IN*/
   const uint8_t* const p_SIF_HeaderAddress,
   const uint32_t p_NumberOfFiles,
   const boolean_t p_SIF_FileFound,
   const TS_FileInfo* const p_SIF_FileInfo,
/*INOUT*/
   TS_FileInfo p_FilesInfo[C_BOOT_MAX_NUMBER_OF_FILES],
/*OUT*/
   boolean_t* p_OutOfOperationalConditionSIF
);

#endif