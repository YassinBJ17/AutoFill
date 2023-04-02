/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"
#include "middleware/pan3/pan3_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
/* GPIO Handling */
#define C_MPC_PAN3_MON  ((uint8_t *)0xFFFC15AF) /* GPDI 175 */

/* GPIO UP value */
#define  C_PAN3_ON      ((uint8_t)0x01)

/* ---------- internal data: ------------------------------------------------ */
/*  */
tu_pan3_fault_word v_pan3_status_word;

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-PAN3-0010 */
/* Manage PAN3 */
void pan3_periodic(const boolean_t channel_is_a)
{
   uint8_t *pv_mpc_pan3_mon;


   /* Reset fault word */
   v_pan3_status_word.u_word = (uint8_t)0;

   /* Process pan3 handling */
   if (FALSE == channel_is_a)
   {
      /*===========*/
      /* Channel B */
      /*===========*/
      /* Point to pan3 GPDI */
      pv_mpc_pan3_mon = C_MPC_PAN3_MON;

      /* Update fault word */
      if (C_PAN3_ON == *pv_mpc_pan3_mon)
         v_pan3_status_word.u_bit.s_commanded = TRUE;
      else
         v_pan3_status_word.u_bit.s_commanded = FALSE;

      /* Signal availability */
      v_pan3_status_word.u_bit.s_unavailable = FALSE;
   }
   else
   {
      /*===========*/
      /* Channel A */
      /*===========*/
      /* Signal unavailability */
      v_pan3_status_word.u_bit.s_commanded   = FALSE;
      v_pan3_status_word.u_bit.s_unavailable = TRUE;
   }
}

/* ---------- internal operations: ------------------------------------------ */
