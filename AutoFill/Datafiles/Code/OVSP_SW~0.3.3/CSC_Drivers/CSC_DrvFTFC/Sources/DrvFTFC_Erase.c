/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Flash memory erase function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTFC_Public.h"
#include "DrvFTFC_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

#include "DrvCPU_Public.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* DrvFTFC_Erase : To erase a specified sector of Flash memory
 *   Inputs:
 *     - p_StartAddr: Start address of the Flash memory sector to erase
 *   Outputs:
 *     - p_pt_Status: Status of the Erase Flash sector operation
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTFC_Erase (const uint32_t p_StartAddr, uint32_t * const p_pt_Status)
{
   uint32_t v_EraseAddr;

   if (((DRVFTFC_FLEXNVM_START_ADDR <= p_StartAddr) && (DRVFTFC_FLEXNVM_END_ADDR >= p_StartAddr)))
   {
      v_EraseAddr = (p_StartAddr & DRVFTFC_FLEXNVM_ADDR_MASK) | DRVFTFC_FLEXNVM_SELECTION;

      /* Wait if operation in progress */
      while (DRVFTFC_FSTAT_CMD_COMPLETED == (C_DrvFTFC_Registers->S_FSTAT & DRVFTFC_FSTAT_CCIF_MASK))
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }

      if (DRVFTFC_FSTAT_NO_ERROR != (C_DrvFTFC_Registers->S_FSTAT & DRVFTFC_FSTAT_ERRORS_MASK))
      {
         C_DrvFTFC_Registers->S_FSTAT = DRVFTFC_FSTAT_ERRORS_MASK;
      }
      else
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }

      C_PtF_DrvCPU_Enter_Crit_Sect ();

      /* {{RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision, the objective is to provide the address */
      /* byte per byte to the registers of byte size. */
      C_DrvFTFC_Registers->S_FCCOB3 = (uint8_t) (v_EraseAddr & OVSP_SW_BYTE_MASK);
      C_DrvFTFC_Registers->S_FCCOB2 = (uint8_t) ((v_EraseAddr >> OVSP_SW_DEC_1BYTE) & OVSP_SW_BYTE_MASK);
      C_DrvFTFC_Registers->S_FCCOB1 = (uint8_t) ((v_EraseAddr >> OVSP_SW_DEC_2BYTES) & OVSP_SW_BYTE_MASK);
      /* }} RELAX<SYNCHRONe_C_Code_10.7> */

      C_DrvFTFC_Registers->S_FCCOB0 = DRVFTFC_FCCOB0_ERASE_CMD;

      C_DrvFTFC_Registers->S_FSTAT = DRVFTFC_FSTAT_LAUNCH_CMD;

      while (DRVFTFC_FSTAT_CMD_COMPLETED == (C_DrvFTFC_Registers->S_FSTAT & DRVFTFC_FSTAT_CCIF_MASK))
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }

      C_PtF_DrvCPU_Exit_Crit_Sect ();

      *p_pt_Status = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Status = OVSP_SW_RESULT_FAILED;
   }
}
