#ifndef BOOT_BIST_public_H
#define BOOT_BIST_public_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */



/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"
#include "BOOT_BIST_CFEX_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* STCU2 register base address */
#define STCU2_BASE_ADDR           (uint32_t)0xFFF44000

/* STCU2 security key code 1 */
#define STCU2_SKC_1               (uint32_t)0x753F924E

/* STCU2 security key code 2 */
#define STCU2_SKC_2               (uint32_t)0x8AC06DB1

/* ---------- internal types: ----------------------------------------------- */

/* ============================================================================
=============================== Module: STCU2 ==============================
============================================================================ */
typedef struct
{
   /* STCU2 Run Register */
   reg32_t RUN;

   union
   {               /* STCU2 Run Software Register */
      reg32_t R;
      struct
      {
         reg32_t  :20;
         reg32_t MBIE:1;
         reg32_t LBIE:1;
         reg32_t MBSWPLLEN:1;
         reg32_t LBSWPLLEN:1;
         reg32_t  :6;
         reg32_t RUNSW_ABORT:1;
         reg32_t RUNSW:1;
      } B;
   } RUNSW;

   /* STCU2 SK Code Register */
   reg32_t SKC; 
   /* STCU2 Configuration Register */
   reg32_t CFG;
   /* STCU2 PLL Configuration Register */
   reg32_t PLL_CFG; 
   /* STCU2 Watchdog Register Granularity */
   reg32_t WDG;
   reg32_t s_regs_A [3];
   reg32_t s_ERR_STAT;
   /* STCU2 Error FM Register */
   reg32_t ERR_FM;
   reg32_t s_regs_B[2];
   /* STCU2 On-Line LBIST Status Register */
   reg32_t LBSSW;
   /* STCU2 On-Line LBIST End Flag Register */
   reg32_t LBESW;
   /* STCU2 On-Line LBIST Reset Management */
   reg32_t LBRMSW;
   /* STCU2 LBIST Unrecoverable FM Register */
   reg32_t LBUFM;
   reg32_t s_regs_C[6];
   /* STCU2 On-Line MBIST Status Low Register */
   reg32_t MBSLSW;
   /* STCU2 On-Line MBIST Status Medium Register */
   reg32_t MBSMSW;
   /* STCU2 On-Line MBIST Status High Register */
   reg32_t MBSHSW;
   /* STCU2 On-Line MBIST End Flag Low Register */
   reg32_t MBELSW;
   /* STCU2 On-Line MBIST End Flag Medium Register */
   reg32_t MBEMSW;
   /* STCU2 On-Line MBIST End Flag High Register */
   reg32_t MBEHSW;
   /* STCU2 MBIST Unrecoverable FM Low Register */
   reg32_t MBUFML;
   /* STCU2 MBIST Unrecoverable FM Medium Register */
   reg32_t MBUFMM;
   /* STCU2 MBIST Unrecoverable FM High Register */
   reg32_t MBUFMH;
   reg8_t STCU2_reserved0[128];
   struct
   {
      /* STCU2 LBIST Control Register */
      reg32_t LB_CTRL;
      /* STCU2 LBIST PC Stop Register */
      reg32_t LB_PCS; 
      reg32_t s_regs_D[2];
      /* STCU2 Off-Line LBIST MISR Expected Low Register */
      reg32_t LB_MISREL;      
      /* STCU2 Off-Line LBIST MISR Expected High Register */
      reg32_t LB_MISREH;      
      reg32_t s_regs_E[2];
      /* STCU2 On-Line LBIST MISR Expected Low Register */
      reg32_t LB_MISRELSW;
      /* STCU2 On-Line LBIST MISR Expected High Register */
      reg32_t LB_MISREHSW;
      reg32_t s_regs_F[2];
      reg8_t LB_reserved0[16];
   } LB[10];

   reg8_t STCU2_reserved1[640];
   /* STCU2 MBIST Control Register */
   reg32_t MB_CTRL[78];
} ts_STCU2_REG;


/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal datas: ----------------------------------------------- */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */
/* none */

/* --------------------------- Function Prototypes --------------------------------------------------*/

extern void BOOT_BIST_END(void);

extern void BOOT_BIST_START(void);

#endif /* BOOT_BIST_public_H */
