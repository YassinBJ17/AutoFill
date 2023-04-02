/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : Memcpy                                                                                                 */
/* FILENAME : Memcpy.c                                                                                               */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "Memcpy.h"


#define C_MASK_ALIGNED 0x3UL

/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   LibC_Memcpy                                                                                           */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function copies data from Src to Dest                                                           */
/*                                                                                                                   */
/* Pre-condition: The memory area starting at address Src and of size N bytes shall be valid for reading             */
/*                The memory area starting at address Dest and of size N bytes shall be valid for writing            */
/*                These two memory areas shall not overlap                                                           */
/*                N shall be higher than 0                                                                           */
/*                                                                                                                   */
/* Input:  Dest : Destination buffer in which the data is copied                                                     */
/*         Src  : Source buffer from which the data is copied                                                        */
/*         N    : number of bytes to copy                                                                            */
/* Output: none                                                                                                      */
/* Return: none                                                                                                      */
/*-------------------------------------------------------------------------------------------------------------------*/
void LibC_Memcpy(const void * const Dest, const void * const Src, const t_uint_32 N)
{

   const t_uint_8 * pByteSource;
   t_uint_8 * pByteDestination;

   const t_uint_32 * pAlignedSource;
   t_uint_32 * pAlignedDestination;
   
   const t_uint_32 C_MEMORY_LENGTH = 4UL;
   t_uint_32 iter1;
   t_uint_32 iter2;

   /* pAlignedSource and pAlignedDestination are used to move in memory by group of 4 bytes */
   pAlignedSource = (t_uint_32 *) Src;
   pAlignedDestination = (t_uint_32 *) Dest;


   /* If Src and Dest are aligned and N is more or equal than 4 bytes */
   /* then copy data by group of 4 bytes */
   if (((((t_uint_32) pAlignedDestination & C_MASK_ALIGNED) == 0UL) && (((t_uint_32) pAlignedSource & C_MASK_ALIGNED) == 0UL)) && (N >= C_MEMORY_LENGTH))
   {
      for (iter1 = N; iter1 >= C_MEMORY_LENGTH; iter1 -= C_MEMORY_LENGTH)
      {
         *pAlignedDestination = *pAlignedSource;
         pAlignedDestination++;
         pAlignedSource++;
      }
   }
   /* Otherwise, initialize the iterator iter1 for the byte per byte copy */
   else
   {
      iter1 = N;
   }

   
   pByteSource = (t_uint_8 *) pAlignedSource;
   pByteDestination = (t_uint_8 *) pAlignedDestination;


   /* Once, the most possible of 4 bytes moves have been performed, */
   /* move every byte */
   for (iter2 = iter1; iter2 > 0UL; iter2--)
   {
      *pByteDestination = *pByteSource;
      pByteDestination++;
      pByteSource++;
   }
}
