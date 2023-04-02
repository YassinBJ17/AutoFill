/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Mailbox Tx cmd read status function
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
void MBX_FIFO_TX_CMD_READ_STATUS ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id,
                                   tu_MBX_TX_CMD_FIFO_STATUS_REG * const p_status_value )
{
   /* Local Variable Declaration */
   ts_MBX_TX_CMD_REG volatile * pt_tx_cmd_fifo_status_reg;

   /* Store the driver registers in local variable */
   /* >RELAX<SYNCHRONe_C_Code_10.3> The cast is safe as the structure is used to retrieve all ts_MBX_TX_CMD_REG registers which start at this address. */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as all the structure fields are tailor-made for the different ts_MBX_TX_CMD_REG registers. */
   pt_tx_cmd_fifo_status_reg = (ts_MBX_TX_CMD_REG volatile *)c_MBX_CFEX_CONFIGURATION_tab[p_MBX_FIFO_conf_id].s_mbx_tx_cmd_fifo_address;

   /* Return Status value */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast changes register type to data type with same size */
   p_status_value->u_R = (reg32_t)pt_tx_cmd_fifo_status_reg->s_TX_CMD_FIFO_STATUS_REG;
}

/* ---------- internal operation bodies: ------------------------------------ */
