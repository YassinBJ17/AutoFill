/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/ethernet/DRV_COM_MNT_ETH_conf.h"
#include "middleware/ethernet/DRV_COM_MNT_ETH_public.h"
#include "middleware/stack_ip/ETH_COMM_public.h"
#include "middleware/stack_ip/ETH_IP_private.h"
#include "middleware/icdl/ICDL_PLT_public.h"
#include "libtools/memory/LIB_MEM_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
#if (ICDL_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_duration_mnt_eth_write_crc_time[DRV_COM_MNT_NB_FRAG_MAX+1];
#endif
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
void DRV_COM_MNT_ETH_WRITE ( ts_DRV_COM_MNT_ETH_TX * p_eth_tx )

{
#if (ICDL_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_start_time;
   CMN_SYSTEM_TIME_t    v_end_time;
#endif
   uint16_t v_nb_frags;

   /*
    * Check the command can be handled
    */
   v_nb_frags = 0;

   if ( p_eth_tx->LCH_CTRL_TX_MSG_SIZE != 0 )
   {
#if (ICDL_TIME_CONF_ENABLE != 0 )
      LIBT_TIME_GET( &v_start_time );
#endif

      /*
      * Sending (First IP fragment if any) of an UDP message
      */
      /*ethUdpInfo.s_IdDest.s_IpAddress.u_IP = ETH_CFEX_CDM_OS_EtherAddr.u_IP;*/
      /*p_eth_tx->LCH_CTRL_TX_MSG_IP_DST = (uint32_t)(ETH_CFEX_CDM_OS_EtherAddr.u_IP);*/
      ETH_COMM_write( p_eth_tx->LCH_CTRL_TX_MSG_DATA,
                      p_eth_tx->LCH_CTRL_TX_MSG_SIZE,
                      p_eth_tx->LCH_CTRL_TX_MSG_UDP_PORT_SRC,
                      p_eth_tx->LCH_CTRL_TX_MSG_UDP_PORT_DST,
                      p_eth_tx->LCH_CTRL_TX_MSG_IP_DST,
                      &(p_eth_tx->LCH_CTRL_TX_STATUS) );

#if (ICDL_TIME_CONF_ENABLE != 0)
      LIBT_TIME_GET( &v_end_time );
      v_duration_mnt_eth_write_crc_time[v_nb_frags] = v_end_time - v_start_time;
#endif

      while ( ( v_ETH_IP_ControlObj.s_TxFragment.s_nbLeftToSent != 0 ) && ( v_nb_frags < DRV_COM_MNT_NB_FRAG_MAX ) )
      {
         /*
          * Sending IP fragments of an UDP message
          */
#if (ICDL_TIME_CONF_ENABLE != 0 )
         LIBT_TIME_GET( &v_start_time );
#endif

         ETH_DRV_HandleEmission();

#if (ICDL_TIME_CONF_ENABLE != 0)
         LIBT_TIME_GET( &v_end_time );
         v_nb_frags++;
         v_duration_mnt_eth_write_crc_time[v_nb_frags] = v_end_time - v_start_time;
#endif
      }
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
