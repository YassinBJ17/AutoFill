/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef CONFIG_PRIVATE_H
#define CONFIG_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "Config_Public.h"
#include "DrvFTFC_Public.h"

#include "OVSP_SW_Public.h"
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define CONFIG_FIRST_FLOAT_INDEX      10UL
#define CONFIG_FIRST_RESERVED_INDEX   22UL

#define CONFIG_NTL_VAR_THRES_NB       6UL


/* ---------- provided types: ----------------------------------------------- */
typedef union
{
   uint32_t U_Array_32BitUint [DRVFTFC_CONFIG_32BIT_NB];

   struct
   {
      uint8_t S_OVS_NTLThresholdInhib;
      uint8_t S_OVS_NGInhib;
      uint8_t S_OVS_CSSInhib;
      uint8_t S_OVS_OneSensorNGInhib;
      uint8_t S_OVS_OneSensorNTLInhib;
      uint8_t S_Interlock_Inhib;
      uint8_t S_Config_Spare_1 [2];

      uint8_t S_NTLOS1_NL;
      uint8_t S_NTLOS1_NH;
      uint8_t S_NTLOS2_NL;
      uint8_t S_NTLOS2_NH;
      uint8_t S_NTL_OVSTHRESD_N;
      uint8_t S_NTL_OVS_FUNCTION;
      uint8_t S_Config_Spare_2 [2];

      uint8_t S_NGOS1_NL;
      uint8_t S_NGOS1_NH;
      uint8_t S_NGOS2_NL;
      uint8_t S_NGOS2_NH;
      uint8_t S_NG_OVSTHRESD_N;
      uint8_t S_Config_Spare_3 [3];

      uint8_t S_NG_OVSTHRESD_Threshold_Ar [CONFIG_NTL_VAR_THRES_NB];
      uint8_t S_Config_Spare_4 [2];

      uint8_t S_NTL_OVSVARIABLE_Threshold_Ar [CONFIG_NTL_VAR_THRES_NB];
      uint8_t S_Config_Spare_5 [2];

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

      uint8_t S_Config_Reserved [38];

      uint8_t S_16BitCRC_MSB;
      uint8_t S_16BitCRC_LSB;
   } U_Fields;

} TU_Config_OVSP_Cfg;


typedef enum
{
   E_Config_OVSP_Cfg_None = 0,
   E_Config_OVSP_Cfg_Used = 1,
   E_Config_OVSP_Cfg_New = 2
} TE_Config_OVSP_Cfg_Type;


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
extern TU_Config_OVSP_Cfg V_Config_OVSP_Cfg_Used;
extern TU_Config_OVSP_Cfg V_Config_OVSP_Cfg_New;
extern TU_Config_OVSP_Cfg V_Config_OVSP_Cfg_Buffer;

extern TU_OVSP_SW_Uint16_Uint8 V_Last_Computed_16BitCRC;

extern TE_Config_Integrity_Status V_Config_OVSP_Cfg_Integrity;


/* ---------- provided operations: ------------------------------------------ */
extern void Config_Retrieve_From_FlexNVM (TU_Config_OVSP_Cfg * const p_pt_Config);

extern void Config_Write_In_FlexNVM (void);

extern void Config_Reset_OVSP_Cfg (TU_Config_OVSP_Cfg * const p_pt_Config);

extern void Config_Copy_Cfg_With_Swap (const TU_Config_OVSP_Cfg * const p_pt_Config_Src,
                                             TU_Config_OVSP_Cfg * const p_pt_Config_Dest);

extern void Config_Compute_16BitCRC (const uint8_t  * const p_pt_StartAddr,
                                     const uint32_t         p_Length,
                                           uint16_t * const p_pt_CrcComputed);

extern void Config_Check_OVSP_Cfg (const TE_Config_OVSP_Cfg_Type            p_OVSP_Cfg_Type,
                                         TE_Config_Integrity_Status * const p_pt_Cfg_Integrity);


#endif /* CONFIG_PRIVATE_H */
