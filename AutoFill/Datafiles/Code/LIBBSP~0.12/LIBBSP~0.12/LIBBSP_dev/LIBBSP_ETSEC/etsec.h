#ifndef ETSEC_H
#define ETSEC_H

/*------------------------------------------------------------------------------*/
/* PROJECT : X4                                                                 */
/* COMPANY : Sagem Defense Securite                                             */
/* CSU NAME : ETSEC                                                             */
/* FILENAME : etsec.h                                                           */
/*+--------+-------------------+-----+-----------------------------------------+*/
/*| DATE   |    Name/Company   | PR  |               PR                         */
/*|        |                   | Num |              Title                       */
/*+--------+-------------------+-----+-----------------------------------------+*/
/*|01/01/01| My_Name/Sagem     | -   |  Header creation                         */
/*+--------+-------------------+-----+-----------------------------------------+*/


/* ---------- DLD symbol ---------------------------------------------------- */
/* none */

/* ---------- include required interface: ----------------------------------- */
/* none */

/* ---------- provided define constants: ------------------------------------ */
 #include "LIBMCP_Types.h"
#include "LIBBSP_ETSEC.h"
 /* ----------------------- */
 /* eTsec id                */
 /* ----------------------- */
 #define    ETSEC1_ID   0ul   /* */
 #define    ETSEC2_ID   0x1ul   /* */
 #define    ETSEC3_ID   0x2ul   /* */
 
 /* ----------------------- */
 /* eTsec base address      */
 /* ----------------------- */
 #define CCSR_BASE_ADDR                 ((uint32_t)0xFF700000)   /* */
 #define ETSEC1_BASE_ADDR               ((uint32_t)0x000B0000)   /* */
 #define ETSEC2_BASE_ADDR               ((uint32_t)0x000B1000)   /* */
 #define ETSEC3_BASE_ADDR               ((uint32_t)0x000B2000)   /* */
 
  /* ----------------------- */
 /* MDIO base address       */
 /* ----------------------- */
 #define ETSEC1_MDIO_BASE_ADDR          ((uint32_t)0x00024000)   /* */
 #define ETSEC2_MDIO_BASE_ADDR          ((uint32_t)0x00025000)   /* */
 #define ETSEC3_MDIO_BASE_ADDR          ((uint32_t)0x00026000)   /* */
 
 /* ----------------------- */
 /* eTsec register values   */
 /* ----------------------- */
 
 /* MACCFG1 register values */
 #define ETSEC_MACCFG1_SOFT_RESET             ((uint32_t)0x80000000)   /* */
 #define ETSEC_MACCFG1_RESET_RX_MC            ((uint32_t)0x00080000)   /* */
 #define ETSEC_MACCFG1_RESET_TX_MC            ((uint32_t)0x00040000)   /* */
 #define ETSEC_MACCFG1_RESET_RX_FUN           ((uint32_t)0x00020000)   /* */
 #define ETSEC_MACCFG1_RESET_TX_FUN           ((uint32_t)0x00010000)   /* */
 #define ETSEC_MACCFG1_LOOPBACK               ((uint32_t)0x00000100)   /* */
 #define ETSEC_MACCFG1_RX_FLOW                ((uint32_t)0x00000020)   /* */
 #define ETSEC_MACCFG1_TX_FLOW                ((uint32_t)0x00000010)   /* */
 #define ETSEC_MACCFG1_SYNCD_RX_EN            ((uint32_t)0x00000008)   /* */
 #define ETSEC_MACCFG1_RX_EN                  ((uint32_t)0x00000004)   /* */
 #define ETSEC_MACCFG1_SYNCD_TX_EN            ((uint32_t)0x00000002)   /* */
 #define ETSEC_MACCFG1_TX_EN                  ((uint32_t)0x00000001)   /* */
 
 /* MACCFG2 register values */
 #define ETSEC_MACCFG2_PREAMB_SIZE            ((uint32_t)0x00007000)   /* */
 #define ETSEC_MACCFG2_FULL_DUPLEX            ((uint32_t)0x00000001)   /* */
 #define ETSEC_MACCFG2_MII                    ((uint32_t)0x00000100)   /* */
 #define ETSEC_MACCFG2_IF_1GB                 ((uint32_t)0x00000200)   /* 1Gbit/s */
 #define ETSEC_MACCFG2_IF_100MB               ((uint32_t)0x00000100)   /* 100 Mbit/s */
 #define ETSEC_MACCFG2_HUGEFRAME              ((uint32_t)0x00000020)   /* */
 #define ETSEC_MACCFG2_LENGTHCHECK            ((uint32_t)0x00000010)   /* */
 #define ETSEC_MACCFG2_MPEN                   ((uint32_t)0x00000008)   /* */
 #define ETSEC_MACCFG2_PAD_CRC                ((uint32_t)0x00000004)   /* */
 #define ETSEC_MACCFG2_CRC_HW                 ((uint32_t)0x00000002)   /* */
 #define ETSEC_MACCFG2_INIT                   (ETSEC_MACCFG2_IF_100MB | ETSEC_MACCFG2_FULL_DUPLEX | ETSEC_MACCFG2_PREAMB_SIZE | ETSEC_MACCFG2_CRC_HW)
 
 /* TQUEUE register values */
 #define  ETSEC_TQUEUE_0_EN                   ((uint32_t)0x00008000)   /* */
 
 /* RQUEUE register values */
 #define  ETSEC_RQUEUE_0_EN                   ((uint32_t)0x00000080)   /* */

 /* ENCTRL register values */

 #define ETSEC_ECNTRL_TBIM                    ((uint32_t)0x00000020)  /* TBI mode                     */
 #define ETSEC_ECNTRL_RPM                     ((uint32_t)0x00000010)  /* Reduced-pin mode for Gigabit */
 #define ETSEC_ECNTRL_R100M                   ((uint32_t)0x00000008)  /* RGMII/RMII 100 mode          */
 #define ETSEC_ECNTRL_RMM                     ((uint32_t)0x00000004)  /* reduced-pin mode for 10/100  */
 #define ETSEC_ECNTRL_SGMIIM                  ((uint32_t)0x00000002)  /* serial GMII mode       */ 
 #define ETSEC_ECNTRL_STEN                    ((uint32_t)0x00001000)  /* statistics enabled  */
 #define ETSEC_ECNTRL_AUTOZ                   ((uint32_t)0x00002000)  /* zero MIB counters   */
 #define ETSEC_ECNTRL_CLRCNT                  ((uint32_t)0x00004000)  /* clear statistics    */

 /* RCTRL register values */
 #define ETSEC_RCTRL_ALL_FRAMES               ((uint32_t)0x00000008)  /* ETSEC accepts all ethernet frames */
 #define ETSEC_RCTRL_BROADCAST_REJECT         ((uint32_t)0x00000010) 
 #define ETSEC_RCTRL_INIT                     ETSEC_RCTRL_ALL_FRAMES
 
 /* MRBLR register value */
 #define ETSEC_MRBLR_BUFFER_SIZE              C_LIBBSP_ETSEC_ETHERNET_RX_BUFFER_SIZE  /* shall be mutliple of 64 (cf datasheet)*/
 
 /* MAXFRM register value */
 #define ETSEC_MAXFRM_FRAME_SIZE              C_LIBBSP_ETSEC_ETHERNET_MAX_FRAME_SIZE   /* */
 
 /* MASK FOR RBASEx and TBASEx registers */ 
 #define ETSEC_BASE0_MASK               ((uint32_t)0xFFFFFFF8)   /* */
 #define ETSEC_BASEH_MASK               ((uint32_t)0x00000007)   /* */
 
 /* DMACTRL register values */
 #define ETSEC_DMACTRL_DATA_SNOOP       ((uint32_t)0x00000080)   /* */
 #define ETSEC_DMACTRL_TXBD_SNOOP       ((uint32_t)0x00000040)   /* */
 #define ETSEC_DMACTRL_GRS              ((uint32_t)0x00000010)   /* */
 #define ETSEC_DMACTRL_GTS              ((uint32_t)0x00000008)   /* */
 #define ETSEC_DMACTRL_TOD              ((uint32_t)0x00000004)   /* */
 #define ETSEC_DMACTRL_WWR              ((uint32_t)0x00000002)   /* */
 #define ETSEC_DMACTRL_WOP              ((uint32_t)0x00000001)   /* */
 /*#define ETSEC_DMACTRL_INIT             (ETSEC_DMACTRL_DATA_SNOOP | ETSEC_DMACTRL_TXBD_SNOOP | ETSEC_DMACTRL_GRS | ETSEC_DMACTRL_GTS)  */
 /*#define ETSEC_DMACTRL_INIT_END         (ETSEC_DMACTRL_DATA_SNOOP | ETSEC_DMACTRL_TXBD_SNOOP) */
 /*#define ETSEC_DMACTRL_INIT             ((uint32_t)0x000000c3)   */ 
 #define ETSEC_DMACTRL_INIT             (ETSEC_DMACTRL_GRS | ETSEC_DMACTRL_GTS)  
 #define ETSEC_DMACTRL_INIT_END         ETSEC_DMACTRL_INIT
  
 /* ----------------------- */
 /* buffer descriptor value */
 /* ----------------------- */  
 
  /* RxBD control bits */
 #define ETSEC_RX_BDCTL_W        ((uint16_t)0x2000)
 #define ETSEC_RX_BDCTL_E        ((uint16_t)0x8000)
 #define ETSEC_RX_BDCTL_E_W      ((uint16_t)(ETSEC_RX_BDCTL_E|ETSEC_RX_BDCTL_W))
 
 /* TxBD control bits */
 #define ETSEC_TX_BDCTL_W        ((uint16_t)0x2000)
 #define ETSEC_TX_BDCTL_I        ((uint16_t)0x1000)
 #define ETSEC_TX_BDCTL_L        ((uint16_t)0x0800)
 #define ETSEC_TX_BDCTL_TC       ((uint16_t)0x0400)
 #define ETSEC_TX_BDCTL_NOT_R    ((uint16_t)0x0000)
 #define ETSEC_TX_BDCTL_NOT_R_W  ETSEC_TX_BDCTL_W
 #define ETSEC_TX_BDCTL_R        ((uint16_t)0x8000)
 #define ETSEC_TX_BDCTL_R_W      ((uint16_t)(ETSEC_TX_BDCTL_R|ETSEC_TX_BDCTL_W))
 #define ETSEC_TX_BDCTL_R_L      ((uint16_t)(ETSEC_TX_BDCTL_R|ETSEC_TX_BDCTL_L))
 #define ETSEC_TX_BDCTL_R_L_W    ((uint16_t)(ETSEC_TX_BDCTL_R_L|ETSEC_TX_BDCTL_W))
 #define ETSEC_TX_BDCTL_R_L_TC   ((uint16_t)(ETSEC_TX_BDCTL_R_L|ETSEC_TX_BDCTL_TC))
 #define ETSEC_TX_BDCTL_R_L_TC_W ((uint16_t)(ETSEC_TX_BDCTL_R_L_TC|ETSEC_TX_BDCTL_W))
  
 /* BD parameters */
 #define ETSEC_BD_PARAM_FLAGS    0
 #define ETSEC_BD_PARAM_LENGTH   1 
 #define ETSEC_BD_PARAM_BUFADDR  2
 #define ETSEC_BD_NB_PARAMETER   3 /* 3 parameters for a bd : flags, legnth and bufptr */ 
  
 /* ---------- provided types: ----------------------------------------------- */
 typedef struct
{
    /* eTSEC General Control and Status Registers */
    uint32_t volatile     TSEC_ID;               /* OFFSET_0000 */
    uint32_t volatile     TSEC_ID2;              /* OFFSET_0004 */
    uint32_t volatile     Reserved010[0x2];      /* OFFSET_0008 -> OFFSET_000C */
    uint32_t volatile     IEVENTGx;              /* OFFSET_0010 */
    uint32_t volatile     IMASKGx;               /* OFFSET_0014 */
    uint32_t volatile     EDIS;                  /* OFFSET_0018 */
    uint32_t volatile     Reserved020[0x1];      /* OFFSET_001C */
    uint32_t volatile     ECNTRL;                /* OFFSET_0020 */
    uint32_t volatile     Reserved030[0x1];      /* OFFSET_0024 */
    uint32_t volatile     PTV;                   /* OFFSET_0028 */
    uint32_t volatile     DMACTRL;               /* OFFSET_002C */
    uint32_t volatile     TBIPA;                 /* OFFSET_0030 */
    uint32_t volatile     Reserved040[0x33];     /* OFFSET_0034 -> OFFSET_00FC */
    /* eTSEC Transmit Control and Status Registers */
    uint32_t volatile     TCTRL;                 /* OFFSET_0100 */
    uint32_t volatile     TSTAT;                 /* OFFSET_0104 */
    uint32_t volatile     DFVLAN;                /* OFFSET_0108 */
    uint32_t volatile     Reserved050[0x1];      /* OFFSET_010C */
    uint32_t volatile     TXIC;                  /* OFFSET_0110 */
    uint32_t volatile     TQUEUE;                /* OFFSET_0114 */
    uint32_t volatile     Reserved060[0xA];      /* OFFSET_0118 -> OFFSET_013C */
    uint32_t volatile     TR03WT;                /* OFFSET_0140 */
    uint32_t volatile     TR47WT;                /* OFFSET_0144 */
    uint32_t volatile     Reserved070[0xE];      /* OFFSET_0148 -> OFFSET_017C */
    uint32_t volatile     TBDBPH;                /* OFFSET_0180 */
    uint32_t volatile     TBPTR0;                /* OFFSET_0184 */
    uint32_t volatile     Reserved080[0x1];      /* OFFSET_0188 */
    uint32_t volatile     TBPTR1;                /* OFFSET_018C */
    uint32_t volatile     Reserved090[0x1];      /* OFFSET_0190 */
    uint32_t volatile     TBPTR2;                /* OFFSET_0194 */
    uint32_t volatile     Reserved100[0x1];      /* OFFSET_0198 */
    uint32_t volatile     TBPTR3;                /* OFFSET_019C */
    uint32_t volatile     Reserved110[0x1];      /* OFFSET_01A0 */
    uint32_t volatile     TBPTR4;                /* OFFSET_01A4 */
    uint32_t volatile     Reserved120[0x1];      /* OFFSET_01A8 */
    uint32_t volatile     TBPTR5;                /* OFFSET_01AC */
    uint32_t volatile     Reserved130[0x1];      /* OFFSET_01B0 */
    uint32_t volatile     TBPTR6;                /* OFFSET_01B4 */
    uint32_t volatile     Reserved140[0x1];      /* OFFSET_01B8 */
    uint32_t volatile     TBPTR7;                /* OFFSET_01BC */
    uint32_t volatile     Reserved150[0x10];     /* OFFSET_01C0 -> OFFSET_01FC */
    uint32_t volatile     TBASEH;                /* OFFSET_0200 */
    uint32_t volatile     TBASE0;                /* OFFSET_0204 */
    uint32_t volatile     Reserved160[0x1];      /* OFFSET_0208 */
    uint32_t volatile     TBASE1;                /* OFFSET_020C */
    uint32_t volatile     Reserved170[0x1];      /* OFFSET_0210 */
    uint32_t volatile     TBASE2;                /* OFFSET_0214 */
    uint32_t volatile     Reserved180[0x1];      /* OFFSET_0218 */
    uint32_t volatile     TBASE3;                /* OFFSET_021C */
    uint32_t volatile     Reserved190[0x1];      /* OFFSET_0220 */
    uint32_t volatile     TBASE4;                /* OFFSET_0224 */
    uint32_t volatile     Reserved200[0x1];      /* OFFSET_0228 */
    uint32_t volatile     TBASE5;                /* OFFSET_022C */
    uint32_t volatile     Reserved210[0x1];      /* OFFSET_0230 */
    uint32_t volatile     TBASE6;                /* OFFSET_0234 */
    uint32_t volatile     Reserved220[0x1];      /* OFFSET_0238 */
    uint32_t volatile     TBASE7;                /* OFFSET_023C */
    uint32_t volatile     Reserved230[0x10];     /* OFFSET_0240 > OFFSET_027C */
    uint32_t volatile     TMR_TXTS1_ID;          /* OFFSET_0280 */
    uint32_t volatile     TMR_TXTS2_ID;          /* OFFSET_0284 */
    uint32_t volatile     Reserved240[0xE];      /* OFFSET_02BC */
    uint32_t volatile     TMR_TXTS1_H;           /* OFFSET_02C0 */
    uint32_t volatile     TMR_TXTS1_L;           /* OFFSET_02C4 */
    uint32_t volatile     TMR_TXTS2_H;           /* OFFSET_02C8 */
    uint32_t volatile     TMR_TXTS2_L;           /* OFFSET_02CC */
    uint32_t volatile     Reserved250[0xC];      /* OFFSET_02D0 -> OFFSET_02FC */
    /* eTSEC Receive Control and Status Registers */
    uint32_t volatile     RCTRL;                 /* OFFSET_0300 */
    uint32_t volatile     RSTAT;                 /* OFFSET_0304 */
    uint32_t volatile     Reserved260[0x2];      /* OFFSET_0308 -> OFFSET_030C */
    uint32_t volatile     RXIC;                  /* OFFSET_0310 */
    uint32_t volatile     RQUEUE;                /* OFFSET_0314 */
    uint32_t volatile     Reserved270[0x6];      /* OFFSET_0318 */
    uint32_t volatile     RBIFX;                 /* OFFSET_0330 */
    uint32_t volatile     RQFAR;                 /* OFFSET_0334 */
    uint32_t volatile     RQFCR;                 /* OFFSET_0338 */
    uint32_t volatile     RQFPR;                 /* OFFSET_033C */
    uint32_t volatile     MRBLR;                 /* OFFSET_0340 */
    uint32_t volatile     Reserved280[0xF];      /* OFFSET_037C */
    uint32_t volatile     RBDBPH;                /* OFFSET_0380 */
    uint32_t volatile     RBPTR0;                /* OFFSET_0384 */
    uint32_t volatile     Reserved290[0x1];      /* OFFSET_0388 */
    uint32_t volatile     RBPTR1;                /* OFFSET_038C */
    uint32_t volatile     Reserved300[0x1];      /* OFFSET_0390 */
    uint32_t volatile     RBPTR2;                /* OFFSET_0394 */
    uint32_t volatile     Reserved310[0x1];      /* OFFSET_0398 */
    uint32_t volatile     RBPTR3;                /* OFFSET_039C */
    uint32_t volatile     Reserved320[0x1];      /* OFFSET_03A0 */
    uint32_t volatile     RBPTR4;                /* OFFSET_03A4 */
    uint32_t volatile     Reserved330[0x1];      /* OFFSET_03A8 */
    uint32_t volatile     RBPTR5;                /* OFFSET_03AC */
    uint32_t volatile     Reserved340[0x1];      /* OFFSET_03B0 */
    uint32_t volatile     RBPTR6;                /* OFFSET_03B4 */
    uint32_t volatile     Reserved350[0x1];      /* OFFSET_03B8 */
    uint32_t volatile     RBPTR7;                /* OFFSET_03BC */
    uint32_t volatile     Reserved360[0x10];     /* OFFSET_03C0 -> 3FC */
    uint32_t volatile     RBASEH;                /* OFFSET_0400 */
    uint32_t volatile     RBASE0;                /* OFFSET_0404 */
    uint32_t volatile     Reserved370[0x1];      /* OFFSET_0408 */
    uint32_t volatile     RBASE1;                /* OFFSET_040C */
    uint32_t volatile     Reserved380[0x1];      /* OFFSET_0410 */
    uint32_t volatile     RBASE2;                /* OFFSET_0414 */
    uint32_t volatile     Reserved390[0x1];      /* OFFSET_0418 */
    uint32_t volatile     RBASE3;                /* OFFSET_041C */
    uint32_t volatile     Reserved400[0x1];      /* OFFSET_0420 */
    uint32_t volatile     RBASE4;                /* OFFSET_0424 */
    uint32_t volatile     Reserved410[0x1];      /* OFFSET_0428 */
    uint32_t volatile     RBASE5;                /* OFFSET_042C */
    uint32_t volatile     Reserved420[0x1];      /* OFFSET_0430 */
    uint32_t volatile     RBASE6;                /* OFFSET_0434 */
    uint32_t volatile     Reserved430[0x1];      /* OFFSET_0438 */
    uint32_t volatile     RBASE7;                /* OFFSET_043C */
    uint32_t volatile     Reserved440[0x20];     /* OFFSET_0440 -> OFFSET_04BC */
    uint32_t volatile     TMR_RXTS_H;            /* OFFSET_04C0 */
    uint32_t volatile     TMR_RXTS_L;            /* OFFSET_04C4 */
    uint32_t volatile     Reserved450[0xE];      /* OFFSET_04C8 -> OFFSET_04F0 */
    /* eTSEC MAC Registers */                   
    uint32_t volatile     MACCFG1;               /* OFFSET_0500 */
    uint32_t volatile     MACCFG2;               /* OFFSET_0504 */
    uint32_t volatile     IPGIFG;                /* OFFSET_0508 */
    uint32_t volatile     HAFDUP;                /* OFFSET_050C */
    uint32_t volatile     MAXFRM;                /* OFFSET_0510 */
    uint32_t volatile     Reserved460[0xA];      /* OFFSET_0514 ->  OFFSET_0538 */
    uint32_t volatile     IFSTAT;                /* OFFSET_053C */
    uint32_t volatile     MACSTNADDR1;           /* OFFSET_0540 */
    uint32_t volatile     MACSTNADDR2;           /* OFFSET_0544 */
    uint32_t volatile     MAC01ADDR1;            /* OFFSET_0548 */
    uint32_t volatile     MAC01ADDR2;            /* OFFSET_054C */
    uint32_t volatile     MAC02ADDR1;            /* OFFSET_0550 */
    uint32_t volatile     MAC02ADDR2;            /* OFFSET_0554 */
    uint32_t volatile     MAC03ADDR1;            /* OFFSET_0558 */
    uint32_t volatile     MAC03ADDR2;            /* OFFSET_055C */
    uint32_t volatile     MAC04ADDR1;            /* OFFSET_0560 */
    uint32_t volatile     MAC04ADDR2;            /* OFFSET_0564 */
    uint32_t volatile     MAC05ADDR1;            /* OFFSET_0568 */
    uint32_t volatile     MAC05ADDR2;            /* OFFSET_056C */
    uint32_t volatile     MAC06ADDR1;            /* OFFSET_0570 */
    uint32_t volatile     MAC06ADDR2;            /* OFFSET_0574 */
    uint32_t volatile     MAC07ADDR1;            /* OFFSET_0578 */
    uint32_t volatile     MAC07ADDR2;            /* OFFSET_057C */
    uint32_t volatile     MAC08ADDR1;            /* OFFSET_0580 */
    uint32_t volatile     MAC08ADDR2;            /* OFFSET_0584 */
    uint32_t volatile     MAC09ADDR1;            /* OFFSET_0588 */
    uint32_t volatile     MAC09ADDR2;            /* OFFSET_058C */
    uint32_t volatile     MAC10ADDR1;            /* OFFSET_0590 */
    uint32_t volatile     MAC10ADDR2;            /* OFFSET_0594 */
    uint32_t volatile     MAC11ADDR1;            /* OFFSET_0598 */
    uint32_t volatile     MAC11ADDR2;            /* OFFSET_059C */
    uint32_t volatile     MAC12ADDR1;            /* OFFSET_05A0 */
    uint32_t volatile     MAC12ADDR2;            /* OFFSET_05A4 */
    uint32_t volatile     MAC13ADDR1;            /* OFFSET_05A8 */
    uint32_t volatile     MAC13ADDR2;            /* OFFSET_05AC */
    uint32_t volatile     MAC14ADDR1;            /* OFFSET_05B0 */
    uint32_t volatile     MAC14ADDR2;            /* OFFSET_05B4 */
    uint32_t volatile     MAC15ADDR1;            /* OFFSET_05B8 */
    uint32_t volatile     MAC15ADDR2;            /* OFFSET_05BC */
    uint32_t volatile     Reserved480[0x30];     /* OFFSET_05C0 -> 67C */
    /* eTSEC Transmit and Receive Counters */   
    uint32_t volatile     TR64;                  /* OFFSET_0680 */
    uint32_t volatile     TR127;                 /* OFFSET_0684 */
    uint32_t volatile     TR255;                 /* OFFSET_0688 */
    uint32_t volatile     TR511;                 /* OFFSET_068C */
    uint32_t volatile     TR1K;                  /* OFFSET_0690 */
    uint32_t volatile     TRMAX;                 /* OFFSET_0694 */
    uint32_t volatile     TRMGV;                 /* OFFSET_0698 */
    /* eTSEC Receive Counters */                 
    uint32_t volatile     RBYT;                  /* OFFSET_069C */
    uint32_t volatile     RPKT;                  /* OFFSET_06A0 */
    uint32_t volatile     RFCS;                  /* OFFSET_06A4 */
    uint32_t volatile     RMCA;                  /* OFFSET_06A8 */
    uint32_t volatile     RBCA;                  /* OFFSET_06AC */
    uint32_t volatile     RXCF;                  /* OFFSET_06B0 */
    uint32_t volatile     RXPF;                  /* OFFSET_06B4 */
    uint32_t volatile     RXUO;                  /* OFFSET_06B8 */
    uint32_t volatile     RALN;                  /* OFFSET_06BC */
    uint32_t volatile     RFLR;                  /* OFFSET_06C0 */
    uint32_t volatile     RCDE;                  /* OFFSET_06C4 */
    uint32_t volatile     RCSE;                  /* OFFSET_06C8 */
    uint32_t volatile     RUND;                  /* OFFSET_06CC */
    uint32_t volatile     ROVR;                  /* OFFSET_06D0 */
    uint32_t volatile     RFRG;                  /* OFFSET_06D4 */
    uint32_t volatile     RJBR;                  /* OFFSET_06D8 */
    uint32_t volatile     RDRP;                  /* OFFSET_06DC */
    /* eTSEC Transmit Counters */               
    uint32_t volatile     TBYT;                  /* OFFSET_06E0 */
    uint32_t volatile     TPKT;                  /* OFFSET_06E4 */
    uint32_t volatile     TMCA;                  /* OFFSET_06E8 */
    uint32_t volatile     TBCA;                  /* OFFSET_06EC */
    uint32_t volatile     TXPF;                  /* OFFSET_06F0 */
    uint32_t volatile     TDFR;                  /* OFFSET_06F4 */
    uint32_t volatile     TEDF;                  /* OFFSET_06F8 */
    uint32_t volatile     TSCL;                  /* OFFSET_06FC */
    uint32_t volatile     TMCL;                  /* OFFSET_0700 */
    uint32_t volatile     TLCL;                  /* OFFSET_0704 */
    uint32_t volatile     TXCL;                  /* OFFSET_0708 */
    uint32_t volatile     TNCL;                  /* OFFSET_070C */
    uint32_t volatile     Reserved490[0x1];      /* OFFSET_0710 */
    uint32_t volatile     TDRP;                  /* OFFSET_0714 */
    uint32_t volatile     TJBR;                  /* OFFSET_0718 */
    uint32_t volatile     TFCS;                  /* OFFSET_071C */
    uint32_t volatile     TXCF;                  /* OFFSET_0720 */
    uint32_t volatile     TOVR;                  /* OFFSET_0724 */
    uint32_t volatile     TUND;                  /* OFFSET_0728 */
    uint32_t volatile     TFRG;                  /* OFFSET_072C */
    /* eTSEC Counter Control and TOE Statistics Registers */
    uint32_t volatile     CAR1;                  /* OFFSET_0730 */
    uint32_t volatile     CAR2;                  /* OFFSET_0734 */
    uint32_t volatile     CAM1;                  /* OFFSET_0738 */
    uint32_t volatile     CAM2;                  /* OFFSET_073C */
    uint32_t volatile     RREJ;                  /* OFFSET_0740 */
    uint32_t volatile     Reserved500[0x2F];     /* OFFSET_0744 -> OFFSET_07FC */
    /* Hash Function Registers */               
    uint32_t volatile     IGADDR0;               /* OFFSET_0800 */
    uint32_t volatile     IGADDR1;               /* OFFSET_0804 */
    uint32_t volatile     IGADDR2;               /* OFFSET_0808 */
    uint32_t volatile     IGADDR3;               /* OFFSET_080C */
    uint32_t volatile     IGADDR4;               /* OFFSET_0810 */
    uint32_t volatile     IGADDR5;               /* OFFSET_0814 */
    uint32_t volatile     IGADDR6;               /* OFFSET_0818 */
    uint32_t volatile     IGADDR7;               /* OFFSET_081C */
    uint32_t volatile     Reserved510[0x18];     /* OFFSET_0820 -> OFFSET_087C */
    uint32_t volatile     GADDR0;                /* OFFSET_0880 */
    uint32_t volatile     GADDR1;                /* OFFSET_0884 */
    uint32_t volatile     GADDR2;                /* OFFSET_0888 */
    uint32_t volatile     GADDR3;                /* OFFSET_088C */
    uint32_t volatile     GADDR4;                /* OFFSET_0890 */
    uint32_t volatile     GADDR5;                /* OFFSET_0894 */
    uint32_t volatile     GADDR6;                /* OFFSET_0898 */
    uint32_t volatile     GADDR7;                /* OFFSET_089C */
    uint32_t volatile     Reserved520[0xD6];     /* OFFSET_0900 -> OFFSET_0BF4 */
    /* eTSEC DMA Attribute Registers */         
    uint32_t volatile     ATTR;                  /* OFFSET_0BF8 */
    uint32_t volatile     ATTRELI;               /* OFFSET_0BFC */
    /* eTSEC Lossless Flow Control Registers */ 
    uint32_t volatile     RQPRM0;                /* OFFSET_0C00 */
    uint32_t volatile     RQPRM1;                /* OFFSET_0C04 */
    uint32_t volatile     RQPRM2;                /* OFFSET_0C08 */
    uint32_t volatile     RQPRM3;                /* OFFSET_0C0C */
    uint32_t volatile     RQPRM4;                /* OFFSET_0C10 */
    uint32_t volatile     RQPRM5;                /* OFFSET_0C14 */
    uint32_t volatile     RQPRM6;                /* OFFSET_0C18 */
    uint32_t volatile     RQPRM7;                /* OFFSET_0C1C */
    uint32_t volatile     Reserved550[0x9];      /* OFFSET_0C20 -> OFFSET_0C40 */
    uint32_t volatile     RFBPTR0;               /* OFFSET_0C44 */
    uint32_t volatile     Reserved560[0x1];      /* OFFSET_0C48 */
    uint32_t volatile     RFBPTR1;               /* OFFSET_0C4C */
    uint32_t volatile     Reserved570[0x1];      /* OFFSET_0C50 */
    uint32_t volatile     RFBPTR2;               /* OFFSET_0C54 */
    uint32_t volatile     Reserved580[0x1];      /* OFFSET_0C58 */
    uint32_t volatile     RFBPTR3;               /* OFFSET_0C5C */
    uint32_t volatile     Reserved590[0x1];      /* OFFSET_0C60 */
    uint32_t volatile     RFBPTR4;               /* OFFSET_0C64 */
    uint32_t volatile     Reserved600[0x1];      /* OFFSET_0C68 */
    uint32_t volatile     RFBPTR5;               /* OFFSET_0C6C */
    uint32_t volatile     Reserved610[0x1];      /* OFFSET_0C70 */
    uint32_t volatile     RFBPTR6;               /* OFFSET_0C74 */
    uint32_t volatile     Reserved620[0x1];      /* OFFSET_0C78 */
    uint32_t volatile     RFBPTR7;               /* OFFSET_0C7C */
    /* eTSEC Future Expansion Space */          
    uint32_t volatile     Reserved640[0x60];     /* OFFSET_0C80 -> OFFSET_0DFC */
    /* eTSEC IEEE 1588 Registers */             
    uint32_t volatile     TMR_CTRL;              /* OFFSET_0E00 */
    uint32_t volatile     TMR_TEVENT;            /* OFFSET_0E04 */
    uint32_t volatile     TMR_TEMASK;            /* OFFSET_0E08 */
    uint32_t volatile     TMR_PEVENT;            /* OFFSET_0E0C */
    uint32_t volatile     TMR_PEMASK;            /* OFFSET_0E10 */
    uint32_t volatile     TMR_STAT;              /* OFFSET_0E14 */
    uint32_t volatile     TMR_CNT_H;             /* OFFSET_0E18 */
    uint32_t volatile     TMR_CNT_L;             /* OFFSET_0E1C */
    uint32_t volatile     TMR_ADD;               /* OFFSET_0E20 */
    uint32_t volatile     TMR_ACC;               /* OFFSET_0E24 */
    uint32_t volatile     TMR_PRSC;              /* OFFSET_0E28 */
    uint32_t volatile     Reserved650[0x1];      /* OFFSET_0E2C */
    uint32_t volatile     TMROFF_H;              /* OFFSET_0E30 */
    uint32_t volatile     TMROFF_L;              /* OFFSET_0E34 */
    uint32_t volatile     Reserved660[0x2];      /* OFFSET_0E38 -> OFFSET_0E3C */
    uint32_t volatile     TMR_ALARM1_H;          /* OFFSET_0E40 */
    uint32_t volatile     TMR_ALARM1_L;          /* OFFSET_0E44 */
    uint32_t volatile     TMR_ALARM2_H;          /* OFFSET_0E48 */
    uint32_t volatile     TMR_ALARM2_L;          /* OFFSET_0E4C */
    uint32_t volatile     Reserved670[0xC];      /* OFFSET_0E50 -> OFFSET_0E7C */
    uint32_t volatile     TMR_FIPER1;            /* OFFSET_0E80 */
    uint32_t volatile     TMR_FIPER2;            /* OFFSET_0E84 */
    uint32_t volatile     TMR_FIPER3;            /* OFFSET_0E88 */
    uint32_t volatile     Reserved680[0x5];      /* OFFSET_0E8C -> OFFSET_0E9C */
    uint32_t volatile     TMR_ETTS1_H;           /* OFFSET_0EA0 */
    uint32_t volatile     TMR_ETTS1_L;           /* OFFSET_0EA4 */
    uint32_t volatile     TMR_ETTS2_H;           /* OFFSET_0EA8 */
    uint32_t volatile     TMR_ETTS2_L;           /* OFFSET_0EAC */
    /* eTSEC Interrupt Steering and Coalescing Registers */
    uint32_t volatile     TMR_ISRG0;             /* OFFSET_0EB0 */
    uint32_t volatile     TMR_ISRG1;             /* OFFSET_0EB4 */
    uint32_t volatile     Reserved690[0x6];      /* OFFSET_0EB8 -> OFFSET_0ECC */   
    uint32_t volatile     TMR_RXIC0;             /* OFFSET_0ED0 */
    uint32_t volatile     TMR_RXIC1;             /* OFFSET_0ED4 */
    uint32_t volatile     TMR_RXIC2;             /* OFFSET_0ED8 */
    uint32_t volatile     TMR_RXIC3;             /* OFFSET_0EDC */
    uint32_t volatile     TMR_RXIC4;             /* OFFSET_0EE0 */
    uint32_t volatile     TMR_RXIC5;             /* OFFSET_0EE4 */
    uint32_t volatile     TMR_RXIC6;             /* OFFSET_0EE8 */
    uint32_t volatile     TMR_RXIC7;             /* OFFSET_0EEC */
    uint32_t volatile     Reserved700[0x8];      /* OFFSET_0EF0 -> OFFSET_0F0C */   
    uint32_t volatile     TMR_TXIC0;             /* OFFSET_0F10 */
    uint32_t volatile     TMR_TXIC1;             /* OFFSET_0F14 */
    uint32_t volatile     TMR_TXIC2;             /* OFFSET_0F18 */
    uint32_t volatile     TMR_TXIC3;             /* OFFSET_0F1C */
    uint32_t volatile     TMR_TXIC4;             /* OFFSET_0F20 */
    uint32_t volatile     TMR_TXIC5;             /* OFFSET_0F24 */
    uint32_t volatile     TMR_TXIC6;             /* OFFSET_0F28 */
    uint32_t volatile     TMR_TXIC7;             /* OFFSET_0F2C */   
} t_ETSEC;  /* ETSEC registers definition */
 
/* ---------- provided operations: ------------------------------------------ */

extern void     etsec_reset    ( const uint32_t device );

extern void     etsec_init     (const uint32_t device, 
                                const uint8_t * const txbd_addr, 
                                const uint8_t * const rxbd_addr,
                                const TS_LIBBSP_ETSEC_ConfHostMac * const p_mac);

extern void     etsec_rx_enable (const uint32_t device, 
                                 const boolean_t enable);
                                 
extern void     etsec_tx_enable (const uint32_t device, 
                                 const boolean_t enable);

extern void     etsec_config    (const uint32_t device );

#endif /* ETSEC_H */
