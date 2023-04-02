/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_UDP_common.h"
#include "middleware/stack_ip/ETH_IP_common.h"


/*---------------------------------------------------------------------------*/
/* NAME: ETH_DRV_UdpChecksum()*/
/*---------------------------------------------------------------------------*/
/* PURPOSE:  compute the UDP (or TCP) header checksum.*/
/**/
/* From rfc768:*/
/* Checksum is the 16-bit one's complement of the one's complement sum of a*/
/* pseudo header of information from the IP header, the UDP header, and the*/
/* data,  padded  with zero octets  at the end (if  necessary)  to  make  a*/
/* multiple of two octets.*/
/**/
/* The pseudo  header  conceptually prefixed to the UDP header contains the*/
/* source  address,  the destination  address,  the protocol,  and the  UDP*/
/* length.   This information gives protection against misrouted datagrams.*/
/* This checksum procedure is the same as is used in TCP.*/
/**/
/*                   0      7 8     15 16    23 24    31*/
/*                  +--------+--------+--------+--------+*/
/*                  |          source address           |*/
/*                  +--------+--------+--------+--------+*/
/*                  |        destination address        |*/
/*                  +--------+--------+--------+--------+*/
/*                  |  zero  |protocol|   UDP length    |*/
/*                  +--------+--------+--------+--------+*/
/**/
/* If the computed  checksum  is zero,  it is transmitted  as all ones (the*/
/* equivalent  in one's complement  arithmetic).   An all zero  transmitted*/
/* checksum value means that the transmitter generated  no checksum  (for*/
/* debugging or for higher level protocols that don't care).*/
/*---------------------------------------------------------------------------*/
/* INPUTS/OUTPUTS: See function declaration*/
/*---------------------------------------------------------------------------*/
/* ASSUMPTIONS/LIMITATIONS: UDP_Length is less than the MAX packet size*/
/* when the Length is an odd number of bytes.*/
/*---------------------------------------------------------------------------*/
uint16_t ETH_UDP_Checksum( const tu_ETH_IPAddr *            const p_src,
                           const tu_ETH_IPAddr *            const p_dest,
                           const ts_ETH_UDP_PacketHeader *  const p_packet ,
                           const ts_CMN_IOSP_BUFFER *       const p_data )
{
   uint32_t          v_i;
   /* {{RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t */
   const uint32_t    c_size1 = ((uint32_t)sizeof(ts_ETH_UDP_Header)) / ((uint32_t)sizeof(uint16_t));
   const uint32_t    c_size2 = p_data->s_buffer_size / ((uint32_t)sizeof(uint16_t));
   /* }}RELAX<SYNCHRONe_C_Code_10.7> */
   tu_u32u16         v_UDPChecksum;
   tu_u32u16         v_UDPChecksum_l;
   const uint16_t*   c_DataPtr;

   /* Initialize local variables */
   v_UDPChecksum.u_u32 = 0ul;

   /* add pseudo header */
   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, buffer is handled as a half-word array */
   c_DataPtr = (const  uint16_t *)p_src ;
   v_UDPChecksum.u_u32 += (uint32_t)(* c_DataPtr) ;
   /* >RELAX<SYNCHRONe_C_Code_17.4>: Operation is safe, it's the same as c_DataPtr[1] */
   v_UDPChecksum.u_u32 += (uint32_t)(* (c_DataPtr+1)) ;

   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, buffer is handled as a half-word array */
   c_DataPtr = (const  uint16_t *)p_dest ;
   v_UDPChecksum.u_u32 += (uint32_t)(* c_DataPtr) ;
   /* >RELAX<SYNCHRONe_C_Code_17.4>: Operation is safe, it's the same as c_DataPtr[1] */
   v_UDPChecksum.u_u32 += (uint32_t)(* (c_DataPtr+1)) ;

   /* checksum for the UDP header */
   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, buffer is handled as a half-word array */
   c_DataPtr = (const uint16_t*) & (p_packet->s_UDP_Header) ;
   for ( v_i = 0UL ; v_i < c_size1 ; v_i++)
   {
      /* >RELAX<SYNCHRONe_C_Code_17.4>: Operation is safe, it's an array indexing */
      v_UDPChecksum.u_u32  += (uint32_t)c_DataPtr[ v_i ];
   }

   /* checksum for the UDP header */
   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, it's needed because buffer is a byte array */
   c_DataPtr = (const uint16_t*) p_data->s_buffer ;
   for ( v_i = 0UL ; v_i < c_size2 ; v_i++)
   {
      /* >RELAX<SYNCHRONe_C_Code_17.4>: Operation is safe, it's an array indexing */
      v_UDPChecksum.u_u32  += (uint32_t)c_DataPtr[ v_i ];
   }

   /* remove checksum */
   /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, uint16_t fits on an uint32_t */
   v_UDPChecksum.u_u32 -= (uint32_t)p_packet->s_UDP_Header.s_UDP_Checksum ;
   /* adding the protocol and the length */
   /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, this enum fits on an uint32_t */
   v_UDPChecksum.u_u32 += (uint32_t)e_ETH_IP_PROTO_UDP ;
   /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, uint16_t fits on an uint32_t */
   v_UDPChecksum.u_u32 += (uint32_t)p_packet->s_UDP_Header.s_UDP_Length ; /* adding a 2nd time UDP packet length */

   /* add carry and cast to uint 16 */
   /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, uint16_t fits on an uint32_t */
   v_UDPChecksum_l.u_u32 = (uint32_t)v_UDPChecksum.u_u16.s_msb + (uint32_t)v_UDPChecksum.u_u16.s_lsb;
   /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, uint16_t fits on an uint32_t */
   v_UDPChecksum_l.u_u32 = v_UDPChecksum_l.u_u32 + (uint32_t)v_UDPChecksum_l.u_u16.s_msb;
   /* checksum is the one's complement of the sum but should be sent as 0xFFFF if equal to 0x0000 */
   /* >RELAX<SYNCHRONe_C_Code_7.2,SYNCHRONe_C_Code_10.7>: we test the 16 bits LSB, literal and cast are safe */
   if (v_UDPChecksum_l.u_u16.s_lsb != (uint16_t)0xFFFF)
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, the complement of an uint32_t obviously fits on an uint32_t */
      v_UDPChecksum_l.u_u32 = ~(v_UDPChecksum_l.u_u32);
   }

   return (v_UDPChecksum_l.u_u16.s_lsb);
}
