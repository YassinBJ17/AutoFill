/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Mailbox Write function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MBX_CFEX_public.h"
#include "driver/mailbox/MBX_HAL_public.h"
#include "driver/mailbox/MBX_REG_common.h"

/* ---------- include required interface: ----------------------------------- */
#include "driver/mailbox/MAC_ETH_CFEX_public.h"
#include "driver/mailbox/MAC_ETH_HAL_public.h"
#include "driver/mailbox/MAC_ETH_REG_common.h"

#include "driver/mailbox/MBX_conf.h"
#if (MBX_TIME_CONF_ENABLE != 0)
#include "libtools/time/LIB_TIME_public.h"
#endif

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */
#if (MBX_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_duration_mbx_write_time;
#endif
/* ---------- provided operation bodies: ------------------------------------ */
/* PRECONDITION :  p_buff->s_buffer_size should be in range [1 ; 2^16-1]*/
void MBX_WRITE( const ts_CMN_IOSP_BUFFER* const p_buff  )
{
   uint32_t v_i;
   uint32_t v_length ;
   uint32_t v_length_lastbytes ;
   tu_TX_CMD_DATA_REG            v_tx_fifo_data;
   uint32_t * pt_todata32Bytes;
   uint16_t * pt_todata16Bytes;
   uint8_t  * pt_todata8Bytes;
   uint32_t v_lastBytes;
#if (MBX_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t v_start_time;
   CMN_SYSTEM_TIME_t v_end_time;
#endif


#if (MBX_TIME_CONF_ENABLE != 0 )
   LIBT_TIME_GET( &v_start_time );
#endif

   pt_todata32Bytes = (uint32_t *)p_buff->s_buffer;

   /*
    * Gestion de l'offset de 2
   */
   MBX_FIFO_TX_WRITE_DATA ((CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, *pt_todata32Bytes >> 16);
   pt_todata16Bytes = (uint16_t *)p_buff->s_buffer;
   pt_todata16Bytes++;
   pt_todata32Bytes = (uint32_t *)pt_todata16Bytes;

   v_length = ( (p_buff->s_buffer_size -2) / 4ul)  ;
   v_length_lastbytes = ((p_buff->s_buffer_size -2) % 4); /* the length is not a multiple of 4 */

   for ( v_i = 0; v_i < v_length ; v_i++ )
   {
      MBX_FIFO_TX_WRITE_DATA ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, *pt_todata32Bytes );
      pt_todata32Bytes++;
   }

   /*
    * the length is not a multiple of 4
    */

   if ( v_length_lastbytes == 1 )
   {
      pt_todata8Bytes = (uint8_t *)pt_todata32Bytes;
      v_lastBytes = ( (uint32_t)(*pt_todata8Bytes) << 24u );
      MBX_FIFO_TX_WRITE_DATA ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, v_lastBytes );
   }
   else if ( v_length_lastbytes == 2 )
   {
      pt_todata16Bytes = (uint16_t *)pt_todata32Bytes;
      v_lastBytes = ( (uint32_t)(*pt_todata16Bytes) << 16u );
      MBX_FIFO_TX_WRITE_DATA ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, v_lastBytes );
   }
   else if ( v_length_lastbytes == 3 ) /* the length is not multiple of 4 -> only 3 last bytes to write to the buffer */
   {
      pt_todata8Bytes = (uint8_t *)pt_todata32Bytes;
      v_lastBytes = ( (uint32_t)(*pt_todata8Bytes) << 24u );
      pt_todata8Bytes++;
      v_lastBytes = ( (v_lastBytes) | (uint32_t)(*pt_todata8Bytes) << 16u );
      pt_todata8Bytes++;
      v_lastBytes = ( (v_lastBytes) | (uint32_t)(*pt_todata8Bytes) << 8u );
      MBX_FIFO_TX_WRITE_DATA ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, v_lastBytes );
   }

   v_tx_fifo_data.u_tx_fifo_send.tx_source = 0;
   v_tx_fifo_data.u_tx_fifo_send.tx_offset = 2;
   v_tx_fifo_data.u_tx_fifo_send.tx_size = p_buff->s_buffer_size;

   MBX_FIFO_TX_CMD_WRITE_DATA ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, &v_tx_fifo_data );

#if (MBX_TIME_CONF_ENABLE != 0)
   LIBT_TIME_GET( &v_end_time );
   v_duration_mbx_write_time = v_end_time - v_start_time;
#endif


}

/* ---------- internal operation bodies: ------------------------------------ */
