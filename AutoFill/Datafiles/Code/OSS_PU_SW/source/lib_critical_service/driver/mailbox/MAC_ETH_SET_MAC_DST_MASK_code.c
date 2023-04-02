/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : MAC ETH Set MAC DST function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MAC_ETH_CFEX_public.h"
#include "driver/mailbox/MAC_ETH_HAL_public.h"
#include "driver/mailbox/MAC_ETH_REG_common.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void MAC_ETH_SET_MAC_DST_MASK ( CMN_IOSP_ID_t const p_conf_ip_id,
                                const MAC_ETH_MACAddr_t * const p_mac_mask_addr )
{
   /* Local Variable Declaration */
   ts_MAC_ETH_RX_CONFIGURATION_REG volatile * pt_mac_eth_rx_filtre_reg;

   /* Store the driver registers in local variable */
   /* >RELAX<SYNCHRONe_C_Code_10.3> The cast is safe as the structure is used to retrieve all BDG_FREQ registers which start at this address. */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as all the structure fields are tailor-made for the different BDG_FREQ registers. */
   pt_mac_eth_rx_filtre_reg = (ts_MAC_ETH_RX_CONFIGURATION_REG volatile *)c_MAC_ETH_CFEX_CONFIGURATION_tab[p_conf_ip_id].s_mac_eth_rx_configuration_address;

   pt_mac_eth_rx_filtre_reg->s_ETH_RX_FILTRE_DEST_ADR_MASK_H_REG = ( ((reg32_t)(*p_mac_mask_addr)[ 0 ]) << 8u ) |
                                                                   ( ((reg32_t)(*p_mac_mask_addr)[ 1 ]) << 0u );

   pt_mac_eth_rx_filtre_reg->s_ETH_RX_FILTRE_DEST_ADR_MASK_L_REG = ( ((reg32_t)(*p_mac_mask_addr)[ 2 ]) << 24u ) |
                                                                   ( ((reg32_t)(*p_mac_mask_addr)[ 3 ]) << 16u ) |
                                                                   ( ((reg32_t)(*p_mac_mask_addr)[ 4 ]) << 8u ) |
                                                                   ( ((reg32_t)(*p_mac_mask_addr)[ 5 ]) << 0u );
}

/* ---------- internal operation bodies: ------------------------------------ */
