/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_UDP_PUBLIC_H
#define ETH_UDP_PUBLIC_H

#include "middleware/stack_ip/ETH_public.h"
#include "middleware/stack_ip/ETH_COMM_public.h"
#include "middleware/stack_ip/ETH_UDP_common.h"
#include "type/common_type.h"

typedef enum
{
   e_ETH_UDP_OK,
   e_ETH_UDP_DATA_SZ_ERROR ,
   e_ETH_UDP_ARP_ERROR
} te_ETH_UDP_Status ;

typedef enum
{
   e_ETH_UDP_PORT_OPEN,
   e_ETH_UDP_PORT_ALREADY_DONE,
   e_ETH_UDP_PORT_ALREADY_CLOSED,
   e_ETH_UDP_PORT_ACTION_FAILED
} te_ETH_UDP_PORT_Status ;


typedef struct
{
   uint32_t s_UDP_len ;
   uint32_t s_UDP_done ;
} ts_ETH_UDP_BUFF_STATS ;

extern void ETH_UDP_OpenPort( uint32_t                    const p_port,
                              const tu_ETH_IPAddr *       const p_addr,
                              const ts_CMN_IOSP_BUFFER *  const p_buff,
                              te_ETH_UDP_PORT_Status *    const p_status  );

extern void ETH_UDP_ClosePort( uint32_t                  const p_port,
                               te_ETH_UDP_PORT_Status *  const p_status );

extern uint32_t ETH_UDP_WRITE_GET_STATUS( ts_ETH_UDP_BUFF_STATS * const p_status );

extern uint32_t ETH_UDP_WRITE( uint32_t                         const p_port,
                           const ts_ETH_EthernetAddress *   const p_Destaddr,
                           uint32_t                         const p_SrcPort,
                           const ts_CMN_IOSP_BUFFER *       const p_data,
                           te_ETH_UDP_Status *              const p_status);

extern void ETH_UDP_READ_GET_STATUS( uint32_t                  const p_port,
                                     ts_ETH_UDP_BUFF_STATS *   const p_status );

extern void ETH_UDP_READ_CPY( uint32_t                const p_port,
                              ts_CMN_IOSP_BUFFER *    const p_data,
                              CMN_SYSTEM_SIZE_t *     const p_nbBytesWritten);

extern ts_ETH_UDP_RECEIVE_BUFF *ETH_UDP_GetReceivedBufferPort( uint32_t const p_PortNumber);

#endif /* ETH_UDP_PUBLIC_H */
