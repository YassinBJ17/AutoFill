/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS_MOCKUP
 * CSU name :
 * %name: BOOT_LIBMEM_SET_code.c %
 * %full_name: fadex#1/csrc/BOOT_LIBMEM_SET_code.c/1 %
 * DESCRIPTION : short description of the operations of the .c file
 *
 * Creation information:
 *   Created by: F554337
 *   Date : Thu Mar 11 10:51:50 CET 2021
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Tue Nov 16 14:50:14 CET 2021 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
/* ---------- include provided interface: ----------------------------------- */
/* LPOS Common Interface */

#include "BOOT_LIBMEM_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
/* none */
/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */
/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */

/* */
void BOOT_LIBMEM_SET( uint8_t const * p_buffer_pt,
                      uint32_t  const p_init_value,
                      uint32_t const p_length)
{
   uint32_t t;
   uint32_t c;
   uint8_t * dst;
   uint32_t size;
   uint8_t init_value8;

   dst = (uint8_t *) p_buffer_pt;
   size = (uint32_t) p_length;
   init_value8 = (uint8_t) p_init_value;

   /*
    * If not enough words, just fill bytes.  A length >= 2 words
    * guarantees that at least one of them is `complete' after
    * any necessary alignment.  For instance:
    *
    * |-----------|-----------|-----------|
    * |00|01|02|03|04|05|06|07|08|09|0A|00|
    *           ^---------------------^
    *     dst      dst+length-1
    *
    * but we use a minimum of 3 here since the overhead of the code
    * to do word writes is substantial.
    */
   if ( size < ( 3 * sizeof(uint32_t) ) )
   {
      do
      {
         *dst++ = init_value8;
      }
      while( (--size) != 0 );

      return;
   }

   /* Align destination by filling in bytes. */
   t = (uint32_t)dst & ( sizeof(uint32_t) - 1 );
   if ( t != 0 )
   {
      t = sizeof(uint32_t) - t;
      size -= t;
      do
      {
         *dst++ = init_value8;
      }
      while ( (--t) != 0 );
   }

   c = init_value8;
   if ( c != 0 )
   {
      /* Fill the word. */
      c = (c << 8) | c;
      c = (c << 16) | c;
   }

   /* for asm optimization */
   {
      int nb_blocks_32;

      nb_blocks_32 = size / 32;
      if ( nb_blocks_32 != 0 )
      {
         BOOT_LIBMEM_SET32( dst, c, nb_blocks_32 * 32 );
      }
      size -= nb_blocks_32 * 32;
      dst += nb_blocks_32 * 32;
   }
   /* end asm optimization */

   /* Fill words.  size was >= 2*words so we know t >= 1 here. */
   t = size / sizeof(uint32_t);
   if ( t != 0 )
   {
      do
      {
         *(uint32_t *)dst = c;
         dst += sizeof(uint32_t);
      }
      while ( (--t) != 0 );
   }

   /* Mop up trailing bytes, if any. */
   t = size & (sizeof(uint32_t) - 1);
   if ( t != 0 )
   {
      do
      {
         *dst++ = init_value8;
      }
      while ( (--t) != 0 );
   }
   return;
}


/* ---------- internal operation bodies: ------------------------------------ */
/* none */