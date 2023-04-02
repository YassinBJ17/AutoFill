/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "driver/spi/SPI_CFEX_public.h"
#include "driver/spi/SPI_HAL_public.h"
#include "driver/dma_cfex/CFEX_HAL_DMA_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* SPI configuration table size */
#define SPI_MPC577_CFEX_TAB_SIZE 8

#define SPI_MPC577_CFEX_CTAR_0_CFG_AD7327    0x7CDE0110  /* All      */
#define SPI_MPC577_CFEX_CTAR_1_CFG_AD7327    0x7CF60241  /* XR, LVDT */
#define SPI_MPC577_CFEX_CTAR_2_CFG_AD7327    0x7C694207  /* SG       */
#define SPI_MPC577_CFEX_CTAR_3_CFG_AD7327    0x7C6B4207  /* P3       */
#define SPI_MPC577_CFEX_CTAR_4_CFG_AD7327    0x7C684207  /* POT      */
#define SPI_MPC577_CFEX_CTAR_5_CFG_AD7327    0x7C6A4207  /* VRT      */
#define SPI_MPC577_CFEX_CTAR_6_CFG_AD7327    0x7C6A4207  /* T4       */
#define SPI_MPC577_CFEX_CTAR_CFG_AD7327_ENA  0x7C000000
                                               /* DBR=0*/
                                               /* FMSZ=0xF*/
                                               /* CPOL=1 & CPHA=0*/
                                               /* PCSSCK=0 & CSSCK=0 => 0.0 ns CS->Clk*/
                                               /* DBR=0 & FMSZ=0*/
                                               /* LSBFE=0*/
                                               /* PASC=0 & ASC=0     => time conversion : 0.0 s*/
                                               /* PDT=0  & DT=0      => inter frame  : 0.0 s*/
                                               /* PBR=0  & BR=0      => 20Mhz clock  (PBR=0 -> Div 2, BR=0 -> Div 2)*/

#define SPI_MPC577_CFEX_CTAR_0_CFG_AD9837    0x7C020004

/* Command to configure CTAR[0] for ADT7310 temperature sensor */
#define SPI_CFEX_CTAR_0_CFG_ADT7310  (0xFE020005)

/* Command to configure CTAR[0] for CPXD pressure sensor */
/* Frame size = 7, CPOL = 0, CPHA = 1 */
#define SPI_CFEX_CTAR_0_CFG_CPXD     (0x3A000000)

/* Command TX : CS=0 - CTSAR0 */
#define SPI_MPC577_CFEX_CMD_TX_CS0_CTAR0   (SPI_HAL_CMD_CS_0 | SPI_HAL_CMD_CTAR_0)
#define SPI_MPC577_CFEX_CMD_TX_CS0_CTAR1   (SPI_HAL_CMD_CS_0 | SPI_HAL_CMD_CTAR_1)

/* Command TX : CS=1 - CTSAR0 */
#define SPI_CFEX_CMD_TX_CS1_CTAR0   (SPI_HAL_CMD_CS_1 | SPI_HAL_CMD_CTAR_0)

/* Command TX : CS=2 - CTSAR0 */
#define SPI_CFEX_CMD_TX_CS2_CTAR0   (SPI_HAL_CMD_CS_2 | SPI_HAL_CMD_CTAR_0)


/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
/* */
/* SPI configuration table size */
const uint32_t c_SPI_CFEX_tab_SIZE = SPI_MPC577_CFEX_TAB_SIZE;
/* */
/* SPI configuration table */
/* 0 : SPI 1 line          */
/* 1 : SPI 2 line          */
/* 2 : SPI 3 line          */
const ts_SPI_CFEX_ELT c_SPI_CFEX_CONFIGURATION_tab[SPI_MPC577_CFEX_TAB_SIZE] =
{
   /* 0 : SPI 1 line */
   {
      e_SPI_CFEX_LINE_1,                /* SPI line number       */
      e_SPI_CFEX_MODE_MASTER,           /* Slave-Master mode     */
      e_SPI_CFEX_TRANSFER_MODE_DMA,     /* Transfer mode         */
      {
         SPI_MPC577_CFEX_CTAR_0_CFG_AD7327,  /* CTAR 0 Configuration  */
         SPI_MPC577_CFEX_CTAR_1_CFG_AD7327,  /* CTAR 1 Configuration  */
         SPI_MPC577_CFEX_CTAR_2_CFG_AD7327,  /* CTAR 2 Configuration  */
         SPI_MPC577_CFEX_CTAR_3_CFG_AD7327,  /* CTAR 3 Configuration  */
         SPI_MPC577_CFEX_CTAR_4_CFG_AD7327,  /* CTAR 4 Configuration  */
         SPI_MPC577_CFEX_CTAR_5_CFG_AD7327,  /* CTAR 5 Configuration  */
         SPI_MPC577_CFEX_CTAR_6_CFG_AD7327,  /* CTAR 6 Configuration  */
         SPI_MPC577_CFEX_CTAR_CFG_AD7327_ENA /* CTAR 7 Configuration  */
      },
      SPI_MPC577_CFEX_CMD_TX_CS0_CTAR0,      /* Command TX by default */
      e_DMA_CFEX_ELT_SPI_ADC1_TX,            /* DMA TX line           */
      e_DMA_CFEX_ELT_SPI_ADC1_RX             /* DMA RX line           */
   },
   /* 1 : SPI 2 line */
   {
      e_SPI_CFEX_LINE_2,                /* SPI line number       */
      e_SPI_CFEX_MODE_MASTER,           /* Slave-Master mode     */
      e_SPI_CFEX_TRANSFER_MODE_DMA,     /* Transfer mode         */
      {
         SPI_MPC577_CFEX_CTAR_0_CFG_AD7327,  /* CTAR 0 Configuration  */
         SPI_MPC577_CFEX_CTAR_1_CFG_AD7327,  /* CTAR 1 Configuration  */
         SPI_MPC577_CFEX_CTAR_2_CFG_AD7327,  /* CTAR 2 Configuration  */
         SPI_MPC577_CFEX_CTAR_3_CFG_AD7327,  /* CTAR 3 Configuration  */
         SPI_MPC577_CFEX_CTAR_4_CFG_AD7327,  /* CTAR 4 Configuration  */
         SPI_MPC577_CFEX_CTAR_5_CFG_AD7327,  /* CTAR 5 Configuration  */
         SPI_MPC577_CFEX_CTAR_6_CFG_AD7327,  /* CTAR 6 Configuration  */
         SPI_MPC577_CFEX_CTAR_CFG_AD7327_ENA /* CTAR 7 Configuration  */
      },
      SPI_MPC577_CFEX_CMD_TX_CS0_CTAR0,      /* Command TX by default */
      e_DMA_CFEX_ELT_SPI_ADC2_TX,            /* DMA TX line           */
      e_DMA_CFEX_ELT_SPI_ADC2_RX             /* DMA RX line           */
   },
   /* 2 : SPI 3 line */
   {
      e_SPI_CFEX_LINE_3,                /* SPI line number       */
      e_SPI_CFEX_MODE_MASTER,           /* Slave-Master mode     */
      e_SPI_CFEX_TRANSFER_MODE_DMA,     /* Transfer mode         */
      {
         SPI_MPC577_CFEX_CTAR_0_CFG_AD7327,  /* CTAR 0 Configuration  */
         SPI_MPC577_CFEX_CTAR_1_CFG_AD7327,  /* CTAR 1 Configuration  */
         SPI_MPC577_CFEX_CTAR_2_CFG_AD7327,  /* CTAR 2 Configuration  */
         SPI_MPC577_CFEX_CTAR_3_CFG_AD7327,  /* CTAR 3 Configuration  */
         SPI_MPC577_CFEX_CTAR_4_CFG_AD7327,  /* CTAR 4 Configuration  */
         SPI_MPC577_CFEX_CTAR_5_CFG_AD7327,  /* CTAR 5 Configuration  */
         SPI_MPC577_CFEX_CTAR_6_CFG_AD7327,  /* CTAR 6 Configuration  */
         SPI_MPC577_CFEX_CTAR_CFG_AD7327_ENA /* CTAR 7 Configuration  */
      },
      SPI_MPC577_CFEX_CMD_TX_CS0_CTAR0,      /* Command TX by default */
      e_DMA_CFEX_ELT_SPI_ADC3_TX,            /* DMA TX line           */
      e_DMA_CFEX_ELT_SPI_ADC3_RX             /* DMA RX line           */
   },
   /* 3 : SPI 6 line */
   {
      e_SPI_CFEX_LINE_6,                /* SPI line number       */
      e_SPI_CFEX_MODE_MASTER,           /* Slave-Master mode     */
      e_SPI_CFEX_TRANSFER_MODE_FIFO,    /* Transfer mode         */
      {
         SPI_MPC577_CFEX_CTAR_0_CFG_AD9837,  /* CTAR 0 Configuration  */
         0,                                  /* CTAR 1 Configuration  */
         0,                                  /* CTAR 2 Configuration  */
         0,                                  /* CTAR 3 Configuration  */
         0,                                  /* CTAR 4 Configuration  */
         0,                                  /* CTAR 5 Configuration  */
         0,                                  /* CTAR 6 Configuration  */
         0                                   /* CTAR 7 Configuration  */
      },
      SPI_MPC577_CFEX_CMD_TX_CS0_CTAR0,      /* Command TX by default */
      4 /* TODO : -> 0  */  ,               /* DMA TX line           */
      5 /* TODO : -> 0  */                  /* DMA RX line           */
   },
   /* 4 : SPI 6 line */
   {
      e_SPI_CFEX_LINE_6,                /* SPI line number       */
      e_SPI_CFEX_MODE_MASTER,           /* Slave-Master mode     */
      e_SPI_CFEX_TRANSFER_MODE_FIFO,    /* Transfer mode         */
      {
         SPI_MPC577_CFEX_CTAR_0_CFG_AD9837,  /* CTAR 0 Configuration  */
         0,                                  /* CTAR 1 Configuration  */
         0,                                  /* CTAR 2 Configuration  */
         0,                                  /* CTAR 3 Configuration  */
         0,                                  /* CTAR 4 Configuration  */
         0,                                  /* CTAR 5 Configuration  */
         0,                                  /* CTAR 6 Configuration  */
         0                                   /* CTAR 7 Configuration  */
      },
      SPI_CFEX_CMD_TX_CS1_CTAR0,             /* Command TX by default */
      4 /* TODO : -> 0  */  ,               /* DMA TX line           */
      5 /* TODO : -> 0  */                  /* DMA RX line           */
   },
   /* 5 : SPI 6 line */
   {
      e_SPI_CFEX_LINE_6,                /* SPI line number       */
      e_SPI_CFEX_MODE_MASTER,           /* Slave-Master mode     */
      e_SPI_CFEX_TRANSFER_MODE_FIFO,    /* Transfer mode         */
      {
         SPI_MPC577_CFEX_CTAR_0_CFG_AD9837,  /* CTAR 0 Configuration  */
         0,                                  /* CTAR 1 Configuration  */
         0,                                  /* CTAR 2 Configuration  */
         0,                                  /* CTAR 3 Configuration  */
         0,                                  /* CTAR 4 Configuration  */
         0,                                  /* CTAR 5 Configuration  */
         0,                                  /* CTAR 6 Configuration  */
         0                                   /* CTAR 7 Configuration  */
      },
      SPI_CFEX_CMD_TX_CS2_CTAR0,             /* Command TX by default */
      4 /* TODO : -> 0  */  ,               /* DMA TX line           */
      5 /* TODO : -> 0  */                  /* DMA RX line           */
   },
   /* 6 : SPI 0 line */
   {
      e_SPI_CFEX_LINE_0,                   /* SPI line number       */
      e_SPI_CFEX_MODE_MASTER,              /* Slave-Master mode     */
      e_SPI_CFEX_TRANSFER_MODE_FIFO,        /* Transfer mode         */
      {
        SPI_CFEX_CTAR_0_CFG_ADT7310,              /* CTAR 0 Configuration  */
       0,                                         /* CTAR 1 Configuration not used */
       0,                                         /* CTAR 2 Configuration not used */
       0,                                         /* CTAR 3 Configuration not used */
       0,                                         /* CTAR 4 Configuration not used */
       0,                                         /* CTAR 5 Configuration not used */
       0,                                         /* CTAR 6 Configuration not used */
       0                                          /* CTAR 7 Configuration not used */
      },
     SPI_MPC577_CFEX_CMD_TX_CS0_CTAR0,          /* Command TX by default */
     0,                                           /* DMA CONF not used (TX line)           */
     0,                                         /* DMA CONF not used (RX line)           */
   },
   /* 7 : SPI 4 line */
   {
      e_SPI_CFEX_LINE_4,                        /* SPI line number       */
      e_SPI_CFEX_MODE_SLAVE,                    /* Slave-Master mode     */
      e_SPI_CFEX_TRANSFER_MODE_FIFO,            /* Transfer mode         */
      {
         SPI_CFEX_CTAR_0_CFG_CPXD,              /* CTAR 0 Configuration  */
         0,                                     /* CTAR 1 Configuration not used  */
         0,                                     /* CTAR 2 Configuration not used  */
         0,                                     /* CTAR 3 Configuration not used  */
         0,                                     /* CTAR 4 Configuration not used  */
         0,                                     /* CTAR 5 Configuration not used  */
         0,                                     /* CTAR 6 Configuration not used  */
         0                                      /* CTAR 7 Configuration not used  */
      },
      0,                                        /* Command TX by default not used */
      0,                                        /* DMA CONF not used (TX line)    */
      0                                         /* DMA CONF not used (RX line)    */
   }
};

/* ---------- internal data: ------------------------------------------------ */
/* SPI descriptor declaration */
ts_SPI_CONFIG_DESC SPI_CFEX_descriptor_tab[SPI_MPC577_CFEX_TAB_SIZE];

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operation bodies: ------------------------------------ */
