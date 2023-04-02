/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/icdl/ICDL_LG_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void ICDL_LG_ComputeMsgArgSet( int8_t * const p_buff_addr , uint32_t const p_buff_size, t_command *p_command_ptr )
{
   int8_t * pt_buff;
   int8_t * pt_msg;
   uint32_t v_buff_size;

   pt_buff = (int8_t *)((uint32_t)p_command_ptr->udpBuffer.s_buffer + K_ARG_SET_BUFFER_IDX );

   pt_msg = (int8_t *)(p_buff_addr);
   v_buff_size = (int32_t)p_buff_size;

   LIB_MEM_CPY ( pt_buff,
                 pt_msg ,
                 v_buff_size );
}

/* ---------- internal operation bodies: ------------------------------------ */
