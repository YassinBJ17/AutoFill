#include "DrvFTM_Public.h"
#include "DrvFTM_Private.h"
#include "Boot_Public.h"
#include "OVSP_Public.h"
#include "MCP_Types.h"

 void DrvFTM_Stop_CAM_Generation (void) {    volatile TS_DrvFTM_Registers * pt_FLEXTIMER2 =       C_DrvFTM_Controller [DRVFTM_TIMER_2];    pt_FLEXTIMER2->S_CONTROLS [DRVFTM_CHAN_4].S_CnSC &= ~DRVFTM_CNSC_ELSA_MASK;    pt_FLEXTIMER2->S_CONTROLS [DRVFTM_CHAN_4].S_CnSC &= ~DRVFTM_CNSC_ELSA_MASK; }
