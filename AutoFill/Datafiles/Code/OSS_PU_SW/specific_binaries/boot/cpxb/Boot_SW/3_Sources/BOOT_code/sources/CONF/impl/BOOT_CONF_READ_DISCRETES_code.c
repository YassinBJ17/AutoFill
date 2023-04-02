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
#include "BOOT_GPIO_HAL_public.h"
#include "BOOT_GPIO_REG_common.h"
#include "logbook_CFEX_public.h"
#include "BOOT_LIBTIME_public.h"

/* ---------- internal define constants: ------------------------------------ */
#define MRAM_POWERUP_COUNTER (uint32_t)0x203FFFFC
#define MDIN_FPGA_ADDR (uint32_t)0x24004000
#define MDIN_MASK      (uint32_t)0x4

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
void BOOT_CONF_READ_DISCRETES ( void )
{
   uint32_t * pt_gpio_mdin = (uint32_t*) MDIN_FPGA_ADDR;
   
   /* Initialize V_acquisition_start_time only at second acquisition (after xBIST execution and reset) */
   if(V_CONF_MDIN_Acquisition.s_acquisition_index == 1)
   {
      /* Get the current time */
      BOOT_LIBTIME_GET ( (CMN_SYSTEM_TIME_t*)&V_acquisition_start_time);
   }

   /*****         GPIO read        *****/
   /* Read the MDIN discret */
   //BOOT_GPIO_READ_IN_PIN ( GPIO_MDIN,
    //                       &V_CONF_MDIN_Acquisition.s_gpio_elt.s_gpio_value_tab[V_CONF_MDIN_Acquisition.s_acquisition_index] );
   
   V_CONF_MDIN_Acquisition.s_gpio_elt.s_gpio_value_tab[V_CONF_MDIN_Acquisition.s_acquisition_index] = (*pt_gpio_mdin & MDIN_MASK)>> (uint32_t)2;
   
   /* Increments the sampling index for the next acquisition */
   V_CONF_MDIN_Acquisition.s_acquisition_index++;
}

