/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP get sw info command send
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/ovsp/ovsp_public.h"
#include "middleware/ovsp/ovsp_private.h"
#include "middleware/ovsp/ovsp_frame.h"
#include "memory/shared_memory_public.h"
#include "driver/can/can_critical_private.h"
#include "middleware/uod_bypass/uod_bypass_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

void ovsp_reset_txs_buffer_monitor()
{
   uint32_t       i;
   uint32_t       j;

   for (i = (uint32_t)0; i<OVSP_TX_FRAME_SEND; i++)
   {
      uod_bypass.uod_can_ovsp_tx_monitor_ls[i].s_identifier =0;
      uod_bypass.uod_can_ovsp_tx_monitor_ls[i].s_length = 0;

      uod_bypass.uod_can_ovsp_tx_monitor_hs[i].s_identifier = 0;
      uod_bypass.uod_can_ovsp_tx_monitor_hs[i].s_length = 0;

      for (j = (uint32_t)0; j<(uint32_t)8; j++)
      {
         uod_bypass.uod_can_ovsp_tx_monitor_ls[i].s_data[j] = 0;
         uod_bypass.uod_can_ovsp_tx_monitor_hs[i].s_data[j] = 0;
      }
   }

}

/* ---------- internal operations: ------------------------------------------ */
