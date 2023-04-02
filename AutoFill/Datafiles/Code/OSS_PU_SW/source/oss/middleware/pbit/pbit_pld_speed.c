/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP get sw info command send
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/pbit/pbit_private.h"
#include "middleware/nfreq/nfreq_private.h"
#include "conf/oss_conf_public.h"
#include "memory/memory_address_public.h"
#include "middleware/logbook/logbook_public.h"
#include "middleware/reset/reset_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

void pbit_pld_speed(void)
{
   ts_nfreq_registers * v_nfreq_register;
   ts_oss_conf_table * pv_oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;

   /* NFREQ2 */
   v_nfreq_register = (ts_nfreq_registers *)(FPGA_MEMORY_ADDR + C_FPGA_IIP10_0_OFFSET);
   if(v_nfreq_register->s_conf_register.s_inc_1_th_sel != pv_oss_conf->s_nfreq2_inc_1_th_sel)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }

   /* NFREQ3 */
   v_nfreq_register = (ts_nfreq_registers *)(FPGA_MEMORY_ADDR + C_FPGA_IIP10_1_OFFSET);
   if(v_nfreq_register->s_conf_register.s_inc_2_th_sel != pv_oss_conf->s_nfreq3_inc_2_th_sel)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }

   /* NFREQ4 */
   v_nfreq_register = (ts_nfreq_registers *)(FPGA_MEMORY_ADDR + C_FPGA_IIP10_2_OFFSET);
   if(v_nfreq_register->s_conf_register.s_inc_1_th_sel != pv_oss_conf->s_nfreq4_inc_1_th_sel)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }

   /* NGALT */
   v_nfreq_register = (ts_nfreq_registers *)(FPGA_MEMORY_ADDR + C_FPGA_IIP10_3_OFFSET);
   if(v_nfreq_register->s_conf_register.s_inc_1_th_sel != pv_oss_conf->s_ngalt_inc_1_th_sel)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }


}

/* ---------- internal operations: ------------------------------------------ */
