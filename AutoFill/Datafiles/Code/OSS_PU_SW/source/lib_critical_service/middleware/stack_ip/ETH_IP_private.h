/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_IP_PRIVATE_H
#define ETH_IP_PRIVATE_H

#include "middleware/stack_ip/ETH_IP_common.h"
#include "middleware/stack_ip/ETH_common.h"
#include "middleware/stack_ip/ETH_INTEG_common.h"
#include "libtools/time/LIB_TIME_public.h"
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"

/* ---------- provided define constants --------------------------------------- */

#define K_MAX_MF_DATA_SIZE ( (uint32_t)K_ETH_MAX_ENET_PACKET_SIZE - \
                             ( (uint32_t)(sizeof(ts_ETH_EthernetHeader)) + \
                               (uint32_t)K_ETH_IP_FCS_SIZE + \
                               (uint32_t)(sizeof(ts_ETH_IP_Header)) ) )


/* Flag field definitions*/
#define K_ETH_IP_FRAG_OFFSET_LSB      (8) /* In bytes*/
#define K_ETH_IP_DONT_FRAGMENT_MASK   (0x4000u)  /* don't fragment flag*/
#define K_ETH_IP_IS_FRAGMENT_MASK     (0x2000u)
#define K_ETH_IP_FRAGMENT_OFFSET_MASK (0x1FFFu)
#define K_ETH_IP_DONT_FRAGMENT        (K_ETH_IP_DONT_FRAGMENT_MASK)  /* don't fragment flag*/

#define K_ETH_IP_VERSION          (4)
#define K_ETH_TYPE_OF_IP_SERVICE  (0)   /* normal precedence & normal delay, throughput & reliability */

/* ---------- provided types -------------------------------------------------- */

#define K_ETH_IP_FRAGMENT_DATA (K_ETH_MAX_ENET_PACKET_SIZE - \
                  (uint32_t)sizeof(ts_ETH_EthernetHeader) - \
                  (uint32_t)sizeof(ts_ETH_IP_Header) )

#define K_ETH_IP_INVALID (0ul)

typedef PACKED_U08 struct
{
   ts_ETH_EthernetHeader s_IPF_eth;
   ts_ETH_IP_Header      s_IPF_ip ;
   /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t (see macro definition) */
   int8_t                s_IPF_data[K_ETH_IP_FRAGMENT_DATA ] ;
} ts_ETH_IP_FRAGMENT_PACKET;

typedef struct
{

   uint32_t                   s_NextOffset;
   uint32_t                   s_nbLeftToSent;
   ts_CMN_IOSP_BUFFER         s_origineBuff;
   ts_ETH_IP_FRAGMENT_PACKET  s_IPFTx_Packetbuff ;
   ts_ETH_STATS_PACKET        s_IPFstats;
} ts_ETH_IP_FRAGMENT_TX_MNGT ;

typedef enum
{
   e_ETH_IP_FRGMT_INVALID ,
   e_ETH_IP_FRGMT_IN_PROG,
   e_ETH_IP_FRGMT_TIMEOUT ,
   e_ETH_IP_FRGMT_FINISH
} te_ETH_IP_FRGMT_STATUS ;

typedef struct
{
   uint32_t                s_dataLen ;
   te_ETH_IP_FRGMT_STATUS  s_IPFRx_status;
   ts_LIB_TIME_CHRONO      s_chrono;
   int8_t                  s_Packetbuff[ INTEG_ETH_IP_SIZE_MAX_DATA_EXCHANGE ] ;
} ts_ETH_IP_FRAGMENT_RX_MNGT ;

typedef struct
{
   ts_ETH_IP_FRAGMENT_TX_MNGT   s_TxFragment;
   ts_ETH_IP_FRAGMENT_RX_MNGT   s_RxFragment;
   ts_ETH_STATS                 s_IPstats;
} ts_ETH_IP_CONTROL ;

/* ---------- provided constants and data  ------------------------------------ */

/* */
extern ts_ETH_IP_CONTROL v_ETH_IP_ControlObj;


/* ---------- provided function ----------------------------------------------- */

/* */
extern void ETH_IP_Reassembly ( const ts_CMN_IOSP_BUFFER * const p_Data,
                                uint32_t                   const v_offSetFragment,
                                uint32_t                   const v_flagFragment,
                                te_CMN_FLAG_VALIDITY *     const p_validData);




extern void ETH_IP_Build_SingleFrame( const tu_ETH_IPAddr *      const p_Destaddr,
                                      const ts_CMN_IOSP_BUFFER * const p_data) ;

extern void ETH_IP_Build_MultiFrame ( const tu_ETH_IPAddr *      const p_Destaddr ,
                                      const ts_CMN_IOSP_BUFFER * const p_header,
                                      const ts_CMN_IOSP_BUFFER * const p_dataToSent,
                                      ts_CMN_IOSP_BUFFER *       const p_dataOut  ) ;

#endif /* ETH_IP_PRIVATE_H */
