/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef OVSP_FRAME_H
#define OVSP_FRAME_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
#define OVSP_GETSWINFO_UNUSED_SIZE (uint8_t)7 /* number of datas byte equal to 0 in GET SW INFO frame */

/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t s_identifier;                            /* Frame identifier */
   uint8_t  s_unused[OVSP_GETSWINFO_UNUSED_SIZE];    /* Frame data unused ( = 0 ) */
   uint8_t  s_oss_pu_comp_number;                    /* OSS_PU CAN compatibility number */
   uint32_t s_length;                                /* Frame number of used bytes */
}
ts_ovsp_get_sw_info_frame;

typedef struct
{
   uint32_t s_identifier;          /* Frame identifier */
   uint8_t  s_ovsp_side;           /* OVSP side (HS / LS) */
   uint8_t  s_sw_version_major;    /* SW Version (X: Major) */
   uint8_t  s_sw_version_minor;    /* SW Version (Y: Minor) */
   uint8_t  s_sw_version_fix_id;   /* SW Version (Z: Fix Id) */
   uint16_t s_ovsp_config_crc;     /* OVSP Config 16-bit CRC */
   uint8_t  s_unused;              /* Frame data unused ( = 0 ) */
   uint8_t  s_oss_pu_comp_number;  /* OSS_PU CAN compatibility number */
   uint32_t s_length;              /* Frame number of used bytes */
}
ts_ovsp_sw_info_response_frame;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   /* Command frame OK => 0xABCDEF01 */
   /* Other values => Invalid */
   uint32_t  s_command_frame;
   uint16_t  s_ovsp_crc;     /* OVSP Config 16-bit CRC  */
   uint16_t  s_data_unused;  /* Frame data unused ( = 0 ) */
   uint32_t s_length;        /* Frame number of used bytes */
}
ts_ovsp_set_param_frame1;

typedef struct
{
   uint32_t s_identifier;           /* Frame identifier */
   uint8_t  s_ntl_threshold_inhib;  /* OVS_NTLThresholdInhib */
   uint8_t  s_ng_inhib;             /* OVS_NGInhib */
   uint8_t  s_css_inhib;            /* OVS_CSSInhib */
   uint8_t  s_one_sensor_ng_inhib;  /* OVS_OneSensorNGInhib */
   uint8_t  s_one_sensor_ntl_inhib; /* OVS_OneSensorNTLInhib */
   uint8_t  s_interlock_inhib;      /* Interlock_Inhib */
   uint16_t s_unused;               /* Frame data unused ( = 0 ) */
   uint32_t s_length;               /* Frame number of used bytes */
}
ts_ovsp_set_param_frame2;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   uint8_t  s_ntlos1_nl; /* NTLOS1_NL */
   uint8_t  s_ntlos1_nh; /* NTLOS1_NH */
   uint8_t  s_ntlos2_nl; /* NTLOS2_NL */
   uint8_t  s_ntlos2_nh; /*NTLOS2_NH */
   uint8_t  s_ntl_ovs_thresd_n; /* NTL_OVSTHRESD_N */
   uint8_t  s_ntl_ovs_funct; /* NTL_OVS_FUNCTION */
   uint16_t s_unused;  /* Frame data unused ( = 0 ) */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_set_param_frame3;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   uint8_t  s_ngos1_nl;  /* NGOS1_NL */
   uint8_t  s_ngos1_nh;  /* NGOS1_NH */
   uint8_t  s_ngos2_nl;  /* NGOS2_NL */
   uint8_t  s_ngos2_nh;  /* NGOS2_NH */
   uint8_t  s_ng_ovs_thresd_n;  /* NG_OVSTHRESD_N */
   uint8_t  s_unused1;  /* Frame data unused ( = 0 ) */
   uint16_t s_unused2;  /* Frame data unused ( = 0 ) */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_set_param_frame4;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   uint8_t  s_ng_ovs_thresd_0; /* NG_OVSTHRESD_Threshold [0] */
   uint8_t  s_ng_ovs_thresd_1; /* NG_OVSTHRESD_Threshold [1] */
   uint8_t  s_ng_ovs_thresd_2; /* NG_OVSTHRESD_Threshold [2] */
   uint8_t  s_ng_ovs_thresd_3; /* NG_OVSTHRESD_Threshold [3] */
   uint8_t  s_ng_ovs_thresd_4; /* NG_OVSTHRESD_Threshold [4] */
   uint8_t  s_ng_ovs_thresd_5; /* NG_OVSTHRESD_Threshold [5] */
   uint16_t s_unused;  /* Frame data unused ( = 0 ) */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_set_param_frame5;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   uint8_t  s_ntl_ovs_variable_threshold_0; /* NTL_OVSVARIABLE_Threshold [0] */
   uint8_t  s_ntl_ovs_variable_threshold_1; /* NTL_OVSVARIABLE_Threshold [1] */
   uint8_t  s_ntl_ovs_variable_threshold_2; /* NTL_OVSVARIABLE_Threshold [2] */
   uint8_t  s_ntl_ovs_variable_threshold_3; /* NTL_OVSVARIABLE_Threshold [3] */
   uint8_t  s_ntl_ovs_variable_threshold_4; /* NTL_OVSVARIABLE_Threshold [4] */
   uint8_t  s_ntl_ovs_variable_threshold_5; /* NTL_OVSVARIABLE_Threshold [5] */
   uint16_t s_unused; /* Frame data unused ( = 0 ) */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_set_param_frame6;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   float32_t  s_ngos1_timeout; /* NGOS1_Timeout*/
   float32_t  s_ngos1_100; /*  NGOS1_100 */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_set_param_frame7;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   float32_t  s_ngos2_timeout; /* NGOS2_Timeout */
   float32_t  s_ngos2_100; /* NGOS2_100 */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_set_param_frame8;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   float32_t  s_ntlos1_timeout;  /* NTLOS1_Timeout */
   float32_t  s_ntlos1_100; /* NTLOS1_100 */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_set_param_frame9;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   float32_t  s_ntlos2_timeout; /* NTLOS2_Timeout */
   float32_t  s_ntlos2_100; /* NTLOS2_100 */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_set_param_frame10;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   float32_t s_ntl_ovs_thresd_threshold; /* NTL_OVSTHRESD_Threshold */
   float32_t s_ntl_ovs_thresd_window; /* NTL_OVSTHRESD_Threshold */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_set_param_frame11;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   float32_t s_ng_ovs_thresd_threshold; /* NG_OVSTHRESD_Threshold */
   float32_t s_ng_ovs_thresd_window; /* NG_OVSTHRESD_Window */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_set_param_frame12;


typedef struct
{
   ts_ovsp_set_param_frame1  s_frame1;  /* Frame 1  format of set param command */
   ts_ovsp_set_param_frame2  s_frame2;  /* Frame 2  format of set param command */
   ts_ovsp_set_param_frame3  s_frame3;  /* Frame 3  format of set param command */
   ts_ovsp_set_param_frame4  s_frame4;  /* Frame 4  format of set param command */
   ts_ovsp_set_param_frame5  s_frame5;  /* Frame 5  format of set param command */
   ts_ovsp_set_param_frame6  s_frame6;  /* Frame 6  format of set param command */
   ts_ovsp_set_param_frame7  s_frame7;  /* Frame 7  format of set param command */
   ts_ovsp_set_param_frame8  s_frame8;  /* Frame 8  format of set param command */
   ts_ovsp_set_param_frame9  s_frame9;  /* Frame 9  format of set param command */
   ts_ovsp_set_param_frame10 s_frame10; /* Frame 10 format of set param command */
   ts_ovsp_set_param_frame11 s_frame11; /* Frame 11 format of set param command */
   ts_ovsp_set_param_frame12 s_frame12; /* Frame 11 format of set param command */
}
ts_ovsp_set_param_frames;

typedef struct
{
   uint32_t s_identifier;              /* Frame identifier */
                                       /* TRIG TEST data */
                                       /* Trig test ON  => 0x12345678 */
                                       /* Trig test OFF => 0x87654321 */
   uint32_t  s_data_trig_test_on_off;
   uint32_t  s_data_test_speed;        /* test speed %NG or % NTL */
   uint32_t s_length;                  /* Frame number of used bytes */
}
ts_ovsp_triggered_test_cmd_frame;

typedef struct
{
   uint32_t s_identifier;        /* Frame identifier */
                                 /* Discrete TEST data */
                                 /* Test discrete close circuit  => 0xA0A1A2A3 */
                                 /* Test off => Other values */
   uint32_t  s_data_dicr_test;
   uint32_t  s_data_unused;      /* unused data (4 x 8bit) */
   uint32_t s_length;            /* Frame number of used bytes */
}
ts_ovsp_discrete_test_cmd_frame;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   /* OS key */
   /* CMD1: 0x0A0A0A0A (OFF), 0xA1A1A1A1 (ON) */
   /* CMD2: 0x0B0B0B0B (OFF), 0xB1B1B1B1 (ON) */
   /* Invalid => Other values                 */
   uint32_t  s_data_os_key;
   /* AS key */
   /* CMD1: 0x0C0C0C0C (OFF), 0xC1C1C1C1 (ON) */
   /* CMD2: 0x0D0D0D0D (OFF), 0xD1D1D1D1 (ON) */
   /* Invalid => Other values                 */
   uint32_t  s_data_as_key;
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_cam_cmd_frame;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   /* OS key */
   /* OSARM ON => 0xE1E2E3E4 */
   /* OSARM OFF => Other values */
   uint32_t  s_data_os_key;
   uint32_t  s_data_unused; /* unused data */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_osarm_cmd_frame;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   /* OS key */
   /* REARM request => 0xF1F2F3F4 */
   /* Invalid => Other values */
   uint32_t  s_data_os_key;
   uint32_t  s_data_unused; /* unused data */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_rearm_cmd_frame;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   /* NTL */
   /* One sensor authorized => 0xEEEE1111 */
   /* Two sensors configuration => 0xEEEE2222 */
   /* No change => Other values                 */
   uint32_t  s_data_ntl_sensor_auth;
   /* NG */
   /* One sensor authorized => 0xFFFF1111 */
   /* Two sensors configuration => 0xFFFF2222 */
   /* No change => Other values                 */
   uint32_t  s_data_ng_sensor_auth;
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_one_sensor_cmd_frame;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   uint32_t  s_unused1; /* unused data */
   uint32_t  s_unused2; /* unused data */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_get_data_frame;

typedef struct
{
   uint8_t  s_cmd1_status; /* CMD1 Status (0=OFF ; 1=ON) */
   uint8_t  s_cmd2_status; /* CMD2 Status (0=OFF ; 1=ON) */
   uint8_t  s_mode;        /* MODE (0=Operational ; 1=Triggered test) */
   uint8_t  s_ovsp_config_reception; /* OVSP Config Reception (0=OK ; 1=NOK) */
   uint8_t  s_ovsp_config_integrity; /* OVSP Config Integrity (0=OK ; 1=NOK) */
   uint8_t  s_unused1; /* unused data */
   uint16_t s_unused2; /* unused data */
}
ts_ovs_status;

typedef struct
{
   uint8_t  s_ngos1_out_of_time;          /* NGOS1 out of time (0=NO ; 1=YES) */
   uint8_t  s_ngos2_out_of_time;          /* NGOS2 out of time (0=NO ; 1=YES) */
   uint8_t  s_ngos1_updated;              /* NGOS1 updated (0=NO ; 1=YES) */
   uint8_t  s_ngos2_updated;              /* NGOS2 updated (0=NO ; 1=YES) */
   uint8_t  s_ngos1_out_of_range_high;    /* NGOS1 out of range high (0=NO ; 1=YES) */
   uint8_t  s_ngos2_out_of_range_high;    /* NGOS2 out of range high (0=NO ; 1=YES) */
   uint8_t  s_incons_ngos1_ngos2;         /* Inconsistency NGOS1 NGOS2 (0=NO ; 1=YES) */
   uint8_t s_unused;                      /* unused data */
}
ts_ng_status;

typedef struct
{
   uint8_t  s_ntlos1_out_of_time;         /* NTLOS1 out of time (0=NO ; 1=YES) */
   uint8_t  s_ntlos2_out_of_time;         /* NTLOS2 out of time (0=NO ; 1=YES) */
   uint8_t  s_ntlos1_updated;             /* NTLOS1 updated (0=NO ; 1=YES) */
   uint8_t  s_ntlos2_updated;             /* NTLOS2 updated (0=NO ; 1=YES) */
   uint8_t  s_ntlos1_out_of_range_high;   /* NTLOS1 out of range high (0=NO ; 1=YES) */
   uint8_t  s_ntlos2_out_of_range_high;   /* NTLOS2 out of range high (0=NO ; 1=YES) */
   uint8_t  s_incons_ntlos1_ntlos2;       /* Inconsistency NTLOS1 NTLOS2 (0=NO ; 1=YES) */
   uint8_t s_unused;                      /* unused data */
}
ts_ntl_status;

typedef struct
{
   uint8_t  s_dininhib_val;/* DININHIB value */
   uint8_t  s_osrearm_val;/* OSREARM value */
   uint8_t  s_ntlostest;/* NTLOSTEST value */
   uint32_t s_unused1; /* unused data */
   uint8_t  s_unused2; /* unused data */
}
ts_discrete_input;

typedef struct
{
   uint8_t  s_doutinhib_fb;/* DOUTINHIB_FB */
   uint8_t  s_camlow2_fb_or_unused;/* OVS HS: CAMLOW2_FB, OVS LS: Unused */
   uint8_t  s_osarm_fb_or_unused;/* OVS HS: OSARM_FB, OVS LS: Unused */
   uint32_t s_unused1;/* unused data */
   uint8_t  s_unused2;/* unused data */
}
ts_discrete_output;

typedef union
{
   uint32_t int32_val;
   float32_t float32_val;
}
tu_int_float;


typedef struct
{
   uint32_t           s_identifier; /* Frame identifier */
   ts_ovs_status      s_ovs_status;/* OVS Status */
   ts_ng_status       s_ng_status;/* NG_Status */
   ts_ntl_status      s_ntl_status;/* NTL_Status */
   ts_discrete_input  s_discrete_input;/* Discrete inputs */
   ts_discrete_output s_discrete_output;/* Discrete outputs */
   uint8_t            s_unused;/* unused data */
   uint16_t           s_ovsp_config_crc;/* OVSP Config 16-bit CRC (last computed) */
   uint32_t           s_length;  /* Frame number of used bytes */
}
ts_ovsp_data_resp_frame1;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   tu_int_float s_ngos1_measure;/* NGOS1_Measure (Freq en Hz) */
   tu_int_float s_ngos2_measure;/* NGOS2_Measure (Freq en Hz) */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_data_resp_frame2;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   tu_int_float s_ntlos1_measure;/* NTLOS1_Measure (Freq en Hz) */
   tu_int_float s_ntlos2_measure;/* NTLOS2_Measure (Freq en Hz) */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_data_resp_frame3;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   tu_int_float s_ovs_hs_cam_vload;/* OVS HS: CAM Vload / OVS LS: Unused */
   tu_int_float s_ovs_hs_cam_hs_current;/* OVS HS: CAM HS current / OVS LS: Unused */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_data_resp_frame4;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   tu_int_float s_ovs_ls_cam_ls_current;/* OVS HS: CAM LS current / OVS LS: Unused */
   tu_int_float s_ovs_temperature;/* Temperature */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_data_resp_frame5;

typedef struct
{
   uint32_t s_identifier; /* Frame identifier */
   tu_int_float s_test_speed_measure;/* Test Speed Measure (% NG or % NTL) */
   uint32_t s_unused;/* unused data */
   uint32_t s_length;  /* Frame number of used bytes */
}
ts_ovsp_data_resp_frame6;

typedef struct
{
   ts_ovsp_data_resp_frame1 s_frame1; /* Frame 1 format of data response */
   ts_ovsp_data_resp_frame2 s_frame2; /* Frame 2 format of data response */
   ts_ovsp_data_resp_frame3 s_frame3; /* Frame 3 format of data response */
   ts_ovsp_data_resp_frame4 s_frame4; /* Frame 4 format of data response */
   ts_ovsp_data_resp_frame5 s_frame5; /* Frame 5 format of data response */
   ts_ovsp_data_resp_frame6 s_frame6; /* Frame 6 format of data response */
}
ts_ovsp_data_response_frames;

/* Bits field of OVSP HS internal fault word */
typedef struct
{
   uint32_t s_status_cmd1               :1;  /* 31: OFF = 0 ; ON = 1 */
   uint32_t s_status_cmd2               :1;  /* 30: OFF = 0 ; ON = 1 */
   uint32_t s_ovs_mode                  :1;  /* 29: Operational = 0 ; Triggerred test = 1 */
   uint32_t s_ovs_config_reception      :1;  /* 28: OK = 0 ; NOK = 1 */
   uint32_t s_ovs_config_integrity      :1;  /* 27: OK = 0 ; NOK = 1 */
   uint32_t s_dininhib_state            :1;  /* 26: State of the DININHIB discrete */
   uint32_t s_osrearm_state             :1;  /* 25: State of the OSREARM discrete */
   uint32_t s_ntlostest_state           :1;  /* 24: State of the NTLOSTEST discrete */
   uint32_t s_camlow2_fb                :1;  /* 23: HV OVSP only */
   uint32_t s_osarm_fb                  :1;  /* 22: HS OVSP only */
   uint32_t s_spare_21                  :1;  /* 21: Spare */
   uint32_t s_time_out_ntlos1           :1;  /* 20: NO = 0 ; YES = 1 */
   uint32_t s_time_out_ntlos2           :1;  /* 19: NO = 0 ; YES = 1 */
   uint32_t s_meas_update_ntlos1        :1;  /* 18: No update = 0 ; Measure was updated since last read = 1 */
   uint32_t s_meas_update_ntlos2        :1;  /* 17: No update = 0 ; Measure was updated since last read = 1 */
   uint32_t s_out_of_range_high_ntlos1  :1;  /* 16: NO = 0 ; One period exceeded max frequency = 1 */
   uint32_t s_out_of_range_high_ntlos2  :1;  /* 15: NO = 0 ; One period exceeded max frequency = 1 */
   uint32_t s_spare_14_to_13            :2;  /* 14 to 13: Spare */
   uint32_t s_time_out_ngos1            :1;  /* 12: NO = 0 ; YES = 1 */
   uint32_t s_time_out_ngos2            :1;  /* 11: NO = 0 ; YES = 1 */
   uint32_t s_meas_update_ngos1         :1;  /* 10: No update = 0 ; Measure was updated since last read = 1 */
   uint32_t s_meas_update_ngos2         :1;  /* 09: No update = 0 ; Measure was updated since last read = 1 */
   uint32_t s_out_of_range_high_ngos1   :1;  /* 08: NO = 0 ; One period exceeded max frequency = 1 */
   uint32_t s_out_of_range_high_ngos2   :1;  /* 07: NO = 0 ; One period exceeded max frequency = 1 */
   uint32_t s_spare_06_to_00            :7;  /* 06 to 00: Spare */
}
ts_ovs_hs_ls_intern_fault_word_u_bit;


/* OVSP HS internal fault word */
typedef union
{
   uint32_t u_word;                             /* OVSP HS internal fault word accessed by 32-bit word */
   ts_ovs_hs_ls_intern_fault_word_u_bit u_bit;  /* OVSP HS internal fault word accessed bit by bit */
}
tu_ovs_hs_ls_intern_fault_word;




/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* ---------- provided operations: ------------------------------------------ */

#endif /* OVSP_FRAME_H */
