#include "ELBCBOOT_CBHW_ConfigureLAW.h"
#include "LIBMCP_Types.h"

const ts_LAW_Config LAWs[] =
{
   {
      /* DDR SDRAM */
      {
         {
            0  /* Mapped at 0x00000000 */
         }
      },
      {
         {
            1,    /* Enabled */
            0xf,  /* DDR memory controller */
            0x1b  /* 256 MB */
         }
      }
   },
   {
      /* PLD COMPAGNON LCS1 */
      {
         {
            0xf1000  /* Mapped at 0xf1000000 */
         }
      },
      {
         {
            1,    /* Enabled */
            0x4,  /* Enhanced local bus (eLBC) */
            0x17  /* 16 MB */
         }
      }
   },
   {
      /* PLD COMPAGNON LCS2 */
      {
         {
            0xf2000  /* Mapped at 0xf2000000 */
         }
      },
      {
         {
            1,    /* Enabled */
            0x4,  /* Enhanced local bus (eLBC) */
            0x17  /* 16 MB */
         }
      }
   },
   {
      /* PCIe 1 */
      {
         {
            0x80000  /* Mapped at 0x80000000 */
         }
      },
      {
         {
            1,    /* Enabled */
            0x2,  /* PCI Express 1 */
            0x1c  /* 256 MB */
         }
      }
   },
   {
      /* PCIe 2 */
      {
         {
            0xB0000  /* Mapped at 0xB0000000 */
         }
      },
      {
         {
            1,    /* Enabled */
            0x1,  /* PCI Express 2 */
            0x1c  /* 256 MB */
         }
      }
   }
   /* NO LAW NEEDED FOR PLD COMPAGNON LCS0 (BOOT RAM 0xFF80_0000) */
};

void ELBCBOOT_CBHW_ConfigureLAW(void)
{
   uint32_t v_index;
   uint32_t v_regAddr;

   for (v_index=0ul;v_index<(sizeof(LAWs)/sizeof(ts_LAW_Config));v_index++)
   {
      v_regAddr = C_ELBCBOOT_CCSR_LAW + (v_index * C_ELBCBOOT_CCSR_LAW_OFFSET) + C_ELBCBOOT_CCSR_LAW_BAR_OFFSET;
      *((volatile uint32_t *)v_regAddr) = LAWs[v_index].LAWBAR.Value;
      v_regAddr = C_ELBCBOOT_CCSR_LAW + (v_index * C_ELBCBOOT_CCSR_LAW_OFFSET) + C_ELBCBOOT_CCSR_LAW_AR_OFFSET;
      *((volatile uint32_t *)v_regAddr) = LAWs[v_index].LAWAR.Value;
   }
}