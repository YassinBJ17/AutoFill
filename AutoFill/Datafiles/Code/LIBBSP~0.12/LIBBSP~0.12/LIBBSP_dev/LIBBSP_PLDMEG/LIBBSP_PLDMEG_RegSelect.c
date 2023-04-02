/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PLDMEG_RegSelect.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_PLDMEG_RegSelect(const TE_LIBBSP_PLDMEG_RegSelectMode v_Mode)
{
    volatile uint32_t * p_reg_select_address = (volatile uint32_t*)(C_LIBBSP_MEGREG_REGSELECT);

    switch (v_Mode)
    {
    case E_LIBBSP_PLDMEG_INITIALIZATION:
        *p_reg_select_address = C_LIBBSP_PLDMEG_INITIALIZATION_MODE;
        break;
    case E_LIBBSP_PLDMEG_OPERATIONAL:
        *p_reg_select_address = C_LIBBSP_PLDMEG_OPERATIONAL_MODE;
        break;
    case E_LIBBSP_PLDMEG_HRG_CALIBRATION:
        *p_reg_select_address = C_LIBBSP_PLDMEG_HRG_CALIBRATION_MODE;
        break;
    case E_LIBBSP_PLDMEG_IMU_CALIBRATION_RS_DL:
        *p_reg_select_address = C_LIBBSP_PLDMEG_IMU_CALIBRATION_RS_DL_MODE;
        break;
    case E_LIBBSP_PLDMEG_IMU_CALIBRATION_RS_CAL:
        *p_reg_select_address = C_LIBBSP_PLDMEG_IMU_CALIBRATION_RS_CAL_MODE;
        break;
    default:
        break;
    }
    return;
}

/*==== END =============================================================================*/
