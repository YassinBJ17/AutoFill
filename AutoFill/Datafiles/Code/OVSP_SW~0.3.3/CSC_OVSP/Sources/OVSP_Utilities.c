/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the OVSP CSC Utilities functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "OVSP_Public.h"
#include "OVSP_Private.h"


/* ---------- include required interface: ----------------------------------- */
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
/* OVSP_Get_Engine_SpeedLevel : To provide the Engine Speed Level
 *   Inputs: None
 *   Outputs: None
 *   Function return: Engine Speed Level
 *   Pre-condition: None
*/
uint32_t * OVSP_Get_Periods_Array (const uint32_t p_Signal_Name)
{
   uint32_t * v_Periods_Array_Ref;

   switch (p_Signal_Name)
   {
      case OVSP_NGOS1_ID:
      {
         v_Periods_Array_Ref = V_OVSP_Context_In.V_NGOS1_Periods_Ar;
      }
      break;

      case OVSP_NGOS2_ID:
      {
         v_Periods_Array_Ref = V_OVSP_Context_In.V_NGOS2_Periods_Ar;
      }
      break;

      case OVSP_NTLOS1_ID:
      {
         v_Periods_Array_Ref = V_OVSP_Context_In.V_NTLOS1_Periods_Ar;
      }
      break;

      case OVSP_NTLOS2_ID:
      {
         v_Periods_Array_Ref = V_OVSP_Context_In.V_NTLOS2_Periods_Ar;
      }
      break;

      case OVSP_TSPEED_ID:
      {
         v_Periods_Array_Ref = V_OVSP_Context_In.V_Test_Periods_Ar;
      }
      break;

      default:
      {
         v_Periods_Array_Ref = V_OVSP_Context_In.V_NGOS1_Periods_Ar;
      }
      break;

   }

   return (v_Periods_Array_Ref);
}


/* OVSP_Get_Engine_SpeedLevel : To provide the Engine Speed Level
 *   Inputs: None
 *   Outputs: None
 *   Function return: Engine Speed Level
 *   Pre-condition: None
*/
TE_OVSP_SW_Speed_Level OVSP_Get_Engine_SpeedLevel (void)
{
   /* >RELAX<SYNCHRONe_C_Code_12.14> The enum types are similar then compatible. */
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return ((TE_OVSP_SW_Speed_Level) V_OVSP_Context_Out.V_Engine_SpeedLevel);
}


/* OVSP_Get_CAM_Cmd1 : To provide the CAM Command 1
 *   Inputs: None
 *   Outputs: None
 *   Function return: CAM Command 1
 *   Pre-condition: None
*/
TE_OVSP_SW_Cmd OVSP_Get_CAM_Cmd1 (void)
{
   /* >RELAX<SYNCHRONe_C_Code_12.14> The enum types are similar then compatible. */
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return ((TE_OVSP_SW_Cmd) V_OVSP_Context_Out.V_CAM_Cmd1);
}


/* OVSP_Get_CAM_Cmd2 : To provide the CAM Command 2
 *   Inputs: None
 *   Outputs: None
 *   Function return: CAM Command 2
 *   Pre-condition: None
*/
TE_OVSP_SW_Cmd OVSP_Get_CAM_Cmd2 (void)
{
   /* >RELAX<SYNCHRONe_C_Code_12.14> The enum types are similar then compatible. */
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return ((TE_OVSP_SW_Cmd) V_OVSP_Context_Out.V_CAM_Cmd2);
}


/* OVSP_Get_DOUTINHIB : To provide the DOUTINHIB Command
 *   Inputs: None
 *   Outputs: None
 *   Function return: DOUTINHIB Command
 *   Pre-condition: None
*/
TE_OVSP_SW_Cmd OVSP_Get_DOUTINHIB (void)
{
   /* >RELAX<SYNCHRONe_C_Code_12.14> The enum types are similar then compatible. */
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return ((TE_OVSP_SW_Cmd) V_OVSP_Context_Out.V_DOUTINHIB);
}


/* OVSP_Get_OSARM_Cmd : To provide the OSARM Command
 *   Inputs: None
 *   Outputs: None
 *   Function return: OSARM Command
 *   Pre-condition: None
*/
TE_OVSP_SW_Cmd OVSP_Get_OSARM_Cmd (void)
{
   /* >RELAX<SYNCHRONe_C_Code_12.14> The enum types are similar then compatible. */
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return ((TE_OVSP_SW_Cmd) V_OVSP_Context_Out.V_OSARM_Cmd);
}


/* OVSP_Get_REARM_Cmd : To provide the REARM Command
 *   Inputs: None
 *   Outputs: None
 *   Function return: REARM Command
 *   Pre-condition: None
*/
TE_OVSP_SW_Cmd OVSP_Get_REARM_Cmd (void)
{
   /* >RELAX<SYNCHRONe_C_Code_12.14> The enum types are similar then compatible. */
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return ((TE_OVSP_SW_Cmd) V_OVSP_Context_Out.V_REARM_Cmd);
}


/* OVSP_Get_NGOS1_Measure : To provide the NGOS1 Frequency Measure
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS1 Frequency Measure
 *   Pre-condition: None
*/
float32_t OVSP_Get_NGOS1_Measure (void)
{
   return ((float32_t) V_OVSP_Context_Out.V_NGOS1_Measure);
}


/* OVSP_Get_NGOS1_OutOfTime : To provide the NGOS1 Out Of Time state
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS1 Out Of Time state
 *   Pre-condition: None
*/
boolean_t OVSP_Get_NGOS1_OutOfTime (void)
{
   return ((boolean_t) V_OVSP_Context_Out.V_NGOS1_OutOfTime);
}


/* OVSP_Get_NGOS1_OutOfHigh : To provide the NGOS1 Out Of High state
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS1 Out Of High state
 *   Pre-condition: None
*/
boolean_t OVSP_Get_NGOS1_OutOfHigh (void)
{
   return ((boolean_t) V_OVSP_Context_Out.V_NGOS1_OutOfHigh);
}


/* OVSP_Get_NGOS1_Updated : To provide the NGOS1 Updated state
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS1 Updated state
 *   Pre-condition: None
*/
boolean_t OVSP_Get_NGOS1_Updated (void)
{
   return ((boolean_t) V_OVSP_Context_Out.V_NGOS1_Updated);
}


/* OVSP_Get_NGOS2_Measure : To provide the NGOS2 Frequency Measure
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS2 Frequency Measure
 *   Pre-condition: None
*/
float32_t OVSP_Get_NGOS2_Measure (void)
{
   return ((float32_t) V_OVSP_Context_Out.V_NGOS2_Measure);
}


/* OVSP_Get_NGOS2_OutOfTime : To provide the NGOS2 Out Of Time state
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS2 Out Of Time state
 *   Pre-condition: None
*/
boolean_t OVSP_Get_NGOS2_OutOfTime (void)
{
   return ((boolean_t) V_OVSP_Context_Out.V_NGOS2_OutOfTime);
}


/* OVSP_Get_NGOS2_OutOfHigh : To provide the NGOS2 Out Of High state
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS2 Out Of High state
 *   Pre-condition: None
*/
boolean_t OVSP_Get_NGOS2_OutOfHigh (void)
{
   return ((boolean_t) V_OVSP_Context_Out.V_NGOS2_OutOfHigh);
}


/* OVSP_Get_NGOS2_Updated : To provide the NGOS2 Updated state
 *   Inputs: None
 *   Outputs: None
 *   Function return: NGOS2 Updated state
 *   Pre-condition: None
*/
boolean_t OVSP_Get_NGOS2_Updated (void)
{
   return ((boolean_t) V_OVSP_Context_Out.V_NGOS2_Updated);
}


/* OVSP_Get_NTLOS1_Measure : To provide the NTLOS1 Frequency Measure
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS1 Frequency Measure
 *   Pre-condition: None
*/
float32_t OVSP_Get_NTLOS1_Measure (void)
{
   return ((float32_t) V_OVSP_Context_Out.V_NTLOS1_Measure);
}


/* OVSP_Get_NTLOS1_OutOfTime : To provide the NTLOS1 Out Of Time state
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS1 Out Of Time state
 *   Pre-condition: None
*/
boolean_t OVSP_Get_NTLOS1_OutOfTime (void)
{
   return ((boolean_t) V_OVSP_Context_Out.V_NTLOS1_OutOfTime);
}


/* OVSP_Get_NTLOS1_OutOfHigh : To provide the NTLOS1 Out Of High state
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS1 Out Of High state
 *   Pre-condition: None
*/
boolean_t OVSP_Get_NTLOS1_OutOfHigh (void)
{
   return ((boolean_t) V_OVSP_Context_Out.V_NTLOS1_OutOfHigh);
}


/* OVSP_Get_NTLOS1_Updated : To provide the NTLOS1 Updated state
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS1 Updated state
 *   Pre-condition: None
*/
boolean_t OVSP_Get_NTLOS1_Updated (void)
{
   return ((boolean_t) V_OVSP_Context_Out.V_NTLOS1_Updated);
}


/* OVSP_Get_NTLOS2_Measure : To provide the NTLOS2 Frequency Measure
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS2 Frequency Measure
 *   Pre-condition: None
*/
float32_t OVSP_Get_NTLOS2_Measure (void)
{
   return ((float32_t) V_OVSP_Context_Out.V_NTLOS2_Measure);
}


/* OVSP_Get_NTLOS2_OutOfTime : To provide the NTLOS2 Out Of Time state
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS2 Out Of Time state
 *   Pre-condition: None
*/
boolean_t OVSP_Get_NTLOS2_OutOfTime (void)
{
   return ((boolean_t) V_OVSP_Context_Out.V_NTLOS2_OutOfTime);
}


/* OVSP_Get_NTLOS2_OutOfHigh : To provide the NTLOS2 Out Of High state
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS2 Out Of High state
 *   Pre-condition: None
*/
boolean_t OVSP_Get_NTLOS2_OutOfHigh (void)
{
   return ((boolean_t) V_OVSP_Context_Out.V_NTLOS2_OutOfHigh);
}


/* OVSP_Get_NTLOS2_Updated : To provide the NTLOS2 Updated state
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTLOS2 Updated state
 *   Pre-condition: None
*/
boolean_t OVSP_Get_NTLOS2_Updated (void)
{
   return ((boolean_t) V_OVSP_Context_Out.V_NTLOS2_Updated);
}


/* OVSP_Get_Test_Speed_Measure : To provide the Test Speed Frequency Measure
 *   Inputs: None
 *   Outputs: None
 *   Function return: Test Speed Frequency Measure
 *   Pre-condition: None
*/
float32_t OVSP_Get_Test_Speed_Measure (void)
{
   return ((float32_t) V_OVSP_Context_Out.V_Test_Speed_Measure);
}
