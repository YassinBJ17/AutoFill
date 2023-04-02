/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef SPI_CFEX_PUBLIC_H
#define SPI_CFEX_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */
/*  */

/* CTAR number */
#define SPI_CFEX_CTAR_NB        8ul

/* Length of FIFO RX and TX */
#define SPI_CFEX_FIFO_SIZE      4ul
/* Length of DATA RX and TX */
#define SPI_CFEX_DATA_SIZE      2ul     /* 16 bits = 2 octets */
/* Length of CMD TX */
#define SPI_CFEX_CMD_SIZE       2ul     /* 16 bits = 2 octets */
/* Length of CMD & DATA TX */
#define SPI_CFEX_CMD_DATA_SIZE  (SPI_CFEX_CMD_SIZE + SPI_CFEX_DATA_SIZE)

/* SPI register RX offset */
#define SPI_REG_RX_OFFSET       0x00000038ul
/* SPI register TX offset */
#define SPI_REG_TX_OFFSET       0x00000034ul

/* ---------- provided types: ----------------------------------------------- */

/* */
typedef enum
{
   /* DSPI 0  */
   e_SPI_CFEX_LINE_0  = 0,
   /* DSPI 1  */
   e_SPI_CFEX_LINE_1  = 1,
   /* DSPI 2  */
   e_SPI_CFEX_LINE_2  = 2,
   /* DSPI 3  */
   e_SPI_CFEX_LINE_3  = 3,
   /* DSPI 4  */
   e_SPI_CFEX_LINE_4  = 4,
   /* DSPI 5  */
   e_SPI_CFEX_LINE_5  = 5,
   /* DSPI 6  */
   e_SPI_CFEX_LINE_6  = 6,
   /* DSPI 12 */
   e_SPI_CFEX_LINE_12 = 7
}
te_SPI_CFEX_LINE_NB;

/* */
typedef enum
{
   /* */
   e_SPI_CFEX_MODE_SLAVE  = 0,
   /* */
   e_SPI_CFEX_MODE_MASTER = 1
}
te_SPI_CFEX_MODE;

/* */
typedef enum
{
   /* */
   e_SPI_CFEX_TRANSFER_MODE_ONE  = 0,
   /* */
   e_SPI_CFEX_TRANSFER_MODE_FIFO = 1,
   /* */
   e_SPI_CFEX_TRANSFER_MODE_DMA  = 2
}
te_SPI_CFEX_TRANSFER_MODE;

/* */
/* Physical description of one SPI */
typedef struct
{
   /* SPI line number */
   te_SPI_CFEX_LINE_NB        s_line_nb;
   /* Slave-Master mode */
   te_SPI_CFEX_MODE           s_slave_master;
   /* Transfer mode */
   te_SPI_CFEX_TRANSFER_MODE  s_transfer_mode;
   /* CTAR Config */
   uint32_t                        s_ctar_conf[SPI_CFEX_CTAR_NB];
   /* Command tx value by default */
   uint32_t                        s_cmd_by_default;        /* 16b cmd & 16b data=0 */
   /* DMA TX line number */
   uint32_t                        s_dma_conf_tx_nb;
   /* DMA RX line number */
   uint32_t                        s_dma_conf_rx_nb;
}
ts_SPI_CFEX_ELT;

/* */
typedef struct
{
   /* Register s_address */
   CMN_SYSTEM_ADDR_VAL_t              s_address;
   /* Command word */
   uint32_t                     s_command_value;        /* 16b cmd & 16b data=0 */
   /* DMA TX line number */
   uint32_t                     s_dma_conf_tx_nb;
   /* DMA RX line number */
   uint32_t                     s_dma_conf_rx_nb;
}
ts_SPI_CONFIG_DESC;



/* ---------- provided constants: ------------------------------------------- */
/* */


/* {{RELAX<SYNCHRONe_C_Code_8.12, SYNCHRONe_C_Code_8.16> : the table c_SPI_CFEX_CONFIGURATION_tab and SPI_CFEX_descriptor_tab share the same size : c_SPI_CFEX_tab_SIZE. This size is a integration value so the table are declared without a size. */
extern const uint32_t c_SPI_CFEX_tab_SIZE;
extern const ts_SPI_CFEX_ELT c_SPI_CFEX_CONFIGURATION_tab[];

/* ---------- provided data: ------------------------------------------------ */
/* */
/* SPI descriptor */
extern ts_SPI_CONFIG_DESC SPI_CFEX_descriptor_tab[];
/* }}<SYNCHRONe_C_Code_8.12, SYNCHRONe_C_Code_8.16> */

/* ---------- provided operations: ------------------------------------------ */
/* */

#endif /* SPI_CFEX_PUBLIC_H */
