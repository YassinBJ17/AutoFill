/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_IMU_SWVAR_H
#define LIBBSP_IMU_SWVAR_H

#include "LIBBSP_IMU_RAMTIC.h"

/*==== Definitions =====================================================================*/

#define C_IMU_SWVAR_IMU_IDENT       (C_IMU_sw_var_40b_0)
#define C_IMU_SWVAR_CMP_VERSION     (C_IMU_sw_var_40b_1)
#define C_IMU_SWVAR_GANAV_IDENT     (C_IMU_sw_var_40b_2)
#define C_IMU_SWVAR_SW_VERSION      (C_IMU_sw_var_40b_3)
#define C_IMU_SWVAR_ON_OFF_CNT      (C_IMU_sw_var_40b_4)
#define C_IMU_SWVAR_OP_TIME         (C_IMU_sw_var_40b_5)
#define C_IMU_SWVAR_SHM_STATE       (C_IMU_sw_var_40b_6)
#define C_IMU_SWVAR_COMP_STATUS     (C_IMU_sw_var_40b_7)
#define C_IMU_SWVAR_BOARD_STATUS    (C_IMU_sw_var_40b_8)

#define C_IMU_SWVAR_SW_STATUS1      (C_IMU_sw_var_40b_10)
#define C_IMU_SWVAR_SW_STATUS2      (C_IMU_sw_var_40b_11)
#define C_IMU_SWVAR_SW_STATUS3      (C_IMU_sw_var_40b_12)
#define C_IMU_SWVAR_LOCAL_TEMP      (C_IMU_sw_var_40b_13)
#define C_IMU_SWVAR_REMOTE_TEMP     (C_IMU_sw_var_40b_14)

#define C_IMU_SWVAR_BSI_IDENT       (C_IMU_sw_var_40b_20)
#define C_IMU_SWVAR_SSI_IDENT       (C_IMU_sw_var_40b_21)
#define C_IMU_SWVAR_GYR_IDENT0      (C_IMU_sw_var_40b_22)
#define C_IMU_SWVAR_GYR_IDENT1      (C_IMU_sw_var_40b_23)
#define C_IMU_SWVAR_GYR_IDENT2      (C_IMU_sw_var_40b_24)
#define C_IMU_SWVAR_ACC_IDENT0      (C_IMU_sw_var_40b_25)
#define C_IMU_SWVAR_ACC_IDENT1      (C_IMU_sw_var_40b_26)
#define C_IMU_SWVAR_ACC_IDENT2      (C_IMU_sw_var_40b_27)
#define C_IMU_SWVAR_IDA_IDENT       (C_IMU_sw_var_40b_28)
#define C_IMU_SWVAR_A600_IDENT      (C_IMU_sw_var_40b_29)
#define C_IMU_SWVAR_HRG_IDENT       (C_IMU_sw_var_40b_30)
#define C_IMU_SWVAR_MEG_VERSION     (C_IMU_sw_var_40b_31)

#define C_IMU_SWVAR_ADC1_SAMP1_2    (C_IMU_sw_var_40b_33)
#define C_IMU_SWVAR_ADC1_SAMP3_4    (C_IMU_sw_var_40b_34)
#define C_IMU_SWVAR_ADC1_SAMP5_6    (C_IMU_sw_var_40b_35)
#define C_IMU_SWVAR_ADC1_SAMP7_0    (C_IMU_sw_var_40b_36)
#define C_IMU_SWVAR_ADC2_SAMP1_2    (C_IMU_sw_var_40b_37)
#define C_IMU_SWVAR_ADC2_SAMP3_4    (C_IMU_sw_var_40b_38)
#define C_IMU_SWVAR_ADC2_SAMP5_6    (C_IMU_sw_var_40b_39)
#define C_IMU_SWVAR_ADC2_SAMP7_0    (C_IMU_sw_var_40b_40)
#define C_IMU_SWVAR_ADC3_SAMP1_2    (C_IMU_sw_var_40b_41)
#define C_IMU_SWVAR_ADC3_SAMP3_4    (C_IMU_sw_var_40b_42)
#define C_IMU_SWVAR_ADC3_SAMP5_6    (C_IMU_sw_var_40b_43)
#define C_IMU_SWVAR_ADC3_SAMP7_0    (C_IMU_sw_var_40b_44)
#define C_IMU_SWVAR_ADC4_SAMP1_2    (C_IMU_sw_var_40b_45)
#define C_IMU_SWVAR_ADC4_SAMP3_4    (C_IMU_sw_var_40b_46)
#define C_IMU_SWVAR_ADC4_SAMP5_6    (C_IMU_sw_var_40b_47)
#define C_IMU_SWVAR_ADC4_SAMP7_0    (C_IMU_sw_var_40b_48)
#define C_IMU_SWVAR_ADC5_SAMP1_2    (C_IMU_sw_var_40b_49)
#define C_IMU_SWVAR_ADC5_SAMP3_4    (C_IMU_sw_var_40b_50)
#define C_IMU_SWVAR_ADC5_SAMP5_6    (C_IMU_sw_var_40b_51)
#define C_IMU_SWVAR_ADC5_SAMP7_0    (C_IMU_sw_var_40b_52)
#define C_IMU_SWVAR_ADC6_SAMP1_2    (C_IMU_sw_var_40b_53)
#define C_IMU_SWVAR_ADC6_SAMP3_4    (C_IMU_sw_var_40b_54)
#define C_IMU_SWVAR_ADC6_SAMP5_6    (C_IMU_sw_var_40b_55)
#define C_IMU_SWVAR_ADC6_SAMP7_0    (C_IMU_sw_var_40b_56)
#define C_IMU_SWVAR_ADC7_SAMP1_2    (C_IMU_sw_var_40b_57)
#define C_IMU_SWVAR_ADC7_SAMP3_4    (C_IMU_sw_var_40b_58)
#define C_IMU_SWVAR_ADC7_SAMP5_6    (C_IMU_sw_var_40b_59)
#define C_IMU_SWVAR_ADC7_SAMP7_0    (C_IMU_sw_var_40b_60)
#define C_IMU_SWVAR_ADC_ERROR_1_4   (C_IMU_sw_var_40b_61)
#define C_IMU_SWVAR_ADC_ERROR_5_6   (C_IMU_sw_var_40b_62)
#define C_IMU_SWVAR_SYNTH_IMU_SW    (C_IMU_sw_var_40b_63)


#endif
