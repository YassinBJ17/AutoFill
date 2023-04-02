/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef LIBUTI_A665_PARSELUH_NUMBEROFFILES_H
#define LIBUTI_A665_PARSELUH_NUMBEROFFILES_H

#include "LIBUTI_ARINC_665.h"
#include "LIBUTI_A665_ParseLUH.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

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
);

/*==== END =============================================================================*/
#endif
