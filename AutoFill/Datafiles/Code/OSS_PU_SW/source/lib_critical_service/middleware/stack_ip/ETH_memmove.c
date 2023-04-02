#include "middleware/stack_ip/ETH_COMM_public.h"
#include "middleware/stack_ip/ETH_UDP_public.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "type/common_type.h"

 void * ETH_memmove ( void *dest, const void *src, uint32_t len ) {   uint8_t *d = dest;   const uint8_t *s = src;   if (d < s)     while (len--)       *d++ = *s++;   else     {       const uint8_t *lasts = s + (len-1);       uint8_t *lastd = d + (len-1);       while (len--)         *lastd-- = *lasts--;     }   return dest; }
