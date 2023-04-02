#ifndef LIBUTI_A665_PARSELUH_PART3FIELDS_H
#define LIBUTI_A665_PARSELUH_PART3FIELDS_H

#include "LIBUTI_ARINC_665.h"
#include "LIBUTI_A665_ParseLUH.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

#ifdef A665_PART3
TE_ParseLUH_ReturnCode LIBUTI_A665_ParseLUH_Part3Fields(
/*IN*/
    const uint8_t *                                 p_LUH_RAM_Address,
    const uint32_t                                  v_LUH_Length,
    const TS_LUH_ConstantSizeFirstFields * const    p_LUH_ConstantSizeFirstFields,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
    uint16_t * const                                p_LoadCheckValueLength,
    TE_ParseLUH_CheckValueType * const              p_LoadCheckValueType,
    uint8_t * const                                 p_LoadCheckValue,
    uint16_t * const                                p_LoadTypeDescriptionLength,
    uint8_t * const                                 p_LoadTypeDescription,
    uint16_t * const                                p_LoadTypeID
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
);
#endif

/*==== END =============================================================================*/
#endif
