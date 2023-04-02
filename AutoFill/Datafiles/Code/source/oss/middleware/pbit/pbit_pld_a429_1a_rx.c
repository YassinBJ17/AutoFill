/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP get sw info command send
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/pbit/pbit_private.h"
#include "middleware/a429/a429_private.h"
#include "conf/oss_conf_public.h"
#include "middleware/logbook/logbook_public.h"
#include "middleware/reset/reset_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

void pbit_pld_a429_1a_rx(void)
{
   /* Simulated by a configuration table in mram */
   ts_oss_conf_table* oss_conf;

   /* Registers for A429 1A RX */
   ts_a429_rx_reg* fpga_a429_1a_rx;

   /* Retrieve conf in MRAM */
   oss_conf = (ts_oss_conf_table*)(OSS_CONF_START_ADDR);

   fpga_a429_1a_rx  = A429_1A_RX_ADDR;

   if(fpga_a429_1a_rx->cmd.u_bit.s_storage_mode != (uint32_t)1)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }

   if(fpga_a429_1a_rx->cmd.u_bit.s_enable_rx != (uint32_t)1)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }

   if ((uint32_t)0 == oss_conf->s_a429_1a_baud)
   {
      if(fpga_a429_1a_rx->gap.u_bit.s_filter_time != LS_FILTER_TIME)
      {
         /* Log fatal fault */
         logbook_pbit_fatal(0, 0);

         /* WD reset */
         reset_critical();
      }

      if(fpga_a429_1a_rx->gap.u_bit.s_gap_bit_time != LS_GAP_BIT_TIME)
      {
         /* Log fatal fault */
         logbook_pbit_fatal(0, 0);

         /* WD reset */
         reset_critical();
      }

      if(fpga_a429_1a_rx->hbit.u_bit.s_max_hbit_time != LS_HBIT_TIME_MAX)
      {
         /* Log fatal fault */
         logbook_pbit_fatal(0, 0);

         /* WD reset */
         reset_critical();
      }

      if(fpga_a429_1a_rx->hbit.u_bit.s_min_hbit_time != LS_HBIT_TIME_MIN)
      {
         /* Log fatal fault */
         logbook_pbit_fatal(0, 0);

         /* WD reset */
         reset_critical();
      }

      if(fpga_a429_1a_rx->bit.u_bit.s_max_bit_time != LS_BIT_TIME_MAX)
      {
         /* Log fatal fault */
         logbook_pbit_fatal(0, 0);

         /* WD reset */
         reset_critical();
      }

      if(fpga_a429_1a_rx->bit.u_bit.s_min_bit_time  != LS_BIT_TIME_MIN)
      {
         /* Log fatal fault */
         logbook_pbit_fatal(0, 0);

         /* WD reset */
         reset_critical();
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
