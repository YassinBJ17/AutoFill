/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "driver/mailbox/MBX_CFEX_public.h"
#include "driver/mailbox/MBX_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/ethernet/ETH_MAC_public.h"
#include "driver/mailbox/CFEX_HAL_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
const uint32_t c_MBX_CFEX_tab_SIZE = MBX_NB;

/* MBX configuration table */
const ts_MBX_CFEX_ELT c_MBX_CFEX_CONFIGURATION_tab[ MBX_NB ] =
{
   /* 0 - MBX 0 */
   {
      MBX_RX_REG_ADDR,     /* RX fifo*/
      MBX_TX_REG_ADDR,     /* TX fifo */
      MBX_TX_CMD_REG_ADDR
   }
};

/* ---------- internal data: ------------------------------------------------ */
/* MBX descriptor declaration */
ts_MBX_CONFIG_DESC MBX_CFEX_descriptor ;

/* ---------- provided operation bodies: ------------------------------------ */

