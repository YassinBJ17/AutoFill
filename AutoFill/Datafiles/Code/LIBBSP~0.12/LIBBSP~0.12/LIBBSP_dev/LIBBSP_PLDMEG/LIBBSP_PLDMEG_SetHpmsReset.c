/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PLDMEG_SetHpmsReset.h"

/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_PLDMEG_SetHpmsReset(const boolean_t v_Value)
{
   V_PldMegRegs->reg_hpms_reset = (uint32_t)v_Value;
}

/*==== END =============================================================================*/
