/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : VRT status management function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/vrt/vrt_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-VRT-0010 */
/* Implements REQ_FADEX_OS_SRD-VRT-0020 */
/* VRT status management function */
void vrt_status_manage(ts_temp* shmem,                                        /* out */
                       float32_t  const  p_vrtx_cal_resistor,                 /* out */
                       float32_t  const  p_gnd_voltage_avg,                   /* in */
                       float32_t  const  p_vrtx_cal_voltage,                  /* in */
                       float32_t  const  p_vrtx_shunt_cal_current,            /* in */
                       float32_t  const  p_vrtx_cal_voltage_min,              /* in */
                       float32_t  const  p_vrtx_cal_voltage_max,              /* in */
                       float32_t  const  p_vrtx_shunt_cal_current_min,        /* in */
                       float32_t  const  p_vrtx_shunt_cal_current_max,        /* in */
                       float32_t  const  p_gnd_voltage_min,                   /* in */
                       float32_t  const  p_gnd_voltage_max,                   /* in */
                       float32_t  const  p_vrtx_cal_resistor_min,             /* in */
                       float32_t  const  p_vrtx_cal_resistor_max)             /* in */
{

   /* If the VRTx ground average voltage is out of the expected range */
   if(p_gnd_voltage_avg < p_gnd_voltage_min || p_gnd_voltage_avg > p_gnd_voltage_max)
   {
      /* Set an internal fault on the VRTx status word (bit 27) */
      shmem->s_fault_word.u_bit.s_internal_failure = (uint32_t)1;
      /* Set an invalid fault if at least one bit is raised on the VRTx status word */
      shmem->s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /* If the VRTx calibrated voltage is higher than the maximum expected calibrated voltage threshold */
   if(p_vrtx_cal_voltage > p_vrtx_cal_voltage_max)
   {
      /* Set an open circuit on measure on the VRTx status word (bit 0) */
      shmem->s_fault_word.u_bit.s_meas1_oc_fault = (uint32_t)1;
      /* Set an invalid fault if at least one bit is raised on the VRTx status word */
      shmem->s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /* If the VRTx calibrated voltage is lower than the minimum expected calibrated voltage threshold */
   if(p_vrtx_cal_voltage < p_vrtx_cal_voltage_min)
   {
      /* Set a short differential on measure on the VRTx status word (bit 1) */
      shmem->s_fault_word.u_bit.s_meas1_short_diff = (uint32_t)1;
      /* Set an short differential on excitation on the VRTx status word (bit 9) */
      shmem->s_fault_word.u_bit.s_exc_short_diff = (uint32_t)1;
      /* Set an invalid fault if at least one bit is raised on the VRTx status word */
      shmem->s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /* If the VRTx shunt calibrated current is lower than the minimum expected shunt calibrated current threshold */
   if(p_vrtx_shunt_cal_current < p_vrtx_shunt_cal_current_min )
   {
      /* Set an open circuit on excitation on the VRTx status word (bit 8) */
      shmem->s_fault_word.u_bit.s_exc_oc_fault = (uint32_t)1;
      /* Set an invalid fault if at least one bit is raised on the VRTx status word */
      shmem->s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /* If the VRTx shunt calibrated current is greater than the maximum expected shunt calibrated current threshold */
   if(p_vrtx_shunt_cal_current > p_vrtx_shunt_cal_current_max)
   {
      /* Set a short to ground on excitation to the VRTx status word (bit 10) */
      shmem->s_fault_word.u_bit.s_exc_short_gnd = (uint32_t)1;
      /* Set a short to ground on measure to the VRTx status word (bit 2) */
      shmem->s_fault_word.u_bit.s_meas1_short_gnd = (uint32_t)1;
      /* Set an invalid fault if at least one bit fault is raised */
      shmem->s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /* If the VRTx calibrated resistor is out of the range */
   if(p_vrtx_cal_resistor < p_vrtx_cal_resistor_min || p_vrtx_cal_resistor > p_vrtx_cal_resistor_max)
   {
      /* Set an out of range bit on the VRTx status word (bit 24) */
      shmem->s_fault_word.u_bit.s_out_of_range = (uint32_t)1;

      /* Set an invalid fault if at least one bit fault is raised */
      shmem->s_fault_word.u_bit.s_invalid = (uint32_t)1;

   }
}

/* ---------- internal operations: ------------------------------------------ */
