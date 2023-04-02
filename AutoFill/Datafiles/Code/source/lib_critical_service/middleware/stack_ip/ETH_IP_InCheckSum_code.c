/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_common.h"
#include "middleware/stack_ip/ETH_IP_common.h"



/*---------------------------------------------------------------------------*/
/* NAME: ETH_DRV_InCheckSum()*/
/*---------------------------------------------------------------------------*/
/* PURPOSE:  compute the IP/UDP checksum.*/
/**/
/* The checksum is computed by taking the 16-bit 1's complement*/
/* of the 1's complement sum of all the 16-bit words.*/
/**/
/* 1's complement sum is performed by summing the integers and adding*/
/* any carry bit to the result.  The computed checksum is returned.*/
/*---------------------------------------------------------------------------*/
/* INPUTS/OUTPUTS: See function declaration*/
/*---------------------------------------------------------------------------*/
/* ASSUMPTIONS/LIMITATIONS: None.*/
/*---------------------------------------------------------------------------*/
uint16_t ETH_IP_InCheckSum(uint16_t *p_Data, uint32_t p_Length)
{
   uint16_t    *pt_data;
   tu_u32u16   v_Sum;

   pt_data = p_Data;
   v_Sum.u_u32 = 0UL;

   /* sum all words in data*/
   while (p_Length > 1UL)
   {
      v_Sum.u_u32 += (uint32_t)(*pt_data);
      /* >RELAX<SYNCHRONe_C_Code_17.4>: operation is safe, the pointer is moved 2 bytes forward */
      pt_data++;
      /* >RELAX<SYNCHRONe_C_Code_7.2>: Literal is OK, 1 word = 2 half-words */
      p_Length -= 2UL;
   }

   /* add in the last byte if needed*/
   if (p_Length > 0ul )
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, we use pt_data as a byte array */
      v_Sum.u_u32 += (uint32_t)(*((uint8_t *)pt_data));
   }

   /* do the carries*/
   while (v_Sum.u_u16.s_msb != (uint16_t)0)
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, an uint16_t fits on an uint32_t */
      v_Sum.u_u32 = (uint32_t)v_Sum.u_u16.s_msb + (uint32_t)v_Sum.u_u16.s_lsb;
   }

   /* return ones complement of sum, in host order*/
   /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, the complement of an uint32_t obviously fits on an uint32_t */
   v_Sum.u_u32 = ~v_Sum.u_u32;
   return (v_Sum.u_u16.s_lsb);
}
