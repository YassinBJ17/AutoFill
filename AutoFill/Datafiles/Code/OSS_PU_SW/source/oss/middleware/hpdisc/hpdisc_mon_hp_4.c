/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Manage FaultWord for HP 4
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "driver/adc/ADC_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/hpdisc/hpdisc_private.h"
#include "middleware/hpdisc/hpdisc_process_raw.h"
#include "middleware/hpdisc/hpdisc_mon_hp_4.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
/* Invalid status masks */
#define C_MASK_HP_4_INVALD    ((uint32_t)0xFE020020)

/* SARADC_B gains (source: BSIS_CPMB draft 7.docm) */
#define C_HP4_VOLTAGE_GAIN  ((float32_t)2.5431E-2)
#define C_HP4_CURRENT_GAIN  ((float32_t)4.08672-4)

/* Measured voltage boundaries */
#define C_HP4_DIFF_VOLT_HIGH_THR ((float32_t)6.0)
#define C_HP4_DIFF_VOLT_LOW_THR  ((float32_t)6.0)

/* Measured current boundaries */
#define C_HP4_CURR_HIGH_THR      ((float32_t)0.02)
#define C_HP4_CURR_LOW_THR       ((float32_t)0.02)

/* ---------- provided data: ------------------------------------------------ */
/* HP 4 mon current and voltage */
float32_t hpdisc_current_mon;
float32_t hpdisc_voltage_mon;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0070 */
/* Manage FaultWord for HP 4 */
void hpdisc_mon_hp_4(ts_hpdisk_device * p_device,
                     tu_hp_fault_word * p_fault_word)
{
   boolean_t v_flag;
   uint16_t  v_current_raw;
   uint16_t  v_voltage_raw;

   /* Get current monitoring value */
   ADC_BUFFER_READ((CMN_IOSP_ID_t)e_CFEX_ADC_INT_AN70,
                   (CMN_SYSTEM_ADDR_t)&v_current_raw);

   hpdisc_current_mon = (float32_t)v_current_raw * C_HP4_CURRENT_GAIN;

   /* Get voltage monitoring value */
   ADC_BUFFER_READ((CMN_IOSP_ID_t)e_CFEX_ADC_INT_AN71,
                   (CMN_SYSTEM_ADDR_t)&v_voltage_raw);

   hpdisc_voltage_mon = (float32_t)v_voltage_raw * C_HP4_VOLTAGE_GAIN;

   /* Process fault word */
   if ((uint32_t)TRUE == p_fault_word->u_bit.s_unexpected_cmd)
   {
      p_fault_word->u_bit.s_out_short_hs_to_gnd = (uint32_t)FALSE;
      p_fault_word->u_bit.s_out_short_ls_to_gnd = (uint32_t)FALSE;
      p_fault_word->u_bit.s_out_short_diff      = (uint32_t)FALSE;
      p_fault_word->u_bit.s_cmd_failed          = (uint32_t)FALSE;
      p_fault_word->u_bit.s_sw1_faulty          = (uint32_t)FALSE;
      p_fault_word->u_bit.s_sw2_faulty          = (uint32_t)FALSE;
      p_fault_word->u_bit.s_out_open_circuit    = (uint32_t)FALSE;

      p_fault_word->u_bit.s_signature_fault     = (uint32_t)FALSE;
   }
   else
   {
      switch (p_device->s_state_read)
      {
         case C_HP_ALL_OPEN:
            if (hpdisc_voltage_mon > C_HP4_DIFF_VOLT_HIGH_THR && hpdisc_current_mon > C_HP4_CURR_HIGH_THR)
            {
               /* Error condition */
               p_fault_word->u_bit.s_sw1_faulty = (uint32_t)TRUE;
               p_fault_word->u_bit.s_sw2_faulty = (uint32_t)TRUE;

               p_fault_word->u_bit.s_signature_fault = (uint32_t)FALSE;
            }
            else if (hpdisc_voltage_mon < C_HP4_DIFF_VOLT_LOW_THR && hpdisc_current_mon < C_HP4_CURR_LOW_THR)
            {
               /* Nominal condition */
               p_fault_word->u_bit.s_sw1_faulty = (uint32_t)FALSE;
               p_fault_word->u_bit.s_sw2_faulty = (uint32_t)FALSE;

               p_fault_word->u_bit.s_signature_fault = (uint32_t)FALSE;
            }

            else
            {
               /* undetermined fault signature */
               p_fault_word->u_bit.s_sw1_faulty = (uint32_t)FALSE;
               p_fault_word->u_bit.s_sw2_faulty = (uint32_t)FALSE;

               p_fault_word->u_bit.s_signature_fault = (uint32_t)TRUE;
            }

            p_fault_word->u_bit.s_out_short_hs_to_gnd = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_short_ls_to_gnd = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_short_diff      = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_open_circuit    = (uint32_t)FALSE;
            p_fault_word->u_bit.s_cmd_failed          = (uint32_t)FALSE;
            break;

         case C_HP_1_CLOSE_2_OPEN:
            if (hpdisc_voltage_mon > C_HP4_DIFF_VOLT_HIGH_THR && hpdisc_current_mon > C_HP4_CURR_HIGH_THR)
            {
               /* Error condition */
               p_fault_word->u_bit.s_out_short_ls_to_gnd = (uint32_t)TRUE;
               p_fault_word->u_bit.s_sw2_faulty          = (uint32_t)TRUE;

               p_fault_word->u_bit.s_signature_fault = (uint32_t)FALSE;
            }
            else if (hpdisc_voltage_mon < C_HP4_DIFF_VOLT_LOW_THR && hpdisc_current_mon < C_HP4_CURR_LOW_THR)
            {
               /* Nominal condition */
               p_fault_word->u_bit.s_out_short_ls_to_gnd = (uint32_t)FALSE;
               p_fault_word->u_bit.s_sw2_faulty          = (uint32_t)FALSE;

               p_fault_word->u_bit.s_signature_fault = (uint32_t)FALSE;
            }
            else
            {
               /* undetermined fault signature */
               p_fault_word->u_bit.s_out_short_ls_to_gnd = (uint32_t)FALSE;
               p_fault_word->u_bit.s_sw2_faulty          = (uint32_t)FALSE;

               p_fault_word->u_bit.s_signature_fault = (uint32_t)TRUE;
            }

            p_fault_word->u_bit.s_out_short_hs_to_gnd = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_short_diff      = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_open_circuit    = (uint32_t)FALSE;
            p_fault_word->u_bit.s_sw1_faulty          = (uint32_t)FALSE;
            p_fault_word->u_bit.s_cmd_failed          = (uint32_t)FALSE;
            break;

         case C_HP_1_OPEN_2_CLOSE:
            if (hpdisc_voltage_mon > C_HP4_DIFF_VOLT_HIGH_THR && hpdisc_current_mon > C_HP4_CURR_HIGH_THR)
            {
               /* Error condition */
               p_fault_word->u_bit.s_sw1_faulty = (uint32_t)TRUE;

               p_fault_word->u_bit.s_signature_fault = (uint32_t)FALSE;
            }
            else if (hpdisc_voltage_mon < C_HP4_DIFF_VOLT_LOW_THR && hpdisc_current_mon < C_HP4_CURR_LOW_THR)
            {
               /* Nominal condition */
               p_fault_word->u_bit.s_sw1_faulty = (uint32_t)FALSE;

               p_fault_word->u_bit.s_signature_fault = (uint32_t)FALSE;
            }
            else
            {
               /* undetermined fault signature */
               p_fault_word->u_bit.s_sw1_faulty = (uint32_t)FALSE;

               p_fault_word->u_bit.s_signature_fault = (uint32_t)TRUE;
            }

            p_fault_word->u_bit.s_out_short_hs_to_gnd = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_short_ls_to_gnd = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_short_diff      = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_open_circuit    = (uint32_t)FALSE;
            p_fault_word->u_bit.s_sw2_faulty          = (uint32_t)FALSE;
            p_fault_word->u_bit.s_cmd_failed          = (uint32_t)FALSE;
            break;

         case C_HP_ALL_CLOSE:
            if (hpdisc_voltage_mon > C_HP4_DIFF_VOLT_HIGH_THR && hpdisc_current_mon < C_HP4_CURR_LOW_THR)
            {
               /* Error condition #1 */
               p_fault_word->u_bit.s_out_open_circuit    = (uint32_t)TRUE;
               p_fault_word->u_bit.s_out_short_hs_to_gnd = (uint32_t)FALSE;
               p_fault_word->u_bit.s_cmd_failed          = (uint32_t)FALSE;
               p_fault_word->u_bit.s_out_short_diff      = (uint32_t)FALSE;

               p_fault_word->u_bit.s_signature_fault  = (uint32_t)FALSE;
            }
            else if (hpdisc_voltage_mon < C_HP4_DIFF_VOLT_LOW_THR && hpdisc_current_mon < C_HP4_CURR_LOW_THR)
            {
               /* Error condition #2 (disjonction) */
               p_fault_word->u_bit.s_out_open_circuit    = (uint32_t)FALSE;
               p_fault_word->u_bit.s_out_short_hs_to_gnd = (uint32_t)TRUE;
               p_fault_word->u_bit.s_cmd_failed          = (uint32_t)TRUE;
               p_fault_word->u_bit.s_out_short_diff      = (uint32_t)FALSE;

               p_fault_word->u_bit.s_signature_fault  = (uint32_t)FALSE;
            }
            else if (hpdisc_voltage_mon < C_HP4_DIFF_VOLT_LOW_THR && hpdisc_current_mon > C_HP4_CURR_HIGH_THR)
            {
               /* Error condition #3 */
               p_fault_word->u_bit.s_out_open_circuit    = (uint32_t)FALSE;
               p_fault_word->u_bit.s_out_short_hs_to_gnd = (uint32_t)FALSE;
               p_fault_word->u_bit.s_cmd_failed          = (uint32_t)FALSE;
               p_fault_word->u_bit.s_out_short_diff      = (uint32_t)TRUE;

               p_fault_word->u_bit.s_signature_fault  = (uint32_t)FALSE;
            }
            else if (hpdisc_voltage_mon > C_HP4_DIFF_VOLT_LOW_THR && hpdisc_current_mon > C_HP4_CURR_HIGH_THR)
            {
               /* Nominal condition */
               p_fault_word->u_bit.s_out_open_circuit    = (uint32_t)FALSE;
               p_fault_word->u_bit.s_out_short_hs_to_gnd = (uint32_t)FALSE;
               p_fault_word->u_bit.s_cmd_failed          = (uint32_t)FALSE;
               p_fault_word->u_bit.s_out_short_diff      = (uint32_t)FALSE;

               p_fault_word->u_bit.s_signature_fault  = (uint32_t)FALSE;
            }
            else
            {
               /* undetermined fault signature */
               p_fault_word->u_bit.s_out_open_circuit    = (uint32_t)FALSE;
               p_fault_word->u_bit.s_out_short_hs_to_gnd = (uint32_t)FALSE;
               p_fault_word->u_bit.s_cmd_failed          = (uint32_t)FALSE;
               p_fault_word->u_bit.s_out_short_diff      = (uint32_t)FALSE;

               p_fault_word->u_bit.s_signature_fault  = (uint32_t)TRUE;
            }

            p_fault_word->u_bit.s_out_short_ls_to_gnd = (uint32_t)FALSE;
            p_fault_word->u_bit.s_sw1_faulty          = (uint32_t)FALSE;
            p_fault_word->u_bit.s_sw2_faulty          = (uint32_t)FALSE;
            break;

         default:
            /* Should not happen */
            p_fault_word->u_bit.s_out_short_hs_to_gnd = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_short_ls_to_gnd = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_short_diff      = (uint32_t)FALSE;
            p_fault_word->u_bit.s_cmd_failed          = (uint32_t)FALSE;
            p_fault_word->u_bit.s_sw1_faulty          = (uint32_t)FALSE;
            p_fault_word->u_bit.s_sw2_faulty          = (uint32_t)FALSE;
            p_fault_word->u_bit.s_out_open_circuit    = (uint32_t)FALSE;

            p_fault_word->u_bit.s_signature_fault     = (uint32_t)FALSE;
            break;
      }
   }

   /* Check general invalid status */
   v_flag = ((p_fault_word->u_word & C_MASK_HP_4_INVALD) != (uint32_t)0);
   p_fault_word->u_bit.s_invalid = (uint32_t)v_flag;
}

/* ---------- internal operations: ------------------------------------------ */
