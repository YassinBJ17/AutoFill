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
#include "middleware/reset/reset_public.h"
#include "middleware/pca9535e/pca9535e_public.h"
#include "middleware/hpdisc/hpdisc_private.h"
#include "middleware/hpdisc/hpdisc_process_raw.h"
#include "middleware/hpdisc/hpdisc_cmd_open.h"
#include "middleware/hpdisc/hpdisc_cmd_close.h"
#include "middleware/hpdisc/hpdisc_cmd_none.h"
#include "middleware/hpdisc/hpdisc_set_cmd.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/*  */
void hpdisc_set_cmd(ts_hpdisk_device * p_device,
                    tu_hp_fault_word * p_fault_word,
                    uint32_t         * p_command)
{
   /* Generic conditions */
   p_fault_word->u_bit.s_unexpected_cmd = (uint32_t)FALSE;
   p_device->s_state_call               = p_device->s_state_read;

   /* Process new switch's state */
   switch (*p_command)
   {
      case C_HP_CMD_OPEN:
         hpdisc_cmd_open(p_device, p_fault_word, p_command);
         break;

      case C_HP_CMD_CLOSE:
         hpdisc_cmd_close(p_device, p_fault_word, p_command);
         break;

      case C_HP_CMD_NONE:
         hpdisc_cmd_none(p_device, p_fault_word, p_command);
        break;

      default: /* Unknown command */
         /* Change switches state to "open" */
         hpdisc_process_raw(C_RAW_OPEN, &p_device->s_raw_swi_1);
         hpdisc_process_raw(C_RAW_OPEN, &p_device->s_raw_swi_2);
         p_device->s_state_call = C_HP_ALL_OPEN;

         /* Update HW state */
         pca9535e_write_all();

         /*************************************/
         /* We SHOULD reset calculator _HERE_ */
         /*************************************/
         reset_critical();
         break;
   }

   /* Complete general invalid status */
   p_fault_word->u_bit.s_invalid |= p_fault_word->u_bit.s_unexpected_cmd;
}

/* ---------- internal operations: ------------------------------------------ */
