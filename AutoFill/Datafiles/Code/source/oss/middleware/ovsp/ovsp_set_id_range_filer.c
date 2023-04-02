/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/ovsp/ovsp_public.h"
#include "middleware/ovsp/ovsp_private.h"
#include "driver/can/can_critical_private.h"
#include "driver/can/can_critical_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

void ovsp_set_id_range_filter(uint32_t const can_ram_addr, uint32_t const id_range_start, uint32_t const id_range_stop)
{
   /* Local variables */
   tu_can_std_filt_elt_t * p_std_addr;
   tu_can_std_filt_elt_t   std_filt_elt;
   uint32_t                local_std_add;

   /* Store standard IDs address */
   local_std_add = can_ram_addr + CAN_STD_FILT_CAN_OFF;
   p_std_addr = (tu_can_std_filt_elt_t*)local_std_add;

   /* Initialize local variable */
   std_filt_elt.u_word = (uint32_t)0;

   /* Range filter : SFID < SFID2 */
   std_filt_elt.u_bit.s_sft1 = (uint32_t)0x0;

   /* store in fifo 0 */
   std_filt_elt.u_bit.s_sfec = CAN_FIFO_0;

   /* configure standard filter id 1 bits [5:15] */
   std_filt_elt.u_bit.s_sfid1 = (id_range_start & CAN_FRAME_STD_ID_MASK);
   /* Configure standard id mask bits [21:31] */
   std_filt_elt.u_bit.s_sfid2 = (id_range_stop & CAN_FRAME_STD_ID_MASK);

   /* Write in CAN SRAM with 32 bits accesses */
   p_std_addr->u_word = std_filt_elt.u_word;


}

/* ---------- internal operation bodies: ------------------------------------ */

