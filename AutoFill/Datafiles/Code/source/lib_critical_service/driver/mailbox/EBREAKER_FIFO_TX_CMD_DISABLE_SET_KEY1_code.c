/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Mailbox Tx cmd disable key1 function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MBX_CFEX_public.h"
#include "driver/mailbox/EBREAKER_HAL_public.h"
#include "driver/mailbox/MBX_REG_common.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
#define F_FIFO_TX_DISABLE_SET_KEY1 (reg32_t)0x02EB5233

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void EBREAKER_FIFO_TX_CMD_DISABLE_SET_KEY1 ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id )
{
   /* Local Variable Declaration */
   ts_MBX_TX_CMD_REG volatile * pt_tx_disable_set_key_1_reg;

   /* Store the driver registers in local variable */
   /* >RELAX<SYNCHRONe_C_Code_10.3> The cast is safe as the structure is used to retrieve all ts_MBX_TX_CMD_REG registers which start at this address. */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as all the structure fields are tailor-made for the different ts_MBX_TX_CMD_REG registers. */
   pt_tx_disable_set_key_1_reg = (ts_MBX_TX_CMD_REG volatile *)c_MBX_CFEX_CONFIGURATION_tab[p_MBX_FIFO_conf_id].s_mbx_tx_cmd_fifo_address;

   /* Return Status value */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast changes register type to data type with same size */
   pt_tx_disable_set_key_1_reg->s_TX_ENABLE_CLEAR_KEY_1_REG = F_FIFO_TX_DISABLE_SET_KEY1;

}



/* ---------- internal operation bodies: ------------------------------------ */
