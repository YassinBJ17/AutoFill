/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/spi/SPI_CFEX_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "driver/spi/SPI_HAL_public.h"
#include "driver/spi/SPI_REG_common.h"

/* ---------- internal define constants: ------------------------------------ */
/* u_CTAR Slave configuration mask */
#define DMA_CTAR_SLAVE_CONF_MASK   0x7F800000ul

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
/* */
/* MPC577 SPI specific controller register mapping */
uint32_t const c_SPI_ctrler_addr[8]=
{
   0xFFE70000,      /* MPC5777DS_DSPI0_BA  */
   0xFFE74000,      /* MPC5777DS_DSPI1_BA  */
   0xFBE70000,      /* MPC5777DS_DSPI2_BA  */
   0xFBE74000,      /* MPC5777DS_DSPI3_BA  */
   0xFFE78000,      /* MPC5777DS_DSPI4_BA  */
   0xFBE78000,      /* MPC5777DS_DSPI5_BA  */
   0xFFE7C000,      /* MPC5777DS_DSPI6_BA  */
   0xFFE88000       /* MPC5777DS_DSPI12_BA */
};

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void SPI_INIT( void )
{
   /* Local variable declaration */
   uint32_t                        v_spi_index;
   uint32_t                        v_spi_ctar;
   ts_SPI_REG volatile *           pt_spi_reg;
   ts_SPI_CFEX_ELT const *         pt_spi_conf;
   reg16_t *                       pt_spi_cmd_default;

   /* */
   /* General SPI configuration */
   /* */

   /* */
   for ( v_spi_index = 0ul ; v_spi_index < c_SPI_CFEX_tab_SIZE ; v_spi_index++ )
   {
      /* Get SPI configuration descriptor */
      pt_spi_conf = &(c_SPI_CFEX_CONFIGURATION_tab[v_spi_index]);

      /* Get SPI registers descriptor */
      /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision. The structure type 'ts_SPI_REG' is tailor-made for the registers starting at this address.  */
      pt_spi_reg = (ts_SPI_REG volatile *)c_SPI_ctrler_addr[pt_spi_conf->s_line_nb];

      /* s_MCR Register */
      /****************/
      /* Transfert start inactive for configuration */
      pt_spi_reg->s_MCR.u_B.s_HALT = (reg32_t)1ul;

      /* Slave-Master mode */
      if ( pt_spi_conf->s_slave_master == e_SPI_CFEX_MODE_MASTER )
      {
         /* Mode Master */
         pt_spi_reg->s_MCR.u_B.s_MSTR = (reg32_t)1ul;
      }
      else   /* e_SPI_CFEX_MODE_SLAVE */
      {
         /* Mode Slave */
         pt_spi_reg->s_MCR.u_B.s_MSTR = (reg32_t)0ul;
      }
      /* By default */
      pt_spi_reg->s_MCR.u_B.s_CONT_SCKE = (reg32_t)0ul;
      pt_spi_reg->s_MCR.u_B.s_DCONF = (reg32_t)0ul;
      pt_spi_reg->s_MCR.u_B.s_FRZ = (reg32_t)0ul;
      pt_spi_reg->s_MCR.u_B.s_MTFE = (reg32_t)0ul;
      pt_spi_reg->s_MCR.u_B.s_PCSSE = (reg32_t)0ul;
      pt_spi_reg->s_MCR.u_B.s_ROOE = (reg32_t)0ul;
      /* >RELAX<SYNCHRONe_C_Code_7.2> The value '0xFF' set the 8 bits of s_PCSIS to '1', which correspond to setting the inactive state of all PCSx to high. */
      pt_spi_reg->s_MCR.u_B.s_PCSIS = (reg32_t)0xFFul;
      pt_spi_reg->s_MCR.u_B.s_MDIS = (reg32_t)0ul;
      /* Transfer mode */
      if ( pt_spi_conf->s_transfer_mode == e_SPI_CFEX_TRANSFER_MODE_ONE )
      {
         /* Mode One   */
         pt_spi_reg->s_MCR.u_B.s_DIS_TXF = (reg32_t)1ul;
         pt_spi_reg->s_MCR.u_B.s_DIS_RXF = (reg32_t)1ul;
         pt_spi_reg->s_MCR.u_B.s_CLR_TXF = (reg32_t)0ul;
         pt_spi_reg->s_MCR.u_B.s_CLR_RXF = (reg32_t)0ul;
      }
      else /* e_SPI_CFEX_TRANSFER_MODE_FIFO or e_SPI_CFEX_TRANSFER_MODE_DMA */
      {
         /* Mode FIFO or DMA   */
         pt_spi_reg->s_MCR.u_B.s_DIS_TXF = (reg32_t)0ul;
         pt_spi_reg->s_MCR.u_B.s_DIS_RXF = (reg32_t)0ul;
         pt_spi_reg->s_MCR.u_B.s_CLR_TXF = (reg32_t)0ul;
         pt_spi_reg->s_MCR.u_B.s_CLR_RXF = (reg32_t)0ul;
      }
      /* By default */
      pt_spi_reg->s_MCR.u_B.s_SMPL_PT = (reg32_t)0ul;
      pt_spi_reg->s_MCR.u_B.s_XSPI = (reg32_t)0ul;         /* 16 bits mode */
      pt_spi_reg->s_MCR.u_B.s_FCPCS = (reg32_t)0ul;
      pt_spi_reg->s_MCR.u_B.s_PES = (reg32_t)0ul;

      /* u_CTAR Register */
      /*****************/
      if ( pt_spi_conf->s_slave_master == e_SPI_CFEX_MODE_MASTER )
      {
         /* Mode Master */
         /* */
         for ( v_spi_ctar = 0ul; v_spi_ctar < SPI_CFEX_CTAR_NB; v_spi_ctar++ )
         {
            pt_spi_reg->s_MODE.u_CTAR[v_spi_ctar].u_R = (reg32_t)pt_spi_conf->s_ctar_conf[v_spi_ctar];
         }
      }
      else   /* e_SPI_CFEX_MODE_SLAVE */
      {
         /* Mode Slave */
         pt_spi_reg->s_MODE.u_CTAR[0].u_R = (reg32_t)pt_spi_conf->s_ctar_conf[0] & (reg32_t)DMA_CTAR_SLAVE_CONF_MASK;
      }

      /***   Mode DMA  ***/
      if ( pt_spi_conf->s_transfer_mode == e_SPI_CFEX_TRANSFER_MODE_DMA )
      {
         /* Master mode and Command Config Used */
         if (  pt_spi_conf->s_slave_master == e_SPI_CFEX_MODE_MASTER )
         {
            /* Mode Master - Program COMMAND_data SPI word only */
            /* Do not access at the data register               */
            /* >RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> The cast is used to retrieve the address of the field TXDATA (16 bits) of PUSHR register */
            pt_spi_cmd_default  = (reg16_t *)(&(pt_spi_reg->s_PUSHR));

            /* s_cmd_by_default is a 32 bit word with the 16 MSB being the 'command' and the 16 LSB the data. */
            /* {{RELAX<SYNCHRONe_C_Code_7.2, SYNCHRONe_C_Code_10.7>  The right shift here is used to retrieve only the '16' command bits. No loss of precision since the right shift reduced the number of bits to '16'. */
            *pt_spi_cmd_default = (reg16_t)  (pt_spi_conf->s_cmd_by_default >> 16); /* Prog. cmd value > Fifo 1 */
            *pt_spi_cmd_default = (reg16_t)  (pt_spi_conf->s_cmd_by_default >> 16); /* Prog. cmd value > Fifo 2 */
            *pt_spi_cmd_default = (reg16_t)  (pt_spi_conf->s_cmd_by_default >> 16); /* Prog. cmd value > Fifo 3 */
            *pt_spi_cmd_default = (reg16_t)  (pt_spi_conf->s_cmd_by_default >> 16); /* Prog. cmd value > Fifo 4 */
            /* }}<SYNCHRONe_C_Code_7.2,10.7> */
         }

         /* s_SR Register : DMA (with FIFO) Enable */
         /****************************************/
         pt_spi_reg->s_SR.u_R   = (reg32_t)0x02130000ul;
         /* s_RSER Register : DMA (with FIFO) Enable */
         /******************************************/
         pt_spi_reg->s_RSER.u_R = (reg32_t)0x4313C000ul;
      }

      /* Transfert start active */
      pt_spi_reg->s_MCR.u_B.s_HALT = (reg32_t)0ul;

      /* SPI Descriptor init       */
      /* Register s_address */
      SPI_CFEX_descriptor_tab[v_spi_index].s_address = c_SPI_ctrler_addr[pt_spi_conf->s_line_nb];
      /* Command word */
      SPI_CFEX_descriptor_tab[v_spi_index].s_command_value = pt_spi_conf->s_cmd_by_default;
      /* DMA TX line number */
      SPI_CFEX_descriptor_tab[v_spi_index].s_dma_conf_tx_nb = pt_spi_conf->s_dma_conf_tx_nb;
      /* DMA RX line number */
      SPI_CFEX_descriptor_tab[v_spi_index].s_dma_conf_rx_nb = pt_spi_conf->s_dma_conf_rx_nb;
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
