/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_ICMP_common.h"
#include "middleware/stack_ip/ETH_ICMP_private.h"
#include "libtools/memory/LIB_MEM_public.h"

void ETH_ICMP_Init(void)
{
   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, buffer is initialized with zeros */
   LIB_MEM_SET( (int8_t* ) &  v_ETH_ICMP_ControlObj,
                (int8_t) 0x00,
                /* >RELAX<SYNCHRONe_C_Code_10.7> No loss, size_t fits on an uint32_t */
                (uint32_t) sizeof(ts_ETH_ICMP_CONTROL) );
}
