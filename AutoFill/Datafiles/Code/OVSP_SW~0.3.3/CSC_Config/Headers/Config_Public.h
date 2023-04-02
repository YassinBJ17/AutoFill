/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef CONFIG_PUBLIC_H
#define CONFIG_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "CAN_Public.h"

#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
/* None */


/* ---------- provided types: ----------------------------------------------- */
typedef enum
{
   E_Config_Integrity_OK = 0,
   E_Config_Integrity_KO = 1
} TE_Config_Integrity_Status;


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void Config_Initialize (void);
extern void Config_Treatments (void);

extern void Config_Manage_NewConfig_HTR (const TU_CAN_SET_PARAM_Frames * const p_pt_New_Config,
                                         const uint16_t                        p_16BitCRC);

extern void Config_Manage_NewConfig_BckGrnd (void);

extern void Config_Use_NewConfig (void);

extern uint8_t Config_Get_OVS_NTLThresholdInhib (void);
extern uint8_t Config_Get_OVS_NGInhib (void);
extern uint8_t Config_Get_OVS_CSSInhib (void);
extern uint8_t Config_Get_OVS_OneSensorNGInhib (void);
extern uint8_t Config_Get_OVS_OneSensorNTLInhib (void);
extern uint8_t Config_Get_Interlock_Inhib (void);
extern uint8_t Config_Get_NTLOS1_NL (void);
extern uint8_t Config_Get_NTLOS1_NH (void);
extern uint8_t Config_Get_NTLOS2_NL (void);
extern uint8_t Config_Get_NTLOS2_NH (void);
extern uint8_t Config_Get_NTL_OVSTHRESD_N (void);
extern uint8_t Config_Get_NTL_OVS_FUNCTION (void);
extern uint8_t Config_Get_NGOS1_NL (void);
extern uint8_t Config_Get_NGOS1_NH (void);
extern uint8_t Config_Get_NGOS2_NL (void);
extern uint8_t Config_Get_NGOS2_NH (void);
extern uint8_t Config_Get_NG_OVSTHRESD_N (void);
extern uint8_t Config_Get_NG_OVSTHRESD_Thres_Ar (const uint32_t p_Index);
extern uint8_t Config_Get_NTL_OVSVARIA_Thres_Ar (const uint32_t p_Index);
extern float32_t Config_Get_NGOS1_Timeout (void);
extern float32_t Config_Get_NGOS1_100 (void);
extern float32_t Config_Get_NGOS2_Timeout (void);
extern float32_t Config_Get_NGOS2_100 (void);
extern float32_t Config_Get_NTLOS1_Timeout (void);
extern float32_t Config_Get_NTLOS1_100 (void);
extern float32_t Config_Get_NTLOS2_Timeout (void);
extern float32_t Config_Get_NTLOS2_100 (void);
extern float32_t Config_Get_NTL_OVSTHRESD_Threshold (void);
extern float32_t Config_Get_NTL_OVSTHRESD_Window (void);
extern float32_t Config_Get_NG_OVSTHRESD_Threshold (void);
extern float32_t Config_Get_NG_OVSTHRESD_Window (void);

extern void Config_Get_16BitCRC (uint8_t * const p_pt_16BitCRC_MSB, uint8_t * const p_pt_16BitCRC_LSB);

extern void Config_Get_LastComputed16BitCRC (uint8_t * const p_pt_16BitCRC_MSB, uint8_t * const p_pt_16BitCRC_LSB);

extern TE_Config_Integrity_Status Config_Get_Integrity_Status (void);


#endif /* CONFIG_PUBLIC_H */
