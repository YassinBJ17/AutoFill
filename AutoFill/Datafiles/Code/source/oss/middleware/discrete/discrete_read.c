/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Read function for MDIN, SVOI, EMAN and DIN01 to DIN16
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
/* Read discrete */
void discrete_read(
   /* INPUT */
   const uint32_t              v_discrete_id,
   /* OUTPUT */
   uint32_t *            const p_discrete_filtred,
   uint32_t *            const p_discrete_prevdata,
   uint32_t *            const p_discrete_data)
{
   /* Local Variable Declaration        */
   reg8_t         v_gpio_data;

   /* Initialization Variable           */

   /* Read GPIO */
   v_gpio_data = *DISCRETE_CONF_tab[v_discrete_id].p_discret_add;

   /* Source code start */
   /* Read real-time discrete value */
   if( DISCRETE_CONF_tab[v_discrete_id].p_conf_filter_nb_cycles == NULL )
   {
      /* Cast and mask data from FPGA */
      *p_discrete_data  =
         (uint32_t)( ( v_gpio_data & DISCRETE_MASK_MDIN ) >> DISCRETE_BIT_SHIFT_MDIN );

   }
   else
   {

      /* Cast data GPIO */
      *p_discrete_data  = (uint32_t)(v_gpio_data);

      /* Read filtered discrete value*/
      *p_discrete_filtred  = *DISCRETE_CONF_tab[v_discrete_id].p_shmem_access_filtered;
   }

   /* Read previous discrete value */
   *p_discrete_prevdata = *DISCRETE_CONF_tab[v_discrete_id].p_shmem_access_raw;

   return ;
}

/* ---------- internal operations: ------------------------------------------ */


