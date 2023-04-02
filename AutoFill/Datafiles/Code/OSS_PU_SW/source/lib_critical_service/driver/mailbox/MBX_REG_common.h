/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef MBX_REG_COMMON_H
#define MBX_REG_COMMON_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- provided types: ----------------------------------------------  */
/* FPGA MBX Register */
typedef struct
{
   /*** Management ***/
   /* Fifo data register (Offset: 0x0000) */
   reg32_t s_RX_DATA_REG;
   /*  Fifo status register */
   reg32_t s_RX_FIFO_STATUS_REG;
   /*  Fifo status acknowledge register */
   reg32_t s_RX_FIFO_STATUS_ACK_REG;
   /*  Fifo control register */
   reg32_t s_RX_FIFO_CONTROL_REG;
   /*  Fifo configuration register */
   reg32_t s_RX_FIFO_CONFIG1_REG;
   /*  Fifo Key 1 enable reception register */
   reg32_t s_RX_ENABLE_SET_KEY_1_REG;
   /*  Fifo Key 2 enable reception register */
   reg32_t s_RX_ENABLE_SET_KEY_2_REG;
   /*  Fifo Key 1 disable reception register */
   reg32_t s_RX_ENABLE_CLEAR_KEY_1_REG;
   /*  Fifo Key 2 disable reception register */
   reg32_t s_RX_ENABLE_CLEAR_KEY_2_REG;
}
ts_MBX_RX_REG;


typedef struct
{
   /*** Management ***/
   /* Fifo data register (Offset: 0x0000) */
   reg32_t s_TX_DATA_REG;
   /*  Fifo status register */
   reg32_t s_TX_FIFO_STATUS_REG;
   /*  Fifo status acknowledge register */
   reg32_t s_TX_FIFO_STATUS_ACK_REG;
   /*  Fifo control register */
   reg32_t s_TX_FIFO_CONTROL_REG;
   /*  Fifo configuration register */
   reg32_t s_TX_FIFO_CONFIG1_REG;
}
ts_MBX_TX_REG;


typedef struct
{
   /*** Management ***/
   /* Fifo data register (Offset: 0x0000) */
   reg32_t s_TX_CMD_DATA_REG;
   /*  Fifo status register */
   reg32_t s_TX_CMD_FIFO_STATUS_REG;
   /*  Fifo status acknowledge register */
   reg32_t s_TX_CMD_FIFO_STATUS_ACK_REG;
   /*  Fifo control register */
   reg32_t s_TX_CMD_FIFO_CONTROL_REG;
   /*  Fifo configuration register */
   reg32_t s_TX_CMD_FIFO_CONFIG_REG;
   /*  Fifo configuration register */
   reg32_t s_TX_CMD_FIFO_DELAY_CONFIG_REG;
   /*  Fifo Key 1 enable reception register */
   reg32_t s_TX_ENABLE_SET_KEY_1_REG;
   /*  Fifo Key 2 enable reception register */
   reg32_t s_TX_ENABLE_SET_KEY_2_REG;
   /*  Fifo Key 1 disable reception register */
   reg32_t s_TX_ENABLE_CLEAR_KEY_1_REG;
   /*  Fifo Key 2 disable reception register */
   reg32_t s_TX_ENABLE_CLEAR_KEY_2_REG;
}
ts_MBX_TX_CMD_REG;

/* ---------- provided global variable--------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided operations: ------------------------------------------ */


#endif /* MBX_REG_COMMON_H */
