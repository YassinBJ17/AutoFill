/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Smot CBIT
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/smot/smot_gpio_common.h"
#include "middleware/smot/smot_write_public.h"
#include "middleware/smot/smot_fpga_reg_common.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/smot/smot_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ------ --- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SMOT-0020 */
/* Smot CBIT */
void smot_cbit(const uint32_t* p_smot_ph_state_idx, /* in */
               const float32_t* p_smot_mon_voltage, /* in */
               const float32_t* p_smot_mon_current) /* in */
{

   /* If the smot is not rotating */
   if((uint32_t)0 == smot_fpga_reg->s_smot_status_reg.u_bit.s_smot_busy)
   {
      /* If the smot computed position is not equal to the FPGA command feedback and smote phase state fedback */
      if (smot_expected_position != smot_fpga_reg->s_smot_status_reg.u_bit.s_smot_position || smot_expected_position != *p_smot_ph_state_idx)
      {
         /* Indicate the css previous command is faulty to the CSS_PU */
         shmem.s_smot_w.s_fault_word.u_bit.s_err_sequence = (uint32_t)1;

         /* Indicate at least one fault is detected to the CSS_PU */
         shmem.s_smot_w.s_fault_word.u_bit.s_invalid = (uint32_t)1;
      }

      /* If the smot monitoring voltage > 50V  AND smot monitoring current < 0.05A */
      if (*p_smot_mon_voltage>SMOT_VOLT_HIGH_TH && *p_smot_mon_current<SMOT_CURR_LOW_TH)
      {
         /* Indicate the open circuit is occured on the controlled phase */
         shmem.s_smot_w.s_fault_word.u_bit.s_output_phase_oc  = (uint32_t)1;

         /* Indicate the open circuit is occured on the common voltage */
         shmem.s_smot_w.s_fault_word.u_bit.s_oc_common_voltage = (uint32_t)1;

         /* Indicate at least one fault is detected to the CSS_PU */
         shmem.s_smot_w.s_fault_word.u_bit.s_invalid = (uint32_t)1;
      }
      /* If the smot monitoring voltage < 10V  AND smot monitoring current < 0.05A */
      if (*p_smot_mon_voltage<SMOT_VOLT_LOW_TH && *p_smot_mon_current<SMOT_CURR_LOW_TH_COM_SC_TO_GND)
      {
         /* Indicate the short circuit on the high side */
         shmem.s_smot_w.s_fault_word.u_bit.s_short_gnd_common_voltage = (uint32_t)1;

         /* Indicate at least one fault is detected to the CSS_PU */
         shmem.s_smot_w.s_fault_word.u_bit.s_invalid = (uint32_t)1;
      }
      /* If the smot monitoring voltage < 10V  AND smot monitoring current > 0.4A */
      if (*p_smot_mon_voltage<SMOT_VOLT_LOW_TH && *p_smot_mon_current>SMOT_CURR_HIGH_TH)
      {
         /* Indicate the differential short circuit */
         shmem.s_smot_w.s_fault_word.u_bit.s_short_diff = (uint32_t)1;

         /* Indicate at least one fault is detected to the CSS_PU */
         shmem.s_smot_w.s_fault_word.u_bit.s_invalid = (uint32_t)1;
      }
      /* If the smot monitoring current > 0.55A */
      if (*p_smot_mon_current > SMOT_CURR_HIGH_TH_BIS)
      {
         /* Indicate the smot monitoring current is out of range */
         shmem.s_smot_w.s_fault_word.u_bit.s_i_phase_out_of_range  = (uint32_t)1;

         /* Indicate at least one fault is detected to the CSS_PU */
         shmem.s_smot_w.s_fault_word.u_bit.s_invalid = (uint32_t)1;
      }


      /*If the smot expected position indicates that only one phase of the smot should be controlled */
      if ((uint32_t)0 == smot_expected_position%2)
      {
         /*If the smot volt < 50V AND the smot current < 0.1A OR the smot phases feedback indicates that more than 1 phase is controlled */
         if (*p_smot_mon_voltage<SMOT_VOLT_HIGH_TH && *p_smot_mon_current<SMOT_CURR_LOW_TH_SC_GND_TO_LS_SINGLE || ((uint32_t)0 != *p_smot_ph_state_idx%2 || *p_smot_ph_state_idx >= (uint32_t)SMOT_POS_NB || *p_smot_ph_state_idx < (uint32_t)0))
         {
            /* Indicate the short circuit on the low side */
            shmem.s_smot_w.s_fault_word.u_bit.s_short_to_gnd_ls = (uint32_t)1;

            /* Indicate at least one fault is detected to the CSS_PU */
            shmem.s_smot_w.s_fault_word.u_bit.s_invalid = (uint32_t)1;
         }

         /* If the smot volt < 50V AND the smot current > 0.4A AND the smot phases feedback indicates that more than 1 phase is controlled */
         if (*p_smot_mon_voltage<SMOT_VOLT_HIGH_TH && *p_smot_mon_current>SMOT_CURR_HIGH_TH && ((uint32_t)0 != *p_smot_ph_state_idx%2 || *p_smot_ph_state_idx >= (uint32_t)SMOT_POS_NB || *p_smot_ph_state_idx < (uint32_t)0))
         {
            /* Indicate the short circuit between phases */
            shmem.s_smot_w.s_fault_word.u_bit.s_short_between_phases = (uint32_t)1;

            /* Indicate at least one fault is detected to the CSS_PU */
            shmem.s_smot_w.s_fault_word.u_bit.s_invalid = (uint32_t)1;
         }
      }
      /*If the smot expected position indicates that two phases of the smot should be controlled */
      else
      {
         /*If the smot volt < 50V AND 0.05A <smot current<0.3A OR the smot phases feedback indicates that more than 2 phases are controlled */
         if ((*p_smot_mon_voltage<SMOT_VOLT_HIGH_TH) && (SMOT_CURR_LOW_TH<*p_smot_mon_current && *p_smot_mon_current<SMOT_CURR_MID_TH) || (*p_smot_ph_state_idx >= (uint32_t)SMOT_POS_NB || *p_smot_ph_state_idx < (uint32_t)0))
         {
            /* Indicate the short circuit on the low side */
            shmem.s_smot_w.s_fault_word.u_bit.s_short_to_gnd_ls = (uint32_t)1;

            /* Indicate at least one fault is detected to the CSS_PU */
            shmem.s_smot_w.s_fault_word.u_bit.s_invalid = (uint32_t)1;
         }

         /* If the smot volt < 50V AND the smot current > 0.4A AND the smot phases feedback indicates that more than 2 phases are controlled */
         if ((*p_smot_mon_voltage<SMOT_VOLT_HIGH_TH) && (*p_smot_mon_current>SMOT_CURR_HIGH_TH) && (*p_smot_ph_state_idx >= (uint32_t)SMOT_POS_NB || *p_smot_ph_state_idx < (uint32_t)0))
         {
            /* Indicate the short circuit between phases */
            shmem.s_smot_w.s_fault_word.u_bit.s_short_between_phases = (uint32_t)1;

            /* Indicate at least one fault is detected to the CSS_PU */
            shmem.s_smot_w.s_fault_word.u_bit.s_invalid = (uint32_t)1;
         }
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
