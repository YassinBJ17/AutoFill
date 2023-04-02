/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSPP_WRAPPER_ConvertUint32ToUint8.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
uint8_t LIBBSPP_WRAPPER_ConvertUint32ToUint8 (const uint32_t p_value32)
{
   uint8_t v_ret = (uint8_t) 0;
   uint32_t v_i;
   
   for (v_i = (uint32_t)0; v_i < (uint32_t)(C_UINT8_SIZE); v_i++)
   {
      if ( ((uint32_t)(p_value32 >> v_i) & (uint32_t)1) == (uint32_t)1)
      {
         v_ret |= C_MASK_OR[v_i]; /* set bit v_i to 1 without changing other bits */
      }
      else
      {
         v_ret &= C_MASK_AND[v_i]; /* set bit v_i to 0 without changing other bits */
      }
   }
   
   return v_ret;
}

/*==== END =============================================================================*/
