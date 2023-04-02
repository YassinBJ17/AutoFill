/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef BOOT_FCCU_ERR_SRC_REG_PRIVATE_H
#define BOOT_FCCU_ERR_SRC_REG_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "CMN_TYPES_common.h"

/* ---------- Linker command file symbol: ----------------------------------- */
/* none */

/* ---------- provided define constants: ------------------------------------ */


/*****************************************************************************/
/*****                        FCCU Error sources                          ****/
/*****************************************************************************/

#define PMCDIG_EPR_VD3_CLEAR_VAL    ((uint32_t)0x000000C1)
#define PMCDIG_EPR_VD4_CLEAR_VAL    ((uint32_t)0x00000001)
#define PMCDIG_EPR_VD7_CLEAR_VAL    ((uint32_t)0x00000001)
#define PMCDIG_EPR_VD8_CLEAR_VAL    ((uint32_t)0x00000041)
#define PMCDIG_EPR_VD9_CLEAR_VAL    ((uint32_t)0x00004F49)
#define PMCDIG_EPR_VD10_CLEAR_VAL   ((uint32_t)0x00008040)
#define PMCDIG_EPR_VD12_CLEAR_VAL   ((uint32_t)0x00000040)
#define PMCDIG_EPR_VD13_CLEAR_VAL   ((uint32_t)0x00000100)
#define PMCDIG_EPR_VD14_CLEAR_VAL   ((uint32_t)0x00008100)
#define PMCDIG_EPR_VD15_CLEAR_VAL   ((uint32_t)0x00008001)
#define PMCDIG_EPR_TD_CLEAR_VAL     ((uint32_t)0xD)

/* CMU_0 = CMU_PLL */
#define CMU_PLL_CMU_ISR             (*(reg32_t *)(0xFFFB0210))
#define CMU_PLL_CMU_ISR_CLEAR_VAL   ((uint32_t)0x00000007)

/* MCU IMA */
#define IMA_SLCT                    (*(reg32_t *) (0xFFF5400C))
#define IMA_SLCT_CLEAR_VAL          ((uint32_t)0xFFFFFFC0)

/* MCR */
#define C55FMC_MCR                  (* (volatile reg32_t *) (0xFFFE0000))
#define C55FMC_MCR_CLEAR_VAL        ((uint32_t)0xc0000000)

/* MEMU */
#define MEMU_ERR_FLAG               (* (volatile reg32_t *) (0xFFF50004))
#define MEMU_ERR_FLAG_CLEAR_VAL     ((uint32_t)0x001F1F1F)

/* SSCM Registers addresses */
#define SSCM_STATUS                 (*(volatile reg16_t *)(0xFFFF8000))
#define SSCM_STATUS_CLEAR_VAL       ((reg16_t)0x4000)

/* Error 36 dummy read (Read one byte (one word is the same)) of the flash memory to clear the error */
#define FLASH_ADDR_DUMMY_READ       (*(volatile uint32_t *) (0x00FC0260))

/* FI[0]*/
/* #define FI_0 */

#define STCU2_UFSF_RFSF_CLEAR       ((uint32_t)0x0)

/* ---------- provided types: ----------------------------------------------- */

/* ---------------------------------------------------------------------------*/
/*                                    STCU2                                   */
/* ---------------------------------------------------------------------------*/
typedef struct
{
   reg32_t :6;
   reg32_t s_ABORTHW:1;
   reg32_t s_ABORTSW:1;
   reg32_t :3;
   reg32_t s_LOCKESW:1;
   reg32_t s_WDTOSW:1;
   reg32_t s_CRCSSW:1;
   reg32_t s_ENGESW:1;
   reg32_t s_INVPSW:1;
   reg32_t :6;
   reg32_t s_UFSF:1;
   reg32_t s_RFSF:1;
   reg32_t :3;
   reg32_t s_LOCKE:1;
   reg32_t s_WDTO:1;
   reg32_t s_CRCS:1;
   reg32_t s_ENGE:1;
   reg32_t s_INVP:1;
}
ts_STCU2_ERR_STAT_tag;

#define STCU2_ERR_STAT              (*(volatile ts_STCU2_ERR_STAT_tag *)(0xFFF44024))
#define STCU2_ERR_STAT_UFSF         STCU2_ERR_STAT.s_UFSF
#define STCU2_ERR_STAT_RFSF         STCU2_ERR_STAT.s_RFSF

/* ---------------------------------------------------------------------------*/
/*                                   PMCDIG                                   */
/* ---------------------------------------------------------------------------*/

#define PMCDIG_REG_RESERVEDA_SIZE (36)
#define PMCDIG_REG_RESERVEDB_SIZE (31)
#define PMCDIG_REG_RESERVEDC_SIZE (15)
#define PMCDIG_REG_RESERVEDD_SIZE (3)
#define PMCDIG_REG_RESERVEDE_SIZE (503)
#define PMCDIG_REG_RESERVEDF_SIZE (7)
#define PMCDIG_REG_RESERVEDG_SIZE (35)
#define PMCDIG_REG_RESERVEDH_SIZE (3)

typedef struct
{

   reg32_t s_PMCDIG_GR_S;
   reg32_t s_PMCDIG_GR_P;
   reg32_t s_PMCDIG_IE_P;

   uint8_t s_reserved_A[PMCDIG_REG_RESERVEDA_SIZE];

   reg32_t s_PMCDIG_EPR_VD3;
   reg32_t s_PMCDIG_REE_VD3;
   reg32_t s_PMCDIG_RES_VD3;
   reg32_t s_PMCDIG_FEE_VD3;

   reg32_t s_PMCDIG_EPR_VD4;
   reg32_t s_PMCDIG_REE_VD4;
   reg32_t s_PMCDIG_RES_VD4;
   reg32_t s_PMCDIG_FEE_VD4;

   uint8_t s_reserved_B[PMCDIG_REG_RESERVEDB_SIZE];

   reg32_t s_PMCDIG_EPR_VD7;
   reg32_t s_PMCDIG_REE_VD7;
   reg32_t s_PMCDIG_RES_VD7;
   reg32_t s_PMCDIG_FEE_VD7;

   reg32_t s_PMCDIG_EPR_VD8;
   reg32_t s_PMCDIG_REE_VD8;
   reg32_t s_PMCDIG_RES_VD8;
   reg32_t s_PMCDIG_FEE_VD8;

   reg32_t s_PMCDIG_EPR_VD9;
   reg32_t s_PMCDIG_REE_VD9;
   reg32_t s_PMCDIG_RES_VD9;
   reg32_t s_PMCDIG_FEE_VD9;

   reg32_t s_PMCDIG_EPR_VD10;
   reg32_t s_PMCDIG_REE_VD10;
   reg32_t s_PMCDIG_RES_VD10;
   reg32_t s_PMCDIG_FEE_VD10;

   uint8_t s_reserved_C[PMCDIG_REG_RESERVEDC_SIZE];

   reg32_t s_PMCDIG_EPR_VD12;
   reg32_t s_PMCDIG_REE_VD12;
   reg32_t s_PMCDIG_RES_VD12;
   reg32_t s_PMCDIG_FEE_VD12;

   reg32_t s_PMCDIG_EPR_VD13;
   reg32_t s_PMCDIG_REE_VD13;
   reg32_t s_PMCDIG_RES_VD13;
   reg32_t s_PMCDIG_FEE_VD13;

   reg32_t s_PMCDIG_EPR_VD14;
   reg32_t s_PMCDIG_REE_VD14;
   reg32_t s_PMCDIG_RES_VD14;
   reg32_t s_PMCDIG_FEE_VD14;

   reg32_t s_PMCDIG_EPR_VD15;
   reg32_t s_PMCDIG_REE_VD15;
   reg32_t s_PMCDIG_RES_VD15;
   reg32_t s_PMCDIG_FEE_VD15;

   uint8_t s_reserved_D[PMCDIG_REG_RESERVEDD_SIZE];

   reg32_t s_PMCDIG_VSIO;
   uint8_t s_reserved_E[PMCDIG_REG_RESERVEDE_SIZE];

   reg32_t s_PMCDIG_EPR_TD;
   reg32_t s_PMCDIG_REE_TD;
   reg32_t s_PMCDIG_RES_TD;
   reg32_t s_PMCDIG_CTL_TD;

   uint8_t s_reserved_F[PMCDIG_REG_RESERVEDF_SIZE];

   reg32_t s_PMCDIG_FEE_TD;

   uint8_t s_reserved_G[PMCDIG_REG_RESERVEDG_SIZE];

   reg32_t s_PMCDIG_VD_UTST;
   reg32_t s_PMCDIG_ADC_CH;

   uint8_t s_reserved_H[PMCDIG_REG_RESERVEDH_SIZE];

   reg32_t s_PMCDIG_VREG1P2_CTRL;
   reg32_t s_PMCDIG_MCR;
}
ts_PMCDIG_tag;

#define PMCDIG                      (*(volatile ts_PMCDIG_tag *) 0xFFFA0400)
#define PMCDIG_EPR_VD3              (PMCDIG.s_PMCDIG_EPR_VD3)
#define PMCDIG_EPR_VD4              (PMCDIG.s_PMCDIG_EPR_VD4)
#define PMCDIG_EPR_VD7              (PMCDIG.s_PMCDIG_EPR_VD7)
#define PMCDIG_EPR_VD8              (PMCDIG.s_PMCDIG_EPR_VD8)
#define PMCDIG_EPR_VD9              (PMCDIG.s_PMCDIG_EPR_VD9)
#define PMCDIG_EPR_VD10             (PMCDIG.s_PMCDIG_EPR_VD10)
#define PMCDIG_EPR_VD12             (PMCDIG.s_PMCDIG_EPR_VD12)
#define PMCDIG_EPR_VD13             (PMCDIG.s_PMCDIG_EPR_VD13)
#define PMCDIG_EPR_VD14             (PMCDIG.s_PMCDIG_EPR_VD14)
#define PMCDIG_EPR_VD15             (PMCDIG.s_PMCDIG_EPR_VD15)
#define PMCDIG_EPR_TD               (PMCDIG.s_PMCDIG_EPR_TD)

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- provided operations: ------------------------------------------ */
/* none */


#endif /* BOOT_FCCU_ERR_SRC_REG_PRIVATE_H */

