/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LOGBOOK_PRIVATE_H
#define LOGBOOK_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "middleware/logbook/logbook_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Size of an event block */
#define EVENT_BLOCK_SIZE               ((uint32_t)sizeof(ts_event_block))

/* Start address in the MRAM of the critical logbook */
#define CRITICAL_LGBK_START_ADDR       ((uint32_t)0x20008A00)
/* Offset between two logs in the critical logbook */
#define CRITICAL_LGBK_OFFSET_ADDR      ((uint32_t)sizeof(ts_event_block))
/* Number of event blocks which can be saved in the critical logbook : 33,5Ko */
#define CRITICAL_LOGS_NB               ((uint32_t)600)

/* Number of log which can be saved in the trigger logbook */
#define TRIGGER_LOGS_NB                ((uint32_t)40)           /* TBD */

/* Number of previous fault words to check against for saving a log in the critical logbook */
#define PREVIOUS_FAULT_WORD_NB         ((uint32_t)2)

/* Spare value */
#define SPARE_VALUE           ((uint32_t)0)

/* ID of periodic logs */
/* 00 to 03 are fatal fault logs */
#define FCT_ID_MRAM_BUS       ((uint32_t)0x104)
#define FCT_ID_MRAM           ((uint32_t)0x105)
/* 06 is a fatal fault log */
/* 07 to 09 are spare */
#define FCT_ID_PW_28V         ((uint32_t)0x10A)
#define FCT_ID_PW_ALT         ((uint32_t)0x10B)
#define FCT_ID_NGALT          ((uint32_t)0x10C)
#define FCT_ID_NFREQ2         ((uint32_t)0x10D)
#define FCT_ID_NFREQ3         ((uint32_t)0x10E)
#define FCT_ID_NFREQ4         ((uint32_t)0x10F)
#define FCT_ID_NTLOS1         ((uint32_t)0x110)
#define FCT_ID_NTLOS2         ((uint32_t)0x111)
#define FCT_ID_NGOS1          ((uint32_t)0x112)
#define FCT_ID_NGOS2          ((uint32_t)0x113)
/* 14 to 16 are spare */
#define FCT_ID_T4             ((uint32_t)0x117)
#define FCT_ID_VRT1_PT100     ((uint32_t)0x118)
#define FCT_ID_VRT2_PT100     ((uint32_t)0x119)
#define FCT_ID_VRTFF_PT100    ((uint32_t)0x11A)
#define FCT_ID_VRT1_PT1000    ((uint32_t)0x11B)
#define FCT_ID_VRT2_PT1000    ((uint32_t)0x11C)
#define FCT_ID_VRTFF_PT1000   ((uint32_t)0x11D)
#define FCT_ID_P3             ((uint32_t)0x11E)
#define FCT_ID_SG1            ((uint32_t)0x11F)
#define FCT_ID_SG2            ((uint32_t)0x120)
#define FCT_ID_SG3            ((uint32_t)0x121)
#define FCT_ID_SG4            ((uint32_t)0x122)
#define FCT_ID_SG5            ((uint32_t)0x123)
#define FCT_ID_SAI1           ((uint32_t)0x124)
#define FCT_ID_SAI2           ((uint32_t)0x125)
#define FCT_ID_SAI3           ((uint32_t)0x126)
#define FCT_ID_SAI4           ((uint32_t)0x127)
#define FCT_ID_POT1           ((uint32_t)0x128)
#define FCT_ID_POT2           ((uint32_t)0x129)
#define FCT_ID_POT3           ((uint32_t)0x12A)
#define FCT_ID_POT1_DIFF      ((uint32_t)0x12B)
#define FCT_ID_POT2_DIFF      ((uint32_t)0x12C)
#define FCT_ID_POT3_DIFF      ((uint32_t)0x12D) /* Never used as POT3 diff does not exist */
/* 2E to 30 are spare */
#define FCT_ID_LVDTA_1        ((uint32_t)0x131)
#define FCT_ID_LVDTA_2        ((uint32_t)0x132)
#define FCT_ID_LVDTB_1        ((uint32_t)0x133)
#define FCT_ID_LVDTB_2        ((uint32_t)0x134)
#define FCT_ID_LVDTC_1        ((uint32_t)0x135)
#define FCT_ID_LVDTC_2        ((uint32_t)0x136)
#define FCT_ID_XR             ((uint32_t)0x137)
#define FCT_ID_XRB            ((uint32_t)0x138)
#define FCT_ID_CALRES1        ((uint32_t)0x139)
#define FCT_ID_CALRES2        ((uint32_t)0x13A)
#define FCT_ID_CALRES3        ((uint32_t)0x13B)
#define FCT_ID_CALRES4        ((uint32_t)0x13C)
#define FCT_ID_SVOI           ((uint32_t)0x13D)
#define FCT_ID_EMAN           ((uint32_t)0x13E)
/* 3F to 41 are spare */
#define FCT_ID_TMOT           ((uint32_t)0x142)
#define FCT_ID_SMOT           ((uint32_t)0x143)
#define FCT_ID_HP1            ((uint32_t)0x144)
#define FCT_ID_HP2            ((uint32_t)0x145)
#define FCT_ID_HP3            ((uint32_t)0x146)
#define FCT_ID_HP4            ((uint32_t)0x147)
#define FCT_ID_HP5            ((uint32_t)0x148)
#define FCT_ID_LP01           ((uint32_t)0x149)
#define FCT_ID_LP02           ((uint32_t)0x14A)
#define FCT_ID_LP03           ((uint32_t)0x14B)
#define FCT_ID_LP04           ((uint32_t)0x14C)
#define FCT_ID_LP05           ((uint32_t)0x14D)
#define FCT_ID_LP06           ((uint32_t)0x14E)
#define FCT_ID_LP07           ((uint32_t)0x14F)
#define FCT_ID_LP08           ((uint32_t)0x150)
#define FCT_ID_LP09           ((uint32_t)0x151)
#define FCT_ID_LP10           ((uint32_t)0x152)
/* 53 to 55 are spare */
#define FCT_ID_PAN3           ((uint32_t)0x156)
#define FCT_ID_PWM            ((uint32_t)0x157)
#define FCT_ID_P0             ((uint32_t)0x158)
#define FCT_ID_TECU           ((uint32_t)0x159)
#define FCT_ID_SYNC           ((uint32_t)0x15A)
#define FCT_ID_CAN_TX         ((uint32_t)0x15B)
#define FCT_ID_CAN_RX         ((uint32_t)0x15C)
#define FCT_ID_ECDRDL_TX      ((uint32_t)0x15D)
#define FCT_ID_ECDRDL_RX      ((uint32_t)0x15E)
#define FCT_ID_A429_1A_TX     ((uint32_t)0x15F)
#define FCT_ID_A429_1A_RX     ((uint32_t)0x160)
#define FCT_ID_A429_2AB_TX    ((uint32_t)0x161)
#define FCT_ID_A429_2AB_RX    ((uint32_t)0x162)
/* 63 to 65 are spare */
#define FCT_ID_RS422_TX       ((uint32_t)0x166)
#define FCT_ID_RS422_RX       ((uint32_t)0x167)
#define FCT_ID_CCDL_TX        ((uint32_t)0x168)
#define FCT_ID_CCDL_RX        ((uint32_t)0x169)
#define FCT_ID_ICDL_TX        ((uint32_t)0x16A)
#define FCT_ID_ICDL_RX        ((uint32_t)0x16B)
#define FCT_ID_CAN_OVSP       ((uint32_t)0x16C)

/* ---------- provided types: ----------------------------------------------- */
/* Hash map associating registered log address to a function */
typedef struct
{
   /* Registered logbook start address */
   ts_registered_lgbk   *s_reg_lgbk_addr;

   /* Occurrences number of the same function */
   uint32_t              s_short_occurrence_counter;
}
ts_registered_lgbk_hashmap;

/* Hash map associating critical log address to an appearance index */
typedef struct
{
   /* Critical log (= an event block) address to read and write */
   ts_event_block *s_event_block_buffer;

   /* Position in circular buffer for the read operation */
   uint32_t       s_read_index;

   /* Position in circular buffer for the write operation */
   uint32_t       s_write_index;

   /* Number of logs that have not been read yet */
   uint32_t       s_logs_to_read_counter;
}
ts_critical_lgbk_hashmap;

/* Hashmap associating trigger log address to an appearance index */
typedef struct
{
   /* Trigger log address to read and write */
   ts_event_block s_trigger_logs[TRIGGER_LOGS_NB];

   /* Position in circular buffer for the read operation */
   uint32_t       s_read_index;

   /* Position in circular buffer for the write operation */
   uint32_t       s_write_index;

   /* Number of logs that have not been read yet */
   uint32_t       s_logs_to_read_counter;
}
ts_trigger_lgbk_hashmap;

/*  */
typedef union
{
   uint32_t    u_integer;
   int32_t     u_signed_int;
   float32_t   u_float;
}
tu_raw_data;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Number of OS power-up */
extern uint32_t power_up_counter;

/* Hash map associating each origin of event to a registered log address and a short occurrence counter */
extern ts_registered_lgbk_hashmap registered_lgbk_hashmap[FUNCTION_NB];

/* Hash map associating critical log address to an appearance index */
extern ts_critical_lgbk_hashmap critical_lgbk_hashmap;

/* Hashmap associating trigger log address to a function*/
extern ts_trigger_lgbk_hashmap trigger_lgbk_hashmap;

/* Table of the two previous fault words for each function */
extern uint32_t previous_critical_flt_wrd[FUNCTION_NB][PREVIOUS_FAULT_WORD_NB];

/* Table of the fault word of the previous RTC */
extern uint32_t previous_rtc_flt_wrd[FUNCTION_NB];

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0020 */
void logbook_check_mram_corruption(ts_event_block * const p_mram_log, const ts_event_block * const p_local_log);

/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs(const boolean_t p_channel_is_a);

/* MRAM logs */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_mram(void);

/* Powersupply 28V and Powersupply alternator log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_powersup(const boolean_t p_channel_is_a);

/* NGALT NFREQ 2 NFREQ 3 NFREQ 4 logs */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_nfreq(const boolean_t p_channel_is_a);

/* NTL1OS NTL2OS NGOS1 NGOS2 logs */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_ntl_ng(void);

/* T4 log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_t4(const boolean_t p_channel_is_a);

/* VRT1 VRT2 VRTFF logs */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_vrt(const boolean_t p_channel_is_a);

/* P3 SG SAI logs */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_p3_sg_sai(const boolean_t p_channel_is_a);

/* POT logs */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_pot(const boolean_t p_channel_is_a);

/* LVDT logs */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_lvdt(const boolean_t p_channel_is_a);

/* XR logs */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_xr(const boolean_t p_channel_is_a);

/* CALRES logs */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_calres(const boolean_t p_channel_is_a);

/* SVOI and EMAN log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_svoi_eman(void);

/* TMOT log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_log_tmot(const boolean_t p_channel_is_a);

/* SMOT log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_log_smot(void);

/* HP 1 to 5 log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_hp(void);

/* LP 01 to 10 logs */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_lp(void);

/* PAN3 log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_log_pan3(const boolean_t p_channel_is_a);

/* PWM log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_log_pwm(const boolean_t p_channel_is_a);

/* P0 log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_log_p0(const boolean_t p_channel_is_a);

/* TECU log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_log_tecu(const boolean_t p_channel_is_a);

/* Sync log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_log_sync(void);

/* CAN and ECDRDL TX RX log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_can(void);

/* UART RX TX log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_rs422(void);

/* CCDL TX RX log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_ccdl(void);

/* A429 1 and 2AB RX TX log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_a429(const boolean_t p_channel_is_a);

/* ICDL TX RX log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_icdl(void);

/* OVS log */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_ovs(void);

/* Create trigger logs when a function short occurrence counter has reached the CSS_PU trigger value */
void logbook_trigger_streams(void);

#endif /* LOGBOOK_PRIVATE_H */
