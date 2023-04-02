/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_RMM_Read.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_RMM_Read(const uint32_t rmmAddress, const uint32_t size, uint8_t * const buffer, TE_LIBBSP_I2C_Code * const v_ret) /* %RELAX<SYNCHRONe_C_Code_8.18> Output used only as parameter in subfunction */
{
   uint16_t v_addr;
   uint32_t v_remain;

   if(V_RMM_State == E_LIBBSP_RMM_OPEN)
   {
      v_addr = (uint16_t)(rmmAddress&0x0000FFFFul);
      if (((uint32_t)v_addr + size) >= 0x10000ul)
      {
         v_remain = 0x10000ul - (uint32_t)v_addr;
      }
      else
      {
         v_remain = size;
      }
      if ((rmmAddress&0x00010000ul) == 0ul)
      {
         *v_ret = LIBBSP_RMM_ReadBlock(C_RMM_24FC1025_B0_ADDR, v_addr, v_remain, buffer);
         if (*v_ret == E_LIBBSP_I2C_OK && v_remain < size)
         {
            *v_ret = LIBBSP_RMM_ReadBlock(C_RMM_24FC1025_B1_ADDR, (uint16_t)0, size - v_remain, &buffer[v_remain]);
         }
      }
      else
      {
         *v_ret = LIBBSP_RMM_ReadBlock(C_RMM_24FC1025_B1_ADDR, v_addr, v_remain, buffer);
      }
   }
   else
   {
      *v_ret = E_LIBBSP_I2C_CLOSED;
   }
}
/*==== END =============================================================================*/
