#ifndef DMA_CFEX_COMMON_H
#define DMA_CFEX_COMMON_H

/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS
 * CSU name :
 * %name: DMA_CFEX_public.h %
 * %full_name: fadex#8/incl/DMA_CFEX_public.h/1 %
 *
 * Creation information:
 *   Created by: F073297
 *   Date : Thu May 31 09:55:02 CEST 2018
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:18:09 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"
#include "DMA_REG_common.h"
#include "DMA_HAL_public.h"

/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */

/* ---------- provided define constants: ------------------------------------ */
/* {{RELAX<SYNCHRONe_C_Code_8.17>: This is a full description of the DMA capability, so all enumerate does not need to be used. */

/* DMA number */
typedef enum
{
   e_DMA_CFEX_DMA_0 = 0,
   e_DMA_CFEX_DMA_1 = 1
}
te_DMA_CFEX_DMA_NB;

/* DMA line number */
typedef enum
{
   e_DMA_CFEX_DMA_LINE_0  = 0,      /* DMA Line 0  */
   e_DMA_CFEX_DMA_LINE_1  = 1,      /* DMA Line 1  */
   e_DMA_CFEX_DMA_LINE_2  = 2,      /* DMA Line 2  */
   e_DMA_CFEX_DMA_LINE_3  = 3,      /* DMA Line 3  */
   e_DMA_CFEX_DMA_LINE_4  = 4,      /* DMA Line 4  */
   e_DMA_CFEX_DMA_LINE_5  = 5,      /* DMA Line 5  */
   e_DMA_CFEX_DMA_LINE_6  = 6,      /* DMA Line 6  */
   e_DMA_CFEX_DMA_LINE_7  = 7,      /* DMA Line 7  */
   e_DMA_CFEX_DMA_LINE_8  = 8,      /* DMA Line 8  */
   e_DMA_CFEX_DMA_LINE_9  = 9,      /* DMA Line 9  */
   e_DMA_CFEX_DMA_LINE_10 = 10,     /* DMA Line 10 */
   e_DMA_CFEX_DMA_LINE_11 = 11,     /* DMA Line 11 */
   e_DMA_CFEX_DMA_LINE_12 = 12,     /* DMA Line 12 */
   e_DMA_CFEX_DMA_LINE_13 = 13,     /* DMA Line 13 */
   e_DMA_CFEX_DMA_LINE_14 = 14,     /* DMA Line 14 */
   e_DMA_CFEX_DMA_LINE_15 = 15,     /* DMA Line 15 */
   e_DMA_CFEX_DMA_LINE_16 = 16,     /* DMA Line 16 */
   e_DMA_CFEX_DMA_LINE_17 = 17,     /* DMA Line 17 */
   e_DMA_CFEX_DMA_LINE_18 = 18,     /* DMA Line 18 */
   e_DMA_CFEX_DMA_LINE_19 = 19,     /* DMA Line 19 */
   e_DMA_CFEX_DMA_LINE_20 = 20,     /* DMA Line 20 */
   e_DMA_CFEX_DMA_LINE_21 = 21,     /* DMA Line 21 */
   e_DMA_CFEX_DMA_LINE_22 = 22,     /* DMA Line 22 */
   e_DMA_CFEX_DMA_LINE_23 = 23,     /* DMA Line 23 */
   e_DMA_CFEX_DMA_LINE_24 = 24,     /* DMA Line 24 */
   e_DMA_CFEX_DMA_LINE_25 = 25,     /* DMA Line 25 */
   e_DMA_CFEX_DMA_LINE_26 = 26,     /* DMA Line 26 */
   e_DMA_CFEX_DMA_LINE_27 = 27,     /* DMA Line 27 */
   e_DMA_CFEX_DMA_LINE_28 = 28,     /* DMA Line 28 */
   e_DMA_CFEX_DMA_LINE_29 = 29,     /* DMA Line 29 */
   e_DMA_CFEX_DMA_LINE_30 = 30,     /* DMA Line 30 */
   e_DMA_CFEX_DMA_LINE_31 = 31,     /* DMA Line 31 */
   e_DMA_CFEX_DMA_LINE_32 = 32,     /* DMA Line 32 */
   e_DMA_CFEX_DMA_LINE_33 = 33,     /* DMA Line 33 */
   e_DMA_CFEX_DMA_LINE_34 = 34,     /* DMA Line 34 */
   e_DMA_CFEX_DMA_LINE_35 = 35,     /* DMA Line 35 */
   e_DMA_CFEX_DMA_LINE_36 = 36,     /* DMA Line 36 */
   e_DMA_CFEX_DMA_LINE_37 = 37,     /* DMA Line 37 */
   e_DMA_CFEX_DMA_LINE_38 = 38,     /* DMA Line 38 */
   e_DMA_CFEX_DMA_LINE_39 = 39,     /* DMA Line 39 */
   e_DMA_CFEX_DMA_LINE_40 = 40,     /* DMA Line 40 */
   e_DMA_CFEX_DMA_LINE_41 = 41,     /* DMA Line 41 */
   e_DMA_CFEX_DMA_LINE_42 = 42,     /* DMA Line 42 */
   e_DMA_CFEX_DMA_LINE_43 = 43,     /* DMA Line 43 */
   e_DMA_CFEX_DMA_LINE_44 = 44,     /* DMA Line 44 */
   e_DMA_CFEX_DMA_LINE_45 = 45,     /* DMA Line 45 */
   e_DMA_CFEX_DMA_LINE_46 = 46,     /* DMA Line 46 */
   e_DMA_CFEX_DMA_LINE_47 = 47,     /* DMA Line 47 */
   e_DMA_CFEX_DMA_LINE_48 = 48,     /* DMA Line 48 */
   e_DMA_CFEX_DMA_LINE_49 = 49,     /* DMA Line 49 */
   e_DMA_CFEX_DMA_LINE_50 = 50,     /* DMA Line 50 */
   e_DMA_CFEX_DMA_LINE_51 = 51,     /* DMA Line 51 */
   e_DMA_CFEX_DMA_LINE_52 = 52,     /* DMA Line 52 */
   e_DMA_CFEX_DMA_LINE_53 = 53,     /* DMA Line 53 */
   e_DMA_CFEX_DMA_LINE_54 = 54,     /* DMA Line 54 */
   e_DMA_CFEX_DMA_LINE_55 = 55,     /* DMA Line 55 */
   e_DMA_CFEX_DMA_LINE_56 = 56,     /* DMA Line 56 */
   e_DMA_CFEX_DMA_LINE_57 = 57,     /* DMA Line 57 */
   e_DMA_CFEX_DMA_LINE_58 = 58,     /* DMA Line 58 */
   e_DMA_CFEX_DMA_LINE_59 = 59,     /* DMA Line 59 */
   e_DMA_CFEX_DMA_LINE_60 = 60,     /* DMA Line 60 */
   e_DMA_CFEX_DMA_LINE_61 = 61,     /* DMA Line 61 */
   e_DMA_CFEX_DMA_LINE_62 = 62,     /* DMA Line 62 */
   e_DMA_CFEX_DMA_LINE_63 = 63      /* DMA Line 63 */
}
te_DMA_CFEX_DMA_LINE;

/* DMA mux number */
typedef enum
{
   e_DMA_CFEX_MUX_0  = 0,           /* MUX Line 0  */
   e_DMA_CFEX_MUX_1  = 1,           /* MUX Line 1  */
   e_DMA_CFEX_MUX_2  = 2,           /* MUX Line 2  */
   e_DMA_CFEX_MUX_3  = 3,           /* MUX Line 3  */
   e_DMA_CFEX_MUX_4  = 4,           /* MUX Line 4  */
   e_DMA_CFEX_MUX_5  = 5,           /* MUX Line 5  */
   e_DMA_CFEX_MUX_6  = 6,           /* MUX Line 6  */
   e_DMA_CFEX_MUX_7  = 7,           /* MUX Line 7  */
   e_DMA_CFEX_MUX_8  = 8,           /* MUX Line 8  */
   e_DMA_CFEX_MUX_9  = 9            /* MUX Line 9  */
}
te_DMA_CFEX_MUX_NB;

/* DMA mux line number */
typedef enum
{
   e_DMA_CFEX_MUX_LINE_0  = 0,      /* MUX Line 0  */
   e_DMA_CFEX_MUX_LINE_1  = 1,      /* MUX Line 1  */
   e_DMA_CFEX_MUX_LINE_2  = 2,      /* MUX Line 2  */
   e_DMA_CFEX_MUX_LINE_3  = 3,      /* MUX Line 3  */
   e_DMA_CFEX_MUX_LINE_4  = 4,      /* MUX Line 4  */
   e_DMA_CFEX_MUX_LINE_5  = 5,      /* MUX Line 5  */
   e_DMA_CFEX_MUX_LINE_6  = 6,      /* MUX Line 6  */
   e_DMA_CFEX_MUX_LINE_7  = 7,      /* MUX Line 7  */
   e_DMA_CFEX_MUX_LINE_8  = 8,      /* MUX Line 8  */
   e_DMA_CFEX_MUX_LINE_9  = 9,      /* MUX Line 9  */
   e_DMA_CFEX_MUX_LINE_10 = 10,     /* MUX Line 10 */
   e_DMA_CFEX_MUX_LINE_11 = 11,     /* MUX Line 11 */
   e_DMA_CFEX_MUX_LINE_12 = 12,     /* MUX Line 12 */
   e_DMA_CFEX_MUX_LINE_13 = 13,     /* MUX Line 13 */
   e_DMA_CFEX_MUX_LINE_14 = 14,     /* MUX Line 14 */
   e_DMA_CFEX_MUX_LINE_15 = 15      /* MUX Line 15 */
}
te_DMA_CFEX_MUX_LINE_NB;

/* DMA mux source number       */
typedef enum
{
   e_DMA_CFEX_MUX_SOURCE_0  = 0,    /* MUX Source 0  */
   e_DMA_CFEX_MUX_SOURCE_1  = 1,    /* MUX Source 1  */
   e_DMA_CFEX_MUX_SOURCE_2  = 2,    /* MUX Source 2  */
   e_DMA_CFEX_MUX_SOURCE_3  = 3,    /* MUX Source 3  */
   e_DMA_CFEX_MUX_SOURCE_4  = 4,    /* MUX Source 4  */
   e_DMA_CFEX_MUX_SOURCE_5  = 5,    /* MUX Source 5  */
   e_DMA_CFEX_MUX_SOURCE_6  = 6,    /* MUX Source 6  */
   e_DMA_CFEX_MUX_SOURCE_7  = 7,    /* MUX Source 7  */
   e_DMA_CFEX_MUX_SOURCE_8  = 8,    /* MUX Source 8  */
   e_DMA_CFEX_MUX_SOURCE_9  = 9,    /* MUX Source 9  */
   e_DMA_CFEX_MUX_SOURCE_10 = 10,   /* MUX Source 10 */
   e_DMA_CFEX_MUX_SOURCE_11 = 11,   /* MUX Source 11 */
   e_DMA_CFEX_MUX_SOURCE_12 = 12,   /* MUX Source 12 */
   e_DMA_CFEX_MUX_SOURCE_13 = 13,   /* MUX Source 13 */
   e_DMA_CFEX_MUX_SOURCE_14 = 14,   /* MUX Source 14 */
   e_DMA_CFEX_MUX_SOURCE_15 = 15,   /* MUX Source 15 */
   e_DMA_CFEX_MUX_SOURCE_16 = 16,   /* MUX Source 16 */
   e_DMA_CFEX_MUX_SOURCE_17 = 17,   /* MUX Source 17 */
   e_DMA_CFEX_MUX_SOURCE_18 = 18,   /* MUX Source 18 */
   e_DMA_CFEX_MUX_SOURCE_19 = 19,   /* MUX Source 19 */
   e_DMA_CFEX_MUX_SOURCE_20 = 20,   /* MUX Source 20 */
   e_DMA_CFEX_MUX_SOURCE_21 = 21,   /* MUX Source 21 */
   e_DMA_CFEX_MUX_SOURCE_22 = 22,   /* MUX Source 22 */
   e_DMA_CFEX_MUX_SOURCE_23 = 23,   /* MUX Source 23 */
   e_DMA_CFEX_MUX_SOURCE_24 = 24,   /* MUX Source 24 */
   e_DMA_CFEX_MUX_SOURCE_25 = 25,   /* MUX Source 25 */
   e_DMA_CFEX_MUX_SOURCE_26 = 26,   /* MUX Source 26 */
   e_DMA_CFEX_MUX_SOURCE_27 = 27,   /* MUX Source 27 */
   e_DMA_CFEX_MUX_SOURCE_28 = 28,   /* MUX Source 28 */
   e_DMA_CFEX_MUX_SOURCE_29 = 29,   /* MUX Source 29 */
   e_DMA_CFEX_MUX_SOURCE_30 = 30,   /* MUX Source 30 */
   e_DMA_CFEX_MUX_SOURCE_31 = 31,   /* MUX Source 31 */
   e_DMA_CFEX_MUX_SOURCE_32 = 32,   /* MUX Source 32 */
   e_DMA_CFEX_MUX_SOURCE_33 = 33,   /* MUX Source 33 */
   e_DMA_CFEX_MUX_SOURCE_34 = 34,   /* MUX Source 34 */
   e_DMA_CFEX_MUX_SOURCE_35 = 35,   /* MUX Source 35 */
   e_DMA_CFEX_MUX_SOURCE_36 = 36,   /* MUX Source 36 */
   e_DMA_CFEX_MUX_SOURCE_37 = 37,   /* MUX Source 37 */
   e_DMA_CFEX_MUX_SOURCE_38 = 38,   /* MUX Source 38 */
   e_DMA_CFEX_MUX_SOURCE_39 = 39,   /* MUX Source 39 */
   e_DMA_CFEX_MUX_SOURCE_40 = 40,   /* MUX Source 40 */
   e_DMA_CFEX_MUX_SOURCE_41 = 41,   /* MUX Source 41 */
   e_DMA_CFEX_MUX_SOURCE_42 = 42,   /* MUX Source 42 */
   e_DMA_CFEX_MUX_SOURCE_43 = 43,   /* MUX Source 43 */
   e_DMA_CFEX_MUX_SOURCE_44 = 44,   /* MUX Source 44 */
   e_DMA_CFEX_MUX_SOURCE_45 = 45,   /* MUX Source 45 */
   e_DMA_CFEX_MUX_SOURCE_46 = 46,   /* MUX Source 46 */
   e_DMA_CFEX_MUX_SOURCE_47 = 47,   /* MUX Source 47 */
   e_DMA_CFEX_MUX_SOURCE_48 = 48,   /* MUX Source 48 */
   e_DMA_CFEX_MUX_SOURCE_49 = 49,   /* MUX Source 49 */
   e_DMA_CFEX_MUX_SOURCE_50 = 50,   /* MUX Source 50 */
   e_DMA_CFEX_MUX_SOURCE_51 = 51,   /* MUX Source 51 */
   e_DMA_CFEX_MUX_SOURCE_52 = 52,   /* MUX Source 52 */
   e_DMA_CFEX_MUX_SOURCE_53 = 53,   /* MUX Source 53 */
   e_DMA_CFEX_MUX_SOURCE_54 = 54,   /* MUX Source 54 */
   e_DMA_CFEX_MUX_SOURCE_55 = 55,   /* MUX Source 55 */
   e_DMA_CFEX_MUX_SOURCE_56 = 56,   /* MUX Source 56 */
   e_DMA_CFEX_MUX_SOURCE_57 = 57,   /* MUX Source 57 */
   e_DMA_CFEX_MUX_SOURCE_58 = 58,   /* MUX Source 58 */
   e_DMA_CFEX_MUX_SOURCE_59 = 59,   /* MUX Source 59 */
   e_DMA_CFEX_MUX_SOURCE_60 = 60,   /* MUX Source 60 */
   e_DMA_CFEX_MUX_SOURCE_61 = 61,   /* MUX Source 61 */
   e_DMA_CFEX_MUX_SOURCE_62 = 62,   /* MUX Source 62 */
   e_DMA_CFEX_MUX_SOURCE_63 = 63    /* MUX Source 63 */
}
te_DMA_CFEX_MUX_SOURCE_NB;

/* DMA Mode       */
typedef enum
{
   e_DMA_CFEX_MODE_LOOP     = 0,
   e_DMA_CFEX_MODE_ONE_SHOT = 1
}
te_DMA_CFEX_MODE_LOOP;

/* Supported maximum number of DMA */
#define DMA_CFEX_MAX_NB   128

/* DMA Priority */
typedef enum
{
   e_P_00 = 0,      /* PRIORITY 0  */
   e_P_01 = 1,      /* PRIORITY 1  */
   e_P_02 = 2,      /* PRIORITY 2  */
   e_P_03 = 3,      /* PRIORITY 3  */
   e_P_04 = 4,      /* PRIORITY 4  */
   e_P_05 = 5,      /* PRIORITY 5  */
   e_P_06 = 6,      /* PRIORITY 6  */
   e_P_07 = 7,      /* PRIORITY 7  */
   e_P_08 = 8,      /* PRIORITY 8  */
   e_P_09 = 9,      /* PRIORITY 9  */
   e_P_10 = 10,     /* PRIORITY 10 */
   e_P_11 = 11,     /* PRIORITY 11 */
   e_P_12 = 12,     /* PRIORITY 12 */
   e_P_13 = 13,     /* PRIORITY 13 */
   e_P_14 = 14,     /* PRIORITY 14 */
   e_P_15 = 15      /* PRIORITY 15 */
}
te_DMA_CFEX_PRIORITY;

/* }}<SYNCHRONe_C_Code_8.17> */


/* ---------- provided types: ----------------------------------------------- */
/* */
/* DMA descriptor table */
typedef struct
{
   /* DMA number address */
   /* eDMA_0 or eDMA_1   */
   ts_DMA_REG volatile * s_dma_addr;
   /* DMA line number */
   /* Line [0..63]    */
   te_DMA_CFEX_DMA_LINE s_line_nb;
}
ts_DMA_DESCR;

/* */
/* Description of the DMA element */
typedef struct
{
   /* DMA number       */
   /* eDMA_0 or eDMA_1 */
   te_DMA_CFEX_DMA_NB s_dma_nb;
   /* DMA line number */
   /* Line [0..63]    */
   te_DMA_CFEX_DMA_LINE s_dma_line_nb;
   /* DMA mux number */
   /* Mux [0..9]     */
   te_DMA_CFEX_MUX_NB s_dma_mux_nb;
   /* DMA mux line number */
   /* Mux Line [0..15]    */
   te_DMA_CFEX_MUX_LINE_NB s_dma_mux_line_nb;
   /* DMA mux source number */
   /* Mux Source [0..63]    */
   te_DMA_CFEX_MUX_SOURCE_NB s_dma_mux_source_nb;
}
ts_DMA_CFEX_ELT;


/* ---------- provided constants: ------------------------------------------- */
/* */
/* DMA configuration table */


extern const te_DMA_CFEX_PRIORITY c_DMA_CFEX_PRIORITY_tab[ DMA_MAX_NB * DMA_LINE_MAX_NB];

/* {{RELAX<SYNCHRONe_C_Code_8.12, SYNCHRONe_C_Code_8.16> : the table c_DMA_CFEX_tab and DMA_descr share the same size : c_DMA_CFEX_tab_SIZE. This size is a integration value so the table are declared without a size. */
extern const uint32_t c_DMA_CFEX_tab_SIZE;
extern const ts_DMA_CFEX_ELT c_DMA_CFEX_tab[];

/* ---------- provided data: ------------------------------------------------ */
/* */
/* DMA descriptor */
extern ts_DMA_DESCR DMA_descr[];
/* }}<SYNCHRONe_C_Code_8.12, SYNCHRONe_C_Code_8.16> */

/* ---------- provided operations: ------------------------------------------ */
/* none */

#endif /* DMA_CFEX_COMMON_H */
