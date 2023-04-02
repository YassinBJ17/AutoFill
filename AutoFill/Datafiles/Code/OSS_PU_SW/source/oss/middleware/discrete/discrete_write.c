/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Write function for MDIN, SVOI, EMAN and DIN01 to DIN16
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

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SVOIEMAN-0010 */
/* Implements REQ_FADEX_OS_SRD-DIN-0010 */
/* Write discrete */
void discrete_write(
   /* INPUT */
   const uint32_t              v_discrete_id,
   const uint32_t *      const p_discrete_data,
   const uint32_t *      const p_discrete_filtred_data)
{
   /* Local Variable Declaration        */

   /* Initialization Variable           */

   /* Source code start */
   /* Write real-time discrete value */
   *DISCRETE_CONF_tab[v_discrete_id].p_shmem_access_raw = *p_discrete_data;

   /* Write updated filtered discrete value */
   if( DISCRETE_CONF_tab[v_discrete_id].p_shmem_access_filtered != NULL)
   {
      *DISCRETE_CONF_tab[v_discrete_id].p_shmem_access_filtered = *p_discrete_filtred_data;
   }

   return ;
}

/* ---------- internal operations: ------------------------------------------ */


