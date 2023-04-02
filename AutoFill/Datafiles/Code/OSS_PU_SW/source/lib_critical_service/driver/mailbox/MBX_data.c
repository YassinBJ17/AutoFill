/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/mailbox/MBX_CFEX_public.h"
#include "driver/mailbox/MBX_HAL_public.h"
#include "driver/mailbox/MBX_REG_common.h"
#include "driver/mailbox/MBX_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */


/* ---------- internal data: ------------------------------------------------ */

/* */
/* Receive buffer Descriptor */
uint32_t MBX_rxBuf [ INTEG_MBX_CFEX_RX_BUF_SIZE_IN_WORDS ] ;
/* }}<SYNCHRONe_C_Code_8.15>  */

tu_MBX_TX_STATUS g_mbx_tx_status;

#ifdef CBIT_MBX
ts_MBX_CBIT_STATUS cbit_mbx_status;
#endif
/* ---------- provided operation bodies: ------------------------------------ */
