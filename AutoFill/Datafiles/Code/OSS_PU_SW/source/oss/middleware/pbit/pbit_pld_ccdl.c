/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP get sw info command send
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/pbit/pbit_private.h"
#include "middleware/ccdl/ccdl_private.h"
#include "middleware/logbook/logbook_public.h"
#include "middleware/reset/reset_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

void pbit_pld_ccdl(void)
{
   ts_ccdl * fpga_ccdl;

   /* Init pointer */
   fpga_ccdl = CCDL_ADDR;


   if(fpga_ccdl->s_tx_control.u_bit.s_ccdl_tx_enable != (uint32_t)1)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }


   if(fpga_ccdl->s_rx_control.u_bit.s_rx_enable != (uint32_t)1)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }


   if(fpga_ccdl->s_rx_control.u_bit.s_echo_mode!= (uint32_t)1)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }



}

/* ---------- internal operations: ------------------------------------------ */
