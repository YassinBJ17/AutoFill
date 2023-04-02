/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_IP_common.h"
#include "middleware/stack_ip/ETH_IP_private.h"
#include "middleware/stack_ip/ETH_IP_conf.h"
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"
#include "middleware/ethernet/ETH_porting.h"

#if (ETH_IP_TIME_CONF_ENABLE != 0)
#include "libtools/time/LIB_TIME_public.h"
#endif

te_CMN_FLAG_VALIDITY ETH_IP_Manage_L_Check ( const ts_CMN_IOSP_BUFFER * const p_Data ) ;

#if (ETH_IP_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_duration_ip_Manage_crc_time;
#endif

void ETH_IP_Manage ( const ts_CMN_IOSP_BUFFER * const p_Data ,
                     ts_CMN_IOSP_BUFFER * const p_DataReassembly )
{
   const ts_ETH_IP_Header *   c_IPHeader_pt ;
   uint32_t                   v_flagFragment ;
   uint32_t                   v_offSetFragment ;
   te_CMN_FLAG_VALIDITY       v_valid ;

   v_valid = ETH_IP_Manage_L_Check ( p_Data ) ;

   if ( v_valid == e_CMN_FLAG_NOT_VALID )
   {
      v_ETH_IP_ControlObj.s_IPstats.s_packet_rx.s_nok++ ;
      /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, buffer is initialized with NULL */
      p_DataReassembly->s_buffer = NULL ;
      p_DataReassembly->s_buffer_size = 0UL ;
   }
   else
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_17.4>: operation is safe, buffer is handled as a byte array, with shift over header */
      c_IPHeader_pt = (const ts_ETH_IP_Header *) ( p_Data->s_buffer + sizeof(ts_ETH_EthernetHeader) ) ;
      /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, uint16_t masked with 0x2000 fits on uint32_t */
      v_flagFragment = (uint32_t)( (uint32_t)c_IPHeader_pt->s_IP_Flags_FragOffset & (uint32_t)K_ETH_IP_IS_FRAGMENT_MASK ) ;
      /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, uint16_t masked with 0x1FFF * 8 fits on uint32_t */
      v_offSetFragment = (uint32_t)( (uint32_t)c_IPHeader_pt->s_IP_Flags_FragOffset & (uint32_t)K_ETH_IP_FRAGMENT_OFFSET_MASK ) * ((uint32_t)K_ETH_IP_FRAG_OFFSET_LSB) ;

      if ( ( v_flagFragment == 0UL ) && ( v_offSetFragment == 0UL ) )
      {
         /* no fragmentation  */
         p_DataReassembly->s_buffer = p_Data->s_buffer ;
/*
* MBX discard from Ethernet frame size the FCS
*/
#if (ETH_FEC != 0 )
         p_DataReassembly->s_buffer_size = p_Data->s_buffer_size - K_ETH_IP_FCS_SIZE ;
#else
         p_DataReassembly->s_buffer_size = p_Data->s_buffer_size ;
#endif
      }
      else
      {

         ETH_IP_Reassembly ( p_Data ,
                             v_offSetFragment ,
                             v_flagFragment ,
                             &v_valid ) ;

         if ( v_valid == e_CMN_FLAG_NOT_VALID )
         {
            v_ETH_IP_ControlObj.s_IPstats.s_packet_rx.s_nok ++ ;
         }
         else
         {
            switch ( v_ETH_IP_ControlObj.s_RxFragment.s_IPFRx_status )
            {
               case e_ETH_IP_FRGMT_IN_PROG :
                  /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, buffer is initialized with NULL */
                  p_DataReassembly->s_buffer = NULL ;
                  p_DataReassembly->s_buffer_size = 0UL ;
                  break ;

               case e_ETH_IP_FRGMT_FINISH :
                  v_ETH_IP_ControlObj.s_IPstats.s_packet_rx.s_handled++ ;
                  p_DataReassembly->s_buffer = v_ETH_IP_ControlObj.s_RxFragment.s_Packetbuff ;
                  p_DataReassembly->s_buffer_size = v_ETH_IP_ControlObj.s_RxFragment.s_dataLen ;
                  break ;

               case e_ETH_IP_FRGMT_TIMEOUT :
               case e_ETH_IP_FRGMT_INVALID :
               default :
                  /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, buffer is initialized with NULL */
                  p_DataReassembly->s_buffer = NULL ;
                  p_DataReassembly->s_buffer_size = 0UL ;
                  v_ETH_IP_ControlObj.s_IPstats.s_packet_rx.s_dropped++ ;
                  break ;
            }
         }
      }
   }
}

te_CMN_FLAG_VALIDITY
ETH_IP_Manage_L_Check ( const ts_CMN_IOSP_BUFFER * const p_Data )
{
   const ts_ETH_IP_Header *   c_IPHeader_pt ;
   const tu_ETH_IPAddr *      c_myIPAddr_pt ;
   te_CMN_FLAG_VALIDITY       v_valid ;
   uint16_t                   v_value ;
#if (ETH_IP_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_start_time;
   CMN_SYSTEM_TIME_t    v_end_time;
#endif

   /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, address of ipAddress is indeed (tu_ETH_IPAddr*) */
   c_myIPAddr_pt = &v_ETH_DRV_EtherOwnAddr.s_IpAddress ;

   /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t */
   if ( p_Data->s_buffer_size < (uint32_t)( sizeof(ts_ETH_EthernetHeader) + sizeof(ts_ETH_IP_Header) ) )
   {
      v_valid = e_CMN_FLAG_NOT_VALID ;
   }
   else
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_17.4>: operation is safe, buffer is handled as a byte array, with shift over header */
      c_IPHeader_pt = (const ts_ETH_IP_Header *) ( p_Data->s_buffer + sizeof(ts_ETH_EthernetHeader) ) ;

      /* note as the checksum is in the ts_ETH_IP_Header structure and the checksum value is a complement of the compute one
       * so the computation of the all ts_ETH_IP_Header with the checksum should be equals to 0 is success */
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, buffer is handled as a half-word array */
#if (ETH_IP_TIME_CONF_ENABLE != 0 )
        LIBT_TIME_GET( &v_start_time );
#endif
#if (ETH_IP_CONF_ENABLE_CHK != 0 )
      v_value = ETH_IP_InCheckSum ( (uint16_t *) c_IPHeader_pt ,
      /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t */
                                    (uint32_t) sizeof(ts_ETH_IP_Header) ) ;
#else
      v_value = 0;
#endif
#if (ETH_IP_TIME_CONF_ENABLE != 0)
      LIBT_TIME_GET( &v_end_time );
      v_duration_ip_Manage_crc_time = v_end_time - v_start_time;
#endif
      /*TODO debug le CRC ici*/
      if ( ( c_myIPAddr_pt->u_IP != c_IPHeader_pt->s_DestinationAddress.u_IP ) ||
               ( v_value != (uint16_t)0 ) )
      {
         v_valid = e_CMN_FLAG_NOT_VALID ;
      }
      else
      {
         v_valid = e_CMN_FLAG_VALID ;
      }
   }

   return ( v_valid ) ;
}
