#include "DrvFTFC_Public.h"
#include "DrvFTFC_Private.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 void DrvFTFC_Clear_Flash_Fault (uint32_t * const p_pt_Clear_Status) {    if (DRVFTFC_FERSTAT_DFDIF_MASK == (C_DrvFTFC_Registers->S_FERSTAT & DRVFTFC_FERSTAT_DFDIF_MASK))    {       C_DrvFTFC_Registers->S_FERCNFG = DRVFTFC_FERCNFG_CLEAR_VALUE;       C_DrvFTFC_Registers->S_FERSTAT |= DRVFTFC_FERSTAT_DFDIF_MASK;       if (DRVFTFC_FERSTAT_DFDIF_RESET == (C_DrvFTFC_Registers->S_FERSTAT & DRVFTFC_FERSTAT_DFDIF_MASK))       {          *p_pt_Clear_Status = OVSP_SW_RESULT_OK;       }       else       {          *p_pt_Clear_Status = OVSP_SW_RESULT_FAILED;       }    }    else    {       *p_pt_Clear_Status = OVSP_SW_RESULT_FAILED;    } }
