/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config ..\..\LIBBSP_api\LIBBSP_TYPE\config.txt
** Generation date: 2022-10-20T18:05:10
*************************************************************$ */

#include "kcg_types.h"

#ifdef kcg_use_TS_LIBBSP_ETSEC_MacAddr
kcg_bool kcg_comp_TS_LIBBSP_ETSEC_MacAddr(
  TS_LIBBSP_ETSEC_MacAddr *kcg_c1,
  TS_LIBBSP_ETSEC_MacAddr *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 6; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_ETSEC_MacAddr */

#ifdef kcg_use_TS_LIBBSP_ETSEC_EthBuffer
kcg_bool kcg_comp_TS_LIBBSP_ETSEC_EthBuffer(
  TS_LIBBSP_ETSEC_EthBuffer *kcg_c1,
  TS_LIBBSP_ETSEC_EthBuffer *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 1518; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_ETSEC_EthBuffer */

#ifdef kcg_use_TS_LIBBSP_A429_Buffer
kcg_bool kcg_comp_TS_LIBBSP_A429_Buffer(
  TS_LIBBSP_A429_Buffer *kcg_c1,
  TS_LIBBSP_A429_Buffer *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 64; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_A429_Buffer */

#ifdef kcg_use_TS_LIBBSP_IMU_AdditionalDataWriteBuffer
kcg_bool kcg_comp_TS_LIBBSP_IMU_AdditionalDataWriteBuffer(
  TS_LIBBSP_IMU_AdditionalDataWriteBuffer *kcg_c1,
  TS_LIBBSP_IMU_AdditionalDataWriteBuffer *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 6; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_IMU_AdditionalDataWriteBuffer */

#ifdef kcg_use_TS_LIBBSP_IMU_Vect9
kcg_bool kcg_comp_TS_LIBBSP_IMU_Vect9(
  TS_LIBBSP_IMU_Vect9 *kcg_c1,
  TS_LIBBSP_IMU_Vect9 *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 9; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_IMU_Vect9 */

#ifdef kcg_use_TS_LIBBSP_IMU_Vect3
kcg_bool kcg_comp_TS_LIBBSP_IMU_Vect3(
  TS_LIBBSP_IMU_Vect3 *kcg_c1,
  TS_LIBBSP_IMU_Vect3 *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 3; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_IMU_Vect3 */

#ifdef kcg_use_TA_LIBBSP_UART_RxBuffer
kcg_bool kcg_comp_TA_LIBBSP_UART_RxBuffer(
  TA_LIBBSP_UART_RxBuffer *kcg_c1,
  TA_LIBBSP_UART_RxBuffer *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 2048; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_TA_LIBBSP_UART_RxBuffer */

#ifdef kcg_use_TS_LIBBSP_IMU_WriteDataBuffer
kcg_bool kcg_comp_TS_LIBBSP_IMU_WriteDataBuffer(
  TS_LIBBSP_IMU_WriteDataBuffer *kcg_c1,
  TS_LIBBSP_IMU_WriteDataBuffer *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 32; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_IMU_WriteDataBuffer */

#ifdef kcg_use_TS_LIBBSP_IMU_WriteAddrBuffer2
kcg_bool kcg_comp_TS_LIBBSP_IMU_WriteAddrBuffer2(
  TS_LIBBSP_IMU_WriteAddrBuffer2 *kcg_c1,
  TS_LIBBSP_IMU_WriteAddrBuffer2 *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 33; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_IMU_WriteAddrBuffer2 */

#ifdef kcg_use_TS_LIBBSP_IMU_AdditionalDataReadBufferOut
kcg_bool kcg_comp_TS_LIBBSP_IMU_AdditionalDataReadBufferOut(
  TS_LIBBSP_IMU_AdditionalDataReadBufferOut *kcg_c1,
  TS_LIBBSP_IMU_AdditionalDataReadBufferOut *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 5; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_IMU_AdditionalDataReadBufferOut */

#ifdef kcg_use_TS_LIBBSP_IMU_FloatTab
kcg_bool kcg_comp_TS_LIBBSP_IMU_FloatTab(
  TS_LIBBSP_IMU_FloatTab *kcg_c1,
  TS_LIBBSP_IMU_FloatTab *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 13; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_IMU_FloatTab */

#ifdef kcg_use_TS_LIBBSP_IMU_InstrumIMUData
kcg_bool kcg_comp_TS_LIBBSP_IMU_InstrumIMUData(
  TS_LIBBSP_IMU_InstrumIMUData *kcg_c1,
  TS_LIBBSP_IMU_InstrumIMUData *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F4_4 == kcg_c2->v_cfPilot_F4_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F4_3 == kcg_c2->v_cfPilot_F4_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F4_2 == kcg_c2->v_cfPilot_F4_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F4_1 == kcg_c2->v_cfPilot_F4_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F4_0 == kcg_c2->v_cfPilot_F4_0);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F3_4 == kcg_c2->v_cfPilot_F3_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F3_3 == kcg_c2->v_cfPilot_F3_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F3_2 == kcg_c2->v_cfPilot_F3_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F3_1 == kcg_c2->v_cfPilot_F3_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F3_0 == kcg_c2->v_cfPilot_F3_0);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F2_4 == kcg_c2->v_cfPilot_F2_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F2_3 == kcg_c2->v_cfPilot_F2_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F2_2 == kcg_c2->v_cfPilot_F2_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F2_1 == kcg_c2->v_cfPilot_F2_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F2_0 == kcg_c2->v_cfPilot_F2_0);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F1_4 == kcg_c2->v_cfPilot_F1_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F1_3 == kcg_c2->v_cfPilot_F1_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F1_2 == kcg_c2->v_cfPilot_F1_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F1_1 == kcg_c2->v_cfPilot_F1_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_F1_0 == kcg_c2->v_cfPilot_F1_0);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E4_4 == kcg_c2->v_cfPilot_E4_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E4_3 == kcg_c2->v_cfPilot_E4_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E4_2 == kcg_c2->v_cfPilot_E4_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E4_1 == kcg_c2->v_cfPilot_E4_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E4_0 == kcg_c2->v_cfPilot_E4_0);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E3_4 == kcg_c2->v_cfPilot_E3_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E3_3 == kcg_c2->v_cfPilot_E3_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E3_2 == kcg_c2->v_cfPilot_E3_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E3_1 == kcg_c2->v_cfPilot_E3_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E3_0 == kcg_c2->v_cfPilot_E3_0);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E2_4 == kcg_c2->v_cfPilot_E2_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E2_3 == kcg_c2->v_cfPilot_E2_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E2_2 == kcg_c2->v_cfPilot_E2_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E2_1 == kcg_c2->v_cfPilot_E2_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E2_0 == kcg_c2->v_cfPilot_E2_0);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E1_4 == kcg_c2->v_cfPilot_E1_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E1_3 == kcg_c2->v_cfPilot_E1_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E1_2 == kcg_c2->v_cfPilot_E1_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E1_1 == kcg_c2->v_cfPilot_E1_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_E1_0 == kcg_c2->v_cfPilot_E1_0);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B4_4 == kcg_c2->v_cfPilot_B4_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B4_3 == kcg_c2->v_cfPilot_B4_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B4_2 == kcg_c2->v_cfPilot_B4_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B4_1 == kcg_c2->v_cfPilot_B4_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B4_0 == kcg_c2->v_cfPilot_B4_0);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B3_4 == kcg_c2->v_cfPilot_B3_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B3_3 == kcg_c2->v_cfPilot_B3_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B3_2 == kcg_c2->v_cfPilot_B3_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B3_1 == kcg_c2->v_cfPilot_B3_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B3_0 == kcg_c2->v_cfPilot_B3_0);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B2_4 == kcg_c2->v_cfPilot_B2_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B2_3 == kcg_c2->v_cfPilot_B2_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B2_2 == kcg_c2->v_cfPilot_B2_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B2_1 == kcg_c2->v_cfPilot_B2_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B2_0 == kcg_c2->v_cfPilot_B2_0);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B1_4 == kcg_c2->v_cfPilot_B1_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B1_3 == kcg_c2->v_cfPilot_B1_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B1_2 == kcg_c2->v_cfPilot_B1_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B1_1 == kcg_c2->v_cfPilot_B1_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_B1_0 == kcg_c2->v_cfPilot_B1_0);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A4_4 == kcg_c2->v_cfPilot_A4_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A4_3 == kcg_c2->v_cfPilot_A4_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A4_2 == kcg_c2->v_cfPilot_A4_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A4_1 == kcg_c2->v_cfPilot_A4_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A4_0 == kcg_c2->v_cfPilot_A4_0);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A3_4 == kcg_c2->v_cfPilot_A3_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A3_3 == kcg_c2->v_cfPilot_A3_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A3_2 == kcg_c2->v_cfPilot_A3_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A3_0 == kcg_c2->v_cfPilot_A3_0);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A3_1 == kcg_c2->v_cfPilot_A3_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A2_4 == kcg_c2->v_cfPilot_A2_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A2_3 == kcg_c2->v_cfPilot_A2_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A2_2 == kcg_c2->v_cfPilot_A2_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A2_1 == kcg_c2->v_cfPilot_A2_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A1_4 == kcg_c2->v_cfPilot_A1_4);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A1_3 == kcg_c2->v_cfPilot_A1_3);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A1_2 == kcg_c2->v_cfPilot_A1_2);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A1_1 == kcg_c2->v_cfPilot_A1_1);
  kcg_equ = kcg_equ & (kcg_c1->v_cfPilot_A1_0 == kcg_c2->v_cfPilot_A1_0);
  kcg_equ = kcg_equ & (kcg_c1->v_lambda_ext_2 == kcg_c2->v_lambda_ext_2);
  kcg_equ = kcg_equ & (kcg_c1->v_lambda_ext_1 == kcg_c2->v_lambda_ext_1);
  kcg_equ = kcg_equ & (kcg_c1->v_lambda_ext_0 == kcg_c2->v_lambda_ext_0);
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_IMU_InstrumIMUData */

#ifdef kcg_use_TS_LIBBSP_IMU_InertialData
kcg_bool kcg_comp_TS_LIBBSP_IMU_InertialData(
  TS_LIBBSP_IMU_InertialData *kcg_c1,
  TS_LIBBSP_IMU_InertialData *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect9(
      &kcg_c1->TmgyrData,
      &kcg_c2->TmgyrData);
  kcg_equ = kcg_equ & (kcg_c1->TicStatus2 == kcg_c2->TicStatus2);
  kcg_equ = kcg_equ & (kcg_c1->TicStatus1 == kcg_c2->TicStatus1);
  kcg_equ = kcg_equ & (kcg_c1->HrgStatus2 == kcg_c2->HrgStatus2);
  kcg_equ = kcg_equ & (kcg_c1->HrgStatus1 == kcg_c2->HrgStatus1);
  kcg_equ = kcg_equ & (kcg_c1->AccStatus == kcg_c2->AccStatus);
  kcg_equ = kcg_equ & (kcg_c1->Tida_sature == kcg_c2->Tida_sature);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(
      &kcg_c1->Cpulse_sature,
      &kcg_c2->Cpulse_sature);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(
      &kcg_c1->Tacc_sature,
      &kcg_c2->Tacc_sature);
  kcg_equ = kcg_equ & (kcg_c1->Tida_filtre == kcg_c2->Tida_filtre);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(
      &kcg_c1->Tacc_filtre,
      &kcg_c2->Tacc_filtre);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(
      &kcg_c1->accAng_filtF_fPilot_custUnit,
      &kcg_c2->accAng_filtF_fPilot_custUnit);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(
      &kcg_c1->accAng_filtE_fPilot_custUnit,
      &kcg_c2->accAng_filtE_fPilot_custUnit);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(
      &kcg_c1->pqr_filtF_fPilot_custUnit,
      &kcg_c2->pqr_filtF_fPilot_custUnit);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(
      &kcg_c1->pqr_filtE_fPilot_custUnit,
      &kcg_c2->pqr_filtE_fPilot_custUnit);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(
      &kcg_c1->fs_filtB_BdL_fPilot_custUnit,
      &kcg_c2->fs_filtB_BdL_fPilot_custUnit);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(
      &kcg_c1->fs_filtA_BdL_fPilot_custUnit,
      &kcg_c2->fs_filtA_BdL_fPilot_custUnit);
  kcg_equ = kcg_equ & (kcg_c1->cpt_tache_fNav == kcg_c2->cpt_tache_fNav);
  kcg_equ = kcg_equ & (kcg_c1->synth_umi == kcg_c2->synth_umi);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(
      &kcg_c1->IndFEP,
      &kcg_c2->IndFEP);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(
      &kcg_c1->ErrFEP,
      &kcg_c2->ErrFEP);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(
      &kcg_c1->TheteE,
      &kcg_c2->TheteE);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(&kcg_c1->Cp, &kcg_c2->Cp);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(&kcg_c1->dV, &kcg_c2->dV);
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_IMU_Vect3(
      &kcg_c1->dTheta,
      &kcg_c2->dTheta);
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_IMU_InertialData */

#ifdef kcg_use_TS_LIBBSP_SHM_BoardStatus
kcg_bool kcg_comp_TS_LIBBSP_SHM_BoardStatus(
  TS_LIBBSP_SHM_BoardStatus *kcg_c1,
  TS_LIBBSP_SHM_BoardStatus *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->inhibit_wdg == kcg_c2->inhibit_wdg);
  kcg_equ = kcg_equ & (kcg_c1->pgood_vrm == kcg_c2->pgood_vrm);
  kcg_equ = kcg_equ & (kcg_c1->pgood_vant == kcg_c2->pgood_vant);
  kcg_equ = kcg_equ & (kcg_c1->tank_fail == kcg_c2->tank_fail);
  kcg_equ = kcg_equ & (kcg_c1->lvdd_type == kcg_c2->lvdd_type);
  kcg_equ = kcg_equ & (kcg_c1->therm2 == kcg_c2->therm2);
  kcg_equ = kcg_equ & (kcg_c1->therm == kcg_c2->therm);
  kcg_equ = kcg_equ & (kcg_c1->meg_pll_lock == kcg_c2->meg_pll_lock);
  kcg_equ = kcg_equ & (kcg_c1->meg_fail == kcg_c2->meg_fail);
  kcg_equ = kcg_equ & (kcg_c1->pgood_1v2meg == kcg_c2->pgood_1v2meg);
  kcg_equ = kcg_equ & (kcg_c1->pgood_p2v5 == kcg_c2->pgood_p2v5);
  kcg_equ = kcg_equ & (kcg_c1->trig_out == kcg_c2->trig_out);
  kcg_equ = kcg_equ & (kcg_c1->ready_p1 == kcg_c2->ready_p1);
  kcg_equ = kcg_equ & (kcg_c1->mezz_fail == kcg_c2->mezz_fail);
  kcg_equ = kcg_equ & (kcg_c1->mezz_pgood == kcg_c2->mezz_pgood);
  kcg_equ = kcg_equ & (kcg_c1->cpcm_1v8_ov == kcg_c2->cpcm_1v8_ov);
  kcg_equ = kcg_equ & (kcg_c1->cpcm_1v8_uv == kcg_c2->cpcm_1v8_uv);
  kcg_equ = kcg_equ & (kcg_c1->vio_3v3_ov == kcg_c2->vio_3v3_ov);
  kcg_equ = kcg_equ & (kcg_c1->vio_3v3_uv == kcg_c2->vio_3v3_uv);
  kcg_equ = kcg_equ & (kcg_c1->cpcm_1v5_ov == kcg_c2->cpcm_1v5_ov);
  kcg_equ = kcg_equ & (kcg_c1->cpcm_1v5_uv == kcg_c2->cpcm_1v5_uv);
  kcg_equ = kcg_equ & (kcg_c1->vdd_ov == kcg_c2->vdd_ov);
  kcg_equ = kcg_equ & (kcg_c1->vdd_uv == kcg_c2->vdd_uv);
  kcg_equ = kcg_equ & (kcg_c1->ddr_vtt_ov == kcg_c2->ddr_vtt_ov);
  kcg_equ = kcg_equ & (kcg_c1->ddr_vtt_uv == kcg_c2->ddr_vtt_uv);
  kcg_equ = kcg_equ & (kcg_c1->pwr_good_28v2 == kcg_c2->pwr_good_28v2);
  kcg_equ = kcg_equ & (kcg_c1->pwr_good_28v1 == kcg_c2->pwr_good_28v1);
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_SHM_BoardStatus */

#ifdef kcg_use_TS_LIBBSP_ETSEC_ConfHostMac
kcg_bool kcg_comp_TS_LIBBSP_ETSEC_ConfHostMac(
  TS_LIBBSP_ETSEC_ConfHostMac *kcg_c1,
  TS_LIBBSP_ETSEC_ConfHostMac *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_ETSEC_MacAddr(
      &kcg_c1->mac_addr,
      &kcg_c2->mac_addr);
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_ETSEC_ConfHostMac */

#ifdef kcg_use_TS_LIBBSP_PSUM_Conf
kcg_bool kcg_comp_TS_LIBBSP_PSUM_Conf(
  TS_LIBBSP_PSUM_Conf *kcg_c1,
  TS_LIBBSP_PSUM_Conf *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->v_data == kcg_c2->v_data);
  kcg_equ = kcg_equ & (kcg_c1->v_address == kcg_c2->v_address);
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_PSUM_Conf */

#ifdef kcg_use_TS_LIBBSP_PSUM_AdcErrorFlags
kcg_bool kcg_comp_TS_LIBBSP_PSUM_AdcErrorFlags(
  TS_LIBBSP_PSUM_AdcErrorFlags *kcg_c1,
  TS_LIBBSP_PSUM_AdcErrorFlags *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->GeneralFailure == kcg_c2->GeneralFailure);
  kcg_equ = kcg_equ & (kcg_c1->Vin7NotInRange == kcg_c2->Vin7NotInRange);
  kcg_equ = kcg_equ & (kcg_c1->ReferenceVoltageFailure ==
      kcg_c2->ReferenceVoltageFailure);
  kcg_equ = kcg_equ & (kcg_c1->UnderVoltage == kcg_c2->UnderVoltage);
  kcg_equ = kcg_equ & (kcg_c1->OverVoltage == kcg_c2->OverVoltage);
  kcg_equ = kcg_equ & (kcg_c1->PresFail_or_Vin6Failure ==
      kcg_c2->PresFail_or_Vin6Failure);
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_PSUM_AdcErrorFlags */

#ifdef kcg_use_TS_LIBBSP_SHM_CompStatus
kcg_bool kcg_comp_TS_LIBBSP_SHM_CompStatus(
  TS_LIBBSP_SHM_CompStatus *kcg_c1,
  TS_LIBBSP_SHM_CompStatus *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->critical_uvd_cnt == kcg_c2->critical_uvd_cnt);
  kcg_equ = kcg_equ & (kcg_c1->hw_reset_request_cnt ==
      kcg_c2->hw_reset_request_cnt);
  kcg_equ = kcg_equ & (kcg_c1->sw_reset_request_cnt ==
      kcg_c2->sw_reset_request_cnt);
  kcg_equ = kcg_equ & (kcg_c1->wd_failure_cnt == kcg_c2->wd_failure_cnt);
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_SHM_CompStatus */

#ifdef kcg_use_TS_LIBBSP_ETR_ReadInfos
kcg_bool kcg_comp_TS_LIBBSP_ETR_ReadInfos(
  TS_LIBBSP_ETR_ReadInfos *kcg_c1,
  TS_LIBBSP_ETR_ReadInfos *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->v_EventCountdata == kcg_c2->v_EventCountdata);
  kcg_equ = kcg_equ & (kcg_c1->v_ETregdata == kcg_c2->v_ETregdata);
  kcg_equ = kcg_equ & (kcg_c1->v_AlarmRegdata == kcg_c2->v_AlarmRegdata);
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_ETR_ReadInfos */

#ifdef kcg_use_TS_LIBBSP_PLDCMP_ErrorStatus
kcg_bool kcg_comp_TS_LIBBSP_PLDCMP_ErrorStatus(
  TS_LIBBSP_PLDCMP_ErrorStatus *kcg_c1,
  TS_LIBBSP_PLDCMP_ErrorStatus *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->wdg_comp_rst == kcg_c2->wdg_comp_rst);
  kcg_equ = kcg_equ & (kcg_c1->overload_error == kcg_c2->overload_error);
  kcg_equ = kcg_equ & (kcg_c1->timeout_error == kcg_c2->timeout_error);
  kcg_equ = kcg_equ & (kcg_c1->acc_error == kcg_c2->acc_error);
  kcg_equ = kcg_equ & (kcg_c1->addr_error == kcg_c2->addr_error);
  kcg_equ = kcg_equ & (kcg_c1->parity_error == kcg_c2->parity_error);
  kcg_equ = kcg_equ & (kcg_c1->nvm_error == kcg_c2->nvm_error);
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_PLDCMP_ErrorStatus */

#ifdef kcg_use_TS_LIBBSP_PLDMEG_IfCpuStatus
kcg_bool kcg_comp_TS_LIBBSP_PLDMEG_IfCpuStatus(
  TS_LIBBSP_PLDMEG_IfCpuStatus *kcg_c1,
  TS_LIBBSP_PLDMEG_IfCpuStatus *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->error_counter == kcg_c2->error_counter);
  kcg_equ = kcg_equ & (kcg_c1->overload_error == kcg_c2->overload_error);
  kcg_equ = kcg_equ & (kcg_c1->timeout_error == kcg_c2->timeout_error);
  kcg_equ = kcg_equ & (kcg_c1->acc_error == kcg_c2->acc_error);
  kcg_equ = kcg_equ & (kcg_c1->addr_error == kcg_c2->addr_error);
  kcg_equ = kcg_equ & (kcg_c1->parity_error == kcg_c2->parity_error);
  return kcg_equ;
}
#endif /* kcg_use_TS_LIBBSP_PLDMEG_IfCpuStatus */

/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** kcg_types.c
** Generation date: 2022-10-20T18:05:10
*************************************************************$ */

