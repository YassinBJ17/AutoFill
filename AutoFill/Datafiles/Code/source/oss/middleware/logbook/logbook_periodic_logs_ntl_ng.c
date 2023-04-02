/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs_ntl_ng function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */

#include "middleware/tecu/tecu_public.h"
#include "middleware/ovsp/ovsp_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_ntl_ng(void)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* Unions used for every raw data [1:4] */
   tu_raw_data    raw_data_1;
   tu_raw_data    raw_data_3;

   /* NTL1OS */
   raw_data_1.u_float = shmem.s_ntlos1.s_measure;
   raw_data_3.u_float = shmem.s_ntlos2.s_measure;
   logbook_fill_event_block(&log, FCT_ID_NTLOS1, shmem.s_ntlos1.s_fault_word.u_word, exception_context,
                           raw_data_1.u_integer, ls_resp_frame_format_3.s_ntlos1_measure.int32_val, raw_data_3.u_integer,
                           ls_resp_frame_format_3.s_ntlos2_measure.int32_val, int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);

   /* NTL2OS */
   raw_data_1.u_float = shmem.s_ntlos1.s_measure;
   raw_data_3.u_float = shmem.s_ntlos2.s_measure;
   logbook_fill_event_block(&log, FCT_ID_NTLOS2, shmem.s_ntlos2.s_fault_word.u_word, exception_context,
                           raw_data_1.u_integer, ls_resp_frame_format_3.s_ntlos1_measure.int32_val, raw_data_3.u_integer,
                           ls_resp_frame_format_3.s_ntlos2_measure.int32_val, int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);

   /* NGOS1 */
   raw_data_1.u_float = shmem.s_ngos1.s_measure;
   raw_data_3.u_float = shmem.s_ngos2.s_measure;
   logbook_fill_event_block(&log, FCT_ID_NGOS1, shmem.s_ngos1.s_fault_word.u_word, exception_context,
                           raw_data_1.u_integer, ls_resp_frame_format_2.s_ngos1_measure.int32_val, raw_data_3.u_integer,
                           ls_resp_frame_format_2.s_ngos2_measure.int32_val, int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);

   /* NGOS2 */
   raw_data_1.u_float = shmem.s_ngos1.s_measure;
   raw_data_3.u_float = shmem.s_ngos2.s_measure;
   logbook_fill_event_block(&log, FCT_ID_NGOS2, shmem.s_ngos2.s_fault_word.u_word, exception_context,
                           raw_data_1.u_integer, ls_resp_frame_format_2.s_ngos1_measure.int32_val, raw_data_3.u_integer,
                           ls_resp_frame_format_2.s_ngos2_measure.int32_val, int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);
}

/* ---------- internal operations: ------------------------------------------ */
