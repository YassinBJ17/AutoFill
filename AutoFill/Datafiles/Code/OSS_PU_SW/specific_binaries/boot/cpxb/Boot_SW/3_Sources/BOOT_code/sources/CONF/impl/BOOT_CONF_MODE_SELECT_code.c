/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function selects the cores configurations depending
 *               on the mode chosen (data loader or run).
 * -------------------------------------------------------------------------- */

#include "BOOT_CONF_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "BOOT_GPIO_HAL_public.h"
#include "BOOT_GPIO_REG_common.h"
#include "logbook_CFEX_public.h"
#include "BOOT_LIBTIME_public.h"
#include "BOOT_FAULT_public.h"

/* ---------- internal types: ----------------------------------------------- */
#define MRAM_POWERUP_COUNTER (uint32_t)0x203FFFFC

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */

#define ASTEKCONF_ADDR_VALID (0x0FACADE0ul)
#define CONF_UOD_DIS (0x0ul)

/* ---------- internal data: ------------------------------------------------ */
#pragma section POWERUP_COUNTER "" ".BOOT_POWERUP_COUNTER"
#pragma use_section POWERUP_COUNTER V_powerUpCounter
uint32_t V_powerUpCounter;

/* ---------- provided operations: ------------------------------------------- */

/* Implements REQ_[User Project Name]_BOOT-LLR_056 */
uint32_t BOOT_CONF_MODE_SELECT (void)
{
   GPIO_PIN_VALUE_t v_DINSHOP,v_DINOLL, v_DINTMODE, v_MDIN;
   uint32_t * pt_css_pu_task_config = (uint32_t*) CSS_PU_TASK_CONFIG_ADDR;
   uint32_t * pt_dtl_request = (uint32_t *) DTL_REQUEST_ADDR;
   
   /* Update the powerup counter (We supposed that the mram is initialized to 0 at production) */
   V_powerUpCounter = V_powerUpCounter + 1;
   
   /* Perform the last acquisition and confirm MDIN value */
   BOOT_CONF_END_ACQUISITION ();
   
   /*****         DINSHOP, DINOLL and DINTMODE discretes read        *****/

   /* {{RELAX<SYNCHRONe_C_Code_10.7> This cast is safe. Conversion of an enum composed by uint32_t values only */
   BOOT_GPIO_READ_IN_PIN(GPIO_DINSHOP, &v_DINSHOP );
   BOOT_GPIO_READ_IN_PIN(GPIO_DINOLL, &v_DINOLL );
   BOOT_GPIO_READ_IN_PIN(GPIO_DINTMODE, &v_DINTMODE );
   /* }}<SYNCHRONe_C_Code_10.7> */

   /* By default, UOD is deactivated */
   V_BOOT_UOD_ACTIVATION_FLAG_ADDR = CONF_UOD_DIS;
   
   /*****         Mode selection        *****/

   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : conversion of the enum te_CONF_MODE */
   /* (Possible values are : 0, 1, 2) to uint32_t. There is no loss of precision. */
   if (    (   (v_DINOLL==(GPIO_PIN_VALUE_t)GPIO_LOGIC_1)   && (v_DINSHOP==(GPIO_PIN_VALUE_t)GPIO_LOGIC_1)
         && (v_DINTMODE==(GPIO_PIN_VALUE_t)GPIO_LOGIC_0)
         )
      ||
         (   (v_DINOLL==(GPIO_PIN_VALUE_t)GPIO_LOGIC_1)   && (v_DINSHOP==(GPIO_PIN_VALUE_t)GPIO_LOGIC_0)
         && (v_DINTMODE==(GPIO_PIN_VALUE_t)GPIO_LOGIC_1)
         )
     )
   {
    if (  ( V_CONF_MDIN_Acquisition.s_gpio_elt.s_gpio_value_tab[0]       == (GPIO_PIN_VALUE_t)GPIO_LOGIC_0 )
       && ( V_CONF_MDIN_Acquisition.s_gpio_elt.s_is_GPIO_value_confirmed == e_CMN_FLAG_YES                 ) )
     {
       /* Dataloader mode requested */
       return (uint32_t)e_MODE_CHOICE_DTLD;
     }
     else
     {
       /* Activate the UOD */
       V_BOOT_UOD_ACTIVATION_FLAG_ADDR = ASTEKCONF_ADDR_VALID;
     }
   }
   else if ( *pt_dtl_request == e_DTL_REQUESTED )
   {
       /* Dataloader mode requested */
       return (uint32_t)e_MODE_CHOICE_DTLD;
   }
   else{
      /* If CSS_PU_TASK_CONFIG parameter has no planned value, fatal error shall be raise */
      if (*pt_css_pu_task_config == e_1_PERIODIC_TASK)
      {
         V_BOOT_OPERATIONAL_1_PERIODIC_TASK = ASTEKCONF_ADDR_VALID;
      }
      else if (*pt_css_pu_task_config == e_4_PERIODIC_TASK)
      {
         V_BOOT_OPERATIONAL_4_PERIODIC_TASK = ASTEKCONF_ADDR_VALID;
      }
      else
      {
         /* never returns */
         BOOT_FAULT_LOG(BOOT_FAULT_CONF_CSS_PU, PBIT_ORIGIN, *pt_css_pu_task_config, LGBK_FIELD_DEFAULT_VALUE, LGBK_FIELD_DEFAULT_VALUE, LGBK_FIELD_DEFAULT_VALUE);
         BOOT_FAULT_INFINITELOOP();
      }

   }
   /* Run mode requested */
   return (uint32_t)e_MODE_CHOICE_ASTERIOS;
   /* }}<SYNCHRONe_C_Code_10.7> */

}
