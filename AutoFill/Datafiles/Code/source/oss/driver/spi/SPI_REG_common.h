/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef SPI_REG_COMMON_H
#define SPI_REG_COMMON_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

typedef struct
{
   /* {{RELAX<SYNCHRONe_C_Code_6.6> Following structures and unions are used for the mapping of the MPC registers. */
   union
   {                              /* DSPI Module Configuration Register */
      reg32_t u_R;
      struct
      {
         reg32_t s_MSTR:1;
         reg32_t s_CONT_SCKE:1;
         reg32_t s_DCONF:2;
         reg32_t s_FRZ:1;
         reg32_t s_MTFE:1;
         reg32_t s_PCSSE:1;
         reg32_t s_ROOE:1;
         reg32_t s_PCSIS:8;
         reg32_t  :1;
         reg32_t s_MDIS:1;
         reg32_t s_DIS_TXF:1;
         reg32_t s_DIS_RXF:1;
         reg32_t s_CLR_TXF:1;
         reg32_t s_CLR_RXF:1;
         reg32_t s_SMPL_PT:2;
         reg32_t  :4;
         reg32_t s_XSPI:1;
         reg32_t s_FCPCS:1;
         reg32_t s_PES:1;
         reg32_t s_HALT:1;
      } u_B;
   } s_MCR;

   reg32_t s_DSPI_reserved0;
   union
   {                              /* DSPI Transfer Count Register */
      reg32_t u_R;
      struct
      {
         reg32_t s_SPI_TCNT:16;
         reg32_t  :16;
      } u_B;
   } s_TCR;

   union
   {
      union
      {                            /* DSPI Clock and Transfer Attributes Register (In Master Mode) */
         reg32_t u_R;
         struct
         {
            reg32_t s_DBR:1;
            reg32_t s_FMSZ:4;
            reg32_t s_CPOL:1;
            reg32_t s_CPHA:1;
            reg32_t s_LSBFE:1;
            reg32_t s_PCSSCK:2;
            reg32_t s_PASC:2;
            reg32_t s_PDT:2;
            reg32_t s_PBR:2;
            reg32_t s_CSSCK:4;
            reg32_t s_ASC:4;
            reg32_t s_DT:4;
            reg32_t s_BR:4;
         } u_B;

      /* >RELAX<SYNCHRONe_C_Code_7.2> There is '8' CTAR registers. */
      } u_CTAR[8];
      union
      {                            /* DSPI Clock and Transfer Attributes Register (In Slave Mode) */
         reg32_t u_R;
         struct
         {
            reg32_t s_FMSZ:5;
            reg32_t s_CPOL:1;
            reg32_t s_CPHA:1;
            reg32_t s_PE:1;
            reg32_t s_PP:1;
            reg32_t s_FMSZ5:1;
            reg32_t  :22;
         } u_B;

      /* >RELAX<SYNCHRONe_C_Code_7.2> There is '2' CTAR_SLAVE registers. */
      } u_CTAR_SLAVE[2];
   } s_MODE;

   union
   {                              /* DSPI Status Register */
      reg32_t u_R;
      struct
      {
         reg32_t s_TCF:1;
         reg32_t s_TXRXS:1;
         reg32_t s_SPITCF:1;
         reg32_t s_EOQF:1;
         reg32_t s_TFUF:1;
         reg32_t s_DSITCF:1;
         reg32_t s_TFFF:1;
         reg32_t s_BSYF:1;
         reg32_t s_CMDTCF:1;
         reg32_t s_DPEF:1;
         reg32_t s_SPEF:1;
         reg32_t s_DDIF:1;
         reg32_t s_RFOF:1;
         reg32_t s_TFIWF:1;
         reg32_t s_RFDF:1;
         reg32_t s_CMDFFF:1;
         reg32_t s_TXCTR:4;
         reg32_t s_TXNXTPTR:4;
         reg32_t s_RXCTR:4;
         reg32_t s_POPNXTPTR:4;
      } u_B;
   } s_SR;

   union
   {                              /* DSPI DMA/Interrupt Request Select and Enable Register */
      reg32_t u_R;
      struct
      {
         reg32_t s_TCF_RE:1;
         reg32_t s_CMDFFF_RE:1;
         reg32_t s_SPITCF_RE:1;
         reg32_t s_EOQF_RE:1;
         reg32_t s_TFUF_RE:1;
         reg32_t s_DSITCF_RE:1;
         reg32_t s_TFFF_RE:1;
         reg32_t s_TFFF_DIRS:1;
         reg32_t s_CMDTCF_RE:1;
         reg32_t s_DPEF_RE:1;
         reg32_t s_SPEF_RE:1;
         reg32_t s_DDIF_RE:1;
         reg32_t s_RFOF_RE:1;
         reg32_t s_TFIWF_RE:1;
         reg32_t s_RFDF_RE:1;
         reg32_t s_RFDF_DIRS:1;
         reg32_t s_CMDFFF_DIRS:1;
         reg32_t s_DDIF_DIRS:1;
         reg32_t  :14;
      } u_B;
   } s_RSER;

   union
   {
      union
      {                            /* DSPI PUSH FIFO Register In Master Mode */
         reg32_t u_R;
         struct
         {
            reg32_t s_CONT:1;
            reg32_t s_CTAS:3;
            reg32_t s_EOQ:1;
            reg32_t s_CTCNT:1;
            reg32_t s_PE_MASC:1;
            reg32_t s_PP_MCSC:1;
            reg32_t s_PCS:8;
            reg32_t s_TXDATA:16;
         } u_B;
      } u_PUSHR;
      union
      {                            /* DSPI PUSH FIFO Register In Slave Mode */
         reg32_t u_R;
         struct
         {
            reg32_t  :16;
            reg32_t s_TXDATA:16;
         } u_B;
      } u_PUSHR_SLAVE;
   } s_PUSHR;

   union
   {                              /* DSPI POP FIFO Register */
      reg32_t u_R;
      struct
      {
         reg32_t s_RXDATA:32;
      } u_B;
   } s_POPR;

   union
   {                              /* DSPI Transmit FIFO Registers */
      reg32_t u_R;
      struct
      {
         reg32_t s_TXCMD_TXDATA:16;
         reg32_t s_TXDATA:16;
      } u_B;
      /* >RELAX<SYNCHRONe_C_Code_7.2> There is '4' TXFR registers. */
   } s_TXFR[4];

   /* >RELAX<SYNCHRONe_C_Code_7.2> There is a reserved area equal to '48' * 8 bits ('reg8_t'). */
   reg8_t s_DSPI_reserved1[48];
   union
   {                              /* DSPI Receive FIFO Registers */
      reg32_t u_R;
      struct
      {
         reg32_t s_RXDATA:32;
      } u_B;

   /* >RELAX<SYNCHRONe_C_Code_7.2> There is '4' RXFR registers. */
   } s_RXFR[4];

   /* >RELAX<SYNCHRONe_C_Code_7.2> There is a reserved area equal to '48' * 8 bits ('reg8_t'). */
   reg8_t s_DSPI_reserved2[48];
   union
   {                              /* DSPI DSI Configuration Register 0 */
      reg32_t u_R;
      struct
      {
         reg32_t  :1;
         reg32_t s_FMSZ4:1;
         reg32_t  :6;
         reg32_t s_FMSZ5:1;
         reg32_t  :1;
         reg32_t s_ITSB:1;
         reg32_t s_TSBC:1;
         reg32_t s_TXSS:1;
         reg32_t s_TPOL:1;
         reg32_t  :1;
         reg32_t s_CID:1;
         reg32_t s_DCONT:1;
         reg32_t s_DSICTAS:3;
         reg32_t s_DMS:1;
         reg32_t s_PES:1;
         reg32_t s_PE:1;
         reg32_t s_PP:1;
         reg32_t s_DPCSx:8;
      } u_B;
   } s_DSICR0;

   union
   {                              /* DSPI DSI Serialization Data Register 0 */
      reg32_t u_R;
      struct
      {
         reg32_t s_SER_DATA:32;
      } u_B;
   } s_SDR0;

   union
   {                              /* DSPI DSI Alternate Serialization Data Register 0 */
      reg32_t u_R;
      struct
      {
         reg32_t s_ASER_DATA:32;
      } u_B;
   } s_ASDR0;

   union
   {                              /* DSPI DSI Transmit Comparison Register 0 */
      reg32_t u_R;
      struct
      {
         reg32_t s_COMP_DATA:32;
      } u_B;
   } s_COMPR0;

   union
   {                              /* DSPI DSI Deserialization Data Register 0 */
      reg32_t u_R;
      struct
      {
         reg32_t s_DESER_DATA:32;
      } u_B;
   } s_DDR0;

   union
   {                              /* DSPI DSI Configuration Register 1 */
      reg32_t u_R;
      struct
      {
         reg32_t  :2;
         reg32_t s_TSBCNT:6;
         reg32_t  :5;
         reg32_t s_DSI64E:1;
         reg32_t s_DSE1:1;
         reg32_t s_DSE0:1;
         reg32_t s_TRGPRD:8;
         reg32_t s_DPCS1_x:8;
      } u_B;
   } s_DSICR1;

   union
   {                              /* DSPI DSI Serialization Source Select Register 0 */
      reg32_t u_R;
      struct
      {
         reg32_t s_SS:32;
      } u_B;
   } s_SSR0;

   union
   {                              /* DSPI DSI Parallel Input Select Register 0 */
      reg32_t u_R;
      struct
      {
         reg32_t s_IPS7:4;
         reg32_t s_IPS6:4;
         reg32_t s_IPS5:4;
         reg32_t s_IPS4:4;
         reg32_t s_IPS3:4;
         reg32_t s_IPS2:4;
         reg32_t s_IPS1:4;
         reg32_t s_IPS0:4;
      } u_B;
   } s_PISR0;

   union
   {                              /* DSPI DSI Parallel Input Select Register 1 */
      reg32_t u_R;
      struct
      {
         reg32_t s_IPS15:4;
         reg32_t s_IPS14:4;
         reg32_t s_IPS13:4;
         reg32_t s_IPS12:4;
         reg32_t s_IPS11:4;
         reg32_t s_IPS10:4;
         reg32_t s_IPS9:4;
         reg32_t s_IPS8:4;
      } u_B;
   } s_PISR1;

   union
   {                              /* DSPI DSI Parallel Input Select Register 2 */
      reg32_t u_R;
      struct
      {
         reg32_t s_IPS23:4;
         reg32_t s_IPS22:4;
         reg32_t s_IPS21:4;
         reg32_t s_IPS20:4;
         reg32_t s_IPS19:4;
         reg32_t s_IPS18:4;
         reg32_t s_IPS17:4;
         reg32_t s_IPS16:4;
      } u_B;
   } s_PISR2;

   union
   {                              /* DSPI DSI Parallel Input Select Register 3 */
      reg32_t u_R;
      struct
      {
         reg32_t s_IPS31:4;
         reg32_t s_IPS30:4;
         reg32_t s_IPS29:4;
         reg32_t s_IPS28:4;
         reg32_t s_IPS27:4;
         reg32_t s_IPS26:4;
         reg32_t s_IPS25:4;
         reg32_t s_IPS24:4;
      } u_B;
   } s_PISR3;

   union
   {                              /* DSPI DSI Deserialized Data Interrupt Mask Register 0 */
      reg32_t u_R;
      struct
      {
         reg32_t s_MASK:32;
      } u_B;
   } s_DIMR0;

   union
   {                              /* DSPI DSI Deserialized Data Polarity Interrupt Register 0 */
      reg32_t u_R;
      struct
      {
         reg32_t s_DP:32;
      } u_B;
   } s_DPIR0;

   union
   {                              /* DSPI DSI Serialization Data Register 1 */
      reg32_t u_R;
      struct
      {
         reg32_t s_SER_DATA:32;
      } u_B;
   } s_SDR1;

   union
   {                              /* DSPI DSI Alternate Serialization Data Register 1 */
      reg32_t u_R;
      struct
      {
         reg32_t s_ASER_DATA:32;
      } u_B;
   } s_ASDR1;

   union
   {                              /* DSPI DSI Transmit Comparison Register 1 */
      reg32_t u_R;
      struct
      {
         reg32_t s_COMP_DATA:32;
      } u_B;
   } s_COMPR1;

   union
   {                              /* DSPI DSI Deserialization Data Register 1 */
      reg32_t u_R;
      struct
      {
         reg32_t s_DESER_DATA:32;
      } u_B;
   } s_DDR1;

   union
   {                              /* DSPI DSI Serialization Source Select Register 1 */
      reg32_t u_R;
      struct
      {
         reg32_t s_SS:32;
      } u_B;
   } s_SSR1;

   union
   {                              /* DSPI DSI Parallel Input Select Register 4 */
      reg32_t u_R;
      struct
      {
         reg32_t s_IPS39:4;
         reg32_t s_IPS38:4;
         reg32_t s_IPS37:4;
         reg32_t s_IPS36:4;
         reg32_t s_IPS35:4;
         reg32_t s_IPS34:4;
         reg32_t s_IPS33:4;
         reg32_t s_IPS32:4;
      } u_B;
   } s_PISR4;

   union
   {                              /* DSPI DSI Parallel Input Select Register 5 */
      reg32_t u_R;
      struct
      {
         reg32_t s_IPS47:4;
         reg32_t s_IPS46:4;
         reg32_t s_IPS45:4;
         reg32_t s_IPS44:4;
         reg32_t s_IPS43:4;
         reg32_t s_IPS42:4;
         reg32_t s_IPS41:4;
         reg32_t s_IPS40:4;
      } u_B;
   } s_PISR5;

   union
   {                              /* DSPI DSI Parallel Input Select Register 6 */
      reg32_t u_R;
      struct
      {
         reg32_t s_IPS55:4;
         reg32_t s_IPS54:4;
         reg32_t s_IPS53:4;
         reg32_t s_IPS52:4;
         reg32_t s_IPS51:4;
         reg32_t s_IPS50:4;
         reg32_t s_IPS49:4;
         reg32_t s_IPS48:4;
      } u_B;
   } s_PISR6;

   union
   {                              /* DSPI DSI Parallel Input Select Register 7 */
      reg32_t u_R;
      struct
      {
         reg32_t s_IPS63:4;
         reg32_t s_IPS62:4;
         reg32_t s_IPS61:4;
         reg32_t s_IPS60:4;
         reg32_t s_IPS59:4;
         reg32_t s_IPS58:4;
         reg32_t s_IPS57:4;
         reg32_t s_IPS56:4;
      } u_B;
   } s_PISR7;

   union
   {                              /* DSPI DSI Deserialized Data Interrupt Mask Register 1 */
      reg32_t u_R;
      struct
      {
         reg32_t s_MASK:32;
      } u_B;
   } s_DIMR1;

   union
   {                              /* DSPI DSI Deserialized Data Polarity Interrupt Register 1 */
      reg32_t u_R;
      struct
      {
         reg32_t s_DP:32;
      } u_B;
   } s_DPIR1;

   union
   {                              /* DSPI Clock and Transfer Attributes Register Extended */
      reg32_t u_R;
      struct
      {
         reg32_t  :15;
         reg32_t s_FMSZE:1;
         reg32_t  :5;
         reg32_t s_DTCP:11;
      } u_B;

   /* >RELAX<SYNCHRONe_C_Code_7.2> There is 8 'CTARE' registers. */
   } s_CTARE[8];

   union
   {                              /* DSPI Status Register Extended */
      reg32_t u_R;
      struct
      {
         reg32_t  :24;
         reg32_t s_CMDCTR:4;
         reg32_t s_CMDNXTPTR:4;
      } u_B;
   } s_SREX;
   /* }}<SYNCHRONe_C_Code_6.6> */
}
ts_SPI_REG;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

#endif /* SPI_REG_COMMON_H */
