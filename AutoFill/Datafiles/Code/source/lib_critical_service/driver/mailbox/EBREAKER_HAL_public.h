/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef EBREAKER_HAL_PUBLIC_H
#define EBREAKER_HAL_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "type/common_type.h"

/* ---------- provided operations: ------------------------------------------ */

/* Management function for Mbx */
/* */
extern void EBREAKER_FIFO_RX_DISABLE_SET_KEY1 ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id );

extern void EBREAKER_FIFO_RX_DISABLE_SET_KEY2 ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id );

extern void EBREAKER_FIFO_RX_ENABLE_SET_KEY1 ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id );

extern void EBREAKER_FIFO_RX_ENABLE_SET_KEY2 ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id );

extern void EBREAKER_FIFO_TX_CMD_DISABLE_SET_KEY1 ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id );

extern void EBREAKER_FIFO_TX_CMD_DISABLE_SET_KEY2 ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id );

extern void EBREAKER_FIFO_TX_CMD_ENABLE_SET_KEY1 ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id );

extern void EBREAKER_FIFO_TX_CMD_ENABLE_SET_KEY2 ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id );


#endif /* EBREAKER_HAL_PUBLIC_H */
