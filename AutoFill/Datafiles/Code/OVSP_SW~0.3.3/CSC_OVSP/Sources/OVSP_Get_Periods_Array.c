#include "OVSP_Public.h"
#include "OVSP_Private.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 uint32_t * OVSP_Get_Periods_Array (const uint32_t p_Signal_Name) {    uint32_t * v_Periods_Array_Ref;    switch (p_Signal_Name)    {       case OVSP_NGOS1_ID:       {          v_Periods_Array_Ref = V_OVSP_Context_In.V_NGOS1_Periods_Ar;       }       break;       case OVSP_NGOS2_ID:       {          v_Periods_Array_Ref = V_OVSP_Context_In.V_NGOS2_Periods_Ar;       }       break;       case OVSP_NTLOS1_ID:       {          v_Periods_Array_Ref = V_OVSP_Context_In.V_NTLOS1_Periods_Ar;       }       break;       case OVSP_NTLOS2_ID:       {          v_Periods_Array_Ref = V_OVSP_Context_In.V_NTLOS2_Periods_Ar;       }       break;       case OVSP_TSPEED_ID:       {          v_Periods_Array_Ref = V_OVSP_Context_In.V_Test_Periods_Ar;       }       break;       default:       {          v_Periods_Array_Ref = V_OVSP_Context_In.V_NGOS1_Periods_Ar;       }       break;    }    return (v_Periods_Array_Ref); }
