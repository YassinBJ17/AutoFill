#ifndef LIBUTI_A665_PARSELUH_PART3TARGETS_H
#define LIBUTI_A665_PARSELUH_PART3TARGETS_H

#include "LIBUTI_ARINC_665.h"
#include "LIBUTI_A665_ParseLUH.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

#ifdef A665_PART3
TE_ParseLUH_ReturnCode LIBUTI_A665_ParseLUH_Part3Targets(
/*IN*/
    const uint8_t *                                 p_LUH_RAM_Address,
    const uint32_t                                  v_LUH_Length,
    const TS_LUH_ConstantSizeFirstFields * const    p_LUH_ConstantSizeFirstFields,
    const uint32_t                                  v_MaxNumberOfTargetHW_IDs_WithPositions,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
    uint32_t * const                                p_NumberOfTargetHW_ID_WithPositions,
    TS_TargetHW_ID_WithPositions * const            p_TargetHW_ID_WithPositions
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
);
#endif

/*==== END =============================================================================*/
#endif
