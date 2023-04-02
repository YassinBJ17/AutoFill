/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_UDP_common.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "middleware/stack_ip/ETH_UDP_private.h"

void ETH_UDP_Init(void)
{
   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, object is handled as a byte array */
   LIB_MEM_SET( (int8_t*)&v_ETH_UDP_ControlObj,
                (const int8_t)0,
                /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t */
                (uint32_t)sizeof( ts_ETH_UDP_CONTROL ) );
}
