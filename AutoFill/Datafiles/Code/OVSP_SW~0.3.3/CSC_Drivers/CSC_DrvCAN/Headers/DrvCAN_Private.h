/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVCAN_PRIVATE_H
#define DRVCAN_PRIVATE_H

/* ---------- include predefined types: ------------------------------------- */
#include "DrvCAN_Public.h"

#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVCAN_FLEXCAN1_ADDRESS     0x40025000UL

#define DRVCAN_MSG_BUF_SIZE         4UL

#define DRVCAN_MCR_FRZACK_MASK      0x01000000UL
#define DRVCAN_MCR_SOFTRST_MASK     0x02000000UL
#define DRVCAN_MCR_NOTRDY_MASK      0x08000000UL
#define DRVCAN_MCR_MDIS_MASK        0x80000000UL

#define DRVCAN_CTRL1_CLKSRC_MASK    0x00002000UL

#define DRVCAN_WMBn_CS_IDE_MASK     0x00200000UL
#define DRVCAN_WMBn_ID_MASK         0x1FFFFFFFUL

#define DRVCAN_MB_MAX_NUMBER        16UL
#define DRVCAN_MB_RX_MAX_NB         9UL
#define DRVCAN_MB_RX_NONE           255UL

#define DRVCAN_MB_ID_OFFSET         1UL
#define DRVCAN_MB_DATA1_OFFSET      2UL
#define DRVCAN_MB_DATA2_OFFSET      3UL

#define DRVCAN_ID_SHIFT             18UL

#define DRVCAN_MB_RX_BIT0_MASK      0x00000001UL

#define DRVCAN_IDE_NONE             0x00000000UL
#define DRVCAN_IDE_MB00             0x00000000UL
#define DRVCAN_IDE_MB01             0x00000001UL
#define DRVCAN_IDE_MB02             0x00000002UL
#define DRVCAN_IDE_MB03             0x00000003UL
#define DRVCAN_IDE_MB04             0x00000004UL
#define DRVCAN_IDE_MB05             0x00000005UL
#define DRVCAN_IDE_MB06             0x00000006UL
#define DRVCAN_IDE_MB07             0x00000007UL
#define DRVCAN_IDE_MB08             0x00000008UL
#define DRVCAN_IDE_MB09             0x00000009UL
#define DRVCAN_IDE_MB10             0x0000000AUL
#define DRVCAN_IDE_MB11             0x0000000BUL

#define DRVCAN_CTRL1_1MBPS_CONFIG   0x04D32006UL
#define DRVCAN_IMASK1_CONFIG        0x000003FFUL
#define DRVCAN_RXMGMASK_CONFIG      0x1FFFFFFFUL
#define DRVCAN_R14MASK_CONFIG       0x1FFFFFFFUL
#define DRVCAN_R15MASK_CONFIG       0x1FFFFFFFUL
#define DRVCAN_MCR_CONFIG           0x0003000FUL

#define DRVCAN_SELECT_TX            0UL
#define DRVCAN_SELECT_RX            1UL

#define DRVCAN_TXRXSELECT_SHIFT     26UL
#define DRVCAN_EXTSTDSELECT_SHIFT   21UL

#define DRVCAN_RXQUEUE_MAX_NB       2UL
#define DRVCAN_RXFRAME_MAX_NB       12UL

#define DRVCAN_GET_DATA_ID_FILTER   0x0000000FUL

#define DRVCAN_TXCMD_VALUE          0x0C480000UL


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t S_MCR;
   uint32_t S_CTRL1;
   uint32_t S_TIMER;
   uint32_t S_CAN_Reserved_1;
   uint32_t S_RXMGMASK;
   uint32_t S_RX14MASK;
   uint32_t S_RX15MASK;
   uint32_t S_ECR;
   uint32_t S_ESR1;
   uint32_t S_CAN_Reserved_2;
   uint32_t S_IMASK1;
   uint32_t S_CAN_Reserved_3;
   uint32_t S_IFLAG1;
   uint32_t S_CTRL2;
   uint32_t S_ESR2;
   uint32_t S_CAN_Reserved_4 [2];
   uint32_t S_CRCR;
   uint32_t S_RXFGMASK;
   uint32_t S_RXFIR;
   uint32_t S_CBT;
   uint32_t S_CAN_Reserved_5 [11];
   uint32_t S_RAMn [128];
   uint32_t S_CAN_Reserved_6 [384];
   uint32_t S_RXIMR [32];
   uint32_t S_CAN_Reserved_7 [128];
   uint32_t S_CTRL1_PN;
   uint32_t S_CTRL2_PN;
   uint32_t S_WU_MTC;
   uint32_t S_FLT_ID1;
   uint32_t S_FLT_DLC;
   uint32_t S_PL1_LO;
   uint32_t S_PL1_HI;
   uint32_t S_FLT_ID2_IDMASK;
   uint32_t S_PL2_PLMASK_LO;
   uint32_t S_PL2_PLMASK_HI;
   uint32_t S_CAN_Reserved_8 [6];
   uint32_t S_WMB0_CS;
   uint32_t S_WMB0_ID;
   uint32_t S_WMB0_D03;
   uint32_t S_WMB0_D47;
   uint32_t S_WMB1_CS;
   uint32_t S_WMB1_ID;
   uint32_t S_WMB1_D03;
   uint32_t S_WMB1_D47;
   uint32_t S_WMB2_CS;
   uint32_t S_WMB2_ID;
   uint32_t S_WMB2_D03;
   uint32_t S_WMB2_D47;
   uint32_t S_WMB3_CS;
   uint32_t S_WMB3_ID;
   uint32_t S_WMB3_D03;
   uint32_t S_WMB3_D47;
   uint32_t S_CAN_Reserved_9 [32];
   uint32_t S_FDCTRL;
   uint32_t S_FDCBT;
   uint32_t S_FDCRC;
} TS_DrvCAN_Registers;


typedef struct
{
   uint32_t S_RxIndivMaskId;
   uint32_t S_ExtStdIdSelect;
   uint32_t S_RxIdTbl;
   uint32_t S_TxRxSelection;
} TS_DrvCAN_CAN_Config;

typedef struct
{
   uint32_t S_NxtMsg_Idx;
   uint32_t S_LastMsg_Idx;
   TS_DrvCAN_RxFrame S_RxMsgQueue [DRVCAN_RXFRAME_MAX_NB];
} TS_DrvCAN_RxQueue;


/* ---------- provided constants: ------------------------------------------- */
extern TS_DrvCAN_Registers * const C_DrvCAN_FlexCAN1_Registers;

extern const TS_DrvCAN_CAN_Config C_DrvCAN_CAN_Config [DRVCAN_MB_MAX_NUMBER];


/* ---------- provided data: ------------------------------------------------ */
extern TS_DrvCAN_RxQueue V_DrvCAN_RxQueues [DRVCAN_RXQUEUE_MAX_NB];


/* ---------- provided operations: ------------------------------------------ */
extern void DrvCAN_Add_RxFrame_ToQueue (const TS_DrvCAN_RxFrame * const p_pt_RxFrame, const uint32_t p_RxQueue_Id);


#endif /* DRVCAN_PRIVATE_H */
