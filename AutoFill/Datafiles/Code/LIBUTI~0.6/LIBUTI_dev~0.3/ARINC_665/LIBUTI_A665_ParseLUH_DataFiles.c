#include "LIBUTI_A665_ParseLUH_DataFiles.h"
#include "Memcpy.h"

TE_ParseLUH_ReturnCode LIBUTI_A665_ParseLUH_DataFiles(
/*IN*/
    const uint8_t *                                 p_LUH_RAM_Address,
    const uint32_t                                  v_LUH_Length,
    const TS_LUH_ConstantSizeFirstFields * const    p_LUH_ConstantSizeFirstFields,
    const uint32_t                                  v_NumberOfDataFiles,
    const uint8_t *                                 p_DataFilesList,
/*IN/OUT*/
    uint32_t * const                                p_FileIterator,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
    TS_ARINC_665_FileInfo * const                   p_FilesInfo,
    const TS_ARINC_665_FileInfo ** const            p_DataFilesInfo
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
    uint32_t  v_index;
    uint32_t  v_FileNameOffset;
    uint32_t  v_FilePN_Offset;
    uint16_t  v_CheckType;
    uint8_t * p_LUH_Iterator;
    uint32_t v_NextFileFieldsGroupOffset;

/*Get data files info*/
    p_LUH_Iterator = (uint8_t*)((uint32_t)p_DataFilesList + 2ul); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */
/* {{RELAX<SYNCHRONe_C_Code_17.4> Need to access the table dynamically as size is not known at compile time */
    *p_DataFilesInfo = &(p_FilesInfo[0]); /* %RELAX<SYNCHRONe_C_Code_10.7> Using as memory address */
    for ( v_index = 0ul; v_index < v_NumberOfDataFiles; v_index++ )
    {
#ifndef A665_NODATA_ADDR
        p_FilesInfo[v_index].Address = (uint8_t*) *p_FileIterator; /* %RELAX<SYNCHRONe_C_Code_10.7> Using as memory address */
#else
        p_FilesInfo[v_index].Address = NULL;
#endif
        p_FilesInfo[v_index].NameLength = *((uint16_t*)(p_LUH_Iterator + 2ul)); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
        if ( p_FilesInfo[v_index].NameLength > (uint16_t)C_FILE_NAME_MAX_LENGTH )
        {
            return ( E_LIBUTI_PARSE_LUH_KO_D_FILE_NAME_LEN );
        }

        LibC_Memcpy( 
            p_FilesInfo[v_index].Name,
            (uint8_t*)((uint32_t)p_LUH_Iterator + 2ul + 2ul), /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */
            (uint32_t)p_FilesInfo[v_index].NameLength );

        v_FileNameOffset = (uint32_t)p_FilesInfo[v_index].NameLength + ((uint32_t)p_FilesInfo[v_index].NameLength % 2ul);

        p_FilesInfo[v_index].PN_Length = *((uint16_t*)(p_LUH_Iterator + 2ul + 2ul + v_FileNameOffset)); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
        if ( p_FilesInfo[v_index].PN_Length > (uint16_t)C_PN_MAX_LENGTH )
        {
            return ( E_LIBUTI_PARSE_LUH_KO_D_FILE_NAME_LEN );
        }

        LibC_Memcpy(
            p_FilesInfo[v_index].PN,
            (uint8_t*)((uint32_t)p_LUH_Iterator + 2ul + 2ul + v_FileNameOffset + 2ul), /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */
            (uint32_t)p_FilesInfo[v_index].PN_Length );

        v_FilePN_Offset = (uint32_t)p_FilesInfo[v_index].PN_Length + ((uint32_t)p_FilesInfo[v_index].PN_Length % 2ul);

        p_FilesInfo[v_index].LengthInWords = *(uint32_t*)((uint32_t)p_LUH_Iterator + 2ul + 2ul + v_FileNameOffset + 2ul + v_FilePN_Offset); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
        p_FilesInfo[v_index].ExpectedCRC16 = *(uint16_t*)((uint32_t)p_LUH_Iterator + 2ul + 2ul + v_FileNameOffset + 2ul + v_FilePN_Offset + 4ul); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
#ifdef A665_PART3
        if (p_LUH_ConstantSizeFirstFields->s_LoadFileFormatVersion == C_LOAD_FILE_FORMAT_VERSION_3)
        {
            p_FilesInfo[v_index].Length = *(uint64_t*)((uint32_t)p_LUH_Iterator + 2ul + 2ul + v_FileNameOffset + 2ul + v_FilePN_Offset + 4ul + 2ul); /* %RELAX<SYNCHRONe_C_Code_10.3,SYNCHRONe_C_Code_11.1> Reading value in memory */
            p_FilesInfo[v_index].CheckValueLength = *(uint16_t*)((uint32_t)p_LUH_Iterator + 2ul + 2ul + v_FileNameOffset + 2ul + v_FilePN_Offset + 4ul + 2ul + 8ul); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
            if ( p_FilesInfo[v_index].CheckValueLength > (uint16_t)C_LOAD_CHECK_VALUE_MAX_LENGTH )
            {
                return ( E_LIBUTI_PARSE_LUH_KO_D_FILE_CHK_LEN );
            }
            if (p_FilesInfo[v_index].CheckValueLength > (uint16_t)0)
            {
                p_FilesInfo[v_index].CheckValueLength -= (uint16_t)4;
                v_CheckType = *(uint16_t*)((uint32_t)p_LUH_Iterator + 2ul + 2ul + v_FileNameOffset + 2ul + v_FilePN_Offset + 4ul+ 2ul + 8ul + 2ul); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
                if (v_CheckType < (uint16_t)E_LIBUTI_PARSE_LUH_CHKVAL_UNKNOWN) /* %RELAX<SYNCHRONe_C_Code_10.7> No loss of precision here, this test ensure convertion is valid */
                {
                    p_FilesInfo[v_index].CheckValueType = (TE_ParseLUH_CheckValueType) v_CheckType;
                }
                else
                {
                    p_FilesInfo[v_index].CheckValueType = E_LIBUTI_PARSE_LUH_CHKVAL_UNKNOWN;
                }
                LibC_Memcpy(
                    p_FilesInfo[v_index].CheckValue,
                    (uint8_t*)((uint32_t)p_LUH_Iterator + 2ul + 2ul + v_FileNameOffset + 2ul + v_FilePN_Offset + 4ul + 2ul + 8ul + 2ul + 2ul), /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
                    (uint32_t)p_FilesInfo[v_index].CheckValueLength );
            }
            else
            {
                p_FilesInfo[v_index].CheckValueType = E_LIBUTI_PARSE_LUH_CHKVAL_EMPTY;
            }
        }
        else
        {
            p_FilesInfo[v_index].Length = (uint64_t)(p_FilesInfo[v_index].LengthInWords * 2ul);
            p_FilesInfo[v_index].CheckValueLength = (uint16_t)0;
            p_FilesInfo[v_index].CheckValueType = E_LIBUTI_PARSE_LUH_CHKVAL_EMPTY;
        }
#else
        p_FilesInfo[v_index].Length = (uint64_t)(p_FilesInfo[v_index].LengthInWords * 2ul);
#endif
        v_NextFileFieldsGroupOffset = ((uint32_t)*((uint16_t*)p_LUH_Iterator)) * 2ul; /* %RELAX<SYNCHRONe_C_Code_11.1> Reading value in memory */
        if ( ( v_NextFileFieldsGroupOffset > ( v_LUH_Length - ( (uint32_t)p_LUH_Iterator - (uint32_t)p_LUH_RAM_Address ) ) ) /* %RELAX<SYNCHRONe_C_Code_11.1> Using as memory address */
          || ( ( v_NextFileFieldsGroupOffset == 0ul ) && ( v_index != (v_NumberOfDataFiles - 1ul) ) ) )
        {
            return ( E_LIBUTI_PARSE_LUH_KO_D_FILE_POINTER );
        }
        else
        {
            p_LUH_Iterator = (uint8_t*)((uint32_t)p_LUH_Iterator + v_NextFileFieldsGroupOffset); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */
#ifndef A665_NODATA_ADDR
            *p_FileIterator = *p_FileIterator + (uint32_t)p_FilesInfo[v_index].Length; /* %RELAX<SYNCHRONe_C_Code_10.7> Those addresses will always fit in uint32_t by design */
#if A665_ADDR_ALIGN > 1
            if (*p_FileIterator % A665_ADDR_ALIGN)
            {
                *p_FileIterator = *p_FileIterator + (A665_ADDR_ALIGN - (*p_FileIterator % A665_ADDR_ALIGN));
            }
#endif
#endif
        }
    }
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
    return ( E_LIBUTI_PARSE_LUH_OK );
}