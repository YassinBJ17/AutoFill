/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/ethernet/DRV_COM_MNT_ETH_public.h"
#include "middleware/stack_ip/ETH_public.h"
#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/stack_ip/ETH_UDP_private.h"
#include "middleware/stack_ip/ETH_COMM_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */


/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
void DRV_COM_MNT_ETH_HANDLE_PORT (
 uint32_t const p_cmd_port,
                                   uint32_t const p_port_src,
                                   )
{
   *p_ETH_Init_status = e_ETH_UDP_PORT_ACTION_FAILED;

   /* TODO PAULO : filtrer les ports en entree de cette fonction pour n'accepter que les euls autorises*/

   /* Open - Close dynamically the PORT SRC */
   if (p_cmd_port != 0)
   {
      /* Open ICDL reception on Port required */
      ETH_UDP_OpenPort( p_port_src,
                        &(ethUdpInfo.s_IdDest.s_IpAddress),
                        p_udpBuffer,
                        p_ETH_Init_status );
      if ( p_isUOD != e_CMN_FLAG_NO )
      {
         ethUdpInfo.s_SrcPortUOD = p_port_src;
         udpBufferUODReception.s_buffer = p_udpBuffer->s_buffer;
         udpBufferUODReception.s_buffer_size = p_udpBuffer->s_buffer_size;
      }
   }
   else
   {
      /* Close reception on Port required */
      ETH_UDP_ClosePort( p_port_src,
                         p_ETH_Init_status );

      if (p_isUOD != e_CMN_FLAG_NO)
      {
         ethUdpInfo.s_SrcPortUOD = K_ETH_UDP_PORT_INVALID;
         udpBufferUODReception.s_buffer = NULL;
         udpBufferUODReception.s_buffer_size = 0;
      }
   }
}
