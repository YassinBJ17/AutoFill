/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/icdl/ICDL_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/stack_ip/ETH_public.h"
#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/stack_ip/ETH_UDP_private.h"
#include "middleware/icdl/ICDL_public.h"
#include "middleware/icdl/ICDL_PLT_public.h"
#include "middleware/ethernet/DRV_COM_MNT_ETH_public.h"
#include "libtools/memory/LIB_MEM_public.h"

/* ---------- internal define constants: ------------------------------------ */
/*#define TEST_READ 1*/
#ifdef TEST_READ
uint32_t debug_rcv;
uint32_t once_create;
#endif
/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/*---------------------------------------------------------------------------
-- icdl_read
---------------------------------------------------------------------------*/
void icdl_read ( void )
{
   /* Local variables */
   uint32_t i;
   ts_DRV_COM_MNT_ETH_RX l_eth_rx;

/* TEST APPLICATION TO BE REMOVED */
#ifdef TEST_READ
   debug_rcv = 0;
   shmem.s_icdl_rx.rx_message_tab[1].s_port   = 50000;
   shmem.s_icdl_rx.rx_message_tab[1].s_length = ICDL_BUFFER_SIZE;
   if (once_create == 0)
   {
      once_create = 1;
      icdl_create_ports();
   }
#endif
/* END TEST APPLICATION TO BE REMOVED */


   /* Deal with AS ports */
   for ( i = 0; i < ICDL_AS_NB_PORT; i++ )
   {
      /* Update ICDL reception */
      if ( shmem.s_icdl_rx.rx_message_tab[i].s_port != 0 )
      {
         l_eth_rx.LCH_CTRL_RX_DATA                  = &(shmem.s_icdl_rx.rx_message_tab[i].s_data_buffer[0]);
         l_eth_rx.LCH_CTRL_RX_DATA_COUNT            = 0; /* receive size will be filled after */
         l_eth_rx.LCH_CTRL_RX_MSG_UDP_PORT_SRC      = (uint16_t)shmem.s_icdl_rx.rx_message_tab[i].s_port;
         l_eth_rx.LCH_CTRL_RX_MSG_UDP_PORT_DST      = (uint16_t)shmem.s_icdl_rx.rx_message_tab[i].s_port;

         DRV_COM_MNT_ETH_READ( &l_eth_rx );

         /*shmem.s_icdl_rx.rx_message_tab[i].s_port   = l_eth_rx.LCH_CTRL_RX_MSG_UDP_PORT_DST;*/
         shmem.s_icdl_rx.rx_message_tab[i].s_length = l_eth_rx.LCH_CTRL_RX_DATA_COUNT;
         shmem.s_icdl_rx.s_status.u_word            = l_eth_rx.LCH_CTRL_RX_status;
      /* TEST APPLICATION TO BE REMOVED */
#ifdef TEST_READ
         if (shmem.s_icdl_rx.rx_message_tab[i].s_port == 50000)
         {
            uint32_t j;
            debug_rcv = 0;
            for (j=0;j<6;j++)
            {
               if (shmem.s_icdl_rx.rx_message_tab[1].s_data_buffer[j]=='A')
               {
                  debug_rcv += 1;
               }
            }
         }
#endif
      /* END TEST APPLICATION TO BE REMOVED */

      }
   }

        /* Deal with UOD port */
/*   {*/
/*      l_eth_rx.LCH_CTRL_RX_MSG_UDP_PORT_SRC = K_UOD_UDP_PORTS_SRC;*/
/*      l_eth_rx.LCH_CTRL_RX_DATA             = (uint8_t *)(&Pt_extern_critical_services_icdl_params->in_msg);*/
/*      l_eth_rx.LCH_CTRL_RX_DATA_COUNT       = Pt_extern_critical_services_icdl_params->nb_bytes;  receive size will be filled after */
/*      DRV_COM_MNT_ETH_READ( &l_eth_rx );*/
/*      Pt_extern_critical_services_icdl_params->nb_bytes = l_eth_rx.LCH_CTRL_RX_DATA_COUNT;*/
/*      Pt_extern_critical_services_icdl_params->status   = l_eth_rx.LCH_CTRL_RX_status;*/
/*   }*/

}
