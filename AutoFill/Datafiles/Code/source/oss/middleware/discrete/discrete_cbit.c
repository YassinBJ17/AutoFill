/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : CBIT function for SVOI and EMAN during OPER
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include <middleware/discrete/discrete_private.h>

/* ---------- include required interface: ----------------------------------- */
#include <memory/lib_critical_service_section_def_data.h>

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
/* Discrete EMAN and SVOI voltage threshold value for short ground detection define in BSIS */
/* The voltage threshold is set at 1 V through ADC converter set at (5.0 / 4096.0)*/
/* Calculus : >> [VOLT] = X . [CONVERTER]  */
/*            >> X = [VOLT] / [CONVERTER]  */
/*            >> X = 819.2  (DEC)          */
/*            >> X = 0x0333 (HEX)          */
#define COMEMANSVOI_THRESHOLD_V        (uint16_t)0x0333

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SVOIEMAN-0010 */
/* Implements REQ_FADEX_OS_SRD-DIN-0010 */
/* Perform the discrete CBIT */
void discrete_cbit(
   /* INPUT */
   const uint16_t*   const  p_adc_value)
{
   /* Local Variable Declaration        */


   /* Initialization Variable           */


   /* Source code start                 */

   /*--- EMAN and SVOI short ground part ---*/
   if( *p_adc_value > COMEMANSVOI_THRESHOLD_V )
   {
      shmem.s_eman.s_fault_word.u_word             = INIT_VALUE_32;
      shmem.s_svoi.s_fault_word.u_word             = INIT_VALUE_32;
   }
   else
   {
      /* Write in share memory the fault word */
      shmem.s_eman.s_fault_word.u_bit.s_short_gnd  = INIT_VALUE_32;
      shmem.s_eman.s_fault_word.u_bit.s_invalid    = INIT_VALUE_32;
      shmem.s_svoi.s_fault_word.u_bit.s_short_gnd  = INIT_VALUE_32;
      shmem.s_svoi.s_fault_word.u_bit.s_invalid    = INIT_VALUE_32;
   }

   return ;
}

/* ---------- internal operations: ------------------------------------------ */
