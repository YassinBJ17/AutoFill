/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : ccdl_init function which allows ccdl initialization.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/ccdl/ccdl_public.h"
#include "middleware/ccdl/ccdl_private.h"
#include "libtools/memory/LIB_MEM_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Registers for CCDL */
ts_ccdl * fpga_ccdl;

/* CCDL frame size, inferred from dedicated structure @ init time */
uint32_t ccdl_frame_size_in_bytes;

/* Data used by a429 : ch A tells ch B to send data on a429 2ab */
ts_a429_tx ccdl_a429_2ab_tx_from_ch_a;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-CCDL-0010 */
void ccdl_init(void)
{
   /* Init pointer */
   fpga_ccdl = CCDL_ADDR;

   /* Enable CCDL TX in fpga */
   fpga_ccdl->s_tx_control.u_bit.s_ccdl_tx_enable = 1;

   /* Enable CCDL RX in fpga */
   fpga_ccdl->s_rx_control.u_bit.s_rx_enable = 1;

   /* Enable full duplex CCDL  */
   fpga_ccdl->s_rx_control.u_bit.s_echo_mode = 1;

   /* Initialize the frame size */
   ccdl_frame_size_in_bytes = sizeof(ts_ccdl_frame);

   /* Init data retrieved from ch A through CCDL on ch B */
   ccdl_a429_2ab_tx_from_ch_a.s_tx_count = 0;
   LIB_MEM_SET((int8_t*)ccdl_a429_2ab_tx_from_ch_a.s_tx_word, 0 , 4 * CCDL_A429_2AB_TX_WORDS_COUNT);
   ccdl_a429_2ab_tx_from_ch_a.s_tx_status.u_word = 0;
   /* TODO : other datas...*/


   /* ++ init shmem  + trame*/

}

/* ---------- internal operations: ------------------------------------------ */
