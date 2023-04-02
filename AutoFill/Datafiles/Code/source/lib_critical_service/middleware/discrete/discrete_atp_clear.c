/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Service to set GPIO 54 ATP_TST_MPC to 0
 * -------------------------------------------------------------------------- */
#include "middleware/discrete/discrete_atp_public.h"


/* Implements */
void discrete_atp_clear(void)
{
   /* define pointer to GPIO54 ATP_TST_MPC*/
   reg8_t * atp_tst_mpc;

   /* point toward GPIO 54 address */
   atp_tst_mpc = GPDO_54_ATP_TST;

   /* clear the value of ATP_TST_MPC by setting value to 0*/
   *atp_tst_mpc = GPIO_DISABLE_VALUE;

   return;
}
