/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef CAN_REG_COMMON_H
#define CAN_REG_COMMON_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */
/* FIFO FULL */
#define CAN_FIFO_NOT_FULL       ((uint32_t)0)
#define CAN_FIFO_FULL           ((uint32_t)1)

/* Standard identifier element size */
#define CAN_STD_ID_SIZE         ((uint32_t)4)

/* Extended identifier element size */
#define CAN_XTD_ID_SIZE         ((uint32_t)8)

/* Maximum data size */
#define CAN_FRAME_DATA_SIZE_MAX ((uint32_t)8)

/* Max time to wait to take account the new mode */
#define CAN_TIME_TO_WAIT        ((int64_t)(20000))

/* Max number of iterations to take account the new mode */
#define CAN_OP_MODE_ITERATION   ((uint32_t)3)

/* XTD or STD mask */
#define CAN_FRAME_ID_t_MASK     ((uint32_t)0x00000001)
/* Frame type (data or remote) mask */
#define CAN_FRAME_t_MASK        ((uint32_t)0x00000004)
/* Bits [3:31] of Rx/Tx buffer element to get the id */
#define CAN_ID_MASK             ((uint32_t)0xFFFFFFF8)
/* */
#define CAN_FRAME_STD_ID_MASK   ((uint32_t)0x000007FF)
/* */
#define CAN_FRAME_XTD_ID_MASK   ((uint32_t)0x1FFFFFFF)

/* No use of message markers */
#define CAN_FRAME_MM_VAL        ((uint32_t)0x00)

/* No use of TX events */
#define CAN_FRAME_EFC_VAL       ((uint32_t)0)

/* Configure FIFO operation */
#define CAN_TQFM_SHIFT          ((uint32_t)30)

/* FIFO operation mask */
#define CAN_TQFM_MASK           ((uint32_t)0x1)

/* Configure TX buffer size */
#define CAN_TQFS_SHIFT          ((uint32_t)24)

/* TX buffer mask */
#define CAN_TQFS_MASK           ((uint32_t)0x3F)

/* Configure dedicated buffer size */
#define CAN_NDTB_SHIFT          ((uint32_t)16)

/* Dedicated buffer mask */
#define CAN_NDTB_MASK           ((uint32_t)0x3F)

/* NDTB value */
#define CAN_NDTB_VALUE          ((uint32_t)0)

/* TQFM value */
#define CAN_TQFM_VALUE          ((uint32_t)0)

/* TQFS value */
#define CAN_TQFS_VALUE          ((uint32_t)32)

/* TX buffer start address mask */
#define CAN_TBSA_MASK           ((uint32_t)0xFFFF)

/* Configure FIFO mode */
#define CAN_FOM_SHIFT           ((uint32_t)31)

/* FIFO mode mask */
#define CAN_FOM_MASK            ((uint32_t)0x1)

/* Configure dedicated buffer size */
#define CAN_FWM_SHIFT           ((uint32_t)24)

/* Dedicated buffer mask */
#define CAN_FWM_VALUE           ((uint32_t)0)

/* Configure FIFO size */
#define CAN_FOS_SHIFT           ((uint32_t)16)

/* FIFO size mask */
#define CAN_FOS_MASK            ((uint32_t)0x7F)

/* FIFO size mask */
#define CAN_FSA_MASK            ((uint32_t)0xFFFF)

/* FIFO size mask */
#define CAN_FIFO_ELT_OFF        ((uint32_t)4)
/* CAN bug */
/* Addresses between 0x2D00 and 0x2F00 cannot be used */

/* Maximum size in number bytes */
/* 1 FIFO element = 28 bytes because we use ts_CAN_FRAME_DESCR_t + 8 bytes to share data with upper layers */
#define CAN_FIFO_ELT_SIZE       ((uint32_t)16)
#define CAN_MAX_MSG_SIZE        (CAN_FRAME_SIZE)

/* reserved space definition */
/* Reserved from Address offset(hex) 30 to 40 */
#define CAN_RESERVED_1          ((uint32_t)4)
/* Reserved from Address offset(hex) 48 to 50 */
#define CAN_RESERVED_2          ((uint32_t)2)
/* Reserved from Address offset(hex) 60 to 80 */
#define CAN_RESERVED_3          ((uint32_t)8)
/* Reserved from Address offset(hex) E8 to F0 */
#define CAN_RESERVED_5          ((uint32_t)2)

/* ---------- provided types: ----------------------------------------------- */

/* Reserved refers to memory space unassigned in MPC577 for more information see */
/* "48.3.5 Memory map and register description" of MPC577 documentation          */
/* Unused refers to defined regster in the documentation but unused here         */

/* test register */
typedef struct
{
   reg32_t s_spare1 : 18;
   reg32_t s_tdcv   : 6;       /* transceiver delay compensation value */
   reg32_t s_rx     : 1;
   reg32_t s_tx     : 2;
   reg32_t s_lbck   : 1;
   reg32_t s_spare2 : 4;
}
ts_reg_test_bits_t;

typedef union
{
   reg32_t            u_reg;
   ts_reg_test_bits_t u_bit;
}
tu_reg_test_t;

/* ram watchdog register */
typedef struct
{
   reg32_t s_spare1 : 16;
   reg32_t s_wdv    : 8;
   reg32_t s_wdc    : 8;
}
ts_reg_rwd_bits_t;

typedef union
{
   reg32_t           u_reg;
   ts_reg_rwd_bits_t u_bit;
}
tu_reg_rwd_t;

/* cc control register */
typedef struct
{
   reg32_t s_spare1 : 16;
   reg32_t s_spare2 : 1;
   reg32_t s_txp    : 1;                 /* transmit pause */
   reg32_t s_fdbs   : 1;                /* can fd bit rate switching */
   reg32_t s_fdo    : 1;                 /* fast frame mode active */
   reg32_t s_cmr    : 2;                 /* can mode request */
   reg32_t s_cme    : 2;                 /* can mode enable */
   reg32_t s_test   : 1;
   reg32_t s_dar    : 1;
   reg32_t s_mon    : 1;
   reg32_t s_csr    : 1;
   reg32_t s_csa    : 1;
   reg32_t s_asm    : 1;
   reg32_t s_cce    : 1;
   reg32_t s_init   : 1;
}
ts_reg_cccr_bits_t;

typedef union
{
   reg32_t            u_reg;
   ts_reg_cccr_bits_t u_bit;
}
tu_reg_cccr_t;

/* bit timing and prescaler register */
typedef struct
{
   reg32_t s_spare1 : 6;
   reg32_t s_brp    : 10;                /* baud rate prescaler */
   reg32_t s_spare2 : 2;
   reg32_t s_tseg1  : 6;
   reg32_t s_tseg2  : 4;
   reg32_t s_sjw    : 4;
}
ts_reg_btp_bits_t;

typedef union
{
   reg32_t           u_reg;
   ts_reg_btp_bits_t u_bit;
}
tu_reg_btp_t;

/* timestamp counter configuration register */
typedef struct
{
   reg32_t s_spare1 : 12;
   reg32_t s_tcp    : 4;
   reg32_t s_spare2 : 14;
   reg32_t s_tss    : 2;
}
ts_reg_tscc_bits_t;

typedef union
{
   reg32_t            u_reg;
   ts_reg_tscc_bits_t u_bit;
}
tu_reg_tscc_t;

/* error counter register */
typedef struct
{
   reg32_t s_spare1 : 8;
   reg32_t s_cel    : 8;
   reg32_t s_rp     : 1;
   reg32_t s_rec    : 7;
   reg32_t s_tec    : 8;
}
ts_reg_ecr_bits_t;

typedef union
{
   reg32_t           u_reg;
   ts_reg_ecr_bits_t u_bit;
}
tu_reg_ecr_t;

/* interrupt register */
typedef struct
{
   reg32_t s_ste  : 1;
   reg32_t s_foe  : 1;
   reg32_t s_acke : 1;
   reg32_t s_be   : 1;
   reg32_t s_crce : 1;
   reg32_t s_wdi  : 1;
   reg32_t s_bo   : 1;
   reg32_t s_ew   : 1;
   reg32_t s_ep   : 1;
   reg32_t s_elo  : 1;
   reg32_t s_beu  : 1;
   reg32_t s_bec  : 1;
   reg32_t s_drx  : 1;                 /* message stored to dedicated rx buffer */
   reg32_t s_too  : 1;
   reg32_t s_mraf : 1;                /* message ram access failure */
   reg32_t s_tsw  : 1;
   reg32_t s_tefl : 1;
   reg32_t s_teff : 1;
   reg32_t s_tefw : 1;
   reg32_t s_tefn : 1;
   reg32_t s_tfe  : 1;
   reg32_t s_tcf  : 1;
   reg32_t s_tc   : 1;
   reg32_t s_hpm  : 1;
   reg32_t s_rf1l : 1;
   reg32_t s_rf1f : 1;
   reg32_t s_rf1w : 1;
   reg32_t s_rf1n : 1;
   reg32_t s_rf0l : 1;
   reg32_t s_rf0f : 1;
   reg32_t s_rf0w : 1;
   reg32_t s_rf0n : 1;
}
ts_reg_ir_bits_t;

typedef union
{
   reg32_t          u_reg;
   ts_reg_ir_bits_t u_bit;
}
tu_reg_ir_t;

/* global filter configuration register */
typedef struct
{
   reg32_t s_spare1 : 26;
   reg32_t s_anfs   : 2;
   reg32_t s_anfe   : 2;
   reg32_t s_rrfs   : 1;
   reg32_t s_rrfe   : 1;
}
ts_reg_gfc_bits_t;

typedef union
{
   reg32_t           u_reg;
   ts_reg_gfc_bits_t u_bit;
}
tu_reg_gfc_t;

/* standard id filter configuration register */
typedef struct
{
   reg32_t s_spare1 : 8;
   reg32_t s_lss    : 8;
   reg32_t s_flssa  : 16;
}
ts_reg_sidfc_bits_t;

typedef union
{
   reg32_t            u_reg;
   ts_reg_sidfc_bits_t u_bit;
}
tu_reg_sidfc_t;

/* extended id filter configuration register */
typedef struct
{
   reg32_t s_spare1 : 9;
   reg32_t s_lse    : 7;
   reg32_t s_flesa  : 16;
}
ts_reg_xidfc_bits_t;

typedef union
{
   reg32_t             u_reg;
   ts_reg_xidfc_bits_t u_bit;
}
tu_reg_xidfc_t;
/* extended id and mask register */
typedef struct
{
   reg32_t s_spare1 : 3;
   reg32_t s_eidm   : 29;
}
ts_reg_xidam_bits_t;

typedef union
{
   reg32_t             u_reg;
   ts_reg_xidam_bits_t u_bit;
}
tu_reg_xidam_t;

/* rx fifo 0 configuration */
typedef struct
{
   reg32_t s_f0om   : 1;                /* fifo 0 operation mode */
   reg32_t s_f0wm   : 7;
   reg32_t s_spare1 : 2;
   reg32_t s_f0s    : 6;
   reg32_t s_f0sa   : 16;
}
ts_reg_rxf0c_bits_t;

typedef union
{
   reg32_t             u_reg;
   ts_reg_rxf0c_bits_t u_bit;
}
tu_reg_rxf0c_t;

/* rx fifo 0 status register */
typedef struct
{
   reg32_t s_spare1 : 6;
   reg32_t s_rf0l   : 1;
   reg32_t s_f0f    : 1;
   reg32_t s_spare2 : 2;
   reg32_t s_f0pi   : 6;                /* rx fifo 0 put index */
   reg32_t s_spare3 : 2;
   reg32_t s_f0gi   : 6;
   reg32_t s_spare4 : 1;
   reg32_t s_f0fl   : 7;
}
ts_reg_rxf0s_bits_t;

typedef union
{
   reg32_t             u_reg;
   ts_reg_rxf0s_bits_t u_bit;
}
tu_reg_rxf0s_t;

/* rx fifo 0 acknowledge register */
typedef struct
{
   reg32_t s_spare1 : 26;
   reg32_t s_f0ai   : 6;
}
ts_reg_rxf0a_bits_t;

typedef union
{
   reg32_t             u_reg;
   ts_reg_rxf0a_bits_t u_bit;
}
tu_reg_rxf0a_t;

/* rx buffer configuration register */
typedef struct
{
   reg32_t s_spare1 : 16;
   reg32_t s_rbsa   : 16;  /* rx buffer start address */
}
ts_reg_rxbc_bits_t;

typedef union
{
   reg32_t            u_reg;
   ts_reg_rxbc_bits_t u_bit;
}
tu_reg_rxbc_t;

/* rx fifo 1 configuration register */
typedef struct
{
   reg32_t s_f1om   : 1;                /* fifo 1 operation mode */
   reg32_t s_f1wm   : 7;
   reg32_t s_spare1 : 1;
   reg32_t s_f1s    : 7;
   reg32_t s_f1sa   : 16;
}
ts_reg_rxf1c_bits_t;

typedef union
{
   reg32_t             u_reg;
   ts_reg_rxf1c_bits_t u_bit;
}
tu_reg_rxf1c_t;

/* rx fifo 1 status register */
typedef struct
{
   reg32_t s_dms    : 2;
   reg32_t s_spare1 : 4;
   reg32_t s_rf1l   : 1;
   reg32_t s_f1f    : 1;
   reg32_t s_spare2 : 2;
   reg32_t s_f1pi   : 6;                /* rx fifo 1 put index */
   reg32_t s_spare3 : 2;
   reg32_t s_f1g1   : 6;
   reg32_t s_spare4 : 1;
   reg32_t s_f1fl   : 7;
}
ts_reg_rxf1s_bits_t;

typedef union
{
   reg32_t             u_reg;
   ts_reg_rxf1s_bits_t u_bit;
}
tu_reg_rxf1s_t;

/* rx fifo 1 acknowledge register */
typedef struct
{
   reg32_t s_spare1 : 26;
   reg32_t s_f1ai   : 6;
}
ts_reg_rxf1a_bits_t;

typedef union
{
   reg32_t             u_reg;
   ts_reg_rxf1a_bits_t u_bit;
}
tu_reg_rxf1a_t;

/* rx buffer / fifo element size configuration register */
typedef struct
{
   reg32_t s_spare1 : 21;
   reg32_t s_rbds   : 3;                /* rx buffer data field size */
   reg32_t s_spare2 : 1;
   reg32_t s_f1ds   : 3;                /* rx fifo 1 data field size */
   reg32_t s_spare3 : 1;
   reg32_t s_f0ds   : 3;                /* rx fifo 0 data field size */
}
ts_reg_rxesc_bits_t;

typedef union
{
   reg32_t             u_reg;
   ts_reg_rxesc_bits_t u_bit;
}
tu_reg_rxesc_t;

/* tx buffer configuration register */
typedef struct
{
   reg32_t s_spare1 : 1;
   reg32_t s_tqfm   : 1;
   reg32_t s_tqfs   : 6;
   reg32_t s_spare2 : 2;
   reg32_t s_ndtb   : 6;
   reg32_t s_tbsa   : 16;
}
ts_reg_txbc_bits_t;

typedef union
{
   reg32_t            u_reg;
   ts_reg_txbc_bits_t u_bit;
}
tu_reg_txbc_t;

/* tx fifo/queue status register */
typedef struct
{
   reg32_t s_spare1 : 10;
   reg32_t s_tfqf   : 1;
   reg32_t s_tfqpi  : 5;
   reg32_t s_spare2 : 3;
   reg32_t s_tfgi   : 5;                /* tx fifo get index */
   reg32_t s_spare3 : 2;
   reg32_t s_tffl   : 6;
}
ts_reg_txfqs_bits_t;

typedef union
{
   reg32_t             u_reg;
   ts_reg_txfqs_bits_t u_bit;
}
tu_reg_txfqs_t;

/* tx buffer element size configuration */
typedef struct
{
   reg32_t s_spare1 : 29;
   reg32_t s_tbds   : 3;
}
ts_reg_txesc_bits_t;

typedef union
{
   reg32_t             u_reg;
   ts_reg_txesc_bits_t u_bit;
}
tu_reg_txesc_t;

/* tx buffer add request register */
typedef struct
{
   reg32_t s_ar : 32;                 /* add request */
}
ts_reg_txbar_bits_t;

typedef union
{
   reg32_t             u_reg;
   ts_reg_txbar_bits_t u_bit;
}
tu_reg_txbar_t;

typedef struct
{
   /* Core Release Register */
   reg32_t        s_m_can_crel_unused;
   /* Endian Register */
   reg32_t        s_m_can_endn_unused;
   /* Reserved from Address offset(hex) 8 to C */
   reg32_t        s_m_can_reserved0;
   /* fast bit timing and prescaler register */
   reg32_t        s_m_can_fbtp_unused;
   /* test register */
   tu_reg_test_t  s_test;
   /* ram watchdog register */
   tu_reg_rwd_t   s_rwd;
   /* cc control register */
   tu_reg_cccr_t  s_cccr;
   /* bit timing and prescaler register */
   tu_reg_btp_t   s_btp;
   /* timestamp counter configuration register */
   tu_reg_tscc_t  s_tscc;
   /* timestamp counter value register */
   reg32_t        s_m_can_tscv_unused;
   /* timeout counter configuration register */
   reg32_t        s_m_can_tocc_unused;
   /* timeout counter value register */
   reg32_t        s_m_can_tocv_unused;
   /* Reserved from Address offset(hex) 30 to 40 */
   reg32_t        s_m_can_reserved1[CAN_RESERVED_1];
   /* error counter register */
   tu_reg_ecr_t   s_ecr;
   /* protocol status register */
   reg32_t        s_m_can_psr_unused;
   /* Reserved from Address offset(hex) 48 to 50 */
   reg32_t        s_m_can_reserved2[CAN_RESERVED_2];
   /* interrupt register */
   tu_reg_ir_t    s_ir;
   /* interrupt enable register */
   reg32_t        s_m_can_ie_unused;
   /* interrupt line select register */
   reg32_t        s_m_can_ils_unused;
   /* interrupt line enable register */
   reg32_t        s_m_can_ile_unused;
   /* Reserved from Address offset(hex) 60 to 80 */
   reg32_t        s_m_can_reserved3[CAN_RESERVED_3];
   /* global filter configuration register */
   tu_reg_gfc_t   s_gfc;
   /* standard id filter configuration register */
   tu_reg_sidfc_t s_sidfc;
   /* extended id filter configuration register */
   tu_reg_xidfc_t s_xidfc;
   /* Reserved from Address offset(hex) 8C to 90 */
   reg32_t        s_m_can_reserved4;
   /* extended id and mask register */
   tu_reg_xidam_t s_xidam;
   /* high priority message status register */
   reg32_t        s_m_can_hpms_unused;
   /* new data 1 register */
   reg32_t        s_m_can_ndat1_unused;
   /* new data 2 register */
   reg32_t        s_m_can_ndat2_unused;
   /* rx fifo 0 configuration */
   tu_reg_rxf0c_t s_rxf0c;
   /* rx fifo 0 status register */
   tu_reg_rxf0s_t s_rxf0s;
   /* rx fifo 0 acknowledge register */
   tu_reg_rxf0a_t s_rxf0a;
   /* rx buffer configuration register */
   tu_reg_rxbc_t  s_rxbc;
   /* rx fifo 1 configuration register */
   tu_reg_rxf1c_t s_rxf1c;
   /* rx fifo 1 status register */
   tu_reg_rxf1s_t s_rxf1s;
   /* rx fifo 1 acknowledge register */
   tu_reg_rxf1a_t s_rxf1a;
   /* rx buffer / fifo element size configuration register */
   tu_reg_rxesc_t s_rxesc;
   /* tx buffer configuration register */
   tu_reg_txbc_t  s_txbc;
   /* tx fifo/queue status register */
   tu_reg_txfqs_t s_txfqs;
   /* tx buffer element size configuration */
   tu_reg_txesc_t s_txesc;
   /* tx buffer request pending register */
   reg32_t        s_m_can_txbrp_unused;
   /* tx buffer add request register */
   tu_reg_txbar_t s_txbar;
   /* tx buffer cancellation request register */
   reg32_t        s_m_can_txbcr_unused;
   /* tx buffer transmission occurred register */
   reg32_t        s_m_can_txbto_unused;
   /* tx buffer cancellation finished register */
   reg32_t        s_m_can_txbcf_unused;
   /* tx buffer transmission interrupt enable register */
   reg32_t        s_m_can_txbtie_unused;
   /* tx buffer cancellation finished interrupt enable register */
   reg32_t        s_m_can_txbcie_unused;
   /* Reserved from Address offset(hex) E8 to F0 */
   reg32_t        s_m_can_reserved5[CAN_RESERVED_5];
   /* tx event fifo configuration register */
   reg32_t        s_m_can_txefc_unused;
   /* tx event fifo status register */
   reg32_t        s_m_can_txefs_unused;
   /* tx event fifo acknowledge register */
   reg32_t        s_m_can_txefa_unused;
}
ts_can_reg_t;

/* standard filter element as defined in "48.3.6.4 Standard message ID Filter element" MPC577 documentation*/
typedef struct
{
   uint32_t  s_sft1   : 2;
   uint32_t  s_sfec   : 3;
   uint32_t  s_sfid1  : 11;
   uint32_t  s_spare1 : 5;
   uint32_t  s_sfid2  : 11;
}
ts_can_std_filt_elt_t;


typedef union
{
   uint32_t              u_word;
   ts_can_std_filt_elt_t u_bit;
}
tu_can_std_filt_elt_t;

/* extended filter element as defined in "48.3.6.5 Extended message ID filter element" MPC577 documentation*/

typedef struct
{
   uint32_t  s_efec  : 3;
   uint32_t  s_efid1 : 29;
}
ts_can_xtd_filt_elt_f0_t;

typedef union
{
   uint32_t                 u_word;
   ts_can_xtd_filt_elt_f0_t u_bit;
}
tu_can_xtd_filt_elt_f0_t;

typedef struct
{
   uint32_t  s_eft    : 2;
   uint32_t  s_spare1 : 1;
   uint32_t  s_efid2  : 29;
}
ts_can_xtd_filt_elt_f1_t;

typedef union
{
   uint32_t                 u_word;
   ts_can_xtd_filt_elt_f1_t u_bit;
}
tu_can_xtd_filt_elt_f1_t;

typedef struct
{
   tu_can_xtd_filt_elt_f0_t s_xtd_filt_elt_f0;
   tu_can_xtd_filt_elt_f1_t s_xtd_filt_elt_f1;
}
ts_can_xtd_filt_elt_t;


/* Tx buffer element as defined in "48.3.6.2 Tx buffer element" MPC577 documentation*/
/* buffer f0 */
typedef struct
{
   uint32_t  s_spare1 : 1;
   uint32_t  s_xtd    : 1;
   uint32_t  s_rtr    : 1;
   uint32_t  s_id     : 29;
}
ts_tx_buff_elt_f0_t;

typedef union
{
   uint32_t            u_word;
   ts_tx_buff_elt_f0_t u_bit;
}
tu_tx_buff_elt_f0_t;
/* buffer f1 */
typedef struct
{
   uint32_t  s_mm     : 8;
   uint32_t  s_efc    : 1;
   uint32_t  s_spare1 : 3;
   uint32_t  s_dlc    : 4;
   uint32_t  s_spare2 : 16;
}
ts_tx_buff_elt_f1_t;

typedef union
{
   uint32_t            u_word;
   ts_tx_buff_elt_f1_t u_bit;
}
tu_tx_buff_elt_f1_t;


typedef struct
{
   tu_tx_buff_elt_f0_t s_tx_buff_elt_f0;
   tu_tx_buff_elt_f1_t s_tx_buff_elt_f1;
   uint8_t             s_data[CAN_FRAME_DATA_SIZE_MAX];
}
ts_can_tx_buff_elt_t;

/* Rx buffer and FIFO element as defined in "48.3.6.1 Rx Buffer and FIFO element" MPC577 documentation*/
/* buffer r0 */
typedef struct
{
   uint32_t  s_esi : 1;
   uint32_t  s_xtd : 1;
   uint32_t  s_rtr : 1;
   uint32_t  s_id  : 29;
}
ts_rx_buff_elt_r0_t;

typedef union
{
   uint32_t            u_word;
   ts_rx_buff_elt_r0_t u_bit;
}
tu_rx_buff_elt_r0_t;

/* buffer r1 */
typedef struct
{
   uint32_t  s_anmf   : 1;
   uint32_t  s_fidx   : 7;
   uint32_t  s_spare1 : 2;
   uint32_t  s_edl    : 1;
   uint32_t  s_brs    : 1;
   uint32_t  s_dlc    : 4;
   uint32_t  s_rxts   : 16;
}
ts_rx_buff_elt_r1_t;

typedef union
{
   uint32_t            u_word;
   ts_rx_buff_elt_r1_t u_bit;
}
tu_rx_buff_elt_r1_t;

typedef struct
{
   tu_rx_buff_elt_r0_t s_rx_buff_elt_r0;
   tu_rx_buff_elt_r1_t s_rx_buff_elt_r1;
   uint8_t             s_data[CAN_FRAME_DATA_SIZE_MAX];
}
ts_can_rx_buff_elt_t;

/* time quantum registers */
typedef struct
{
   uint32_t   s_prop;
   uint32_t   s_phase1;
   uint32_t   s_phase2;
}
ts_can_tq_t;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */



#endif /* CAN_REG_COMMON_H */
