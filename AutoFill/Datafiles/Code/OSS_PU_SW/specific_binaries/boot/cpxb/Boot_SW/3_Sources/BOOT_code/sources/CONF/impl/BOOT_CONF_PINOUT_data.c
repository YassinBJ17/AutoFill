/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : SIUL2 configuration (PIN)
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
/* none */

/* ---------- include required interface: ----------------------------------- */

#include "BOOT_CONF_public.h"

const ts_PAD_IO_CFG c_conf_pad_io_st =
{
   {
      { 0, 0x00190000 }, /* IT_PWD_N    PA[0] */
      { 1, 0x12180000 }, /* CCDL_SPARE_OUT1    PA[1] */
      { 2, 0x00390000 }, /* SELECT_XRB_CALRES_RX_N    PA[2] */
      { 3, 0x12180000 }, /* SELECT_XRB_CALRES_TX1    PA[3] */
      { 4, 0x00190000 }, /* IT_PWD_N    PA[4] */
      { 5, 0x00000000 }, /* CC_JTAG_JCOMP    PA[5] */
      { 6, 0x00000000 }, /* CC_JTAG_TCK    PA[6] */
      { 7, 0x00000000 }, /* CC_JTAG_TMS    PA[7] */
      { 8, 0x00000000 }, /* CC_JTAG_TDI    PA[8] */
      { 9, 0x00000000 }, /* CC_JTAG_TDO    PA[9] */
      { 10, 0x12180002 }, /* RS422_EECU_TX    PA[10] */
      { 11, 0x00190000 }, /* PIN not attribute */
      { 12, 0x12180004 }, /* SPI_ADC2_CS_N    PA[12] */
      { 13, 0x12180004 }, /* SPI_ADC2_SCK    PA[13] */
      { 14, 0x12180000 }, /* MODEM_POWER_EN_OUTMPC    PA[14] */
      { 15, 0x12180000 }, /* CCDL_SPARE_OUT2    PA[15] */
      { 16, 0x00390000 }, /* RS422_EECU_TX (loopback GPI)    PB[0] */
      { 17, 0x00190000 }, /* NOT_USED    PB[1] */
      { 18, 0x00190000 }, /* NOT_USED    PB[2] */
      { 19, 0x00190000 }, /* NOT_USED    PB[3] */
      { 20, 0x00390000 }, /* SM_STATE_PH1    PB[4] */
      { 21, 0x00390000 }, /* SM_STATE_PH2    PB[5] */
      { 22, 0x00190000 }, /* NOT_USED    PB[6] */
      { 23, 0x00190000 }, /* NOT_USED    PB[7] */
      { 24, 0x12180000 }, /* PBIT_D_CLEAR    PB[8] */
      { 25, 0x00190000 }, /* PBIT_OVD_P3V3_PLD_CDE    PB[9] */
      { 26, 0x00190000 }, /* FCN_P15V0_STATUS    PB[10] */
      { 27, 0x12180001 }, /* MPC_ACCOM_CPU_ERROR0    PB[11] */
      { 28, 0x00190000 }, /* NOT_USED    PB[12] */
      { 29, 0x00190000 }, /* NOT_USED    PB[13] */
      { 30, 0x00190000 }, /* NOT_USED    PB[14] */
      { 31, 0x00190000 }, /* NOT_USED    PB[15] */
      { 32, 0x00190000 }, /* NOT_USED    PC[0] */
      { 33, 0x00390000 }, /* ENERGY_STORAGE_STATUS    PC[1] */
      { 34, 0x12180001 }, /* MPC_ACCOM_CPU_ERROR1    PC[2] */
      { 35, 0x12180003 }, /* SELECT_XRB_CALRES_TX2 => to be renamed "MUX_A0"    PC[3] */
      { 36, 0x12180000 }, /* MU_LOCAL_SHUTDOWN_OUTMPC_N    PC[4] */
      { 37, 0x00190000 }, /* NOT_USED    PC[5] */
      { 38, 0x32190001 }, /* I2C_IOEXP_SCL    PC[6] */
      { 39, 0x31190001 }, /* I2C_IOEXP_SDA    PC[7] */
      { 40, 0x00190000 }, /* PIN not attribute */
      { 41, 0x12180001 }, /* CAN_ECDR_TX    PC[9] */
      { 42, 0x22380001 }, /* CC_FEC_REF_CLK    PC[10] */
      { 43, 0x00190000 }, /* PIN not attribute */
      { 44, 0x00190000 }, /* PIN not attribute */
      { 45, 0x00190000 }, /* PIN not attribute */
      { 46, 0x22300001 }, /* CC_FEC_TX_EN    PC[14] */
      { 47, 0x22300001 }, /* CC_FEC_TXD0    PC[15] */
      { 48, 0x12180002 }, /* MPC_P0_CE_N_MOSI    PD[0] */
      { 49, 0x00390000 }, /* P0_DATA_READY    PD[1] */
      { 50, 0x00390000 }, /* P0_DEVICE_STATUS    PD[2] */
      { 51, 0x12180000 }, /* TC_MUX_A0    PD[3] */
      { 52, 0x12180000 }, /* TC_MUX_A1    PD[4] */
      { 53, 0x12180000 }, /* MUX_VRT_EN    PD[5] */
      { 54, 0x12180000 }, /* ATP_TST_MPC_F    PD[6] */
      { 55, 0x12180000 }, /* MPC_SPARE5    PD[7] */
      { 56, 0x12180000 }, /* MUX_VRT_A0    PD[8] */
      { 57, 0x12180003 }, /* MUX_VRT_A1 => to be renamed "MUX_A1"    PD[9] */
      { 58, 0x12180000 }, /* P0_RESET_FROM_MPC_N    PD[10] */
      { 59, 0x00390000 }, /* SM_STATE_PH3    PD[11] */
      { 60, 0x00190000 }, /* PIN not attribute */
      { 61, 0x12180002 }, /* P0_SCLK    PD[13] */
      { 62, 0x12180003 }, /* POT_MUX_EN0 => to be renamed "MUX_EN0"    PD[14] */
      { 63, 0x12180003 }, /* POT_MUX_EN1 => to be renamed "MUX_EN1"    PD[15] */
      { 64, 0x12180000 }, /* VRT_T1_PT100_PT1000_N    PE[0] */
      { 65, 0x12180002 }, /* P0_BUSY_CS_N    PE[1] */
      { 66, 0x00190000 }, /* NOT_USED    PE[2] */
      { 67, 0x00190000 }, /* NOT_USED    PE[3] */
      { 68, 0x12180000 }, /* VRT_T2_PT100_PT1000_N    PE[4] */
      { 69, 0x12180004 }, /* SPI_ADC1_CS_N    PE[5] */
      { 70, 0x00190000 }, /* PIN not attribute */
      { 71, 0x12180002 }, /* RS422_CCDL1_TX    PE[7] */
      { 72, 0x12180000 }, /* SELECT_SAI1_3_N    PE[8] */
      { 73, 0x12180000 }, /* SELECT_SAI2_4_N    PE[9] */
      { 74, 0x00190000 }, /* RTC_OUT    PE[10] */
      { 75, 0x12180000 }, /* VRT_TFF_PT100_PT1000_N    PE[11] */
      { 76, 0x22300001 }, /* CC_FEC_TXD1    PE[12] */
      { 77, 0x00390000 }, /* SM_STATE_PH2    PE[13] */
      { 78, 0x00190000 }, /* NOT_USED    PE[14] */
      { 79, 0x00580000 }, /* REF_2V5    PE[15] */
      { 80, 0x12180000 }, /* MU_NOR_WP_OUTMPC_N    PF[0] */
      { 81, 0x12180000 }, /* MU_SPARE_IN_OUTMPC    PF[1] */
      { 82, 0x12180000 }, /* MU_PROG_EN1_OUTMPC    PF[2] */
      { 83, 0x12180000 }, /* MU_PROG_EN2_OUTMPC    PF[3] */
      { 84, 0x12180000 }, /* MU_IRQ_OUTMPC_N    PF[4] */
      { 85, 0x00190000 }, /* CC_TEST_POINT_IRQ2    PF[5] */
      { 86, 0x12180000 }, /* MPC_SPARE4    PF[6] */
      { 87, 0x12180000 }, /* PWM_ENABLE    PF[7] */
      { 88, 0x12180000 }, /* FCN_POWER_EN_OUTMPC    PF[8] */
      { 89, 0x12180000 }, /* FCN_PHY_RST_OUTMPC_N    PF[9] */
      { 90, 0x12180000 }, /* MPC_SPARE3    PF[10] */
      { 91, 0x12180000 }, /* POT_MUX_A1    PF[11] */
      { 92, 0x12180000 }, /* MPC_SPARE2    PF[12] */
      { 93, 0x12180000 }, /* MPC_SPARE1    PF[13] */
      { 94, 0x12180000 }, /* CC_JTAG EVTO    PF[14] */
      { 95, 0x00190000 }, /* CC_JTAG EVTI0    PF[15] */
      { 96, 0x00580000 }, /* TMOT_IMON    PG[0] */
      { 97, 0x00580000 }, /* TMOT_VMON    PG[1] */
      { 98, 0x00580000 }, /* XR_DC_MON    PG[2] */
      { 99, 0x00580000 }, /* XRB_DC_MON    PG[3] */
      { 100, 0x00580000 }, /* LVDTA_B_S1_DC_MON    PG[4] */
      { 101, 0x00580000 }, /* LVDTA_B_S2_DC_MON    PG[5] */
      { 102, 0x00580000 }, /* LVDTC_S1_DC_MON    PG[6] */
      { 103, 0x00580000 }, /* LVDTC_S2_DC_MON    PG[7] */
      { 104, 0x00580000 }, /* COMEMANSVOI_MON    PG[8] */
      { 105, 0x00580000 }, /* P3V3_LOGIC_MON    PG[9] */
      { 106, 0x00390000 }, /* DIN1_N    PG[10] */
      { 107, 0x00390000 }, /* DIN2_N    PG[11] */
      { 108, 0x00390000 }, /* DIN3_N    PG[12] */
      { 109, 0x00390000 }, /* DINSHOP_N    PG[13] */
      { 110, 0x00390000 }, /* DINOLL_N    PG[14] */
      { 111, 0x00390000 }, /* DINTMODE_N    PG[15] */
      { 112, 0x00190000 }, /* PIN not attribute */
      { 113, 0x00190000 }, /* CC_TEST_POINT_IRQ1    PH[1] */
      { 114, 0x00390000 }, /* DIN4_N    PH[2] */
      { 115, 0x00390000 }, /* DIN5_N    PH[3] */
      { 116, 0x00390000 }, /* DIN6_N    PH[4] */
      { 117, 0x00190000 }, /* TEST_POINT_MPC    PH[5] */
      { 118, 0x00390000 }, /* MPC_ACCOM_OPP_CPU_FAIL_N    PH[6] */
      { 119, 0x12180007 }, /* CC_SPI0_CS0_N    PH[7] */
      { 120, 0x12180004 }, /* SPI_ADC1_CLK    PH[8] */
      { 121, 0x00190000 }, /* PIN not attribute */
      { 122, 0x00190000 }, /* MPC_SELECT    PH[10] */
      { 123, 0x12180000 }, /* CC_NEXUS_EVTO1    PH[11] */
      { 124, 0x00190000 }, /* CC_TEST_POINT_IRQ8    PH[12] */
      { 125, 0x00190000 }, /* NOT_USED    PH[13] */
      { 126, 0x12180004 }, /* SPI_ADC1_MOSI    PH[14] */
      { 127, 0x00190000 }, /* NOT_USED    PH[15] */
      { 128, 0x00390000 }, /* DIN7_N    PI[0] */
      { 129, 0x00390000 }, /* DIN8_N    PI[1] */
      { 130, 0x00190000 }, /* NOT_USED    PI[2] */
      { 131, 0x00190000 }, /* NOT_USED    PI[3] */
      { 132, 0x00390000 }, /* DIN13_N    PI[4] */
      { 133, 0x00390000 }, /* DIN14_N    PI[5] */
      { 134, 0x00390000 }, /* DIN15_N    PI[6] */
      { 135, 0x00390000 }, /* DIN16_N    PI[7] */
      { 136, 0x00390000 }, /* CCDL_SPARE_IN1    PI[8] */
      { 137, 0x00390000 }, /* CCDL_SPARE_IN1    PI[9] */
      { 138, 0x00390000 }, /* DIN9_N    PI[10] */
      { 139, 0x00390000 }, /* DIN10_N    PI[11] */
      { 140, 0x00390000 }, /* DIN11_N    PI[12] */
      { 141, 0x00390000 }, /* DIN12_N    PI[13] */
      { 142, 0x22300001 }, /* CC_FEC_MDC    PI[14] */
      { 143, 0x21380001 }, /* CC_FEC_MDIO    PI[15] */
      { 144, 0x00190000 }, /* NOT_USED    PJ[0] */
      { 145, 0x00190000 }, /* NOT_USED    PJ[1] */
      { 146, 0x00190000 }, /* NOT_USED    PJ[2] */
      { 147, 0x00190000 }, /* NOT_USED    PJ[3] */
      { 148, 0x00190000 }, /* NOT_USED    PJ[4] */
      { 149, 0x00190000 }, /* CC_NEXUS_CLK_P    PJ[5] */
      { 150, 0x00190000 }, /* NOT_USED    PJ[6] */
      { 151, 0x00190000 }, /* CC_NEXUS_CLK_M    PJ[7] */
      { 152, 0x00190000 }, /* NOT_USED    PJ[8] */
      { 153, 0x00390000 }, /* EMAN    PJ[9] */
      { 154, 0x00390000 }, /* PBIT_COMDIN_LEVEL    PJ[10] */
      { 155, 0x00190000 }, /* PIN not attribute */
      { 156, 0x00190000 }, /* NFREQ2_MON    PJ[12] */
      { 157, 0x00390000 }, /* NFREQ3_MON    PJ[13] */
      { 158, 0x00390000 }, /* NFREQ4_MON    PJ[14] */
      { 159, 0x12180003 }, /* CC_SPI0_CLK    PJ[15] */
      { 160, 0x00390000 }, /* SVOI    PK[0] */
      { 161, 0x00190000 }, /* MPC_DECISION_MON    PK[1] */
      { 162, 0x00190000 }, /* NOT_USED    PK[2] */
      { 163, 0x00190000 }, /* NOT_USED    PK[3] */
      { 164, 0x00190000 }, /* NOT_USED    PK[4] */
      { 165, 0x00190000 }, /* NOT_USED    PK[5] */
      { 166, 0x00190000 }, /* NOT_USED    PK[6] */
      { 167, 0x00190000 }, /* MU_SECUR_ALERT_INMPC    PK[7] */
      { 168, 0x00190000 }, /* MU_SPARE_OUT_INMPC    PK[8] */
      { 169, 0x00190000 }, /* MU_OVERTEMP_INMPC    PK[9] */
      { 170, 0x00190000 }, /* MU_STATUS_INMPC    PK[10] */
      { 171, 0x00190000 }, /* NOT_USED    PK[11] */
      { 172, 0x00190000 }, /* NOT_USED    PK[12] */
      { 173, 0x12180003 }, /* CC_SPI0_MOSI    PK[13] */
      { 174, 0x00190000 }, /* NOT_USED    PK[14] */
      { 175, 0x00190000 }, /* MPC_PAN3_MON    PK[15] */
      { 176, 0x00190000 }, /* PIN not attribute */
      { 177, 0x12180001 }, /* CAN1_TX    PL[1] */
      { 178, 0x12180000 }, /* POT_MUX_A0    PL[2] */
      { 179, 0x12180000 }, /* SW_FORCE_DECISION_INACTIVE_N    PL[3] */
      { 180, 0x12180004 }, /* SPI_ADC3_CS_N    PL[4] */
      { 181, 0x00190000 }, /* PIN not attribute */
      { 182, 0x12180003 }, /* SPI_ADC3_MOSI    PL[6] */
      { 183, 0x12180003 }, /* SPI_ADC3_SCK    PL[7] */
      { 184, 0x00190000 }, /* NOT_USED    PL[8] */
      { 185, 0x00190000 }, /* CC_NEXUS_TX1_M    PL[9] */
      { 186, 0x00190000 }, /* NOT_USED    PL[10] */
      { 187, 0x00190000 }, /* CC_NEXUS_TX1_P    PL[11] */
      { 188, 0x00190000 }, /* NOT_USED    PL[12] */
      { 189, 0x00190000 }, /* CC_NEXUS_TX0_M    PL[13] */
      { 190, 0x00190000 }, /* NOT_USED    PL[14] */
      { 191, 0x00190000 }, /* CC_NEXUS_TX0_P    PL[15] */
      { 192, 0x00190000 }, /* PIN not attribute */
      { 193, 0x00190000 }, /* PIN not attribute */
      { 194, 0x00190000 }, /* PIN not attribute */
      { 195, 0x00190000 }, /* PIN not attribute */
      { 196, 0x00190000 }, /* NOT_USED    PM[4] */
      { 197, 0x00190000 }, /* POR_OPP_N    PM[5] */
      { 198, 0x22300001 }, /* CC_FEC_TXER    PM[6] */
      { 199, 0x00190000 }, /* CC_NEXUS_EVTI1    PM[7] */
      { 200, 0x00190000 }, /* NOT_USED    PM[8] */
      { 201, 0x12180004 }, /* SPI_ADC2_MOSI    PM[9] */
      { 202, 0x00190000 }, /* NOT_USED    PM[10] */
      { 203, 0x12180000 }, /* HP4_CMD_N    PM[11] */
      { 204, 0x00190000 }, /* NOT_USED    PM[12] */
      { 205, 0x12180000 }, /* REARM_PMA    PM[13] */
      { 206, 0x12180000 }, /* MPC_PBIT_SELECT_TEST1    PM[14] */
      { 207, 0x12180000 }, /* MPC_PBIT_SELECT_TEST2    PM[15] */
      { 208, 0x12180000 }, /* MPC_ACCOM_INCONSISTENT    PN[0] */
      { 209, 0x12180000 }, /* MPC_ACCOM_INCONSISTENT_N    PN[1] */
      { 210, 0x12180001 }, /* CAN_OVSP_HS_MPC_TX    PN[2] */
      { 211, 0x00190000 }, /* PIN not attribute */
      { 212, 0x00190000 }, /* MODEM_P15V0_STATUS    PN[4] */
      { 213, 0x00190000 }, /* PIN not attribute */
      { 214, 0x00190000 }, /* NOT_USED    PN[6] */
      { 215, 0x12180001 }, /* CAN_OVSP_LS_MPC_TX    PN[7] */
      { 216, 0x12180000 }, /* CAN1_TERM_EN    PN[8] */
      { 217, 0x12180000 }, /* CAN1_LBK_EN    PN[9] */
      { 218, 0x12180000 }, /* SGP3_MUX_A0    PN[10] */
      { 219, 0x12180000 }, /* SGP3_MUX_A1    PN[11] */
      { 220, 0x12180000 }, /* SG2_5B_MUX_A0    PN[12] */
      { 221, 0x12180000 }, /* SG2_5B_MUX_A1    PN[13] */
      { 222, 0x12180000 }, /* SG1_34_MUX_A0    PN[14] */
      { 223, 0x12180000 }, /* SG1_34_MUX_A1    PN[15] */
      { 224, 0x12180000 }, /* PBIT_TC_EN    PQ[0] */
      { 225, 0x12180000 }, /* PBIT_XR_XRB_EXC_OPEN_N    PQ[1] */
      { 226, 0x12180000 }, /* PBIT_LVDTA_B_EXC_OPEN_N    PQ[2] */
      { 227, 0x12180000 }, /* PBIT_LVDTC_EXC_OPEN_N    PQ[3] */
      { 228, 0x12180000 }, /* PBIT_EMAN_SVOI_FORCE_OPEN    PQ[4] */
      { 229, 0x12180000 }, /* PBIT_COMDIN_FORCE_OPEN_N    PQ[5] */
      { 230, 0x12180000 }, /* PBIT_EMAN_SVOI_FORCE_CLOSED    PQ[6] */
      { 231, 0x12180000 }, /* PBIT_DIN1_16_FORCE_CLOSED    PQ[7] */
      { 232, 0x12180000 }, /* PBIT_CALRES_RETURN_OPEN_N    PQ[8] */
      { 233, 0x12180000 }, /* SW28V_PBIT_SWITCH_LS    PQ[9] */
      { 234, 0x12180000 }, /* SW28V_PBIT_SWITCH_HS    PQ[10] */
      { 235, 0x12180000 }, /* SW28V_PBIT_DIODE    PQ[11] */
      { 236, 0x12180000 }, /* BOOST_PBIT    PQ[12] */
      { 237, 0x32190004 }, /* I2C_TPIB_SCL    PQ[13] */
      { 238, 0x00190000 }, /* NOT_USED    PQ[14] */
      { 239, 0x31190001 }, /* I2C_TPIB_SDA    PQ[15] */
      { 240, 0x12180000 }, /* DEBUG_GPIO_SW1_5V    PX[2] */
      { 241, 0x00580000 }, /* MPC_SM_CURRENT_MON    PR[0] */
      { 242, 0x00580000 }, /* MPC_SM_VOLTAGE_MON    PR[1] */
      { 243, 0x00190000 }, /* NOT_USED    PR[2] */
      { 244, 0x00580000 }, /* MPC_P28V_MON    PR[3] */
      { 245, 0x00580000 }, /* MPC_HP4_CURRENT_MON    PR[4] */
      { 246, 0x00580000 }, /* MPC_HP4_VOLTAGE_MON    PR[5] */
      { 247, 0x00190000 }, /* NOT_USED    PR[6] */
      { 248, 0x00580000 }, /* MPC_SPARE6    PR[7] */
      { 249, 0x00580000 }, /* MPC_SPARE7    PR[8] */
      { 250, 0x00580000 }, /* PIN_PROG    PR[9] */
      { 251, 0x00190000 }, /* NOT_USED    PR[10] */
      { 252, 0x00190000 }, /* NOT_USED    PR[11] */
      { 253, 0x00190000 }, /* NOT_USED    PR[12] */
      { 254, 0x00190000 }, /* NOT_USED    PR[13] */
      { 255, 0x00190000 }, /* NOT_USED    PR[14] */
      { 256, 0x00190000 }, /* NOT_USED    PR[15] */
      { 257, 0x22390003 }, /* CC_EBI_DATA[30]    PS[0] */
      { 258, 0x22390003 }, /* CC_EBI_DATA[29]    PS[1] */
      { 259, 0x22390003 }, /* CC_EBI_DATA[28]    PS[2] */
      { 260, 0x22390003 }, /* CC_EBI_DATA[26]    PS[3] */
      { 261, 0x22390003 }, /* CC_EBI_DATA[24]    PS[4] */
      { 262, 0x22390003 }, /* CC_EBI_DATA[23]    PS[5] */
      { 263, 0x22390003 }, /* CC_EBI_DATA[20]    PS[6] */
      { 264, 0x22390003 }, /* CC_EBI_DATA[16]    PS[7] */
      { 265, 0x22390003 }, /* CC_EBI_DATA[31]    PS[8] */
      { 266, 0x22390003 }, /* CC_EBI_DATA[27]    PS[9] */
      { 267, 0x22390003 }, /* CC_EBI_DATA[21]    PS[10] */
      { 268, 0x22390003 }, /* CC_EBI_DATA[25]    PS[11] */
      { 269, 0x22390003 }, /* CC_EBI_DATA[19]    PS[12] */
      { 270, 0x22390003 }, /* CC_EBI_DATA[22]    PS[13] */
      { 271, 0x22390003 }, /* CC_EBI_DATA[18]    PS[14] */
      { 272, 0x22390003 }, /* CC_EBI_DATA[17]    PS[15] */
      { 273, 0x22390003 }, /* CC_EBI_DATA[14]    PT[0] */
      { 274, 0x22390003 }, /* CC_EBI_DATA[11]    PT[1] */
      { 275, 0x22390003 }, /* CC_EBI_DATA[12]    PT[2] */
      { 276, 0x22390003 }, /* CC_EBI_DATA[15]    PT[3] */
      { 277, 0x22390003 }, /* CC_EBI_DATA[8]    PT[4] */
      { 278, 0x22390003 }, /* CC_EBI_DATA[13]    PT[5] */
      { 279, 0x22390003 }, /* CC_EBI_DATA[4]    PT[6] */
      { 280, 0x22390003 }, /* CC_EBI_DATA[7]    PT[7] */
      { 281, 0x22390003 }, /* CC_EBI_DATA[3]    PT[8] */
      { 282, 0x22390003 }, /* CC_EBI_DATA[0]    PT[9] */
      { 283, 0x22390003 }, /* CC_EBI_DATA[5]    PT[10] */
      { 284, 0x22390003 }, /* CC_EBI_DATA[10]    PT[11] */
      { 285, 0x22390003 }, /* CC_EBI_DATA[9]    PT[12] */
      { 286, 0x22390003 }, /* CC_EBI_DATA[2]    PT[13] */
      { 287, 0x22390003 }, /* CC_EBI_DATA[1]    PT[14] */
      { 288, 0x22390003 }, /* CC_EBI_DATA[6]    PT[15] */
      { 289, 0x72390003 }, /* CC_EBI_CLK    PV[0] */
      { 290, 0x72390003 }, /* CC_EBI_OE_N    PV[1] */
      { 291, 0x72390003 }, /* CC_EBI_RD_WR_N    PV[2] */
      { 292, 0x72390003 }, /* CC_EBI_CS2_N    PV[3] */
      { 293, 0x72390003 }, /* CC_EBI_CS1_N    PV[4] */
      { 294, 0x72390003 }, /* CC_EBI_CS0_N    PV[5] */
      { 295, 0x72390002 }, /* CC_EBI_BDIP_N    PV[6] */
      { 296, 0x72390003 }, /* CC_EBI_TS_N    PV[7] */
      { 297, 0x72390003 }, /* CC_EBI_WE_N[0]    PV[8] */
      { 298, 0x72390003 }, /* CC_EBI_WE_N[1]    PV[9] */
      { 299, 0x72390003 }, /* CC_EBI_WE_N[2]    PV[10] */
      { 300, 0x72390003 }, /* CC_EBI_WE_N[3]    PV[11] */
      { 301, 0x62390003 }, /* CC_EBI_ADDR[12]    PV[12] */
      { 302, 0x62390003 }, /* CC_EBI_ADDR[14]    PV[13] */
      { 303, 0x62390003 }, /* CC_EBI_ADDR[13]    PV[14] */
      { 304, 0x62390003 }, /* CC_EBI_ADDR[15]    PV[15] */
      { 305, 0x62390003 }, /* CC_EBI_ADDR[20]    PW[0] */
      { 306, 0x62390003 }, /* CC_EBI_ADDR[16]    PW[1] */
      { 307, 0x62390003 }, /* CC_EBI_ADDR[17]    PW[2] */
      { 308, 0x62390003 }, /* CC_EBI_ADDR[18]    PW[3] */
      { 309, 0x62390003 }, /* CC_EBI_ADDR[22]    PW[4] */
      { 310, 0x62390003 }, /* CC_EBI_ADDR[19]    PW[5] */
      { 311, 0x62390003 }, /* CC_EBI_ADDR[26]    PW[6] */
      { 312, 0x62390003 }, /* CC_EBI_ADDR[23]    PW[7] */
      { 313, 0x62390003 }, /* CC_EBI_ADDR[21]    PW[8] */
      { 314, 0x62390003 }, /* CC_EBI_ADDR[25]    PW[9] */
      { 315, 0x62390003 }, /* CC_EBI_ADDR[27]    PW[10] */
      { 316, 0x62390003 }, /* CC_EBI_ADDR[28]    PW[11] */
      { 317, 0x62390003 }, /* CC_EBI_ADDR[30]    PW[12] */
      { 318, 0x62390003 }, /* CC_EBI_ADDR[29]    PW[13] */
      { 319, 0x62390003 }, /* CC_EBI_ADDR[31]    PW[14] */
      { 320, 0x62390003 }, /* CC_EBI_ADDR[24]    PW[15] */
      { 321, 0x00190000 }, /* NOT_USED    PX[0] */
      { 322, 0x12180000 }, /* DEBUG_GPIO_SW0_5V    PX[1] */
      { 323, 0x12180000 }, /* DEBUG_GPIO_SW2_5V    PX[3] */
      { 324, 0x12180000 }, /* DEBUG_GPIO_SW3_5V    PX[4] */
      { 325, 0x00190000 }, /* NOT_USED    PX[5] */
      { 326, 0x00190000 }, /* NOT_USED    PX[6] */
      { 327, 0x12180003 }, /* SPI_SINGENE_CS_LVDTC_N    PX[7] */
      { 328, 0x12180003 }, /* SPI_SINGENE_CS_LVDTA_B_N    PX[8] */
      { 329, 0x12180003 }, /* SPI_SINGENE_CS_XR_N    PX[9] */
      { 330, 0x12180003 }, /* SPI_SINGENE_MOSI    PX[10] */
      { 331, 0x12180003 }, /* SPI_SINGENE_SCK    PX[11] */
      { 332, 0x00580000 }, /* SGP3_EXC_MON    PX[12] */
      { 333, 0x00580000 }, /* SG1_34_EXC_MON    PX[13] */
      { 334, 0x00580000 }, /* SG2_5B_EXC_MON    PX[14] */
      { 335, 0x00580000 }, /* ECDR_EXC_MON    PX[15] */
      { 336, 0x00580000 }, /* POT1_2_EXC_MON    PY[0] */
      { 337, 0x00580000 }, /* POT3_EXC_MON    PY[1] */
      { 338, 0x00190000 }, /* NOT_USED    PY[2] */
      { 339, 0x00580000 }, /* PBIT_TC_CM_ADC    PY[3] */
      { 340, 0x12180000 }, /* CC_SRAM_ECC_MODE    PY[4] */
      { 341, 0x00000000 }, /* FIXED TO 0    VOID */
      { 342, 0x00000000 }, /* FIXED TO 0    VOID */
      { 343, 0x00000000 }, /* FIXED TO 0    VOID */
      { 344, 0x00000000 }, /* FIXED TO 0    VOID */
      { 345, 0x00000000 }, /* FIXED TO 0    VOID */
      { 346, 0x00000000 }, /* FIXED TO 0    VOID */
      { 347, 0x00000000 }, /* FIXED TO 0    VOID */
      { 348, 0x00000000 }, /* FIXED TO 0    VOID */
      { 349, 0x00000000 }, /* FIXED TO 0    VOID */
      { 350, 0x00000000 }, /* FIXED TO 0    VOID */
      { 351, 0x00000000 }, /* FIXED TO 0    VOID */
      { 352, 0x00000000 }, /* FIXED TO 0    VOID */
      { 353, 0x00000000 }, /* FIXED TO 0    VOID */
      { 354, 0x00000000 }, /* FIXED TO 0    VOID */
      { 355, 0x00000000 }, /* FIXED TO 0    VOID */
      { 356, 0x00000000 }, /* FIXED TO 0    VOID */
      { 357, 0x00000000 }, /* FIXED TO 0    VOID */
      { 358, 0x00000000 }, /* FIXED TO 0    VOID */
      { 359, 0x00000000 }, /* FIXED TO 0    VOID */
      { 360, 0x00000000 }, /* FIXED TO 0    VOID */
      { 361, 0x00000000 }, /* FIXED TO 0    VOID */
      { 362, 0x00000000 }, /* FIXED TO 0    VOID */
      { 363, 0x00000000 }, /* FIXED TO 0    VOID */
      { 364, 0x00000000 }, /* FIXED TO 0    VOID */
      { 365, 0x00000000 }, /* FIXED TO 0    VOID */
      { 366, 0x00000000 }, /* FIXED TO 0    VOID */
      { 367, 0x00000000 }, /* FIXED TO 0    VOID */
      { 368, 0x00000000 }, /* FIXED TO 0    VOID */
      { 369, 0x00000000 }, /* FIXED TO 0    VOID */
      { 370, 0x00000000 }, /* FIXED TO 0    VOID */
      { 371, 0x00000000 }, /* FIXED TO 0    VOID */
      { 372, 0x00000000 }, /* FIXED TO 0    VOID */
      { 373, 0x00000000 }, /* FIXED TO 0    VOID */
      { 374, 0x00000000 }, /* FIXED TO 0    VOID */
      { 375, 0x00000000 }, /* FIXED TO 0    VOID */
      { 376, 0x00000000 }, /* FIXED TO 0    VOID */
      { 377, 0x00000000 }, /* FIXED TO 0    VOID */
      { 378, 0x00000000 }, /* FIXED TO 0    VOID */
      { 379, 0x00000000 }, /* FIXED TO 0    VOID */
      { 380, 0x00000000 }, /* FIXED TO 0    VOID */
      { 381, 0x00000000 }, /* FIXED TO 0    VOID */
      { 382, 0x00000000 }, /* FIXED TO 0    VOID */
      { 383, 0x00000000 }, /* FIXED TO 0    VOID */
      { 384, 0x00000000 }, /* FIXED TO 0    VOID */
      { 385, 0x00000000 }, /* FIXED TO 0    VOID */
      { 386, 0x00000000 }, /* FIXED TO 0    VOID */
      { 387, 0x00000000 }, /* FIXED TO 0    VOID */
      { 388, 0x00000000 }, /* FIXED TO 0    VOID */
      { 389, 0x00000000 }, /* FIXED TO 0    VOID */
      { 390, 0x00000000 }, /* FIXED TO 0    VOID */
      { 391, 0x00000000 }, /* FIXED TO 0    VOID */
      { 392, 0x00000000 }, /* FIXED TO 0    VOID */
      { 393, 0x00000000 }, /* FIXED TO 0    VOID */
      { 394, 0x00000000 }, /* FIXED TO 0    VOID */
      { 395, 0x00000000 }, /* FIXED TO 0    VOID */
      { 396, 0x00000000 }, /* FIXED TO 0    VOID */
      { 397, 0x00000000 }, /* FIXED TO 0    VOID */
      { 398, 0x00000000 }, /* FIXED TO 0    VOID */
      { 399, 0x00000000 }, /* FIXED TO 0    VOID */
      { 400, 0x00000000 }, /* FIXED TO 0    VOID */
      { 401, 0x00000000 }, /* FIXED TO 0    VOID */
      { 402, 0x00000000 }, /* FIXED TO 0    VOID */
      { 403, 0x00000000 }, /* FIXED TO 0    VOID */
      { 404, 0x00000000 }, /* FIXED TO 0    VOID */
      { 405, 0x00000000 }, /* FIXED TO 0    VOID */
      { 406, 0x00000000 }, /* FIXED TO 0    VOID */
      { 407, 0x00000000 }, /* FIXED TO 0    VOID */
      { 408, 0x00000000 }, /* FIXED TO 0    VOID */
      { 409, 0x00000000 }, /* FIXED TO 0    VOID */
      { 410, 0x00000000 }, /* FIXED TO 0    VOID */
      { 411, 0x00000000 }, /* FIXED TO 0    VOID */
      { 412, 0x00000000 }, /* FIXED TO 0    VOID */
      { 413, 0x00000000 }, /* FIXED TO 0    VOID */
      { 414, 0x00000000 }, /* FIXED TO 0    VOID */
      { 415, 0x00000000 }, /* FIXED TO 0    VOID */
      { 416, 0x00000000 }, /* FIXED TO 0    VOID */
      { 417, 0x00000000 }, /* FIXED TO 0    VOID */
      { 418, 0x00000000 }, /* FIXED TO 0    VOID */
      { 419, 0x00000000 }, /* FIXED TO 0    VOID */
      { 420, 0x00000000 }, /* FIXED TO 0    VOID */
      { 421, 0x00000000 }, /* FIXED TO 0    VOID */
      { 422, 0x00000000 }, /* FIXED TO 0    VOID */
      { 423, 0x00000000 }, /* FIXED TO 0    VOID */
      { 424, 0x00000000 }, /* FIXED TO 0    VOID */
      { 425, 0x00000000 }, /* FIXED TO 0    VOID */
      { 426, 0x00000000 }, /* FIXED TO 0    VOID */
      { 427, 0x00000000 }, /* FIXED TO 0    VOID */
      { 428, 0x00000000 }, /* FIXED TO 0    VOID */
      { 429, 0x00000000 }, /* FIXED TO 0    VOID */
      { 430, 0x00000000 }, /* FIXED TO 0    VOID */
      { 431, 0x00000000 }, /* FIXED TO 0    VOID */
      { 432, 0x00000000 }, /* FIXED TO 0    VOID */
      { 433, 0x00000000 }, /* FIXED TO 0    VOID */
      { 434, 0x00000000 }, /* FIXED TO 0    VOID */
      { 435, 0x00000000 }, /* FIXED TO 0    VOID */
      { 436, 0x00000000 }, /* FIXED TO 0    VOID */
      { 437, 0x00000000 }, /* FIXED TO 0    VOID */
      { 438, 0x00000000 }, /* FIXED TO 0    VOID */
      { 439, 0x00000000 }, /* FIXED TO 0    VOID */
      { 440, 0x00000000 }, /* FIXED TO 0    VOID */
      { 441, 0x00000000 }, /* FIXED TO 0    VOID */
      { 442, 0x00000000 }, /* FIXED TO 0    VOID */
      { 443, 0x00000000 }, /* FIXED TO 0    VOID */
      { 444, 0x00000000 }, /* FIXED TO 0    VOID */
      { 445, 0x00000000 }, /* FIXED TO 0    VOID */
      { 446, 0x00000000 }, /* FIXED TO 0    VOID */
      { 447, 0x00000000 }, /* FIXED TO 0    VOID */
      { 448, 0x00000000 }, /* FIXED TO 0    VOID */
      { 449, 0x00000000 }, /* FIXED TO 0    VOID */
      { 450, 0x00000000 }, /* FIXED TO 0    VOID */
      { 451, 0x00000000 }, /* FIXED TO 0    VOID */
      { 452, 0x00000000 }, /* FIXED TO 0    VOID */
      { 453, 0x00000000 }, /* FIXED TO 0    VOID */
      { 454, 0x00000000 }, /* FIXED TO 0    VOID */
      { 455, 0x00000000 }, /* FIXED TO 0    VOID */
      { 456, 0x00000000 }, /* FIXED TO 0    VOID */
      { 457, 0x00000000 }, /* FIXED TO 0    VOID */
      { 458, 0x00000000 }, /* FIXED TO 0    VOID */
      { 459, 0x00000000 }, /* FIXED TO 0    VOID */
      { 460, 0x00000000 }, /* FIXED TO 0    VOID */
      { 461, 0x00000000 }, /* FIXED TO 0    VOID */
      { 462, 0x00000000 }, /* FIXED TO 0    VOID */
      { 463, 0x00000000 }, /* FIXED TO 0    VOID */
      { 464, 0x00000000 }, /* FIXED TO 0    VOID */
      { 465, 0x00000000 }, /* FIXED TO 0    VOID */
      { 466, 0x00000000 }, /* FIXED TO 0    VOID */
      { 467, 0x00000000 }, /* FIXED TO 0    VOID */
      { 468, 0x00000000 }, /* FIXED TO 0    VOID */
      { 469, 0x00000000 }, /* FIXED TO 0    VOID */
      { 470, 0x00000000 }, /* FIXED TO 0    VOID */
      { 471, 0x00000000 }, /* FIXED TO 0    VOID */
      { 472, 0x00000000 }, /* FIXED TO 0    VOID */
      { 473, 0x00000000 }, /* FIXED TO 0    VOID */
      { 474, 0x00000000 }, /* FIXED TO 0    VOID */
      { 475, 0x00000000 }, /* FIXED TO 0    VOID */
      { 476, 0x00000000 }, /* FIXED TO 0    VOID */
      { 477, 0x00000000 }, /* FIXED TO 0    VOID */
      { 478, 0x00000000 }, /* FIXED TO 0    VOID */
      { 479, 0x00000000 }, /* FIXED TO 0    VOID */
      { 480, 0x00000000 }, /* FIXED TO 0    VOID */
      { 481, 0x00000000 }, /* FIXED TO 0    VOID */
      { 482, 0x00000000 }, /* FIXED TO 0    VOID */
      { 483, 0x00000000 }, /* FIXED TO 0    VOID */
      { 484, 0x00000000 }, /* FIXED TO 0    VOID */
      { 485, 0x00000000 }, /* FIXED TO 0    VOID */
      { 486, 0x00000000 }, /* FIXED TO 0    VOID */
      { 487, 0x00000000 }, /* FIXED TO 0    VOID */
      { 488, 0x00000000 }, /* FIXED TO 0    VOID */
      { 489, 0x00000000 }, /* FIXED TO 0    VOID */
      { 490, 0x00000000 }, /* FIXED TO 0    VOID */
      { 491, 0x00000000 }, /* FIXED TO 0    VOID */
      { 492, 0x00000000 }, /* FIXED TO 0    VOID */
      { 493, 0x00000000 }, /* FIXED TO 0    VOID */
      { 494, 0x00000000 }, /* FIXED TO 0    VOID */
      { 495, 0x00000000 }, /* FIXED TO 0    VOID */
      { 496, 0x00000000 }, /* FIXED TO 0    VOID */
      { 497, 0x00000000 }, /* FIXED TO 0    VOID */
      { 498, 0x00000000 }, /* FIXED TO 0    VOID */
      { 499, 0x00000000 }, /* FIXED TO 0    VOID */
      { 500, 0x00000000 }, /* FIXED TO 0    VOID */
      { 501, 0x00000000 }, /* FIXED TO 0    VOID */
      { 502, 0x00000000 }, /* FIXED TO 0    VOID */
      { 503, 0x00000000 }, /* FIXED TO 0    VOID */
      { 504, 0x00000000 }, /* FIXED TO 0    VOID */
      { 505, 0x00000000 }, /* FIXED TO 0    VOID */
      { 506, 0x00000000 }, /* FIXED TO 0    VOID */
      { 507, 0x00000000 }, /* FIXED TO 0    VOID */
      { 508, 0x00000000 }, /* FIXED TO 0    VOID */
      { 509, 0x00000000 }, /* FIXED TO 0    VOID */
      { 510, 0x00000000 }, /* FIXED TO 0    VOID */
      { 511, 0x00000000 }, /* FIXED TO 0    VOID */
   }
};  
        
const ts_PAD_MUX_CFG c_conf_pad_mux_st =
{  
   {
      { 512, 0x00000000 }, /* PIN not attribute */
      { 513, 0x00000000 }, /* PIN not attribute */
      { 514, 0x00000000 }, /* PIN not attribute */
      { 515, 0x00000000 }, /* PIN not attribute */
      { 516, 0x00000000 }, /* PIN not attribute */
      { 517, 0x00000000 }, /* PIN not attribute */
      { 518, 0x00000000 }, /* PIN not attribute */
      { 519, 0x00000000 }, /* PIN not attribute */
      { 520, 0x00000000 }, /* PIN not attribute */
      { 521, 0x00000000 }, /* PIN not attribute */
      { 522, 0x00000000 }, /* PIN not attribute */
      { 523, 0x00000000 }, /* PIN not attribute */
      { 524, 0x00000000 }, /* PIN not attribute */
      { 525, 0x00000000 }, /* PIN not attribute */
      { 526, 0x00000000 }, /* PIN not attribute */
      { 527, 0x00000000 }, /* PIN not attribute */
      { 528, 0x00000000 }, /* PIN not attribute */
      { 529, 0x00000000 }, /* PIN not attribute */
      { 530, 0x00000000 }, /* PIN not attribute */
      { 531, 0x00000000 }, /* PIN not attribute */
      { 532, 0x00000000 }, /* PIN not attribute */
      { 533, 0x00000000 }, /* PIN not attribute */
      { 534, 0x00000000 }, /* PIN not attribute */
      { 535, 0x00000000 }, /* PIN not attribute */
      { 536, 0x00000000 }, /* PIN not attribute */
      { 537, 0x00000000 }, /* PIN not attribute */
      { 538, 0x00000000 }, /* PIN not attribute */
      { 539, 0x00000000 }, /* PIN not attribute */
      { 540, 0x00000000 }, /* PIN not attribute */
      { 541, 0x00000000 }, /* PIN not attribute */
      { 542, 0x00000000 }, /* PIN not attribute */
      { 543, 0x00000000 }, /* PIN not attribute */
      { 544, 0x00000000 }, /* PIN not attribute */
      { 545, 0x00000000 }, /* PIN not attribute */
      { 546, 0x00000000 }, /* PIN not attribute */
      { 547, 0x00000000 }, /* PIN not attribute */
      { 548, 0x00000000 }, /* PIN not attribute */
      { 549, 0x00000000 }, /* PIN not attribute */
      { 550, 0x00000000 }, /* PIN not attribute */
      { 551, 0x00000000 }, /* PIN not attribute */
      { 552, 0x00000000 }, /* PIN not attribute */
      { 553, 0x00000000 }, /* PIN not attribute */
      { 554, 0x00000000 }, /* PIN not attribute */
      { 555, 0x00000000 }, /* PIN not attribute */
      { 556, 0x00000000 }, /* PIN not attribute */
      { 557, 0x00000000 }, /* PIN not attribute */
      { 558, 0x00000000 }, /* PIN not attribute */
      { 559, 0x00000000 }, /* PIN not attribute */
      { 560, 0x00000000 }, /* PIN not attribute */
      { 561, 0x00000000 }, /* PIN not attribute */
      { 562, 0x00000000 }, /* PIN not attribute */
      { 563, 0x00000000 }, /* PIN not attribute */
      { 564, 0x00000000 }, /* PIN not attribute */
      { 565, 0x00000000 }, /* PIN not attribute */
      { 566, 0x00000000 }, /* PIN not attribute */
      { 567, 0x00000000 }, /* PIN not attribute */
      { 568, 0x00000000 }, /* PIN not attribute */
      { 569, 0x00000000 }, /* PIN not attribute */
      { 570, 0x00000000 }, /* PIN not attribute */
      { 571, 0x00000000 }, /* PIN not attribute */
      { 572, 0x00000000 }, /* PIN not attribute */
      { 573, 0x00000000 }, /* PIN not attribute */
      { 574, 0x00000000 }, /* PIN not attribute */
      { 575, 0x00000000 }, /* PIN not attribute */
      { 576, 0x00000000 }, /* PIN not attribute */
      { 577, 0x00000000 }, /* PIN not attribute */
      { 578, 0x00000000 }, /* PIN not attribute */
      { 579, 0x00000000 }, /* PIN not attribute */
      { 580, 0x00000000 }, /* PIN not attribute */
      { 581, 0x00000000 }, /* PIN not attribute */
      { 582, 0x00000000 }, /* PIN not attribute */
      { 583, 0x00000000 }, /* PIN not attribute */
      { 584, 0x00000000 }, /* PIN not attribute */
      { 585, 0x00000000 }, /* PIN not attribute */
      { 586, 0x00000000 }, /* PIN not attribute */
      { 587, 0x00000000 }, /* PIN not attribute */
      { 588, 0x00000000 }, /* PIN not attribute */
      { 589, 0x00000000 }, /* PIN not attribute */
      { 590, 0x00000000 }, /* PIN not attribute */
      { 591, 0x00000000 }, /* PIN not attribute */
      { 592, 0x00000000 }, /* PIN not attribute */
      { 593, 0x00000000 }, /* PIN not attribute */
      { 594, 0x00000000 }, /* PIN not attribute */
      { 595, 0x00000000 }, /* PIN not attribute */
      { 596, 0x00000000 }, /* PIN not attribute */
      { 597, 0x00000000 }, /* PIN not attribute */
      { 598, 0x00000000 }, /* PIN not attribute */
      { 599, 0x00000000 }, /* PIN not attribute */
      { 600, 0x00000000 }, /* PIN not attribute */
      { 601, 0x00000000 }, /* PIN not attribute */
      { 602, 0x00000000 }, /* PIN not attribute */
      { 603, 0x00000000 }, /* PIN not attribute */
      { 604, 0x00000000 }, /* PIN not attribute */
      { 605, 0x00000000 }, /* PIN not attribute */
      { 606, 0x00000000 }, /* PIN not attribute */
      { 607, 0x00000000 }, /* PIN not attribute */
      { 608, 0x00000000 }, /* PIN not attribute */
      { 609, 0x00000000 }, /* PIN not attribute */
      { 610, 0x00000000 }, /* PIN not attribute */
      { 611, 0x00000000 }, /* PIN not attribute */
      { 612, 0x00000000 }, /* PIN not attribute */
      { 613, 0x00000000 }, /* PIN not attribute */
      { 614, 0x00000000 }, /* PIN not attribute */
      { 615, 0x00000000 }, /* PIN not attribute */
      { 616, 0x00000000 }, /* PIN not attribute */
      { 617, 0x00000000 }, /* PIN not attribute */
      { 618, 0x00000000 }, /* PIN not attribute */
      { 619, 0x00000000 }, /* PIN not attribute */
      { 620, 0x00000000 }, /* PIN not attribute */
      { 621, 0x00000000 }, /* PIN not attribute */
      { 622, 0x00000000 }, /* PIN not attribute */
      { 623, 0x00000000 }, /* PIN not attribute */
      { 624, 0x00000000 }, /* PIN not attribute */
      { 625, 0x00000000 }, /* PIN not attribute */
      { 626, 0x00000000 }, /* PIN not attribute */
      { 627, 0x00000000 }, /* PIN not attribute */
      { 628, 0x00000000 }, /* PIN not attribute */
      { 629, 0x00000000 }, /* PIN not attribute */
      { 630, 0x00000000 }, /* PIN not attribute */
      { 631, 0x00000000 }, /* PIN not attribute */
      { 632, 0x00000000 }, /* PIN not attribute */
      { 633, 0x00000000 }, /* PIN not attribute */
      { 634, 0x00000000 }, /* PIN not attribute */
      { 635, 0x00000000 }, /* PIN not attribute */
      { 636, 0x00000000 }, /* PIN not attribute */
      { 637, 0x00000000 }, /* PIN not attribute */
      { 638, 0x00000000 }, /* PIN not attribute */
      { 639, 0x00000000 }, /* PIN not attribute */
      { 640, 0x00000000 }, /* PIN not attribute */
      { 641, 0x00000000 }, /* PIN not attribute */
      { 642, 0x00000000 }, /* PIN not attribute */
      { 643, 0x00000000 }, /* PIN not attribute */
      { 644, 0x00000000 }, /* PIN not attribute */
      { 645, 0x00000000 }, /* PIN not attribute */
      { 646, 0x00000000 }, /* PIN not attribute */
      { 647, 0x00000000 }, /* PIN not attribute */
      { 648, 0x00000000 }, /* PIN not attribute */
      { 649, 0x00000000 }, /* PIN not attribute */
      { 650, 0x00000000 }, /* PIN not attribute */
      { 651, 0x00000000 }, /* PIN not attribute */
      { 652, 0x00000000 }, /* PIN not attribute */
      { 653, 0x00000000 }, /* PIN not attribute */
      { 654, 0x00000000 }, /* PIN not attribute */
      { 655, 0x00000000 }, /* PIN not attribute */
      { 656, 0x00000000 }, /* PIN not attribute */
      { 657, 0x00000000 }, /* PIN not attribute */
      { 658, 0x00000000 }, /* PIN not attribute */
      { 659, 0x00000000 }, /* PIN not attribute */
      { 660, 0x00000000 }, /* PIN not attribute */
      { 661, 0x00000000 }, /* PIN not attribute */
      { 662, 0x00000000 }, /* PIN not attribute */
      { 663, 0x00000000 }, /* PIN not attribute */
      { 664, 0x00000000 }, /* PIN not attribute */
      { 665, 0x00000000 }, /* PIN not attribute */
      { 666, 0x00000000 }, /* PIN not attribute */
      { 667, 0x00000000 }, /* PIN not attribute */
      { 668, 0x00000000 }, /* PIN not attribute */
      { 669, 0x00000000 }, /* PIN not attribute */
      { 670, 0x00000000 }, /* PIN not attribute */
      { 671, 0x00000000 }, /* PIN not attribute */
      { 672, 0x00000000 }, /* PIN not attribute */
      { 673, 0x00000000 }, /* PIN not attribute */
      { 674, 0x00000000 }, /* PIN not attribute */
      { 675, 0x00000000 }, /* PIN not attribute */
      { 676, 0x00000000 }, /* PIN not attribute */
      { 677, 0x00000000 }, /* PIN not attribute */
      { 678, 0x00000000 }, /* PIN not attribute */
      { 679, 0x00000000 }, /* PIN not attribute */
      { 680, 0x00000000 }, /* PIN not attribute */
      { 681, 0x00000000 }, /* PIN not attribute */
      { 682, 0x00000000 }, /* PIN not attribute */
      { 683, 0x00000000 }, /* PIN not attribute */
      { 684, 0x00000000 }, /* PIN not attribute */
      { 685, 0x00000000 }, /* PIN not attribute */
      { 686, 0x00000000 }, /* PIN not attribute */
      { 687, 0x00000000 }, /* PIN not attribute */
      { 688, 0x00000000 }, /* PIN not attribute */
      { 689, 0x00000000 }, /* PIN not attribute */
      { 690, 0x00000000 }, /* PIN not attribute */
      { 691, 0x00000000 }, /* PIN not attribute */
      { 692, 0x00000000 }, /* PIN not attribute */
      { 693, 0x00000000 }, /* PIN not attribute */
      { 694, 0x00000000 }, /* PIN not attribute */
      { 695, 0x00000000 }, /* PIN not attribute */
      { 696, 0x00000000 }, /* PIN not attribute */
      { 697, 0x00000000 }, /* PIN not attribute */
      { 698, 0x00000000 }, /* PIN not attribute */
      { 699, 0x00000000 }, /* PIN not attribute */
      { 700, 0x00000000 }, /* PIN not attribute */
      { 701, 0x00000000 }, /* PIN not attribute */
      { 702, 0x00000000 }, /* PIN not attribute */
      { 703, 0x00000000 }, /* PIN not attribute */
      { 704, 0x00000000 }, /* PIN not attribute */
      { 705, 0x00000000 }, /* PIN not attribute */
      { 706, 0x00000000 }, /* PIN not attribute */
      { 707, 0x00000000 }, /* PIN not attribute */
      { 708, 0x00000000 }, /* PIN not attribute */
      { 709, 0x00000000 }, /* PIN not attribute */
      { 710, 0x00000000 }, /* PIN not attribute */
      { 711, 0x00000000 }, /* PIN not attribute */
      { 712, 0x00000000 }, /* PIN not attribute */
      { 713, 0x00000000 }, /* PIN not attribute */
      { 714, 0x00000000 }, /* PIN not attribute */
      { 715, 0x00000000 }, /* PIN not attribute */
      { 716, 0x00000000 }, /* PIN not attribute */
      { 717, 0x00000000 }, /* PIN not attribute */
      { 718, 0x00000000 }, /* PIN not attribute */
      { 719, 0x00000000 }, /* PIN not attribute */
      { 720, 0x00000000 }, /* PIN not attribute */
      { 721, 0x00000000 }, /* PIN not attribute */
      { 722, 0x00000000 }, /* PIN not attribute */
      { 723, 0x00000000 }, /* PIN not attribute */
      { 724, 0x00000000 }, /* PIN not attribute */
      { 725, 0x00000000 }, /* PIN not attribute */
      { 726, 0x00000000 }, /* PIN not attribute */
      { 727, 0x00000000 }, /* PIN not attribute */
      { 728, 0x00000000 }, /* PIN not attribute */
      { 729, 0x00000000 }, /* PIN not attribute */
      { 730, 0x00000000 }, /* PIN not attribute */
      { 731, 0x00000000 }, /* PIN not attribute */
      { 732, 0x00000000 }, /* PIN not attribute */
      { 733, 0x00000000 }, /* PIN not attribute */
      { 734, 0x00000000 }, /* PIN not attribute */
      { 735, 0x00000000 }, /* PIN not attribute */
      { 736, 0x00000000 }, /* PIN not attribute */
      { 737, 0x00000000 }, /* PIN not attribute */
      { 738, 0x00000000 }, /* PIN not attribute */
      { 739, 0x00000000 }, /* PIN not attribute */
      { 740, 0x00000000 }, /* PIN not attribute */
      { 741, 0x00000000 }, /* PIN not attribute */
      { 742, 0x00000000 }, /* PIN not attribute */
      { 743, 0x00000000 }, /* PIN not attribute */
      { 744, 0x00000000 }, /* PIN not attribute */
      { 745, 0x00000000 }, /* PIN not attribute */
      { 746, 0x00000000 }, /* PIN not attribute */
      { 747, 0x00000000 }, /* PIN not attribute */
      { 748, 0x00000000 }, /* PIN not attribute */
      { 749, 0x00000000 }, /* PIN not attribute */
      { 750, 0x00000000 }, /* PIN not attribute */
      { 751, 0x00000000 }, /* PIN not attribute */
      { 752, 0x00000000 }, /* PIN not attribute */
      { 753, 0x00000000 }, /* PIN not attribute */
      { 754, 0x00000000 }, /* PIN not attribute */
      { 755, 0x00000000 }, /* PIN not attribute */
      { 756, 0x00000000 }, /* PIN not attribute */
      { 757, 0x00000000 }, /* PIN not attribute */
      { 758, 0x00000004 }, /* CAN1_RX    PL[0] */
      { 759, 0x00000003 }, /* CAN_ECDR_RX    PC[8] */
      { 760, 0x00000004 }, /* CAN_OVSP_LS_MPC_RX    PN[5] */
      { 761, 0x00000004 }, /* CAN_OVSP_HS_MPC_RX    PN[3] */
      { 762, 0x00000000 }, /* PIN not attribute */
      { 763, 0x00000000 }, /* PIN not attribute */
      { 764, 0x00000000 }, /* PIN not attribute */
      { 765, 0x00000000 }, /* PIN not attribute */
      { 766, 0x00000000 }, /* PIN not attribute */
      { 767, 0x00000000 }, /* PIN not attribute */
      { 768, 0x00000000 }, /* PIN not attribute */
      { 769, 0x00000000 }, /* PIN not attribute */
      { 770, 0x00000000 }, /* PIN not attribute */
      { 771, 0x00000000 }, /* PIN not attribute */
      { 772, 0x00000000 }, /* PIN not attribute */
      { 773, 0x00000000 }, /* PIN not attribute */
      { 774, 0x00000000 }, /* PIN not attribute */
      { 775, 0x00000000 }, /* PIN not attribute */
      { 776, 0x00000000 }, /* PIN not attribute */
      { 777, 0x00000000 }, /* PIN not attribute */
      { 778, 0x00000000 }, /* PIN not attribute */
      { 779, 0x00000000 }, /* PIN not attribute */
      { 780, 0x00000000 }, /* PIN not attribute */
      { 781, 0x00000000 }, /* PIN not attribute */
      { 782, 0x00000000 }, /* PIN not attribute */
      { 783, 0x00000000 }, /* PIN not attribute */
      { 784, 0x00000000 }, /* PIN not attribute */
      { 785, 0x00000000 }, /* PIN not attribute */
      { 786, 0x00000000 }, /* PIN not attribute */
      { 787, 0x00000000 }, /* PIN not attribute */
      { 788, 0x00000000 }, /* PIN not attribute */
      { 789, 0x00000000 }, /* PIN not attribute */
      { 790, 0x00000000 }, /* PIN not attribute */
      { 791, 0x00000000 }, /* PIN not attribute */
      { 792, 0x00000000 }, /* PIN not attribute */
      { 793, 0x00000000 }, /* PIN not attribute */
      { 794, 0x00000000 }, /* PIN not attribute */
      { 795, 0x00000000 }, /* PIN not attribute */
      { 796, 0x00000000 }, /* PIN not attribute */
      { 797, 0x00000000 }, /* PIN not attribute */
      { 798, 0x00000000 }, /* PIN not attribute */
      { 799, 0x00000000 }, /* PIN not attribute */
      { 800, 0x00000000 }, /* PIN not attribute */
      { 801, 0x00000000 }, /* PIN not attribute */
      { 802, 0x00000000 }, /* PIN not attribute */
      { 803, 0x00000000 }, /* PIN not attribute */
      { 804, 0x00000000 }, /* PIN not attribute */
      { 805, 0x00000000 }, /* PIN not attribute */
      { 806, 0x00000000 }, /* PIN not attribute */
      { 807, 0x00000000 }, /* PIN not attribute */
      { 808, 0x00000001 }, /* I2C_IOEXP_SDA    PC[7] */
      { 809, 0x00000001 }, /* I2C_IOEXP_SCL    PC[6] */
      { 810, 0x00000002 }, /* I2C_TPIB_SDA    PQ[15] */
      { 811, 0x00000002 }, /* I2C_TPIB_SCL    PQ[13] */
      { 812, 0x00000000 }, /* PIN not attribute */
      { 813, 0x00000000 }, /* PIN not attribute */
      { 814, 0x00000000 }, /* PIN not attribute */
      { 815, 0x00000000 }, /* PIN not attribute */
      { 816, 0x00000000 }, /* PIN not attribute */
      { 817, 0x00000000 }, /* PIN not attribute */
      { 818, 0x00000000 }, /* PIN not attribute */
      { 819, 0x00000000 }, /* PIN not attribute */
      { 820, 0x00000000 }, /* PIN not attribute */
      { 821, 0x00000000 }, /* PIN not attribute */
      { 822, 0x00000000 }, /* PIN not attribute */
      { 823, 0x00000000 }, /* PIN not attribute */
      { 824, 0x00000000 }, /* PIN not attribute */
      { 825, 0x00000000 }, /* PIN not attribute */
      { 826, 0x00000000 }, /* PIN not attribute */
      { 827, 0x00000000 }, /* PIN not attribute */
      { 828, 0x00000000 }, /* PIN not attribute */
      { 829, 0x00000000 }, /* PIN not attribute */
      { 830, 0x00000000 }, /* PIN not attribute */
      { 831, 0x00000000 }, /* PIN not attribute */
      { 832, 0x00000000 }, /* PIN not attribute */
      { 833, 0x00000000 }, /* PIN not attribute */
      { 834, 0x00000000 }, /* PIN not attribute */
      { 835, 0x00000000 }, /* PIN not attribute */
      { 836, 0x00000000 }, /* PIN not attribute */
      { 837, 0x00000000 }, /* PIN not attribute */
      { 838, 0x00000000 }, /* PIN not attribute */
      { 839, 0x00000000 }, /* PIN not attribute */
      { 840, 0x00000000 }, /* PIN not attribute */
      { 841, 0x00000000 }, /* PIN not attribute */
      { 842, 0x00000000 }, /* PIN not attribute */
      { 843, 0x00000000 }, /* PIN not attribute */
      { 844, 0x00000000 }, /* PIN not attribute */
      { 845, 0x00000000 }, /* PIN not attribute */
      { 846, 0x00000000 }, /* PIN not attribute */
      { 847, 0x00000000 }, /* PIN not attribute */
      { 848, 0x00000002 }, /* RS422_EECU_RX    PA[11] */
      { 849, 0x00000001 }, /* RS422_CCDL1_RX    PE[6] */
      { 850, 0x00000000 }, /* PIN not attribute */
      { 851, 0x00000000 }, /* PIN not attribute */
      { 852, 0x00000000 }, /* PIN not attribute */
      { 853, 0x00000000 }, /* PIN not attribute */
      { 854, 0x00000000 }, /* PIN not attribute */
      { 855, 0x00000000 }, /* PIN not attribute */
      { 856, 0x00000000 }, /* PIN not attribute */
      { 857, 0x00000000 }, /* PIN not attribute */
      { 858, 0x00000000 }, /* PIN not attribute */
      { 859, 0x00000000 }, /* PIN not attribute */
      { 860, 0x00000000 }, /* PIN not attribute */
      { 861, 0x00000000 }, /* PIN not attribute */
      { 862, 0x00000000 }, /* PIN not attribute */
      { 863, 0x00000000 }, /* PIN not attribute */
      { 864, 0x00000000 }, /* PIN not attribute */
      { 865, 0x00000000 }, /* PIN not attribute */
      { 866, 0x00000000 }, /* PIN not attribute */
      { 867, 0x00000000 }, /* PIN not attribute */
      { 868, 0x00000000 }, /* PIN not attribute */
      { 869, 0x00000000 }, /* PIN not attribute */
      { 870, 0x00000000 }, /* PIN not attribute */
      { 871, 0x00000000 }, /* PIN not attribute */
      { 872, 0x00000000 }, /* PIN not attribute */
      { 873, 0x00000000 }, /* PIN not attribute */
      { 874, 0x00000000 }, /* PIN not attribute */
      { 875, 0x00000000 }, /* PIN not attribute */
      { 876, 0x00000000 }, /* PIN not attribute */
      { 877, 0x00000000 }, /* PIN not attribute */
      { 878, 0x00000000 }, /* PIN not attribute */
      { 879, 0x00000000 }, /* PIN not attribute */
      { 880, 0x00000003 }, /* CC_SPI0_MISO    PJ[11] */
      { 881, 0x00000000 }, /* PIN not attribute */
      { 882, 0x00000000 }, /* PIN not attribute */
      { 883, 0x00000005 }, /* SPI_ADC1_MISO    PH[9] */
      { 884, 0x00000000 }, /* PIN not attribute */
      { 885, 0x00000000 }, /* PIN not attribute */
      { 886, 0x00000004 }, /* SPI_ADC2_MISO    PH[0] */
      { 887, 0x00000000 }, /* PIN not attribute */
      { 888, 0x00000000 }, /* PIN not attribute */
      { 889, 0x00000005 }, /* SPI_ADC3_MISO    PL[5] */
      { 890, 0x00000000 }, /* PIN not attribute */
      { 891, 0x00000000 }, /* PIN not attribute */
      { 892, 0x00190002 }, /* P0_TX_MISO    PD[12] */
      { 893, 0x00000000 }, /* PIN not attribute */
      { 894, 0x00000000 }, /* PIN not attribute */
      { 895, 0x00000000 }, /* PIN not attribute */
      { 896, 0x00000000 }, /* PIN not attribute */
      { 897, 0x00000000 }, /* PIN not attribute */
      { 898, 0x00000000 }, /* PIN not attribute */
      { 899, 0x00000000 }, /* PIN not attribute */
      { 900, 0x00000000 }, /* PIN not attribute */
      { 901, 0x00000000 }, /* PIN not attribute */
      { 902, 0x00000000 }, /* PIN not attribute */
      { 903, 0x00000000 }, /* PIN not attribute */
      { 904, 0x00000000 }, /* PIN not attribute */
      { 905, 0x00000000 }, /* PIN not attribute */
      { 906, 0x00000000 }, /* PIN not attribute */
      { 907, 0x00000000 }, /* PIN not attribute */
      { 908, 0x00000000 }, /* PIN not attribute */
      { 909, 0x00000000 }, /* PIN not attribute */
      { 910, 0x00000000 }, /* PIN not attribute */
      { 911, 0x00000000 }, /* PIN not attribute */
      { 912, 0x00000000 }, /* PIN not attribute */
      { 913, 0x00000000 }, /* PIN not attribute */
      { 914, 0x00000000 }, /* PIN not attribute */
      { 915, 0x00000000 }, /* PIN not attribute */
      { 916, 0x00000000 }, /* PIN not attribute */
      { 917, 0x00000000 }, /* PIN not attribute */
      { 918, 0x00000000 }, /* PIN not attribute */
      { 919, 0x00000000 }, /* PIN not attribute */
      { 920, 0x00000000 }, /* PIN not attribute */
      { 921, 0x00000000 }, /* PIN not attribute */
      { 922, 0x00000000 }, /* PIN not attribute */
      { 923, 0x00000000 }, /* PIN not attribute */
      { 924, 0x00000000 }, /* PIN not attribute */
      { 925, 0x00000002 }, /* CC_FEC_RXDV    PC[11] */
      { 926, 0x00000000 }, /* CC_FEC_CRS    PM[0] */
      { 927, 0x00000001 }, /* CC_FEC_RXD0    PC[12] */
      { 928, 0x00000001 }, /* CC_FEC_RXD1    PC[13] */
      { 929, 0x00000001 }, /* CC_FEC_RXD2    PM[1] */
      { 930, 0x00000000 }, /* PIN not attribute */
      { 931, 0x00000001 }, /* CC_FEC_COL    PM[2] */
      { 932, 0x00000001 }, /* CC_FEC_RXER    PM[3] */
   }
};
