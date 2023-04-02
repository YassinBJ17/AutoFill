/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/can/can_critical_private.h"
#include "middleware/can/can_public.h"
#include "driver/can/can_private.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */


/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_FADEX_OS_SRD-CAN-0020 */
/* Implements REQ_FADEX_OS_SRD-CAN-0050 */
void can_periodic(void)
{
   ts_can_reg_t * can2_reg_descr;
   can2_reg_descr = (ts_can_reg_t*)CAN2_REG_ADDR;


   /* if this channel is in control */
   if (1 == shmem.s_channel_state.s_channel_state || 2 == shmem.s_channel_state.s_channel_state)
   {
      /* if can 2 is in slepp mode */
      if (1 == can2_reg_descr->s_cccr.u_bit.s_csr)
      {
         /* Then deactivate sleep mode  */
         can2_reg_descr->s_cccr.u_bit.s_csr = 0;
         /* Flush CAN2 TX to prevent from sending when reactivation */
         can2_reg_descr->s_m_can_txbcr_unused = 0xFFFFFFFF;
         /* Restarting CAN communication by resetting bit CCCR[INIT]. */
         can2_reg_descr->s_cccr.u_bit.s_init = 0;
      }
   }
   /* else channel is not in control */
   else
   {
      /* check if can 2 is NOT in sleep mode */
      if(0 == can2_reg_descr->s_cccr.u_bit.s_csr)
      {
         /* if can 2 not in sleep mode, put it in sleep mode*/
         can2_reg_descr->s_cccr.u_bit.s_csr = 1;
      }
   }

   /* if the parameter configure_on_request is equal to e_not_done the CSS request a configuration of the CAN id filt */
   if(shmem.s_can1_configure.s_configure_on_request == e_not_done)
   {
      /* The CAN is configure to accept frame with id present in the id filtering list */
      can_configure(CAN1_RAM_ADDR, &(can1_conf), &(shmem.s_can1_configure));
      /* the configure parameter is set to e_done to ackowledge the configure request of the CSS*/
      shmem.s_can1_configure.s_configure_on_request = e_done;
   }

   if(shmem.s_can2_configure.s_configure_on_request == e_not_done)
   {
      /* The CAN is configure to accept frame with id present in the id filtering list */
      can_configure(CAN2_RAM_ADDR, &(can2_conf), &(shmem.s_can2_configure));
      /* the configure parameter is set to e_done to ackowledge the configure request of the CSS*/
      shmem.s_can2_configure.s_configure_on_request = e_done;
   }

   /* Check in SHMEM if there are frames to send through CAN2 */
   if (shmem.s_can2_tx.s_frames_nb > 0)
   {
      /* Sending frames through CAN2 */
      can_write(&(shmem.s_can2_tx), CAN2_RAM_ADDR, CAN2_REG_ADDR, &(can2_conf));
   }

   /* Check if the CSS has processed all the previous CAN1 Rx frames */
   if (0 == shmem.s_can1_rx.s_frames_nb)
   {
      /* reading CAN1 frames and storing it in SHMEM */
      can_read(CAN1_REG_ADDR, CAN1_RAM_ADDR, &(shmem.s_can1_rx), &(can1_conf));
   }

   /* Check if the CSS has processed all the previous CAN2 Rx frames */
   if (0 == shmem.s_can2_rx.s_frames_nb)
   {
      /* reading CAN2 frames and storing it in SHMEM */
      can_read(CAN2_REG_ADDR, CAN2_RAM_ADDR, &(shmem.s_can2_rx), &(can2_conf));
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
