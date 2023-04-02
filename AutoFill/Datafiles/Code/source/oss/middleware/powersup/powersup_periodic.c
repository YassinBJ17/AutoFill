/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Perform periodic function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/powersup/powersup_private.h"
#include "middleware/powersup/powersup_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/oss_section_def_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
float32_t c_voltage_measure;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-POWERSUP-0010 */
/* Implements REQ_FADEX_OS_SRD-POWERSUP-0020 */
/* Implements REQ_FADEX_OS_SRD-POWERSUP-0030 */
/* Acquire 28V A/C measure and perform CBIT */
void powersup_periodic(const boolean_t           channel_is_a)
{
   /* structure to retrieve I2C0 data */
   tu_i2c0              u_i2c0;
   uint32_t             c_i2c0_err;
   uint16_t             c_voltage;
   float32_t            c_alt_freq_meas;
   te_powersup_rearm    e_rearm_need;
   tu_pw_alt_fault_word u_alt_fault_word;
   tu_pw_28v_fault_word u_28v_fault_word;

   /* Initialized value */
   u_i2c0.u_word            = (uint16_t)0;
   c_i2c0_err               = (uint32_t)0;
   c_voltage                = (uint16_t)0;
   c_alt_freq_meas          = (float32_t)0.0;
   u_alt_fault_word.u_word  = (uint32_t)0;
   u_28v_fault_word.u_word  = (uint32_t)0;

   /* Acquire POWERSUP status from I2C and voltage measurement */
   powersup_get(
      channel_is_a,
      &u_i2c0 ,
      &c_i2c0_err,
      &c_voltage,
      &c_alt_freq_meas,
      &e_rearm_need);

   /* Monitoring POWERSUP voltage */
   powersup_monitor(
         &c_voltage);

   /* perform CBIT */
   powersup_cbit(
      &u_i2c0 ,
      &c_i2c0_err,
      &c_voltage,
      &c_alt_freq_meas,
      &u_alt_fault_word,
      &u_28v_fault_word);

   /* Transmit data to store fault words in SHMEM */
   powersup_transmit(
         &u_alt_fault_word.u_word,
         &u_28v_fault_word.u_word);

   /* Alternator rearm service function */
   /* If CSS has required to perform alternator rearm service and if {NGALT} status is invalid */
   if( (e_rearm_need == e_rearm_yes) &&
         (u_alt_fault_word.u_bit.s_invalid == (uint32_t)1) )
   {
      /* perform alternator rearm service */
      powersup_alt_rearm();
      /* Indicate alternator rearm service has been processed by setting cmd in shmem to 0 */
      /* shmem.s_alt_rearm = (uint32_t)0; */
   }
   /* WARNING !!! STEP TO ACQUIRE THE OPPOSITE CHANNEL POWER STATE NEED TO BE CODE */

   return;
}

/* ---------- internal operations: ------------------------------------------ */
