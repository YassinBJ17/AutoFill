/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef BOOT_FCCU_REG_PRIVATE_H
#define BOOT_FCCU_REG_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "CMN_TYPES_common.h"

/* ---------- Linker command file symbol: ----------------------------------- */
/* none */

/* ---------- provided define constants: ------------------------------------ */

/*****************************************************************************/
/*****              FCCU Registers Initialization Values                  ****/
/*****************************************************************************/
#define FCCU_BASE_ADDR           ((uint32_t) 0xFBF58000)
#define FCCU_RFK_KEY             ((uint32_t) 0xAB3498FE)
#define FCCU_RF_Sx_W1C           ((uint32_t) 0xFFFFFFFF)
#define FCCU_CTRL_OPS_SUCCESS    ((uint32_t) 0x3)
#define FCCU_TRANSLOCK_KEY       ((uint32_t) 0xBC)
#define FCCU_CTRLK_OP_1_KEY      ((uint32_t) 0x913756AF)
#define FCCU_CTRLK_OP_2_KEY      ((uint32_t) 0x825A132B)
#define FCCU_CTRL_OPR_OP1        ((uint32_t) 0x1)
#define FCCU_CTRL_OPR_OP2        ((uint32_t) 0x2)
#define FCCU_CTRL_OPR_OP3        ((uint32_t) 0x3)
#define FCCU_CTRL_OPR_OP10       ((uint32_t) 0xA)
#define FCCU_STAT_NORMAL_STATE   ((uint32_t) 0x0)

/*
 * All available 56 faults recovered by SW
 */
#define FCCU_RF_CFG0_INIT_VAL    ((uint32_t) 0xFFFFFFFF)
#define FCCU_RF_CFG1_INIT_VAL    ((uint32_t) 0x00BFFFFF)

/*
 * For all fault, configure the FCCU to reset for defined critical errors
 */
#define FCCU_RFS_CFG0_INIT_VAL   ((uint32_t) 0xFFFFFFFF)
#define FCCU_RFS_CFG1_INIT_VAL   ((uint32_t) 0xFFFFFFFF)
#define FCCU_RFS_CFG2_INIT_VAL   ((uint32_t) 0xFFFFFFFF)
#define FCCU_RFS_CFG3_INIT_VAL   ((uint32_t) 0xFFFFFFFF)

/*
 * For defined critical fault, move to ALARM or FAULT state in case of critical errors
 *
 * Note:
 * - error 51 occurs when trying to debug in trace32 while core0
 * and core checker are running. No break is possible. Real time execution
 * is required.
 */
#define FCCU_RF_E0_INIT_VAL      ((uint32_t) 0x03B60300)
#define FCCU_RF_E1_INIT_VAL      ((uint32_t) 0x002029F8)

/* Activate the ALARM state for critical faults only */
#define FCCU_RF_TOE0_INIT_VAL    ((uint32_t) 0x03B60300)
#define FCCU_RF_TOE1_INIT_VAL    ((uint32_t) 0x002029F8)

/* Initialization value of the ALARM time-out */
#define FCCU_RF_TO_INIT_VAL      ((uint32_t) 0x640)

/* Generate an alarm IRQ for defined critical faults */
#define FCCU_IRQ_ALARM_EN0_INIT_VAL ((uint32_t) 0x03B60300)
#define FCCU_IRQ_ALARM_EN1_INIT_VAL ((uint32_t) 0x002029F8)

#define FCCU_REG_SIZE (4)
#define FCCU_REF_RFS_CFG_SIZE (8)
#define FCCU_REG_RESERVED0_SIZE (16)
#define FCCU_REG_RESERVED1_SIZE (32)
#define FCCU_REG_RESERVED2_SIZE (20)
#define FCCU_REG_RESERVED3_SIZE (8)

/* ---------- provided types: ----------------------------------------------- */

/* ============================================================================
   =============================== Module: FCCU ===============================
   ============================================================================ */

typedef struct
{
   reg32_t s_FILTER_BYPASS:1;
   reg32_t s_FILTER_WIDTH:2;
   reg32_t  :19;
   reg32_t s_DEBUG:1;
   reg32_t  :1;
   reg32_t s_OPS:2;
   reg32_t  :1;
   reg32_t s_OPR:5;
}
ts_CTRL_field;

typedef union
{                              /* Control Register */
   reg32_t u_CTRL_reg;
   ts_CTRL_field u_CTRL_field;
}
tu_CTRL;

typedef struct
{
   reg32_t  :26;
   reg32_t s_PhysicErrorPin:2;
   reg32_t s_ESTAT:1;
   reg32_t s_STATUS:3;
}
ts_STAT;

typedef struct
{
   reg32_t  :23;
   reg32_t s_TRANSKEY:9;
}
ts_TRANS_LOCK;


typedef struct
{
   /* Control Register */
   tu_CTRL s_CTRL;

   /* CTRL Key Register */
   reg32_t s_CTRLK;
   
   /* Configuration Register */
   reg32_t s_CFG;
   
   uint8_t s_FCCU_reserved0[FCCU_REG_RESERVED0_SIZE];
   /* RF Configuration Register */
   reg32_t s_RF_CFG[FCCU_REG_SIZE];
   
   uint8_t s_FCCU_reserved1[FCCU_REG_RESERVED1_SIZE];
   /* RFS Configuration Register */
   reg32_t s_RFS_CFG[FCCU_REF_RFS_CFG_SIZE];
   
   uint8_t s_FCCU_reserved2[FCCU_REG_RESERVED2_SIZE];
   /* UF Status Register */
   reg32_t s_RF_S[FCCU_REG_SIZE];
   
   /* RF Key Register */
   reg32_t s_RFK;
   
   /* RF Enable Register */
   reg32_t s_RF_E[FCCU_REG_SIZE];
   
   /* RF Time-out Enable Register */
   reg32_t s_RF_TOE[FCCU_REG_SIZE];
   
   /* RF Time-out Register */
   reg32_t s_RF_TO;
   
   /* CFG Timeout Register */
   reg32_t s_CFG_TO;
   
   /* IO Control Register */
   reg32_t s_EINOUT;
   
   ts_STAT s_STAT;

   /* NA Freeze Status Register */
   reg32_t s_N2AF_STATUS;
   
   /* AF Freeze Status Register */
   reg32_t s_A2FF_STATUS;
   
   /* NF Freeze Status Register */
   reg32_t s_N2FF_STATUS;
   
   /* FA Freeze Status Register */
   reg32_t s_F2A_STATUS;
   
   uint8_t s_FCCU_reserved3[FCCU_REG_RESERVED3_SIZE];
   /* RF Fake Register */
   reg32_t s_RFF;
   
   /* IRQ Status Register */
   reg32_t s_IRQ_STAT;
   
   /* IRQ Enable Register */
   reg32_t s_IRQ_EN;
   
   /* XTMR Register */
   reg32_t s_XTMR;
   
   /* MCS Register */
   reg32_t s_MCS;
   
   /* Transient Lock Register */
   ts_TRANS_LOCK s_TRANS_LOCK;
   
   /* Permanent Lock Register */
   reg32_t s_PERMNT_LOCK;
   
   /* Delta T Register */
   reg32_t s_DELTA_T;
   
   /* IRQ Alarm Enable Register */
   reg32_t s_IRQ_ALARM_EN[FCCU_REG_SIZE];
   
   /* NMI Enable Register */
   reg32_t s_NMI_EN[FCCU_REG_SIZE];
   
   /* EOUT Signaling Enable Register */
   reg32_t s_EOUT_SIG_EN[FCCU_REG_SIZE];
}
ts_FCCU_tag;

/* FCCU */
#define FCCU (*(ts_FCCU_tag volatile *) FCCU_BASE_ADDR)

#define FCCU_CTRL                   FCCU.s_CTRL.u_CTRL_reg                         /* Control Register */
#define FCCU_CTRL_OPS               FCCU.s_CTRL.u_CTRL_field.s_OPS                   /* OPS field of Control Register */
#define FCCU_CTRLK                  FCCU.s_CTRLK                                 /* CTRL Key Register */
#define FCCU_RF_CFG0                FCCU.s_RF_CFG[0]                             /* RF Configuration Register */
#define FCCU_RF_CFG1                FCCU.s_RF_CFG[1]                             /* RF Configuration Register */
#define FCCU_RFS_CFG0               FCCU.s_RFS_CFG[0]                            /* RFS Configuration Register */
#define FCCU_RFS_CFG1               FCCU.s_RFS_CFG[1]                            /* RFS Configuration Register */
#define FCCU_RFS_CFG2               FCCU.s_RFS_CFG[2]                            /* RFS Configuration Register */
#define FCCU_RFS_CFG3               FCCU.s_RFS_CFG[3]                            /* RFS Configuration Register */
#define FCCU_RF_S0                  FCCU.s_RF_S[0]                               /* UF Status Register */
#define FCCU_RF_S1                  FCCU.s_RF_S[1]                               /* UF Status Register */
#define FCCU_RF_S2                  FCCU.s_RF_S[2]                               /* UF Status Register */
#define FCCU_RFK                    FCCU.s_RFK                                   /* RF Key Register */
#define FCCU_RF_E0                  FCCU.s_RF_E[0]                               /* RF Enable Register */
#define FCCU_RF_E1                  FCCU.s_RF_E[1]                               /* RF Enable Register */
#define FCCU_RF_TOE0                FCCU.s_RF_TOE[0]                             /* RF Time-out Enable Register */
#define FCCU_RF_TOE1                FCCU.s_RF_TOE[1]                             /* RF Time-out Enable Register */
#define FCCU_RF_TO                  FCCU.s_RF_TO                                 /* RF Time-out Register */
#define FCCU_RFF                    FCCU.s_RFF                                   /* RF Fake Register */
#define FCCU_IRQ_ALARM_EN0          FCCU.s_IRQ_ALARM_EN[0]                       /* IRQ Alarm Enable Register */
#define FCCU_IRQ_ALARM_EN1          FCCU.s_IRQ_ALARM_EN[1]                       /* IRQ Alarm Enable Register */
#define FCCU_STAT_STATUS            FCCU.s_STAT.s_STATUS                /* STATUS field of Status Register */
#define FCCU_TRANS_LOCK_TRANSKEY    FCCU.s_TRANS_LOCK.s_TRANSKEY  /* Transkey field */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- provided operations: ------------------------------------------ */
/* none */


#endif /* BOOT_FCCU_REG_PRIVATE_H */

