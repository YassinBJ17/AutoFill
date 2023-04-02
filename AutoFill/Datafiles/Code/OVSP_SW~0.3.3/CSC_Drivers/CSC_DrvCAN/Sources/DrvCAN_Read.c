/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvCAN frame read function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvCAN_Public.h"
#include "DrvCAN_Private.h"


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
/* DrvCAN_Read : To read data of a CAN frame received on FlexCAN
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvCAN_Read (void)
{
   uint32_t v_CAN_IFLAG1;
   uint32_t v_RxMB_IdShift;
   uint32_t v_RxMB_Id;

   uint32_t v_RxMB_Pos;
   uint32_t v_RxMB_Id_Pos;
   uint32_t v_RxMB_Data1_Pos;
   uint32_t v_RxMB_Data2_Pos;

   TS_DrvCAN_RxFrame v_RxFrame_Read;
   uint32_t v_RxQueue_Id;

   volatile uint32_t v_Timer_Dummy;

   v_CAN_IFLAG1 = C_DrvCAN_FlexCAN1_Registers->S_IFLAG1;

   v_RxMB_IdShift = 0UL;

   do
   {
      if (DRVCAN_MB_RX_BIT0_MASK == ((v_CAN_IFLAG1 >> v_RxMB_IdShift) & DRVCAN_MB_RX_BIT0_MASK))
      {
         v_RxMB_Id = v_RxMB_IdShift;
      }
      else
      {
         v_RxMB_Id = DRVCAN_MB_RX_NONE;
         v_RxMB_IdShift++;
      }
   }
   while ((DRVCAN_MB_RX_NONE == v_RxMB_Id) && (DRVCAN_MB_RX_MAX_NB >= v_RxMB_IdShift));

   if (DRVCAN_MB_RX_MAX_NB >= v_RxMB_Id)
   {
      v_RxMB_Pos = v_RxMB_Id * DRVCAN_MSG_BUF_SIZE;

      while (DRVCAN_MCR_FRZACK_MASK == (C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_RxMB_Pos] & DRVCAN_MCR_FRZACK_MASK))
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }

      v_RxMB_Id_Pos = v_RxMB_Pos + DRVCAN_MB_ID_OFFSET;

      if (DRVCAN_WMBn_CS_IDE_MASK == (C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_RxMB_Id_Pos] & DRVCAN_WMBn_CS_IDE_MASK))
      {
         v_RxFrame_Read.S_RxId = (C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_RxMB_Id_Pos] & DRVCAN_WMBn_ID_MASK);
      }
      else
      {
         v_RxFrame_Read.S_RxId =
            (C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_RxMB_Id_Pos] & DRVCAN_WMBn_ID_MASK) >> DRVCAN_ID_SHIFT;
      }

      v_RxMB_Data1_Pos = v_RxMB_Pos + DRVCAN_MB_DATA1_OFFSET;
      v_RxFrame_Read.S_RxData [OVSP_SW_LONG_0] = C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_RxMB_Data1_Pos];

      v_RxMB_Data2_Pos = v_RxMB_Pos + DRVCAN_MB_DATA2_OFFSET;
      v_RxFrame_Read.S_RxData [OVSP_SW_LONG_1] = C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_RxMB_Data2_Pos];

      C_DrvCAN_FlexCAN1_Registers->S_IFLAG1 = (DRVCAN_MB_RX_BIT0_MASK << v_RxMB_Id);

      v_Timer_Dummy = C_DrvCAN_FlexCAN1_Registers->S_TIMER;

      if ((DRVCAN_IDE_MB01 == v_RxMB_Id) &&
          (DRVCAN_IDE_MB07 != (v_RxFrame_Read.S_RxId & DRVCAN_GET_DATA_ID_FILTER)))
      {
         v_RxQueue_Id = DRVCAN_RXQUEUE1_ID;
      }
      else
      {
         v_RxQueue_Id = DRVCAN_RXQUEUE0_ID;
      }

      DrvCAN_Add_RxFrame_ToQueue (&v_RxFrame_Read, v_RxQueue_Id);
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
