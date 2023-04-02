/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * --------------------------------------------------------------------------
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/can/can_critical_private.h"
#include "driver/can/can_critical_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_FADEX_OS_SRD-CAN-0020 */
void can_configure(uint32_t            const can_ram_addr,
                   ts_can_conf const * const ptr_can_conf,
                   ts_can_configure *  const ptr_shmem_can_configure)
{
   /* Local variables */
   uint32_t                idx_conf;
   tu_can_std_filt_elt_t * p_std_addr;
   ts_can_xtd_filt_elt_t * p_xtd_addr;
   tu_can_std_filt_elt_t   std_filt_elt;
   ts_can_xtd_filt_elt_t   xtd_filt_elt;
   uint32_t                local_std_add;
   uint32_t                local_xtd_add;

   /* Reset local variables */
   idx_conf = (uint32_t)0;

   /* Store standard IDs address */
   local_std_add = can_ram_addr + CAN_STD_FILT_CAN_OFF;
   p_std_addr = (tu_can_std_filt_elt_t*)local_std_add;

   /* Store extended IDs address */
   local_xtd_add = can_ram_addr + CAN_XTD_FILT_CAN_OFF;
   p_xtd_addr = (ts_can_xtd_filt_elt_t*)local_xtd_add;

   /*  */
   while (idx_conf < CAN_CFG_ID_MAX_NB)
   {
      /* Store standard ID configuration */
      if (e_can_02_a == ptr_can_conf->s_can_type_id)
      {
         /* Initialize local variable */
         std_filt_elt.u_word = (uint32_t)0;

         /* Range filter : SFID < SFID2 */
         std_filt_elt.u_bit.s_sft1 = (uint32_t)0x0;

         /* store in fifo 0 */
         std_filt_elt.u_bit.s_sfec = CAN_FIFO_0;

         /* configure standard filter id 1 bits [5:15] */
         std_filt_elt.u_bit.s_sfid1 = (ptr_shmem_can_configure->s_id_ranges[idx_conf].s_start_id)
         & CAN_FRAME_STD_ID_MASK;
         /* Configure standard id mask bits [21:31] */
         std_filt_elt.u_bit.s_sfid2 = (ptr_shmem_can_configure->s_id_ranges[idx_conf].s_stop_id)
         & CAN_FRAME_STD_ID_MASK;

         /* Write in CAN SRAM with 32 bits accesses */
         p_std_addr->u_word = std_filt_elt.u_word;

         p_std_addr++;
      }
      /* Store extended ID configuration */
      else
      {
         /* Initialize local variable */
         xtd_filt_elt.s_xtd_filt_elt_f0.u_word = (uint32_t)0;
         xtd_filt_elt.s_xtd_filt_elt_f1.u_word = (uint32_t)0;

         /* Store in FIFO 0 */
         xtd_filt_elt.s_xtd_filt_elt_f0.u_bit.s_efec = CAN_FIFO_0;

         /* Classic filter EFID1 = id EFID2 = mask */
         xtd_filt_elt.s_xtd_filt_elt_f1.u_bit.s_eft = (uint32_t)0x00;

         /* Configure extended id bits [28:0] */
         xtd_filt_elt.s_xtd_filt_elt_f0.u_bit.s_efid1 = (ptr_shmem_can_configure->s_id_ranges[idx_conf].s_start_id)
         & CAN_FRAME_XTD_ID_MASK;

         /* Configure extended id mask bits [28:0] */
         xtd_filt_elt.s_xtd_filt_elt_f1.u_bit.s_efid2 = (ptr_shmem_can_configure->s_id_ranges[idx_conf].s_stop_id)
         & CAN_FRAME_XTD_ID_MASK;

         /* Write in CAN SRAM with 32 bits accesses */
         p_xtd_addr->s_xtd_filt_elt_f0.u_word = xtd_filt_elt.s_xtd_filt_elt_f0.u_word;

         /* Write in CAN SRAM with 32 bits accesses */
         p_xtd_addr->s_xtd_filt_elt_f1.u_word = xtd_filt_elt.s_xtd_filt_elt_f1.u_word;

         p_xtd_addr++;
         p_xtd_addr++;
      }
      idx_conf++;
   }
}

/* ---------- internal operation bodies: ------------------------------------ */

