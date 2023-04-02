/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef MAC_ETH_CFEX_PUBLIC_H
#define MAC_ETH_CFEX_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "driver/mailbox/MAC_ETH_HAL_public.h"
#include "driver/mailbox/MAC_ETH_REG_common.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

typedef enum
{
   e_CFEX_MAC_ETH_CONF_0 = 0 ,
   e_CFEX_MAC_ETH__CONF_NB
}
te_CFEX_MAC_ETH_CONF ;

typedef struct
{
   /* Register s_address */
   CMN_SYSTEM_ADDR_VAL_t   s_mac_eth_rx_configuration_address;
   /* Register s_address */
   CMN_SYSTEM_ADDR_VAL_t   s_mac_eth_rx_status_address;
   /* Register s_address */
   CMN_SYSTEM_ADDR_VAL_t   s_mac_eth_tx_status_address;
   /* Register s_address */
   CMN_SYSTEM_ADDR_VAL_t   s_mac_eth_mdio_interface_address;
   /* MAC filtering address source */
   MAC_ETH_MACAddr_t       s_mac_filtering_addr_src[MAC_ETH_RX_FILTRE_SRC_SIZE];
   /* MAC filtering address destination */
   MAC_ETH_MACAddr_t       s_mac_filtering_addr_dst[MAC_ETH_RX_FILTRE_DST_SIZE];
   /* MAC rx filter mask address source */
   MAC_ETH_MACAddr_t       s_mac_rx_filter_mask_addr_src;
   /* MAC rx filter mask  address destination */
   MAC_ETH_MACAddr_t       s_mac_rx_filter_mask_addr_dst;
}
ts_MAC_ETH_CFEX_ELT;

/* */
typedef enum
{
   e_MAC_ETH_STATUS_INIT = 0 ,
   e_MAC_ETH_AUTONEGO = 1,
   e_MAC_ETH_STATUS_CONNECTION = 2,
   e_MAC_ETH_STATUS_READY = 3,
   e_MAC_ETH_STATUS_FAILED = 4

} te_MAC_ETH_STATUS ;

typedef struct
{
   MAC_ETH_MACAddr_t s_mac_filtering_addr_src[MAC_ETH_RX_FILTRE_SRC_SIZE];
   MAC_ETH_MACAddr_t s_mac_filtering_addr_dst[MAC_ETH_RX_FILTRE_DST_SIZE];
   MAC_ETH_MACAddr_t s_mac_rx_filter_mask_addr_src;
   MAC_ETH_MACAddr_t s_mac_rx_filter_mask_addr_dst;
   te_MAC_ETH_STATUS s_status ;
}
ts_MAC_ETH_CONFIG_DESC;

/* ---------- provided constants: ------------------------------------------- */
/* */
extern const uint32_t c_MAC_ETH_CFEX_tab_SIZE;

extern const ts_MAC_ETH_CFEX_ELT c_MAC_ETH_CFEX_CONFIGURATION_tab[];

/* ---------- provided data: ------------------------------------------------ */
extern ts_MAC_ETH_CONFIG_DESC MAC_ETH_CFEX_descriptor ;

/* ---------- provided operations: ------------------------------------------ */
/* */

#endif /* MAC_ETH_CFEX_PUBLIC_H */
