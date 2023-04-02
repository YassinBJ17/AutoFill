/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Initialization of function for MDIN, SVOI, EMAN and DIN01 to DIN16
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/discrete/discrete_private.h"
#include "middleware/discrete/discrete_public.h"

/* ---------- include required interface: ----------------------------------- */



/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SVOIEMAN-0010 */
/* Implements REQ_FADEX_OS_SRD-DIN-0010 */
/* Initialization of GPIO */
void discrete_init(void)
{
   /* Local Variable Declaration        */
   uint32_t                     v_conf_id;

   /* Initialization Variable           */

   /* Source code start */

   /* Perform PBIT sequence to use discrete signal */
   *GPDO_228_EMAN_SVOI_OPEN    = DISCRETE_GPDO_DISABLE;
   *GPDO_229_COMDIN_OPEN       = DISCRETE_GPDO_ENABLE;
   *GPDO_230_EMAN_SVOI_CLOSED  = DISCRETE_GPDO_DISABLE;
   *GPDO_231_DIN1_16_CLOSED    = DISCRETE_GPDO_DISABLE;

   /*--- GPIO init part ---*/
   /* Discrete GPIO loop for DIN1 to DIN16 with EMAN and SVOI */
   for( v_conf_id = INIT_VALUE_32 ; v_conf_id < DISCRETE_DATA_NB ; v_conf_id++ )
   {
      /* Initiate error report */
      DISCRETE_COUNTER_tab[v_conf_id].u_word  = DISCRETE_INIT_VALUE ;

      /* Initiate counter part */
      /* MDIN define in FPGA register as DISCRETE not filtered */
      if( DISCRETE_CONF_tab[v_conf_id].p_conf_filter_nb_cycles == NULL )
      {
         /* Number of cycles need in OSS_CONF for discrete filter at null for MDIN */
         DISCRETE_COUNTER_tab[v_conf_id].u_discrete_bit.c_max_counter =
            DISCRETE_INIT_VALUE;

         /* Down counter at null for MDIN */
         DISCRETE_COUNTER_tab[v_conf_id].u_discrete_bit.s_unstable_counter =
            DISCRETE_INIT_VALUE;
      }
      else
      {
         /* Number of cycles need in OSS_CONF for discrete filter for GPIO discrete */
         DISCRETE_COUNTER_tab[v_conf_id].u_discrete_bit.c_max_counter =
            (uint32_t)(*DISCRETE_CONF_tab[v_conf_id].p_conf_filter_nb_cycles);

         /* Down counter at Number of cycles for GPIO discrete */
         DISCRETE_COUNTER_tab[v_conf_id].u_discrete_bit.s_unstable_counter =
            (uint32_t)(*DISCRETE_CONF_tab[v_conf_id].p_conf_filter_nb_cycles);
      }
   }

   return ;
}

/* ---------- internal operations: ------------------------------------------ */


