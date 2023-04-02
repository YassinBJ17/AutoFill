#include "DrvMCM_Public.h"
#include "DrvMCM_Private.h"
#include "MCP_Types.h"
#include "DrvCPU_Public.h"
#include "OVSP_SW_Public.h"

 void DrvMCM_Check_CBIT_FPU_IRQ (void) {    uint32_t v_FPU_int_flags;    v_FPU_int_flags = C_DrvMCM_Registers->S_ISCR;    DrvCPU_Init_FPSCR_Reg ();    if (DRVMCM_ISCR_FIOC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FIOC_MASK))    {       V_DrvMCM_CBIT_FPU_FIOC_status = OVSP_SW_RESULT_FAILED;       v_FPU_int_flags &= ~DRVMCM_ISCR_FIOCE_MASK;    }    else    {     }    if (DRVMCM_ISCR_FDZC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FDZC_MASK))    {       V_DrvMCM_CBIT_FPU_FDZC_status = OVSP_SW_RESULT_FAILED;       v_FPU_int_flags &= ~DRVMCM_ISCR_FDZCE_MASK;    }    else    {     }    if (DRVMCM_ISCR_FOFC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FOFC_MASK))    {       V_DrvMCM_CBIT_FPU_FOFC_status = OVSP_SW_RESULT_FAILED;       v_FPU_int_flags &= ~DRVMCM_ISCR_FOFCE_MASK;    }    else    {     }    if (DRVMCM_ISCR_FUFC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FUFC_MASK))    {       V_DrvMCM_CBIT_FPU_FUFC_status = OVSP_SW_RESULT_FAILED;       v_FPU_int_flags &= ~DRVMCM_ISCR_FUFCE_MASK;    }    else    {     }    if (DRVMCM_ISCR_FIDC_MASK == (v_FPU_int_flags & DRVMCM_ISCR_FIDC_MASK))    {       V_DrvMCM_CBIT_FPU_FIDC_status = OVSP_SW_RESULT_FAILED;       v_FPU_int_flags &= ~DRVMCM_ISCR_FIDCE_MASK;    }    else    {     }    C_DrvMCM_Registers->S_ISCR = v_FPU_int_flags;    DrvCPU_Init_FPU_Sn_Reg (); }
