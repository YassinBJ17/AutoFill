/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Monitor function filters for MDIN, SVOI, EMAN and DIN01 to DIN16
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/discrete/discrete_private.h"

/* ---------- include required interface: ----------------------------------- */



/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* During filter function, GPIO state will be upgraded in global counter structure before transmission function  */
/* GPIO counter description defined as followed                                                                  */
/* | XX | XX | XX | XX |
 *    ^    ^    ^    ^
 *    |    |    |    |---> {s_stable_counter}   in 8bits RTC counter when GPIO level is stable
 *    |    |    |--------> {c_max_counter}      in 8bits Constant value from OSS_CONF
 *    |    |-------------> {s_unstable_counter} in 8bits RTC down counter when GPIO level is unstable
 *    |------------------> {s_active_filter}    in 8bits Active filter status
 * */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SVOIEMAN-0010 */
/* Implements REQ_FADEX_OS_SRD-DIN-0010 */
/* Read discrete */
void discrete_monitor(
      /* INPUT */
      const uint32_t              v_discrete_id,
      const uint32_t*       const p_discrete_prevdata,
      const uint32_t*       const p_discrete_data,
      /* OUTPUT */
      uint32_t *            const p_discrete_filtred_data)
{
   /* Local Variable Declaration        */
   uint32_t    v_discrete_sum;

   /* Initialization Variable           */

   /* Source code start */
   /*--- UPGRADE UNSTABLE COUNTER ---*/
   if(   (DISCRETE_COUNTER_tab[v_discrete_id].u_discrete_bit.s_unstable_counter >  DISCRETE_INIT_VALUE)
      && ( DISCRETE_COUNTER_tab[v_discrete_id].u_discrete_bit.s_active_filter   == DISCRETE_INIT_VALUE ) )
   {
      /* Decrease unstable down counter */
      DISCRETE_COUNTER_tab[v_discrete_id].u_discrete_bit.s_unstable_counter--;
   }
   else
   {
      /* Filter status set to active to lock filtering mode */
      DISCRETE_COUNTER_tab[v_discrete_id].u_discrete_bit.s_active_filter = DISCRETE_FILTER_ACTIF;
   }

   /*--- UPGRADE STABLE COUNTER ---*/
   /* In first step, current and previous values of GPIO are save before be used */
   v_discrete_sum = *p_discrete_data + *p_discrete_prevdata;

   /* Depending on the case, GPIO counter upgrade if GPIO state change or stay stable */
   if((v_discrete_sum == DISCRETE_GPIO_HIGH) ||
      (v_discrete_sum == DISCRETE_GPIO_LOW)  )
   {
      /* In case of equality increase counter by one */
      DISCRETE_COUNTER_tab[v_discrete_id].u_discrete_bit.s_stable_counter++;
   }
   else
   {
      /* Otherwise, GPIO counter set to null */
      DISCRETE_COUNTER_tab[v_discrete_id].u_discrete_bit.s_stable_counter = DISCRETE_INIT_VALUE ;
   }

   /* Lock counter at the maximum value if the s_stable_counter is higher than */
   /* OSS_CONF value saved in counter in INIT */
   if( ( DISCRETE_COUNTER_tab[v_discrete_id].u_discrete_bit.s_stable_counter >=
      DISCRETE_COUNTER_tab[v_discrete_id].u_discrete_bit.c_max_counter )
      || ( DISCRETE_COUNTER_tab[v_discrete_id].u_discrete_bit.s_active_filter ==
      DISCRETE_INIT_VALUE ) )
   {
      /* Confirm counter to the maximum value */
      DISCRETE_COUNTER_tab[v_discrete_id].u_discrete_bit.s_stable_counter =
         DISCRETE_COUNTER_tab[v_discrete_id].u_discrete_bit.c_max_counter;

      /* Update DIN filtered by present GPIO */
      *p_discrete_filtred_data = *p_discrete_data;
   }

   return ;
}

/* ---------- internal operations: ------------------------------------------ */


