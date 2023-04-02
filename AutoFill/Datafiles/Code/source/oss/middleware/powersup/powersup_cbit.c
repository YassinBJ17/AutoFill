/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Perform CBIT to compute fault word
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/powersup/powersup_private.h"
#include "middleware/powersup/powersup_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/oss_section_def_public.h"
#include "memory/lib_critical_service_section_def_data.h"
/*#include "middleware/nfreq/nfreq_private.h"*/


/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-POWERSUP-0010 */
/* Acquire 28V A/C measure and perform CBIT */
void powersup_cbit(
      /* Inputs value */
      const tu_i2c0 *             const i2c0,
      const uint32_t*             const p_i2c0_err,
      const uint16_t*             const p_voltage,
      const float32_t*            const p_alt_freq_meas,
      /* Output values */
      tu_pw_alt_fault_word* const c_alt_fault_word,
      tu_pw_28v_fault_word* const c_28v_fault_word)
{
   /* Local Variable Declaration        */
   float32_t  v_alt_freq_meas;

   /* Initialization Variable           */
   /* Calculus between alternator frequency and NGALT limitation of 330 Hz to set CC value at null */
   v_alt_freq_meas = *p_alt_freq_meas - PWSUP_NGALT_HIGH_FREQ;

   /* Source code start                 */

   /*--- NGALT STEP - START ---*/
   /* If the alternator is not the selected power source */
   /* Indicate the pw NGALT is not selected */

   /* TODO : WARNING !!! TO REMOVE AFTER HW TEST !!! NEED TO PASS PRODUCT TEST */
   if( *p_voltage  >= HEX_EMERG_VOLTAGE_MIN )
   {
      c_alt_fault_word->u_bit.s_not_selected = !(uint32_t)(i2c0->u_bit.s_ac_disc_cmd);
   }else
   {
      c_alt_fault_word->u_bit.s_not_selected = (uint32_t)0;
   }
   /* WARNING !!! TO REMOVE AFTER HW TEST !!! NEED TO PASS PRODUCT TEST */

   /* Indicate the pw NGALT is in open phase */
   c_alt_fault_word->u_bit.s_open_phase = !(uint32_t)(i2c0->u_bit.s_ngatl_oc_stat);

   /* If the alternator frequency is equal or higher than 330 Hz and open phase detection state is fail ( < 0) */
   /* Indicate the pw NGALT short circuit state in case of this condition */
   if( (v_alt_freq_meas >= PWSUP_NULL_CALCULUS) &&
      c_alt_fault_word->u_bit.s_open_phase != POWERSUP_INIT_VALUE )
   {
      /* CC shall set to null */
      c_alt_fault_word->u_bit.s_short_circuit = POWERSUP_INIT_VALUE;
   }
   else
   {
      /* CC shall set to real state */
      c_alt_fault_word->u_bit.s_short_circuit = !(uint32_t)(i2c0->u_bit.s_ngalt_cc_stat);
   }

   /* Transmit I2C error to fault word */
   if( (uint32_t)0 == *p_i2c0_err )
   {
      c_alt_fault_word->u_bit.s_i2c_not_working = (uint32_t)0;
      c_28v_fault_word->u_bit.s_i2c_not_working = (uint32_t)0;
   }
   else
   {
      c_alt_fault_word->u_bit.s_i2c_not_working = (uint32_t)1;
      c_28v_fault_word->u_bit.s_i2c_not_working = (uint32_t)1;
   }

   /* WARNING !!! INVALID BIT FROM I2C */

   /* If at least one fault is detected */
   if ((uint32_t)0 < c_alt_fault_word->u_word)
   {
      /* Indicate at least one fault is detected to the CSS_PU */
      c_alt_fault_word->u_bit.s_invalid = (uint32_t)1;
   }
   /*--- NGALT STEP - END ---*/

   /*--- 28V A/C STEP - START ---*/

   /* If inconsistency between hot switch state and command */

   /* Indicate the low side out of range fault */
   if( V_POWERSUP_ERROR_RTC.u_bit.s_nb_rtc_ls_er == CONST_RTC_LIMIT)
   {
      c_28v_fault_word->u_bit.s_out_of_range_low = (uint32_t)1;
   }else
   {
      c_28v_fault_word->u_bit.s_out_of_range_low = (uint32_t)0;
   }

   /* Indicate the high side out of range fault */
   if( V_POWERSUP_ERROR_RTC.u_bit.s_nb_rtc_hs_er == CONST_RTC_LIMIT)
   {
      c_28v_fault_word->u_bit.s_out_of_range_high = (uint32_t)1;
   }else
   {
      c_28v_fault_word->u_bit.s_out_of_range_high = (uint32_t)0;
   }

   /* If 28V A/C overcurrent or overvoltage */
   /* Indicate the 28V global switch fault */
   c_28v_fault_word->u_bit.s_glob_switch_fault =
         !(uint32_t)(i2c0->u_bit.s_ac_glob_switch_fault);

   /* If inconsistency between hot switch state and command */
   /* TODO : WARNING !!! TO REMOVE AFTER HW TEST !!! NEED TO PASS PRODUCT TEST */
   /* Indicate the high side switch fault */
   /* if(  ( i2c0->u_bit.s_ac_disc_cmd       == (uint32_t)1 ) &
   *   ( i2c0->u_bit.s_ac_hs_switch_stat == (uint32_t)1 )   )
    *{
   *  c_28v_fault_word->u_bit.s_switch_fault_high = (uint32_t)1;
    *}else
    *{
   *  c_28v_fault_word->u_bit.s_switch_fault_high = (uint32_t)0;
    *}
    */
   /* WARNING !!! TO REMOVE AFTER HW TEST !!! NEED TO PASS PRODUCT TEST */

   /* If inconsistency between cold switch state and command */
   /* Indicate the low side switch fault */
   if( i2c0->u_bit.s_ac_ls_switch_stat == (uint16_t)1 )
   {
      c_28v_fault_word->u_bit.s_switch_fault_low = (uint32_t)(i2c0->u_bit.s_ac_disc_cmd);
   }else
   {
      c_28v_fault_word->u_bit.s_switch_fault_low = (uint32_t)0;
   }

   /* If 28V A/C is disconnected (low side or high side) */
   /* TODO : WARNING !!! TO REMOVE AFTER HW TEST !!! NEED TO PASS PRODUCT TEST */
   /* Indicate the 28V disconnected fault */
   c_28v_fault_word->u_bit.s_is_disc = !(uint32_t)(i2c0->u_bit.s_ac_ls_switch_stat);

   /* WARNING !!! TO REMOVE AFTER HW TEST !!! NEED TO PASS PRODUCT TEST */

   /*--- 28V A/C STEP - END ---*/

   return;
}

/* ---------- internal operations: ------------------------------------------ */
