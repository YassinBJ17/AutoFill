#include "DrvFTM_Private.h"
#include "DrvFTM_Public.h"
#include "Boot_Public.h"
#include "OVSP_Public.h"
#include "MCP_Types.h"

 void DrvFTM_Stop_NTLOS2_Acquisition (void) {    volatile TS_DrvFTM_Registers * pt_FLEXTIMER3 =       C_DrvFTM_Controller [DRVFTM_TIMER_3];    pt_FLEXTIMER3->S_CONTROLS [DRVFTM_CHAN_4].S_CnSC &= ~DRVFTM_CNSC_ELSA_MASK;    pt_FLEXTIMER3->S_CONTROLS [DRVFTM_CHAN_4].S_CnSC &= ~DRVFTM_CNSC_ELSB_MASK; }
