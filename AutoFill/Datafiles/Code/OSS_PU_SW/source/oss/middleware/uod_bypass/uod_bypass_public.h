/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef UOD_BYPASS_PUBLIC_H
#define UOD_BYPASS_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "middleware/ovsp/ovsp_public.h"
#include "memory/shared_memory_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Structure for UOD accessing variables */
typedef struct
{
   uint8_t enable_bypass_adcOverSpi;
   uint8_t enable_bypass_can_ovsp;

   /* SG / SAI for DSPI 1 */
   uint16_t sg1_sg3_sai1_sai3_sig;
   uint16_t sg1_sg3_sg4_sai1_sai3_gnd;
   uint16_t sg1_sg3_sg4_sai1_sai3_exc;
   uint16_t sg4_sig;

   /* SG / SAI for DSPI2 */
   uint16_t sg2_sai2_sig;
   uint16_t sg2_sg5b_sai2_sai4_gnd;
   uint16_t sg2_sg5b_sai2_sai4_exc;
   uint16_t sg5_sai4_sig;

   /* SG / SAI for DSPI3 */
   uint16_t p3_sig;
   uint16_t p3_gnd;
   uint16_t p3_exc;

   /* XR SIN for DSPI1 */
   uint16_t xr_vsin_raw;
   uint16_t xr_vsin_ref;
   uint16_t xr_vsin_gnd;

   /* XR COS for DSPI2 */
   uint16_t xr_vcos_raw;
   uint16_t xr_vcos_ref;
   uint16_t xr_vcos_gnd;

   /* XR EXC for DSPI3 */
   uint16_t xr_exc_raw;

   /* LVDT S1 for DSPI1 */
   uint16_t lvdt_a_b_s1_raw;
   uint16_t lvdt_c_s1_raw;

   /* LVDT S2 for DSPI2 */
   uint16_t lvdt_a_b_s2_raw;
   uint16_t lvdt_c_s2_raw;

   /* LVDT EXC for DSPI3 */
   uint16_t lvdt_a_b_exc_raw;
   uint16_t lvdt_c_exc_raw;

   /* T4 for DSPI3 */
   uint16_t t4_sig;
   uint16_t t4_gnd;
   uint16_t t4_ref;

   /* VRTx shunt current for DSPI3 */
   uint16_t vrt1_shunt_curr_raw;
   uint16_t vrt2_shunt_curr_raw;
   uint16_t vrtff_shunt_curr_raw;

   /* VRTx voltage for DSPI3 */
   uint16_t vrt1_voltage_raw;
   uint16_t vrt2_voltage_raw;
   uint16_t vrtff_voltage_raw;

   /* VRTx ground voltage for DSPI3 */
   uint16_t gnd_voltage_raw;

   /* UOD RX buffer for OVSP HS  */
   ts_can_frame uod_can_ovsp_rx_buffer_hs[OVSP_RX_NB_MAX_FRAME];
   /* UOD RX buffer for OVSP LS  */
   ts_can_frame uod_can_ovsp_rx_buffer_ls[OVSP_RX_NB_MAX_FRAME];
   /* UOD TX buffer for OVSP HS  */
   ts_can_frame uod_can_ovsp_tx_buffer_hs;
   /* UOD TX buffer for OVSP LS  */
   ts_can_frame uod_can_ovsp_tx_buffer_ls;
   /* UOD TX buffer monitoring level for OVSP LS  */
   uint32_t uod_can_ovsp_tx_lvl_monitor_ls;
   /* UOD TX buffer monitoring level for OVSP HS  */
   uint32_t uod_can_ovsp_tx_lvl_monitor_hs;
   /* UOD TX buffer monitoring for OVSP HS  */
   ts_can_frame uod_can_ovsp_tx_monitor_hs[OVSP_TX_FRAME_SEND];
   /* UOD TX buffer monitoring for OVSP LS  */
   ts_can_frame uod_can_ovsp_tx_monitor_ls[OVSP_TX_FRAME_SEND];

   /* POT voltages for DSPI3 */
   uint16_t pot_1_2_signal_raw;
   uint16_t pot_1_2_exc_raw;
   uint16_t pot_gnd_raw;
   uint16_t pot_ref_raw;
   uint16_t pot_3_signal_raw;
   uint16_t pot_3_exc_raw;

   /* CALRES voltages for DSPI1 */
   uint16_t calres_2_4_signal_raw;
   uint16_t calres_2_4_ref_raw;
   uint16_t calres_2_4_gnd_raw;

   /* CALRES voltages for DSPI2 */
   uint16_t calres_1_3_signal_raw;
   uint16_t calres_1_3_ref_raw;
   uint16_t calres_1_3_gnd_raw;

} ts_uod_bypass;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Structure for UOD */
extern ts_uod_bypass uod_bypass;

/* ---------- provided operations: ------------------------------------------ */
/* Init */
extern void initialize_uod_bypass(void);

#endif /* UOD_BYPASS_PUBLIC_H */
