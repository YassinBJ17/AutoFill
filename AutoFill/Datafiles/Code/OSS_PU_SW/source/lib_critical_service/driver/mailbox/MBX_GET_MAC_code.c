/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Mailbox Tx get mac function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MBX_CFEX_public.h"
#include "driver/mailbox/MBX_HAL_public.h"
#include "driver/mailbox/MBX_REG_common.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void MBX_GET_MAC( MAC_ETH_MACAddr_t * const p_pt_mac_addr )
{
   uint32_t v_i ;

   for ( v_i  = 0ul ; v_i < ETH_HAL_MAC_SIZE ; v_i++ )
   {
      (*p_pt_mac_addr)[ v_i ] = MBX_CFEX_descriptor.s_mac_addr[ v_i ];
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
