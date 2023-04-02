/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP get sw info command send
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/pbit/pbit_public.h"
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

void pbit_pld_a429_tx(const boolean_t ch_is_a)
{
   /* Simulated by a configuration table in mram */
   ts_oss_conf_table* oss_conf;

   /* Registers for A429 1A RX & TX */
   ts_a429_tx_reg* fpga_a429_1a_tx;

   /* Registers for A429 2AB RX & TX */
   ts_a429_tx_reg* fpga_a429_2ab_tx;

   /* Retrieve conf in MRAM */
   oss_conf = (ts_oss_conf_table*)(OSS_CONF_START_ADDR);


   fpga_a429_1a_tx = A429_1A_2AB_TX_ADDR;
   fpga_a429_2ab_tx = A429_1A_2AB_TX_ADDR;

   if(ch_is_a)
   {
      if(fpga_a429_1a_tx->conf.u_bit.s_speed_select != oss_conf->s_a429_1a_baud)
      {
         /* Log fatal fault */
         logbook_pbit_fatal(0, 0);

         /* WD reset */
         reset_critical();
      }
      if(fpga_a429_1a_tx->cmd.u_bit.s_enable_tx != (uint32_t)1)
      {
         /* Log fatal fault */
         logbook_pbit_fatal(0, 0);

         /* WD reset */
         reset_critical();
      }
   }
   else
   {
      if(fpga_a429_2ab_tx->conf.u_bit.s_speed_select != oss_conf->s_a429_2ab_baud)
      {
         /* Log fatal fault */
         logbook_pbit_fatal(0, 0);

         /* WD reset */
         reset_critical();
      }
      if(fpga_a429_2ab_tx->cmd.u_bit.s_enable_tx != (uint32_t)1)
      {
         /* Log fatal fault */
         logbook_pbit_fatal(0, 0);

         /* WD reset */
         reset_critical();
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
