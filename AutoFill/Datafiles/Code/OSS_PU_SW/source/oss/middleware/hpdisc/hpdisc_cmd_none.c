/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/hpdisc/hpdisc_private.h"
#include "middleware/hpdisc/hpdisc_process_raw.h"
#include "middleware/hpdisc/hpdisc_cmd_none.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
void hpdisc_cmd_none(ts_hpdisk_device * p_device,
                     tu_hp_fault_word * p_fault_word,
                     uint32_t         * p_command)
{
   if (C_HP_1_CLOSE_2_OPEN == p_device->s_state_read)
   {
      p_fault_word->u_bit.s_unexpected_cmd = (uint32_t)TRUE;

      hpdisc_process_raw(C_RAW_OPEN, &p_device->s_raw_swi_1);
      p_device->s_state_call = C_HP_ALL_OPEN;

      *p_command = C_HP_CMD_NONE;
   }
   else if (C_HP_1_OPEN_2_CLOSE == p_device->s_state_read
        &&  (uint32_t)TRUE == p_device->s_open_in_progress)
   {
      hpdisc_process_raw(C_RAW_OPEN, &p_device->s_raw_swi_2);
      p_device->s_state_call = C_HP_ALL_OPEN;

      *p_command = C_HP_CMD_NONE;
   }

   p_device->s_open_in_progress = (uint32_t)FALSE;
}

/* ---------- internal operations: ------------------------------------------ */
