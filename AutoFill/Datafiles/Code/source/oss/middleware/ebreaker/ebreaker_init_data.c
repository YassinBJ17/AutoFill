/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Perform periodic function for ebreaker
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/ebreaker/ebreaker_public.h"
#include "middleware/ebreaker/ebreaker_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "driver/mailbox/EBREAKER_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
const ts_ebreaker_function EBREAKER_tab[e_ebreaker_nb_cmd] =
{
   {
      /* RX sequence to engage */
      e_ebreaker_rx_enable,
      {
         EBREAKER_CMD1_ON,
         EBREAKER_CMD2_ON
      },
      /* Function access for RX engage */
      (uint32_t)(&EBREAKER_FIFO_RX_ENABLE_SET_KEY1),
      (uint32_t)(&EBREAKER_FIFO_RX_ENABLE_SET_KEY2)
   },
   {
      /* RX sequence to disengage */
      e_ebreaker_rx_disable,
      {
         EBREAKER_CMD1_OFF,
         EBREAKER_CMD2_OFF
      },
      /* Function access for RX disengage */
      (uint32_t)(&EBREAKER_FIFO_RX_DISABLE_SET_KEY1),
      (uint32_t)(&EBREAKER_FIFO_RX_DISABLE_SET_KEY2)
   }
};
/* ---------- internal data: ------------------------------------------------ */
uint32_t  ebreaker_previous_cmd;

/* ---------- provided operation bodies: ------------------------------------- */


/* ---------- internal operations: ------------------------------------------ */
