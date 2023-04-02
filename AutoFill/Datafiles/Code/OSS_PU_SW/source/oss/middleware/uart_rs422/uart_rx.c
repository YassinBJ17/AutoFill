/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : uart_rx function which allows UART Rx management
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/uart_rs422/uart_public.h"
#include "middleware/uart_rs422/uart_private.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "driver/uart/UART_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */
ts_CMN_IOSP_BUFFER context_rx;
int8_t uart_rx_double_buffer_0[UART_RS422_MAX_SIZE];
int8_t uart_rx_double_buffer_1[UART_RS422_MAX_SIZE];
int8_t * uart_rx_previous_buffer;

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-UART-0020 */
/* Manage UART Rx */
void uart_rx(void)
{
   /* Initialize rx fault word */
   tu_rs422_rx_fault_word *fault_word = &shmem.s_rs422_rx.s_rx_status;
   fault_word->u_word = 0;

   /* Switch Rx buffer to let UART work during Rx buffer processing :
      Note : it is not a problem to switch context buffer while a DMA transfer is potentially in progress, as the
      call to FDX_UART_DMA_START_READ actually registers the address held in context_rx in DMA prog structure. The
      context_rx is passed by value in this function. */
   uart_rx_previous_buffer = context_rx.s_buffer;
   if(uart_rx_double_buffer_0 == context_rx.s_buffer)
   {
      context_rx.s_buffer = uart_rx_double_buffer_1;
   }
   else
   {
      context_rx.s_buffer = uart_rx_double_buffer_0;
   }

   {
      uint32_t nb_of_bytes_read_previously;

      /* Terminate current DMA read and start a new one */
      FDX_UART_DMA_START_READ(0 , &context_rx , &nb_of_bytes_read_previously);

      /* If we have read more than UART_RS422_CAPABILITY_SIZE then get only
      UART_RS422_CAPABILITY_SIZE bytes and set error flag */
      if (nb_of_bytes_read_previously > UART_RS422_CAPABILITY_SIZE)
      {
         nb_of_bytes_read_previously = UART_RS422_CAPABILITY_SIZE;
         fault_word->u_bit.s_overflow_err = 1;
      }

      /* If no data has been received, raise a no rx flag */
      if(nb_of_bytes_read_previously == 0)
      {
         fault_word->u_bit.s_no_new_rx = 1;
      }

      /* Copy bytes of interest */
      LIB_MEM_CPY((int8_t*)&(shmem.s_rs422_rx.s_rx_word),
               uart_rx_previous_buffer,
               nb_of_bytes_read_previously);

      /* Clean Rx frame by removing potential old data */
      LIB_MEM_SET((int8_t*)&(shmem.s_rs422_rx.s_rx_word) + nb_of_bytes_read_previously,
                0,
                UART_RS422_CAPABILITY_SIZE - nb_of_bytes_read_previously);

      /* Notify CSS with the amount of data that has been received during this RTC */
      shmem.s_rs422_rx.s_rx_count = nb_of_bytes_read_previously;
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
