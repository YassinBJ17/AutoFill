/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef CAN_PRIVATE_H
#define CAN_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "driver/can/can_critical_public.h"
#include "memory/shared_memory_public.h"
#include "driver/can/can_critical_private.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Function to conpute time quantum and set the baudrate  */
extern void can_init_baudrate(uint32_t const can_x_reg_addr, ts_can_conf const * const ptr_can_conf);

/* Function to initialize the Tx buffers  */
extern void can_init_buff_tx(uint32_t const can_x_reg_addr,
                             uint32_t const can_ram_start_addr);

/* Function to initialize the Rx buffers  */
extern void can_init_buff_rx(uint32_t const can_x_reg_addr,
                             uint32_t const can_ram_start_addr);

/* Function to initialize the MPC577 registers  */
extern void can_init_register(uint32_t const can_x_reg_addr,
                              ts_can_conf const * const ptr_can_conf,
                              uint32_t const can_ram_start_addr);

/* Function to store the CAN frames from Rx FIFO to shared mem  */
extern void can_read(uint32_t  const can_x_reg_addr,
                     uint32_t const src_can_ram_addr,
                     ts_can_rx* const ptr_dest_shmem_can,
                     ts_can_conf const * const ptr_can_conf);

/* Function to get the different index of Rx buffers  */
extern void can_read_get_fifo_rx_lvl(uint32_t  const can_conf_id,
                                     uint32_t* const p_fifo_0_lvl,
                                     uint32_t* const p_fifo_0_start_offset,
                                     uint32_t* const p_fifo_1_lvl,
                                     uint32_t* const p_fifo_1_start_offset);

/* Function to retrieve the frames from ram (FIFO)  */
extern void can_read_get_msg_from_can_ram(uint32_t const src_can_ram_addr,
                                   ts_can_frame* const can_frame_rx_tab,
                                   ts_can_conf const * const ptr_can_conf,
                                   te_can_fifo_rec_t const fifo_selection,
                                   uint32_t          const buff_elt_position);

/* Function to swap endianess of frames  */
extern void can_read_conv_rx_frame(ts_can_rx_buff_elt_t * src_can_ram_frame,
                            ts_can_frame * const dest_can_frame_rx_tab,
                            ts_can_conf const * const ptr_can_conf);

/* Function to get fifo fill level  */
extern void can_read_ack_index_fifo_rx(uint32_t          const can_conf_id,
                                       te_can_fifo_rec_t const wich_fifo,
                                       uint32_t          const idx_fifo);

#endif /* CAN_PRIVATE_H */
