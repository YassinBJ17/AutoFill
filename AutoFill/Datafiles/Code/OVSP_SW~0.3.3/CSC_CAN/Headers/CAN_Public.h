/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef CAN_PUBLIC_H
#define CAN_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define CAN_SET_PARAM_32BIT_NB          22UL
#define CAN_SET_PARAM_FIRST_FLOAT_INDEX 10UL


/* ---------- provided types: ----------------------------------------------- */
typedef enum
{
   E_CAN_TriggTest_On = 0,
   E_CAN_TriggTest_Off = 1,
   E_CAN_TriggTest_Invalid = 2
} TE_CAN_TriggTest_Cmd;

typedef union
{
   uint32_t U_Array_32BitUint [CAN_SET_PARAM_32BIT_NB];

   struct
   {
      uint8_t S_OVS_OneSensorNGInhib;
      uint8_t S_OVS_CSSInhib;
      uint8_t S_OVS_NGInhib;
      uint8_t S_OVS_NTLThresholdInhib;

      uint8_t S_Frame1_Unused_1;
      uint8_t S_Frame1_Unused_0;
      uint8_t S_Interlock_Inhib;
      uint8_t S_OVS_OneSensorNTLInhib;


      uint8_t S_NTLOS2_NH;
      uint8_t S_NTLOS2_NL;
      uint8_t S_NTLOS1_NH;
      uint8_t S_NTLOS1_NL;

      uint8_t S_Frame2_Unused_1;
      uint8_t S_Frame2_Unused_0;
      uint8_t S_NTL_OVS_FUNCTION;
      uint8_t S_NTL_OVSTHRESD_N;


      uint8_t S_NGOS2_NH;
      uint8_t S_NGOS2_NL;
      uint8_t S_NGOS1_NH;
      uint8_t S_NGOS1_NL;

      uint8_t S_Frame3_Unused_2;
      uint8_t S_Frame3_Unused_1;
      uint8_t S_Frame3_Unused_0;
      uint8_t S_NG_OVSTHRESD_N;


      uint8_t S_NG_OVSTHRESD_Threshold_Ar_3;
      uint8_t S_NG_OVSTHRESD_Threshold_Ar_2;
      uint8_t S_NG_OVSTHRESD_Threshold_Ar_1;
      uint8_t S_NG_OVSTHRESD_Threshold_Ar_0;

      uint8_t S_Frame4_Unused_1;
      uint8_t S_Frame4_Unused_0;
      uint8_t S_NG_OVSTHRESD_Threshold_Ar_5;
      uint8_t S_NG_OVSTHRESD_Threshold_Ar_4;


      uint8_t S_NTL_OVSVARIABLE_Threshold_Ar_3;
      uint8_t S_NTL_OVSVARIABLE_Threshold_Ar_2;
      uint8_t S_NTL_OVSVARIABLE_Threshold_Ar_1;
      uint8_t S_NTL_OVSVARIABLE_Threshold_Ar_0;

      uint8_t S_Frame5_Unused_1;
      uint8_t S_Frame5_Unused_0;
      uint8_t S_NTL_OVSVARIABLE_Threshold_Ar_5;
      uint8_t S_NTL_OVSVARIABLE_Threshold_Ar_4;


      float32_t S_NGOS1_Timeout;
      float32_t S_NGOS1_100;

      float32_t S_NGOS2_Timeout;
      float32_t S_NGOS2_100;

      float32_t S_NTLOS1_Timeout;
      float32_t S_NTLOS1_100;

      float32_t S_NTLOS2_Timeout;
      float32_t S_NTLOS2_100;

      float32_t S_NTL_OVSTHRESD_Threshold;
      float32_t S_NTL_OVSTHRESD_Window;

      float32_t S_NG_OVSTHRESD_Threshold;
      float32_t S_NG_OVSTHRESD_Window;
   } U_Fields;

} TU_CAN_SET_PARAM_Frames;


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void CAN_Initialize (void);
extern void CAN_Treatments (void);

extern TE_CAN_TriggTest_Cmd CAN_Get_TriggTest_Cmd (void);
extern float32_t CAN_Get_Test_Speed (void);

extern TE_OVSP_SW_Cmd CAN_Get_TestDiscrete_Cmd (void);

extern TE_OVSP_SW_Cmd CAN_Get_CAM_Cmd_1 (void);
extern TE_OVSP_SW_Cmd CAN_Get_CAM_Cmd_2 (void);

extern TE_OVSP_SW_Request CAN_Get_OSARM_Rqst (void);
extern TE_OVSP_SW_Request CAN_Get_REARM_Rqst (void);

extern boolean_t CAN_Get_NG_NTL_Statuses_Sent (void);

extern TE_OVSP_SW_OneSensor_Auth CAN_Get_NTL_OneSensor_CSSAuth (void);
extern TE_OVSP_SW_OneSensor_Auth CAN_Get_NG_OneSensor_CSSAuth (void);

extern void CAN_Reset_TestDiscrete_Cmd (void);


#endif /* CAN_PUBLIC_H */
