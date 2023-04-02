#include "DrvFTFC_Public.h"
#include "DrvFTFC_Private.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 void DrvFTFC_Copy_Data_To_RAM (void) {    uint32_t * v_pt_Source;    uint32_t * v_pt_Data_Start;    uint32_t * v_pt_Data_End;    uint32_t   v_Area_Size;    uint32_t   v_Iter_Area;    v_pt_Source = (uint32_t *) &__Linker_Code_End;    v_pt_Data_Start = (uint32_t *) &__Linker_Data_Start;    v_pt_Data_End = (uint32_t *) &__Linker_Data_End;    v_Area_Size = ((uint32_t) v_pt_Data_End - (uint32_t) v_pt_Data_Start) / OVSP_SW_NB_BYTE_IN_LONG;    for (v_Iter_Area = 0UL; v_Iter_Area < v_Area_Size ; v_Iter_Area++)    {       v_pt_Data_Start [v_Iter_Area] = v_pt_Source [v_Iter_Area];    } }
