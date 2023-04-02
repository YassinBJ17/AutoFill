/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef CAN_CRITICAL_PRIVATE_H
#define CAN_CRITICAL_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "driver/can/can_reg_common.h"
#include "memory/shared_memory_public.h"
#include "driver/can/can_critical_public.h"

/* ---------- provided define constants: ------------------------------------ */
#define CAN_FRAME_SIZE               ((uint32_t)(sizeof(ts_can_frame_descr_t)+8))

/* Number of ID managed */
#define CAN_CFG_ID_MAX_NB            ((uint32_t)64)

/* Timestamp is equal to 5 * CAN bit time, so CAN counter resolution is equal to 10micro-s for CAN speed at 500 kbits/s */
/* TCP register value adds 1 */
#define CAN_CFEX_TIMESTAMP_VALUE     ((uint32_t)0)

/* Timestamp Select */
#define CAN_CFEX_TIMESTAMP_SEL_VALUE ((uint32_t)0)

/* Accept Non-matching Frames */
/* Reject all frames */
#define CAN_CFEX_NMF_POLICY_VALUE    ((uint32_t)0x2)

/* Reject all remote frames */
#define CAN_CFEX_RRF_POLICY_VALUE    ((uint32_t)0x1)

/* CAN Mode Request */
#define CAN_CFEX_CMR_POLICY_VALUE    ((uint32_t)0x3)

/* CAN Mode Enable */
#define CAN_CFEX_CME_POLICY_VALUE    ((uint32_t)0x0)

/* Time quantum phase 1, register adds 1 */
#define CAN_CFEX_TQ_PHASE1_VALUE     ((uint32_t)5)

/* Time quantum phase 2, register adds 1 */
#define CAN_CFEX_TQ_PHASE2_VALUE     ((uint32_t)6)

/* Time quantum propagation, register adds 1 */
#define CAN_CFEX_TQ_PROP_VALUE       ((uint32_t)6)

/* Time quantum SJW, register adds 1 */
#define CAN_CFEX_TQ_SJW_VALUE        ((uint32_t)5)

/* Baudrate prescalar, register adds 1 */
#define CAN_CFEX_BRP_125KBITSPS      ((uint32_t)31)
#define CAN_CFEX_BRP_250KBITSPS      ((uint32_t)15)
#define CAN_CFEX_BRP_500KBITSPS      ((uint32_t)7)
#define CAN_CFEX_BRP_1000KBITSPS     ((uint32_t)3)

/* Max number of standards identifiers per CAN */
#define CAN_CFEX_CAN_STD_ID_MAX_NB   ((uint32_t)64)
#define CAN_CFEX_CAN_XTD_ID_MAX_NB   ((uint32_t)64)

/* Maximum data size in CAN frame */
#define CAN_FRAME_DATA_SIZE          ((uint32_t)8)

/* Maximum number of frames */
#define CAN_FRAME_MAX_NB             ((uint32_t)32)

/* Adress for CAN register  */
#define CAN_TT_CAN_BASE_ADDR         ((uint32_t)0xFFEDC000)  /* CAN registers use CAN TT address */
#define CAN1_REG_ADDR                ((uint32_t)0xFFEE4000)
#define CAN2_REG_ADDR                ((uint32_t)0xFFEE8000)
#define CAN3_REG_ADDR                ((uint32_t)0xFFEEC000)
#define CAN4_REG_ADDR                ((uint32_t)0xFFEF0000)
#define CAN_CAN_OFF                  ((uint32_t)0x4000)  /* CAN offset */

#define CAN1_RAM_ADDR                ((uint32_t)0xFFED4000)  /* CAN 1 RAM start address */
#define CAN2_RAM_ADDR                ((uint32_t)0xFFED5000)  /* CAN 2 RAM start address */
#define CAN3_RAM_ADDR                ((uint32_t)0xFFED6000)  /* CAN 3 RAM start address */
#define CAN4_RAM_ADDR                ((uint32_t)0xFFED7000)  /* CAN 4 RAM start address */
#define CAN_CAN_RAM_OFF              ((uint32_t)0x1000)  /* CAN RAM offset */

#define CAN_RX_FIFO_F0_ELT_MAX       ((uint32_t)64)
#define CAN_RX_FIFO_F1_ELT_MAX       ((uint32_t)0)
#define CAN_TX_FIFO_F0_ELT_MAX       ((uint32_t)32)

#define CAN_STD_FILT_CAN_OFF         ((uint32_t)0x0000)  /* 128 standards filters max for CAN1 */
#define CAN_XTD_FILT_CAN_OFF         ((uint32_t)0x0200)  /* 64 extended filters max for CAN1 */
/* 64 reception buffer elements max for CAN1, each buffer element is 16 bytes (header + 8 data bytes) */
#define CAN_RX_FIFO_0_CAN_OFF        ((uint32_t)0x0400)
/* 64 reception buffer elements max for CAN1, each buffer element is 16 bytes (header + 8 data bytes) */
#define CAN_RX_FIFO_1_CAN_OFF        ((uint32_t)0x0800)
/* 32 transmission buffer elements max for CAN1, each buffer element is 16 bytes (header + 8 data bytes)*/
#define CAN_TX_CAN_OFF               ((uint32_t)0x0C00)

#define CAN_F0M_VALUE                ((uint32_t)0)

/* Status */
#define CAN_FIFO_VALID               ((uint32_t)0)
#define CAN_FIFO_INVALID             ((uint32_t)1)

#define CAN_FRAME_VALID              ((uint32_t)0)
#define CAN_FRAME_INVALID            ((uint32_t)1)

#define CAN_CRC_VALID                ((uint32_t)0)
#define CAN_CRC_INVALID              ((uint32_t)1)

#define CAN_ACK_VALID                ((uint32_t)0)
#define CAN_ACK_INVALID              ((uint32_t)1)

#define CAN_NOT_BUSY                 ((uint32_t)0)
#define CAN_BUSY                     ((uint32_t)1)

#define CAN_STATUS_VALID             ((uint32_t)0)
#define CAN_STATUS_INVALID           ((uint32_t)1)

#define CAN_FIFO_0                   ((uint32_t)1)
#define CAN_FIFO_1                   ((uint32_t)2)
/* endianess swap */

#define SWAP_MASK_VERY_LOW_SIGN_BIT  ((uint32_t)0x000000ff)
#define SWAP_MASK_LOW_SIGN_BIT       ((uint32_t)0x0000ff00)
#define SWAP_MASK_HIGH_SIGN_BIT      ((uint32_t)0x00ff0000)
#define SWAP_MASK_VERY_HIGH_SIGN_BIT ((uint32_t)0xff000000)

#define SWAP_SHIFT_24_BIT            ((uint32_t)24)
#define SWAP_SHIFT_8_BIT             ((uint32_t)8)

#define SWAP_FRAME_DATA_IT_MAX       ((uint32_t)2)

#define STD_TX_FRAME_IDENTIFIER_TYPE ((uint32_t)0)
#define XTD_TX_FRAME_IDENTIFIER_TYPE ((uint32_t)1)

#define RTR_TX_DATA_FRAME            ((uint32_t)0)
#define RTR_TX_REMOTE_FRAME          ((uint32_t)1)

#define CAN_STD_ID_SHIFT             ((uint32_t) 18)

#define GPIO_216                     ((uint8_t*) 0xFFFC13D8)

#define CAN_OFFSET   ((uint32_t) 0x00000380)

/* ---------- provided types: ----------------------------------------------- */
/* */

typedef enum
{
   e_can_cfex_fifo_0 = 1,
   e_can_cfex_fifo_1 = 2
}
te_can_fifo_rec_t;

typedef enum
{
   e_can_baudrate_veryslow  = 0, /*  125 Kbit/s */
   e_can_baudrate_slow      = 1, /*  250 Kbit/s */
   e_can_baudrate_fast      = 2, /*  500 Kbit/s */
   e_can_baudrate_very_fast = 3  /* 1000 Kbit/s */
}
te_can_baudrate_t;

typedef enum
{
   e_can_adapt_res_is_disconnected = 1,  /* the 120 ohm resistor is disconnected */
   e_can_adapt_res_is_connected    = 0   /* the 120 ohm resistor is connected    */
}
te_can_adapt_pres_t;

typedef enum
{
   e_can_02_a = 0,  /* 0 = CAN 2.0A (11 bits identifier) */
   e_can_02_b = 1   /* 1 = CAN 2.0B (29 bits identifier) */
}
te_can_02b_auth_t;




/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ----------------------------------------------- */

/* ---------- provided operations: ------------------------------------------ */



/* ----------------------------------------------------------------------------------------------------- */
/* Function to set the ID filters for CAN received frames  */
extern void can_configure(uint32_t const can_ram_addr,
                          ts_can_conf const * const ptr_can_conf,
                          ts_can_configure* const ptr_shmem_can_configure);

/* ----------------------------------------------------------------------------------------------------- */


/* ----------------------------------------------------------------------------------------------------- */
/* Function to write and send Tx frames with CAN from shared mem  */
extern void can_write( ts_can_tx* const ptr_src_shmem_can,
                uint32_t const dest_can_ram_addr,
                uint32_t const can_x_reg_addr,
                ts_can_conf const * const ptr_can_conf);

/* Function to retriev the index of Tx buffers */
extern void can_write_get_fifo_tx_lvl(uint32_t const can_x_reg_addr,
                                      uint32_t * const p_fifo_lvl,
                                      uint32_t * const p_fifo_elt_offset,
                                      uint32_t * const fifo_overflow);

/* Function to check status word and set the invalid fault state */
extern void can_write_put_msg_to_can_ram(ts_can_tx* const ptr_src_shmem_can,
                                         uint32_t const dest_can_ram_addr,
                                         ts_can_conf const * const ptr_can_conf,
                                         uint32_t const id_elt_to_send,
                                         uint32_t const fifo_elt_offset);

/* Function to start sending the frames */
extern void can_write_start_tx(uint32_t    const can_x_reg_addr,
                               uint32_t    const fifo_elt_offset);

/* ----------------------------------------------------------------------------------------------------- */
/* Function to swap endianess of data */
extern void swap_data(const uint8_t * p_data_src_addr,
                          const uint8_t * p_data_swap_addr);

/* Function to check status word and set the invalid fault state */
extern void can_is_status_invalid(uint32_t * const p_u_R_status);

extern void can_write_check_tx_status(uint32_t const can_x_reg_addr, ts_can_tx* const ptr_src_shmem_can);

extern void can_read_check_rx_status(uint32_t  const can_x_reg_addr, ts_can_rx* ptr_dest_shmem_can);

extern void can_read_filter_frames_by_id(ts_can_frame * const can_frame_rx_tab,
                                  ts_can_rx* const ptr_dest_shmem_can,
                                  uint32_t  const nb_read_data,
                                  uint32_t  *  const rx_count);


#endif /* CAN_CRITICAL_PRIVATE_H */
