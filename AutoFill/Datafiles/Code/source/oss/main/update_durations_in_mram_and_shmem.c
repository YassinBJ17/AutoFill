/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "libtools/time/LIB_TIME_public.h"

int64_t update_durations_in_mram_and_shmem(int64_t * function_duration_shmem,
                                           int64_t * function_duration_max_mram,
                                           int64_t current_time_previous)
{
   int64_t current_time;

   /* Get the current time */
   LIBT_TIME_GET(&current_time);

   /* Compute the elapsed time in this function */
   *function_duration_shmem = (int64_t)(current_time - current_time_previous);
   if (*function_duration_shmem > *function_duration_max_mram)
   {
      *function_duration_max_mram = *function_duration_shmem;
   }
   return current_time;
}
