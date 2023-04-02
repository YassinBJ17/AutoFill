/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : GPIO Read in pin function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_GPIO_CFEX_public.h"
#include "BOOT_GPIO_HAL_public.h"
#include "BOOT_GPIO_REG_common.h"

/* LPOS Private Interface */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void BOOT_GPIO_READ_IN_PIN ( CMN_IOSP_ID_t             const p_gpio_conf_id,
                               GPIO_PIN_VALUE_t * const p_logic_value)
{
   /* Local Variable Declaration */
   ts_GPIO_CTRL_REG volatile* pt_gpio_ctrl;

   /* store the driver registers in local variable */
   /* >RELAX<SYNCHRONe_C_Code_10.3> The cast is safe as the structure is used to retrieve all */
   /* GPIO registers which start at this address. */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as all the structure fields are tailor-made for the different*/
   /* GPIO registers. */
   pt_gpio_ctrl = (ts_GPIO_CTRL_REG volatile*)GPIO_SIUL2_GPIO_REG_ADDR;

   /* Get Current Pin Data value */
   *p_logic_value = pt_gpio_ctrl->s_GPIO_IN_PIN[GPIO_CFEX_descriptor_tab[p_gpio_conf_id].s_gpio_id];

}
/* ---------- internal operation bodies: ------------------------------------ */
/* none */
