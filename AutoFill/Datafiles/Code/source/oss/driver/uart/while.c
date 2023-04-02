#include "UART_CFEX_public.h"
#include "UART_HAL_public.h"
#include "driver/dma/DMA_HAL_public.h"
#include "libtools/time/LIB_TIME_public.h"

       while ( ( 0x1000u != ( c_uart_reg.s_uart_common_reg->s_LINSR.u_R & 0xF000u ) ) && ( v_time < v_timeout ) )       {             LIBT_TIME_GET ( &v_time ) ;       }
