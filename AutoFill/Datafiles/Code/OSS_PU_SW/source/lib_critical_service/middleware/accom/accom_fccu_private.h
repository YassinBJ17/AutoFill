/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef ACCOM_FCCU_PRIVATE_H
#define ACCOM_FCCU_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* Register used to declare ACCOM faults in the FCCU */
#define ACCOM_FCCU_FAULT_BIT_MASK ((uint32_t) 0x400000)

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
#define FCCU_RFS_CFG0_INIT_VAL   ((uint32_t) 0xFFEAFFFF)
#define FCCU_RFS_CFG1_INIT_VAL   ((uint32_t) 0xFFFABAEB)
#define FCCU_RFS_CFG2_INIT_VAL   ((uint32_t) 0xFBBEAABF)
#define FCCU_RFS_CFG3_INIT_VAL   ((uint32_t) 0x0000FBFF)

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
   reg32_t s_spare_00_to_06  : 7; /* 00 to 06 : Reserved */
   reg32_t s_set_after_reset : 1; /* 07 : FCCU_SET_AFTER_RESET : This bit controls the enable of the o/p error pin after reset lifts. After power-on the error out pins shall be in high impedance */
   reg32_t s_set_clear       : 2; /* 08-09 : FCCU_SET_CLEAR : Error pin state can be controlled by these bits. These bits clear(0) and set(1) the error pin. Higher priority is of the FCCU_SET_AFTER_RESET bit's capability to lead the error pins to Hi-Z. (With '0b00', FCCU acts independent of above SW control) */
   reg32_t s_spare_10_to_18  : 9; /* 10 to 18 : Reserved */
   reg32_t s_od              : 1; /* 19 : Open Drain : Mechanism to select between Push-pull and Open drain mode for the error indicating pin. ('0b0' = push-pull) */
   reg32_t s_spare_20        : 1; /* 20 : Reserved */
   reg32_t s_sm              : 1; /* 21 : Switching mode (won't be used) */
   reg32_t s_ps              : 1; /* 22 : Polarity Selection : defines the polarity of the EOUT output (on ps=='0b0', EOUT[1] is active high, EOUT[0] is active low ; on ps=='0b1', EOUT[1] is active low, EOUT[0] is active high) */
   reg32_t s_fom             : 3; /* 23 to 25 : Fault Output Mode : switch the mode of the FCCU fault output (0b010 is for the Bi-stable mode) */
   reg32_t s_spare_26_to_31  : 6; /* 26 to 31 : Reserved */
}
ts_accom_fccu_cfg;

typedef union
{
   ts_accom_fccu_cfg u_field;
   reg32_t u_word;
}
tu_accom_fccu_cfg;

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
   tu_CTRL s_CTRL;                        /* Control Register */
   reg32_t s_CTRLK;                       /* CTRL Key Register */
   tu_accom_fccu_cfg s_CFG;               /* Configuration Register */
   uint8_t s_FCCU_reserved0[FCCU_REG_RESERVED0_SIZE];
   reg32_t s_RF_CFG[FCCU_REG_SIZE];       /* RF Configuration Register */
   uint8_t s_FCCU_reserved1[FCCU_REG_RESERVED1_SIZE];
   reg32_t s_RFS_CFG[FCCU_REF_RFS_CFG_SIZE]; /* RFS Configuration Register */
   uint8_t s_FCCU_reserved2[FCCU_REG_RESERVED2_SIZE];
   reg32_t s_RF_S[FCCU_REG_SIZE];         /* UF Status Register */
   reg32_t s_RFK;                         /* RF Key Register */
   reg32_t s_RF_E[FCCU_REG_SIZE];         /* RF Enable Register */
   reg32_t s_RF_TOE[FCCU_REG_SIZE];       /* RF Time-out Enable Register */
   reg32_t s_RF_TO;                       /* RF Time-out Register */
   reg32_t s_CFG_TO;                      /* CFG Timeout Register */
   reg32_t s_EINOUT;                      /* IO Control Register */
   ts_STAT s_STAT;
   reg32_t s_N2AF_STATUS;                 /* NA Freeze Status Register */
   reg32_t s_A2FF_STATUS;                 /* AF Freeze Status Register */
   reg32_t s_N2FF_STATUS;                 /* NF Freeze Status Register */
   reg32_t s_F2A_STATUS;                  /* FA Freeze Status Register */
   uint8_t s_FCCU_reserved3[FCCU_REG_RESERVED3_SIZE];
   reg32_t s_RFF;                         /* RF Fake Register */
   reg32_t s_IRQ_STAT;                    /* IRQ Status Register */
   reg32_t s_IRQ_EN;                      /* IRQ Enable Register */
   reg32_t s_XTMR;                        /* XTMR Register */
   reg32_t s_MCS;                         /* MCS Register */
   ts_TRANS_LOCK s_TRANS_LOCK;            /* Transient Lock Register */
   reg32_t s_PERMNT_LOCK;                 /* Permanent Lock Register */
   reg32_t s_DELTA_T;                     /* Delta T Register */
   reg32_t s_IRQ_ALARM_EN[FCCU_REG_SIZE]; /* IRQ Alarm Enable Register */
   reg32_t s_NMI_EN[FCCU_REG_SIZE];       /* NMI Enable Register */
   reg32_t s_EOUT_SIG_EN[FCCU_REG_SIZE];  /* EOUT Signaling Enable Register */
}
ts_accom_FCCU_tag;

/* FCCU */
#define FCCU (*(ts_accom_FCCU_tag volatile *) FCCU_BASE_ADDR)

#define FCCU_CTRL                   FCCU.s_CTRL.u_CTRL_reg                 /* Control Register */
#define FCCU_CTRL_OPS               FCCU.s_CTRL.u_CTRL_field.s_OPS         /* OPS field of Control Register */
#define FCCU_CTRLK                  FCCU.s_CTRLK                           /* CTRL Key Register */
#define FCCU_CFG                    FCCU.s_CFG                             /* Configuration Register */
#define FCCU_RF_CFG0                FCCU.s_RF_CFG[0]                       /* RF Configuration Register */
#define FCCU_RF_CFG1                FCCU.s_RF_CFG[1]                       /* RF Configuration Register */
#define FCCU_RFS_CFG0               FCCU.s_RFS_CFG[0]                      /* RFS Configuration Register */
#define FCCU_RFS_CFG1               FCCU.s_RFS_CFG[1]                      /* RFS Configuration Register */
#define FCCU_RFS_CFG2               FCCU.s_RFS_CFG[2]                      /* RFS Configuration Register */
#define FCCU_RFS_CFG3               FCCU.s_RFS_CFG[3]                      /* RFS Configuration Register */
#define FCCU_RF_S0                  FCCU.s_RF_S[0]                         /* UF Status Register */
#define FCCU_RF_S1                  FCCU.s_RF_S[1]                         /* UF Status Register */
#define FCCU_RF_S2                  FCCU.s_RF_S[2]                         /* UF Status Register */
#define FCCU_RFK                    FCCU.s_RFK                             /* RF Key Register */
#define FCCU_RF_E0                  FCCU.s_RF_E[0]                         /* RF Enable Register */
#define FCCU_RF_E1                  FCCU.s_RF_E[1]                         /* RF Enable Register */
#define FCCU_RF_TOE0                FCCU.s_RF_TOE[0]                       /* RF Time-out Enable Register */
#define FCCU_RF_TOE1                FCCU.s_RF_TOE[1]                       /* RF Time-out Enable Register */
#define FCCU_RF_TO                  FCCU.s_RF_TO                           /* RF Time-out Register */
#define FCCU_RFF                    FCCU.s_RFF                             /* RF Fake Register */
#define FCCU_IRQ_ALARM_EN0          FCCU.s_IRQ_ALARM_EN[0]                 /* IRQ Alarm Enable Register */
#define FCCU_IRQ_ALARM_EN1          FCCU.s_IRQ_ALARM_EN[1]                 /* IRQ Alarm Enable Register */
#define FCCU_STAT_STATUS            FCCU.s_STAT.s_STATUS                   /* STATUS field of Status Register */
#define FCCU_TRANS_LOCK_TRANSKEY    FCCU.s_TRANS_LOCK.s_TRANSKEY           /* Transkey field */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

/**
 * Function to allow a transition from the NORMAL to the CONFIG state of the
 *   FCCU.
 */
extern void accom_fccu_cfg_unlock(void);

/**
 * Function to set the FCCU back to NORMAL mode, leaving the CONFIG state.
 */
extern void accom_fccu_cfg_validate(void);

/**
 * Function to set the FCCU in failure state.
 */
extern void accom_fccu_failure_set(void);

/* Implements REQ_FADEX_OS_SRD-RESET-0010 */
/**
 * Function to initialize the FCCU in Bi-stable mode.
 */
void accom_fccu_init(void);

#endif /* ACCOM_FCCU_PRIVATE_H */

