/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP get sw info command send
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/pbit/pbit_private.h"
/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

void pbit_pld_config(const boolean_t ch_is_a)
{
   /* Watchdog part */
   /* Done in WD function */

   /* PLL part */
   pbit_pld_pll();

   /* A429 Rx Part */
   if (ch_is_a)
   {
      pbit_pld_a429_1a_rx();
   }

   pbit_pld_a429_2ab_rx();

   /* A429 Tx Part */
   pbit_pld_a429_tx(ch_is_a);

   /* PWM Part */
   if (ch_is_a)
   {
      pbit_pld_pwm();
   }

   /* Speed Part */
   pbit_pld_speed();

   /* UART - CCDL Part */
   pbit_pld_ccdl();

   /* SM Part */
   pbit_pld_sm();


}

/* ---------- internal operations: ------------------------------------------ */
