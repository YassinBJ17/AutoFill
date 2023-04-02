#ifndef _LIBUTI_ARINC_665_
#define _LIBUTI_ARINC_665_

#include "LIBMCP_Types.h"

#define C_FILE_NAME_MAX_LENGTH 60
#define C_PN_MAX_LENGTH 60
#define C_TARGET_HW_ID_MAX_LENGTH 60
#define C_LOAD_CHECK_VALUE_MAX_LENGTH 60
#define C_LOAD_TYPE_ID_MAX_LENGTH 60
#define C_MAX_TARGET_HW_ID_POSITIONS 5
#define C_TARGET_HW_ID_POSITIONS_MAX_LENGTH 60
#define C_LOAD_FILE_FORMAT_VERSION_3 ((uint16_t) 0x8004)
#define C_LOAD_FILE_FORMAT_VERSION_2 ((uint16_t) 0x8003)


#ifdef A665_PART3
typedef enum
{
   E_LIBUTI_PARSE_LUH_CHKVAL_EMPTY = 0,
   E_LIBUTI_PARSE_LUH_CHKVAL_CRC8 = 1,  /* - ARINC665-4 : Deprecated */
   E_LIBUTI_PARSE_LUH_CHKVAL_CRC16 = 2, /* - ARINC665-4 : Deprecated */
   E_LIBUTI_PARSE_LUH_CHKVAL_CRC32 = 3,
   E_LIBUTI_PARSE_LUH_CHKVAL_MD5 = 4,
   E_LIBUTI_PARSE_LUH_CHKVAL_SHA1 = 5,
   E_LIBUTI_PARSE_LUH_CHKVAL_SHA256 = 6,
   E_LIBUTI_PARSE_LUH_CHKVAL_SHA512 = 7,
   E_LIBUTI_PARSE_LUH_CHKVAL_CRC64 = 8,
   E_LIBUTI_PARSE_LUH_CHKVAL_UNKNOWN = 9
} TE_ParseLUH_CheckValueType;
#endif

typedef struct
{
   uint8_t * Address;
   uint32_t  LengthInWords;
   uint64_t  Length;
   uint16_t  ExpectedCRC16;
   uint16_t  NameLength;
   uint8_t   Name[C_FILE_NAME_MAX_LENGTH];
   uint16_t  PN_Length;
   uint8_t   PN[C_PN_MAX_LENGTH];
#ifdef A665_PART3
   uint16_t  CheckValueLength;
   TE_ParseLUH_CheckValueType CheckValueType;
   uint8_t   CheckValue[C_LOAD_CHECK_VALUE_MAX_LENGTH];
#endif
}
TS_ARINC_665_FileInfo;

typedef struct
{
   uint16_t Length;
   uint8_t  TargetHW_ID[C_TARGET_HW_ID_MAX_LENGTH];
}
TS_TargetHW_ID_WithLength;

#ifdef A665_PART3
typedef struct
{
   uint16_t Length;
   uint8_t  Position[C_TARGET_HW_ID_POSITIONS_MAX_LENGTH];
}
TS_TargetHW_ID_Positions;

typedef struct
{
   TS_TargetHW_ID_WithLength  TargetHW_ID_WithLength;
   uint16_t NumberOfTargetHW_ID_Positions;
   TS_TargetHW_ID_Positions TargetHW_ID_Positions[C_MAX_TARGET_HW_ID_POSITIONS];
}
TS_TargetHW_ID_WithPositions;
#endif

typedef enum
{
   E_LIBUTI_PARSE_LUH_OK = 0,
   E_LIBUTI_PARSE_LUH_KO_SIZE = 1,
   E_LIBUTI_PARSE_LUH_KO_VERSION = 2,
   E_LIBUTI_PARSE_LUH_KO_PN_POINTER = 3,
   E_LIBUTI_PARSE_LUH_KO_PN_LEN = 4,
   E_LIBUTI_PARSE_LUH_KO_T_HW_IDS_POINTER = 5,
   E_LIBUTI_PARSE_LUH_KO_NB_T_HW_IDS = 6,
   E_LIBUTI_PARSE_LUH_KO_T_HW_ID_NAME_LEN = 7,
   E_LIBUTI_PARSE_LUH_KO_D_FILE_LIST_POINTER = 8,
   E_LIBUTI_PARSE_LUH_KO_S_FILE_LIST_POINTER = 9,
   E_LIBUTI_PARSE_LUH_KO_NB_FILES = 10,
   E_LIBUTI_PARSE_LUH_KO_D_FILE_POINTER = 11,
   E_LIBUTI_PARSE_LUH_KO_D_FILE_NAME_LEN = 12,
   E_LIBUTI_PARSE_LUH_KO_D_FILE_PN_LEN = 13,
   E_LIBUTI_PARSE_LUH_KO_S_FILE_POINTER = 14,
   E_LIBUTI_PARSE_LUH_KO_S_FILE_NAME_LEN = 15,
   E_LIBUTI_PARSE_LUH_KO_S_FILE_PN_LEN = 16,
#ifdef A665_PART3
   E_LIBUTI_PARSE_LUH_KO_LOADTYPE_POINTER = 17,
   E_LIBUTI_PARSE_LUH_KO_LOADCHK_POINTER = 18,
   E_LIBUTI_PARSE_LUH_KO_T_HW_IDS_WITH_POS_POINTER = 19,
   E_LIBUTI_PARSE_LUH_KO_LOADTYPE_LEN = 20,
   E_LIBUTI_PARSE_LUH_KO_LOADCHK_LEN = 21,
   E_LIBUTI_PARSE_LUH_KO_T_HW_ID_WITH_POS_NAME_LEN = 22,
   E_LIBUTI_PARSE_LUH_KO_T_HW_ID_WITH_POS_NAME_POS_LEN = 23,
   E_LIBUTI_PARSE_LUH_KO_NB_T_HW_IDS_WITH_POS = 24,
   E_LIBUTI_PARSE_LUH_KO_NB_T_HW_IDS_POS = 25,
   E_LIBUTI_PARSE_LUH_KO_D_FILE_CHK_LEN = 26,
   E_LIBUTI_PARSE_LUH_KO_S_FILE_CHK_LEN = 27,
#endif
   E_LIBUTI_PARSE_LUH_KO_UDD_POINTER = 28
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
   boolean_t * const                     p_OutOfOperationalConditionLUH
);

#endif
