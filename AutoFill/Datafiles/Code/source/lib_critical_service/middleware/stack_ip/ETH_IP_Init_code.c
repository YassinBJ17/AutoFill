/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */


#include "middleware/stack_ip/ETH_IP_common.h"
#include "middleware/stack_ip/ETH_IP_private.h"
#include "libtools/memory/LIB_MEM_public.h"

void ETH_IP_Init(void)
{
   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, ControlObj is handled as a byte array */
   LIB_MEM_SET( (int8_t*) & v_ETH_IP_ControlObj,
                (int8_t)0x00,
                /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t */
                (uint32_t)sizeof ( ts_ETH_IP_CONTROL ) );

   v_ETH_IP_ControlObj.s_RxFragment.s_IPFRx_status = e_ETH_IP_FRGMT_FINISH ;

}
