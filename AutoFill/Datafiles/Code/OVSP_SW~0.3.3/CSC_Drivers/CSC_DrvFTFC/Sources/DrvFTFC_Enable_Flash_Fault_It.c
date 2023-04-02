#include "DrvFTFC_Public.h"
#include "DrvFTFC_Private.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 void DrvFTFC_Enable_Flash_Fault_It (uint32_t * const p_pt_Set_Status) {    C_DrvFTFC_Registers->S_FERCNFG |= DRVFTFC_FERCNFG_DFDIE_MASK;    if (DRVFTFC_FERCNFG_DFDIE_MASK == (C_DrvFTFC_Registers->S_FERCNFG & DRVFTFC_FERCNFG_DFDIE_MASK))    {       *p_pt_Set_Status = OVSP_SW_RESULT_OK;    }    else    {       *p_pt_Set_Status = OVSP_SW_RESULT_FAILED;    } }
