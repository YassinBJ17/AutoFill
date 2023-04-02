/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#include "LIBUTI_A665_ParseLUH_Init.h"
#include "BOOT_LIBMEM_public.h"

void LIBUTI_A665_ParseLUH_Init(
/*IN*/
    const uint32_t                        v_MaxNumberOfFiles,
    const uint32_t                        v_MaxNumberOfTargetHW_IDs,
#ifdef A665_PART3
    const uint32_t                        v_MaxNumberOfTargetHW_IDs_WithPositions,
#endif
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
    uint32_t * const                      p_NumberOfFiles,
    uint32_t * const                      p_NumberOfDataFiles,
    uint32_t * const                      p_NumberOfSupportFiles,
#ifdef A665_PART3
    uint32_t * const                      p_NumberOfTargetHW_ID_WithPositions,
    TS_TargetHW_ID_WithPositions * const  p_TargetHW_ID_WithPositions,
    uint16_t * const                      p_LoadCheckValueLength,
    TE_ParseLUH_CheckValueType * const    p_LoadCheckValueType,
    uint8_t * const                       p_LoadCheckValue,
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
    uint32_t * const                      p_CRC_16_Offset
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
    *p_NumberOfFiles = (uint32_t)0;
    *p_NumberOfDataFiles = (uint32_t)0;
    *p_NumberOfSupportFiles = (uint32_t)0;

    *p_LoadPN_Length = (uint16_t) 0;
    BOOT_LIBMEM_SET( p_LoadPN, (uint8_t) 0, (uint32_t)K_PN_MAX_LENGTH );

    *p_NumberOfTargetHW_IDs = (uint32_t)0;
    BOOT_LIBMEM_SET(
        (uint8_t*)p_TargetHW_IDs_WithLengths, /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using area as buffer to initialize */
        (uint8_t) 0,
        v_MaxNumberOfTargetHW_IDs*sizeof(TS_TargetHW_ID_WithLength) );


    BOOT_LIBMEM_SET(
        (uint8_t*)p_FilesInfo, /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using area as buffer to initialize */
        (uint8_t) 0,
        v_MaxNumberOfFiles * sizeof(TS_ARINC_665_FileInfo) );

    *p_DataFilesInfo = NULL; /* %RELAX<SYNCHRONe_C_Code_10.7> Initialize to NULL no not imply loss of precision */
    *p_SupportFilesInfo = NULL; /* %RELAX<SYNCHRONe_C_Code_10.7> Initialize to NULL no not imply loss of precision */
    *p_LoadExpectedCRC32 = (uint32_t)0x00000000;
    *p_UserDefinedData_Offset = (uint32_t)0;
    *p_CRC_16_Offset = (uint32_t)0;

#ifdef A665_PART3
    /* Target HW ID with Positions */
    *p_NumberOfTargetHW_ID_WithPositions = (uint32_t)0;
    BOOT_LIBMEM_SET(
        (uint8_t*)p_TargetHW_ID_WithPositions, /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using area as buffer to initialize */
        (uint8_t) 0,
        v_MaxNumberOfTargetHW_IDs_WithPositions*sizeof(TS_TargetHW_ID_WithPositions) );

    /* Load Check value */
    *p_LoadCheckValueLength = (uint16_t) 0;
    *p_LoadCheckValueType = E_LIBUTI_PARSE_LUH_CHKVAL_UNKNOWN;
    BOOT_LIBMEM_SET( p_LoadCheckValue, (uint8_t) 0, (uint32_t)K_LOAD_CHECK_VALUE_MAX_LENGTH );

    /* Load Type */
    *p_LoadTypeDescriptionLength = (uint16_t) 0;
    BOOT_LIBMEM_SET( p_LoadTypeDescription, (uint8_t) 0, (uint32_t)K_LOAD_TYPE_ID_MAX_LENGTH );
    *p_LoadTypeID = (uint16_t) 0;
#endif
}