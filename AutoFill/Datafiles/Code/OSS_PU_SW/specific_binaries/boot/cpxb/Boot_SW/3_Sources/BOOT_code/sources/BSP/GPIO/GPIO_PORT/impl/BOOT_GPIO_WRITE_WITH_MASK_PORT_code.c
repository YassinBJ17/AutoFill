/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : GPIO write port with mask function
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
void BOOT_GPIO_WRITE_WITH_MASK_PORT ( CMN_IOSP_ID_t            const p_gpio_conf_id,
                                        GPIO_PORT_VALUE_t const p_logic_value )
{
   /* Local Variable Declaration */
   ts_GPIO_CTRL_REG volatile * pt_gpio_ctrl;

   /* store the driver registers in local variable */
   /* >RELAX<SYNCHRONe_C_Code_10.3> The cast is safe as the structure is used to retrieve all GPIO registers */
   /* which start at this address. */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as all the structure fields are tailor-made for the different*/
   /* GPIO registers. */
   pt_gpio_ctrl = (ts_GPIO_CTRL_REG volatile *)GPIO_SIUL2_GPIO_REG_ADDR;

   /* */

   /* {{RELAX<SYNCHRONe_C_Code_7.2> The 16 bit left shift allows to move the 16 bit mask towards the MSB. */
   /* 'p_logic_value & 0xFFFF' allows to set the last 16 bits to '1111 1111 1111 111x' 'x' being p_logic_value */
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as reg32_t is volatile unsigned long  (32 bits) and uint32_t*/
   /* is unsigned long (32 bits). */
   pt_gpio_ctrl->s_GPIO_OUT_PORT_WITH_MASK[GPIO_CFEX_descriptor_tab[p_gpio_conf_id].s_gpio_id] =
   (reg32_t)
   ( ((uint32_t)(~(GPIO_CFEX_descriptor_tab[p_gpio_conf_id].s_mask_value))) << 16UL)
   | ((reg32_t)(p_logic_value) & (reg32_t)0x0000FFFFUL);
   /* }}<SYNCHRONe_C_Code_7.2> */
   /* }}<SYNCHRONe_C_Code_10.7> */
}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
