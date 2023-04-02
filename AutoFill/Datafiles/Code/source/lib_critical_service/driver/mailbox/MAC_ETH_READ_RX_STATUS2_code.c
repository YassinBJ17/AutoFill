/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : MAC ETH Read Rx Status2 function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MAC_ETH_CFEX_public.h"
#include "driver/mailbox/MAC_ETH_HAL_public.h"
#include "driver/mailbox/MAC_ETH_REG_common.h"

/* LPOS Private Interface */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void MAC_ETH_READ_RX_STATUS2 ( CMN_IOSP_ID_t const p_conf_ip_id,
                               tu_MAC_ETH_RX_STATUS_2_REG * const  p_status_value )
{
   /* Local Variable Declaration */
   ts_MAC_ETH_RX_STATUS_REG volatile *    pt_mac_eth_rx_status_2_reg;

   /* Store the driver registers in local variable */
   /* >RELAX<SYNCHRONe_C_Code_10.3> The cast is safe as the structure is used to retrieve all BDG_FREQ registers which start at this address. */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as all the structure fields are tailor-made for the different BDG_FREQ registers. */
   pt_mac_eth_rx_status_2_reg = (ts_MAC_ETH_RX_STATUS_REG volatile *)c_MAC_ETH_CFEX_CONFIGURATION_tab[p_conf_ip_id].s_mac_eth_rx_status_address;

   /* Return Status value */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast changes register type to data type with same size */
   p_status_value->u_R = (uint32_t)(pt_mac_eth_rx_status_2_reg->s_ETH_RX_STATUS_2_REG);
}

/* ---------- internal operation bodies: ------------------------------------ */
