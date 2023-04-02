/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : uart_init which allows UART initialization
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/uart_rs422/uart_public.h"
#include "middleware/uart_rs422/uart_private.h"
#include "driver/uart/UART_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */
#define  MRAM_UOD_CONFIG_ADDR           0x200103E8
#define  MRAM_UOD_CONFIG_MASK_ETH       0x3

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */
int8_t disable_uart_for_uod;

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-UART-0010 */
void uart_init(const boolean_t p_channel_is_a)
{
   /* In UOD mode, do not init uart */
   uint32_t * mram_uod_config_addr = (uint32_t *)MRAM_UOD_CONFIG_ADDR;
   uint32_t   mram_uod_config_val  = *mram_uod_config_addr;

   if((mram_uod_config_val & MRAM_UOD_CONFIG_MASK_ETH) == MRAM_UOD_CONFIG_MASK_ETH)  /* UOD configured in ETH direct mode ? */
   {
      /* UOD in eth mode, let's init UART */
      disable_uart_for_uod = 0;

      /* Configuration for UART driver */
      uart_configuration(p_channel_is_a);

      /* Initialize UART driver */
      {
        tu_CMN_RC v_return_code;
        v_return_code.u_r = 0UL;
        FDX_UART_INIT(&v_return_code);
      }

      /* Initialize Tx buffer for DMA transfer from shared mem */
      context_tx.s_buffer      = (int8_t*)&(shmem.s_rs422_tx.s_tx_word);
      context_tx.s_buffer_size = 0;

      /* Initialize Rx buffer for DMA transfers and corresponding size */
      context_rx.s_buffer      = uart_rx_double_buffer_0;
      context_rx.s_buffer_size = UART_RS422_CAPABILITY_SIZE + 1;   /* Problem with UART/DMA driver if 256 bytes request with UART_RS422_CAPABILITY_SIZE set to 256 (read count stays @ 256 instead of being reset to zero when Rx stops...) */

      /* Initialize internal send status, mentioning Tx service is idle */
      is_currently_sending     = TX_IDLE;
   }
   else
   {
      /* Set global flag to disable UART/RS422 link and let UOD work in UART mode */
      disable_uart_for_uod = 1;
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
