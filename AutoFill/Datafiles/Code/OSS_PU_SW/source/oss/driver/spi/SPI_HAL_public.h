/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef SPI_HAL_PUBLIC_H
#define SPI_HAL_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */

/* SPI Command CS define */
#define SPI_HAL_CMD_CS_0            0x00010000ul
#define SPI_HAL_CMD_CS_1            0x00020000ul
#define SPI_HAL_CMD_CS_2            0x00040000ul
#define SPI_HAL_CMD_CS_3            0x00080000ul
#define SPI_HAL_CMD_CS_4            0x00100000ul
#define SPI_HAL_CMD_CS_5            0x00200000ul
#define SPI_HAL_CMD_CS_6            0x00400000ul
#define SPI_HAL_CMD_CS_7            0x00800000ul

/* SPI Command CTAR define */
#define SPI_HAL_CMD_CTAR_0          0x00000000ul
#define SPI_HAL_CMD_CTAR_1          0x10000000ul
#define SPI_HAL_CMD_CTAR_2          0x20000000ul
#define SPI_HAL_CMD_CTAR_3          0x30000000ul
#define SPI_HAL_CMD_CTAR_4          0x40000000ul
#define SPI_HAL_CMD_CTAR_5          0x50000000ul
#define SPI_HAL_CMD_CTAR_6          0x60000000ul
#define SPI_HAL_CMD_CTAR_7          0x70000000ul

/* SPI Command Clear Transfer Counter define */
#define SPI_HAL_CMD_CLEAR_COUNTER   (uint32_t)0x04000000

/* SPI Command Mode Frame State define */
#define SPI_HAL_CMD_MODE_FRAME      (uint32_t)0x80000000
#define SPI_HAL_CMD_MODE_FRAME_END  (uint32_t)0x08000000

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
/* */

/* ---------- provided datas: ----------------------------------------------- */

/* ---------- provided operations: ------------------------------------------ */
/* */
extern void SPI_INIT( void );

extern void SPI_CLEAR_TX_FIFO (CMN_IOSP_ID_t       const p_spi_conf_id);

extern void SPI_CLEAR_RX_FIFO (CMN_IOSP_ID_t       const p_spi_conf_id);
/* */
extern void SPI_ONE_READ_DATA ( CMN_IOSP_ID_t       const p_spi_conf_id,
                                CMN_SYSTEM_ADDR_t   const p_buff_addr,
                                CMN_SYSTEM_SIZE_t   const p_buff_size,
                                CMN_SYSTEM_SIZE_t * const p_read_size);
/* */
extern void SPI_ONE_WRITE_CMD_DATA( CMN_IOSP_ID_t       const p_spi_conf_id,
                                    CMN_SYSTEM_ADDR_t   const p_buff_addr,
                                    CMN_SYSTEM_SIZE_t   const p_buff_size,
                                    CMN_SYSTEM_SIZE_t * const p_written_size);
/* */
extern void SPI_ONE_WRITE_DATA( CMN_IOSP_ID_t       const p_spi_conf_id,
                                CMN_SYSTEM_ADDR_t   const p_buff_addr,
                                CMN_SYSTEM_SIZE_t   const p_buff_size,
                                CMN_SYSTEM_SIZE_t * const p_written_size);
/* */
extern void SPI_FIFO_READ_DATA ( CMN_IOSP_ID_t       const p_spi_conf_id,
                                 CMN_SYSTEM_ADDR_t   const p_buff_addr,
                                 CMN_SYSTEM_SIZE_t   const p_buff_size,
                                 CMN_SYSTEM_SIZE_t * const p_read_size);
/* */
extern void SPI_FIFO_WRITE_CMD_DATA( CMN_IOSP_ID_t       const p_spi_conf_id,
                                     CMN_SYSTEM_ADDR_t   const p_buff_addr,
                                     CMN_SYSTEM_SIZE_t   const p_buff_size,
                                     CMN_SYSTEM_SIZE_t * const p_written_size);
/* */
extern void SPI_FIFO_WRITE_DATA( CMN_IOSP_ID_t       const p_spi_conf_id,
                                 CMN_SYSTEM_ADDR_t   const p_buff_addr,
                                 CMN_SYSTEM_SIZE_t   const p_buff_size,
                                 CMN_SYSTEM_SIZE_t * const p_written_size);
/* */
extern void SPI_DMA_READ_DATA ( CMN_IOSP_ID_t       const p_spi_conf_id,
                                CMN_SYSTEM_ADDR_t   const p_buff_addr,
                                CMN_SYSTEM_SIZE_t   const p_buff_size,
                                CMN_SYSTEM_SIZE_t * const p_read_size);
/* */
extern void SPI_DMA_WRITE_CMD_DATA( CMN_IOSP_ID_t         const p_spi_conf_id,
                                    CMN_SYSTEM_ADDR_t     const p_buff_addr,
                                    CMN_SYSTEM_SIZE_t     const p_buff_size,
                                    CMN_SYSTEM_SIZE_t *   const p_written_size);
/* */
extern void SPI_DMA_WRITE_DATA( CMN_IOSP_ID_t       const p_spi_conf_id,
                                CMN_SYSTEM_ADDR_t   const p_buff_addr,
                                CMN_SYSTEM_SIZE_t   const p_buff_size,
                                CMN_SYSTEM_SIZE_t * const p_written_size);
/* */
extern void SPI_DMA_STATUS_READ_DATA ( CMN_IOSP_ID_t       const p_spi_conf_id,
                                       CMN_SYSTEM_SIZE_t * const p_read_size);
/* */
extern void SPI_DMA_STATUS_WRITE_CMD_DATA ( CMN_IOSP_ID_t       const p_spi_conf_id,
                                            CMN_SYSTEM_SIZE_t * const p_write_size);
/* */
extern void SPI_DMA_STATUS_WRITE_DATA ( CMN_IOSP_ID_t       const p_spi_conf_id,
                                        CMN_SYSTEM_SIZE_t * const p_write_size);

#endif /* SPI_HAL_PUBLIC_H */
