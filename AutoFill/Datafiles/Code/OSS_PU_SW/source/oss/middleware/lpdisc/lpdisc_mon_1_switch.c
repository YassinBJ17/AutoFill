/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Manage FaultWord for LP with one switches (LP 1, 2, 3, 4, 9)
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/lpdisc/lpdisc_private.h"
#include "middleware/lpdisc/lpdisc_process_raw.h"
#include "middleware/lpdisc/lpdisc_mon_1_switch.h"

/* ---------- internal define constants: ------------------------------------ */
/* Invalid status masks */
#define C_MASK_LP_1_SWITCH_INVALD    ((uint32_t)0xDA000020)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LPDISC-0070 */
/* Manage FaultWord for LP with one switches (LP 1, 2, 3, 4, 9) */
void lpdisc_mon_1_switch(ts_lpdisk_device * p_device,
                         tu_lp_fault_word * p_fault_word)
{
   boolean_t v_flag;
   boolean_t v_status;
   boolean_t v_switch_1;


   if ((uint32_t)TRUE == p_fault_word->u_bit.s_unexpected_cmd)
   {
      p_fault_word->u_bit.s_out_short_ls_to_gnd = (uint32_t)FALSE;
      p_fault_word->u_bit.s_cmd_failed          = (uint32_t)FALSE;
      p_fault_word->u_bit.s_out_short_diff      = (uint32_t)FALSE;
      p_fault_word->u_bit.s_sw1_faulty          = (uint32_t)FALSE;
      p_fault_word->u_bit.s_out_open_circuit    = (uint32_t)FALSE;
   }
   else
   {
      /* Check if I2C command failed */
      v_status   = (boolean_t)lpdisc_process_raw(C_RAW_READ, &p_device->s_raw_status);
      v_switch_1 = (boolean_t)lpdisc_process_raw(C_RAW_READ, &p_device->s_raw_swi_1);

      v_flag = (p_device->s_state_read != p_device->s_state_call || v_status != v_switch_1);

      /* Process status setting according to read state */
      switch (p_device->s_state_read)
      {
         case C_LP_ALL_OPEN:
            p_fault_word->u_bit.s_out_open_circuit    = (uint32_t)v_flag;
            p_fault_word->u_bit.s_sw1_faulty          = (uint32_t)v_flag;
            p_fault_word->u_bit.s_out_short_ls_to_gnd = (uint32_t)v_flag;

            p_fault_word->u_bit.s_cmd_failed     = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_short_diff = (uint32_t)FALSE;
            break;

         case C_LP_ALL_CLOSE:
            p_fault_word->u_bit.s_cmd_failed     = (uint32_t)v_flag;
            p_fault_word->u_bit.s_out_short_diff = (uint32_t)v_flag;

            p_fault_word->u_bit.s_out_open_circuit    = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_short_ls_to_gnd = (uint32_t)FALSE;
            p_fault_word->u_bit.s_sw1_faulty          = (uint32_t)FALSE;
            break;

         default:
            /* Should not happen */
            p_fault_word->u_bit.s_out_short_ls_to_gnd = (uint32_t)FALSE;
            p_fault_word->u_bit.s_cmd_failed          = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_short_diff      = (uint32_t)FALSE;
            p_fault_word->u_bit.s_sw1_faulty          = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_open_circuit    = (uint32_t)FALSE;
            break;
      }
   }

   /* Set general invalid status */
   v_flag = ((p_fault_word->u_word & C_MASK_LP_1_SWITCH_INVALD) != (uint32_t)0);
   p_fault_word->u_bit.s_invalid = (uint32_t)v_flag;
}

/* ---------- internal operations: ------------------------------------------ */
