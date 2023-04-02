/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Tmot initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/adc/ADC_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/tmot/tmot_public.h"
#include "middleware/tmot/tmot_private.h"
#include "middleware/tmot/tmot_fpga_reg_common.h"
#include "memory/memory_address_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* tmot PBIT fault word */
tu_tmot_init_fault_word tmot_pbit;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ------ --- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-TMOT-0030 */
/* Tmot initialization function */
void tmot_init(void)
{
   uint32_t i;

   /* Tmot current acquired from SARADC_B */
   uint16_t tmot_current;

   /* Assign the defined adress to the FPGA tmot register */
   tmot_fpga_reg = (tu_tmot_fpga_reg_type*)TMOT_FPGA_MEMORY_ADDR;

   /* Set the tmot PBIT fault word to no fault */
   tmot_pbit.u_word = (uint32_t)0;

   /* Initiliaze the tmot current to no current */
   shmem.s_tmot_w.s_current = (float32_t)0;

   /* Acquire the tmot current sample */
   ADC_BUFFER_READ(e_CFEX_ADC_INT_AN50, (CMN_SYSTEM_ADDR_t)&tmot_current);

   /* If the tmot computed low side current feedback is not equal to the default value */
   if((int32_t)2048 != tmot_current)
   {
      /* Indicate the tmot current at initialization is not at the expected default value */
      tmot_pbit.u_bit.s_current_invalid_1 = (uint32_t)1;

      /* Set the tmot current to the default value */
      tmot_fpga_reg->u_field.s_voltage_cmd = (uint32_t)2048;

      /* TBD wait */
      for(i=0;i<400;i++)
      {
         asm("nop");
      }

      /* Acquire the tmot current sample for the second time */
      ADC_BUFFER_READ(e_CFEX_ADC_INT_AN50, (CMN_SYSTEM_ADDR_t)&tmot_current);

      /* If the tmot computed low side current feedback is not equal to the default value */
      if((int32_t)2048 != tmot_current)
      {
         /* Indicate the tmot current at initialization is not at the expected default value */
         tmot_pbit.u_bit.s_current_invalid_2 = (uint32_t)1;
      }

      /* TODO : if tmot current faulty go to reset */
   }
}

/* ---------- internal operations: ------------------------------------------ */
