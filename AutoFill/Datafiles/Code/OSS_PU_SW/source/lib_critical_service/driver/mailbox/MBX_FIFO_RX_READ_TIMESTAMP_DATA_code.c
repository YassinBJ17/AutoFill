/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Mailbox Rx read timestamp data function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MBX_CFEX_public.h"
#include "driver/mailbox/MBX_HAL_public.h"
#include "driver/mailbox/MBX_REG_common.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void MBX_FIFO_READ_TIMESTAMP_DATA ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id,
                                    uint32_t * const p_timestamp )
{
   /* Local variable declaration */
   ts_MBX_RX_REG volatile *    pt_mbx_rx_data_fifo_reg_descr;
   /* */

   /* Local variable initialization */
   /* */

   /* Initialize the read size */

   /* Get the MBX_FIFO register descriptor */
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision. The structure type 'ts_MBX_FIFO_REG' is tailor-made for the registers starting at this address.  */
   pt_mbx_rx_data_fifo_reg_descr = (ts_MBX_RX_REG volatile *)c_MBX_CFEX_CONFIGURATION_tab[p_MBX_FIFO_conf_id].s_mbx_rx_fifo_address;

   /* Read */
   *p_timestamp = (uint32_t)(pt_mbx_rx_data_fifo_reg_descr->s_RX_DATA_REG);
   /* */
}

/* ---------- internal operation bodies: ------------------------------------ */
