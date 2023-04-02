/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVFTM_PRIVATE_H
#define DRVFTM_PRIVATE_H

/* ---------- include predefined types: ------------------------------------- */
#include "MCP_Types.h"
#include "DrvFTM_Public.h"

/* ---------- include required interface: ----------------------------------- */
/* None */
/* ---------- provided define Variables: ------------------------------------ */
// uint8_t DRV_OVSP_FLEXTIMER__NbCaptureValInTimeoutNGOS1 = 0;
// uint8_t DRV_OVSP_FLEXTIMER_PlaceValInTabNGOS1 = 0;
// boolean_t DRV_OVSP_FLEXTIMER_CalNGOS1_ok = FALSE;

/* ---------- provided define constants: ------------------------------------ */
#define DRVFTM_FTM0_ADDRESS                     0x40038000UL
#define DRVFTM_FTM1_ADDRESS                     0x40039000UL
#define DRVFTM_FTM2_ADDRESS                     0x4003A000UL
#define DRVFTM_FTM3_ADDRESS                     0x40026000UL

#define DRVFTM_NGOS1_OFF_CNSC_CONFIG_HS         0x00000448UL
#define DRVFTM_NTLOS1_OFF_CNSC_CONFIG_HS        0x00000448UL
#define DRVFTM_NGOS2_OFF_CNSC_CONFIG_HS         0x00000448UL
#define DRVFTM_NTLOS2_OFF_CNSC_CONFIG_HS        0x00000448UL
#define DRVFTM_TSPEED_OFF_CNSC_CONFIG_HS        0x00000448UL

#define DRVFTM_NGOS1_ON_CNSC_CONFIG_HS          0x00000048UL
#define DRVFTM_NTLOS1_ON_CNSC_CONFIG_HS         0x00000048UL
#define DRVFTM_NGOS2_ON_CNSC_CONFIG_HS          0x00000048UL
#define DRVFTM_NTLOS2_ON_CNSC_CONFIG_HS         0x00000048UL
#define DRVFTM_TSPEED_ON_CNSC_CONFIG_HS         0x00000048UL

#define DRVFTM_NXOSY_RUNNING_CNSC_MASK          0x0000017FUL

#define DRVFTM_NGOS1_OFF_CNSC_CONFIG_LS         0x0000044CUL
#define DRVFTM_NTLOS1_OFF_CNSC_CONFIG_LS        0x0000044CUL
#define DRVFTM_NGOS2_OFF_CNSC_CONFIG_LS         0x0000044CUL
#define DRVFTM_NTLOS2_OFF_CNSC_CONFIG_LS        0x0000044CUL
#define DRVFTM_TSPEED_OFF_CNSC_CONFIG_LS        0x0000044CUL

#define DRVFTM_NGOS1_ON_CNSC_CONFIG_LS          0x0000004CUL
#define DRVFTM_NTLOS1_ON_CNSC_CONFIG_LS         0x0000004CUL
#define DRVFTM_NGOS2_ON_CNSC_CONFIG_LS          0x0000004CUL
#define DRVFTM_NTLOS2_ON_CNSC_CONFIG_LS         0x0000004CUL
#define DRVFTM_TSPEED_ON_CNSC_CONFIG_LS         0x0000004CUL

#define DRVFTM_CAM_CNSC_CONFIG_HS               0x00000050UL
#define DRVFTM_CAM_CNV_CONFIG_HS                0x0000004AUL
#define DRVFTM_CAM_MOD_CONFIG_HS                0x0000004AUL
#define DRVFTM_CAM_SC_CONFIG_HS                 0x00100388UL
#define DRVFTM_CAM_POL_CONFIG_HS                0x00000000UL

#define DRVFTM_CNTIN_CONFIG                     0UL
#define DRVFTM_COMBINE_CONFIG                   0UL

#define DRVFTM_FREQ_FTM0_SC_CONFIG              0x00000388UL
#define DRVFTM_FREQ_FTM3_SC_CONFIG              0x00000388UL
#define DRVFTM_FREQ_FTM1_SC_CONFIG              0x00000388UL

#define DRVFTM_SC_DEFAULT                       0x00000000UL

#define DRVFTM_FTM_NUMBER                       4UL

#define DRVFTM_FREQ_PORTS_NB                    4UL
#define DRVFTM_CAM_PORT_NB                      1UL

#define DRVFTM_DRVFTM_PORTS_NB                  5UL

#define DRVFTM_FREQS_NB                         5UL

#define DRVFTM_OVSP_HS_ID                       0UL
#define DRVFTM_OVSP_LS_ID                       1UL

#define DRVFTM_FREQ_CLK_HZ                      75000000UL
#define DRVFTM_FREQUENCIES_PERIODS_NB           100UL
#define DRVFTM_TIMER_NB_MAX_VALUES              65536UL

#define DRVFTM_TSPEED_SIGNAL_OK                 0UL
#define DRVFTM_TSPEED_SIGNAL_KO                 1UL
#define DRVFTM_TSPEED_SIGNAL_ON                 TRUE
#define DRVFTM_TSPEED_SIGNAL_OFF                FALSE

#define DRVFTM_OVSP_SIDE_NB                     2UL


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t S_Timer_Id;
   uint32_t S_Channel_Id;
   uint32_t S_CnSC_Config;
   uint32_t S_SC_Config;
} TS_DrvFTM_Freq_Port_Config;

typedef struct
{
   uint32_t S_Timer_Id;
   uint32_t S_Channel_Id;
   uint32_t S_CnSC_Config;
   uint32_t S_CnV_Config;
   uint32_t S_MOD_Config;
   uint32_t S_SC_Config;
} TS_DrvFTM_CAM_Port_Config;

typedef struct
{
    volatile uint32_t * S_Freq_CnV;
    volatile uint32_t * S_Freq_CnSC;
    volatile uint32_t * S_Freq_SC;
    volatile uint32_t * S_Freq_Cnt;
    volatile uint32_t S_Timer_Id;
    volatile uint32_t S_Timer_Side;
    volatile uint32_t S_LastPeriod_Index;
    volatile uint32_t S_NbPeriods_Acquired;
    volatile uint32_t S_PeriodCnt_Prev;
    volatile uint32_t S_OFlow_Cpt;
    volatile uint32_t S_OFlow_Cpt_Prev;
} TS_DrvFTM_Acq_Raw_Freq_Data;


/* ---------- provided data: ------------------------------------------------ */
/* None */

/* ---------- provided constants: ------------------------------------------- */
extern const TS_DrvFTM_Freq_Port_Config C_DrvFTM_Freq_Port_Config [DRVFTM_OVSP_SIDE_NB] [DRVFTM_FREQS_NB];
extern const TS_DrvFTM_CAM_Port_Config C_DrvFTM_CAM_Port_Config;

/* ---------- provided data: ------------------------------------------------ */
extern TS_DrvFTM_Acq_Raw_Freq_Data V_DrvFTM_Acq_Raw_Freq_Data[DRVFTM_FREQS_NB];

extern TE_DrvFTM_TSpeed_State V_DrvFTM_TSpeed_State;
extern volatile boolean_t V_DrvFTM_TSpeed_First_Attempt;
extern float32_t V_DrvFTM_TSpeed_Applied_Speed;
extern float32_t V_DrvFTM_TSpeed_Test_Speed_Prev;
extern boolean_t V_DrvFTM_New_Test_Speed_Recv;
extern boolean_t V_DrvFTM_TSpeed_Activation_Status;
extern uint16_t V_DrvFTM_TSpeed_Signal_Mod;
/* ---------- provided operations: ------------------------------------------ */
extern void DrvFTM_Check_TSpeed_HS_RegConfig (uint32_t * const p_pt_Check_Result);
extern void DrvFTM_Check_TSpeed_LS_RegConfig (uint32_t * const p_pt_Check_Result);

extern void DrvFTM_Initialize_Freq_Acq_Data (void);

extern void DrvFTM_Start_NGOS1_Acquisition (void);
extern void DrvFTM_Start_NGOS2_Acquisition (void);
extern void DrvFTM_Start_NTLOS1_Acquisition (void);
extern void DrvFTM_Start_NTLOS2_Acquisition (void);

extern void DrvFTM_Stop_NGOS1_Acquisition (void);
extern void DrvFTM_Stop_NGOS2_Acquisition (void);
extern void DrvFTM_Stop_NTLOS1_Acquisition (void);
extern void DrvFTM_Stop_NTLOS2_Acquisition (void);

extern void DrvFTM_Acquire_RawData (uint32_t p_freq_id);
extern void DrvFTM_Acquire_Raw_NGOS1 (void);
extern void DrvFTM_Acquire_Raw_NGOS2 (void);
extern void DrvFTM_Acquire_Raw_NTLOS1 (void);
extern void DrvFTM_Acquire_Raw_NTLOS2 (void);
extern void DrvFTM_Acquire_Raw_TSpeed (void);


extern void DrvFTM_Count_Overflow (uint32_t p_freq_id, uint32_t p_timer_id);
extern void DrvFTM_Count_FTM0_Overflow (void);
extern void DrvFTM_Count_FTM1_Overflow (void);
extern void DrvFTM_Count_FTM3_Overflow (void);
#endif /* DRVFTM_PRIVATE_H */
