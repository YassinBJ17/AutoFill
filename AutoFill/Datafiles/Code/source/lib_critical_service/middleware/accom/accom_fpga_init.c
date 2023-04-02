/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The FPGA torque motor initialization
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/accom/accom_public.h"
#include "middleware/accom/accom_fpga_common.h"
#include "memory/memory_address_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* FPGA register for accomodation */
ts_accom_fpga_reg_type * const accom_fpga_reg =   (ts_accom_fpga_reg_type*) ACCOM_FPGA_MEMORY_ADDR;
tu_accom_fpga_ip02_rtc_sync_status_reg * const sync_sts_reg =
                                  (tu_accom_fpga_ip02_rtc_sync_status_reg*) ACCOM_FPGA_SYNC_STATUS;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */
