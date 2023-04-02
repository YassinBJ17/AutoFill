/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Periodic process of HP devices
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/hpdisc/hpdisc_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/hpdisc/hpdisc_private.h"
#include "middleware/hpdisc/hpdisc_process_raw.h"
#include "middleware/hpdisc/hpdisc_set_cmd.h"
#include "middleware/hpdisc/hpdisc_mon_hp_1235.h"
#include "middleware/hpdisc/hpdisc_mon_hp_4.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* HP mon state */
uint16_t hpdisc_mon_state[e_HpDeviceMax];

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0020 */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0030 */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0040 */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0050 */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0060 */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0070 */
/* Periodic process of HP devices */
void hpdisc_periodic(void)
{
   te_hpdisc_device_index   v_index;
   ts_hpdisk_device        *v_device;
   tu_hp_fault_word        *v_fault_word;
   uint32_t                *v_command;


   /*==============*/
   /* Process loop */
   for (v_index = (te_hpdisc_device_index)0; v_index < e_HpDeviceMax; v_index++)
   {
      v_device     = &v_hp_devices[v_index];
      v_fault_word = &shmem.s_hp_w.s_hp_status[v_index];
      v_command    = &shmem.s_hp_w.s_hp_command[v_index];

      v_fault_word->u_bit.s_i2c_not_working = (uint32_t)FALSE;

      /* Get current switches state */
      if ((uint8_t)0 != *v_device->s_raw_swi_1.s_err_pointer
      ||  (uint8_t)0 != *v_device->s_raw_swi_2.s_err_pointer)
      {
         v_device->s_state_read                = C_HP_COMM_ERROR;
         v_fault_word->u_bit.s_i2c_not_working = (uint32_t)TRUE;
      }
      else
      {
         v_device->s_state_read = C_HP_ALL_OPEN
                                | (uint16_t)(hpdisc_process_raw(C_RAW_READ, &v_device->s_raw_swi_1) << 1)
                                | (uint16_t)(hpdisc_process_raw(C_RAW_READ, &v_device->s_raw_swi_2) << 2);
      }

      /* Indicate hp mon states for logbook */
      hpdisc_mon_state[v_index] = v_device->s_state_read;

      /* Set error flags */
      if (e_hp_4 == v_index)
         hpdisc_mon_hp_4(v_device, v_fault_word);
      else
         hpdisc_mon_hp_1235(v_device, v_fault_word);

      /* Check & set CMD */
      hpdisc_set_cmd(v_device, v_fault_word, v_command);
   }
}

/* ---------- internal operations: ------------------------------------------ */
