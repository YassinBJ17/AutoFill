#include "DrvFTM_Private.h"
#include "DrvFTM_Public.h"
#include "Boot_Public.h"
#include "MCP_Types.h"

 void DrvFTM_Stop_TSpeed_HS (void) {    C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC &= ~DRVFTM_CNSC_ELSA_MASK;    C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC &= ~DRVFTM_CNSC_ELSB_MASK;    C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_1].S_CnV = 0x0;    C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_MOD = 0x0;    C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_SC &=~DRVFTM_SC_CLKS_MASK;    C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC = 0;    DrvFTM_Stop (1); }
