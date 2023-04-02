#ifndef LIBUTI_A665_PARSELUH_VERSIONPN_H
#define LIBUTI_A665_PARSELUH_VERSIONPN_H

#include "LIBUTI_ARINC_665.h"
#include "LIBUTI_A665_ParseLUH.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_ParseLUH_ReturnCode LIBUTI_A665_ParseLUH_VersionPN(
/*IN*/
    const uint8_t *                                 p_LUH_RAM_Address,
    const uint32_t                                  v_LUH_Length,
    const TS_LUH_ConstantSizeFirstFields * const    p_LUH_ConstantSizeFirstFields,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
    uint16_t * const                                p_LoadPN_Length,
    uint8_t * const                                 p_LoadPN
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
);

/*==== END =============================================================================*/
#endif
