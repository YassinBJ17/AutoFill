/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_H
#define LIBBSP_FNAND_H

#if defined(__RTRT__)
#define __attribute__(x_dummy)
#endif

#include "LIBMCP_Types.h"

/*==== Definitions =====================================================================*/
/* 512 octets */
#define C_FNAND_BLOCK_SIZE 0x200ul
#define C_FNAND_CID_BUFFER_SIZE 4ul
#define C_FNAND_CSD_BUFFER_SIZE 4ul
#define C_FNAND_EXTCSD_BUFFER_SIZE 128ul
/*==== Types ===========================================================================*/

/*==== Memory Registers ===========================================================================*/
typedef enum
{
   E_LIBBSP_FNAND_CARD_STATE_IDLE      = 0,  /* IDLE State */
   E_LIBBSP_FNAND_CARD_STATE_READY     = 1,  /* Ready State */
   E_LIBBSP_FNAND_CARD_STATE_IDENT     = 2,  /* Identification State */
   E_LIBBSP_FNAND_CARD_STATE_STBY      = 3,  /* Standby State */
   E_LIBBSP_FNAND_CARD_STATE_TRAN      = 4,  /* Transfer State */
   E_LIBBSP_FNAND_CARD_STATE_DATA      = 5,  /* Sending data State */
   E_LIBBSP_FNAND_CARD_STATE_RCV       = 6,  /* Receive Data State */
   E_LIBBSP_FNAND_CARD_STATE_PRG       = 7,  /* Programming State */
   E_LIBBSP_FNAND_CARD_STATE_DIS       = 8,  /* Disconnect State */
   E_LIBBSP_FNAND_CARD_STATE_BTST      = 9,  /* Bus Test State */
   E_LIBBSP_FNAND_CARD_STATE_SLP       = 10  /* Sleep State */
}TE_LIBBSP_FNAND_CARD_STATE;

typedef union
{
   uint32_t R;
   struct
   {
      uint32_t ADDRESS_OUT_OF_RANGE :1;
      uint32_t ADDRESS_MISALIGN     :1;
      uint32_t BLOCK_LEN_ERROR      :1;
      uint32_t ERASE_SEQ_ERROR      :1;
      uint32_t ERASE_PARAM          :1;
      uint32_t WP_VIOLATION         :1;
      uint32_t CARD_IS_LOCKED       :1;
      uint32_t LOCK_UNLOCK_FAILED   :1;
      uint32_t COM_CRC_ERROR        :1;
      uint32_t ILLEGAL_COMMAND      :1;
      uint32_t CARD_ECC_FAILED      :1;
      uint32_t CC_ERROR             :1;
      uint32_t ERROR                :1;
      uint32_t UNDERRUN             :1;
      uint32_t OVERRUN              :1;
      uint32_t CID_CSD_OVERWRITE    :1;
      uint32_t WP_ERASE_SKIP        :1;
      uint32_t                      :1;
      uint32_t ERASE_RESET          :1;
      uint32_t CURRENT_STATE        :4;
      uint32_t READY_FOR_DATA       :1;
      uint32_t SWITCH_ERROR         :1;
      uint32_t URGENT_BKOPS         :1;
      uint32_t APP_CMD              :1;
      uint32_t                      :5;
   }B;
} TU_LIBBSP_FNAND_STATUSCARD;
/*=================================================================================================*/

/*==== Library definitions ========================================================================*/
typedef struct
{
   volatile uint32_t CMD;
   volatile uint32_t CMD_RSP[4];  /* Last response received */
   volatile uint32_t DATA_ADDR;   /* Transfer address */
   volatile uint32_t BLK_LEN;     /* Number of blocks to transfer */
} TS_LIBBSP_FNAND_OP;

typedef enum
{
   E_LIBBSP_FNAND_NO_TRAN,
   E_LIBBSP_FNAND_TRAN_IP,
   E_LIBBSP_FNAND_TRAN_FAILED
} TE_LIBBSP_LAST_TRAN;

typedef struct
{
   volatile boolean_t COMMAND;                 /* Command succeed */
   volatile TE_LIBBSP_LAST_TRAN TRANSFER;      /* Transfer Complete */
} TS_LIBBSP_FNAND_STATUS;

typedef enum
{
   E_LIBBSP_FNAND_NO_ERROR,
   E_LIBBSP_FNAND_ERROR_CMD,
   E_LIBBSP_FNAND_CMD_LINE_BUSY,
   E_LIBBSP_FNAND_DATA_LINE_BUSY,
   E_LIBBSP_FNAND_BAD_STATE,
   E_LIBBSP_FNAND_TIMEOUT_CMD,
   E_LIBBSP_FNAND_CARD_NOT_READY,
   E_LIBBSP_FNAND_INV_NBR_BLOCKS,
   E_LIBBSP_FNAND_CMD_REJECTED,
   E_LIBBSP_FNAND_ERROR_STOP
} TE_LIBBSP_FNAND_ERROR_OP;

typedef enum
{
   E_LIBBSP_FNAND_CID,
   E_LIBBSP_FNAND_CSD,
   E_LIBBSP_FNAND_EXTCSD
} TE_LIBBSP_FNAND_CONFIG_REG;

typedef enum
{
   E_LIBBSP_FNAND_BAD_BLOCKS,
   E_LIBBSP_FNAND_ERASE_COUNTERS
} TE_LIBBSP_FNAND_HEALTH_CMD;

typedef union
{
   uint32_t R[C_FNAND_CID_BUFFER_SIZE];
   struct
   {
      uint32_t MID   : 8;  /* Manufacturer ID */
      uint32_t       : 6;
      uint32_t CBX   : 2;  /* Card/BGA */
      uint32_t OID   : 8;  /* OEM/Application ID */
      uint8_t  PNM[6];     /* Product name */
      uint32_t PRV   : 8;  /* Product revision */
      uint32_t PSN   : 32; /* Product serial number */
      uint32_t MDT   : 8;  /* Manufacturing date */
      uint32_t CRC   : 7;  /* CRC7 checksum */
      uint32_t       : 1;
   } __attribute__((packed)) B;
} TU_LIBBSP_FNAND_CID_REG;

typedef union
{
   uint32_t R[C_FNAND_CSD_BUFFER_SIZE];
   struct
   {
      uint32_t CSD_STRUCTURE        : 2;  /* CSD structure */
      uint32_t SPEC_VERS            : 4;  /* System specification version */
      uint32_t TAAC                 : 8;  /* Data read access-time 1 */
      uint32_t NSAC                 : 8;  /* Data read access-time 2 in CLK cycles (NSAC*100) */
      uint32_t TRAN_SPEED           : 8;  /* Max. bus clock frequency */
      uint32_t CCC                  : 12; /* Card command classes */
      uint32_t READ_BL_LEN          : 4;  /* Max. read data block length */
      uint32_t READ_BL_PARTIAL      : 1;  /* Partial blocks for read allowed */
      uint32_t WRITE_BLK_MISALIGN   : 1;  /* Write block misalignment */
      uint32_t READ_BLK_MISALIGN    : 1;  /* Read block misalignment */
      uint32_t DSR_IMP              : 1;  /* DSR implemented */
      uint32_t                      : 2;
      uint32_t C_SIZE               : 12; /* Device size */
      uint32_t VDD_R_CURR_MIN       : 3;  /* Max. read current @ VDD min */
      uint32_t VDD_R_CURR_MAX       : 3;  /* Max. read current @ VDD max */
      uint32_t VDD_W_CURR_MIN       : 3;  /* Max. write current @ VDD min */
      uint32_t VDD_W_CURR_MAX       : 3;  /* Max. write current @ VDD max */
      uint32_t C_SIZE_MULT          : 3;  /* Device size multiplier */
      uint32_t ERASE_GRP_SIZE       : 5;  /* Erase group size */
      uint32_t ERASE_GRP_MULT       : 5;  /* Erase group size multiplier */
      uint32_t WP_GRP_SIZE          : 5;  /* Write protect group size */
      uint32_t WP_GRP_ENABLE        : 1;  /* Write protect group enable */
      uint32_t DEFAULT_ECC          : 2;  /* Manufacturer default ECC */
      uint32_t R2W_FACTOR           : 3;  /* Write speed factor */
      uint32_t WRITE_BL_LEN         : 4;  /* Max. write data block length */
      uint32_t WRITE_BL_PARTIAL     : 1;  /* Partial blocks for write allowed */
      uint32_t                      : 4;
      uint32_t CONTENT_PROT_APP     : 1;  /* Content protection application */
      uint32_t FILE_FORMAT_GRP      : 1;  /* File format group */
      uint32_t COPY                 : 1;  /* Copy flag (OTP) */
      uint32_t PERM_WRITE_PROTECT   : 1;  /* Permanent write protection */
      uint32_t TMP_WRITE_PROTECT    : 1;  /* Temporary write protection */
      uint32_t FILE_FORMAT          : 2;  /* File format */
      uint32_t ECC                  : 2;  /* ECC code */
      uint32_t CRC                  : 7;  /* CRC */
      uint32_t                      : 1;
   } __attribute__((packed)) B;
} TU_LIBBSP_FNAND_CSD_REG;

typedef union
{
   uint32_t R[C_FNAND_EXTCSD_BUFFER_SIZE];
   struct
   {
      /* Properties Segment */
      uint8_t RESERVED_1[7];
      uint8_t S_CMD_SET;                     /* Supported Command Sets */
      uint8_t HPI_FEATURES;                  /* HPI features */
      uint8_t BKOPS_SUPPORT;                 /* Background operations support */
      uint8_t RESERVED_2[255];
      uint8_t BKOPS_STATUS;                  /* Background operations status */
      uint32_t CORRECTLY_PRG_SECTORS_NUM;    /* Number of correctly programmed sectors */
      uint8_t INI_TIMEOUT_AP;                /* 1st initialization time after partitioning */
      uint8_t RESERVED_3[1];
      uint8_t PWR_CL_DDR_52_360;             /* Power class for 52MHz, DDR at 3.6V */
      uint8_t PWR_CL_DDR_52_195;             /* Power class for 52MHz, DDR at 1.95V */
      uint8_t RESERVED_4[2];
      uint8_t MIN_PERF_DDR_W_8_52;           /* Minimum Write Performance for 8bit at 52MHz in DDR mode */
      uint8_t MIN_PERF_DDR_R_8_52;           /* Minimum Read Performance for 8bit at 52MHz in DDR mode */
      uint8_t RESERVED_5[1];
      uint8_t TRIM_MULT;                     /* TRIM Multiplier */
      uint8_t SEC_FEATURE_SUPPORT;           /* Secure Feature support */
      uint8_t SEC_ERASE_MULT;                /* Secure Erase Multiplier */
      uint8_t SEC_TRIM_MULT;                 /* Secure TRIM Multiplier */
      uint8_t BOOT_INFO;                     /* Boot information */
      uint8_t RESERVED_6[1];
      uint8_t BOOT_SIZE_MULTI;               /* Boot partition size */
      uint8_t ACC_SIZE;                      /* Access size */
      uint8_t HC_ERASE_GRP_SIZE;             /* High-capacity erase unit size */
      uint8_t ERASE_TIMEOUT_MULT;            /* High-capacity erase timeout */
      uint8_t REL_WR_SEC_C;                  /* Reliable write sector count */
      uint8_t HC_WP_GRP_SIZE;                /* High-capacity write protect group size */
      uint8_t S_C_VCC;                       /* Sleep current (VCC) */
      uint8_t S_C_VCCQ;                      /* Sleep current (VCCQ) */
      uint8_t RESERVED_7[1];
      uint8_t S_A_TIMEOUT;                   /* Sleep/awake timeout */
      uint8_t RESERVED_8[1];
      uint32_t SEC_COUNT;                    /* Sector Count */
      uint8_t RESERVED_9[1];
      uint8_t MIN_PERF_W_8_52;               /* Minimum Write Performance for 8bit at 52MHz */
      uint8_t MIN_PERF_R_8_52;               /* Minimum Read Performance for 8bit at 52MHz */
      uint8_t MIN_PERF_W_8_26_4_52;          /* Minimum Write Performance for 8bit at 26MHz, for 4bit at 52MHz */
      uint8_t MIN_PERF_R_8_26_4_52;          /* Minimum Read Performance for 8bit at 26MHz, for 4bit at 52MHz */
      uint8_t MIN_PERF_W_4_26;               /* Minimum Write Performance for 4bit at 26MHz */
      uint8_t MIN_PERF_R_4_26;               /* Minimum Read Performance for 4bit at 26MHz */
      uint8_t RESERVED_A[1];
      uint8_t PWR_CL_26_360;                 /* Power class for 26MHz at 3.6V */
      uint8_t PWR_CL_52_360;                 /* Power class for 52MHz at 3.6V */
      uint8_t PWR_CL_26_195;                 /* Power class for 26MHz at 1.95V */
      uint8_t PWR_CL_52_195;                 /* Power class for 52MHz at 1.95V */
      uint8_t PARTITION_SWITCH_TIME;         /* Partition switching timing */
      uint8_t OUT_OF_INTERRUPT_TIME;         /* Out-of-interrupt busy timing */
      uint8_t RESERVED_B[1];
      uint8_t CARD_TYPE;                     /* Card type */
      uint8_t RESERVED_C[1];
      uint8_t CSD_STRUCTURE;                 /* CSD structure version */
      uint8_t RESERVED_D[1];
      uint8_t EXT_CSD_REV;                   /* Extended CSD revision */

      /* Modes Segment */
      uint8_t CMD_SET;                       /* Command set */
      uint8_t RESERVED_10[1];
      uint8_t CMD_SET_REV;                   /* Command set revision */
      uint8_t RESERVED_11[1];
      uint8_t POWER_CLASS;                   /* Power class */
      uint8_t RESERVED_12[1];
      uint8_t HS_TIMING;                     /* High-speed interface timing */
      uint8_t RESERVED_13[1];
      uint8_t BUS_WIDTH;                     /* Bus width mode */
      uint8_t RESERVED_14[1];
      uint8_t ERASED_MEM_CONT;               /* Erased memory content */
      uint8_t RESERVED_15[1];
      uint8_t PARTITION_CONFIG;              /* Partition configuration */
      uint8_t BOOT_CONFIG_PROT;              /* Boot config protection */
      uint8_t BOOT_BUS_WIDTH;                /* Boot bus width */
      uint8_t RESERVED_16[1];
      uint8_t ERASE_GROUP_DEF;               /* High-density erase group definition */
      uint8_t RESERVED_17[1];
      uint8_t BOOT_WP;                       /* Boot area write protection reg */
      uint8_t RESERVED_18[1];
      uint8_t USER_WP;                       /* User area write protection register */
      uint8_t RESERVED_19[1];
      uint8_t FW_CONFIG;                     /* FW configuration */
      uint8_t RPMB_SIZE_MULT;                /* RPMB Size */
      uint8_t WR_REL_SET;                    /* Write reliability setting register */
      uint8_t WR_REL_PARAM;                  /* Write reliability parameter register */
      uint8_t RESERVED_1A[1];
      uint8_t BKOPS_START;                   /* Manually start background operations */
      uint8_t BKOPS_EN;                      /* Enable background operations handshake */
      uint8_t RST_n_FUNCTION;                /* H/W reset function */
      uint8_t HPI_MGMT;                      /* HPI management */
      uint8_t PARTITIONING_SUPPORT;          /* Partitioning Support */
      uint32_t MAX_ENH_SIZE_MULT : 24;       /* Max Enhanced Area Size */
      uint8_t PARTITIONS_ATTRIBUTE;          /* Partitions attribute */
      uint8_t PARTITION_SETTING_COMPLETED;   /* Paritioning Setting */
      uint8_t GP_SIZE_MULT[12];              /* General Purpose Partition Size */
      uint32_t ENH_SIZE_MULT : 24;           /* Enhanced User Data Area Size */
      uint32_t ENH_START_ADDR;               /* Enhanced User Data Start Address */
      uint8_t RESERVED_1B[1];
      uint8_t SEC_BAD_BLK_MGMNT;             /* Bad Block Management mode */
      uint8_t RESERVED_1C[134];
   } __attribute__((packed)) B;
} TU_LIBBSP_FNAND_EXTCSD_REG;

/*==== Variables =======================================================================*/
extern volatile TS_LIBBSP_FNAND_STATUS* P_LIBBSP_FNAND_Status; /* Contain the actual status of the operations */
extern volatile TS_LIBBSP_FNAND_OP*     P_LIBBSP_FNAND_Op; /* Contain the last operation executed */

/*==== Services ========================================================================*/
extern boolean_t LIBBSP_FNAND_Configure(const boolean_t v_StartSequence);

extern void LIBBSP_FNAND_Init(void);

/* Utilities functions */
extern boolean_t LIBBSP_FNAND_UpdateStatus(void); /* Use to poll the memory status */
extern TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_GetStatus(TU_LIBBSP_FNAND_STATUSCARD * const v_CardStatus);
extern TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_SendConfig(const TE_LIBBSP_FNAND_CONFIG_REG v_ConfigReg, uint32_t * const p_Config);
extern TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_MemoryWearInfo(const TE_LIBBSP_FNAND_HEALTH_CMD v_HealthCmd, uint32_t * const p_WearStatus);

/* DMA transfers */
extern TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_Write(const uint32_t v_SectorAddr, const uint32_t * const p_Data, const uint32_t v_NbrBlock, const boolean_t v_Blocking);
extern TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_Read(const uint32_t v_SectorAddr, uint32_t * const p_Data, const uint32_t v_NbrBlock, const boolean_t v_Blocking);

/* No DMA transfers */
extern TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_Write_NoDMA(const uint32_t v_SectorAddr, const uint32_t * const p_Data, const uint32_t v_NbrBlock);
extern TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_Read_NoDMA(const uint32_t v_SectorAddr, uint32_t * const p_Data, const uint32_t v_NbrBlock);

/* Utilities functions for transfer operations */
extern TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_Erase(const uint32_t v_StartAddr, const uint32_t v_NbrBlock);
extern TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_StopTransmission(void);

/*==== END =============================================================================*/
#endif /* LIBBSP_FNAND_H */
