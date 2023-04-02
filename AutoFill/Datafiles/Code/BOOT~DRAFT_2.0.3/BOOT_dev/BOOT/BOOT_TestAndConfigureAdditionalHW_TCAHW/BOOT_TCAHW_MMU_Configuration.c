#include "BOOT_TCAHW_MMU_Configuration.h"

const ts_TLB_Config L2SRAM_TLB_Conf =
{
   {
   /* MAS0 */
      1, /* TLBSEL */
      0, /* ESEL */
      0, /* NV */
   /* MAS1 */
      1, /* V */
      1, /* IPROT */
      0, /* TID */
      0, /* TS */
      4, /* TSIZE */ /* 256kB */
   /* MAS2 */
      0x20000, /* EPN */ /* 0x20000000 start of L2SRAM */
      0, /* VLE */
      1, /* W */
      0, /* I */
      0, /* M */
      0, /* G */
      0, /* E */
   /* MAS3 */
      0x20000, /* RPN */ /* 0x20000000 start of L2SRAM */
      0, /* U0-U3 */
      0, /* UX */
      1, /* SX */
      0, /* UW */
      1, /* SW */
      0, /* UR */
      1, /* SR */
   /* MAS7 */
      0  /* RPN */
   }
};

const ts_TLB_Config MMU_PBIT_RO_ZoneTLB_Conf =
{
   {
   /* MAS0 */
      1, /* TLBSEL */
      6, /* ESEL */
      0, /* NV */
   /* MAS1 */
      1, /* V */
      1, /* IPROT */
      0, /* TID */
      0, /* TS */
      1, /* TSIZE */ /* 4kB */
   /* MAS2 */
      0, /* EPN */ /* 0x00000000 start of SDRAM */
      0, /* VLE */
      0, /* W */
      1, /* I */
      0, /* M */
      1, /* G */
      0, /* E */
   /* MAS3 */
      0, /* RPN */ /* 0x00000000 start of SDRAM */
      0, /* U0-U3 */
      0, /* UX */
      0, /* SX */
      0, /* UW */
      0, /* SW */
      0, /* UR */
      1, /* SR */
   /* MAS7 */
      0  /* RPN */
   }
};

const ts_TLB_Config MMU_PBIT_DIS_ZoneTLB_Conf =
{
   {
   /* MAS0 */
      1, /* TLBSEL */
      6, /* ESEL */
      0, /* NV */
   /* MAS1 */
      0, /* V */
      1, /* IPROT */
      0, /* TID */
      0, /* TS */
      1, /* TSIZE */ /* 4kB */
   /* MAS2 */
      0, /* EPN */ /* 0x00000000 start of SDRAM */
      0, /* VLE */
      0, /* W */
      0, /* I */
      0, /* M */
      0, /* G */
      0, /* E */
   /* MAS3 */
      0, /* RPN */ /* 0x00000000 start of SDRAM */
      0, /* U0-U3 */
      0, /* UX */
      0, /* SX */
      0, /* UW */
      0, /* SW */
      0, /* UR */
      0, /* SR */
   /* MAS7 */
      0  /* RPN */
   }
};

const ts_TLB_Config MMU_PBIT_MIN_ZoneTLB_Conf =
{
   {
   /* MAS0 */
      1, /* TLBSEL */
      1, /* ESEL */
      0, /* NV */
   /* MAS1 */
      1, /* V */
      1, /* IPROT */
      0, /* TID */
      0, /* TS */
      6, /* TSIZE */ /* 4MB */
   /* MAS2 */
      0x0F800, /* EPN */ /* 0x00000000 start of SDRAM */
      0, /* VLE */
      1, /* W */
      0, /* I */
      0, /* M */
      0, /* G */
      0, /* E */
   /* MAS3 */
      0x0F800, /* RPN */ /* 0x00000000 start of SDRAM */
      0, /* U0-U3 */
      0, /* UX */
      1, /* SX */
      0, /* UW */
      1, /* SW */
      0, /* UR */
      1, /* SR */
   /* MAS7 */
      0  /* RPN */
   }
};

const ts_TLB_Config SDRAM_TLB_Conf =
{
   {
   /* MAS0 */
      1, /* TLBSEL */
      1, /* ESEL */
      0, /* NV */
   /* MAS1 */
      1, /* V */
      1, /* IPROT */
      0, /* TID */
      0, /* TS */
      9, /* TSIZE */ /* 256MB */
   /* MAS2 */
      0, /* EPN */ /* 0x00000000 start of SDRAM */
      0, /* VLE */
      1, /* W */
      0, /* I */
      0, /* M */
      0, /* G */
      0, /* E */
   /* MAS3 */
      0, /* RPN */ /* 0x00000000 start of SDRAM */
      0, /* U0-U3 */
      0, /* UX */
      1, /* SX */
      0, /* UW */
      1, /* SW */
      0, /* UR */
      1, /* SR */
   /* MAS7 */
      0  /* RPN */
   }
};

const ts_TLB_Config CCSR_TLB_Conf =
{
   {
   /* MAS0 */
      1, /* TLBSEL */
      2, /* ESEL */
      0, /* NV */
   /* MAS1 */
      1, /* V */
      1, /* IPROT */
      0, /* TID */
      0, /* TS */
      5, /* TSIZE */ /* 1MB */
   /* MAS2 */
      0xFF700, /* EPN */ /* 0xFF700000 start of CCSR */
      0, /* VLE */
      0, /* W */
      1, /* I */
      0, /* M */
      1, /* G */
      0, /* E */
   /* MAS3 */
      0xFF700, /* RPN */ /* 0xFF700000 start of CCSR */
      0, /* U0-U3 */
      0, /* UX */
      1, /* SX */
      0, /* UW */
      1, /* SW */
      0, /* UR */
      1, /* SR */
   /* MAS7 */
      0  /* RPN */
   }
};

const ts_TLB_Config MEGATICE_PLD_TLB_Conf =
{
   {
   /* MAS0 */
      1, /* TLBSEL */
      3, /* ESEL */
      0, /* NV */
   /* MAS1 */
      1, /* V */
      1, /* IPROT */
      0, /* TID */
      0, /* TS */
      7, /* TSIZE */ /* 16MB */
   /* MAS2 */
      0xF1000, /* EPN */ /* 0xF1000000 start of MEGATICE PLD */
      0, /* VLE */
      0, /* W */
      1, /* I */
      0, /* M */
      1, /* G */
      0, /* E */
   /* MAS3 */
      0xF1000, /* RPN */ /* 0xF1000000 start of MEGATICE PLD */
      0, /* U0-U3 */
      0, /* UX */
      1, /* SX */
      0, /* UW */
      1, /* SW */
      0, /* UR */
      1, /* SR */
   /* MAS7 */
      0  /* RPN */
   }
};

const ts_TLB_Config COMPAGNON_PLD_TLB_Conf =
{
   {
   /* MAS0 */
      1, /* TLBSEL */
      4, /* ESEL */
      0, /* NV */
   /* MAS1 */
      1, /* V */
      1, /* IPROT */
      0, /* TID */
      0, /* TS */
      7, /* TSIZE */ /* 16MB */
   /* MAS2 */
      0xF2000, /* EPN */ /* 0xF2000000 start of COMPAGNON PLD */
      0, /* VLE */
      0, /* W */
      1, /* I */
      0, /* M */
      1, /* G */
      0, /* E */
   /* MAS3 */
      0xF2000, /* RPN */ /* 0xF2000000 start of COMPAGNON PLD */
      0, /* U0-U3 */
      0, /* UX */
      1, /* SX */
      0, /* UW */
      1, /* SW */
      0, /* UR */
      1, /* SR */
   /* MAS7 */
      0  /* RPN */
   }
};

const ts_TLB_Config COMPAGNON_RAM_TLB_Conf =
{
   {
   /* MAS0 */
      1, /* TLBSEL */
      5, /* ESEL */
      0, /* NV */
   /* MAS1 */
      1, /* V */
      1, /* IPROT */
      0, /* TID */
      0, /* TS */
      1, /* TSIZE */ /* 4KB */
   /* MAS2 */
      0xFFFF8, /* EPN */ /* 0xF2000000 start of COMPAGNON PLD */
      0, /* VLE */
      0, /* W */
      1, /* I */
      0, /* M */
      1, /* G */
      0, /* E */
   /* MAS3 */
      0xFFFF8, /* RPN */ /* 0xF2000000 start of COMPAGNON PLD */
      0, /* U0-U3 */
      0, /* UX */
      0, /* SX */
      0, /* UW */
      0, /* SW */
      0, /* UR */
      1, /* SR */
   /* MAS7 */
      0  /* RPN */
   }
};
