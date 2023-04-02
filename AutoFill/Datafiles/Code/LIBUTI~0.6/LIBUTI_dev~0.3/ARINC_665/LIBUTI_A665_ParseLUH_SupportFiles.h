#ifndef LIBUTI_A665_PARSELUH_SUPPORTFILES_H
#define LIBUTI_A665_PARSELUH_SUPPORTFILES_H

#include "LIBUTI_ARINC_665.h"
#include "LIBUTI_A665_ParseLUH.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_ParseLUH_ReturnCode LIBUTI_A665_ParseLUH_SupportFiles(
/*IN*/
    const uint8_t *                                 p_LUH_RAM_Address,
    const uint32_t                                  v_LUH_Length,
    const TS_LUH_ConstantSizeFirstFields * const    p_LUH_ConstantSizeFirstFields,
    const uint32_t                                  v_NumberOfDataFiles,
    const uint32_t                                  v_NumberOfSupportFiles,
    const uint8_t *                                 p_SupportFilesList,
/*IN/OUT*/
    uint32_t * const                                p_FileIterator,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
    TS_ARINC_665_FileInfo * const                   p_FilesInfo,
    const TS_ARINC_665_FileInfo ** const            p_SupportFilesInfo
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
);

/*==== END =============================================================================*/
#endif
