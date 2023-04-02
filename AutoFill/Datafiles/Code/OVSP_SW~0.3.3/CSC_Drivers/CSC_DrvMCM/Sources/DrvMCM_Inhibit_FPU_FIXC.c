#include "DrvMCM_Public.h"
#include "DrvMCM_Private.h"
#include "MCP_Types.h"
#include "DrvCPU_Public.h"
#include "OVSP_SW_Public.h"

 void DrvMCM_Inhibit_FPU_FIXC (void) {    uint32_t v_FPU_int_flags;    v_FPU_int_flags = C_DrvMCM_Registers->S_ISCR;    v_FPU_int_flags &= ~ DRVMCM_ISCR_FIXCE_MASK;    C_DrvMCM_Registers->S_ISCR = v_FPU_int_flags; }
