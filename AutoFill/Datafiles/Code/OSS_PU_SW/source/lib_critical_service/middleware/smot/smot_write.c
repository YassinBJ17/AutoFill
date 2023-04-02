/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Transmit the CSS_PU command to FPGA when the command is valid
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "middleware/smot/smot_write_public.h"
#include "middleware/smot/smot_private.h"
#include "middleware/smot/smot_gpio_common.h"
#include "middleware/smot/smot_fpga_reg_common.h"
#include "memory/lib_critical_service_section_def_data.h"

extern float32_t LIB_MATH_FABS(const float32_t p_input);

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Smot speed configuration (Time to move one half step in second) */
float32_t smot_speed_time;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SMOT-0001 */
/* Transmit the CSS_PU command to FPGA when the command is valid */
void smot_write(void)
{

   uint32_t smot_ph_state_idx;         /*Smot phase state index */
   float32_t smot_mon_voltage;         /* Smot monitoring voltage (acquired from SARADC_B) */
   float32_t smot_mon_current;         /* Smot monitoring current (acquired from SARADC_B) */


   /* Cancel any previous command to avoid problems when sign bit is set */
   smot_fpga_reg->s_smot_cmd_reg.u_bit.s_inc_cmd = 0;

   /* Acquire the smot monitoring data  */
   smot_acquire_samples(&smot_mon_voltage, &smot_mon_current);
   /* Acquire the smot phases state and affect it an index */
   smot_ph_state_acq(&smot_ph_state_idx);

   /* Set the smot write status to no fault */
   shmem.s_smot_w.s_fault_word.u_word = SMOT_STATUS_NO_FAULT;

   /* Update the smot CBIT fault word */
   smot_cbit(&smot_ph_state_idx,&smot_mon_voltage,&smot_mon_current);

   /* Transmit the smot monitoring data to the CSS_PU */
   shmem.s_smot_w.s_voltage = smot_mon_voltage;           /* SMOT_voltage */
   shmem.s_smot_w.s_current = smot_mon_current;           /* SMOT_current */
   shmem.s_smot_w.s_position = smot_ph_state_idx;         /* SMOT_Position */

   /* If the smot computed position is equal to the FPGA command feedback and smote phase state fedback */
   if (smot_expected_position != smot_fpga_reg->s_smot_status_reg.u_bit.s_smot_position || smot_expected_position != smot_ph_state_idx)
   {
      /* Indicate the css previous command is faulty to the CSS_PU */
      shmem.s_smot_w.s_fault_word.u_bit.s_err_sequence = (uint32_t)1;

      /* Indicate at least one fault is detected to the CSS_PU */
      shmem.s_smot_w.s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /* Store the smot phase current state  */
   smot_ph_prev_state_idx = smot_ph_state_idx;

   /* If the smot is rotating */
   if((uint32_t)1 == smot_fpga_reg->s_smot_status_reg.u_bit.s_smot_busy)
   {
      /* Indicate the smot is still rotating and the CSS_PU request is rejected */
      shmem.s_smot_w.s_fault_word.u_bit.s_busy = (uint32_t)1;

      /* Indicate at least one fault is detected to the CSS_PU */
      shmem.s_smot_w.s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /* If the number of half steps command is positive */
   if(shmem.s_smot_w.s_half_step_nb >= (int32_t)0)
   {
      /* Set the FPGA to the increment mode */
      smot_fpga_reg->s_smot_cmd_reg.u_bit.s_inc_sign = (uint32_t)1;

      /* If the CSS_PU request could not be executed before the next critical service */
      if (shmem.s_smot_w.s_half_step_nb * smot_speed_time > SRV_CALL_DELAY)
      {
         /* Indicate the CSS_PU request is out of the expected range (Fatal error) */
         shmem.s_smot_w.s_fault_word.u_bit.s_css_cmd_out_of_range = (uint32_t)1;

         /* Indicate at least one fault is detected to the CSS_PU */
         shmem.s_smot_w.s_fault_word.u_bit.s_invalid = (uint32_t)1;
      }

   }
   /* If the number of half steps command is negative */
   else
   {
      /* Set the FPGA to the decrement mode */
      smot_fpga_reg->s_smot_cmd_reg.u_bit.s_inc_sign = (uint32_t)0;

      /* If the CSS_PU request could not be executed before the next critical service */
      if (-shmem.s_smot_w.s_half_step_nb * smot_speed_time > SRV_CALL_DELAY)
      {
         /* Indicate the CSS_PU request is out of the expected range (Fatal error) */
         shmem.s_smot_w.s_fault_word.u_bit.s_css_cmd_out_of_range = (uint32_t)1;

         /* Indicate at least one fault is detected to the CSS_PU */
         shmem.s_smot_w.s_fault_word.u_bit.s_invalid = (uint32_t)1;
      }
   }

   /* If the SM is not rotating (FPGA indication) and the CSS_PU orders a command && the CSS_PU command is in the expected range */
   if ((uint32_t)0 == smot_fpga_reg->s_smot_status_reg.u_bit.s_smot_busy && (int32_t)0 != shmem.s_smot_w.s_half_step_nb &&
       (uint32_t)0 == shmem.s_smot_w.s_fault_word.u_bit.s_css_cmd_out_of_range)
   {
      /* Transmit the CSS_PU command to the FPGA  */
      {
         uint32_t cmd_to_fpga;
         /* If the CSS_PU command is positive */
         if(shmem.s_smot_w.s_half_step_nb >= 0)
         {
            cmd_to_fpga = (uint32_t)shmem.s_smot_w.s_half_step_nb;
         }
         /* If the CSS_PU command is negative */
         else
         {
            cmd_to_fpga = (uint32_t)(-shmem.s_smot_w.s_half_step_nb);
         }

         /* Transmit the CSS_PU command to the FPGA */
         smot_fpga_reg->s_smot_cmd_reg.u_bit.s_inc_cmd = cmd_to_fpga;
     }
   }

   /* If the CSS_PU request has not been rejected */
   if ((uint32_t)0 == shmem.s_smot_w.s_fault_word.u_bit.s_css_cmd_out_of_range && (uint32_t)0 == shmem.s_smot_w.s_fault_word.u_bit.s_busy)
   {
      /* Store the current CSS_PU command */
         /* Store the smot command for the next smot service call */
         smot_previous_incr_cmd = shmem.s_smot_w.s_half_step_nb;

         if(shmem.s_smot_w.s_half_step_nb >= 0)
         {
            /* Compute the smot expected position for the next service call check */
            smot_expected_position = (smot_previous_incr_cmd + smot_ph_prev_state_idx)%SMOT_POS_NB;
         }
         else
         {
            /* Compute the smot expected position for the next service call check */
            smot_expected_position = (uint32_t)LIB_MATH_FABS((smot_previous_incr_cmd + smot_ph_prev_state_idx)%SMOT_POS_NB);
         }


   }
   else
   {
      /* Set the CSS_PU previous command to no command */
      smot_previous_incr_cmd = (int32_t)0;
   }

      /* Set the CSS_PU increment command to no command */
      shmem.s_smot_w.s_half_step_nb = (int32_t)0;
}

/* ---------- internal operations: ------------------------------------------ */
