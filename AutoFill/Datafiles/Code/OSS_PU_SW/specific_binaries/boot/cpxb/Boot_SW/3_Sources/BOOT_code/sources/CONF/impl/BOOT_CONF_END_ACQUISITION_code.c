/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function selects the cores configurations depending
 *               on the mode chosen (data loader or run).
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_CONF_public.h"
#include "BOOT_LIBTIME_public.h"
/* ---------- include required interface: ----------------------------------- */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* Required duration of the GPIO acquisition */
#define ACQUISITION_MIN_VALUE_IN_MS   100
#define BIST_DURATION_IN_MS           53
#define TIME_LEFT_IN_MS               (ACQUISITION_MIN_VALUE_IN_MS-BIST_DURATION_IN_MS)
#define TIME_LEFT_IN_NS               (CMN_SYSTEM_TIME_t)(TIME_LEFT_IN_MS*1000*1000)

/* ---------- internal types: ----------------------------------------------- */
/* none */


/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */


/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies : ------------------------------------------- */
/* Implements REQ_[User Project Name]_BOOT-LLR_056 */
void BOOT_CONF_END_ACQUISITION ( void )
{
   /* Index */
   uint32_t i;
   /* Temporary variable to compute the duration of the GPIO acquisition */
   CMN_SYSTEM_TIME_t v_time_tmp;
   /* Computed acquisition duration */
   CMN_SYSTEM_TIME_t v_acquisition_duration;

   /* Continue the acquisition until ACQUISITION_MIN_IN_NS ns */
   do
   {
      /* Get the timer value and update the acquisition duration */
      BOOT_LIBTIME_GET ( (CMN_SYSTEM_TIME_t*)&v_time_tmp);
      v_acquisition_duration = v_time_tmp - V_acquisition_start_time;

   }
   while ( v_acquisition_duration < TIME_LEFT_IN_NS );

   /* Read the discretes one last time */
   BOOT_CONF_READ_DISCRETES ();

   /* */
   if (  V_CONF_MDIN_Acquisition.s_gpio_elt.s_gpio_value_tab[0] == V_CONF_MDIN_Acquisition.s_gpio_elt.s_gpio_value_tab[1]
         || V_CONF_MDIN_Acquisition.s_gpio_elt.s_gpio_value_tab[0] == V_CONF_MDIN_Acquisition.s_gpio_elt.s_gpio_value_tab[2]
    )
   {
      /* The GPIO value is confirmed */
      V_CONF_MDIN_Acquisition.s_gpio_elt.s_is_GPIO_value_confirmed = e_CMN_FLAG_YES;
   }

}

