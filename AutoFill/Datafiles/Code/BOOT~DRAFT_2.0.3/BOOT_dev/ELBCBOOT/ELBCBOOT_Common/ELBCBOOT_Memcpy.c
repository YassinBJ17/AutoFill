#include "ELBCBOOT_Memcpy.h"

#define C_MASK_ALIGNED 0x3ul
#define C_MEMORY_LENGTH 4ul

/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   ELBCBOOT_Memcpy                                                                                       */
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

void ELBCBOOT_Memcpy(
   void * const Dest, /* %RELAX<SYNCHRONe_C_Code_8.18> This parameter is output */
   const void * const Src,
   const uint32_t N
)
{
   const uint8_t * pt_ByteSource;
   uint8_t * pt_ByteDestination;

   const uint32_t * pt_AlignedSource;
   uint32_t * pt_AlignedDestination;
   
   uint32_t v_iter1;
   uint32_t v_iter2;

   /* pt_AlignedSource and pt_AlignedDestination are used to move in memory by group of 4 bytes */
   /* {{RELAX<SYNCHRONe_C_Code_11.1> We copy the data regardless of the type so we need to convert to generic accessible bytes */
   pt_AlignedSource = (uint32_t *) Src;
   pt_AlignedDestination = (uint32_t *) Dest;
   /* }} RELAX<SYNCHRONe_C_Code_11.1> */


   /* If Src and Dest are aligned and N is more or equal than 4 bytes */
   /* then copy data by group of 4 bytes */
   /* >RELAX<SYNCHRONe_C_Code_11.1> need to use address as uint to check alignment */
   if (((((uint32_t) pt_AlignedDestination & C_MASK_ALIGNED) == 0ul) && (((uint32_t) pt_AlignedSource & C_MASK_ALIGNED) == 0ul)) && (N >= C_MEMORY_LENGTH))
   {
      for (v_iter1 = N; v_iter1 >= C_MEMORY_LENGTH; v_iter1 -= C_MEMORY_LENGTH)
      {
         *pt_AlignedDestination = *pt_AlignedSource;
         /* {{RELAX<SYNCHRONe_C_Code_17.4> In this function, we use the same input as 8bits and 32bits buffers for performance reasons */
         pt_AlignedDestination++;
         pt_AlignedSource++;
         /* }} RELAX<SYNCHRONe_C_Code_17.4> */
      }
   }
   /* Otherwise, initialize the iterator v_iter1 for the byte per byte copy */
   else
   {
      v_iter1 = N;
   }

   /* {{RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> */
   /* Warns us because destination pointer could be use to address values with different alignment than source */
   /* This is exactly what we want to do here */
   pt_ByteSource = (uint8_t *) pt_AlignedSource;
   pt_ByteDestination = (uint8_t *) pt_AlignedDestination;
   /* }} RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> */

   /* Once the most possible of 4 bytes moves have been performed, */
   /* move every byte */
   for (v_iter2 = v_iter1; v_iter2 > 0ul; v_iter2--)
   {
      *pt_ByteDestination = *pt_ByteSource;
      /* {{RELAX<SYNCHRONe_C_Code_17.4> In this function, we use the same input as 8bits and 32bits buffers for performance reasons */
      pt_ByteDestination++;
      pt_ByteSource++;
      /* }} RELAX<SYNCHRONe_C_Code_17.4> */
   }
}