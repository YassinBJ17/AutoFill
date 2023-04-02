#include "DrvFTM_Private.h"
#include "DrvFTM_Public.h"
#include "Boot_Public.h"
#include "MCP_Types.h"

 void DrvFTM_Stop(uint32_t p_ftm_id) {    TS_DrvFTM_Registers * pt_ftm_reg;    if (p_ftm_id < DRVFTM_FTM_NUMBER)    {       pt_ftm_reg = C_DrvFTM_Controller[p_ftm_id];       pt_ftm_reg->S_SC &= ~DRVFTM_SC_CLKS_MASK;    } }
