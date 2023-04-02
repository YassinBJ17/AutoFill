/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef UART_REG_PUBLIC_H
#define UART_REG_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */

#include "type/mcp_types.h"
#include "type/common_type.h"


 /* ============================================================================
    =============================== Module: LINFLEX2 ===========================
    ============================================================================ */

/* ---------- provided constants: ------------------------------------------- */
/* MPC5777M LINFlexD controller register address */
#define UART_LINFLEXD_CONTROLLER_0_ADDR  0xFFE8C000
#define UART_LINFLEXD_CONTROLLER_1_ADDR  0xFFE90000
#define UART_LINFLEXD_CONTROLLER_2_ADDR  0xFBE8C000
#define UART_LINFLEXD_CONTROLLER_14_ADDR 0xFFEA8000
#define UART_LINFLEXD_CONTROLLER_15_ADDR 0xFBEA8000
#define UART_LINFLEXD_CONTROLLER_16_ADDR 0xFFEAC000

/* MPC5777M LINFlexD master register address */
#define UART_LINFlexD_MASTER_ONLY_0_ADDR  0xFFE8C08C
#define UART_LINFlexD_MASTER_ONLY_1_ADDR  0xFFE9004C
#define UART_LINFlexD_MASTER_ONLY_2_ADDR  0xFBE8C04C
#define UART_LINFlexD_MASTER_ONLY_14_ADDR 0xFFEA804C
#define UART_LINFlexD_MASTER_ONLY_15_ADDR 0xFBEA804C
#define UART_LINFlexD_MASTER_ONLY_16_ADDR 0xFFEAC04C


/* {{RELAX<SYNCHRONe_C_Code_6.6> All structure respects the Register format : union between a 32 bits and a structure.*/
/* {{RELAX<SYNCHRONe_C_Code_8.17> All MPC5777M registers are described even if there are not used. */
/* {{RELAX<SYNCHRONe_C_Code_7.2> all literal value are defined by the MPC5777M Reference manual */
typedef struct
{
   union
   { /* LIN Control Register 1 */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :16 ;
        reg32_t s_CCD :1 ;
        reg32_t s_CFD :1 ;
        reg32_t s_LASE :1 ;
        reg32_t s_AUTOWU :1 ;
        reg32_t s_MBL :4 ;
        reg32_t s_BF :1 ;
        reg32_t s_RESERVE_2 :1 ;
        reg32_t s_LBKM :1 ;
        reg32_t s_MME :1 ;
        reg32_t s_SSBL :1 ;
        reg32_t s_RBLM :1 ;
        reg32_t s_SLEEP :1 ;
        reg32_t s_INIT :1 ;
      } u_B ;
   }
   s_LINCR1 ;


   union
   { /* LIN Interrupt enable register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :16 ;
        reg32_t s_SZIE :1 ;
        reg32_t s_OCIE :1 ;
        reg32_t s_BEIE :1 ;
        reg32_t s_CEIE :1 ;
        reg32_t s_HEIE :1 ;
        reg32_t s_RESERVE_2 :2 ;
        reg32_t s_FEIE :1 ;
        reg32_t s_BOIE :1 ;
        reg32_t s_LSIE :1 ;
        reg32_t s_WUIE :1 ;
        reg32_t s_DBFIE :1 ;
        reg32_t s_DBEIETOIE :1 ;
        reg32_t s_DRIE :1 ;
        reg32_t s_DTIE :1 ;
        reg32_t s_HRIE :1 ;
      } u_B ;
   }
   s_LINIER ;


   union
   { /* LIN Status Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :12 ;
        reg32_t s_AUTOSYNC_COMP :1 ;
        reg32_t s_RDC :3 ;
        reg32_t s_LINS :4 ; /* LIN state */
        reg32_t s_RESERVE_2 :2 ;
        reg32_t s_RMB :1 ;
        reg32_t s_DRBNE :1 ;
        reg32_t s_RXbusy :1 ;
        reg32_t s_RDI :1 ;
        reg32_t s_WUF :1 ;
        reg32_t s_DBFF :1 ;
        reg32_t s_DBEF :1 ;
        reg32_t s_DRF :1 ;
        reg32_t s_DTF :1 ;
        reg32_t s_HRF :1 ;
      } u_B ;
   }
   s_LINSR ;


   union
   { /* LIN Error Status Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :16 ;
        reg32_t s_SZF :1 ;
        reg32_t s_OCF :1 ;
        reg32_t s_BEF :1 ;
        reg32_t s_CEF :1 ;
        reg32_t s_SFEF :1 ;
        reg32_t s_SDEF :1 ;
        reg32_t s_IDPEF :1 ;
        reg32_t s_FEF :1 ;
        reg32_t s_BOF :1 ;
        reg32_t s_RESERVE_2 :6 ;
        reg32_t s_NF :1 ;
      } u_B ;
   }
   s_LINESR ;


   union

   { /* UART Mode Control Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_MIS :1 ;
        reg32_t s_CSP :3 ;
        reg32_t s_OSR :4 ;
        reg32_t s_ROSE :1 ;
        reg32_t s_NEF :3 ;
        reg32_t s_DTU_PCETX :1 ; /* Disable Timeout in UART mode/Parity transmission and checking */
        reg32_t s_SBUR :2 ;
        reg32_t s_WLS :1 ;
        reg32_t s_TDFL_TFC :3 ;
        reg32_t s_RDFL_RFC :3 ;
        reg32_t s_RFBM :1 ;
        reg32_t s_TFBM :1 ;
        reg32_t s_WL1 :1 ;
        reg32_t s_PC1 :1 ;
        reg32_t s_RxEn :1 ;
        reg32_t s_TxEn :1 ;
        reg32_t s_PC0 :1 ;
        reg32_t s_PCE :1 ;
        reg32_t s_WL0 :1 ;
        reg32_t s_UART :1 ;
      } u_B ;
   }
   s_UARTCR ;


   union
   { /* UART Mode Status Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :16 ;
        reg32_t s_SZF :1 ;
        reg32_t s_OCF :1 ;
        reg32_t s_PE :4 ;
        reg32_t s_RMB :1 ; /*  Release Message Buffer flag */
        reg32_t s_FEF :1 ;
        reg32_t s_BOF :1 ;
        reg32_t s_RDI :1 ;
        reg32_t s_WUF :1 ;
        reg32_t s_RFNE :1 ;
        reg32_t s_TO :1 ;
        reg32_t s_DRFRFE :1 ; /*  data reception completed flag */
        reg32_t s_DTFTFF :1 ;
        reg32_t s_NF :1 ;
      } u_B ;
   }
   s_UARTSR ;


   union
   { /* LIN Time-Out Control Status Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :21 ;
        reg32_t s_MODE :1 ;
        reg32_t s_IOT :1 ;
        reg32_t s_TOCE :1 ;
        reg32_t s_CNT :8 ;
      } u_B ;
   }
   s_LINTCSR ;


   union
   { /* LIN Output Compare Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :16 ;
        reg32_t s_OC2 :8 ;
        reg32_t s_OC1 :8 ;
      } u_B ;
   }
   s_LINOCR ;


   union
   { /* LIN Time-Out Control Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :20 ;
        reg32_t s_RTO :4 ;
        reg32_t s_RESERVE_2 :1 ;
        reg32_t s_HTO :7 ;
      } u_B ;
   }
   s_LINTOCR ;


   union

   { /* LIN Fractional Baud Rate Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :28 ;
        reg32_t s_FBR :4 ;
      } u_B ;
   }
   s_LINFBRR ;


   union
   { /* LIN Integer Baud Rate Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :12 ;
        reg32_t s_IBR :20 ;
      } u_B ;
   }
   s_LINIBRR ;

   union
   { /* LIN Checksum Field Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :24 ;
        reg32_t s_CF :8 ;
      } u_B ;
   }
   s_LINCFR ;


   union
   { /* LIN Control Register 2 */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :16 ;
        reg32_t s_TBDE :1 ;
        reg32_t s_IOBE :1 ;
        reg32_t s_IOPE :1 ;
        reg32_t s_WURQ :1 ;
        reg32_t s_DDRQ :1 ;
        reg32_t s_DTRQ :1 ;
        reg32_t s_ABRQ :1 ;
        reg32_t s_HTRQ :1 ;
        reg32_t s_RESERVE_1 :8 ;
      } u_B ;
   }
   s_LINCR2 ;


   union
   { /* Buffer Identifier Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :16 ;
        reg32_t s_DFL :6 ;
        reg32_t s_DIR :1 ;
        reg32_t s_CCS :1 ;
        reg32_t s_RESERVE_2 :2 ;
        reg32_t s_ID :6 ;
      } u_B ;
   }
   s_BIDR ;


   union
   { /* Buffer Data Register Least Significant */
      reg32_t u_R ;
      struct
      {
        reg32_t s_DATA3 :8 ;
        reg32_t s_DATA2 :8 ;
        reg32_t s_DATA1 :8 ;
        reg32_t s_DATA0 :8 ;
      } u_B ;
   }
   s_BDRL ;


   union
   { /* Buffer Data Register Most Significant */
      reg32_t u_R ;
      struct
      {
        reg32_t s_DATA7 :8 ;
        reg32_t s_DATA6 :8 ;
        reg32_t s_DATA5 :8 ;
        reg32_t s_DATA4 :8 ;
      } u_B ;
   }
   s_BDRM ;

   union
   { /* Identifier Filter Enable Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :16 ;
        reg32_t s_FACT :16 ;
      } u_B ;
   }
   s_IFER ;


   union
   { /* Identifier Filter Match Index */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :27 ;
        reg32_t s_IFMI :5 ;
      } u_B ;
   }
   s_IFMI ;


   union
   { /* Identifier Filter Mode Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :24 ;
        reg32_t s_IFM :8 ;
      } u_B ;
   }
   s_IFMR ;


   union
   { /* Identifier Filter Control Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :16 ;
        reg32_t s_DFL :6 ; /* Data Field Length */
        reg32_t s_DIR :1 ; /* Direction */
        reg32_t s_CCS :1 ; /* Classic Checksum */
        reg32_t s_RESERVE_2 :2 ;
        reg32_t s_ID :6 ; /* Identifier */
      } u_B ;
   }
   s_IFCR[16];
}
ts_UART_LINFlexD_COMMON_REG;

typedef struct
{
   union
   { /* Global Control Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :26 ;
        reg32_t s_TDFBM :1 ;
        reg32_t s_RDFBM :1 ;
        reg32_t s_TDLIS :1 ;
        reg32_t s_RDLIS :1 ;
        reg32_t s_STOP :1 ;
        reg32_t s_SR :1 ;
      } u_B ;
   }
   s_GCR ;


   union
   { /* UART Preset Timeout Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :20 ;
        reg32_t s_PTO :12 ;
      } u_B ;
   }
   s_UARTPTO ;


   union
   { /* UART Current Timeout Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :20 ;
        reg32_t s_CTO :12 ;
      } u_B ;
   }
   s_UARTCTO ;



   union
   { /* DMA Tx Enable Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :16 ;
        reg32_t s_DTE :16 ;
      } u_B ;
   }
   s_DMATXE ;


   union
   { /* DMA Rx Enable Register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :16 ;
        reg32_t s_DRE :16 ;
      } u_B ;
   }
   s_DMARXE ;

   union
   { /* PSI5-S Tx Delay register */
      reg32_t u_R ;
      struct
      {
        reg32_t s_RESERVE :27 ;
        reg32_t s_IFD :4 ;
        reg32_t s_EN :1 ;
      } u_B ;
   }
   s_PTD ;
}
ts_UART_LINFlexD_MASTER_REG;

/* }}<SYNCHRONe_C_Code_7.2> */

/* LINFlexD structure, merge of common + master (see in Reference Manual note at P.59.4 */
typedef struct
{
   volatile ts_UART_LINFlexD_COMMON_REG * s_uart_common_reg;
   volatile ts_UART_LINFlexD_MASTER_REG * s_uart_master_reg;
}
ts_UART_LINFlexD_REG;

#endif /* UART_REG_PUBLIC_H */
