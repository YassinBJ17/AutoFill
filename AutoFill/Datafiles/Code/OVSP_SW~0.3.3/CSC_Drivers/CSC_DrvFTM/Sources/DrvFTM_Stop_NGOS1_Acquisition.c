#include "DrvFTM_Public.h"
#include "DrvFTM_Private.h"
#include "Boot_Public.h"
#include "OVSP_Public.h"
#include "MCP_Types.h"

 void DrvFTM_Stop_NGOS1_Acquisition (void) {    volatile TS_DrvFTM_Registers * pt_FLEXTIMER0 =       C_DrvFTM_Controller [DRVFTM_TIMER_0];    pt_FLEXTIMER0->S_CONTROLS [DRVFTM_CHAN_4].S_CnSC &= ~DRVFTM_CNSC_ELSA_MASK;    pt_FLEXTIMER0->S_CONTROLS [DRVFTM_CHAN_4].S_CnSC &= ~DRVFTM_CNSC_ELSB_MASK; }
