/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LOGBOOK_PUBLIC_H
#define LOGBOOK_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Start address in the MRAM of the registered logbook */
#define REGISTERED_LGBK_START_ADDR     ((uint32_t)0x20004A00)
/* Offset between two logs in the registered logbook */
#define REGISTERED_LGBK_OFFSET_ADDR    ((uint32_t)sizeof(ts_registered_lgbk))
/* Number of function which uses the logbook */
#define FUNCTION_NB                    ((uint32_t)120)

/* Logs IDs */
#define INIT_LOG_ID                    ((uint32_t)1)
#define PTF_LOG_ID                     ((uint32_t)2)

/* Value used for speeds in the preblue label */
#define SPEED_PREBLUE_VALUE            ((uint32_t)0xCAFEDECA)

/* Calculator mode */
#define CALC_OPERATIONAL_MODE          ((uint32_t)0x000000B0)

/* ---------- provided types: ----------------------------------------------- */
/* Event block definition */
typedef struct
{
   uint32_t s_id;                   /* Log ID */

   uint32_t s_flt_wrd_calc_mode;    /* Fault word or calculator mode */

   uint32_t s_timestamp;            /* Time of event */
   uint32_t s_pwr_up_counter;       /* Power-up counter of the platform */

   uint32_t s_exc_context_spare;    /* Exception context or spare */

   uint32_t s_raw_data_1;           /* Part 1 of the raw data */
   uint32_t s_raw_data_2;           /* Part 2 of the raw data */
   uint32_t s_raw_data_3;           /* Part 3 of the raw data */
   uint32_t s_raw_data_4;           /* Part 4 of the raw data */

   uint32_t s_accom_info;           /* Accomodation information */

   uint32_t s_temp_calc_pn;         /* Internal and external temperatures or calculator part number */
   uint32_t s_speed_calc_sn;        /* NGOS and NGALT speeds or calculator serial number */

   uint32_t s_mission_id;           /* Identifier of the mission */
}
ts_event_block;

/* Temperature stream log definition */
typedef struct
{
   uint32_t s_mission_id;        /* Identifier of the mission */

   uint32_t s_timestamp;         /* Time of event */
   uint32_t s_pwr_up_counter;    /* Power-up counter of the platform */

   uint32_t s_t1t2;        /* Filtered control unit temperature and filtered processing core die temperature */
   uint32_t s_t3t4;        /* Filtered accommodation temperature and filtered primary power supply temperature */
   uint32_t s_t5t6;        /* Filtered over speed high side temperature and filtered over speed low side temperature */
   uint32_t s_t7t8;        /* Filtered cold junction temperature and filtered engine control unit average temperature */

   uint32_t s_spare_1;           /* Spare (set to 0) */
   uint32_t s_spare_2;           /* Spare (set to 0) */
   uint32_t s_spare_3;           /* Spare (set to 0) */
   uint32_t s_spare_4;           /* Spare (set to 0) */
}
ts_temp_stream_log;

/* Registered log definition */
typedef struct
{
   /* First log in the current mission */
   ts_event_block s_first_log;

   /* Last log in the current mission */
   ts_event_block s_last_log;

   /* Counter of the event occurrences */
   uint32_t       s_long_occurrence_counter;
}
ts_registered_lgbk;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Initialize the variables used for logbook */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0010 */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0030 */
void logbook_init(void);

void logbook_pbit_fatal(const uint32_t p_last_addr, const uint32_t p_last_data);

/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0030 */
void logbook_pbit_logs(void);

/* Create trigger logs when a function short occurrence counter has reached the CSS_PU trigger value */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0030 */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic(const boolean_t p_channel_is_a);

/* Fill the event block with logbook data */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0010 */
void logbook_fill_event_block(ts_event_block * const p_event_block, const uint32_t p_id,
                              const uint32_t p_flt_wrd_calc_mode, const uint32_t p_exc_context_spare,
                              const uint32_t p_raw_data_1, const uint32_t p_raw_data_2,
                              const uint32_t p_raw_data_3, const uint32_t p_raw_data_4,
                              const uint32_t p_temp_calc_pn, const uint32_t p_speed_calc_sn);

/* Save a new event in the registered logbook and in the critical logbook */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0010 */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0020 */
void logbook_save_log(const ts_event_block * const p_event_block);

/* Read the oldest critical log and return TRUE if a log has been read, FALSE otherwise */
boolean_t logbook_read_oldest_critical_log(ts_event_block * const p_event_block);

/* Read the oldest trigger log and return TRUE if a log has been read, FALSE otherwise */
boolean_t logbook_read_oldest_trigger_log(ts_event_block * const p_trigger_log);

/* Create a temperature stream log */
void logbook_fill_temp_stream_log(ts_temp_stream_log * const p_temp_stream_log, const boolean_t p_channel_is_a);

#endif /* LOGBOOK_PUBLIC_H */
