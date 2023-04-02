/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : lvdt_init function which allows lvdt acquisition
 *               initialization.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/lvdt/lvdt_public.h"
#include "middleware/lvdt/lvdt_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
/* GPIOs defs */
#define GPIO_226 ((uint8_t *)0xFFFC13E2) /* PBIT_LVDTA_B_EXC_OPEN_N */
#define GPIO_227 ((uint8_t *)0xFFFC13E3) /* PBIT_LVDTC_EXC_OPEN_N   */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* GPIO manipulation */
uint8_t * gpioPtr_lvdt;

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-lvdt-xxxx */
void lvdt_init(const boolean_t channel_is_a)
{
    /* Set GPIOs to enable LVDT : TODO */
   gpioPtr_lvdt = GPIO_226;
   *gpioPtr_lvdt = 0x1;
   gpioPtr_lvdt = GPIO_227;
   *gpioPtr_lvdt = 0x1;

   /* Initialize fault word thresholds */
   lvdt_init_fault_word_thresholds();

   /* Configure sinus generator on SPI */
   lvdt_init_configure_exc_frequency(channel_is_a);
}

/* ---------- internal operations: ------------------------------------------ */
