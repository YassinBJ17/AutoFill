/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "libtools/time/LIB_TIME_public.h"

/* Higher value of a 32 bits integer on 8 bytes */
#define MAX_UINT32_VALUE_ON_8_BYTES 0x00000000FFFFFFFFll

/* Higher value of a 32 bits integer on 4 bytes */
#define MAX_UINT32_VALUE_ON_4_BYTES 0xFFFFFFFFul


void LIBT_TIME_Update( ts_LIB_TIME_CHRONO* const p_chrono)
{
   CMN_SYSTEM_TIME_t v_curr;
   if ( p_chrono->s_ongoing == 0ul )
   {
      LIBT_TIME_GET( &p_chrono->s_start );
      p_chrono->s_ongoing = 1ul ;
   }
   else
   {
      LIBT_TIME_GET( &v_curr);

      /* note as the LIBT_TIME_GET is on 64 bits, the loop back of the system timer is not managed here. */

      if ( (v_curr - p_chrono->s_start) > MAX_UINT32_VALUE_ON_8_BYTES )
      {
         p_chrono->s_ongoing = MAX_UINT32_VALUE_ON_4_BYTES ;
      }
      else
      {
         /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_10.3>: the chronometer is limited to 32 bits only. Safe cast (test in range done previously)  */
         p_chrono->s_ongoing = (uint32_t) (v_curr - p_chrono->s_start) ;
      }

   }
}
