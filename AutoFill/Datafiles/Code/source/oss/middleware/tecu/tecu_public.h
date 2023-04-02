/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef TECU_PUBLIC_H
#define TECU_PUBLIC_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "memory/shared_memory_public.h"

/* ---------- provided define constants: ------------------------------------ */
/* The minimum expected control unit temperature (provided from ADT7310 sensor) */
#define CONTROL_UNIT_1_TEMP_MIN -60

/* The maximum expected control unit temperature (provided from ADT7310 sensor) */
#define CONTROL_UNIT_1_TEMP_MAX 160

/* The minimum expected control processing core die temperature (provided from the internal processor sensor) */
#define CONTROL_UNIT_2_TEMP_MIN -60

/* The minimum expected control processing core die temperature (provided from the internal processor sensor) */
#define CONTROL_UNIT_2_TEMP_MAX 160

/* The minimum expected primary power supply function (provided from TMP116 sensor) */
#define TPSF_TEMP_MIN -60

/* The maximum expected primary power supply function (provided from TMP116 sensor) */
#define TPSF_TEMP_MAX 160

/* The minimum expected cold junction function (provided from TMP116 sensor) */
#define TCJ_TEMP_MIN -60

/* The maximum expected cold junction function (provided from TMP116 sensor) */
#define TCJ_TEMP_MAX 160

/* The minimum expected control processing core die temperature (provided from the internal processor sensor) */
#define TECU_AVG_TEMP_MIN -60

/* The minimum expected control processing core die temperature (provided from the internal processor sensor) */
#define TECU_AVG_TEMP_MAX 160

/* Control unit temperature filter coefficiant (Set to NULL for the BLUE LABEL) */
#define TCU1_FILTER_COEFF 0

/* Control processing core die temperature filter coefficiant (Set to NULL for the BLUE LABEL) */
#define TCU2_FILTER_COEFF 0

/* Accommodation temperature filter coefficiant (Set to NULL for the BLUE LABEL) */
#define TACCOM_FILTER_COEFF 0

/* Primary power supply temperature filter coefficiant (Set to NULL for the BLUE LABEL) */
#define TPSF_FILTER_COEFF 0

/* Overspeed high side temperature filter coefficiant (Set to NULL for the BLUE LABEL) */
#define TOHS_FILTER_COEFF 0

/* Overspeed low side temperature filter coefficiant (Set to NULL for the BLUE LABEL) */
#define TOLS_FILTER_COEFF 0

/* Cold junction temperature filter coefficiant (Set to NULL for the BLUE LABEL) */
#define TCJ_FILTER_COEFF 0

/* Cold junction temperature filter coefficiant (Set to NULL for the BLUE LABEL) */
#define TCJ_FILTER_COEFF 0

/* Temperature Sensor Calibration A address */
#define TCSA_ADDR (0x00400000)

/* Temperature Sensor Calibration B address */
#define TCSB_ADDR (0x00400002)

/* Number of ship select used per SPI line */
#define SPI_CFEX_SPI0_CS_NB (uint32_t)1

/* Value that indicates all temperature are faulty */
#define TECU_STATUS_ALL_TEMP_FAULTY (uint32_t)0x3F080

/* Index of SPI line 0 configuration in SPI_MPC577_CFEX_CONFIGURATION_tab table */
#define TECU_SPI_CONF_IDx (uint32_t)6

/* Number of ship select used per SPI line */
#define SPI_CFEX_SPI0_CS_NB (uint32_t)1

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/***** Previous TECU status *****/

extern ts_tecu prev_tecua_status;    /* Previous TECU status for channel A */
extern ts_tecu prev_tecub_status;    /* Previous TECU status for channel B */



/***** Previous TECU temperatures *****/

extern float32_t prev_taccom;             /* Previous accommodation temperature */
extern float32_t prev_tcu1;               /* Previous control unit temperature  */
extern float32_t prev_tpsf;               /* Previous primary power supply temperature */
extern float32_t prev_tcu2;               /* Previous control processing core die temperature */
extern float32_t prev_tohs;               /* Previous overspeed high side temperature */
extern float32_t prev_tols;               /* Previous overspeed low side temperature */
extern float32_t prev_tcj;                /* Previous cold junction temperature */
extern float32_t last_valid_tecu_avg;     /* The last valid weighted average temperature */



/***** TECU temperatures *****/

extern float32_t taccom;    /* Accommodation temperature */
extern float32_t tcu1;      /* Control unit temperature (provided from ADT7310 sensor) */
extern float32_t tcu2;      /* Control processing core die temperature (provided from the internal processor sensor) */
extern float32_t tpsf;      /* Primary power supply temperature (provided from TMP116 sensor) */
extern float32_t tohs;      /* Overspeed high side temperature */
extern float32_t tols;      /* Overspeed low side temperature */



/***** TECU filtered temperatures *****/

extern float32_t filt_taccom;       /* Accommodation filtered temperature */
extern float32_t filt_tcu1;         /* Control unit filtered temperature */
extern float32_t filt_tpsf;         /* Primary power supply filtered temperature */
extern float32_t filt_tcu2;         /* Control processing core die filtered temperature */
extern float32_t filt_tohs;         /* Overspeed high side filtered temperature */
extern float32_t filt_tols;         /* Overspeed low side filtered temperature */
extern float32_t filt_tcj;          /* Cold junction filtered temperature */
extern float32_t prev_filt_taccom;  /* Accommodation filtered temperature */


/***** Previous  TECU filtered temperatures *****/

extern float32_t prev_filt_tcu1;    /* revious control unit filtered temperature */
extern float32_t prev_filt_tpsf;    /* Previous primary power supply filtered temperature */
extern float32_t prev_filt_tcu2;    /* Previous control processing core die filtered temperature */
extern float32_t prev_filt_tohs;    /* Previous overspeed high side filtered temperature */
extern float32_t prev_filt_tols;    /* Previous overspeed low side filtered temperature */
extern float32_t prev_filt_tcj;     /* Previous cold junction filtered temperature */


extern float32_t max_tecu;          /* The maximum computed TECU value */
extern float32_t max_tecu_time;     /* Indicate the time when the maximum TECU value is computed */


extern int16_t   TECU_tcsa;         /* Temperature Sensor Calibration A */
extern int16_t   TECU_tcsb;         /* Temperature Sensor Calibration B */

extern uint32_t int_ext_temp;       /* Internal and external temperature */

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-TECU_0001 */
/* Implements REQ_FADEX_OS_SRD-TECU_0020 */
/* TECU status management function */
extern void tecu_manage_status(const boolean_t channel_is_a);

/* Implements REQ_FADEX_OS_SRD-TECU_0010 */
/* Compute accomodation temperature filter */
extern void tecu_compute_taccom(const boolean_t channel_is_a);

/* Implements REQ_FADEX_OS_SRD-TECU_0010 */
/* Compute control unit temperature filter */
extern void tecu_compute_tcu1(const boolean_t channel_is_a);

/* Implements REQ_FADEX_OS_SRD-TECU_0010 */
/* Compute control processing core die temperature filter */
extern void tecu_compute_tcu2(const boolean_t channel_is_a);

/* Implements REQ_FADEX_OS_SRD-TECU_0010 */
/* Compute primary supply function temperature filter */
extern void tecu_compute_tpsf(const boolean_t channel_is_a);

/* Implements REQ_FADEX_OS_SRD-TECU_0010 */
/* Compute cold junction temperature filter */
extern void tecu_compute_tcj(const boolean_t channel_is_a);

/* Implements REQ_FADEX_OS_SRD-TECU_0010 */
/* Compute overspeed high side temperature filter */
extern void tecu_compute_tohs(const boolean_t channel_is_a);

/* Implements REQ_FADEX_OS_SRD-TECU_0010 */
/* Compute overspeed low side temperature filter */
extern void tecu_compute_tols(const boolean_t channel_is_a);

/* Implements REQ_FADEX_OS_SRD-TECU-0010 */
/* Implements REQ_FADEX_OS_SRD-TECU-0020 */
/* Implements REQ_FADEX_OS_SRD-TECU-0040 */
/* Implements REQ_FADEX_OS_SRD-TECU-0050 */
/* Compute weighted average TECU final temperature function */
extern void tecu_compute_avg(const boolean_t channel_is_a);

/* Implements REQ_FADEX_OS_SRD-TECU_0001 */
/* Implements REQ_FADEX_OS_SRD-TECU_0010 */
/* Implements REQ_FADEX_OS_SRD-TECU_0020 */
/* TECU periodic function (CBIT) */
extern void tecu_periodic(const boolean_t channel_is_a);

/* Implements REQ_FADEX_OS_SRD-TECU_0020 */
/* TECU initialization function */
extern void tecu_init(void);

#endif /* TECU_PUBLIC_H */
