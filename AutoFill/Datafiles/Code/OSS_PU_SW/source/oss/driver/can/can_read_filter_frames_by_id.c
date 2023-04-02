/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * --------------------------------------------------------------------------
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "memory/shared_memory_public.h"
#include "libtools/memory/LIB_MEM_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_FADEX_OS_SRD-CAN-0030 */
void can_read_filter_frames_by_id(ts_can_frame * const can_frame_rx_tab,
                                  ts_can_rx    * const ptr_dest_shmem_can,
                                  uint32_t       const nb_read_data,
                                  uint32_t     * const rx_count)
{
   /* Initialize loop */
   uint32_t copy_postponed;
   uint32_t id_rx_tab;
   uint32_t i;
   uint32_t local_rx_count;

   id_rx_tab      = (uint32_t)0;
   local_rx_count = (uint32_t)0;

   /* the table with all the frames received will be filtered, if more than one frame have the same id it will keep */
   /* the more recent one (last recived) */
   while( id_rx_tab < nb_read_data )
   {
      copy_postponed = (uint32_t)0 ;
      /* one id frame is selected and its id is compard with the other frames in the table */
      for (i=id_rx_tab+(uint32_t)1;i<nb_read_data;i++)
      {
         if (can_frame_rx_tab[id_rx_tab].s_identifier == can_frame_rx_tab[i].s_identifier)
         {
            /* if the id matches = a more recent frame has the same id so the selected frame is no copied */
            copy_postponed = (uint32_t)1 ;
         }
      }
      /* if not the frame is copied in shmem */
      if (copy_postponed == (uint32_t)0)
      {
         /* Put the frame id */
         ptr_dest_shmem_can->s_frames[local_rx_count].s_identifier = can_frame_rx_tab[id_rx_tab].s_identifier;

         /* put the frame size */
         ptr_dest_shmem_can->s_frames[local_rx_count].s_length = can_frame_rx_tab[id_rx_tab].s_length;

         /* Copy data from RAM to SHMEM */
         LIB_MEM_CPY( (int8_t*)&(ptr_dest_shmem_can->s_frames[local_rx_count].s_data[0]),
                      (int8_t*)&(can_frame_rx_tab[id_rx_tab].s_data[0]),
                      (uint32_t)8);

         local_rx_count++;
      }

      id_rx_tab++;

   }
   *rx_count = local_rx_count;

}



/* ---------- internal operation bodies: ------------------------------------ */
