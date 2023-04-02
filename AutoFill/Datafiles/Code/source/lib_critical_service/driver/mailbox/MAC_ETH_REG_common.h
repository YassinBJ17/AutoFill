/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef MAC_ETH_REG_COMMON_H
#define MAC_ETH_REG_COMMON_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */
#define MAC_ETH_RX_FILTRE_SRC_SIZE (8ul)
#define MAC_ETH_RX_FILTRE_DST_SIZE (8ul)

/* ---------- provided types: ----------------------------------------------  */
/* FPGA MAC ETH Register */
typedef struct
{
   /*** Management ***/
   /* MSB de {eth_rx_filtre_dest_adr_0} register (Offset: 0x0000) */
   reg32_t s_ETH_RX_FILTRE_ADR_H_REG;
   /* LSB de {eth_rx_filtre_dest_adr_0} register*/
   reg32_t s_ETH_RX_FILTRE_ADR_L_REG;
}
ts_MAC_ETH_RX_FILTRE_ADR_REG;

/* FPGA MAC ETH Register */
typedef struct
{
   /*** Management ***/
   /* MSB/LSB de {eth_rx_filtre_dest_adr_0_7} register (Offset: 0x0000) */
   ts_MAC_ETH_RX_FILTRE_ADR_REG s_ETH_RX_FILTRE_DST_REG[MAC_ETH_RX_FILTRE_DST_SIZE];
   /* MSB de {eth_rx_filtre_dest_adr_mask} register*/
   reg32_t s_ETH_RX_FILTRE_DEST_ADR_MASK_H_REG;
   /* LSB de {eth_rx_filtre_dest_adr_mask} register*/
   reg32_t s_ETH_RX_FILTRE_DEST_ADR_MASK_L_REG;
   /* MSB de {eth_rx_filtre_src_adr_0_7} register*/
   ts_MAC_ETH_RX_FILTRE_ADR_REG s_ETH_RX_FILTRE_SRC_REG[MAC_ETH_RX_FILTRE_SRC_SIZE];
   /* MSB de {eth_rx_filtre_src_adr_mask} register*/
   reg32_t s_ETH_RX_FILTRE_SRC_ADR_MASK_H_REG;
   /* LSB de {eth_rx_filtre_src_adr_mask} register*/
   reg32_t s_ETH_RX_FILTRE_SRC_ADR_MASK_L_REG;
}
ts_MAC_ETH_RX_CONFIGURATION_REG;


typedef struct
{
   /*** Management ***/
   /* status of MAC ethernet receiver (1/2) register (Offset: 0x0000) */
   reg32_t s_ETH_RX_STATUS_1_REG;
   /*  status of MAC ethernet receiver (2/2) register */
   reg32_t s_ETH_RX_STATUS_2_REG;
}
ts_MAC_ETH_RX_STATUS_REG;

typedef struct
{
   /*** Management ***/
   /* status of MAC ethernet transmitter (1/2) (Offset: 0x0000) */
   reg32_t s_ETH_TX_STATUS_REG;
}
ts_MAC_ETH_TX_STATUS_REG;


/* ---------- provided global variable--------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided operations: ------------------------------------------ */


#endif /* MAC_ETH_REG_COMMON_H */
