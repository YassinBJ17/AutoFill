/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ICDL_PLT_PUBLIC_H
#define ICDL_PLT_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "middleware/stack_ip/ETH_COMM_public.h"
#include "middleware/stack_ip/ETH_UDP_public.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */
typedef enum
{
   e_INIT_LOG = 1,
   e_CRITICAL_LOG,
   e_TRIGGER_LOG,
   e_TEMP_STREAM_LOG,
   e_PLATFORM_LOG,
   e_SECURITY_LOG
}
te_TYPE_LOG ;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided datas: ----------------------------------------------- */
extern const tu_ETH_IPAddr ETH_CFEX_CDM_OS_A_EtherAddr ;
extern const tu_ETH_IPAddr ETH_CFEX_CDM_OS_B_EtherAddr ;

/* ---------- provided operations: ------------------------------------------ */
extern void ICDL_PLT_Init( void );

extern t_eth_comm_status ICDL_PLT_Eth_comm_write( void );

extern void ICDL_PLT_Eth_SendFragmentedFrame( void );

extern void ICDL_PLT_SendTestFrame( CMN_SYSTEM_ADDR_t const p_buff_addr,
                                    CMN_SYSTEM_SIZE_t const p_buff_size );

extern void ICDL_PLT_SendDataLog ( CMN_SYSTEM_ADDR_t const p_buff_addr,
                                   CMN_SYSTEM_SIZE_t const p_buff_size,
                                   te_TYPE_LOG p_logType );

extern void ICDL_PLT_SendTemperatureStream ( CMN_SYSTEM_ADDR_t const p_buff_addr,
                                             CMN_SYSTEM_SIZE_t const p_buff_size,
                                             uint32_t const p_nb_sensors );

extern void ICDL_PLT_SendPowerUpCount ( CMN_SYSTEM_ADDR_t const p_buff_addr,
                                        CMN_SYSTEM_SIZE_t const p_buff_size );

extern void ICDL_PLT_SendLastPwrUptime ( CMN_SYSTEM_ADDR_t const p_buff_addr,
                                         CMN_SYSTEM_SIZE_t const p_buff_size );

extern void ICDL_PLT_SendSecuAlertAck ( CMN_SYSTEM_ADDR_t const p_buff_addr,
                                        CMN_SYSTEM_SIZE_t const p_buff_size );

extern boolean_t ICDL_PLT_ReceiveSecuAlert( void );

extern boolean_t ICDL_PLT_ReceiveMuAlive ( uint8_t * pt_buff, uint32_t * pt_size );

extern void ICDL_PLT_SendToMU ( CMN_SYSTEM_ADDR_t const p_buff_addr,
                                CMN_SYSTEM_SIZE_t const p_buff_size,
                                uint32_t port );

#endif /* ICDL_PLT_PUBLIC_H */
