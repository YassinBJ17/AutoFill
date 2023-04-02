/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_Write_NoDMA.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Public function
 * Write v_NbrBlock block (512 bytes per block) in memory without DMA transfer.
 * Data are Written from v_SectorAddr to v_SectorAddr + v_Length.
 * Parameters : (uint32_t)  v_SectorAddr -> Address to start in FNAND memory
 *              (uint32_t*) p_Data       -> Pointer on data to send
 *              (uint32_t)  v_NbrBlock   -> Number of blocks to write.
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_Write_NoDMA(const uint32_t v_SectorAddr, const uint32_t* const p_Data, const uint32_t v_NbrBlock)
{
   TE_LIBBSP_FNAND_ERROR_OP v_ret;

   if(v_NbrBlock > 1ul)
   {
      v_ret = Write_Multiblock_NoDMA(v_SectorAddr, p_Data, v_NbrBlock);
   }
   else if(v_NbrBlock == 1ul)
   {
      v_ret = Write_Singleblock_NoDMA(v_SectorAddr, p_Data);
   }
   else
   {
      v_ret = E_LIBBSP_FNAND_INV_NBR_BLOCKS;
   }
   return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
