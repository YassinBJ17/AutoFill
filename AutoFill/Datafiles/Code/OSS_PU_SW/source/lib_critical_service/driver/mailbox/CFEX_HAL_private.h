/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef CFEX_HAL_PRIVATE_H
#define CFEX_HAL_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */
/* FPGA register address                  */
#define FPGA_REG_ADDR    (0x24000000)     /* FPGA_REG_ADDR Register*/
/* MBX register address                  */
#define MBX_REG_ADDR    (FPGA_REG_ADDR + 0x000F4000)     /* MBX_REG_ADDR Register*/
/* MBX RX offset Register */
#define MBX_RX_REG_ADDR    (MBX_REG_ADDR + 0x00000000)      /* MBX_RX_REG_ADDR Register*/
/* MBX TX offset Register */
#define MBX_TX_REG_ADDR    (MBX_REG_ADDR + 0x00000030)      /* MBX_TX_REG_ADDR Register*/
/* MBX TX CMD offset Register */
#define MBX_TX_CMD_REG_ADDR    (MBX_REG_ADDR + 0x00000050)     /* MBX_TX_CMD_REG_ADDR Register*/

/* MBX register address                  */
#define MAC_ETH_REG_ADDR    (FPGA_REG_ADDR + 0x000F8000)    /* MAC_ETH_REG_ADDR Register*/
/* MAC ETH  RX offset Register */
#define MAC_ETH_RX_REG_ADDR    (MAC_ETH_REG_ADDR + 0x00000000)    /* MAC_ETH_RX_REG_ADDR Register*/
/* MAC ETH RX STATUS offset Register */
#define MAC_ETH_RX_STATUS_REG_ADDR    (MAC_ETH_REG_ADDR + 0x00000100)      /* MAC_ETH_RX_STATUS_REG_ADDR Register*/
/* MAC ETH TX STATUS offset Register */
#define MAC_ETH_TX_STATUS_REG_ADDR    (MAC_ETH_REG_ADDR + 0x00000120)      /* MAC_ETH_TX_STATUS_REG_ADDR Register*/
/* MAC ETH MDIO offset Register */
#define MAC_ETH_MDIO_REG_ADDR    (MAC_ETH_REG_ADDR + 0x00000140)     /* MAC_ETH_MDIO_REG_ADDR Register*/

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

#endif /* CFEX_HAL_PRIVATE_H */
