/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs function which manages CBIT logs
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/logbook/logbook_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs(const boolean_t p_channel_is_a)
{
   /* MRAM logs */
   /* CURRENTLY NOTHING TO LOG FOR MRAM BUS AND MRAM */
   /* logbook_periodic_logs_mram(); */

   /* Powersupply 28V and Powersupply alternator log */
   logbook_periodic_logs_powersup(p_channel_is_a);

   /* NGALT NFREQ 2 NFREQ 3 NFREQ 4 logs */
   logbook_periodic_logs_nfreq(p_channel_is_a);

   /* NTL1OS NTL2OS NGOS1 NGOS2 logs */
   logbook_periodic_logs_ntl_ng();

   /* T4 log */
   logbook_periodic_logs_t4(p_channel_is_a);

   /* VRT1 VRT2 VRTFF logs */
   logbook_periodic_logs_vrt(p_channel_is_a);

   /* P3 SG SAI logs */
   logbook_periodic_logs_p3_sg_sai(p_channel_is_a);

   /* POT logs */
   logbook_periodic_logs_pot(p_channel_is_a);

   /* LVDT logs */
   logbook_periodic_logs_lvdt(p_channel_is_a);

   /* XR logs */
   logbook_periodic_logs_xr(p_channel_is_a);

   /* CALRES logs */
   logbook_periodic_logs_calres(p_channel_is_a);

   /* SVOI and EMAN log */
   logbook_periodic_logs_svoi_eman();

   /* TMOT log */
   logbook_periodic_log_tmot(p_channel_is_a);

   /* SMOT log */
   logbook_periodic_log_smot();

   /* HP 1 to 5 log */
   logbook_periodic_logs_hp();

   /* LP 01 to 10 logs */
   logbook_periodic_logs_lp();

   /* PAN3 log */
   logbook_periodic_log_pan3(p_channel_is_a);

   /* PWM log */
   logbook_periodic_log_pwm(p_channel_is_a);

   /* P0 log */
   logbook_periodic_log_p0(p_channel_is_a);

   /* TECU log */
   logbook_periodic_log_tecu(p_channel_is_a);

   /* Sync log */
   logbook_periodic_log_sync();

   /* CAN and ECDRDL TX RX log */
   logbook_periodic_logs_can();

   /* UART RX TX log */
   logbook_periodic_logs_rs422();

   /* CCDL TX RX log */
   logbook_periodic_logs_ccdl();

   /* A429 1 and 2AB RX TX log */
   logbook_periodic_logs_a429(p_channel_is_a);

   /* ICDL TX RX log */
   logbook_periodic_logs_icdl();

   /* OVS log */
   logbook_periodic_logs_ovs();
}

/* ---------- internal operations: ------------------------------------------ */
