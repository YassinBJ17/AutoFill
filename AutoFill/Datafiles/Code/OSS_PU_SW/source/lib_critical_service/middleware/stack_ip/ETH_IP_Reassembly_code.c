/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_IP_private.h"
#include "middleware/ethernet/ETH_porting.h"
#include "libtools/memory/LIB_MEM_public.h"

#define K_ETH_IP_SEC_TO_NS (1000ul* 1000ul * 1000ul )

te_CMN_FLAG_VALIDITY ETH_IP_Reassembly_L_Check( const ts_ETH_IP_PacketHeader * const p_DataHeader ) ;

void ETH_IP_Reassembly_L_CheckTimeOut(void);

void ETH_IP_Reassembly (  const ts_CMN_IOSP_BUFFER * const p_Data,
                                uint32_t const p_offSetFragment,
                                uint32_t const p_flagFragment,
                                te_CMN_FLAG_VALIDITY* const p_validData )
{
   const ts_ETH_IP_PacketHeader *   c_IPHeader_pt ;
   uint32_t                         v_lastCellIndex;
   uint32_t                         v_DataLen ;
   uint32_t                         v_offset ;

   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, buffer is handled as a byte array */
   c_IPHeader_pt = (const ts_ETH_IP_PacketHeader *)(p_Data->s_buffer );

   ETH_IP_Reassembly_L_CheckTimeOut();

   /* first Fragmentation */
   if (p_offSetFragment == 0UL)
   {
      if(  v_ETH_IP_ControlObj.s_RxFragment.s_IPFRx_status != e_ETH_IP_FRGMT_IN_PROG )
      {
         /* set fragment */
/*
* MBX discard from Ethernet frame size the FCS
*/
#if (ETH_FEC != 0 )
         LIB_MEM_CPY( v_ETH_IP_ControlObj.s_RxFragment.s_Packetbuff,
                      p_Data->s_buffer,
                      p_Data->s_buffer_size - K_ETH_IP_FCS_SIZE);
#else
         LIB_MEM_CPY( v_ETH_IP_ControlObj.s_RxFragment.s_Packetbuff,
                               p_Data->s_buffer,
                               p_Data->s_buffer_size);
#endif

         v_ETH_IP_ControlObj.s_RxFragment.s_IPFRx_status = e_ETH_IP_FRGMT_IN_PROG ;

/*
* MBX discard from Ethernet frame size the FCS
*/
#if (ETH_FEC != 0 )
         v_ETH_IP_ControlObj.s_RxFragment.s_dataLen = p_Data->s_buffer_size - K_ETH_IP_FCS_SIZE ;
#else
         v_ETH_IP_ControlObj.s_RxFragment.s_dataLen = p_Data->s_buffer_size ;
#endif

         v_ETH_IP_ControlObj.s_RxFragment.s_chrono.s_ongoing = 0UL ;
         v_ETH_IP_ControlObj.s_RxFragment.s_chrono.s_end = (uint32_t)c_IPHeader_pt->s_IP_ip.s_IP_TimeToLive * (uint32_t)K_ETH_IP_SEC_TO_NS;
         LIBT_TIME_Update( &v_ETH_IP_ControlObj.s_RxFragment.s_chrono ) ;

         *p_validData = e_CMN_FLAG_VALID;
      }
      else
      {
         *p_validData = e_CMN_FLAG_NOT_VALID;
      }
   }
   else
   {
      if (  v_ETH_IP_ControlObj.s_RxFragment.s_IPFRx_status == e_ETH_IP_FRGMT_IN_PROG )
      {
         *p_validData = ETH_IP_Reassembly_L_Check( c_IPHeader_pt ) ;

         if (  *p_validData == e_CMN_FLAG_VALID )
         {
            /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t */
 /*
 * MBX discard from Ethernet frame size the FCS
 */
#if (ETH_FEC != 0 )
            v_DataLen =  p_Data->s_buffer_size - K_ETH_IP_FCS_SIZE - (uint32_t)sizeof(ts_ETH_IP_PacketHeader) ;
#else
            v_DataLen =  p_Data->s_buffer_size - (uint32_t)sizeof(ts_ETH_IP_PacketHeader) ;
#endif

            /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t */
            v_offset = p_offSetFragment + (uint32_t)sizeof(ts_ETH_IP_PacketHeader);
            v_lastCellIndex = p_offSetFragment + v_DataLen;

            if ( v_lastCellIndex > INTEG_ETH_IP_SIZE_MAX_DATA_EXCHANGE )
            {
               v_ETH_IP_ControlObj.s_RxFragment.s_IPFRx_status = e_ETH_IP_FRGMT_INVALID ;
            }
            else
            {
               /* >RELAX<SYNCHRONe_C_Code_17.4>: operation is safe, buffer shifted over header */
               LIB_MEM_CPY( (v_ETH_IP_ControlObj.s_RxFragment.s_Packetbuff + v_offset),
               /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_17.4>: operation is safe, buffer shifted over header */
                            (int8_t*) (p_Data->s_buffer + sizeof(ts_ETH_IP_PacketHeader) ),
                            v_DataLen );

               if ( v_lastCellIndex > v_ETH_IP_ControlObj.s_RxFragment.s_dataLen )
               {
                  v_ETH_IP_ControlObj.s_RxFragment.s_dataLen =  v_lastCellIndex ;
               }
            }

            /* fragmentation is finish */
            if (p_flagFragment == 0ul)
            {
               v_ETH_IP_ControlObj.s_RxFragment.s_IPFRx_status = e_ETH_IP_FRGMT_FINISH ;

               /* RJI A tester modif FFO */
               v_ETH_IP_ControlObj.s_RxFragment.s_dataLen = v_ETH_IP_ControlObj.s_RxFragment.s_dataLen + (uint32_t)sizeof(ts_ETH_IP_PacketHeader);
            }
         }
      }
      else
      {
         *p_validData = e_CMN_FLAG_NOT_VALID;
      }
   }
}


te_CMN_FLAG_VALIDITY ETH_IP_Reassembly_L_Check( const ts_ETH_IP_PacketHeader * const p_DataHeader )
{
   const ts_ETH_IP_PacketHeader *   c_PcktHeader_pt ;
   te_CMN_FLAG_VALIDITY             v_valid;
   te_CMN_FLAG_QUESTION             v_MACValid ;

   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, buffer is handled as a byte array */
   c_PcktHeader_pt = ( const ts_ETH_IP_PacketHeader *  ) v_ETH_IP_ControlObj.s_RxFragment.s_Packetbuff ;

   v_MACValid = ETH_DRV_IsSameMAC_ADDR( &p_DataHeader->s_IP_eth.s_SourceHost,
                                        &c_PcktHeader_pt->s_IP_eth.s_SourceHost );

   /* check Performed :
    * - Sender MAC and IP
    * - ID of the packet fragmented */

   if( (p_DataHeader->s_IP_ip.s_SourceAddress.u_IP ==  c_PcktHeader_pt->s_IP_ip.s_SourceAddress.u_IP ) &&
            (v_MACValid == e_CMN_FLAG_YES) &&
            (p_DataHeader->s_IP_ip.s_IP_Id ==  c_PcktHeader_pt->s_IP_ip.s_IP_Id )
       )
   {
      v_valid = e_CMN_FLAG_VALID ;
   }
   else
   {
      v_valid = e_CMN_FLAG_NOT_VALID ;
   }

   return v_valid ;
}

void ETH_IP_Reassembly_L_CheckTimeOut(void)
{
   ts_LIB_TIME_CHRONO * pt_chrono;


   if ( v_ETH_IP_ControlObj.s_RxFragment.s_IPFRx_status == e_ETH_IP_FRGMT_IN_PROG  )
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, address of s_chrono is indeed (ts_LIB_TIME_CHRONO *) */
      pt_chrono = &v_ETH_IP_ControlObj.s_RxFragment.s_chrono ;

      LIBT_TIME_Update( pt_chrono );

      if ( pt_chrono->s_ongoing >= pt_chrono->s_end )
      {
         v_ETH_IP_ControlObj.s_RxFragment.s_IPFRx_status = e_ETH_IP_FRGMT_TIMEOUT ;
      }
   }
}
