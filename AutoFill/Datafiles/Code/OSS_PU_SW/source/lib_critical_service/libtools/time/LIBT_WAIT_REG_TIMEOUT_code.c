/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */
/* ---------- include provided interface: ----------------------------------- */
#include "libtools/time/LIB_TIME_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void LIBT_WAIT_REG_TIMEOUT ( uint32_t          const reg,
                             int32_t           const expected_state,
                             CMN_SYSTEM_TIME_t  const time_to_wait,
                             tu_CMN_RC         * return_code_pt )
{
   /* */
   CMN_SYSTEM_TIME_t    time_start;
   CMN_SYSTEM_TIME_t    current_time;
   uint8_t                stop_loop;

   /* Read MODE_STATUS register to check that PROGRAMMING mode has been taken account*/

   /* initialize values */
   stop_loop = 1;
   time_start = 0;
   current_time = 0;

   /* Read time */
   LIBT_TIME_GET( &time_start);


   while( stop_loop == 1)
   {

      /* Has the register taken account the value ? */
      if (expected_state == reg)
      {
         /* register has taken account the value  */
         stop_loop = 0;

         /* */
         return_code_pt->u_r = 0UL;
      }
      else
      {
         /* */
         LIBT_TIME_GET( &current_time);

         /* */
         if ( (time_start + time_to_wait) < current_time )
         {
             /* time out is reached */
             stop_loop = 0;

             /* Register has not taken account the new mode */
             return_code_pt->u_b.s_RC_HW_ERROR = 1;
         }
         else
         {
            /* */
            if ((0xFFFFFFFFFFFFFFFFLL - time_start + current_time) < time_to_wait)
            {
               /* continue to wait for busy */
               stop_loop = 1;
            }
            else
            {
               /* time out is reached */
               stop_loop = 0;

               /* Register has not taken account the new mode */
               return_code_pt->u_b.s_RC_HW_ERROR = 1;
            }
         }
      }
   }
}

/* ---------- internal operation bodies: ------------------------------------ */

