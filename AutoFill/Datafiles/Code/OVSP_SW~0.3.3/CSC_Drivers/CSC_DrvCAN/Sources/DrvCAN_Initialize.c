/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvCAN CSC initialization function
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
/* DrvCAN_Initialize : To initialize the DrvCAN CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvCAN_Initialize (void)
{
   uint32_t v_Iter_MB;
   uint32_t v_MB_Pos;
   uint32_t v_Iter_Queue;
   uint32_t v_Iter_Msg;

   C_DrvCAN_FlexCAN1_Registers->S_MCR |= DRVCAN_MCR_SOFTRST_MASK;
   C_DrvCAN_FlexCAN1_Registers->S_MCR |= DRVCAN_MCR_MDIS_MASK;

   C_DrvCAN_FlexCAN1_Registers->S_CTRL1 |= DRVCAN_CTRL1_CLKSRC_MASK;

   C_DrvCAN_FlexCAN1_Registers->S_MCR &= ~DRVCAN_MCR_MDIS_MASK;

   while (DRVCAN_MCR_FRZACK_MASK != (C_DrvCAN_FlexCAN1_Registers->S_MCR & DRVCAN_MCR_FRZACK_MASK))
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   C_DrvCAN_FlexCAN1_Registers->S_CTRL1 = DRVCAN_CTRL1_1MBPS_CONFIG;

   for (v_Iter_MB = 0UL; v_Iter_MB < DRVCAN_MB_MAX_NUMBER ; v_Iter_MB++)
   {
      C_DrvCAN_FlexCAN1_Registers->S_RXIMR [v_Iter_MB] = C_DrvCAN_CAN_Config [v_Iter_MB].S_RxIndivMaskId;

      v_MB_Pos = v_Iter_MB * DRVCAN_MSG_BUF_SIZE;

      C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_MB_Pos] =
         (C_DrvCAN_CAN_Config [v_Iter_MB].S_TxRxSelection << DRVCAN_TXRXSELECT_SHIFT) |
         (C_DrvCAN_CAN_Config [v_Iter_MB].S_ExtStdIdSelect << DRVCAN_EXTSTDSELECT_SHIFT);

      if (DRVCAN_SELECT_RX == C_DrvCAN_CAN_Config [v_Iter_MB].S_TxRxSelection)
      {
         if (0UL == C_DrvCAN_CAN_Config [v_Iter_MB].S_ExtStdIdSelect)
         {
            C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_MB_Pos + DRVCAN_MB_ID_OFFSET] =
               (C_DrvCAN_CAN_Config [v_Iter_MB].S_RxIdTbl << DRVCAN_ID_SHIFT);
         }
         else
         { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
            /* Nothing to do */
         }
      }
      else
      {
         C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_MB_Pos + DRVCAN_MB_ID_OFFSET] = 0UL;
      }

      C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_MB_Pos + DRVCAN_MB_DATA1_OFFSET] = 0UL;
      C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_MB_Pos + DRVCAN_MB_DATA2_OFFSET] = 0UL;
   }

   C_DrvCAN_FlexCAN1_Registers->S_IMASK1 = DRVCAN_IMASK1_CONFIG;

   C_DrvCAN_FlexCAN1_Registers->S_RXMGMASK = DRVCAN_RXMGMASK_CONFIG;
   C_DrvCAN_FlexCAN1_Registers->S_RX14MASK = DRVCAN_R14MASK_CONFIG;
   C_DrvCAN_FlexCAN1_Registers->S_RX15MASK = DRVCAN_R15MASK_CONFIG;

   C_DrvCAN_FlexCAN1_Registers->S_MCR = DRVCAN_MCR_CONFIG;

   while (DRVCAN_MCR_FRZACK_MASK == (C_DrvCAN_FlexCAN1_Registers->S_MCR & DRVCAN_MCR_FRZACK_MASK))
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   while (DRVCAN_MCR_NOTRDY_MASK == (C_DrvCAN_FlexCAN1_Registers->S_MCR & DRVCAN_MCR_NOTRDY_MASK))
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   for (v_Iter_Queue = 0UL; v_Iter_Queue < DRVCAN_RXQUEUE_MAX_NB ; v_Iter_Queue++)
   {
      V_DrvCAN_RxQueues [v_Iter_Queue].S_NxtMsg_Idx = 0UL;
      V_DrvCAN_RxQueues [v_Iter_Queue].S_LastMsg_Idx = 0UL;

      for (v_Iter_Msg = 0UL; v_Iter_Msg < DRVCAN_RXFRAME_MAX_NB ; v_Iter_Msg++)
      {
         V_DrvCAN_RxQueues [v_Iter_Queue].S_RxMsgQueue [v_Iter_Msg].S_RxId = OVSP_SW_LONG_MAX;
         V_DrvCAN_RxQueues [v_Iter_Queue].S_RxMsgQueue [v_Iter_Msg].S_RxData [OVSP_SW_LONG_0] = OVSP_SW_LONG_MAX;
         V_DrvCAN_RxQueues [v_Iter_Queue].S_RxMsgQueue [v_Iter_Msg].S_RxData [OVSP_SW_LONG_1] = OVSP_SW_LONG_MAX;
      }
   }
}
