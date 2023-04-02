/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .v_c file
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
/* LPOS Common Interface */
#include "LIB_MEM_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */

/* */
/* >RELAX<SYNCHRONe_C_Code_22.4> the function is simple : memory set. In order to have a optimise CPU code, some code has been directly implemented instead to call a function. */
void LIB_MEM_SET ( int8_t * const p_buffer ,
                   int8_t const p_init_value ,
                   uint32_t const p_length ) /* p_length in byte */
{
   register uint32_t v_temp ;
   register uint32_t v_c ;
   register int8_t * pt_dst ;
   register uint32_t v_size ;

   pt_dst = p_buffer ;
   v_size = p_length ;

   /*
    * If not enough words, just fill bytes.  A p_length >= 2 words
    * guarantees that at least one of them is `complete' after
    * any necessary alignment.  For instance:
    *
    * |-----------|-----------|-----------|
    * |00|01|02|03|04|05|06|07|08|09|0A|00|
    *           ^---------------------^
    */
   /* >RELAX<SYNCHRONe_C_Code_7.2> use a minimum of 3 here since the overhead of the code to do word writes is substantial. */
   if ( v_size < ( 3ul * sizeof(uint32_t) ) )
   {
      while ( v_size != 0ul )
      {
         *pt_dst = p_init_value ;
         /* >RELAX<SYNCHRONe_C_Code_17.4> pt_dst is a pointer on a memory area. Length is control, so the Pointer arithmetic can be used. */
         pt_dst++ ;
         v_size-- ;
      }
   }
   else
   {

      /* Align destination by filling in bytes. */
      /* >RELAX<SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_10.7> Pointer arithmetic operation in order to retrieve the number of bytes in order to align on 4 bytes */
      v_temp = ( (uint32_t) pt_dst ) & ( sizeof(uint32_t) - 1ul ) ;
      if ( v_temp != 0ul )
      {
         v_temp = sizeof(uint32_t) - v_temp ;
         v_size -= v_temp ;

         do
         {
            *pt_dst = p_init_value ;
            /* >RELAX<SYNCHRONe_C_Code_17.4> the pt_dst is a pointer on a memory area. Length is control, so the Pointer arithmetic can be used. */
            pt_dst++ ;
            v_temp --;
         }
         while ( v_temp  != 0ul );
      }

      /* >RELAX<SYNCHRONe_C_Code_10.7> :  the signed value is useless as the hexadecimal value will be duplicated in all byte of the v_c word.  */
      v_c = (uint32_t)p_init_value ;
      if ( v_c != 0ul )
      {
         /* Fill the word. */
         /* {{RELAX<SYNCHRONe_C_Code_7.2> 8 and 16 correspond to the offset for setting a byte in a 4 bytes word. */
         v_c = ( v_c << 8ul ) | v_c ;
         v_c = ( v_c << 16ul ) | v_c ;
         /* }}<SYNCHRONe_C_Code_7.2> */

      }

      /* for asm optimization */
      {
         uint32_t v_nb_blocks_32 ;

         /* {{RELAX<SYNCHRONe_C_Code_7.2> 32 corresponds to the number bytes that manages the assembly multi-word (stmw) instruction (see LIB_MEM_SET32)  */
         v_nb_blocks_32 = v_size / 32ul ;
         if ( v_nb_blocks_32 != 0ul )
         {
            LIB_MEM_SET32 ( pt_dst ,
                            v_c ,
                            v_nb_blocks_32 ) ;
         }
         v_size -= v_nb_blocks_32 * 32ul ;
         /* >RELAX<SYNCHRONe_C_Code_17.4, SYNCHRONe_C_Code_10.7> the pt_dst is a pointer on a memory area. Length is control, so the Pointer arithmetic can be used. */
         pt_dst += v_nb_blocks_32 * 32ul ;
         /* }}<SYNCHRONe_C_Code_7.2> */
      }
      /* end asm optimization */

      /* Fill words.  v_size was >= 2*words so we know v_t >= 1 here. */
      v_temp = v_size / sizeof(uint32_t) ;
      if ( v_temp != 0ul )
      {
         do
         {
            /* >RELAX<SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_10.7> Cast is indeed here : the copy is done 4 by 4 bytes. */
            *(uint32_t *) pt_dst = v_c ;
            /* >RELAX<SYNCHRONe_C_Code_17.4, SYNCHRONe_C_Code_10.7> the pt_dst is a pointer on a memory area. Length is control, so the Pointer arithmetic can be used. */
            pt_dst += sizeof(uint32_t) ;
            v_temp --;
         }
         while ( v_temp != 0ul ) ;
      }

      /* Mop up trailing bytes, if any. */
      v_temp = v_size & ( sizeof(uint32_t) - 1ul ) ;
      if ( v_temp != 0ul )
      {
         do
         {
            *pt_dst = p_init_value ;
            /* >RELAX<SYNCHRONe_C_Code_17.4> the pt_dst is a pointer on a memory area. Length is control, so the Pointer arithmetic can be used. */
            pt_dst++;
            v_temp --;
         }
         while ( v_temp != 0ul ) ;
      }
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
