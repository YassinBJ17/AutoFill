#include "ELBCBOOT_CBHW_ConfigureDDR.h"
#include "LIBMCP_Types.h"

#define C_CCSR_DDR_CS0_BNDS_SA   0x00000000ul  /* Starting address */
#define C_CCSR_DDR_CS0_BNDS_EA   0x00f00000ul  /* Ending address */

const tu_DDR_Config DDR_Config =
{
   {
      /* DDR_SDRAM_CFG */
      {
         C_ELBCBOOT_CCSR_DDR_SDRAM_CFG_ADDRESS,
         {
            0,    /* SDRAM interface logic is disabled for now */
            0,    /* SDRAM self refresh is disabled during sleep */
            1,    /* ECC is enabled */
            0,    /* Unbuffered DIMMs */
            0x7,  /* DDR3 */
            0,    /* Dynamic power management mode is disabled */
            1,    /* 32-bit bus is used */
            1,    /* 8-beat bursts */
            0,    /* 1T timing (no T3) */
            0,    /*     ^     (no T2) */
            0,    /* No external memory banks are interleaved */
            0,    /* Either x8 or x16 discrete DRAM chips are used */
            0,    /* 0 MA[10] is used to indicate the auto-precharge and precharge all commands */
            1,    /* I/O driver impedance is configured to half strength */
            0,    /* DDR controller accepts new transactions */
            0     /* DDR controller cycles through initialization routine based on SDRAM_TYPE */
         }
      },
      /* DDR_CS0_BNDS */
      {
         C_ELBCBOOT_CCSR_DDR_CS0_BNDS_ADDRESS,
         {
            C_CCSR_DDR_CS0_BNDS_SA >> 20,
            C_CCSR_DDR_CS0_BNDS_EA >> 20
         }
      },
      /* DDR_CS0_CONFIG */
      {
         C_ELBCBOOT_CCSR_DDR_CS0_CONFIG_ADDRESS,
         {
            1, /* Chip select 0 is active */
            1, /* Chip select 0 always issues an auto-precharge for read and write transactions */
            0, /* Never assert ODT for reads */
            1, /* Assert ODT only during writes to CS 0 */
            1, /* 3 logical bank bits */
            1, /* 13 row bits */
            2  /* 10 column bits */
         }
      },
      /* DDR_CS0_CONFIG_2 */
      {
         C_ELBCBOOT_CCSR_DDR_CS0_CONFIG_2_ADDRESS,
         {
            0  /* Partial array self refresh is disabled */
         }
      },
      /* DDR_TIMING_CFG_3 */
      {
         C_ELBCBOOT_CCSR_DDR_TIMING_CFG_3_ADDRESS,
         {
            0, /* 0 clocks */
            1, /* 16 clocks */
            0, /* 0 clocks */
            0  /* MODT[ 0:1 ], MCS [ 0:1 ], and MCKE[ 0:1 ] are launched aligned with the other DRAM address
   and control signals */
         }
      },
      /* DDR_TIMING_CFG_0 */
      {
         C_ELBCBOOT_CCSR_DDR_TIMING_CFG_0_ADDRESS,
         {
            0, /* 0 clocks */
            0, /* 0 clocks */
            0, /* 0 clocks */
            0, /* 0 clocks */
            2, /* 3 clocks */
            2, /* 3 clocks */
            1, /* 1 clock */
            4  /* 4 clocks */
         }
      },
      /* DDR_TIMING_CFG_1 */
      {
         C_ELBCBOOT_CCSR_DDR_TIMING_CFG_1_ADDRESS,
         {
            0x4, /* 4 clocks */
            0xc, /* 12 clocks */
            0x4, /* 4 clocks */
            0x9, /* 5 clocks */
            0xd, /* 21 clocks */
            0x5, /* 5 clocks */
            0x4, /* 4 clocks */
            0x4  /* 4 clocks */
         }
      },
      /* DDR_TIMING_CFG_2 */
      {
         C_ELBCBOOT_CCSR_DDR_TIMING_CFG_2_ADDRESS,
         {
            0,    /* 0 clocks */
            0x1F, /* Automatic Calibration */
            0x5,  /* 5 clocks */
            0x4,  /* 4 cycles */
            0,    /* 0 clock delay */
            0x3,  /* 3 clocks */
            0x0F  /* 15 cycles */
         }
      },
      /* DDR_SDRAM_CFG_2 */
      {
         C_ELBCBOOT_CCSR_DDR_SDRAM_CFG_2_ADDRESS,
         {
            0, /* DDR controller operates in normal mode */
            0, /* DDR controller does not enter self-refresh mode if panic interrupt is asserted */
            0, /* DDR controller issues a DLL reset to the DRAMs when exiting self refresh */
            1, /* Differential DQS signals are used */
            2, /* Assert ODT to internal IOs only during reads to DRAM */
            1, /* 1 refresh is issued at a time */
            0, /* Address parity is not used */
            1, /* The memory controller initializes memory once it is enabled (The value in DDR_DATA_INIT register is used) */
            0, /* Register control words will not be automatically written during DRAM initialization */
            0  /* Mirrored DIMMs are not used */
         }
      },
      /* DDR_SDRAM_MODE */
      {
         C_ELBCBOOT_CCSR_DDR_SDRAM_MODE_ADDRESS,
         {
            0x4044,
            0x1210
         }
      },
      /* DDR_SDRAM_MODE_2 */
      {
         C_ELBCBOOT_CCSR_DDR_SDRAM_MODE_2_ADDRESS,
         {
            0x8040,
            0xe000
         }
      },
      /* DDR_SDRAM_INTERVAL */
      {
         C_ELBCBOOT_CCSR_DDR_SDRAM_INTERVAL_ADDRESS,
         {
            0x0514,
            0x0000   /* global auto-precharge mode */
         }
      },
      /* DDR_DATA_INIT */
      {
         C_ELBCBOOT_CCSR_DDR_DATA_INIT_ADDRESS,
         {
            0x600dfeed
         }
      },
      /* DDR_SDRAM_CLK_CNTL */
      {
         C_ELBCBOOT_CCSR_DDR_SDRAM_CLK_CNTL_ADDRESS,
         {
            0x6   /* Clock is launched 3/4 applied cycle after address/command */
         }
      },
      /* DDR_INIT_ADDR */
      {
         C_ELBCBOOT_CCSR_DDR_INIT_ADDR_ADDRESS,
         {
            0x00000000
         }
      },
      /* DDR_INIT_EXT_ADR */
      {
         C_ELBCBOOT_CCSR_DDR_INIT_EXT_ADR_ADDRESS,
         {
            0, /* Use the default address for training sequence as calculated by the controller */
            0
         }
      },
      /* DDR_TIMING_CFG_4 */
      {
         C_ELBCBOOT_CCSR_DDR_TIMING_CFG_4_ADDRESS,
         {
            0, /* Default */
            0, /* Default */
            0, /* BL/2 clocks */
            0, /* BL/2 clocks */
            1  /* 512 clocks */
         }
      },
      /* DDR_TIMING_CFG_5 */
      {
         C_ELBCBOOT_CCSR_DDR_TIMING_CFG_5_ADDRESS,
         {
            0, /* RL 3 clocks */
            0, /* 3 clocks */
            0, /* WL - 3 clocks */
            4  /* 4 clocks */
         }
      },
      /* DDR_ZQ_CNTL */
      {
         C_ELBCBOOT_CCSR_DDR_ZQ_CNTL_ADDRESS,
         {
            1,    /* ZQ Calibration is used */
            0x9,  /* 512 clocks */
            0x8,  /* 256 clocks */
            0x6   /* 64 clocks */
         }
      },
      /* DDR_WRLVL_CNTL */
      {
         C_ELBCBOOT_CCSR_DDR_WRLVL_CNTL_ADDRESS,
         {
            0x1,  /* Write leveling is used */
            0x6,  /* 64 clocks */
            0x4,  /* 16 clocks */
            0x5,  /* 32 clocks */
            0x9,  /* 9 clocks */
            0x6,  /* 64 clocks */
            0x8   /* 1 clock delay */
         }
      },
      /* DDR_WRLVL_CNTL_2 */
      {
         C_ELBCBOOT_CCSR_DDR_WRLVL_CNTL_2_ADDRESS,
         {
            0, /* Use value from DDR_WRLVL_CNTL[WRLVL_START] */
            0, /* Use value from DDR_WRLVL_CNTL[WRLVL_START] */
            0, /* Use value from DDR_WRLVL_CNTL[WRLVL_START] */
            0  /* Use value from DDR_WRLVL_CNTL[WRLVL_START] */
         }
      },
      /* DDR_WRLVL_CNTL_3 */
      {
         C_ELBCBOOT_CCSR_DDR_WRLVL_CNTL_3_ADDRESS,
         {
            0, /* Use value from DDR_WRLVL_CNTL[WRLVL_START] */
            0, /* Use value from DDR_WRLVL_CNTL[WRLVL_START] */
            0, /* Use value from DDR_WRLVL_CNTL[WRLVL_START] */
            0  /* Use value from DDR_WRLVL_CNTL[WRLVL_START] */
         }
      },
      /* DDR_SR_CNTR */
      {
         C_ELBCBOOT_CCSR_DDR_SR_CNTR_ADDRESS,
         {
            0  /* Automatic self refresh entry disabled */
         }
      },
      /* DDR_CDR_1 */
      {
         C_ELBCBOOT_CCSR_DDR_CDR_1_ADDRESS,
         {
            0,    /* Disable DDR driver hardware compensation */
            0,    /* Disable Driver software override for MDIC */
            0,    /* - */
            0,    /* - */
            0,    /* Disable driver software override p-impedance output */
            0,    /* Disable driver software override n-impedance output */
            0x2,  /* 43 O (10x combined with CDR_2[ODT]) */
            0,    /* Disable software override for address/command */
            0,    /* Disable software override for data */
            0,    /* - */
            0,    /* - */
            0,    /* - */
            0     /* - */
         }
      },
      /* DDR_CDR_2 */
      {
         C_ELBCBOOT_CCSR_DDR_CDR_2_ADDRESS,
         {
            0, /* Disable software override for clocks */
            0, /* - */
            0, /* - */
            1  /* 43 O (xx1 combined with CDR_1[ODT]) */
         }
      },
      /* DDR_ERR_DISABLE */
      {
         C_ELBCBOOT_CCSR_DDR_ERR_DISABLE_ADDRESS,
         {
            0, /* Address parity errors are detected if DDR_SDRAM_CFG_2[AP_EN] is set */
            0, /* Automatic calibration errors are enabled */
            0, /* Multiple-bit ECC errors are detected if DDR_SDRAM_CFG[ECC_EN] is set */
            0, /* Single-bit ECC errors are enabled */
            0  /* Memory select errors are enabled */
         }
      },
      /* DDR_ERR_INT_EN */
      {
         C_ELBCBOOT_CCSR_DDR_ERR_INT_EN_ADDRESS,
         {
            0, /* Address parity errors cannot generate interrupts */
            0, /* Automatic calibration errors cannot generate interrupts */
            1, /* Multiple-bit ECC errors generate interrupts */
            1, /* Single-bit ECC errors generate interrupts */
            1  /* Memory select errors generate interrupts */
         }
      },
      /* DDR_ERR_SBE */
      {
         C_ELBCBOOT_CCSR_DDR_ERR_SBE_ADDRESS,
         {
            0,
            0
         }
      }
   }
};

void ELBCBOOT_CBHW_ConfigureDDR(void)
{
   uint32_t v_index;

   for (v_index=0ul;v_index<(sizeof(DDR_Config)/sizeof(ts_DDR_SDRAM_CFG));v_index++)
   {
      *((volatile uint32_t *)DDR_Config.Register[v_index].Addr) = DDR_Config.Register[v_index].Value;
   }
   asm("nop");
   asm("nop");
   ((volatile ts_DDR_SDRAM_CFG_Fields *)DDR_Config.Registers.DDR_SDRAM_CFG.Addr)->MEM_EN = 1ul; /* %RELAX<SYNCHRONe_C_Code_10.7> Changing 1 bit in a 32bit register; there is no loss of precision */
 }