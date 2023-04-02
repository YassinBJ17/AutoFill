#ifndef HWCRC_CFEX_PUBLIC_H
#define HWCRC_CFEX_PUBLIC_H

/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS
 * CSU name :
 * %name: HWCRC_CFEX_public.h %
 * %full_name: fadex#1/incl/HWCRC_CFEX_public.h/1 %
 *
 * Creation information:
 *   Created by: F073297
 *   Date : Thu May 31 09:55:02 CEST 2018
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:18:30 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"

/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */

/* ---------- provided define constants: ------------------------------------ */
/* CTAR number */
#define HWCRC_CFEX_CTAR_NB        8ul

/* Length of FIFO RX and TX */
#define HWCRC_CFEX_FIFO_SIZE      4ul
/* Length of DATA RX and TX */
#define HWCRC_CFEX_DATA_SIZE      1ul     /* 8 bits = 1 octet */
/* Length of CMD TX */
#define HWCRC_CFEX_CMD_SIZE       2ul     /* 16 bits = 2 octets */
/* Length of CMD & DATA TX */
#define HWCRC_CFEX_CMD_DATA_SIZE  (HWCRC_CFEX_CMD_SIZE + HWCRC_CFEX_DATA_SIZE)

/* HWCRC register RX offset */
#define HWCRC_REG_RX_OFFSET       0x00000038ul
/* HWCRC register TX offset */
#define HWCRC_REG_TX_OFFSET       0x00000034ul


/* ---------- provided types: ----------------------------------------------- */

/* */
typedef enum
{
   /* HWCRC 0  */
   e_HWCRC_CFEX_MODULE_0  = 0,
   /* HWCRC 1  */
   e_HWCRC_CFEX_MODULE_1  = 1
}
te_HWCRC_CFEX_MODULE_NB;


typedef enum
{
   /* */
   e_HWCRC_CFEX_CRC_CCITT_POLY = 0,
   /* */
   e_HWCRC_CFEX_CRC32_POLY = 1,
   /* */
   e_HWCRC_CFEX_CRC8_POLY = 2
}
te_HWCRC_CFEX_CRC_POLYNOME;

/* */
typedef enum
{
   /* */
   e_HWCRC_CFEX_TRANSFER_MODE_SW  = 0,
   /* */
   e_HWCRC_CFEX_TRANSFER_MODE_DMA  = 1
}
te_HWCRC_CFEX_TRANSFER_MODE;

/* */
/* Physical description of one HWCRC */
typedef struct
{
   /* HWRCRC module number */
	te_HWCRC_CFEX_MODULE_NB        s_module_nb;
   /* CRC Polynome mode */
	te_HWCRC_CFEX_CRC_POLYNOME     s_crc_poly;
   /* Transfer mode */
	te_HWCRC_CFEX_TRANSFER_MODE    s_transfer_mode;
   /* DMA line number */
   uint32_t                        s_dma_conf_nb;
}
ts_HWCRC_CFEX_ELT;

/* */
typedef struct
{
   /* Register s_address */
   CMN_SYSTEM_ADDR_VAL_t        s_address;
   /* DMA line number */
   uint32_t                     s_dma_conf_nb;
}
ts_HWCRC_CONFIG_DESC;


/* ---------- provided constants: ------------------------------------------- */
/* */


/* {{RELAX<SYNCHRONe_C_Code_8.12, SYNCHRONe_C_Code_8.16> : the table c_HWCRC_CFEX_CONFIGURATION_tab and HWCRC_CFEX_descriptor_tab share the same size : c_HWCRC_CFEX_tab_SIZE. This size is a integration value so the table are declared without a size. */
extern const uint32_t c_HWCRC_CFEX_tab_SIZE;
extern const ts_HWCRC_CFEX_ELT c_HWCRC_CFEX_CONFIGURATION_tab[];

/* ---------- provided data: ------------------------------------------------ */
/* */
/* HWCRC descriptor */
extern ts_HWCRC_CONFIG_DESC HWCRC_CFEX_descriptor_tab[];
/* }}<SYNCHRONe_C_Code_8.12, SYNCHRONe_C_Code_8.16> */

/* ---------- provided operations: ------------------------------------------ */
/* */
#endif /* HWCRC_CFEX_PUBLIC_H */
