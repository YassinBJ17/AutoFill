/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function selects the cores configurations depending
 *               on the mode chosen (data loader or run).
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_CONF_public.h"

/* ---------- include required interface: ----------------------------------- */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* none */


/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
#pragma section SECTION_BOOT_DISCRETES "" ".BOOT_SAVE_DISCRETES"
#pragma use_section SECTION_BOOT_DISCRETES V_CONF_MDIN_Acquisition
ts_GPIO_acquisition V_CONF_MDIN_Acquisition;

CMN_SYSTEM_TIME_t V_acquisition_start_time;

/* ---------- provided operation bodies : ------------------------------------------- */
/* Implements REQ_[User Project Name]_BOOT-LLR_056 */
void BOOT_CONF_INIT_ACQUISITION ( void )
{
   /* Index */
   uint32_t i;

   /* First acquisition of GPIOs */

   /* The acquisition index is 0 */
   V_CONF_MDIN_Acquisition.s_acquisition_index = 0;

   /* The MDIN value has not yet been confirmed */
   V_CONF_MDIN_Acquisition.s_gpio_elt.s_is_GPIO_value_confirmed = e_CMN_FLAG_NO;
   
   V_acquisition_start_time=(CMN_SYSTEM_TIME_t)0;

   /* Perform the first acquisition */
   BOOT_CONF_READ_DISCRETES ();

}

