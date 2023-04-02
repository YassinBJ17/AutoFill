/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVFTM_PUBLIC_H
#define DRVFTM_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "DrvNVIC_Public.h"

#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVFTM_TIMER_0 0UL
#define DRVFTM_TIMER_1 1UL
#define DRVFTM_TIMER_2 2UL
#define DRVFTM_TIMER_3 3UL
#define DRVFTM_TIMER_4 4UL
#define DRVFTM_TIMER_5 5UL
#define DRVFTM_TIMER_6 6UL
#define DRVFTM_TIMER_7 7UL

#define DRVFTM_CHAN_0 0UL
#define DRVFTM_CHAN_1 1UL
#define DRVFTM_CHAN_2 2UL
#define DRVFTM_CHAN_3 3UL
#define DRVFTM_CHAN_4 4UL
#define DRVFTM_CHAN_5 5UL
#define DRVFTM_CHAN_6 6UL
#define DRVFTM_CHAN_7 7UL

/* S_SC Bit Fields */
#define DRVFTM_SC_CLKS_MASK                         (uint8_t)(0x18u)
#define DRVFTM_SC_CLKS_SHIFT                        (uint8_t)(3u)
#define DRVFTM_SC_TOIE_MASK                         (uint16_t)(0x100u)
#define DRVFTM_SC_TOIE_SHIFT                        (uint8_t)(8u)
#define DRVFTM_SC_TOF_MASK                          0x00000200UL
#define DRVFTM_SC_TOF_SHIFT                         9UL

#define DRVFTM_SC_PS_MASK                           0x7u
#define DRVFTM_SC_PS_SHIFT                          0u
#define DRVFTM_SC_PS_WIDTH                          3u
#define DRVFTM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<DRVFTM_SC_PS_SHIFT)) & DRVFTM_SC_PS_MASK)
#define DRVFTM_SC_CLKS_WIDTH                        2u
#define DRVFTM_SC_CLKS(x)                           (((uint32_t)(((uint32_t)(x))<<DRVFTM_SC_CLKS_SHIFT)) & DRVFTM_SC_CLKS_MASK)
#define DRVFTM_SC_CPWMS_MASK                        0x20u
#define DRVFTM_SC_CPWMS_SHIFT                       5u
#define DRVFTM_SC_CPWMS_WIDTH                       1u
#define DRVFTM_SC_CPWMS(x)                          (((uint32_t)(((uint32_t)(x))<<DRVFTM_SC_CPWMS_SHIFT)) & DRVFTM_SC_CPWMS_MASK)

#define DRVFTM_SC_PWMEN0_MASK                       0x10000u
#define DRVFTM_SC_PWMEN0_SHIFT                      16u
#define DRVFTM_SC_PWMEN1_MASK                       0x20000u
#define DRVFTM_SC_PWMEN1_SHIFT                      17u
#define DRVFTM_SC_PWMEN2_MASK                       0x40000u
#define DRVFTM_SC_PWMEN2_SHIFT                      18u
#define DRVFTM_SC_PWMEN3_MASK                       0x80000u
#define DRVFTM_SC_PWMEN3_SHIFT                      19u
#define DRVFTM_SC_PWMEN4_MASK                       0x100000u
#define DRVFTM_SC_PWMEN4_SHIFT                      20u
#define DRVFTM_SC_PWMEN5_MASK                       0x200000u
#define DRVFTM_SC_PWMEN5_SHIFT                      21u
#define DRVFTM_SC_PWMEN6_MASK                       0x400000u
#define DRVFTM_SC_PWMEN6_SHIFT                      22u
#define DRVFTM_SC_PWMEN7_MASK                       0x800000u
#define DRVFTM_SC_PWMEN7_SHIFT                      23u
/* CnSC Bit Fields */
#define DRVFTM_CNSC_ELSA_MASK                       0x00000004UL
#define DRVFTM_CNSC_ELSA_SHIFT                      2UL
#define DRVFTM_CNSC_ELSB_MASK                       0x00000008UL
#define DRVFTM_CNSC_ELSB_SHIFT                      3UL
#define DRVFTM_CNSC_MSA_MASK                        0x00000010UL
#define DRVFTM_CNSC_MSA_SHIFT                       4UL
#define DRVFTM_CNSC_MSB_MASK                        0x00000020UL
#define DRVFTM_CNSC_MSB_SHIFT                       5UL
#define DRVFTM_CNSC_CHIE_MASK                       0x00000040UL
#define DRVFTM_CNSC_CHIE_SHIFT                      6UL
#define DRVFTM_CNSC_CHF_MASK                        0x00000080UL
#define DRVFTM_CNSC_CHF_SHIFT                       7UL

/** FTM - Size of Registers Arrays */
#define DRVFTM_CONTROLS_COUNT                       8UL

#define DRVFTM_NGOS1_DATA_ID                    0UL
#define DRVFTM_NTLOS1_DATA_ID                   1UL
#define DRVFTM_NGOS2_DATA_ID                    2UL
#define DRVFTM_NTLOS2_DATA_ID                   3UL
#define DRVFTM_TSPEED_DATA_ID                   4UL

/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t S_CnSC;
   uint32_t S_CnV;
} TS_DrvFTM_CnSC_CnV;

typedef struct
{
   uint32_t S_SC;
   uint32_t S_CNT;
   uint32_t S_MOD;
   TS_DrvFTM_CnSC_CnV S_CONTROLS [DRVFTM_CONTROLS_COUNT];
   uint32_t S_CNTIN;
   uint32_t S_STATUS;
   uint32_t S_MODE;
   uint32_t S_SYNC;
   uint32_t S_OUTINIT;
   uint32_t S_OUTMASK;
   uint32_t S_COMBINE;
   uint32_t S_DEADTIME;
   uint32_t S_EXTTRIG;
   uint32_t S_POL;
   uint32_t S_FMS;
   uint32_t S_FILTER;
   uint32_t S_FLTCTRL;
   uint32_t S_QDCTRL;
   uint32_t S_CONF;
   uint32_t S_FLTPOL;
   uint32_t S_SYNCONF;
   uint32_t S_INVCTRL;
   uint32_t S_SWOCTRL;
   uint32_t S_PWMLOAD;
   uint32_t S_HCR;
   uint32_t S_PAIR0DEADTIME;
   uint8_t  S_RESERVED_0 [4];
   uint32_t S_PAIR1DEADTIME;
   uint8_t  S_RESERVED_1 [4];
   uint32_t S_PAIR2DEADTIME;
   uint8_t  S_RESERVED_2 [4];
   uint32_t S_PAIR3DEADTIME;
} TS_DrvFTM_Registers;

typedef enum
{
   E_DrvFTM_TSpeed_Idle        = 0,
   E_DrvFTM_TSpeed_Activated   = 1,
   E_DrvFTM_TSpeed_Deactivated = 2
} TE_DrvFTM_TSpeed_State;


/* ---------- provided constants: ------------------------------------------- */
extern TS_DrvFTM_Registers * const C_DrvFTM_Controller [DRVFTM_CONTROLS_COUNT];

extern const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Acq_NGOS1;
extern const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Acq_NGOS2;
extern const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Acq_NTLOS1;
extern const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Acq_NTLOS2;

extern const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Count_FTM0_Overflow;
extern const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Count_FTM1_Overflow;
extern const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Count_FTM3_Overflow;

extern const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Acq_Raw_TSpeed;

/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void DrvFTM_Initialize (void);

extern void DrvFTM_Check_Freqs_RegConfig (uint32_t * const p_pt_Check_Result);
extern void DrvFTM_Check_CAM_RegConfig (uint32_t * const p_pt_Check_Result);
extern void DrvFTM_Check_TSpeed_RegConfig (uint32_t * const p_pt_Check_Result);

extern void DrvFTM_Start (uint32_t p_ftm_id);
extern void DrvFTM_Stop (uint32_t p_ftm_id);

extern void DrvFTM_Start_TSpeed_HS (uint16_t p_mod);
extern void DrvFTM_Start_TSpeed_LS (uint16_t p_mod);
extern void DrvFTM_Stop_TSpeed_HS (void);
extern void DrvFTM_Stop_TSpeed_LS (void);
extern void DrvFTM_Manage_TSpeed_Signal (void);
extern void DrvFTM_Prepare_TSpeed_Signal (float32_t p_trig_speed);

extern void DrvFTM_Initialize_TSpeed_Data (void);


extern void DrvFTM_Start_Freqs_Acq (void);
extern void DrvFTM_Stop_Freqs_Acq (void);


extern uint32_t DrvFTM_Get_NbPeriods_Acquired (uint32_t p_freq_id);
extern uint32_t DrvFTM_Get_LastPeriod_Index (uint32_t p_freq_id);

extern uint32_t DrvFTM_Get_TSpeed_LastPeriod_Index (void);
extern uint32_t DrvFTM_Get_TSpeed_NbPeriods_Acquired (void);

extern void DrvFTM_Start_CAM_Generation (void);
extern void DrvFTM_Stop_CAM_Generation (void);


#endif /* DRVFTM_PUBLIC_H */
