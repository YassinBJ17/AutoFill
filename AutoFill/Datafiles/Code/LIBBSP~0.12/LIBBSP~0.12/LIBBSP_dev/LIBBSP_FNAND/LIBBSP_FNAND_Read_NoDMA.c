/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_Read_NoDMA.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Public function
 * Read v_NbrBlock block (512 bytes per block) in memory without a DMA transfer.
 * Data are read from v_SectorAddr to v_SectorAddr + v_Length.
 * Parameters : (uint32_t)  v_SectorAddr -> Address to start in FNAND memory
 *              (uint32_t*) p_Data       -> Pointer on data reception
 *              (uint32_t)  v_NbrBlock   -> Number of blocks to read.
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_Read_NoDMA(const uint32_t v_SectorAddr, uint32_t* const p_Data, const uint32_t v_NbrBlock) /* %RELAX<SYNCHRONe_C_Code_8.18> p_Data is output */
{
   TE_LIBBSP_FNAND_ERROR_OP v_ret;

   if(v_NbrBlock > 1ul)
   {
      v_ret = Read_Multiblock_NoDMA(v_SectorAddr, p_Data, v_NbrBlock);
   }
   else if(v_NbrBlock == 1ul)
   {
      v_ret = Read_Singleblock_NoDMA(v_SectorAddr, p_Data);
   }
   else
   {
      v_ret = E_LIBBSP_FNAND_INV_NBR_BLOCKS;
   }
   return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
