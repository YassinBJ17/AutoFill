/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Compute weighted average TECU final temperature function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/tecu/tecu_public.h"
#include "middleware/rtc/rtc_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */
/* Maximum temperature value */
#define TEMP_MAX          ((float32_t)256.0)
/* Resolution of the temperature : Max temperature (256) * 2 / Max int16_t (32767) */
#define TEMP_RESOLUTION   ((float32_t)0.015625)
/* Shift for the 1st value in the temperature fields */
#define TEMP_SHIFT        ((uint32_t)16)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Internal and external temperature */
uint32_t int_ext_temp;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU-0010 */
/* Implements REQ_FADEX_OS_SRD-TECU-0020 */
/* Implements REQ_FADEX_OS_SRD-TECU-0040 */
/* Implements REQ_FADEX_OS_SRD-TECU-0050 */
/* Compute weighted average TECU final temperature function */
void tecu_compute_avg(const boolean_t channel_is_a)
{

   ts_tecu* shmem_tecu;                /* Pointer to the TECU status of the actual channel   */
   ts_tecu* prev_shmem_tecu;           /* Pointer to the TECU status of the previous RTC */

   float32_t tecu_avg;                 /* Weighted average temperature */
   float32_t sum_w_coeff;              /* Sum of the all weighted coefficient */


   float32_t taccom_w_coeff;           /* Weighted coefficient of the accomodation temperature */
   float32_t tcu1_w_coeff;             /* Weighted coefficient of the control unit temperature */
   float32_t tcu2_w_coeff;             /* Weighted coefficient of the control processing core die temperature */
   float32_t tpsf_w_coeff;             /* Weighted coefficient of the primary supply function temperature */
   float32_t tohs_w_coeff;             /* Weighted coefficient of the overspeed high side temperature */
   float32_t tols_w_coeff;             /* Weighted coefficient of the overspeed low side temperature */
   float32_t tcj_w_coeff;              /* Weighted coefficient of the cold junction temperature */

   /* Temporary variable to store converted temperatures */
   uint16_t tmp_temp1;
   uint16_t tmp_temp2;

   /* Validity of the ECU temperature */
   boolean_t tecu_is_valid = TRUE;

   /**** Initialization of the weighted coefficient ****/
   taccom_w_coeff = 0;       /* accomodation temperature */            /* Set temporary at NULL because the temperature is not available yet */
   tcu1_w_coeff = 1;         /* Control unit temperature */
   tcu2_w_coeff = 1;         /* Control processing core die temperature */
   tpsf_w_coeff = 1;         /* Primary supply function temperature */
   tohs_w_coeff = 0;         /* Overspeed high side temperature */     /* Set temporary at NULL because the temperature is not available yet */
   tols_w_coeff = 0;         /* Overspeed low side temperature */      /* Set temporary at NULL because the temperature is not available yet */
   tcj_w_coeff = 1;          /* Cold junction temperature */

   /* If channel A */
   if(channel_is_a)
   {
      /* The TECU status of the channel A is affected to the status of the actual channel */
      shmem_tecu = &(shmem.s_tecua);

      /* The previous TECU status of channel A is affected to the previous TECU status to the actual channel */
      prev_shmem_tecu = &(prev_tecua_status);
   }
   /* If channel B */
   else
   {
      /* The TECU status of the channel B is affected to the status of the actual channel */
      shmem_tecu = &(shmem.s_tecub);

      /* The previous TECU status of channel B is affected to the previous TECu status to the actual channel */
      prev_shmem_tecu = &(prev_tecub_status);
   }

   /* If the accomodation temperature is inconsistent or out of range */
   /*if ((uint32_t)1 == shmem_tecu->s_fault_word.u_bit.s_err_taccom)*/
   /*{*/
   /*    Set the weighted coefficient of the accomodation temperature to no value */
   /*   taccom_w_coeff = 0;*/
   /*}*/

   /* If the control unit temperature is inconsistent or out of range */
   if ((uint32_t)1 == shmem_tecu->s_fault_word.u_bit.s_err_tcu1)
   {
      /* Set the weighted coefficient of the control unit temperature to no value */
      tcu1_w_coeff = 0;
   }

   /* If the control processing core die temperature is inconsistent or out of range */
   if ((uint32_t)1 == shmem_tecu->s_fault_word.u_bit.s_err_tcu2)
   {
      /* Set the weighted coefficient of the control processing core die temperature to no value */
      tcu2_w_coeff = 0;
   }

   /* If the primary supply function temperature is inconsistent or out of range */
   if ((uint32_t)1 == shmem_tecu->s_fault_word.u_bit.s_err_tpsf)
   {
      /* Set the weighted coefficient of the primary supply function temperature to no value */
      tpsf_w_coeff = 0;
   }

   /* If the overspeed high side temperature is inconsistent or out of range */
   /*if ((uint32_t)1 == shmem_tecu->s_fault_word.u_bit.s_err_tohs)*/
   /*{*/
   /*   Set the weighted coefficient of overspeed high side temperature to no value */
   /*   tohs_w_coeff = 0;*/
   /*}*/

   /* If the overspeed low side temperature is inconsistent or out of range */
   /*if ((uint32_t)1 == shmem_tecu->s_fault_word.u_bit.s_err_tols)*/
   /*{*/
   /*   Set the weighted coefficient of overspeed low side temperature to no value */
   /*   tols_w_coeff = 0;*/
   /*}*/

   /* If the cold junction temperature is inconsistent or out of range */
   if ((uint32_t)1 == shmem_tecu->s_fault_word.u_bit.s_err_tcj)
   {
      /* Set the weighted coefficient of the cold junction temperature to no value */
      tcj_w_coeff = 0;
   }

   /* Compute the sum of the all weighted coefficient */
   sum_w_coeff = taccom_w_coeff + tcu1_w_coeff + tcu2_w_coeff + tpsf_w_coeff + tohs_w_coeff + tols_w_coeff + tcj_w_coeff;

   /* Compute the weighted average temperature */
   tecu_avg = ((filt_taccom * taccom_w_coeff) + (filt_tcu1 * tcu1_w_coeff) + (filt_tcu2 * tcu2_w_coeff) +
              (filt_tpsf * tpsf_w_coeff) + (filt_tohs * tohs_w_coeff) + (filt_tols * tols_w_coeff) +
              (filt_tcj * tcj_w_coeff))/sum_w_coeff;


   /* If the weighted average temperature is out of range */
   if(tecu_avg < TECU_AVG_TEMP_MIN || tecu_avg > TECU_AVG_TEMP_MAX)
   {
      /* Set a fault on the TECU status */
      shmem_tecu->s_fault_word.u_bit.s_out_of_range = (uint32_t)1;

      /* Set the weighted average temperature to the last valid weighted average temperature */
      tecu_avg = last_valid_tecu_avg;
   }

   /* If all tcu1 & tcu2 & tpsf & tcj & tohs & tols & tecu_avg are faulty */
   if(TECU_STATUS_ALL_TEMP_FAULTY == shmem_tecu->s_fault_word.u_word)
   {
      /* Indicate TECU is invalid */
      tecu_is_valid = FALSE;
      /* Set a fault on the TECU status */
      shmem_tecu->s_fault_word.u_bit.s_invalid = (uint32_t)1;

   }

   /* Store the weighted average temperature as the last valid weighted average temperature */
   last_valid_tecu_avg = tecu_avg;

   /* Set the previous TECU status to the current TECU status */
   prev_shmem_tecu->s_fault_word = shmem_tecu->s_fault_word;

   /* Store the weighted average computed temperature to the shared memory */
   shmem_tecu->s_measure = tecu_avg;

   /* When the ECU temperature is valid and is the maximum detected since the last clear of the MRAM */
   if (tecu_is_valid && (tecu_avg > shmem.s_oss_counter.s_max_tecu))
   {
      /* Save maximum valid ECU temperature and its timestamp in shared memory */
      shmem.s_oss_counter.s_max_tecu = tecu_avg;
      shmem.s_oss_counter.s_max_tecu_date.s_power_up_count = shmem.s_oss_counter.s_pw_up_count;
      shmem.s_oss_counter.s_max_tecu_date.s_first_power_up_time = shmem.s_oss_counter.s_first_power_up_time;
      shmem.s_oss_counter.s_max_tecu_date.s_last_power_up_time = rtc_counter;
   }

   /* Compute internal and external temperature */
   /* To put two float32_t in one uint32_t, we use a method which allow to save a float32_t in a uint16_t, */
   /* with a bit of precision loss. */
   /* To do that, we use the following formula (which inherits from fixed-point arithmetic) : */
   /* y = (x + max(x)) / resolution */
   /* With : - y the integer value on 16 bits */
   /*        - x the float value on 32 bits   */
   /*        - max(x) the maximal value of x  */
   /*        - resolution the precisien level */
   tmp_temp1 = (uint16_t)((filt_tcu1 + TEMP_MAX) / TEMP_RESOLUTION);
   tmp_temp2 = (uint16_t)((tecu_avg  + TEMP_MAX) / TEMP_RESOLUTION);
   int_ext_temp = ((uint32_t)tmp_temp1 << TEMP_SHIFT) | (uint32_t)tmp_temp2;
}
/* ---------- internal operations: ------------------------------------------ */
