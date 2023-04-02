/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_public.h"
#include "middleware/ethernet/ETH_MAC_public.h"

/* CDR  - CDM */
#define ETH_CDM_AS_IP_ADDR 192,168,30,10
#define ETH_CDM_OS_A_IP_ADDR 192,168,10,10
#define ETH_CDM_OS_B_IP_ADDR 192,168,20,10
#define ETH_CDRA_IP_ADDR 192,168,10,1
#define ETH_CDRB_IP_ADDR 192,168,20,1

#define ETH_BENCH_IP_ADDR 172,127,3,99


/* CDR / CDM */
const tu_ETH_IPAddr ETH_CFEX_CDRAEtherAddr =  {ETH_CDRA_IP_ADDR};
const tu_ETH_IPAddr ETH_CFEX_CDRBEtherAddr =  {ETH_CDRB_IP_ADDR};

const tu_ETH_IPAddr ETH_CFEX_CDM_AS_EtherAddr =  {ETH_CDM_AS_IP_ADDR};

const tu_ETH_IPAddr ETH_CFEX_CDM_OS_A_EtherAddr =  {ETH_CDM_OS_A_IP_ADDR};
const tu_ETH_IPAddr ETH_CFEX_CDM_OS_B_EtherAddr =  {ETH_CDM_OS_B_IP_ADDR};

const tu_ETH_IPAddr ETH_CFEX_BENCH_EtherAddr =  {ETH_BENCH_IP_ADDR};

const MAC_ETH_MACAddr_t c_mac_CDMAaddr = MAC_ETH_CDMA_MAC_ADDR ;
const MAC_ETH_MACAddr_t c_mac_CDMBaddr = MAC_ETH_CDMB_MAC_ADDR ;
const MAC_ETH_MACAddr_t c_mac_CDRAaddr = MAC_ETH_CDRA_MAC_ADDR ;
const MAC_ETH_MACAddr_t c_mac_CDRBaddr = MAC_ETH_CDRB_MAC_ADDR ;

