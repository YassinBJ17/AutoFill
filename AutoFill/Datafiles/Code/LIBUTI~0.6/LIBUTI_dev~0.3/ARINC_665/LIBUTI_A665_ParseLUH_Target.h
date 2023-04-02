#ifndef LIBUTI_A665_PARSELUH_TARGET_H
#define LIBUTI_A665_PARSELUH_TARGET_H

#include "LIBUTI_ARINC_665.h"
#include "LIBUTI_A665_ParseLUH.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_ParseLUH_ReturnCode LIBUTI_A665_ParseLUH_Target(
/*IN*/
    const uint8_t *                                 p_LUH_RAM_Address,
    const uint32_t                                  v_LUH_Length,
    const TS_LUH_ConstantSizeFirstFields * const    p_LUH_ConstantSizeFirstFields,
    const uint32_t                                  v_MaxNumberOfTargetHW_IDs,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
    uint32_t * const                                p_NumberOfTargetHW_IDs,
    TS_TargetHW_ID_WithLength * const               p_TargetHW_IDs_WithLengths
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
);

/*==== END =============================================================================*/
#endif
