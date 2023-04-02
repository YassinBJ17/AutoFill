/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_Read.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Public function
 * Read v_NbrBlock block (512 bytes per block) in memory with a DMA transfer.
 * Data are read from v_SectorAddr to v_SectorAddr + v_Length.
 * Parameters : (uint32_t)  v_SectorAddr -> Address to start in FNAND memory
 *              (uint32_t*) p_Data       -> Pointer on data reception
 *              (uint32_t)  v_NbrBlock   -> Number of blocks to read.
 *              (boolean_t) v_Blocking   -> This function is non-blocking if v_Blocking is set to FALSE and blocking if set to TRUE.
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_Read(const uint32_t v_SectorAddr, uint32_t* const p_Data, const uint32_t v_NbrBlock, const boolean_t v_Blocking) /* %RELAX<SYNCHRONe_C_Code_8.18> p_Data is output */
{
   boolean_t v_Status;
   TE_LIBBSP_FNAND_ERROR_OP v_Error;

   (void) LIBBSP_FNAND_GetStatus(P_LIBBSP_FNAND_StatusCard);
   if(v_NbrBlock > 1ul)
   {
      v_Error = Read_Multiblock(v_SectorAddr, p_Data, v_NbrBlock);
   }
   else if(v_NbrBlock == 1ul)
   {
      v_Error = Read_Singleblock(v_SectorAddr, p_Data);
   }
   else
   {
      v_Error = E_LIBBSP_FNAND_INV_NBR_BLOCKS;
   }

   if((v_Blocking != FALSE) && (v_Error == E_LIBBSP_FNAND_NO_ERROR))
   {
      do
      {
         v_Status = LIBBSP_FNAND_UpdateStatus();
         Wait(5ul);
      }while((v_Status == FALSE) && (P_LIBBSP_FNAND_Status->TRANSFER != E_LIBBSP_FNAND_TRAN_FAILED));
      do
      {
         Wait(100ul);
         (void) LIBBSP_FNAND_GetStatus(P_LIBBSP_FNAND_StatusCard);
      }while(P_LIBBSP_FNAND_StatusCard->B.READY_FOR_DATA == 0x00ul);
   }
   else
   {
      /* Nothing to do */
   }

   return (v_Error); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
