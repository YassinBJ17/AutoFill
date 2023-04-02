/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : compare two adresses and return an index where a difference is found
 * -------------------------------------------------------------------------- */
/* ---------- include provided interface: ----------------------------------- */
#include "libtools/memory/LIB_MEM_public.h"
#include "type/common_type.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
int32_t LIB_MEM_CMP( int8_t const * const p_mem1,
                     int8_t const * const p_mem2,
                     uint32_t const p_length )
{
   /* */
   te_CMN_FLAG_RUN v_run_loop;
   uint32_t v_len;
   int32_t v_cmp;

   /* */
   v_run_loop = e_CMN_FLAG_RUN;
   v_len = 0ul;
   v_cmp = 0l;

   /* Simple, byte oriented memcmp */
   while ( ( v_len < p_length ) && (v_run_loop != e_CMN_FLAG_STOP) )
   {
      /* */
      /* >RELAX<SYNCHRONe_C_Code_17.4> p_mem1 and p_mem2 are array pointer (aim of the function) */
      v_cmp = ( int32_t ) (p_mem1[v_len]) - ( int32_t ) (p_mem2[v_len]);

      if (v_cmp == 0l )
      {
         v_len++;
      }
      else
      {
         v_run_loop = e_CMN_FLAG_STOP;
      }
   }

   return v_cmp;
}

/* ---------- internal operation bodies: ------------------------------------ */
