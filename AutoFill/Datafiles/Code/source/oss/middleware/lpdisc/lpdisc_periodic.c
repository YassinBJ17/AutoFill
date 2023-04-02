/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Periodic process of LP devices
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/lpdisc/lpdisc_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/lpdisc/lpdisc_private.h"
#include "middleware/lpdisc/lpdisc_process_raw.h"
#include "middleware/lpdisc/lpdisc_set_cmd.h"
#include "middleware/lpdisc/lpdisc_mon_1_switch.h"
#include "middleware/lpdisc/lpdisc_mon_2_switch.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* LP mon state */
uint16_t lpdisc_mon_state[e_LpDeviceMax];

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LPDISC-0020 */
/* Implements REQ_FADEX_OS_SRD-LPDISC-0030 */
/* Implements REQ_FADEX_OS_SRD-LPDISC-0040 */
/* Implements REQ_FADEX_OS_SRD-LPDISC-0050 */
/* Implements REQ_FADEX_OS_SRD-LPDISC-0060 */
/* Implements REQ_FADEX_OS_SRD-LPDISC-0070 */
/* Periodic process of LP devices */
void lpdisc_periodic(void)
{
   te_lpdisc_device_index   v_index;
   ts_lpdisk_device        *v_device;
   tu_lp_fault_word        *v_fault_word;
   uint32_t                *v_command;


   /*==============*/
   /* Process loop */
   for (v_index = (te_lpdisc_device_index)0; v_index < e_LpDeviceMax; v_index++)
   {
      v_device     = &v_lp_devices[v_index];
      v_fault_word = &shmem.s_lp_w.s_lp_status[v_index];
      v_command    = &shmem.s_lp_w.s_lp_command[v_index];

      v_fault_word->u_bit.s_i2c_not_working = (uint32_t)FALSE;

      /* Get current switches state */
      if ((uint8_t)0 != *v_device->s_raw_swi_1.s_err_pointer
      ||  (uint8_t)0 != *v_device->s_raw_swi_2.s_err_pointer)
      {
         v_device->s_state_read                = C_LP_COMM_ERROR;
         v_fault_word->u_bit.s_i2c_not_working = (uint32_t)TRUE;
      }
      else
      {
         v_device->s_state_read = C_LP_ALL_OPEN
                                | (uint16_t)(lpdisc_process_raw(C_RAW_READ, &v_device->s_raw_swi_1) << 1)
                                | (uint16_t)(lpdisc_process_raw(C_RAW_READ, &v_device->s_raw_swi_2) << 2);
      }

      /* Set error flags */
      if (v_device->s_raw_swi_1.s_io_mask != v_device->s_raw_swi_2.s_io_mask)
         lpdisc_mon_2_switch(v_device, v_fault_word);
      else
         lpdisc_mon_1_switch(v_device, v_fault_word);

      /* Check & set CMD */
      lpdisc_set_cmd(v_device, v_fault_word, v_command);
   }
}

/* ---------- internal operations: ------------------------------------------ */
