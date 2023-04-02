/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 *  DESCRIPTION : This function retrieve the current time.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_LIBTIME_private.h"
#include "BOOT_LIBTIME_public.h"
#include "LIB_MATH_public.h"

/* ---------- include required interface: ----------------------------------- */
/* none */


/* ---------- internal define constants: ------------------------------------ */
#define PIT_TICK_TO_NS ( 25ull )

#define MAX_UINT64_VALUE 0xFFFFFFFFFFFFFFFFull
/* ---------- internal types: ----------------------------------------------- */
typedef union
{
   uint64_t u_fullval ;
   
   struct
   /* >RELAX<SYNCHRONe_C_Code_6.6, SYNCHRONe_C_Code_8.2> Register Definition. compliant with standard. */
   {
      reg32_t s_high ;
      reg32_t s_low ;
   } u_val ;
} tu_LIBT_GET_SYSTIME_REGISTER ;

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_[User Project Name]_BOOT-LLR_059 */
void BOOT_LIBTIME_GET( CMN_SYSTEM_TIME_t* const p_timeNanoSec )
{
   /* Local Variable Declaration */
   tu_LIBT_GET_SYSTIME_REGISTER v_regvalue ;
   uint64_t v_decrement ;
   uint64_t op1,op2;

   /* Get PIT registers content */
   v_regvalue.u_val.s_high = LIBT_pit_ctrl->s_PIT_LTMR64H ;
   v_regvalue.u_val.s_low = LIBT_pit_ctrl->s_PIT_LTMR64L ;

   if ( v_regvalue.u_val.s_high != LIBT_pit_ctrl->s_PIT_LTMR64H )
   {
      v_regvalue.u_val.s_high = LIBT_pit_ctrl->s_PIT_LTMR64H ;
   }
   v_decrement = v_regvalue.u_fullval ;

   /* >RELAX<SYNCHRONe_C_Code_7.2>Not a magic number: it is a simple way to convert a decrementer into an incrementer*/
   v_decrement = ( (uint64_t) MAX_UINT64_VALUE ) - v_decrement ;

   /* Warning with overflow prevention : according to the computation: the overflow will occur after 292 years.  */
   /* due to this threshold, no prevention on overflow is performed. */
   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_10.3> : the value is divided by 2, so the change from unsigned*/
   /* to signed is under control.  */
   //*p_timeNanoSec = (CMN_SYSTEM_TIME_t) ( ( v_decrement * (uint64_t) ( PIT_TICK_TO_NS ) ) >> 1ull ) ;
   op1 = v_decrement >> 1ull;
   op2 = PIT_TICK_TO_NS;
   *p_timeNanoSec = (CMN_SYSTEM_TIME_t)( lib_math_umul64( op1, op2 ) );

}

/* ---------- internal operation bodies: ------------------------------------ */
/* */

