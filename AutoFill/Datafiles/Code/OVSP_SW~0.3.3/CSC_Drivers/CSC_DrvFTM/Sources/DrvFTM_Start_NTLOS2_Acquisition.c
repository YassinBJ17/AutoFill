#include "DrvFTM_Private.h"
#include "DrvFTM_Public.h"
#include "Boot_Public.h"
#include "OVSP_Public.h"
#include "MCP_Types.h"

 void DrvFTM_Start_NTLOS2_Acquisition (void) {    volatile TS_DrvFTM_Registers * pt_FLEXTIMER3 =       C_DrvFTM_Controller [DRVFTM_TIMER_3];    uint8_t v_OVSP_Side_Id;    if (0UL ==        ((pt_FLEXTIMER3->S_CONTROLS [DRVFTM_CHAN_4].S_CnSC & DRVFTM_CNSC_ELSA_MASK) >>        DRVFTM_CNSC_ELSA_SHIFT))    {       v_OVSP_Side_Id = Boot_Get_Side_Id ();       switch (v_OVSP_Side_Id)       {          case BOOT_SIDE_ID_HS:          {             pt_FLEXTIMER3->S_CONTROLS [DRVFTM_CHAN_4].S_CnSC |=                ((0UL << DRVFTM_CNSC_ELSA_SHIFT) & DRVFTM_CNSC_ELSA_MASK);             pt_FLEXTIMER3->S_CONTROLS [DRVFTM_CHAN_4].S_CnSC |=                ((1UL << DRVFTM_CNSC_ELSB_SHIFT) & DRVFTM_CNSC_ELSB_MASK);          }          break;          case BOOT_SIDE_ID_LS:          {             pt_FLEXTIMER3->S_CONTROLS [DRVFTM_CHAN_4].S_CnSC |=                ((1UL << DRVFTM_CNSC_ELSA_SHIFT) & DRVFTM_CNSC_ELSA_MASK);             pt_FLEXTIMER3->S_CONTROLS [DRVFTM_CHAN_4].S_CnSC |=                ((1UL << DRVFTM_CNSC_ELSB_SHIFT) & DRVFTM_CNSC_ELSB_MASK);          }          break;          default:          {           }          break;       }    }    else    {     } }
