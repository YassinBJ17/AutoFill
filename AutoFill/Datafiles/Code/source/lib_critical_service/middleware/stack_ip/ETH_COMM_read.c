/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/stack_ip/ETH_COMM_public.h"
#include "middleware/stack_ip/ETH_UDP_public.h"

#include "libtools/memory/LIB_MEM_public.h"
#include "type/common_type.h"

void * ETH_memmove ( void *dest, const void *src, uint32_t len );

/* ---------- function bodies: ---------------------------------------------- */

/*!@brief Read data from the communication link.
 *
 * @param[out] in_msg        Buffer where are copied the data coming from the communication link
 * @param[in]  nb_bytes      Maximum number of bytes to read
 * @param[out] nb_bytes_read Number of bytes that were actually read
 * @return The status of the read operation
 */
t_eth_comm_status ETH_COMM_read( uint8_t *in_msg,
                                 uint32_t nb_bytes,
                                 uint16_t *nb_bytes_read,
                                 uint16_t *p_port_dst,
                                 uint32_t *p_ip_dst,
                                 int8_t *in_buffer )
{
   int8_t *     pt_msg;
   int16_t *    pt_size;
   uint32_t *   pt_ip;
   uint16_t *   pt_udp;

   pt_size = (int16_t *)((uint32_t)(in_buffer) + (uint32_t)38);
   pt_ip = (uint32_t *)((uint32_t)(in_buffer) + (uint32_t)26);
   pt_udp = (uint16_t *)((uint32_t)(in_buffer) + (uint32_t)34);

   if( *pt_size >= UDP_HEADER_SIZE )
   {
      *nb_bytes_read = (uint16_t)(*pt_size - UDP_HEADER_SIZE);

      pt_msg = (int8_t *)( (uint32_t)(in_buffer) + (uint32_t)ETH_UDP_IP_SIZE );

      if ( (uint8_t*)in_buffer == in_msg )
      {
         /* port buffer and des buffer are the same */
         ETH_memmove( in_msg, pt_msg, *pt_size );
         *p_port_dst = *pt_udp;
         *p_ip_dst = *pt_ip;
      }
      else
      {
         /* TODO Confirmer en integration *pt_size - UDP_HEADER_SIZE dans la copie */
         LIB_MEM_CPY ( (int8_t* const) in_msg ,
                        pt_msg ,
                        *pt_size );
         *p_port_dst = *pt_udp;
         *p_ip_dst = *pt_ip;
         /* TODO perfo : mise a 0 de la taille seulement */
         LIB_MEM_SET( (int8_t* const)(in_buffer),
                      (int8_t const)0,
                      (uint32_t const)(ETH_UDP_IP_SIZE + *pt_size) );
      }
   }
   else
   {
      *nb_bytes_read = 0;
   }

   return ( ETH_COMM_STATUS_OK );
}



void * ETH_memmove ( void *dest, const void *src, uint32_t len )
{
  uint8_t *d = dest;
  const uint8_t *s = src;
  if (d < s)
    while (len--)
      *d++ = *s++;
  else
    {
      const uint8_t *lasts = s + (len-1);
      uint8_t *lastd = d + (len-1);
      while (len--)
        *lastd-- = *lasts--;
    }
  return dest;
}
