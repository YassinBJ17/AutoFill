/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : move data from one adresse to another
 * -------------------------------------------------------------------------- */
/* ---------- include provided interface: ----------------------------------- */
#include "libtools/memory/LIB_MEM_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void LIB_MEM_MOVE( int8_t * const p_destination ,
                   int8_t const * const p_source ,
                   uint32_t const p_length ) /* p_length in byte */
{
   /* */
   int8_t *       pt_dst;
   const int8_t * c_src;
   uint32_t     v_size;

   pt_dst = p_destination;
   c_src = p_source;
   v_size = p_length;

   /* {{RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_17.4> c_src and pt_dst pointer address are coded on 32 bits (unsigned), and are memory pointer. */
   /* {{RELAX<SYNCHRONe_C_Code_11.1> Comparison pointer wanted */
   if ( ( ((uint32_t) c_src) < ((uint32_t)pt_dst) ) &&
        ( ((uint32_t)pt_dst) < ( ((uint32_t)c_src) + p_length ) )
   )
   /* }}<SYNCHRONe_C_Code_11.1> */
   {
      /* Destructive overlap...have to copy backwards */
      /* {{RELAX<SYNCHRONe_C_Code_10.2> incrementing the pointer array. Not a Implicit cast .  */
      c_src +=  p_length;
      pt_dst +=  p_length ;
      /* }}<SYNCHRONe_C_Code_10.2> */
      while ( v_size != 0x0ul )
      {
         pt_dst--;
         c_src--;
         *pt_dst = *c_src;
         v_size--;
      }
   }
   else
   {
      LIB_MEM_CPY ( p_destination, p_source, p_length );
   }
   /* }}<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_17.4> */
}

/* ---------- internal operation bodies: ------------------------------------ */
