/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_MAC_ETH_H
#define FPGA_REG_MAC_ETH_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Union definition for register 's_eth_rx_filtre_dest_adr_0_h_reg' */
typedef struct
{
   uint32_t s_reserved                        : 16; /* Bits : 31:16 : N/A                                          */
   uint32_t s_eth_rx_filtre_dest_adr_0[47:32] : 16; /* Bits : 15:0  : Destination address 0 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_0_h_reg_u_bit;

typedef union
{
   uint32_t                                                 u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_0_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_0_h_reg;

/* Union definition for register 's_eth_rx_filtre_dest_adr_1_h_reg' */
typedef struct
{
   uint32_t s_reserved                        : 16; /* Bits : 31:16 : N/A                                          */
   uint32_t s_eth_rx_filtre_dest_adr_1[47:32] : 16; /* Bits : 15:0  : Destination address 1 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_1_h_reg_u_bit;

typedef union
{
   uint32_t                                                 u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_1_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_1_h_reg;

/* Union definition for register 's_eth_rx_filtre_dest_adr_2_h_reg' */
typedef struct
{
   uint32_t s_reserved                        : 16; /* Bits : 31:16 : N/A                                          */
   uint32_t s_eth_rx_filtre_dest_adr_2[47:32] : 16; /* Bits : 15:0  : Destination address 2 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_2_h_reg_u_bit;

typedef union
{
   uint32_t                                                 u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_2_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_2_h_reg;

/* Union definition for register 's_eth_rx_filtre_dest_adr_3_h_reg' */
typedef struct
{
   uint32_t s_reserved                        : 16; /* Bits : 31:16 : N/A                                          */
   uint32_t s_eth_rx_filtre_dest_adr_3[47:32] : 16; /* Bits : 15:0  : Destination address 3 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_3_h_reg_u_bit;

typedef union
{
   uint32_t                                                 u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_3_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_3_h_reg;

/* Union definition for register 's_eth_rx_filtre_dest_adr_4_h_reg' */
typedef struct
{
   uint32_t s_reserved                        : 16; /* Bits : 31:16 : N/A                                          */
   uint32_t s_eth_rx_filtre_dest_adr_4[47:32] : 16; /* Bits : 15:0  : Destination address 4 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_4_h_reg_u_bit;

typedef union
{
   uint32_t                                                 u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_4_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_4_h_reg;

/* Union definition for register 's_eth_rx_filtre_dest_adr_5_h_reg' */
typedef struct
{
   uint32_t s_reserved                        : 16; /* Bits : 31:16 : N/A                                          */
   uint32_t s_eth_rx_filtre_dest_adr_5[47:32] : 16; /* Bits : 15:0  : Destination address 5 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_5_h_reg_u_bit;

typedef union
{
   uint32_t                                                 u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_5_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_5_h_reg;

/* Union definition for register 's_eth_rx_filtre_dest_adr_6_h_reg' */
typedef struct
{
   uint32_t s_reserved                        : 16; /* Bits : 31:16 : N/A                                          */
   uint32_t s_eth_rx_filtre_dest_adr_6[47:32] : 16; /* Bits : 15:0  : Destination address 6 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_6_h_reg_u_bit;

typedef union
{
   uint32_t                                                 u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_6_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_6_h_reg;

/* Union definition for register 's_eth_rx_filtre_dest_adr_7_h_reg' */
typedef struct
{
   uint32_t s_reserved                        : 16; /* Bits : 31:16 : N/A                                          */
   uint32_t s_eth_rx_filtre_dest_adr_7[47:32] : 16; /* Bits : 15:0  : Destination address 7 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_7_h_reg_u_bit;

typedef union
{
   uint32_t                                                 u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_7_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_7_h_reg;

/* Union definition for register 's_eth_rx_filtre_dest_adr_mask_h_reg' */
typedef struct
{
   uint32_t s_reserved                           : 16; /* Bits : 31:16 : N/A                                             */
   uint32_t s_eth_rx_filtre_dest_adr_mask[47:32] : 16; /* Bits : 15:0  : Destination address mask for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_mask_h_reg_u_bit;

typedef union
{
   uint32_t                                                    u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_mask_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_mask_h_reg;

/* Union definition for register 's_eth_rx_filtre_src_adr_0_h_reg' */
typedef struct
{
   uint32_t s_reserved                       : 16; /* Bits : 31:16 : N/A                                     */
   uint32_t s_eth_rx_filtre_src_adr_0[47:32] : 16; /* Bits : 15:0  : Source address 0 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_0_h_reg_u_bit;

typedef union
{
   uint32_t                                                u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_0_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_0_h_reg;

/* Union definition for register 's_eth_rx_filtre_src_adr_1_h_reg' */
typedef struct
{
   uint32_t s_reserved                       : 16; /* Bits : 31:16 : N/A                                     */
   uint32_t s_eth_rx_filtre_src_adr_1[47:32] : 16; /* Bits : 15:0  : Source address 1 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_1_h_reg_u_bit;

typedef union
{
   uint32_t                                                u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_1_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_1_h_reg;

/* Union definition for register 's_eth_rx_filtre_src_adr_2_h_reg' */
typedef struct
{
   uint32_t s_reserved                       : 16; /* Bits : 31:16 : N/A                                     */
   uint32_t s_eth_rx_filtre_src_adr_2[47:32] : 16; /* Bits : 15:0  : Source address 2 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_2_h_reg_u_bit;

typedef union
{
   uint32_t                                                u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_2_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_2_h_reg;

/* Union definition for register 's_eth_rx_filtre_src_adr_3_h_reg' */
typedef struct
{
   uint32_t s_reserved                       : 16; /* Bits : 31:16 : N/A                                     */
   uint32_t s_eth_rx_filtre_src_adr_3[47:32] : 16; /* Bits : 15:0  : Source address 3 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_3_h_reg_u_bit;

typedef union
{
   uint32_t                                                u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_3_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_3_h_reg;

/* Union definition for register 's_eth_rx_filtre_src_adr_4_h_reg' */
typedef struct
{
   uint32_t s_reserved                       : 16; /* Bits : 31:16 : N/A                                     */
   uint32_t s_eth_rx_filtre_src_adr_4[47:32] : 16; /* Bits : 15:0  : Source address 4 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_4_h_reg_u_bit;

typedef union
{
   uint32_t                                                u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_4_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_4_h_reg;

/* Union definition for register 's_eth_rx_filtre_src_adr_5_h_reg' */
typedef struct
{
   uint32_t s_reserved                       : 16; /* Bits : 31:16 : N/A                                     */
   uint32_t s_eth_rx_filtre_src_adr_5[47:32] : 16; /* Bits : 15:0  : Source address 5 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_5_h_reg_u_bit;

typedef union
{
   uint32_t                                                u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_5_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_5_h_reg;

/* Union definition for register 's_eth_rx_filtre_src_adr_6_h_reg' */
typedef struct
{
   uint32_t s_reserved                       : 16; /* Bits : 31:16 : N/A                                     */
   uint32_t s_eth_rx_filtre_src_adr_6[47:32] : 16; /* Bits : 15:0  : Source address 6 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_6_h_reg_u_bit;

typedef union
{
   uint32_t                                                u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_6_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_6_h_reg;

/* Union definition for register 's_eth_rx_filtre_src_adr_7_h_reg' */
typedef struct
{
   uint32_t s_reserved                       : 16; /* Bits : 31:16 : N/A                                     */
   uint32_t s_eth_rx_filtre_src_adr_7[47:32] : 16; /* Bits : 15:0  : Source address 7 for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_7_h_reg_u_bit;

typedef union
{
   uint32_t                                                u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_7_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_7_h_reg;

/* Union definition for register 's_eth_rx_filtre_src_adr_mask_h_reg' */
typedef struct
{
   uint32_t s_reserved                          : 16; /* Bits : 31:16 : N/A                                        */
   uint32_t s_eth_rx_filtre_src_adr_mask[47:32] : 16; /* Bits : 15:0  : Source address mask for RX frame filtering */
}
ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_mask_h_reg_u_bit;

typedef union
{
   uint32_t                                                   u_word;
   ts_fpga_reg_mac_eth_eth_rx_filtre_src_adr_mask_h_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_mask_h_reg;

/* Group of registers in 'mac_eth' named 'confguration_rx' */
typedef struct
{
   tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_0_h_reg    s_eth_rx_filtre_dest_adr_0_h_reg;
   uint32_t                                              s_eth_rx_filtre_dest_adr_0_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_1_h_reg    s_eth_rx_filtre_dest_adr_1_h_reg;
   uint32_t                                              s_eth_rx_filtre_dest_adr_1_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_2_h_reg    s_eth_rx_filtre_dest_adr_2_h_reg;
   uint32_t                                              s_eth_rx_filtre_dest_adr_2_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_3_h_reg    s_eth_rx_filtre_dest_adr_3_h_reg;
   uint32_t                                              s_eth_rx_filtre_dest_adr_3_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_4_h_reg    s_eth_rx_filtre_dest_adr_4_h_reg;
   uint32_t                                              s_eth_rx_filtre_dest_adr_4_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_5_h_reg    s_eth_rx_filtre_dest_adr_5_h_reg;
   uint32_t                                              s_eth_rx_filtre_dest_adr_5_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_6_h_reg    s_eth_rx_filtre_dest_adr_6_h_reg;
   uint32_t                                              s_eth_rx_filtre_dest_adr_6_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_7_h_reg    s_eth_rx_filtre_dest_adr_7_h_reg;
   uint32_t                                              s_eth_rx_filtre_dest_adr_7_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_dest_adr_mask_h_reg s_eth_rx_filtre_dest_adr_mask_h_reg;
   uint32_t                                              s_eth_rx_filtre_dest_adr_mask_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_0_h_reg     s_eth_rx_filtre_src_adr_0_h_reg;
   uint32_t                                              s_eth_rx_filtre_src_adr_0_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_1_h_reg     s_eth_rx_filtre_src_adr_1_h_reg;
   uint32_t                                              s_eth_rx_filtre_src_adr_1_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_2_h_reg     s_eth_rx_filtre_src_adr_2_h_reg;
   uint32_t                                              s_eth_rx_filtre_src_adr_2_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_3_h_reg     s_eth_rx_filtre_src_adr_3_h_reg;
   uint32_t                                              s_eth_rx_filtre_src_adr_3_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_4_h_reg     s_eth_rx_filtre_src_adr_4_h_reg;
   uint32_t                                              s_eth_rx_filtre_src_adr_4_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_5_h_reg     s_eth_rx_filtre_src_adr_5_h_reg;
   uint32_t                                              s_eth_rx_filtre_src_adr_5_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_6_h_reg     s_eth_rx_filtre_src_adr_6_h_reg;
   uint32_t                                              s_eth_rx_filtre_src_adr_6_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_7_h_reg     s_eth_rx_filtre_src_adr_7_h_reg;
   uint32_t                                              s_eth_rx_filtre_src_adr_7_l_reg;
   tu_fpga_reg_mac_eth_eth_rx_filtre_src_adr_mask_h_reg  s_eth_rx_filtre_src_adr_mask_h_reg;
   uint32_t                                              s_eth_rx_filtre_src_adr_mask_l_reg;
}
ts_fpga_reg_mac_eth_confguration_rx;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_eth_rx_status_1_reg' */
typedef struct
{
   uint32_t s_reserved                 : 24; /* Bits : 31:8 : N/A                          */
   uint32_t s_eth_rx_stat_frame_filtre :  8; /* Bits : 7:0  : Count of the filtered frames */
}
ts_fpga_reg_mac_eth_eth_rx_status_1_reg_u_bit;

typedef union
{
   uint32_t                                      u_word;
   ts_fpga_reg_mac_eth_eth_rx_status_1_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_status_1_reg;

/* Union definition for register 's_eth_rx_status_2_reg' */
typedef struct
{
   uint32_t s_eth_rx_stat_frame_err_phy : 8; /* Bits : 31:24 : Count of the PHY errors        */
   uint32_t s_eth_rx_stat_frame_err_fcs : 8; /* Bits : 23:16 : Count of the FCS errors        */
   uint32_t s_eth_rx_stat_frame_err_sz  : 8; /* Bits : 15:8  : Count of the frame size errors */
   uint32_t s_eth_rx_stat_frame_err_ifg : 8; /* Bits : 7:0   : Count of the IFG errors        */
}
ts_fpga_reg_mac_eth_eth_rx_status_2_reg_u_bit;

typedef union
{
   uint32_t                                      u_word;
   ts_fpga_reg_mac_eth_eth_rx_status_2_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_rx_status_2_reg;

/* Group of registers in 'mac_eth' named 'rx_status' */
typedef struct
{
   tu_fpga_reg_mac_eth_eth_rx_status_1_reg s_eth_rx_status_1_reg;
   tu_fpga_reg_mac_eth_eth_rx_status_2_reg s_eth_rx_status_2_reg;
}
ts_fpga_reg_mac_eth_rx_status;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_eth_tx_status_reg' */
typedef struct
{
   uint32_t s_reserved                 : 23; /* Bits : 31:9 : N/A                                                                                                       */
   uint32_t s_eth_tx_buffer_idle       :  1; /* Bits : 08   : Transmission status1: no more {tx_payload} to be transmitted  0:  there is {tx_payload} to be transmitted */
   uint32_t s_eth_tx_stat_frame_err_sz :  8; /* Bits : 7:0  : Count of the frame size errors                                                                            */
}
ts_fpga_reg_mac_eth_eth_tx_status_reg_u_bit;

typedef union
{
   uint32_t                                    u_word;
   ts_fpga_reg_mac_eth_eth_tx_status_reg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_eth_tx_status_reg;

/* Group of registers in 'mac_eth' named 'tx_status' */
typedef struct
{
   tu_fpga_reg_mac_eth_eth_tx_status_reg s_eth_tx_status_reg;
}
ts_fpga_reg_mac_eth_tx_status;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_mdio_cfg' */
typedef struct
{
   uint32_t s_mdio_start    :  1; /* Bits : 31    : 0: not enabled1: trig an access    */
   uint32_t s_mdio_rw_n     :  1; /* Bits : 30    : 1: Read Access0: Write Access      */
   uint32_t s_reserved      :  1; /* Bits : 29    : N/A                                */
   uint32_t s_mdio_reg_addr :  5; /* Bits : 28:24 : PHY Configuration register Address */
   uint32_t s_reserved      :  3; /* Bits : 23:21 : N/A                                */
   uint32_t s_mdio_phy_addr :  5; /* Bits : 20:16 : PHY Address                        */
   uint32_t s_mdio_wr_data  : 16; /* Bits : 15:0  : WR_DATA                            */
}
ts_fpga_reg_mac_eth_mdio_cfg_u_bit;

typedef union
{
   uint32_t                           u_word;
   ts_fpga_reg_mac_eth_mdio_cfg_u_bit u_bit;
}
tu_fpga_reg_mac_eth_mdio_cfg;

/* Union definition for register 's_mdio_rd_data' */
typedef struct
{
   uint32_t s_reserved     : 16; /* Bits : 31:16 : N/A       */
   uint32_t s_mdio_rd_data : 16; /* Bits : 15:0  : Read Data */
}
ts_fpga_reg_mac_eth_mdio_rd_data_u_bit;

typedef union
{
   uint32_t                               u_word;
   ts_fpga_reg_mac_eth_mdio_rd_data_u_bit u_bit;
}
tu_fpga_reg_mac_eth_mdio_rd_data;

/* Union definition for register 's_mdio_status' */
typedef struct
{
   uint32_t s_reserved  : 31; /* Bits : 31:1 : N/A                                                                                                                                                           */
   uint32_t s_mdio_busy :  1; /* Bits : 00   : Busy status0: MDIO Interface is not busy1: MDIO interface is busyBusy signal is active during the whole MDIO transaction (approximatively 35us - MDC at 2Mhz) */
}
ts_fpga_reg_mac_eth_mdio_status_u_bit;

typedef union
{
   uint32_t                              u_word;
   ts_fpga_reg_mac_eth_mdio_status_u_bit u_bit;
}
tu_fpga_reg_mac_eth_mdio_status;

/* Group of registers in 'mac_eth' named 'mdio_interface' */
typedef struct
{
   tu_fpga_reg_mac_eth_mdio_cfg     s_mdio_cfg;
   tu_fpga_reg_mac_eth_mdio_rd_data s_mdio_rd_data;
   tu_fpga_reg_mac_eth_mdio_status  s_mdio_status;
}
ts_fpga_reg_mac_eth_mdio_interface;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'mac_eth' */

typedef struct
{
   ts_fpga_reg_mac_eth_confguration_rx s_confguration_rx_regs;
   uint32_t                            s_spare_00[28];
   ts_fpga_reg_mac_eth_rx_status       s_rx_status_regs;
   uint32_t                            s_spare_01[6];
   ts_fpga_reg_mac_eth_tx_status       s_tx_status_regs;
   uint32_t                            s_spare_02[8];
   ts_fpga_reg_mac_eth_mdio_interface  s_mdio_interface_regs;
}
ts_fpga_reg_mac_eth;

#endif /* FPGA_REG_MAC_ETH_H */
