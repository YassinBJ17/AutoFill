/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef OVSP_PRIVATE_H
#define OVSP_PRIVATE_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "middleware/ovsp/ovsp_frame.h"
#include "driver/can/can_critical_private.h"
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */
typedef enum
{
   e_ovsp_baudrate_125  = 0, /*  125 Kbit/s */
   e_ovsp_baudrate_250  = 1, /*  250 Kbit/s */
   e_ovsp_baudrate_500  = 2, /*  500 Kbit/s */
   e_ovsp_baudrate_1000 = 3  /* 1000 Kbit/s */
}
te_ovsp_baudrate_t;

typedef enum
{
   e_ovsp_11_bits_id = 0,  /* 0 = CAN 2.0A (11 bits identifier) */
   e_ovsp_29_bits_id = 1   /* 1 = CAN 2.0B (29 bits identifier) */
}
te_ovsp_identifier_t;

typedef struct
{
   uint32_t te_ovsp_identifier_t;
   uint32_t te_ovsp_baudrate_t;
}
ts_ovsp_conf;

typedef enum
{
   e_ovsp_cam_cmd1_on  = 0, /*  */
   e_ovsp_cam_cmd1_off = 1, /*  */
   e_ovsp_cam_cmd2_on  = 2, /*  */
   e_ovsp_cam_cmd2_off = 3  /*  */
}
te_ovsp_cam_cmd_t;

typedef enum
{
   e_one_ng_sensor_auth    = 0, /*  */
   e_one_ntl_sensor_auth   = 1,
   e_ovsp_two_sensor_config  = 2 /*  */
}
te_ovsp_one_sensor_cmd_t;



/* ---------- provided constants: ------------------------------------------- */
#define CAN3_REG_ADDR                ((uint32_t)0xFFEEC000)
#define CAN4_REG_ADDR                ((uint32_t)0xFFEF0000)
#define CAN_CAN_OFF                  ((uint32_t)0x4000)      /* CAN offset */

#define CAN3_RAM_ADDR                ((uint32_t)0xFFED6000)  /* CAN 3 RAM start address */
#define CAN4_RAM_ADDR                ((uint32_t)0xFFED7000)  /* CAN 4 RAM start address */
#define CAN_CAN_RAM_OFF              ((uint32_t)0x1000)      /* CAN RAM offset */

#define CAN_OVS_OFFSET   ((uint32_t) 0x00000380)

#define OVSP_FRAME_TOT_LENGTH (uint32_t)8

#define OVSP_TRIG_TEST_ON_OFF_SIZE (uint8_t)4 /* number of datas byte equal to 0 in GET SW INFO frame */
#define OVSP_TRIG_TEST_SPEED_SIZE (uint8_t)4 /* number of datas byte equal to 0 in GET SW INFO frame */

#define OVSP_DISCR_TEST_ON_OFF_SIZE (uint8_t)4 /* number of datas byte equal to 0 in GET SW INFO frame */
#define OVSP_DISCR_TEST_UNUSED_SIZE (uint8_t)4 /* number of datas byte equal to 0 in GET SW INFO frame */

#define OVSP_CAM_CMD_OS_AS_KEY_SIZE (uint8_t)4 /* number of datas byte equal to 0 in GET SW INFO frame */

#define OVSP_OSARM_CMD_OS_KEY_SIZE (uint8_t)4 /* number of datas byte equal to 0 in GET SW INFO frame */
#define OVSP_OSARM_CMD_UNUSED_SIZE (uint8_t)4 /* number of datas byte equal to 0 in GET SW INFO frame */

#define OVSP_REARM_CMD_OS_KEY_SIZE (uint8_t)4 /* number of datas byte equal to 0 in GET SW INFO frame */
#define OVSP_REARM_CMD_UNUSED_SIZE (uint8_t)4 /* number of datas byte equal to 0 in GET SW INFO frame */

#define OVSP_GET_DATA_UNUSED_SIZE (uint8_t)8 /* number of datas byte equal to 0 in GET SW INFO frame */

#define OVSP_ONE_SENSOR_NTL_AUTH_SIZE (uint8_t)4 /* number of datas byte equal to 0 in GET SW INFO frame */
#define OVSP_ONE_SENSOR_NG_AUTH_SIZE (uint8_t)4 /* number of datas byte equal to 0 in GET SW INFO frame */

/* FIFO FULL */
#define OVSP_FIFO_NOT_FULL       (uint32_t)0
#define OVSP_FIFO_FULL           (uint32_t)1

#define OVSP_GET_SW_INFO_ID         (uint32_t)0x0
#define OVSP_SET_PARAM_ID_frame1    (uint32_t)0x1  /* Old 64 */
#define OVSP_SET_PARAM_ID_frame2    (uint32_t)0x21 /* Old 68 */
#define OVSP_SET_PARAM_ID_frame3    (uint32_t)0x41 /* Old 72 */
#define OVSP_SET_PARAM_ID_frame4    (uint32_t)0x61 /* Old 76 */
#define OVSP_SET_PARAM_ID_frame5    (uint32_t)0x81  /* Old 80 */
#define OVSP_SET_PARAM_ID_frame6    (uint32_t)0xA1 /* Old 84 */
#define OVSP_SET_PARAM_ID_frame7    (uint32_t)0xC1 /* Old 88 */
#define OVSP_SET_PARAM_ID_frame8    (uint32_t)0xE1 /* Old 92 */
#define OVSP_SET_PARAM_ID_frame9    (uint32_t)0x101  /* Old 96 */
#define OVSP_SET_PARAM_ID_frame10   (uint32_t)0x121 /* Old 100 */
#define OVSP_SET_PARAM_ID_frame11   (uint32_t)0x141 /* Old 104 */
#define OVSP_SET_PARAM_ID_frame12   (uint32_t)0x161 /* Old 108 */
#define OVSP_TRIGGERED_TEST_ID      (uint32_t)0x02   /* Old 128 */
#define OVSP_TEST_DISCRETE_ID       (uint32_t)0x03  /* Old 192 */
#define OVSP_CAM_CMD_ID             (uint32_t)0x04   /* Old 256 */
#define OVSP_OSARM_CMD_ID           (uint32_t)0x05  /* Old 320 */
#define OVSP_REARM_CMD_ID           (uint32_t)0x06  /* Old 384 */
#define OVSP_GET_DATA_ID            (uint32_t)0x07  /* Old 448 */
#define OVSP_ONE_SENSOR_CMD_ID      (uint32_t)0x08   /* Old 512 */

#define OVSP_DATA_RESP_ID_FRAME1_0    (uint32_t)0x27
#define OVSP_DATA_RESP_ID_FRAME1_1    (uint32_t)0x227
#define OVSP_DATA_RESP_ID_FRAME1_2    (uint32_t)0x427
#define OVSP_DATA_RESP_ID_FRAME1_3    (uint32_t)0x627

#define OVSP_DATA_RESP_ID_FRAME2_0    (uint32_t)0x47
#define OVSP_DATA_RESP_ID_FRAME2_1    (uint32_t)0x247
#define OVSP_DATA_RESP_ID_FRAME2_2    (uint32_t)0x447
#define OVSP_DATA_RESP_ID_FRAME2_3    (uint32_t)0x647

#define OVSP_DATA_RESP_ID_FRAME3_0    (uint32_t)0x67
#define OVSP_DATA_RESP_ID_FRAME3_1   (uint32_t)0x267
#define OVSP_DATA_RESP_ID_FRAME3_2    (uint32_t)0x467
#define OVSP_DATA_RESP_ID_FRAME3_3    (uint32_t)0x667

#define OVSP_DATA_RESP_ID_FRAME4_0    (uint32_t)0x87
#define OVSP_DATA_RESP_ID_FRAME4_1    (uint32_t)0x287
#define OVSP_DATA_RESP_ID_FRAME4_2    (uint32_t)0x487
#define OVSP_DATA_RESP_ID_FRAME4_3    (uint32_t)0x687

#define OVSP_DATA_RESP_ID_FRAME5_0    (uint32_t)0xA7
#define OVSP_DATA_RESP_ID_FRAME5_1    (uint32_t)0x2A7
#define OVSP_DATA_RESP_ID_FRAME5_2    (uint32_t)0x4A7
#define OVSP_DATA_RESP_ID_FRAME5_3    (uint32_t)0x6A7

#define OVSP_DATA_RESP_ID_FRAME6_0    (uint32_t)0xC7
#define OVSP_DATA_RESP_ID_FRAME6_1    (uint32_t)0x2C7
#define OVSP_DATA_RESP_ID_FRAME6_2    (uint32_t)0x4C7
#define OVSP_DATA_RESP_ID_FRAME6_3    (uint32_t)0x6C7

#define OVSP_GET_DATA_MAX_FRAME      ((uint32_t)64)
#define OVSP_TX_NB_MAX_FRAME      ((uint32_t)1)

#define OVSP_ID_START (uint32_t)0
#define OVSP_ID_STOP  (uint32_t)2000

/* CAMhigh side voltage monitoring threshold for erroneous LS command */
#define OVSP_CAM_VOLT_THOLD_MIN_LS_CMD (uint32_t)2

/* CAMhigh side voltage monitoring  minimum threshold for open circuit detection */
#define OVSP_CAM_VOLT_THOLD_MIN (float32_t)8.6

/* CAM high side voltage monitoring maximum threshold for open circuit detection or erroneous high side command */
#define OVSP_CAM_VOLT_THOLD_MAX (float32_t)15.0

#define OVSP_CAM_CURRENT_MAX (float32_t)2.0

/* ---------- provided data: ------------------------------------------------ */
/* Frame counter on the identifier field */
extern uint32_t get_data_count_id;
/* overspeed detected counter */
extern uint32_t ovs_detected_count;

/* OVS detect consecutive rtc cam_on counter */
extern uint32_t consec_rtc_cam_cmd_on;
/* OVS Parameter used to remember AS key if an OFF cmd needs to be send on other channel */
extern uint32_t as_key_off_to_send_opp_channel;
/* OVS css command state (what command is asked by css)*/
extern uint32_t css_ovs_detect_cmd_state;


/* get_data_send frame */
extern ts_ovsp_get_data_frame get_data_frame;

/* OVSP LS get_data response frame format */
extern ts_ovsp_data_resp_frame1 ls_resp_frame_format_1;   /* Response data frame format 1 */
extern ts_ovsp_data_resp_frame4 ls_resp_frame_format_4;   /* Response data frame format 4 */
extern ts_ovsp_data_resp_frame5 ls_resp_frame_format_5;   /* Response data frame format 5 */
extern ts_ovsp_data_resp_frame6 ls_resp_frame_format_6;   /* Response data frame format 6 */

/* OVSP HS get_data response frame format */
extern ts_ovsp_data_resp_frame1 hs_resp_frame_format_1;   /* Response data frame format 1 */
extern ts_ovsp_data_resp_frame2 hs_resp_frame_format_2;   /* Response data frame format 2 */
extern ts_ovsp_data_resp_frame3 hs_resp_frame_format_3;   /* Response data frame format 3 */
extern ts_ovsp_data_resp_frame4 hs_resp_frame_format_4;   /* Response data frame format 4 */
extern ts_ovsp_data_resp_frame5 hs_resp_frame_format_5;   /* Response data frame format 5 */
extern ts_ovsp_data_resp_frame6 hs_resp_frame_format_6;   /* Response data frame format 6 */

/* GET_SW_INFO Command frame */
extern ts_ovsp_get_sw_info_frame get_sw_info_frame;

/* SW_INFO response frame */
extern ts_ovsp_sw_info_response_frame sw_info_response_frame;


/* ---------- provided operations: ------------------------------------------ */
void ovsp_one_sensor_cmd_send(uint32_t const can_x_reg_addr, uint32_t const dest_can_ram_addr, te_ovsp_one_sensor_cmd_t const one_sensor_cmd);

void ovsp_get_sw_info_send(uint32_t const can_x_reg_addr, uint32_t const dest_can_ram_addr);

void ovsp_cam_cmd_send(uint32_t const can_x_reg_addr, uint32_t const dest_can_ram_addr, te_ovsp_cam_cmd_t const cam_cmd);

void ovsp_osarm_cmd_send(uint32_t const can_x_reg_addr, uint32_t const dest_can_ram_addr, boolean_t const osarm_request);

void ovsp_rearm_cmd_send(uint32_t const can_x_reg_addr, uint32_t const dest_can_ram_addr, boolean_t const rearm_request);

void ovsp_set_id_range_filter(uint32_t const can_ram_addr, uint32_t const id_range_start, uint32_t const id_range_stop);

void ovsp_set_param_send(uint32_t const can_x_reg_addr, uint32_t const dest_can_ram_addr);

void ovsp_test_discrete_send(uint32_t const can_x_reg_addr, uint32_t const dest_can_ram_addr, boolean_t const test_discrete_on);

void ovsp_triggered_test_send(uint32_t const can_x_reg_addr, uint32_t const dest_can_ram_addr, boolean_t const triggered_test_on,
                              uint32_t const test_speed);

void ovsp_get_data_send(uint32_t const can_x_reg_addr, uint32_t const dest_can_ram_addr);

void ovsp_set_param_build(void);

/* Read 6 Rx get_data response frame */
void ovsp_get_data_read(uint32_t const ovspx_reg_addr,uint32_t const src_ovspx_ram_addr, boolean_t const is_ovsp_ls);

/* Read Rx SW_INFO response frame */
void ovsp_get_sw_info_read(uint32_t const ovspx_reg_addr,uint32_t const src_ovspx_ram_addr);

/* OVSP_LS decode get_data response frame thanks to the ID */
void ovsp_get_data_ls_decode(uint32_t const total_nb_frame_received);

/* OVSP_HS decode get_data response frame thanks to the ID */
void ovsp_get_data_hs_decode(uint32_t const total_nb_frame_received);

/* OVSP_HS decode get_data response frame thanks to the ID */
void ovsp_get_sw_info_decode(uint32_t const total_nb_frame_received);

/* OVSP_LS update shared memory status */
void ovsp_update_ls_shmem_status(void);

/* OVSP_HS update shared memory status */
void ovsp_update_hs_shmem_status(void);

/* OVSP update internal status */
void ovsp_update_internal_status(boolean_t is_ovsp_ls);

/* Update ngosx shared memory status */
void ovsp_update_ngosx_status(uint32_t const can_x_reg_addr);

/* Update ntlosx shared memory status */
void ovsp_update_ntlosx_status(uint32_t const can_x_reg_addr);

/* Function to swap endianess of data  */
void swap_data_cmd(const uint32_t * p_data_src_addr, const uint8_t * p_data_swap_addr);

/* Function to transmit frames from UOD  */
void ovsp_uod_send(uint32_t const can_x_reg_addr, uint32_t const dest_can_ram_addr);

/* Function for OVS_DETECT service */
void ovsp_ovs_detect(const boolean_t channel_is_a);

/* Check for erroneous css cmd */
void ovsp_ovs_detect_check_css_cmd( uint32_t * const css_cmd_erroneous);

/* ovs_detect for normal mode opp channel health ok */
void ovsp_ovs_detect_normal_mode(const boolean_t channel_is_a);

/* OVSP function for faulty mode opp channel health Nok  */
void ovsp_ovs_detect_faulty_mode(const boolean_t channel_is_a);

void ovsp_reset_rxs_buffer_monitor(void);
void ovsp_reset_txs_buffer_monitor(void);

#endif /* OVSP_PRIVATE_H */
