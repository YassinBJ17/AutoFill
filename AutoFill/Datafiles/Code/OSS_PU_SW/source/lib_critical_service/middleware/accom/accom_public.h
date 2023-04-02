/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ACCOM_PUBLIC_H
#define ACCOM_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
#define ACCOM_CHANNEL_ID_IS_B ((uint32_t) 1)
#define ACCOM_CHANNEL_ID_IS_A ((uint32_t) 0)

/* ---------- provided types: ----------------------------------------------- */

/* Channel status of FPGA for PBIT or CBIT, accessed field by field */
typedef struct
{
   uint32_t s_ch_id : 1;            /* 31 : Channel identifier on one bit ('1' means channel B) */
   uint32_t s_spare_30_to_01 : 30;  /* 30 to 01 : Spare */
   uint32_t s_ch_id_is_invalid : 1; /* 00 : Whether the channel identifier is invalid */
}
ts_accom_ch_bit_fault_word;

/* Channel status of FPGA  for PBIT or CBIT */
typedef union
{
   ts_accom_ch_bit_fault_word u_bit;  /* Channel identifier PBIT/CBIT fault word  accessed field by field */
   uint32_t u_word; /* Channel identifier PBIT/CBIT fault word  accessed by 32-bit word*/
}
tu_accom_ch_bit_fault_word;

/* Data structure to keep the accommodation data for the Logbook */
typedef struct
{
   uint32_t s_spare_31_to_28   :  4;
   uint32_t s_ch_id_on_one_bit :  1;
   uint32_t s_spare_26_to_18   :  9;
   uint32_t s_ch_decision      :  1;
   uint32_t s_ch_selection     :  1;
   uint32_t s_ch_health_word   : 16;
}
ts_accom_info;

/* Data structure to keep the accommodation data for the Logbook */
typedef union
{
   uint32_t u_word; /* Structure to keep accommodation data for the Logbook */
   ts_accom_info u_bit; /* whole word */
}
tu_accom_info;


/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Channel identifier status */
extern tu_accom_ch_bit_fault_word accom_ch_bit_fault_word;

extern tu_accom_info accom_info;

/* ---------- provided operations: ------------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-ACCOM-0010 */
/**
 * Function to perform checks on the channel identifier, at power-up.
 */
extern tu_accom_ch_bit_fault_word accom_ch_init(void);

/* Implements REQ_FADEX_OS_SRD-ACCOM-0070 */
/**
 * Function to perform CBIT checks on the channel identifier, every RTC.
 */
extern tu_accom_ch_bit_fault_word accom_ch_cbit(void);

/* Implements NO REQUIREMENT */
/**
 * Function to tell the FPGA to take the control from the local channel, and
 *   set the local FCCU to failure state, which will eventually cause a reset.
 */
extern void accom_on_fail_mode(void);

/* Implements REQ_FADEX_OS_SRD-ACCOM-0020 */
/* Implements REQ_FADEX_OS_SRD-ACCOM-0080 */
/* Implements REQ_FADEX_OS_SRD-ACCOM-0090 */
/**
 * Function to provide the logbook capability the accommodation data, using the
 *   shared memory.
 */
void accom_info_for_logbook(void);

/* Implements REQ_FADEX_OS_SRD-ACCOM-0060 */
/* Implements REQ_FADEX_OS_SRD-ACCOM-0090 */
/**
 * Function to provide the CSS_PU and MCSS_PU the accommodation data, using the
 *   shared memory.
 */
extern void accom_periodic(void);


/* -- CRITICAL SERVICES -- */


/* Implements REQ_FADEX_OS_SRD-ACCOM-0040 */
/**
 * Function to set the channel non-prefered state in the FPGA to K_TRUE.
 */
extern void accom_preferential_channel_refuse_write_set(void);
/* Implements REQ_FADEX_OS_SRD-ACCOM-0040 */
/**
 * Function to set the channel non-prefered state in the FPGA to K_FALSE.
 */
extern void accom_preferential_channel_refuse_write_clear(void);


/* Implements REQ_FADEX_OS_SRD-ACCOM-0040 */
/**
 * Function to set the channel unrequested state in the FPGA to K_TRUE.
 */
extern void accom_control_refuse_write_set(void);
/* Implements REQ_FADEX_OS_SRD-ACCOM-0040 */
/**
 * Function to set the channel unrequested state in the FPGA to K_FALSE.
 */
extern void accom_control_refuse_write_clear(void);


/* Implements REQ_FADEX_OS_SRD-ACCOM-0040 */
/**
 * Function to set the non-ability to control the channel in the FPGA to K_TRUE.
 */
extern void accom_css_unable_write_set(void);
/* Implements REQ_FADEX_OS_SRD-ACCOM-0040 */
/**
 * Function to set non-ability to control the channel to K_FALSE.
 */
extern void accom_css_unable_write_clear(void);


/* Implements REQ_FADEX_OS_SRD-ACCOM-0040 */
/**
 * Function to set the channel force disconnection requested
 *   in the GPIO to K_TRUE.
 */
extern void accom_force_disconnection_set(void);
/* Implements REQ_FADEX_OS_SRD-ACCOM-0030 */
/* Implements REQ_FADEX_OS_SRD-ACCOM-0040 */
/**
 * Function to set the channel force disconnection requested in the GPIO
 *   to K_FALSE.
 */
extern void accom_force_disconnection_clear(void);


/* Implements REQ_FADEX_OS_SRD-ACCOM-0050 */
/**
 * Function to set cross-channel inconsistency state in the GPIO to K_TRUE.
 */
extern void accom_mcss_inconsistent_write_set(void);
/* Implements REQ_FADEX_OS_SRD-ACCOM-0050 */
/**
 * Function to set cross-channel inconsistency state in the GPIO to K_FALSE.
 */
extern void accom_mcss_inconsistent_write_clear(void);

#endif /* ACCOM_PUBLIC_H  */
