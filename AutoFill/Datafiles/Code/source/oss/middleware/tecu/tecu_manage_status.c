/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : TECU status management function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/tecu/tecu_public.h"
#include "middleware/tecu/tecu_private.h"
#include "middleware/t4/t4_public.h"
#include "middleware/rtc/rtc_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

float32_t taccom;   /* Accommodation temperature */
float32_t tcu1;     /* Control unit temperature (provided from ADT7310 sensor) */
float32_t tcu2;     /* Control processing core die temperature (provided from the internal processor sensor) */
float32_t tpsf;     /* Primary power supply temperature (provided from TMP116 sensor) */
float32_t tohs;     /* The overspeed high side temperature */
float32_t tols;     /* The overspeed low side temperature */

/* The control unit temperature sensor ID */
uint16_t tcu1_sensor_id;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU-0001 */
/* TECU status management function */
void tecu_manage_status(const boolean_t channel_is_a)
{

   ts_tecu* shmem_tecu;                     /* Pointer to the TECU status of the actual channel */

   boolean_t tcu1_flag;                     /* Control unit temperature inconsistency flag */
   boolean_t tpsf_flag;                     /* Primary power supply temperature inconsistency flag */
   boolean_t tcu2_flag;                     /* Control processing core die temperature inconsistency flag */
   boolean_t tcj_flag;                      /* Cold junction temperature inconsistency flag */

   uint16_t sensor_id;                 /* The control unit temperature sensor ID */

   uint32_t test;

   shmem.s_tecua.s_fault_word.u_word = (uint32_t)0;    /* Initialiaze the TECU status of the channel A */
   shmem.s_tecub.s_fault_word.u_word = (uint32_t)0;    /* Initialiaze the TECU status of the channel B */

   /* Initialize temperatures' inconsistency flag */
   tcu1_flag = (boolean_t)0;
   tpsf_flag = (boolean_t)0;
   tcu2_flag = (boolean_t)0;
   tcj_flag  = (boolean_t)0;

   /* Acquire the primary power supply temperature */
   tecu_acq_tpsf();
   /* Acquire the control unit temperature */
   tecu_acq_tcu1(&sensor_id);
   /* Acquire the control processing core die temperature */
   tecu_acq_tcu2();

   test = (uint32_t)(tcu1_sensor_id ^ 0x18);

   /********************ACCOM TEMPERATURE IS NOT REQUIRED ON THE BLUE LABEL ****************************/
   /* Check if the accom temperature is more than 10degC different from the previous value */
   /* tecu_inconsistency_check(&prev_accom_temp,&accom_temp,&accom_temp_flag); */
   /* Check if the control unit temperature is more than 10degC different from the previous value */
   tecu_inconsistency_check(prev_tcu1,tcu1,tecu_err_indic.u_bit.tcu1_err,&tcu1_flag);
   /* Check  if the processing core die temperature is more than 10degC different from the previous value */
   tecu_inconsistency_check(prev_tcu2,tcu2,tecu_err_indic.u_bit.tcu2_err,&tcu2_flag);
   /* Check if the primary power supply temperature is more than 10degC different from the previous value */
   tecu_inconsistency_check(prev_tpsf,tpsf,tecu_err_indic.u_bit.tpsf_err,&tpsf_flag);
   /* Check if cold junction temperature is more than 10degC different from the previous value */
   tecu_inconsistency_check(prev_filt_tcj,tcj_conv,tecu_err_indic.u_bit.tcj_err,&tcj_flag);

   /* Check if the overspeed high side temperature is more than 10degC different from the previous value */
   /* tecu_inconsistency_check(&prev_ovsp_hs_temp,&ovsp_hs_temp,&ovsp_hs_temp_flag,&tohs_err); */

   /* Check if the overspeed low side temperature is more than 10degC different from the previous value */
   /* tecu_inconsistency_check(&prev_ovsp_ls_temp,&ovsp_ls_temp,&ovsp_ls_temp_flag,&tols_err); */

   /*** Initialize the TECU temperatures erroneous value indicators ***/
   tecu_err_indic.u_word = (uint32_t)0;


   /* If channel A */
   if(channel_is_a)
   {
      /* The TECU status of the channel A is affected to the status of the actual channel */
      shmem_tecu = &(shmem.s_tecua);
   }
   /* If channel B */
   else
   {
      /* The TECU status of the channel B is affected to the status of the actual channel */
      shmem_tecu = &(shmem.s_tecub);
   }

      /********************ACCOM TEMPERATURE IS NOT REQUIRED ON THE BLUE LABEL ****************************/
      /* If the control accom temperature is out of the range or is more than 10degC different from the previous value */
      /*if(accom_temp<CONTROL_UNIT_1_TEMP_MIN || accom_temp>CONTROL_UNIT_1_TEMP_MAX || accom_temp_flag)*/
      /*{*/
      /*    Set the fault to the TECU status */
      /*     TO DO : According to the BITE, the accom temperature fault bit is still not present on the TECU status */
      /*}*/
      /********************ACCOM TEMPERATURE IS NOT REQUIRED ON THE BLUE LABEL ****************************/

      /* If the control unit temperature is out of the range or is more than 10degC different from the previous value */
      if(tcu1 < CONTROL_UNIT_1_TEMP_MIN || tcu1 > CONTROL_UNIT_1_TEMP_MAX || tcu1_flag ||(uint32_t)0 != test/*(uint32_t)(tcu1_sensor_id ^ 0x18)*/)
      {
         /* Set the fault to the TECU status */
         shmem_tecu->s_fault_word.u_bit.s_err_tcu1 = (uint32_t)1;
         /* Indicate that the control unit temperature is erroneous for the inconsistency check of the next RTC */
         tecu_err_indic.u_bit.tcu1_err = (uint32_t)1;
      }
      else
      {
         /* Set the previous control unit temperature to the current control unit temperature */
         prev_tcu1 = tcu1;
      }

      /* If the control processing core die temperature is out of the range or is more than 10degC different from the previous value */
      if(tcu2 < CONTROL_UNIT_2_TEMP_MIN || tcu2 > CONTROL_UNIT_2_TEMP_MAX || tcu2_flag)
      {
         /* Set the fault to the TECU status */
         shmem_tecu->s_fault_word.u_bit.s_err_tcu2 = (uint32_t)1;
         /* Indicate that the control unit temperature is erroneous for the inconsistency check of the next RTC */
         tecu_err_indic.u_bit.tcu2_err = (uint32_t)1;
      }
      else
      {
         /* Set the control processing core die temperature temperature to the current temperature */
         prev_tcu2 = tcu2;
      }


      /* If the primary power supply temperature is out of the range or is more than 10degC different from the previous value */
      if(tpsf < TPSF_TEMP_MIN || tpsf > TPSF_TEMP_MAX || tpsf_flag)
      {
         /* Set the fault to the TECU status */
         shmem_tecu->s_fault_word.u_bit.s_err_tpsf = (uint32_t)1;
         /* Indicate the primary power supply temperature is erroneous for the inconsistency check of the next RTC */
         tecu_err_indic.u_bit.tpsf_err = (uint32_t)1;
      }
      else
      {
         /* Set the primary power supply temperature temperature to the current the primary power supply temperature */
         prev_tpsf = tpsf;
      }

      /* If the cold junction temperature is out of the range or is more than 10degC different from the previous value */
      if(tcj_conv < TCJ_TEMP_MIN || tcj_conv > TCJ_TEMP_MAX || tcj_flag)
      {
         /* Set the fault to the TECU status */
         shmem_tecu->s_fault_word.u_bit.s_err_tcj = (uint32_t)1;
         /* Indicate that the cold junction temperature is erroneous for the inconsistency check of the next RTC */
         tecu_err_indic.u_bit.tcj_err = (uint32_t)1;
      }
      else
      {
         /* Set the cold junction temperature temperature to the current the cold junction temperature */
         prev_tcj = tcj_conv;
      }

      /****** DRIVER CAN_OVSP IS NOT AVAILABLE SO IT IS NOT POSSIBLE TO ACQUIRE OVERSPEED HIGH SIDE TEMPERATURE *******/
      /* If the overspeed high side temperature is out of the range or is more than 10degC different from the previous value */
      /*if(ovsp_hs_temp<TOHS_TEMP_MIN || ovsp_hs_temp>TOHS_TEMP_MAX || ovsp_hs_temp_flag)*/
      /*{*/
      /*    Set the fault to the TECU status */
      /*   shmem_tecu->s_fault_word.u_bit.s_err_tohs = (uint32_t)1;*/
      /*    Indicate that the control unit temperature is erroneous for the inconsistency check of the next RTC */
      /*   tecu_err_indic.u_bit.tohs_err = (uint32_t)1;*/
      /*}*/


      /****** DRIVER CAN_OVSP IS NOT AVAILABLE SO IT IS NOT POSSIBLE TO ACQUIRE OVERSPEED LOW SIDE TEMPERATURE *******/
      /* If the overspeed low side temperature is out of the range or is more than 10degC different from the previous value */
      /*if(ovsp_ls_temp<TOLS_TEMP_MIN || ovsp_ls_temp>TOLS_TEMP_MAX || ovsp_ls_temp_flag)*/
      /*{*/
      /*    Set the fault to the TECU status */
      /*   shmem_tecu->s_fault_word .u_bit.s_err_tols = (uint32_t)1;*/
      /*    Indicate that the control unit temperature is erroneous for the inconsistency check of the next RTC */
      /*   tecu_err_indic.u_bit.tols_err = (uint32_t)1;*/
      /*}*/

}

/* ---------- internal operations: ------------------------------------------ */
