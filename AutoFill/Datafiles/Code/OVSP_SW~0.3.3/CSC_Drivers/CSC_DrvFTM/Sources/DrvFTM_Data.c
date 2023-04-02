/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvGPIO CSC data definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTM_Private.h"
#include "DrvFTM_Public.h"


/* ---------- include required interface: ----------------------------------- */
#include "DrvNVIC_Public.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* {{RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data are not internal as shared within the CSC. */
/* {{RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as they are 32-bit Unsigned Long address */
/* converted to pointers which are also an 32-bit Unsigned Long. */
TS_DrvFTM_Registers * const C_DrvFTM_Controller[DRVFTM_CONTROLS_COUNT]=
{
   (TS_DrvFTM_Registers*) DRVFTM_FTM0_ADDRESS,
   (TS_DrvFTM_Registers*) DRVFTM_FTM1_ADDRESS,
   (TS_DrvFTM_Registers*) DRVFTM_FTM2_ADDRESS,
   (TS_DrvFTM_Registers*) DRVFTM_FTM3_ADDRESS
};
/* }} RELAX<SYNCHRONe_C_Code_10.7> */

/* {{RELAX<SYNCHRONe_C_Code_23.2> CR lem#11175: Braces and comma have not to be on next line for "Initializer list" */
const TS_DrvFTM_Freq_Port_Config C_DrvFTM_Freq_Port_Config [DRVFTM_OVSP_SIDE_NB] [DRVFTM_FREQS_NB] =
{
   {
      {DRVFTM_TIMER_0, DRVFTM_CHAN_4, DRVFTM_NGOS1_OFF_CNSC_CONFIG_HS, DRVFTM_FREQ_FTM0_SC_CONFIG},
      {DRVFTM_TIMER_0, DRVFTM_CHAN_2, DRVFTM_NTLOS1_OFF_CNSC_CONFIG_HS, DRVFTM_FREQ_FTM0_SC_CONFIG},
      {DRVFTM_TIMER_3, DRVFTM_CHAN_0, DRVFTM_NGOS2_OFF_CNSC_CONFIG_HS, DRVFTM_FREQ_FTM3_SC_CONFIG},
      {DRVFTM_TIMER_3, DRVFTM_CHAN_4, DRVFTM_NTLOS2_OFF_CNSC_CONFIG_HS, DRVFTM_FREQ_FTM3_SC_CONFIG},
      {DRVFTM_TIMER_0, DRVFTM_CHAN_1, DRVFTM_TSPEED_OFF_CNSC_CONFIG_HS, DRVFTM_FREQ_FTM0_SC_CONFIG},
   },
   {
      {DRVFTM_TIMER_0, DRVFTM_CHAN_4, DRVFTM_NGOS1_OFF_CNSC_CONFIG_LS, DRVFTM_FREQ_FTM0_SC_CONFIG},
      {DRVFTM_TIMER_0, DRVFTM_CHAN_2, DRVFTM_NTLOS1_OFF_CNSC_CONFIG_LS, DRVFTM_FREQ_FTM0_SC_CONFIG},
      {DRVFTM_TIMER_3, DRVFTM_CHAN_0, DRVFTM_NGOS2_OFF_CNSC_CONFIG_LS, DRVFTM_FREQ_FTM3_SC_CONFIG},
      {DRVFTM_TIMER_3, DRVFTM_CHAN_4, DRVFTM_NTLOS2_OFF_CNSC_CONFIG_LS, DRVFTM_FREQ_FTM3_SC_CONFIG},
      {DRVFTM_TIMER_1, DRVFTM_CHAN_5, DRVFTM_TSPEED_OFF_CNSC_CONFIG_LS, DRVFTM_FREQ_FTM1_SC_CONFIG},
   }
};

const TS_DrvFTM_CAM_Port_Config C_DrvFTM_CAM_Port_Config =
{
   DRVFTM_TIMER_2,
   DRVFTM_CHAN_4,
   DRVFTM_CAM_CNSC_CONFIG_HS,
   DRVFTM_CAM_CNV_CONFIG_HS,
   DRVFTM_CAM_MOD_CONFIG_HS,
   DRVFTM_CAM_SC_CONFIG_HS
};

const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Acq_NGOS1 = &DrvFTM_Acquire_Raw_NGOS1;
const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Acq_NGOS2 = &DrvFTM_Acquire_Raw_NGOS2;
const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Acq_NTLOS1 = &DrvFTM_Acquire_Raw_NTLOS1;
const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Acq_NTLOS2 = &DrvFTM_Acquire_Raw_NTLOS2;

const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Count_FTM0_Overflow = &DrvFTM_Count_FTM0_Overflow;
const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Count_FTM1_Overflow = &DrvFTM_Count_FTM1_Overflow;
const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Count_FTM3_Overflow = &DrvFTM_Count_FTM3_Overflow;

const TPTF_DrvNVIC_VectorsTable C_PtF_DrvFTM_Acq_Raw_TSpeed = &DrvFTM_Acquire_Raw_TSpeed;
/* }} RELAX<SYNCHRONe_C_Code_23.2> */
/* }} RELAX<SYNCHRONe_C_Code_24.5> */


/* ---------- provided data: ------------------------------------------------ */
TS_DrvFTM_Acq_Raw_Freq_Data V_DrvFTM_Acq_Raw_Freq_Data[DRVFTM_FREQS_NB];

TE_DrvFTM_TSpeed_State V_DrvFTM_TSpeed_State;
float32_t V_DrvFTM_TSpeed_Applied_Speed;
float32_t V_DrvFTM_TSpeed_Test_Speed_Prev;
boolean_t V_DrvFTM_New_Test_Speed_Recv;
boolean_t V_DrvFTM_TSpeed_Activation_Status;
uint16_t V_DrvFTM_TSpeed_Signal_Mod;
/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* None */
