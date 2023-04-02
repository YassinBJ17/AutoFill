/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Mailbox ETH init function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MBX_CFEX_public.h"
#include "driver/mailbox/MBX_HAL_public.h"
#include "driver/mailbox/MBX_REG_common.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
void MBX_READ ( ts_CMN_IOSP_BUFFER * const p_buffer )
{
   tu_RX_FIRST_DATA_REG v_rx_first_data;
   uint32_t  v_timestamp;
   uint32_t offset;

   MBX_FIFO_READ_SIZE_DATA( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, &v_rx_first_data );
   MBX_FIFO_READ_TIMESTAMP_DATA( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, &v_timestamp );
   /* TODO PAULO : compute offset with v_rx_first_data.u_B.s_rx_tkeep */
   /* IT IS ALWAYS 2 !*/
   offset = 2;
   MBX_FIFO_READ_DATA( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, v_rx_first_data.u_B.s_rx_tsize, offset, p_buffer );

}

/* ---------- internal operation bodies: ------------------------------------ */
