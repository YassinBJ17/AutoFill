/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Mailbox Rx read config1 function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MBX_CFEX_public.h"
#include "driver/mailbox/MBX_HAL_public.h"
#include "driver/mailbox/MBX_REG_common.h"

/* LPOS Private Interface */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void MBX_FIFO_RX_READ_CONFIG1 ( CMN_IOSP_ID_t const p_conf_ip_id,
                                tu_RX_FIFO_CONFIG1_REG * const p_status_value )
{
   /* Local Variable Declaration */
   ts_MBX_RX_REG volatile *    pt_rx_fifo_config1_reg;

   /* Store the driver registers in local variable */
   /* >RELAX<SYNCHRONe_C_Code_10.3> The cast is safe as the structure is used to retrieve all ts_MBX_RX_REG registers which start at this address. */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as all the structure fields are tailor-made for the different ts_MBX_RX_REG registers. */
   pt_rx_fifo_config1_reg = (ts_MBX_RX_REG volatile *)(tu_RX_FIRST_DATA_REG volatile *)c_MBX_CFEX_CONFIGURATION_tab[p_conf_ip_id].s_mbx_rx_fifo_address;

   /* Return Status value */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast changes register type to data type with same size */
   p_status_value->u_R = (uint32_t)(pt_rx_fifo_config1_reg->s_RX_FIFO_CONFIG1_REG);
}

/* ---------- internal operation bodies: ------------------------------------ */
