#ifndef LIBUTI_A665_PARSELUH_INIT_H
#define LIBUTI_A665_PARSELUH_INIT_H

#include "LIBUTI_ARINC_665.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

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
);

/*==== END =============================================================================*/
#endif
