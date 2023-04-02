/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_RMM_Write.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_RMM_Write(  const uint32_t             rmmAddress,
                        const uint32_t             size,
                        uint8_t *            const buffer, /* %RELAX<SYNCHRONe_C_Code_8.18> Output only used as parameter in subfunction */
                        TE_LIBBSP_I2C_Code * const v_ret)
{
   uint32_t v_sizeRemaining;
   uint32_t v_Index;

   v_sizeRemaining = size;
   v_Index = 0ul;

   /* Process first block separately in case it is not aligned to start of page*/
   if (v_sizeRemaining >= (uint32_t)C_RMM_PAGE_SIZE)
   {
      v_Index = ((uint32_t)C_RMM_PAGE_SIZE - (rmmAddress % ((uint32_t)C_RMM_PAGE_SIZE)));
      *v_ret = LIBBSP_RMM_WritePage(rmmAddress, v_Index, buffer);
      if (*v_ret != E_LIBBSP_I2C_OK)
      {
         return;
      }
      v_sizeRemaining -= v_Index;
   }

   /* Process middle full page size blocks*/
   while (v_sizeRemaining >= (uint32_t)C_RMM_PAGE_SIZE)
   {
      *v_ret = LIBBSP_RMM_WritePage(rmmAddress + v_Index, (uint32_t)C_RMM_PAGE_SIZE, &buffer[v_Index]);
      if (*v_ret != E_LIBBSP_I2C_OK)
      {
         return;
      }
      v_Index += (uint32_t)C_RMM_PAGE_SIZE;
      v_sizeRemaining -= (uint32_t)C_RMM_PAGE_SIZE;
   }

   /* Process last block if not reading a full page*/
   if (v_sizeRemaining > 0ul)
   {
      *v_ret = LIBBSP_RMM_WritePage(rmmAddress + v_Index, v_sizeRemaining, &buffer[v_Index]);
   }
}

/*==== END =============================================================================*/
