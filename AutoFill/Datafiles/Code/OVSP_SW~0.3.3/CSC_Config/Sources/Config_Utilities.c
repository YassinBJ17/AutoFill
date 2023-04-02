/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Config CSC Utilities functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Config_Public.h"
#include "Config_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "DrvFTFC_Public.h"

#include "OVSP_SW_Public.h"
#include "MCP_Types.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* Config_Get_OVS_NTLThresholdInhib : To provide the OVS_NTLThresholdInhib Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: OVS_NTLThresholdInhib Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_OVS_NTLThresholdInhib (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_OVS_NTLThresholdInhib);
}


/* Config_Get_OVS_NGInhib : To provide the OVS_NGInhib Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: OVS_NGInhib Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_OVS_NGInhib (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_OVS_NGInhib);
}


/* Config_Get_OVS_CSSInhib : To provide the OVS_CSSInhib Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: OVS_CSSInhib Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_OVS_CSSInhib (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_OVS_CSSInhib);
}


/* Config_Get_OVS_OneSensorNGInhib : To provide the OVS_OneSensorNGInhib Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: OVS_OneSensorNGInhib Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_OVS_OneSensorNGInhib (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_OVS_OneSensorNGInhib);
}


/* Config_Get_OVS_OneSensorNTLInhib : To provide the OVS_OneSensorNTLInhib Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: OVS_OneSensorNTLInhib Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_OVS_OneSensorNTLInhib (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_OVS_OneSensorNTLInhib);
}


/* Config_Get_Interlock_Inhib : To provide the Interlock_Inhib Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: Interlock_Inhib Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_Interlock_Inhib (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_Interlock_Inhib);
}


/* Config_Get_NTLOS1_NL : To provide the NTLOS1_NL Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS1_NL Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_NTLOS1_NL (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NTLOS1_NL);
}


/* Config_Get_NTLOS1_NH : To provide the NTLOS1_NH Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS1_NH Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_NTLOS1_NH (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NTLOS1_NH);
}


/* Config_Get_NTLOS2_NL : To provide the NTLOS2_NL Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS2_NL Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_NTLOS2_NL (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NTLOS2_NL);
}


/* Config_Get_NTLOS2_NH : To provide the NTLOS2_NH Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS2_NH Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_NTLOS2_NH (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NTLOS2_NH);
}


/* Config_Get_NTL_OVSTHRESD_N : To provide the NTL_OVSTHRESD_N Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTL_OVSTHRESD_N Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_NTL_OVSTHRESD_N (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NTL_OVSTHRESD_N);
}


/* Config_Get_NTL_OVS_FUNCTION : To provide the NTL_OVS_FUNCTION Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTL_OVS_FUNCTION Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_NTL_OVS_FUNCTION (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NTL_OVS_FUNCTION);
}


/* Config_Get_NGOS1_NL : To provide the NGOS1_NL Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS1_NL Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_NGOS1_NL (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NGOS1_NL);
}


/* Config_Get_NGOS1_NH : To provide the NGOS1_NH Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS1_NH Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_NGOS1_NH (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NGOS1_NH);
}


/* Config_Get_NGOS2_NL : To provide the NGOS2_NL Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS2_NL Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_NGOS2_NL (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NGOS2_NL);
}


/* Config_Get_NGOS2_NH : To provide the NGOS2_NH Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS2_NH Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_NGOS2_NH (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NGOS2_NH);
}


/* Config_Get_NG_OVSTHRESD_N : To provide the NG_OVSTHRESD_N Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NG_OVSTHRESD_N Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_NG_OVSTHRESD_N (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NG_OVSTHRESD_N);
}


/* Config_Get_NG_OVSTHRESD_Thres_Ar : To provide the NG_OVSTHRESD_Threshold_Ar Configuration parameter
 *   Inputs:
 *     - p_Index: Index of the requested value of NG_OVSTHRESD_Threshold_Ar
 *   Outputs: None
 *   Function return: NG_OVSTHRESD_Threshold_Ar Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_NG_OVSTHRESD_Thres_Ar (const uint32_t p_Index)
{
   uint8_t v_Return_Value;

   if (CONFIG_NTL_VAR_THRES_NB > p_Index)
   {
      v_Return_Value = V_Config_OVSP_Cfg_Used.U_Fields.S_NG_OVSTHRESD_Threshold_Ar [p_Index];
   }
   else
   {
      v_Return_Value = (uint8_t) 0;
   }

   return (v_Return_Value);
}


/* Config_Get_NTL_OVSVARIA_Thres_Ar : To provide the NTL_OVSVARIABLE_Threshold_Ar Configuration parameter
 *   Inputs:
 *     - p_Index: Index of the requested value of NTL_OVSVARIABLE_Threshold_Ar
 *   Outputs: None
 *   Function return: NTL_OVSVARIABLE_Threshold_Ar Configuration parameter
 *   Pre-condition: None
*/
uint8_t Config_Get_NTL_OVSVARIA_Thres_Ar (const uint32_t p_Index)
{
   uint8_t v_Return_Value;

   if (CONFIG_NTL_VAR_THRES_NB > p_Index)
   {
      v_Return_Value = V_Config_OVSP_Cfg_Used.U_Fields.S_NTL_OVSVARIABLE_Threshold_Ar [p_Index];
   }
   else
   {
      v_Return_Value = (uint8_t) 0;
   }

   return (v_Return_Value);
}

/* Config_Get_NGOS1_Timeout : To provide the NGOS1_Timeout Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS1_Timeout Configuration parameter
 *   Pre-condition: None
*/
float32_t Config_Get_NGOS1_Timeout (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NGOS1_Timeout);
}


/* Config_Get_NGOS1_100 : To provide the NGOS1_100 Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS1_100 Configuration parameter
 *   Pre-condition: None
*/
float32_t Config_Get_NGOS1_100 (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NGOS1_100);
}


/* Config_Get_NGOS2_Timeout : To provide the NGOS2_Timeout Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS2_Timeout Configuration parameter
 *   Pre-condition: None
*/
float32_t Config_Get_NGOS2_Timeout (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NGOS2_Timeout);
}


/* Config_Get_NGOS2_100 : To provide the NGOS2_100 Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS2_100 Configuration parameter
 *   Pre-condition: None
*/
float32_t Config_Get_NGOS2_100 (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NGOS2_100);
}


/* Config_Get_NTLOS1_Timeout : To provide the NTLOS1_Timeout Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS1_Timeout Configuration parameter
 *   Pre-condition: None
*/
float32_t Config_Get_NTLOS1_Timeout (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NTLOS1_Timeout);
}


/* Config_Get_NTLOS1_100 : To provide the NTLOS1_100 Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS1_100 Configuration parameter
 *   Pre-condition: None
*/
float32_t Config_Get_NTLOS1_100 (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NTLOS1_100);
}


/* Config_Get_NTLOS2_Timeout : To provide the NTLOS2_Timeout Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS2_Timeout Configuration parameter
 *   Pre-condition: None
*/
float32_t Config_Get_NTLOS2_Timeout (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NTLOS2_Timeout);
}


/* Config_Get_NTLOS2_100 : To provide the NTLOS2_100 Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS2_100 Configuration parameter
 *   Pre-condition: None
*/
float32_t Config_Get_NTLOS2_100 (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NTLOS2_100);
}


/* Config_Get_NTL_OVSTHRESD_Threshold : To provide the NTL_OVSTHRESD_Threshold Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTL_OVSTHRESD_Threshold Configuration parameter
 *   Pre-condition: None
*/
float32_t Config_Get_NTL_OVSTHRESD_Threshold (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NTL_OVSTHRESD_Threshold);
}


/* Config_Get_NTL_OVSTHRESD_Window : To provide the NTL_OVSTHRESD_Window Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTL_OVSTHRESD_Window Configuration parameter
 *   Pre-condition: None
*/
float32_t Config_Get_NTL_OVSTHRESD_Window (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NTL_OVSTHRESD_Window);
}


/* Config_Get_NG_OVSTHRESD_Threshold : To provide the NG_OVSTHRESD_Threshold Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NG_OVSTHRESD_Threshold Configuration parameter
 *   Pre-condition: None
*/
float32_t Config_Get_NG_OVSTHRESD_Threshold (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NG_OVSTHRESD_Threshold);
}


/* Config_Get_NG_OVSTHRESD_Window : To provide the NG_OVSTHRESD_Window Configuration parameter
 *   Inputs: None
 *   Outputs: None
 *   Function return: NG_OVSTHRESD_Window Configuration parameter
 *   Pre-condition: None
*/
float32_t Config_Get_NG_OVSTHRESD_Window (void)
{
   return (V_Config_OVSP_Cfg_Used.U_Fields.S_NG_OVSTHRESD_Window);
}


/* Config_Get_16BitCRC : To provide the 16-bit CRC of the OVSP Config table
 *   Inputs: None
 *   Outputs:
 *     - p_pt_16BitCRC_MSB : MSB of the OVSP Config table 16-bit CRC
 *     - p_pt_16BitCRC_LSB : LSB of the OVSP Config table 16-bit CRC
 *   Function return: None
 *   Pre-condition: None
*/
void Config_Get_16BitCRC (uint8_t * const p_pt_16BitCRC_MSB, uint8_t * const p_pt_16BitCRC_LSB)
{
   *p_pt_16BitCRC_MSB = V_Config_OVSP_Cfg_Used.U_Fields.S_16BitCRC_MSB;
   *p_pt_16BitCRC_LSB = V_Config_OVSP_Cfg_Used.U_Fields.S_16BitCRC_LSB;
}


/* Config_Get_LastComputed16BitCRC : To provide the last computed 16-bit CRC of the OVSP Config table
 *   Inputs: None
 *   Outputs:
 *     - p_pt_16BitCRC_MSB : MSB of the OVSP Config table 16-bit CRC
 *     - p_pt_16BitCRC_LSB : LSB of the OVSP Config table 16-bit CRC
 *   Function return: None
 *   Pre-condition: None
*/
void Config_Get_LastComputed16BitCRC (uint8_t * const p_pt_16BitCRC_MSB, uint8_t * const p_pt_16BitCRC_LSB)
{
   *p_pt_16BitCRC_MSB = V_Last_Computed_16BitCRC.U_Array_8BitUint [OVSP_SW_BYTE_0];
   *p_pt_16BitCRC_LSB = V_Last_Computed_16BitCRC.U_Array_8BitUint [OVSP_SW_BYTE_1];
}


/* Config_Get_Integrity_Status : To provide the OVSP Config table Integrity Status
 *   Inputs: None
 *   Outputs: None
 *   Function return: OVSP Config table Integrity Status
 *   Pre-condition: None
*/
TE_Config_Integrity_Status Config_Get_Integrity_Status (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_Config_OVSP_Cfg_Integrity);
}


/* Config_Retrieve_From_FlexNVM : To retrieve from FlexNVM the OVSP Config table
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Config: OVSP Config table to be set with the FlexNVM data
 *   Function return: None
 *   Pre-condition: None
*/
void Config_Retrieve_From_FlexNVM (TU_Config_OVSP_Cfg * const p_pt_Config)
{
   uint32_t v_Iter_32BitWord;
   TU_Config_OVSP_Cfg * pt_FlexNVM_Cfg;

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as it is a 32-bit Unsigned Long address */
   /* converted to a pointer which is also an 32-bit Unsigned Long. */
   pt_FlexNVM_Cfg = (TU_Config_OVSP_Cfg *) DRVFTFC_CONFIG_START_ADDR;

   for (v_Iter_32BitWord = 0UL; v_Iter_32BitWord < DRVFTFC_CONFIG_32BIT_NB ; v_Iter_32BitWord++)
   {
      p_pt_Config->U_Array_32BitUint [v_Iter_32BitWord] = pt_FlexNVM_Cfg->U_Array_32BitUint [v_Iter_32BitWord];
   }
}


/* Config_Reset_OVSP_Cfg : To reset an OVSP Config table
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Config: OVSP Config table to be reseted
 *   Function return: None
 *   Pre-condition: None
*/
void Config_Reset_OVSP_Cfg (TU_Config_OVSP_Cfg * const p_pt_Config)
{
   uint32_t v_Iter_32BitWord;

   /* The OVSP Config table parameters are reseted to 0x00 */
   for (v_Iter_32BitWord = 0UL; v_Iter_32BitWord < CONFIG_FIRST_RESERVED_INDEX ; v_Iter_32BitWord++)
   {
      p_pt_Config->U_Array_32BitUint [v_Iter_32BitWord] = OVSP_SW_LONG_MIN;
   }

   /* The Reserved area and the 16-bit CRC of the OVSP Config table are reseted to 0xFF */
   for (v_Iter_32BitWord = CONFIG_FIRST_RESERVED_INDEX; v_Iter_32BitWord < DRVFTFC_CONFIG_32BIT_NB ; v_Iter_32BitWord++)
   {
      p_pt_Config->U_Array_32BitUint [v_Iter_32BitWord] = OVSP_SW_LONG_MAX;
   }
}
