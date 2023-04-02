/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : CAN 1 Write critical service
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/can/can_critical_private.h"
#include "driver/can/can_critical_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */


/* ---------- internal data: ------------------------------------------------ */
ts_can_conf can1_conf;

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-CAN-0040 */
/* CAN 1 Write critical service */
void can1_critical_write(void)
{

   /* Check in SHMEM if there are frames to send through CAN1 */
   if (shmem.s_can1_tx.s_frames_nb > 0)
   {
      /* Sending frames through CAN1 critical service */
      can_write(&(shmem.s_can1_tx), CAN1_RAM_ADDR, CAN1_REG_ADDR, &(can1_conf));
   }

}

/* ---------- internal operation bodies: ------------------------------------ */
