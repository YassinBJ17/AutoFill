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
#include "middleware/lpdisc/lpdisc_private.h"
#include "middleware/lpdisc/lpdisc_process_raw.h"
#include "middleware/lpdisc/lpdisc_cmd_close.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
void lpdisc_cmd_close(ts_lpdisk_device * p_device,
                      tu_lp_fault_word * p_fault_word,
                      uint32_t         * p_command)
{
   p_device->s_open_in_progress = (uint32_t)FALSE;

   switch (p_device->s_state_read)
   {
      case C_LP_ALL_OPEN:
         lpdisc_process_raw(C_RAW_CLOSE, &p_device->s_raw_swi_1);
         /* Report different called state depending on number of switches device has */
         if (p_device->s_raw_swi_1.s_io_mask != p_device->s_raw_swi_2.s_io_mask)
            p_device->s_state_call = C_LP_1_CLOSE_2_OPEN;
         else
            p_device->s_state_call = C_LP_ALL_CLOSE;

         *p_command = C_LP_CMD_NONE;
         break;

      case C_LP_1_CLOSE_2_OPEN:
         lpdisc_process_raw(C_RAW_CLOSE, &p_device->s_raw_swi_2);
         p_device->s_state_call = C_LP_ALL_CLOSE;

         *p_command = C_LP_CMD_NONE;
         break;

      case C_LP_1_OPEN_2_CLOSE:
         p_fault_word->u_bit.s_unexpected_cmd = (uint32_t)TRUE;
         break;

      case C_LP_ALL_CLOSE:
         p_fault_word->u_bit.s_unexpected_cmd = (uint32_t)TRUE;

         *p_command = C_LP_CMD_NONE;
         break;

      default:
         /* Avoid warning */
         break;
   }
}

/* ---------- internal operations: ------------------------------------------ */
