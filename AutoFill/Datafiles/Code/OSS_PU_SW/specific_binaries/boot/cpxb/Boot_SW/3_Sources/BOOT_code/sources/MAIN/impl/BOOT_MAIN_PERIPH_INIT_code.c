/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function manages peripherals initializations.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
/* none */

/* ---------- include required interface: ----------------------------------- */
#include "BOOT_LIBTIME_public.h"
#include "BOOT_GPIO_HAL_public.h"
#include "BOOT_GPIO_REG_common.h"
#include "BOOT_FCCU_public.h"
#include "BOOT_INTC_public.h"
#include "BOOT_MEM_public.h"
#include "BOOT_PBRIDGE_public.h"
#include "BOOT_PINOUT_public.h"
#include "BOOT_XBAR_public.h"
#include "BOOT_MAIN_private.h"
/* ---------- internal define constants: ------------------------------------ */
/* */
#define WAIT_100MS (uint32_t)(100*1000*1000)
#define PBRIDGE_OPACRB_VAL (0xFul)
#define SIUL2_REG_PROT_VAL (0x00800000ul)

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_[User Project Name]_BOOT-LLR_002 */
void BOOT_MAIN_PERIPH_INIT( void )
{

   volatile uint32_t *pt_opacrb = (volatile uint32_t *)(PBRIDGE_OPACRB_BASE_ADDR);
   volatile uint32_t *pt_siul2_reg_prot = (volatile uint32_t *)(SIUL2_REG_PROT_GCR_ADDR);

   BOOT_LIBTIME_INIT();
   /* Initialize Bridge */
   BOOT_PBRIDGE_INIT();
   /* Initialize XBAR */
   BOOT_XBAR_INIT();
   *pt_opacrb &= ~(PBRIDGE_OPACRB_VAL);
   *pt_siul2_reg_prot = SIUL2_REG_PROT_VAL;
   BOOT_GPIO_INIT();
   /* Initialize PINOUT */
   BOOT_PINOUT_INIT();
   /* Initialize EBI */
   BOOT_MEM_EBI_INIT();
   /* Initialize PIT */
   /* Initialize INTC */
   BOOT_INTC_INIT();

   BOOT_FCCU_INIT();
}
void BOOT_MAIN_PERIPH_SHORT_INIT(void)
{
   BOOT_PINOUT_INIT();
   /* Initialize driver*/
   BOOT_MEM_EBI_INIT();
   /* GPIO initialization */
   BOOT_GPIO_INIT();

}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
