/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_GLOBALS_H_
#define LIBBSP_FNAND_GLOBALS_H_
#include "LIBBSP_FNAND.h"
#include "LIBBSP_CCSR.h"



/*==== Definitions =====================================================================*/
#define C_FNAND_RCA 0x0100ul

/* Value in microseconds */
#define C_FNAND_TIME_1_MICRO_S       (0x29ul)
#define C_FNAND_T_1_S                1000000ul
#define C_FNAND_T_10_MS              10000ul
#define C_FNAND_T_5_MS               5000ul
#define C_FNAND_T_1_MS               1000ul
#define C_FNAND_T_200_US             200ul
#define C_FNAND_T_100_US             100ul
#define C_FNAND_T_15_US              15ul
#define C_FNAND_T_10_US              10ul
#define C_FNAND_T_5_US               5ul

#define C_FNAND_NAC_TIMING_400K      62500ul /* NAC Timing @400KHz */
#define C_FNAND_NAC_TIMING_10M       10100ul /* NAC Timing @10MHz  */

   /* Commands list */                       /* response type */
#define C_FNAND_GO_IDLE_STATE        0ul     /* R0 */
#define C_FNAND_SEND_OP_COND         1ul     /* R3 */
#define C_FNAND_ALL_SEND_CID         2ul     /* R2 */
#define C_FNAND_SET_RELATIVE_ADDR    3ul     /* R1 */
#define C_FNAND_SWITCH               6ul     /* R1B */
#define C_FNAND_SELECT_CARD          7ul     /* R1 */
#define C_FNAND_SEND_EXT_CSD         8ul     /* R1 */
#define C_FNAND_SEND_CSD             9ul     /* R2 */
#define C_FNAND_SEND_CID             10ul    /* R2 */
#define C_FNAND_STOP_TRANSMISSION    12ul    /* R1 (Read) / R1B (write) */
#define C_FNAND_SEND_STATUS          13ul    /* R1 */
#define C_FNAND_SET_BLOCKLEN         16ul    /* R1 */
#define C_FNAND_READ_SINGLE_BLOCK    17ul    /* R1 */
#define C_FNAND_READ_MULTIPLE_BLOCK  18ul    /* R1 */
#define C_FNAND_WRITE_DAT_UNTIL_STOP 20ul    /* R1 */
#define C_FNAND_SET_BLOCK_COUNT      23ul    /* R1 */
#define C_FNAND_WRITE_SINGLE_BLOCK   24ul    /* R1 */
#define C_FNAND_WRITE_MULTIPLE_BLOCK 25ul    /* R1 */
#define C_FNAND_ERASE_GROUP_START    35ul    /* R1 */
#define C_FNAND_ERASE_GROUP_END      36ul    /* R1 */
#define C_FNAND_ERASE                38ul    /* R1 */
#define C_FNAND_GENERAL_CMD          56ul    /* R1 */
#define C_FNAND_NO_COMMAND           255ul

#define C_FNAND_OPCOND_MAX_RETRIES 1000ul
#define C_FNAND_OPCOND_MAX_ERROR 3ul

#define C_FNAND_CARD_OP_COND 0x40FF8080ul
#define C_FNAND_CARD_OCR_READY 0xC0FF8080ul
#define C_FNAND_POWERCLASS_2 0x3BB0200ul
#define C_FNAND_DATABUS_WIDTH_4 0x3B70100ul

#define C_FNAND_MASK_SPEC_VERS 0x003C0000ul
#define C_FNAND_IRQSTAT_MASK_ERROR 0x117F0000ul

#define C_FNAND_MASK_ERR_RW 0xE0000000ul

/* Command type */
#define C_FNAND_NORMAL_COMMAND 0ul
#define C_FNAND_ABORT_COMMAND  3ul

#define C_FNAND_SINGLE_BLOCK 0ul
#define C_FNAND_MULTI_BLOCK  1ul

#define C_FNAND_WRITE_CMD 0ul
#define C_FNAND_READ_CMD  1ul

#define C_FNAND_NO_RESPONSE  0ul
#define C_FNAND_R1_RESPONSE  2ul  /* 48 bits response */
#define C_FNAND_R1B_RESPONSE 3ul  /* 48 bits response with busy */
#define C_FNAND_R2_RESPONSE  1ul  /* 136 bits response */
#define C_FNAND_R3_RESPONSE  2ul  /* 48 bits response */

#define C_LIBBSP_FNAND_HOSTVER_OFFSET 0x000000FCul
#define C_LIBBSP_FNAND_DCR_OFFSET 0x0000040Cul
#define C_LIBBSP_FNAND_GUTS_PMUXCR_OFFSET 0x000B2060ul

/*==== Controller Registers =======================================================================*/
/* eSDHC_BLKATTR register
 * Offset: CCSRBAR + 0x2_E004
 * Ref: P1020 Reference Manual p.1177 */
typedef union
{
   uint32_t R;
   struct
   {
      uint32_t BLKCNT:16;
      uint32_t :3;            /* Reserved */
      uint32_t BLKSZE:13;
   } B;
} TU_LIBBSP_FNAND_BLKATTR;

/* eSDHC_XFERTYP register
 * Offset: CCSRBAR + 0x2_E00C
 * Ref: P1020 Reference Manual p.1179 */
typedef union
{
   uint32_t R;
   struct
   {
      uint32_t :2;                   /* Reserved */
      uint32_t CMDINX:6;
      uint32_t CMDTYP:2;
      uint32_t DPSEL:1;
      uint32_t CICEN:1;
      uint32_t CCCEN:1;
      uint32_t :1;                   /* Reserved */
      uint32_t RSPTYP:2;
      uint32_t :10;                  /* Reserved */
      uint32_t MSBSEL:1;
      uint32_t DTDSEL:1;
      uint32_t :1;                   /* Reserved */
      uint32_t AC12EN:1;
      uint32_t BCEN:1;
      uint32_t DMAEN:1;
   } B;
} TU_LIBBSP_FNAND_XFERTYP;

/* eSDHC_PRSSTAT register
 * Offset: CCSRBAR + 0x2_E024
 * Ref: P1020 Reference Manual p.1184 */
typedef union
{
   uint32_t R;
   struct
   {
      uint32_t DLSL:8;
      uint32_t CLSL:1;
      uint32_t :3;                   /* Reserved */
      uint32_t WPSPL:1;
      uint32_t CDPL:1;
      uint32_t :1;                   /* Reserved */
      uint32_t CINS:1;
      uint32_t :4;                  /* Reserved */
      uint32_t BREN:1;
      uint32_t BWEN:1;
      uint32_t RTA:1;
      uint32_t WTA:1;
      uint32_t SDOFF:1;
      uint32_t PEROFF:1;
      uint32_t HCKOFF:1;
      uint32_t IPGOFF:1;
      uint32_t :1;                   /* Reserved */
      uint32_t DLA:1;
      uint32_t CDIHB:1;
      uint32_t CIHB:1;
   } B;
} TU_LIBBSP_FNAND_PRSSTAT;

/* eSDHC_PROCTL register
 * Offset: CCSRBAR + 0x2_E028
 * Ref: P1020 Reference Manual p.1189 */
typedef union
{
   uint32_t R;
   struct
   {
      uint32_t :5;            /* Reserved */
      uint32_t WECRM:1;
      uint32_t WECINS:1;
      uint32_t :6;            /* Reserved */
      uint32_t RWCTL:1;
      uint32_t CREQ:1;
      uint32_t SABGREQ:1;
      uint32_t :8;            /* Reserved */
      uint32_t CDSS:1;
      uint32_t CDTL:1;
      uint32_t EMODE:2;
      uint32_t D3CD:1;
      uint32_t DTW:2;
      uint32_t :1;            /* Reserved */
   } B;
} TU_LIBBSP_FNAND_PROCTL;

/* eSDHC_SYSCTL register
 * Offset: CCSRBAR + 0x2_E02C
 * Ref: P1020 Reference Manual p.1192 */
typedef union
{
   uint32_t R;
   struct
   {
      uint32_t :4;            /* Reserved */
      uint32_t INITA:1;
      uint32_t RSTD:1;
      uint32_t RSTC:1;
      uint32_t RSTA:1;
      uint32_t :4;            /* Reserved */
      uint32_t DTOCV:4;
      uint32_t SDCLKFS:8;
      uint32_t DVS:4;
      uint32_t SDCLKEN:1;
      uint32_t PEREN:1;
      uint32_t HCKEN:1;
      uint32_t IPGEN:1;
   } B;
} TU_LIBBSP_FNAND_SYSCTL;

/* eSDHC_IRQSTAT register
 * Offset: CCSRBAR + 0x2_E030
 * Ref: P1020 Reference Manual p.1195 */
typedef union
{
   uint32_t R;
   struct
   {
      uint32_t :3;            /* Reserved */
      uint32_t DMAE:1;
      uint32_t :3;            /* Reserved */
      uint32_t AC12E:1;
      uint32_t :1;            /* Reserved */
      uint32_t DEBE:1;
      uint32_t DCE:1;
      uint32_t DTOE:1;
      uint32_t CIE:1;
      uint32_t CEBE:1;
      uint32_t CCE:1;
      uint32_t CTOE:1;
      uint32_t :8;            /* Reserved */
      uint32_t CRM:1;
      uint32_t CINS:1;
      uint32_t BRR:1;
      uint32_t BWR:1;
      uint32_t DINT:1;
      uint32_t BGE:1;
      uint32_t TC:1;
      uint32_t CC:1;
   } B;
} TU_LIBBSP_FNAND_IRQSTAT;

/* eSDHC_IRQSTATEN register
 * Offset: CCSRBAR + 0x2_E034
 * Ref: P1020 Reference Manual p.1199 */
typedef union
{
   uint32_t R;
   struct
   {
      uint32_t :3;            /* Reserved */
      uint32_t DMAESEN:1;
      uint32_t :3;            /* Reserved */
      uint32_t AC12ESEN:1;
      uint32_t :1;            /* Reserved */
      uint32_t DEBESEN:1;
      uint32_t DCESEN:1;
      uint32_t DTOESEN:1;
      uint32_t CIESEN:1;
      uint32_t CEBESEN:1;
      uint32_t CCESEN:1;
      uint32_t CTOESEN:1;
      uint32_t :8;            /* Reserved */
      uint32_t CRMSEN:1;
      uint32_t CINSEN:1;
      uint32_t BRRSEN:1;
      uint32_t BWRSEN:1;
      uint32_t DINTSEN:1;
      uint32_t BGESEN:1;
      uint32_t TCSEN:1;
      uint32_t CCSEN:1;
   } B;
} TU_LIBBSP_FNAND_IRQSTATEN;

/* eSDHC_IRQSIGEN register
 * Offset: CCSRBAR + 0x038 = 0x2_E038
 * Ref: P1020 Reference Manual p.1202 */
typedef union
{
   uint32_t R;
   struct
   {
      uint32_t :3;            /* Reserved */
      uint32_t DMAEIEN:1;
      uint32_t :3;            /* Reserved */
      uint32_t AC12EIEN:1;
      uint32_t :1;            /* Reserved */
      uint32_t DEBEIEN:1;
      uint32_t DCEIEN:1;
      uint32_t DTOEIEN:1;
      uint32_t CIEIEN:1;
      uint32_t CEBEIEN:1;
      uint32_t CCEIEN:1;
      uint32_t CTOEIEN:1;
      uint32_t :8;            /* Reserved */
      uint32_t CRMIEN:1;
      uint32_t CINSIEN:1;
      uint32_t BRRIEN:1;
      uint32_t BWRIEN:1;
      uint32_t DINTIEN:1;
      uint32_t BGEIEN:1;
      uint32_t TCIEN:1;
      uint32_t CCIEN:1;
   } B;
} TU_LIBBSP_FNAND_IRQSIGEN;

/* eSDHC_WML register
 * Offset: CCSRBAR + 0x44 = 0x2_E044
 * Ref: P1020 Reference Manual p.1210 */
typedef union
{
      uint32_t R;
      struct
      {
         uint32_t :8;
         uint32_t WR_WML:8;
         uint32_t :8;
         uint32_t RD_WML:8;

      } B;
}TU_LIBBSP_FNAND_WML;

/* eSDHC_HOSTVER register R
 * Offset: CCSRBAR + 0x0FC = 2_E0FC
 * Ref: P1020 Reference Manual p.1213 */
typedef union
{
      uint32_t R;
      struct
      {
         uint32_t :16;
         uint32_t VVN:8;
         uint32_t SVN:8;
      } B;
}TU_LIBBSP_FNAND_HOSTVER;

/* eSDHC_DCR register R/W
 * Offset: CCSRBAR + 0x40C = 0x2_E40C
 * Ref: P1020 Reference Manual p.1214 */
typedef union
{
      uint32_t R;
      struct
      {
         uint32_t :16;
         uint32_t PRI:2;
         uint32_t :7;
         uint32_t SNOOP:1;
         uint32_t :3;
         uint32_t RD_SAFE:1;
         uint32_t RD_PFE:1;
         uint32_t RD_PF_SIZE:1;
      } B;
}TU_LIBBSP_FNAND_DCR;

/* Gereral Utilities PMUX Control Register (Alternate function signal multiplex control)
 * Offset: CCSRBAR + 0xE_0060
 * Ref: P1020 Reference Manual p.1625 */
typedef struct
{
   volatile uint32_t SD_DATA:1;           /* R/W  */
   volatile uint32_t FNAND_CD:1;          /* R/W  */
   volatile uint32_t FNAND_WP:1;          /* R/W  */
   volatile uint32_t :29;                 /* Non used fields / Reserved */
} TS_LIBBSP_FNAND_GUTS_PMUXCR;

/* eFNAND controller registers
 * Offset: CCSRBAR + 0x2_E000
 * Ref: P1020 Reference Manual p.1176 */
typedef struct
{
   volatile uint32_t DSADDR;                     /* R/W  */
   volatile TU_LIBBSP_FNAND_BLKATTR   BLKATTR;   /* R/W  */
   volatile uint32_t CMDARG;                     /* R/W  */
   volatile TU_LIBBSP_FNAND_XFERTYP   XFERTYP;   /* R/W  */
   volatile uint32_t CMDRSP0;                    /* R    */
   volatile uint32_t CMDRSP1;                    /* R    */
   volatile uint32_t CMDRSP2;                    /* R    */
   volatile uint32_t CMDRSP3;                    /* R    */
   volatile uint32_t DATPORT;                    /* R/W  */
   volatile TU_LIBBSP_FNAND_PRSSTAT   PRSSTAT;   /* R    */
   volatile TU_LIBBSP_FNAND_PROCTL    PROCTL;    /* R/W  */
   volatile TU_LIBBSP_FNAND_SYSCTL    SYSCTL;    /* R/W  */
   volatile TU_LIBBSP_FNAND_IRQSTAT   IRQSTAT;   /* R/W  */
   volatile TU_LIBBSP_FNAND_IRQSTATEN IRQSTATEN; /* R/W  */
   volatile TU_LIBBSP_FNAND_IRQSIGEN  IRQSIGEN;  /* R/W  */
   volatile uint32_t AUTOC12ERR;                 /* R    */
   volatile uint32_t HOSTCAPBLT;                 /* R    */
   volatile TU_LIBBSP_FNAND_WML WML;             /* R/W  */
   volatile uint32_t RESERVED[2];
   volatile uint32_t FEVT;                       /* W    */
   /* Two last registers are declared individually because them not have a continuous offset */
   /* HOSTVER register */
   /* DCR register */
} TS_LIBBSP_FNAND_HOST;

typedef enum
{
   E_LIBBSP_FNAND_CARD_OK,
   E_LIBBSP_FNAND_CARD_TIMEOUT,
   E_LIBBSP_FNAND_CARD_ERR_INHIBIT,
   E_LIBBSP_FNAND_CARD_ERR_RESET_CARD,
   E_LIBBSP_FNAND_CARD_ERR_VOLTAGE_VALID,
   E_LIBBSP_FNAND_CARD_ERR_CARD_ID,
   E_LIBBSP_FNAND_CARD_ERR_BUS_CONF
} TE_LIBBSP_FNAND_INIT_CARD;

typedef struct
{
   volatile uint32_t CMD_ARG;
   volatile TU_LIBBSP_FNAND_XFERTYP CMD_PARAM;
} TS_LIBBSP_FNAND_CMD;

typedef enum
{
   E_LIBBSP_FNAND_R1_R1B_RSP,        /* 48 bits response without/with busy */
   E_LIBBSP_FNAND_R1B_ACMD13_RSP,    /* 48 bits response with busy and auto CMD12*/
   E_LIBBSP_FNAND_R3_R4_R6_RSP,      /* 48 bits response (OCR register) */
   E_LIBBSP_FNAND_R2_RSP,            /* 136 bits response */
   E_LIBBSP_FNAND_NO_RSP             /* No response */
} TE_LIBBSP_FNAND_RSP_TYPE;

typedef enum
{
   E_LIBBSP_FNAND_HOST_OK,
   E_LIBBSP_FNAND_HOST_BAD_ADDR,
   E_LIBBSP_FNAND_HOST_TIMEOUT,
   E_LIBBSP_FNAND_HOST_NO_MEM
} TE_LIBBSP_FNAND_INIT_HOST;



extern TU_LIBBSP_FNAND_STATUSCARD  V_LIBBSP_FNAND_StatusCard;
extern TU_LIBBSP_FNAND_STATUSCARD* P_LIBBSP_FNAND_StatusCard;

extern TS_LIBBSP_FNAND_OP  V_LIBBSP_FNAND_Op;
extern TS_LIBBSP_FNAND_OP* P_LIBBSP_FNAND_Op;

extern TS_LIBBSP_FNAND_STATUS  V_LIBBSP_FNAND_Status;
extern TS_LIBBSP_FNAND_STATUS* P_LIBBSP_FNAND_Status;

extern const uint32_t C_FNAND_MAX_TIME;


extern volatile TS_LIBBSP_FNAND_HOST* const P_LIBBSP_FNAND_Host;
extern volatile TU_LIBBSP_FNAND_DCR* const P_LIBBSP_FNAND_FNAND_DCRReg;
extern volatile TS_LIBBSP_FNAND_GUTS_PMUXCR* const P_LIBBSP_FNAND_PMUXCRReg;


/*=================================================================================================*/

#endif /* LIBBSP_FNAND_GLOBALS_H_ */
