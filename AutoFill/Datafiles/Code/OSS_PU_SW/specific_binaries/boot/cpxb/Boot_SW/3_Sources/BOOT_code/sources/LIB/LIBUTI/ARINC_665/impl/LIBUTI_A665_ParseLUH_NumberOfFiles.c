/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#include "LIBUTI_A665_ParseLUH_NumberOfFiles.h"

TE_ParseLUH_ReturnCode LIBUTI_A665_ParseLUH_NumberOfFiles(
/*IN*/
    const uint8_t *                                 p_LUH_RAM_Address,
    const uint32_t                                  v_LUH_Length,
    const TS_LUH_ConstantSizeFirstFields * const    p_LUH_ConstantSizeFirstFields,
    const uint32_t                                  v_MaxNumberOfFiles,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
    uint32_t * const                                p_NumberOfFiles,
    uint32_t * const                                p_NumberOfDataFiles,
    uint32_t * const                                p_NumberOfSupportFiles,
    uint8_t ** const                                p_DataFilesList,
    uint8_t ** const                                p_SupportFilesList
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
    uint32_t  v_DataFileListOffset;
    uint32_t  v_SupportFileListOffset;

    v_DataFileListOffset = p_LUH_ConstantSizeFirstFields->s_PointerToDataFilesList * (uint32_t)2;
    if ( v_DataFileListOffset > v_LUH_Length )
    {
        return ( E_LIBUTI_PARSE_LUH_KO_D_FILE_LIST_POINTER );
    }

    *p_DataFilesList = (uint8_t*)((uint32_t)p_LUH_RAM_Address + v_DataFileListOffset); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */
    *p_NumberOfDataFiles = (uint32_t)(*(uint16_t*)*p_DataFilesList); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */

    v_SupportFileListOffset = p_LUH_ConstantSizeFirstFields->s_PointerToSupportFilesList * (uint32_t)2;
    if ( v_SupportFileListOffset > v_LUH_Length )
    {
        return ( E_LIBUTI_PARSE_LUH_KO_S_FILE_LIST_POINTER );
    }
    *p_SupportFilesList = (uint8_t*)((uint32_t)p_LUH_RAM_Address + v_SupportFileListOffset); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */
    *p_NumberOfSupportFiles = (uint32_t)(*(uint16_t*)*p_SupportFilesList); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */

    *p_NumberOfFiles = *p_NumberOfDataFiles + *p_NumberOfSupportFiles;
    if ( *p_NumberOfFiles > v_MaxNumberOfFiles )
    {
        return ( E_LIBUTI_PARSE_LUH_KO_NB_FILES );
    }

    return ( E_LIBUTI_PARSE_LUH_OK );
}