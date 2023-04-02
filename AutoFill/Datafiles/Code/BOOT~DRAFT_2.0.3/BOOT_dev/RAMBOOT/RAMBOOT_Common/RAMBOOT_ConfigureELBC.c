#include "RAMBOOT_ConfigureELBC.h"
#include "LIBMCP_Types.h"

const tu_eLBC_LBCR LBCR =
{
   {
      0, /* LDIS */
      0, /* BCTLC */
      0, /* AHD */
      0, /* ABSWP */
      0, /* AS16 */
      0, /* LPBSE */
      1, /* EPAR */
      0, /* BMT */
      0  /* BMTPS */
   }
};

const tu_eLBC_LCRR LCRR =
{
   {
      1,    /* PBYP */
      3,    /* EADC */
      0x02  /* CLKDIV */
   }
};

const ts_eLBC_Config LINEs[] = 
{
   {
      /* PLD COMPAGNON LCS0 */
      {
         0xff800000 >> 15, /* BA */
         0x2,  /* PS: 16-bit */
         0,    /* DECC */
         0,    /* WP */
         0,    /* MSEL */
         1     /* V */
      },
      {
         0xff800000 >> 15, /* AM: 8Mbytes */
         0,    /* BCTLD */
         0,    /* CSNT */
         0x2,  /* ACS */
         1,    /* XACS */
         0xf,  /* SCY */
         0,    /* SETA */
         1,    /* TRLX */
         0,    /* EHTR */
         1     /* EAD */
      }
   },
   {
      /* PLD MEGATICE LCS1 */
      {
         0xf1000000 >> 15, /* ADDR */
         0x2,  /* PS: 16-bit */
         0,    /* DECC */
         0,    /* WP */
         0,    /* MSEL */
         1     /* V */
      },
      {
         0xff000000 >> 15, /* 16Mbytes */
         0,    /* BCTLD */
         0,    /* CSNT */
         0x2,  /* ACS */
         1,    /* XACS */
         0xf,  /* SCY */
         1,    /* SETA */
         1,    /* TRLX */
         0,    /* EHTR */
         1     /* EAD */
      }
   },
   {
      /* PLD COMPAGNON LCS2 */
      {
         0xf2000000 >> 15, /* ADDR */
         0x2,  /* PS: 16-bit */
         0,    /* DECC */
         0,    /* WP */
         0,    /* MSEL */
         1     /* V */
      },
      {
         0xff000000 >> 15, /* 16Mbytes */
         0,    /* BCTLD */
         0,    /* CSNT */
         0x2,  /* ACS */
         1,    /* XACS */
         0xf,  /* SCY */
         1,    /* SETA */
         1,    /* TRLX */
         0,    /* EHTR */
         1     /* EAD */
      }
   }
};

void RAMBOOT_ConfigureELBC(void)
{
   uint32_t v_index;
   uint32_t v_regAddr;
   volatile uint32_t v_LCRR;

   v_regAddr = C_RAMBOOT_CCSR_ELBC_LBCR_ADDRESS;
   *((volatile uint32_t *) v_regAddr) = LBCR.Value;
   v_regAddr = C_RAMBOOT_CCSR_ELBC_LCRR_ADDRESS;
   *((volatile uint32_t *) v_regAddr) = LCRR.Value;
   v_LCRR = *((uint32_t *) v_regAddr);
   asm("isync");

   for (v_index = 0ul; v_index < (sizeof(LINEs)/sizeof(ts_eLBC_Config)); v_index++)
   {
      v_regAddr = C_LIBBSP_CCSR_ELBC + (v_index * C_RAMBOOT_CCSR_ELBC_OFFSET);
      *((volatile uint32_t *) v_regAddr) = LINEs[v_index].BR.Value;
      v_regAddr += C_RAMBOOT_CCSR_ELBC_OR_OFFSET;
      *((volatile uint32_t *) v_regAddr) = LINEs[v_index].OR.Value;
   }
}