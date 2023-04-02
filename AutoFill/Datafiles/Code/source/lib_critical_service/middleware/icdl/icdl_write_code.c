/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/icdl/ICDL_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "type/common_type.h"

#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/stack_ip/ETH_public.h"
#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/stack_ip/ETH_UDP_private.h"
#include "middleware/icdl/ICDL_public.h"
#include "middleware/icdl/ICDL_PLT_public.h"
#include "middleware/ethernet/DRV_COM_MNT_ETH_public.h"
#include "middleware/accom/accom_public.h"
#include "libtools/memory/LIB_MEM_public.h"


/* ---------- internal define constants: ------------------------------------ */
/*#define TEST_WRITE 1*/
#define  ICDL_CHAN_A (uint32_t)0x55555555
#define  ICDL_CHAN_B (uint32_t)0xAAAAAAAA

/* ---------- internal types: ----------------------------------------------- */

typedef struct
{
   uint32_t health_word;
   uint32_t opp_health_word;
   uint32_t data[248];
} ts_send_to_mu_type;



/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/*---------------------------------------------------------------------------
-- icdl_write
---------------------------------------------------------------------------*/
void icdl_write ( void )
{
   /* Local variables */
   uint32_t i;

   ts_DRV_COM_MNT_ETH_TX l_eth_tx;
   ts_send_to_mu_type msg;

/* TEST APPLICATION TO BE REMOVED */
#ifdef TEST_WRITE
   shmem.s_icdl_tx.tx_message_tab[1].s_port = 50000;
   for (i=0;i<6;i++)
      shmem.s_icdl_tx.tx_message_tab[1].s_data_buffer[i]='A';
   shmem.s_icdl_tx.tx_message_tab[1].s_length = 6;
#endif
/* END TEST APPLICATION TO BE REMOVED */


   for ( i = 0; i < ICDL_AS_NB_PORT; i++ )
   {
      if ( shmem.s_icdl_tx.tx_message_tab[i].s_length != 0 )
      {
         if ( ( shmem.s_icdl_tx.tx_message_tab[i].s_port >= 50000 ) &&
              ( shmem.s_icdl_tx.tx_message_tab[i].s_port < 60000 ) )
         {
            /* #SEND_TO_MU frame */
            msg.health_word     = shmem.s_health_wd_status.u_word;
            msg.opp_health_word = shmem.s_o_health_wd_status_ccdl.u_word;
            LIB_MEM_CPY( (int8_t * const) msg.data,
                         (int8_t const * const) shmem.s_icdl_tx.tx_message_tab[i].s_data_buffer, 248 );
            ICDL_PLT_SendToMU( &msg, sizeof(msg), shmem.s_icdl_tx.tx_message_tab[i].s_port );
         }
         else
         {
            /* not a SEND_TO_MU frame */
            /* send frame as it is ie payload contains raw data */
            l_eth_tx.LCH_CTRL_TX_MSG_DATA         = &(shmem.s_icdl_tx.tx_message_tab[i].s_data_buffer[0]);
            l_eth_tx.LCH_CTRL_TX_MSG_SIZE         = shmem.s_icdl_tx.tx_message_tab[i].s_length;
            l_eth_tx.LCH_CTRL_TX_MSG_UDP_PORT_SRC = (uint16_t)shmem.s_icdl_tx.tx_message_tab[i].s_port;
            l_eth_tx.LCH_CTRL_TX_MSG_UDP_PORT_DST = (uint16_t)shmem.s_icdl_tx.tx_message_tab[i].s_port;

            if ( shmem.s_icdl_tx.tx_message_tab[i].s_port == K_UOD_UDP_PORTS_SRC )
            {
               /* UOD */
               l_eth_tx.LCH_CTRL_TX_MSG_IP_DST = (uint32_t)(ETH_CFEX_BENCH_EtherAddr.u_IP);
            }
            else
            {
               l_eth_tx.LCH_CTRL_TX_MSG_IP_DST = (uint32_t)(ETH_CFEX_CDM_AS_EtherAddr.u_IP);
            }
            DRV_COM_MNT_ETH_WRITE( &l_eth_tx );
         }
         shmem.s_icdl_tx.tx_message_tab[i].s_length = 0; /* reset size */
      }
   }


     /* Deal with UOD buffer */
/*   {*/
/*      l_eth_tx.LCH_CTRL_TX_MSG_UDP_PORT_SRC = K_UOD_UDP_PORTS_SRC;*/
/*      l_eth_tx.LCH_CTRL_TX_MSG_UDP_PORT_DST = K_UOD_UDP_PORTS_SRC;*/
/*      l_eth_tx.LCH_CTRL_TX_MSG_SIZE         = Pt_extern_critical_services_icdl_params->nb_bytes;*/
/*      l_eth_tx.LCH_CTRL_TX_MSG_DATA         = Pt_extern_critical_services_icdl_params->out_msg;*/
/*      DRV_COM_MNT_ETH_WRITE( &l_eth_tx );*/
/*      Pt_extern_critical_services_icdl_params->status = l_eth_tx.LCH_CTRL_TX_STATUS;*/
/*   }*/

}
