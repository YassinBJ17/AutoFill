/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP get sw info command send
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/ovsp/ovsp_public.h"
#include "middleware/ovsp/ovsp_private.h"
#include "middleware/ovsp/ovsp_frame.h"
#include "memory/shared_memory_public.h"
#include "driver/can/can_critical_private.h"
#include "conf/oss_conf_public.h"
#include "memory/memory_address_public.h"
#include "memory/shared_memory_public.h"
#include "libtools/memory/LIB_MEM_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
extern ts_can_frame*   table_frames_set_param[12];

/* ---------- provided operation bodies: ------------------------------------ */

void ovsp_set_param_build(void)
{
   /* declaration of the structure of set param frames */
   ts_ovsp_set_param_frames set_param_cmd_frames;
   /* declaration of the struc to retrieve conf in MRAM */
   ts_oss_conf_table * oss_conf;


   /* retrieve conf in MRAM */
   oss_conf = (ts_oss_conf_table *)(OSS_CONF_START_ADDR);

   /* frame 1 construction */
   set_param_cmd_frames.s_frame1.s_identifier    = (uint32_t)OVSP_SET_PARAM_ID_frame1;
   set_param_cmd_frames.s_frame1.s_command_frame = (uint32_t)0xABCDEF01;
   set_param_cmd_frames.s_frame1.s_ovsp_crc      = oss_conf->s_ovsp_config_16bitcrc ;
   set_param_cmd_frames.s_frame1.s_data_unused   = (uint16_t)0x00;
   set_param_cmd_frames.s_frame1.s_length        = OVSP_FRAME_TOT_LENGTH;

   /* frame 2 construction */
   set_param_cmd_frames.s_frame2.s_identifier = (uint32_t)OVSP_SET_PARAM_ID_frame2;
   set_param_cmd_frames.s_frame2.s_ntl_threshold_inhib = oss_conf->s_ovs_ntlthresholdinhib;
   set_param_cmd_frames.s_frame2.s_ng_inhib = oss_conf->s_ovs_nginhib;
   set_param_cmd_frames.s_frame2.s_css_inhib = oss_conf->s_ovs_cssinhib;
   set_param_cmd_frames.s_frame2.s_one_sensor_ng_inhib = oss_conf->s_ovs_onesensornginhib;
   set_param_cmd_frames.s_frame2.s_one_sensor_ntl_inhib = oss_conf->s_ovs_onesensorntlinhib;
   set_param_cmd_frames.s_frame2.s_interlock_inhib = oss_conf->s_interlock_inhib;
   set_param_cmd_frames.s_frame2.s_unused   = (uint16_t)0x00;
   set_param_cmd_frames.s_frame2.s_length = OVSP_FRAME_TOT_LENGTH;

   /* frame 3 construction */
   set_param_cmd_frames.s_frame3.s_identifier       = (uint32_t)OVSP_SET_PARAM_ID_frame3;
   set_param_cmd_frames.s_frame3.s_ntlos1_nl        = oss_conf->s_ntlos1_nl;
   set_param_cmd_frames.s_frame3.s_ntlos1_nh        = oss_conf->s_ntlos1_nh;
   set_param_cmd_frames.s_frame3.s_ntlos2_nl        = oss_conf->s_ntlos2_nl;
   set_param_cmd_frames.s_frame3.s_ntlos2_nh        = oss_conf->s_ntlos2_nh;
   set_param_cmd_frames.s_frame3.s_ntl_ovs_thresd_n = oss_conf->s_ntl_ovsthresd_n;
   set_param_cmd_frames.s_frame3.s_ntl_ovs_funct    = oss_conf->s_ntl_ovs_function;
   set_param_cmd_frames.s_frame3.s_unused           = (uint16_t)0x00;
   set_param_cmd_frames.s_frame3.s_length = OVSP_FRAME_TOT_LENGTH;

   /* frame 4 construction */
   set_param_cmd_frames.s_frame4.s_identifier       = (uint32_t)OVSP_SET_PARAM_ID_frame4;
   set_param_cmd_frames.s_frame4.s_ngos1_nl         = oss_conf->s_ngos1_nl;
   set_param_cmd_frames.s_frame4.s_ngos1_nh         = oss_conf->s_ngos1_nh;
   set_param_cmd_frames.s_frame4.s_ngos2_nl         = oss_conf->s_ngos2_nl;
   set_param_cmd_frames.s_frame4.s_ngos2_nh         = oss_conf->s_ngos2_nh;
   set_param_cmd_frames.s_frame4.s_ng_ovs_thresd_n  = oss_conf->s_ng_ovsthresd_n;
   set_param_cmd_frames.s_frame4.s_unused1           = (uint8_t)0x0;
   set_param_cmd_frames.s_frame4.s_unused2           = (uint16_t)0x00;
   set_param_cmd_frames.s_frame4.s_length = OVSP_FRAME_TOT_LENGTH;

   /* frame 5 construction */
   set_param_cmd_frames.s_frame5.s_identifier       = (uint32_t)OVSP_SET_PARAM_ID_frame5;
   set_param_cmd_frames.s_frame5.s_ng_ovs_thresd_0 = oss_conf->s_ng_ovsthresd_threshold_ar[0];
   set_param_cmd_frames.s_frame5.s_ng_ovs_thresd_1 = oss_conf->s_ng_ovsthresd_threshold_ar[1];
   set_param_cmd_frames.s_frame5.s_ng_ovs_thresd_2 = oss_conf->s_ng_ovsthresd_threshold_ar[2];
   set_param_cmd_frames.s_frame5.s_ng_ovs_thresd_3 = oss_conf->s_ng_ovsthresd_threshold_ar[3];
   set_param_cmd_frames.s_frame5.s_ng_ovs_thresd_4 = oss_conf->s_ng_ovsthresd_threshold_ar[4];
   set_param_cmd_frames.s_frame5.s_ng_ovs_thresd_5 = oss_conf->s_ng_ovsthresd_threshold_ar[5];
   set_param_cmd_frames.s_frame5.s_unused           = (uint16_t)0x00;
   set_param_cmd_frames.s_frame5.s_length = OVSP_FRAME_TOT_LENGTH;

   /* frame 6 construction */
   set_param_cmd_frames.s_frame6.s_identifier       = (uint32_t)OVSP_SET_PARAM_ID_frame6;
   set_param_cmd_frames.s_frame6.s_ntl_ovs_variable_threshold_0 = oss_conf->s_ntl_ovsvariable_threshold_ar[0];
   set_param_cmd_frames.s_frame6.s_ntl_ovs_variable_threshold_1 = oss_conf->s_ntl_ovsvariable_threshold_ar[1];
   set_param_cmd_frames.s_frame6.s_ntl_ovs_variable_threshold_2 = oss_conf->s_ntl_ovsvariable_threshold_ar[2];
   set_param_cmd_frames.s_frame6.s_ntl_ovs_variable_threshold_3 = oss_conf->s_ntl_ovsvariable_threshold_ar[3];
   set_param_cmd_frames.s_frame6.s_ntl_ovs_variable_threshold_4 = oss_conf->s_ntl_ovsvariable_threshold_ar[4];
   set_param_cmd_frames.s_frame6.s_ntl_ovs_variable_threshold_5 = oss_conf->s_ntl_ovsvariable_threshold_ar[5];
   set_param_cmd_frames.s_frame6.s_unused           = (uint16_t)0x00;
   set_param_cmd_frames.s_frame6.s_length = OVSP_FRAME_TOT_LENGTH;

   /* frame 7 construction */
   set_param_cmd_frames.s_frame7.s_identifier    = (uint32_t)OVSP_SET_PARAM_ID_frame7;
   set_param_cmd_frames.s_frame7.s_ngos1_timeout = oss_conf->s_ngos1_timeout;
   set_param_cmd_frames.s_frame7.s_ngos1_100     = oss_conf->s_ngos1_100;
   set_param_cmd_frames.s_frame7.s_length        = OVSP_FRAME_TOT_LENGTH;

   /* frame 8 construction */
   set_param_cmd_frames.s_frame8.s_identifier    = (uint32_t)OVSP_SET_PARAM_ID_frame8;
   set_param_cmd_frames.s_frame8.s_ngos2_timeout = oss_conf->s_ngos2_timeout;
   set_param_cmd_frames.s_frame8.s_ngos2_100     = oss_conf->s_ngos2_100;
   set_param_cmd_frames.s_frame8.s_length        = OVSP_FRAME_TOT_LENGTH;

   /* frame 9 construction */
   set_param_cmd_frames.s_frame9.s_identifier     = (uint32_t)OVSP_SET_PARAM_ID_frame9;
   set_param_cmd_frames.s_frame9.s_ntlos1_timeout = oss_conf->s_ntlos1_timeout;
   set_param_cmd_frames.s_frame9.s_ntlos1_100     = oss_conf->s_ntlos1_100;
   set_param_cmd_frames.s_frame9.s_length         = OVSP_FRAME_TOT_LENGTH;

   /* frame 10 construction */
   set_param_cmd_frames.s_frame10.s_identifier     = (uint32_t)OVSP_SET_PARAM_ID_frame10;
   set_param_cmd_frames.s_frame10.s_ntlos2_timeout = oss_conf->s_ntlos2_timeout;
   set_param_cmd_frames.s_frame10.s_ntlos2_100     = oss_conf->s_ntlos2_100;
   set_param_cmd_frames.s_frame10.s_length         = OVSP_FRAME_TOT_LENGTH;

   /* frame 11 construction */
   set_param_cmd_frames.s_frame11.s_identifier                = (uint32_t)OVSP_SET_PARAM_ID_frame11;
   set_param_cmd_frames.s_frame11.s_ntl_ovs_thresd_threshold  = oss_conf->s_ntl_ovsthresd_threshold;
   set_param_cmd_frames.s_frame11.s_ntl_ovs_thresd_window     = oss_conf->s_ntl_ovsthresd_window;
   set_param_cmd_frames.s_frame11.s_length                    = OVSP_FRAME_TOT_LENGTH;

   /* frame 12 construction */
   set_param_cmd_frames.s_frame12.s_identifier              = (uint32_t)OVSP_SET_PARAM_ID_frame12;
   set_param_cmd_frames.s_frame12.s_ng_ovs_thresd_threshold = oss_conf->s_ng_ovsthresd_threshold;
   set_param_cmd_frames.s_frame12.s_ng_ovs_thresd_window    = oss_conf->s_ng_ovsthresd_window;
   set_param_cmd_frames.s_frame12.s_length                  = OVSP_FRAME_TOT_LENGTH;

   /***** Fill set_param Tx frame ******/
   /* Trame 1 */
   table_frames_set_param[0] = (ts_can_frame*)(&set_param_cmd_frames.s_frame1);
   /* Trame 2 */
   table_frames_set_param[1] = (ts_can_frame*)(&set_param_cmd_frames.s_frame2);
   /* Trame 3 */
   table_frames_set_param[2] = (ts_can_frame*)(&set_param_cmd_frames.s_frame3);
   /* Trame 4 */
   table_frames_set_param[3] = (ts_can_frame*)(&set_param_cmd_frames.s_frame4);
   /* Trame 5 */
   table_frames_set_param[4] = (ts_can_frame*)(&set_param_cmd_frames.s_frame5);
   /* Trame 6 */
   table_frames_set_param[5] = (ts_can_frame*)(&set_param_cmd_frames.s_frame6);
   /* Trame 7 */
   table_frames_set_param[6] = (ts_can_frame*)(&set_param_cmd_frames.s_frame7);
   /* Trame 8 */
   table_frames_set_param[7] = (ts_can_frame*)(&set_param_cmd_frames.s_frame8);
   /* Trame 9 */
   table_frames_set_param[8] = (ts_can_frame*)(&set_param_cmd_frames.s_frame9);
   /* Trame 10 */
   table_frames_set_param[9] = (ts_can_frame*)(&set_param_cmd_frames.s_frame10);
   /* Trame 11 */
   table_frames_set_param[10] = (ts_can_frame*)(&set_param_cmd_frames.s_frame11);
   /* Trame 12 */
   table_frames_set_param[11] = (ts_can_frame*)(&set_param_cmd_frames.s_frame12);

}

/* ---------- internal operations: ------------------------------------------ */
