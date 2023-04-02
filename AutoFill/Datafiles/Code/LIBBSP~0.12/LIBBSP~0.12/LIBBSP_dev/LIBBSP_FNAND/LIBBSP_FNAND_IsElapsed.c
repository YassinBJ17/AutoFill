/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_IsElapsed.h"

/*==== Definitions =====================================================================*/
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Internal definition of LIBBSP_CMD_isElapsed. This function wait 1 us instead of 10us.
 */
uint32_t IsElapsed(uint32_t *Count)
{
   uint32_t previousTime;
   uint32_t currentTime;
   uint32_t elapsedTime;
   uint32_t v_ret;

   if (*Count == 0ul)
   {
      v_ret = 1ul;
   }
   else
   {
      *Count -= 1ul;
      previousTime = LIBBSP_CMN_GetTicks();
      elapsedTime = 0ul;
      do {
         currentTime = LIBBSP_CMN_GetTicks();
         if(currentTime > previousTime)
         {
            elapsedTime += (currentTime - previousTime) ;
         }
         else
         {
            previousTime = C_FNAND_MAX_TIME - previousTime;
            elapsedTime += (currentTime+previousTime);
         };
         previousTime = currentTime;
      }while(elapsedTime < C_FNAND_TIME_1_MICRO_S);
      v_ret = 0ul;
   }
    return v_ret;
}

/*==== END =============================================================================*/
