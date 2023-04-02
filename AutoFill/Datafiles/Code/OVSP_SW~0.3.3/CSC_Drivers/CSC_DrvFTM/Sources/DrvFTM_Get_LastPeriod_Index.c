#include "DrvFTM_Private.h"
#include "DrvFTM_Public.h"
#include "Boot_Public.h"
#include "MCP_Types.h"

 uint32_t DrvFTM_Get_LastPeriod_Index (uint32_t p_freq_id) {    uint32_t v_return;    if (p_freq_id < DRVFTM_FREQS_NB)    {       v_return = V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_LastPeriod_Index;    }    return v_return; }
