#include "DrvMCM_Public.h"
#include "DrvMCM_Private.h"
#include "MCP_Types.h"
#include "DrvCPU_Public.h"
#include "OVSP_SW_Public.h"

 void DrvMCM_Reset_ISCR (void) {    C_DrvMCM_Registers->S_ISCR = DRVMCM_ISCR_CONFIG; }
