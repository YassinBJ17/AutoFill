#include "LIBUTI_A665_ParseLUH.h"
#include "LIBUTI_A665_ParseLUH_DataFiles.h"
#include "LIBUTI_A665_ParseLUH_Init.h"
#include "LIBUTI_A665_ParseLUH_NumberOfFiles.h"
#include "LIBUTI_A665_ParseLUH_Part3.h"
#include "LIBUTI_A665_ParseLUH_SupportFiles.h"
#include "LIBUTI_A665_ParseLUH_Target.h"
#include "LIBUTI_A665_ParseLUH_VersionPN.h"

TE_ParseLUH_ReturnCode LIBUTI_A665_ParseLUH
(
    const uint8_t *                       p_LUH_RAM_Address,
    const uint8_t *                       p_LoadBaseAddress,
    const uint32_t                        v_MaxNumberOfFiles,
    const uint32_t                        v_MaxNumberOfTargetHW_IDs,
    const uint32_t                        v_MaxNumberOfTargetHW_IDs_WithPositions,
    uint32_t * const                      p_NumberOfFiles,
    uint32_t * const                      p_NumberOfDataFiles,
    uint32_t * const                      p_NumberOfSupportFiles,
    uint32_t * const                      p_NumberOfTargetHW_ID_WithPositions,
    TS_TargetHW_ID_WithPositions * const  p_TargetHW_ID_WithPositions,
    uint16_t * const                      p_LoadCheckValueLength,
    TE_ParseLUH_CheckValueType * const    p_LoadCheckValueType,
    uint8_t * const                       p_LoadCheckValue,
    uint16_t * const                      p_LoadTypeDescriptionLength,
    uint8_t * const                       p_LoadTypeDescription,
    uint16_t * const                      p_LoadTypeID,

)
{
    TE_ParseLUH_ReturnCode  v_ret;
    uint32_t  v_LUH_Length;
    TS_LUH_ConstantSizeFirstFields * p_LUH_ConstantSizeFirstFields;

    uint8_t * p_DataFilesList;
    uint8_t * p_SupportFilesList;

    uint32_t  p_FileIterator;

/*Inits*/
    *p_OutOfOperationalConditionLUH = FALSE;

    LIBUTI_A665_ParseLUH_Init(
        v_MaxNumberOfFiles,
        v_MaxNumberOfTargetHW_IDs,
#ifdef A665_PART3
        v_MaxNumberOfTargetHW_IDs_WithPositions,
#endif
        p_NumberOfFiles,
        p_NumberOfDataFiles,
        p_NumberOfSupportFiles,
#ifdef A665_PART3
        p_NumberOfTargetHW_ID_WithPositions,
        p_TargetHW_ID_WithPositions,
        p_LoadCheckValueLength,
        p_LoadCheckValueType,
        p_LoadCheckValue,
        p_LoadTypeDescriptionLength,
        p_LoadTypeDescription,
        p_LoadTypeID,
#endif
        p_FilesInfo,
        p_DataFilesInfo,
        p_SupportFilesInfo,
        p_LoadExpectedCRC32,
        p_LoadPN_Length,
        p_LoadPN,
        p_NumberOfTargetHW_IDs,
        p_TargetHW_IDs_WithLengths,
        p_UserDefinedData_Offset,
        p_CRC_16_Offset
    );

    p_LUH_ConstantSizeFirstFields = (TS_LUH_ConstantSizeFirstFields*)p_LUH_RAM_Address; /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using data in ram as structure for parsing */
    v_LUH_Length = p_LUH_ConstantSizeFirstFields->s_HeaderFileLength * 2ul;
    if ( v_LUH_Length < C_LUH_MIN_SIZE )
    {
        *p_OutOfOperationalConditionLUH = TRUE;
        return ( E_LIBUTI_PARSE_LUH_KO_SIZE );
    }

    v_ret = LIBUTI_A665_ParseLUH_VersionPN(
        p_LUH_RAM_Address,
        v_LUH_Length,
        p_LUH_ConstantSizeFirstFields,
        p_LoadPN_Length,
        p_LoadPN
    );
    if ( v_ret != E_LIBUTI_PARSE_LUH_OK )
    {
        *p_OutOfOperationalConditionLUH = TRUE;
        return ( v_ret );
    }

#ifdef A665_PART3
    v_ret = LIBUTI_A665_ParseLUH_Part3(
        p_LUH_RAM_Address,
        v_LUH_Length,
        p_LUH_ConstantSizeFirstFields,
        v_MaxNumberOfTargetHW_IDs_WithPositions,
        p_NumberOfTargetHW_ID_WithPositions,
        p_TargetHW_ID_WithPositions,
        p_LoadCheckValueLength,
        p_LoadCheckValueType,
        p_LoadCheckValue,
        p_LoadTypeDescriptionLength,
        p_LoadTypeDescription,
        p_LoadTypeID
    );
    if ( v_ret != E_LIBUTI_PARSE_LUH_OK )
    {
        *p_OutOfOperationalConditionLUH = TRUE;
        return ( v_ret );
    }
#endif

    v_ret = LIBUTI_A665_ParseLUH_Target(
        p_LUH_RAM_Address,
        v_LUH_Length,
        p_LUH_ConstantSizeFirstFields,
        v_MaxNumberOfTargetHW_IDs,
        p_NumberOfTargetHW_IDs,
        p_TargetHW_IDs_WithLengths
    );
    if ( v_ret != E_LIBUTI_PARSE_LUH_OK )
    {
        *p_OutOfOperationalConditionLUH = TRUE;
        return ( v_ret );
    }

    v_ret = LIBUTI_A665_ParseLUH_NumberOfFiles(
        p_LUH_RAM_Address,
        v_LUH_Length,
        p_LUH_ConstantSizeFirstFields,
        v_MaxNumberOfFiles,
        p_NumberOfFiles,
        p_NumberOfDataFiles,
        p_NumberOfSupportFiles,
        &p_DataFilesList,
        &p_SupportFilesList
    );
    if ( v_ret != E_LIBUTI_PARSE_LUH_OK )
    {
        *p_OutOfOperationalConditionLUH = TRUE;
        return ( v_ret );
    }

    p_FileIterator = ((uint32_t)p_LoadBaseAddress + v_LUH_Length);  /* %RELAX<SYNCHRONe_C_Code_11.1> Using as memory address */
#if A665_ADDR_ALIGN > 1
    if (p_FileIterator % A665_ADDR_ALIGN)
    {
        p_FileIterator = p_FileIterator + (A665_ADDR_ALIGN - (p_FileIterator % A665_ADDR_ALIGN));
    }
#endif

    v_ret = LIBUTI_A665_ParseLUH_DataFiles(
        p_LUH_RAM_Address,
        v_LUH_Length,
        p_LUH_ConstantSizeFirstFields,
        *p_NumberOfDataFiles,
        p_DataFilesList,
        &p_FileIterator,
        p_FilesInfo,
        p_DataFilesInfo
    );
    if ( v_ret != E_LIBUTI_PARSE_LUH_OK )
    {
        *p_OutOfOperationalConditionLUH = TRUE;
        return ( v_ret );
    }

    v_ret = LIBUTI_A665_ParseLUH_SupportFiles(
        p_LUH_RAM_Address,
        v_LUH_Length,
        p_LUH_ConstantSizeFirstFields,
        *p_NumberOfDataFiles,
        *p_NumberOfSupportFiles,
        p_SupportFilesList,
        &p_FileIterator,
        p_FilesInfo,
        p_SupportFilesInfo
    );
    if ( v_ret != E_LIBUTI_PARSE_LUH_OK )
    {
        *p_OutOfOperationalConditionLUH = TRUE;
        return ( v_ret );
    }

    *p_LoadExpectedCRC32 = *((uint32_t*)((uint32_t)p_LUH_RAM_Address + (v_LUH_Length - 4ul))); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
    *p_CRC_16_Offset = (p_LUH_ConstantSizeFirstFields->s_HeaderFileLength * 2ul) - 6ul;
    *p_UserDefinedData_Offset = (p_LUH_ConstantSizeFirstFields->s_PointerToUserDefinedData * 2ul);
    if ( *p_UserDefinedData_Offset > v_LUH_Length )
    {
        *p_OutOfOperationalConditionLUH = TRUE;
        return ( E_LIBUTI_PARSE_LUH_KO_UDD_POINTER );
    }

    return ( E_LIBUTI_PARSE_LUH_OK );
}
