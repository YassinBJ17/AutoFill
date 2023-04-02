/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_PUBLIC_H
#define ETH_PUBLIC_H

/* ---------- DLD symbol ---------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
#include "type/common_type.h"

#include "middleware/ethernet/ETH_MAC_public.h"

/* u_IP Version 4 internet address type definition*/
#define K_PROTOCOL_ADDR_LEN 4
typedef PACKED_U08 union
{
   uint8_t        u_IP_Def[  K_PROTOCOL_ADDR_LEN ];
   uint32_t      u_IP;
}
tu_ETH_IPAddr;

#define K_HW_ADDR_LEN 6
typedef  PACKED_U08 struct
{
   uint8_t  s_val[ K_HW_ADDR_LEN ];
} ts_ETH_MACAddr;

/* Ethernet address type*/
typedef PACKED_U08 struct
{
   ts_ETH_MACAddr      s_HwAddress;
   uint16_t            s_Gap;
   tu_ETH_IPAddr       s_IpAddress;
}
ts_ETH_EthernetAddress;

/* ---------- provided variables: ------------------------------------------- */
extern const tu_ETH_IPAddr ETH_CFEX_CDRAEtherAddr ;
extern const tu_ETH_IPAddr ETH_CFEX_CDRBEtherAddr ;
/* ---------- provided operations: ------------------------------------------ */


extern void ETH_INIT( tu_CMN_RC * const p_rc );


extern void ETH_DRV_HandleReception(void) ;

extern void ETH_DRV_HandleEmission(void);

extern void ETH_ESTABLISH_CONNECTION( te_CMN_FLAG_ACTIVATION * const p_done );

extern void ETH_COPY_MAC_ADD( ts_ETH_MACAddr * const p_dst,
                              const ts_ETH_MACAddr* const p_src) ;

#endif /* ETH_PUBLIC_H */
