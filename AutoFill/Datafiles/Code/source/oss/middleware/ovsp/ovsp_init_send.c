/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP initialization send command function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "driver/can/can_private.h"
#include "driver/can/can_critical_private.h"
#include "middleware/ovsp/ovsp_public.h"
#include "middleware/ovsp/ovsp_private.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/uod_bypass/uod_bypass_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */
ts_can_conf can3_conf;  /* Structure for CAN3 configuration */
ts_can_conf can4_conf;  /* Structure for CAN4 configuration */
uint32_t get_data_count_id;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* GET_SW_INFO Command frame */
ts_ovsp_get_sw_info_frame get_sw_info_frame;

/* Overspeed detected counter */
uint32_t ovs_detected_count;

/* OVS css command state (what command is asked by css)*/
uint32_t css_ovs_detect_cmd_state;

/* OVS detect consecutive rtc cam_on counter */
uint32_t consec_rtc_cam_cmd_on;
/* OVS Parameter used to remember AS key if an OFF cmd needs to be send on other channel */
uint32_t as_key_off_to_send_opp_channel;



/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-CANOVS-0001 */
/* Implements REQ_FADEX_OS_SRD-CANOVS-0003 */
/* OVSP initialization send command function */
void ovsp_init_send(void)
{
   /* Initialize the CAN3 (OVSP_LS) */
   can3_conf.s_can_type_id  = e_can_02_a;                 /* 11 bits identifier      */
   can3_conf.s_can_baudrate = e_can_baudrate_very_fast ;  /* CAN BAUD = 1000 kbits/s */

   /* Initialize the CAN4 (OVSP_HS) */
   can4_conf.s_can_type_id  = e_can_02_a;                 /* 11 bits identifier      */
   can4_conf.s_can_baudrate = e_can_baudrate_very_fast ;  /* CAN BAUD = 1000 kbits/s */

   /* Initialize the memory map and set MPC the register configuration for CAN3 and CAN4*/
   LIB_MEM_SET( (void*)(CAN3_RAM_ADDR), (int8_t)0x00000000, CAN_CAN_RAM_OFF );
   LIB_MEM_SET( (void*)(CAN4_RAM_ADDR), (int8_t)0x00000000, CAN_CAN_RAM_OFF );

   /* Configure CAN3 and CAN4 Baudrate and ID type */
   can_init_register(CAN3_REG_ADDR, &can3_conf, CAN3_RAM_ADDR);
   can_init_register(CAN4_REG_ADDR, &can4_conf, CAN4_RAM_ADDR);

   /* Is it necessary to set the range ID filter ? (ID mAX possible = 512) | filter range = [0-513[ */
   ovsp_set_id_range_filter(CAN3_RAM_ADDR, OVSP_ID_START, OVSP_ID_STOP);
   ovsp_set_id_range_filter(CAN4_RAM_ADDR, OVSP_ID_START, OVSP_ID_STOP);

   uod_bypass.uod_can_ovsp_tx_lvl_monitor_ls = (uint32_t)0;
   uod_bypass.uod_can_ovsp_tx_lvl_monitor_hs = (uint32_t)0;

   /* Initialize ovs_detect command in shmem*/
   shmem.s_ovs.s_ovs_cmd1_on  = (uint32_t)0;
   shmem.s_ovs.s_ovs_cmd1_off = (uint32_t)0;
   shmem.s_ovs.s_ovs_cmd2_on  = (uint32_t)0;
   shmem.s_ovs.s_ovs_cmd2_off = (uint32_t)0;

   /* Send the GET_SW_INFO frame command to the OVSP_LS */
   ovsp_get_sw_info_send(CAN3_REG_ADDR, CAN3_RAM_ADDR);
   /* Send the GET_SW_INFO frame command to the OVSP_HS */
   ovsp_get_sw_info_send(CAN4_REG_ADDR, CAN4_RAM_ADDR);


   /* Initialize the frame counter on the identifier field */
   get_data_count_id = (uint32_t)0;

   /* Initialize the overspeed detected counter */
   ovs_detected_count = (uint32_t)0;

   /* initialize ovs detect state counter to 2 (no cmd)*/
   css_ovs_detect_cmd_state = (uint32_t)2;

   /* initialize ovs detect consecutive cam cmd on counter*/
   consec_rtc_cam_cmd_on = (uint32_t)0;

   as_key_off_to_send_opp_channel = (uint32_t)0;


}

/* ---------- internal operations: ------------------------------------------ */
