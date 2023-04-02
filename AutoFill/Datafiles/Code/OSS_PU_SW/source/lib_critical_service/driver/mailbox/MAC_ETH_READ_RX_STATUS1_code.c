/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : MAC ETH Read Rx Status1 function
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
void MAC_ETH_READ_RX_STATUS1 ( CMN_IOSP_ID_t const p_conf_ip_id,
                               uint32_t * const p_eth_rx_stat_frame_filtre )
{
   /* Local Variable Declaration */
   tu_MAC_ETH_RX_STATUS_1_REG volatile * pt_mac_eth_rx_status_1_reg;

   /* Store the driver registers in local variable */
   /* >RELAX<SYNCHRONe_C_Code_10.3> The cast is safe as the structure is used to retrieve all BDG_FREQ registers which start at this address. */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as all the structure fields are tailor-made for the different BDG_FREQ registers. */
   pt_mac_eth_rx_status_1_reg = (tu_MAC_ETH_RX_STATUS_1_REG volatile *)c_MAC_ETH_CFEX_CONFIGURATION_tab[p_conf_ip_id].s_mac_eth_rx_status_address;

   /* Return Status value */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast changes register type to data type with same size */
   *p_eth_rx_stat_frame_filtre = (uint32_t)(pt_mac_eth_rx_status_1_reg->u_B.s_eth_rx_stat_frame_filtre);
}

/* ---------- internal operation bodies: ------------------------------------ */
