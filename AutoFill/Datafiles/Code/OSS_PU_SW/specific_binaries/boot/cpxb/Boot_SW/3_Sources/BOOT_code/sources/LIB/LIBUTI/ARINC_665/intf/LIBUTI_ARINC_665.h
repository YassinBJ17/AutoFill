/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef _LIBUTI_ARINC_665_
#define _LIBUTI_ARINC_665_

#include "CMN_TYPES_common.h"

#define K_FILE_NAME_MAX_LENGTH (uint32_t)60
#define K_PN_MAX_LENGTH 60
#define K_TARGET_HW_ID_MAX_LENGTH 60
#define K_LOAD_CHECK_VALUE_MAX_LENGTH 60
#define K_LOAD_TYPE_ID_MAX_LENGTH 60
/* TODO ACHTUNG MARIE A DIT DE NE PAS TOUCHER A 5 SANS LUI DEMANDER */
#define K_MAX_TARGET_HW_ID_POSITIONS 5
#define K_TARGET_HW_ID_POSITIONS_MAX_LENGTH 60
#define K_LOAD_FILE_FORMAT_VERSION_3 ((uint16_t) 0x8004)
#define K_LOAD_FILE_FORMAT_VERSION_2 ((uint16_t) 0x8003)

#ifdef A665_PART3
typedef enum
{
   E_LIBUTI_PARSE_LUH_CHKVAL_EMPTY = 0,
   E_LIBUTI_PARSE_LUH_CHKVAL_CRC8,
   E_LIBUTI_PARSE_LUH_CHKVAL_CRC16,
   E_LIBUTI_PARSE_LUH_CHKVAL_CRC32,
   E_LIBUTI_PARSE_LUH_CHKVAL_MD5,
   E_LIBUTI_PARSE_LUH_CHKVAL_SHA1,
   E_LIBUTI_PARSE_LUH_CHKVAL_SHA256,
   E_LIBUTI_PARSE_LUH_CHKVAL_SHA512,
   E_LIBUTI_PARSE_LUH_CHKVAL_CRC64,
   E_LIBUTI_PARSE_LUH_CHKVAL_UNKNOWN
}
TE_ParseLUH_CheckValueType;
#endif

typedef struct
{
   uint8_t * Address;
   uint32_t  LengthInWords;
   uint64_t  Length;
   uint16_t  ExpectedCRC16;
   uint16_t  NameLength;
   uint8_t   Name[K_FILE_NAME_MAX_LENGTH];
   uint16_t  PN_Length;
   uint8_t   PN[K_PN_MAX_LENGTH];
#ifdef A665_PART3
   uint16_t  CheckValueLength;
   TE_ParseLUH_CheckValueType CheckValueType;
   uint8_t   CheckValue[K_LOAD_CHECK_VALUE_MAX_LENGTH];
#endif
}
TS_ARINC_665_FileInfo;

typedef struct
{
   uint16_t Length;
   uint8_t  TargetHW_ID[K_TARGET_HW_ID_MAX_LENGTH];
}
TS_TargetHW_ID_WithLength;

#ifdef A665_PART3
typedef struct
{
   uint16_t Length;
   uint8_t  Position[K_TARGET_HW_ID_POSITIONS_MAX_LENGTH];
}
TS_TargetHW_ID_Positions;

typedef struct
{
   TS_TargetHW_ID_WithLength  TargetHW_ID_WithLength;
   uint16_t NumberOfTargetHW_ID_Positions;
   TS_TargetHW_ID_Positions TargetHW_ID_Positions[K_MAX_TARGET_HW_ID_POSITIONS];
}
TS_TargetHW_ID_WithPositions;
#endif

typedef enum
{
   E_LIBUTI_PARSE_LUH_OK = 0,
   E_LIBUTI_PARSE_LUH_KO_SIZE,
   E_LIBUTI_PARSE_LUH_KO_VERSION,
   E_LIBUTI_PARSE_LUH_KO_PN_POINTER,
   E_LIBUTI_PARSE_LUH_KO_PN_LEN,
   E_LIBUTI_PARSE_LUH_KO_T_HW_IDS_POINTER,
   E_LIBUTI_PARSE_LUH_KO_NB_T_HW_IDS,
   E_LIBUTI_PARSE_LUH_KO_T_HW_ID_NAME_LEN,
   E_LIBUTI_PARSE_LUH_KO_D_FILE_LIST_POINTER,
   E_LIBUTI_PARSE_LUH_KO_S_FILE_LIST_POINTER,
   E_LIBUTI_PARSE_LUH_KO_NB_FILES,
   E_LIBUTI_PARSE_LUH_KO_D_FILE_POINTER,
   E_LIBUTI_PARSE_LUH_KO_D_FILE_NAME_LEN,
   E_LIBUTI_PARSE_LUH_KO_D_FILE_PN_LEN,
   E_LIBUTI_PARSE_LUH_KO_S_FILE_POINTER,
   E_LIBUTI_PARSE_LUH_KO_S_FILE_NAME_LEN,
   E_LIBUTI_PARSE_LUH_KO_S_FILE_PN_LEN,
#ifdef A665_PART3
   E_LIBUTI_PARSE_LUH_KO_LOADTYPE_POINTER,
   E_LIBUTI_PARSE_LUH_KO_LOADCHK_POINTER,
   E_LIBUTI_PARSE_LUH_KO_T_HW_IDS_WITH_POS_POINTER,
   E_LIBUTI_PARSE_LUH_KO_LOADTYPE_LEN,
   E_LIBUTI_PARSE_LUH_KO_LOADCHK_LEN,
   E_LIBUTI_PARSE_LUH_KO_T_HW_ID_WITH_POS_NAME_LEN,
   E_LIBUTI_PARSE_LUH_KO_T_HW_ID_WITH_POS_NAME_POS_LEN,
   E_LIBUTI_PARSE_LUH_KO_NB_T_HW_IDS_WITH_POS,
   E_LIBUTI_PARSE_LUH_KO_NB_T_HW_IDS_POS,
   E_LIBUTI_PARSE_LUH_KO_D_FILE_CHK_LEN,
   E_LIBUTI_PARSE_LUH_KO_S_FILE_CHK_LEN,
#endif
   E_LIBUTI_PARSE_LUH_KO_UDD_POINTER
}
TE_ParseLUH_ReturnCode;

TE_ParseLUH_ReturnCode LIBUTI_A665_ParseLUH
(
/*IN*/
   const uint8_t *                       p_LUH_RAM_Address,
   const uint8_t *                       p_LoadBaseAddress,
   const uint32_t                        v_MaxNumberOfFiles,
   const uint32_t                        v_MaxNumberOfTargetHW_IDs,
#ifdef A665_PART3
   const uint32_t                        v_MaxNumberOfTargetHW_IDs_WithPositions,
#endif
/*OUT*/
   uint32_t * const                      p_NumberOfFiles,
   uint32_t * const                      p_NumberOfDataFiles,
   uint32_t * const                      p_NumberOfSupportFiles,
#ifdef A665_PART3
   /* Number of target HW ID with positions */
   uint32_t * const                      p_NumberOfTargetHW_ID_WithPositions,
   TS_TargetHW_ID_WithPositions * const  p_TargetHW_ID_WithPositions,
   /* Load Check Value */
   uint16_t * const                      p_LoadCheckValueLength,
   TE_ParseLUH_CheckValueType * const    p_LoadCheckValueType,
   uint8_t * const                       p_LoadCheckValue,
   /* Load Type */
   uint16_t * const                      p_LoadTypeDescriptionLength,
   uint8_t * const                       p_LoadTypeDescription,
   uint16_t * const                      p_LoadTypeID,
#endif
   TS_ARINC_665_FileInfo * const         p_FilesInfo,
   const TS_ARINC_665_FileInfo ** const  p_DataFilesInfo,
   const TS_ARINC_665_FileInfo ** const  p_SupportFilesInfo,
   uint32_t * const                      p_LoadExpectedCRC32,
   uint16_t * const                      p_LoadPN_Length,
   uint8_t * const                       p_LoadPN,
   uint32_t * const                      p_NumberOfTargetHW_IDs,
   TS_TargetHW_ID_WithLength * const     p_TargetHW_IDs_WithLengths,
   uint32_t * const                      p_UserDefinedData_Offset,
   uint32_t * const                      p_CRC_16_Offset,
   te_CMN_FLAG_QUESTION * const          p_OutOfOperationalConditionLUH
);

#endif
