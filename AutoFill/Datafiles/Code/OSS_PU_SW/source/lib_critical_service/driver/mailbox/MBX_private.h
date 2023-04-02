/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef MBX_PRIVATE_H
#define MBX_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided constants: ------------------------------------------- */
/* */

#define as_return_no_frame      15
#define as_return_crc_err       14
#define as_return_sz_error      13
#define as_return_frmt_err      12
#define as_return_overflow      15
#define as_return_mem_corr      6

/* ---------- provided types: ----------------------------------------------- */
#ifdef CBIT_MBX
typedef struct
{
   uint32_t RX_status;
   uint32_t TX_status;
}
ts_MBX_CBIT_STATUS;
#endif /* CBIT_MBX */

extern tu_MBX_TX_STATUS g_mbx_tx_status;

#ifdef CBIT_MBX
extern ts_MBX_CBIT_STATUS cbit_mbx_status;
#endif

#endif /* MBX_PRIVATE_H */
