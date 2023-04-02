#ifndef BOOT_BIST_CFEX_public_H
#define BOOT_BIST_CFEX_public_H

/* --------------------------------------------------------------------------
 *                                 SAFRAN
 *                               SAFRAN Electronics & Defense
 * --------------------------------------------------------------------------
 * PROJECT : MODULE
 * CSU name :
 * %name: BOOT_BIST_CFEX_public.h %
 * %full_name:  fadex#2/incl/BOOT_BIST_CFEX_public.h/3 %
 *
 * --------------------------------------------------------------------------
 * SAFRAN Electronics & Defense document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"



/* STCU2 MBIST recoverable fault mapping for low register */
#define STCU2_MBIST_FAULT_RECOV_LOW_VAL   (uint32_t)0x0

/* STCU2 MBIST recoverable fault mapping for medium register */
#define STCU2_MBIST_FAULT_RECOV_MED_VAL   (uint32_t)0x0

/* STCU2 MBIST recoverable fault mapping for high register */
#define STCU2_MBIST_FAULT_RECOV_HIGH_VAL  (uint32_t)0x0

/* STCU2 LBIST recoverable fault mapping */
#define STCU2_LBIST_FAULT_RECOV_VAL       (uint32_t)0x0

/* Global functional reset is pulsed at the end of LBIST 9 */
#define STCU2_LBIST_RESET                 (uint32_t)0x200

/* STCU2 Watchdog timeout max value : 4294967296 x 16 STCU2 Core clock cycles */
#define STCU2_WATCHDOG_MAX_TIMEOUT_VAL    (uint32_t)0xFFFFFFFF


/* STCU2 configuration register for reduced test:
   - PTR=10h : pointer to MBIST
   - LB_DELAY=00h : No delay
   - WRP=0 : Specific STCU2 registers can be written through IPS bus interface after Off-Line Self-Test sequence
			 has been completed
   - CRCEN=0 : The CRC comparison is not performed
   - PMOSEN=0 : When MBU is 0 then selects the "Reduced test" MBIST test type.
   - MBU=0 : Either "Full test" or "Reduced test" 
			 MBIST test type will be selected according to the PMOSEN value.
   - CLK_CFG=000b : No divider for sys_clk */
#define STCU2_REDUCED_TEST_CONF           (uint32_t)0x10000000

/* STCU2 run software register configuration to start on-line self testing procedure 
   - MBIE=0b : Interrupt is not generated at the end of the software MBIST execution phase of the selected
			   Memories.
   - LBIE=0b : Interrupt is not generated at the end of the software LBIST execution phase of the selected LBIST.
   - MBSWPLLEN=1b : On-Line MBIST is executed using the PLL configuration provided by software.
   - LBSWPLLEN=1b : On-Line LBIST is executed using the PLL configuration provided by software.
   - RUNSW_ABORT=0b : On-line self-test abort is not requested.
   - RUNSW=1b : On-line self testing procedure is running
*/
#define STCU2_RUN_CONF                    (uint32_t)0x00000301


/* Set the system clock, enable XOSC and PLLs 
   - PWRLVL=011b
   - PDO=0 : No automatic safe gating of I/Os used and pads power sequence driver is enabled
   - MVRON=1b : Main voltage regulator is switched on
   - FLAON=11b : Flash is in normal mode
   - PLL1ON=0 : secondary PLL is switched off
   - PLL0ON=0 : primary PLL is switched off
   - XOSCON=1b : external crystal oscillator is switched on
   - IRCON=1b : 16 MHz internal RC oscillator is switched on
   - SYSCLK=0001b : external crystal osc.
*/
#define MC_ME_DRUN_MC_PLL_OFF             (uint32_t)0x30130031

/* Set the system clock, enable XOSC and PLLs 
   - PWRLVL=011b
   - PDO=0 : No automatic safe gating of I/Os used and pads power sequence driver is enabled
   - MVRON=1b : Main voltage regulator is switched on
   - FLAON=11b : Flash is in normal mode
   - PLL1ON=1 : secondary PLL is switched on
   - PLL0ON=1 : primary PLL is switched on
   - XOSCON=1b : external crystal oscillator is switched on
   - IRCON=1b : 16 MHz internal RC oscillator is switched on
   - SYSCLK=0100b : secondary PLL
*/
#define MC_ME_DRUN_MC_PLL_ON              (uint32_t)0x301300F4


/* ---------- internal types: ----------------------------------------------- */

/* MBIST CTRL value */
typedef enum
{
	e_NEXT_MBIST_1	=	0x91000000	,
	e_NEXT_MBIST_2	=	0x92000000	,
	e_NEXT_MBIST_3	=	0x93000000	,
	e_NEXT_MBIST_4	=	0x94000000	,
	e_NEXT_MBIST_5	=	0x95000000	,
	e_NEXT_MBIST_6	=	0x96000000	,
	e_NEXT_MBIST_7	=	0x97000000	,
	e_NEXT_MBIST_8	=	0x98000000	,
	e_NEXT_MBIST_9	=	0x99000000	,
	e_NEXT_MBIST_10	=	0x9A000000	,
	e_NEXT_MBIST_11	=	0x9B000000	,
	e_NEXT_MBIST_12	=	0x9C000000	,
	e_NEXT_MBIST_13	=	0x9D000000	,
	e_NEXT_MBIST_14	=	0x9E000000	,
	e_NEXT_MBIST_15	=	0x9F000000	,
	e_NEXT_MBIST_16	=	0xA0000000	,
	e_NEXT_MBIST_17	=	0xA1000000	,
	e_NEXT_MBIST_18	=	0xA2000000	,
	e_NEXT_MBIST_19	=	0xA3000000	,
	e_NEXT_MBIST_20	=	0xA4000000	,
	e_NEXT_MBIST_21	=	0xA5000000	,
	e_NEXT_MBIST_22	=	0xA6000000	,
	e_NEXT_MBIST_23	=	0xA7000000	,
	e_NEXT_MBIST_24	=	0xA8000000	,
	e_NEXT_MBIST_25	=	0xA9000000	,
	e_NEXT_MBIST_26	=	0xAA000000	,
	e_NEXT_MBIST_27	=	0xAB000000	,
	e_NEXT_MBIST_28	=	0xAC000000	,
	e_NEXT_MBIST_29	=	0xAD000000	,
	e_NEXT_MBIST_30	=	0xAE000000	,
	e_NEXT_MBIST_31	=	0xAF000000	,
	e_NEXT_MBIST_32	=	0xB0000000	,
	e_NEXT_MBIST_33	=	0xB1000000	,
	e_NEXT_MBIST_34	=	0xB2000000	,
	e_NEXT_MBIST_35	=	0xB3000000	,
	e_NEXT_MBIST_36	=	0xB4000000	,
	e_NEXT_MBIST_37	=	0xB5000000	,
	e_NEXT_MBIST_38	=	0xB6000000	,
	e_NEXT_MBIST_39	=	0x37000000	,
	e_NEXT_MBIST_40	=	0xB8000000	,
	e_NEXT_MBIST_41	=	0xB9000000	,
	e_NEXT_MBIST_42	=	0xBA000000	,
	e_NEXT_MBIST_43	=	0xBB000000	,
	e_NEXT_MBIST_44	=	0xBC000000	,
	e_NEXT_MBIST_45	=	0xBD000000	,
	e_NEXT_MBIST_46	=	0xBE000000	,
	e_NEXT_MBIST_47	=	0xBF000000	,
	e_NEXT_MBIST_48	=	0xC0000000	,
	e_NEXT_MBIST_49	=	0xC1000000	,
	e_NEXT_MBIST_50	=	0xC2000000	,
	e_NEXT_MBIST_51	=	0xC3000000	,
	e_NEXT_MBIST_52	=	0xC4000000	,
	e_NEXT_MBIST_53	=	0xC5000000	,
	e_NEXT_MBIST_54	=	0xC6000000	,
	e_NEXT_MBIST_55	=	0xC7000000	,
	e_NEXT_MBIST_56	=	0xC8000000	,
	e_NEXT_MBIST_57	=	0xC9000000	,
	e_NEXT_MBIST_58	=	0xCA000000	,
	e_NEXT_MBIST_59	=	0xCB000000	,
	e_NEXT_MBIST_60	=	0xCC000000	,
	e_NEXT_MBIST_61	=	0xCD000000	,
	e_NEXT_MBIST_62	=	0xCE000000	,
	e_NEXT_MBIST_63	=	0xCF000000	,
	e_NEXT_MBIST_64	=	0xD0000000	,
	e_NEXT_MBIST_65	=	0xD1000000	,
	e_NEXT_MBIST_66	=	0xD2000000	,
	e_NEXT_MBIST_67	=	0xD3000000	,
	e_NEXT_MBIST_68	=	0xD4000000	,
	e_NEXT_MBIST_69	=	0xD5000000	,
	e_NEXT_MBIST_70	=	0xD6000000	,
	e_NEXT_MBIST_71	=	0xD7000000	,
	e_NEXT_MBIST_72	=	0xD8000000	,
	e_NEXT_MBIST_73	=	0xD9000000	,
	e_NEXT_MBIST_74	=	0xDA000000	,
	e_NEXT_MBIST_75	=	0xDB000000	,
	e_NEXT_MBIST_76	=	0xDC000000	,
	e_NEXT_MBIST_77	=	0xDD000000	,
	e_NEXT_MBIST_78	=	0x00000000	
}
te_MBIST_CTRL_VALUE;

/* Number of MBIST partition */
typedef enum
{
	e_MBIST_PART_0	=	0	,
	e_MBIST_PART_1	=	1	,
	e_MBIST_PART_2	=	2	,
	e_MBIST_PART_3	=	3	,
	e_MBIST_PART_4	=	4	,
	e_MBIST_PART_5	=	5	,
	e_MBIST_PART_6	=	6	,
	e_MBIST_PART_7	=	7	,
	e_MBIST_PART_8	=	8	,
	e_MBIST_PART_9	=	9	,
	e_MBIST_PART_10	=	10	,
	e_MBIST_PART_11	=	11	,
	e_MBIST_PART_12	=	12	,
	e_MBIST_PART_13	=	13	,
	e_MBIST_PART_14	=	14	,
	e_MBIST_PART_15	=	15	,
	e_MBIST_PART_16	=	16	,
	e_MBIST_PART_17	=	17	,
	e_MBIST_PART_18	=	18	,
	e_MBIST_PART_19	=	19	,
	e_MBIST_PART_20	=	20	,
	e_MBIST_PART_21	=	21	,
	e_MBIST_PART_22	=	22	,
	e_MBIST_PART_23	=	23	,
	e_MBIST_PART_24	=	24	,
	e_MBIST_PART_25	=	25	,
	e_MBIST_PART_26	=	26	,
	e_MBIST_PART_27	=	27	,
	e_MBIST_PART_28	=	28	,
	e_MBIST_PART_29	=	29	,
	e_MBIST_PART_30	=	30	,
	e_MBIST_PART_31	=	31	,
	e_MBIST_PART_32	=	32	,
	e_MBIST_PART_33	=	33	,
	e_MBIST_PART_34	=	34	,
	e_MBIST_PART_35	=	35	,
	e_MBIST_PART_36	=	36	,
	e_MBIST_PART_37	=	37	,
	e_MBIST_PART_38	=	38	,
	e_MBIST_PART_39	=	39	,
	e_MBIST_PART_40	=	40	,
	e_MBIST_PART_41	=	41	,
	e_MBIST_PART_42	=	42	,
	e_MBIST_PART_43	=	43	,
	e_MBIST_PART_44	=	44	,
	e_MBIST_PART_45	=	45	,
	e_MBIST_PART_46	=	46	,
	e_MBIST_PART_47	=	47	,
	e_MBIST_PART_48	=	48	,
	e_MBIST_PART_49	=	49	,
	e_MBIST_PART_50	=	50	,
	e_MBIST_PART_51	=	51	,
	e_MBIST_PART_52	=	52	,
	e_MBIST_PART_53	=	53	,
	e_MBIST_PART_54	=	54	,
	e_MBIST_PART_55	=	55	,
	e_MBIST_PART_56	=	56	,
	e_MBIST_PART_57	=	57	,
	e_MBIST_PART_58	=	58	,
	e_MBIST_PART_59	=	59	,
	e_MBIST_PART_60	=	60	,
	e_MBIST_PART_61	=	61	,
	e_MBIST_PART_62	=	62	,
	e_MBIST_PART_63	=	63	,
	e_MBIST_PART_64	=	64	,
	e_MBIST_PART_65	=	65	,
	e_MBIST_PART_66	=	66	,
	e_MBIST_PART_67	=	67	,
	e_MBIST_PART_68	=	68	,
	e_MBIST_PART_69	=	69	,
	e_MBIST_PART_70	=	70	,
	e_MBIST_PART_71	=	71	,
	e_MBIST_PART_72	=	72	,
	e_MBIST_PART_73	=	73	,
	e_MBIST_PART_74	=	74	,
	e_MBIST_PART_75	=	75	,
	e_MBIST_PART_76	=	76	,
	e_MBIST_PART_77	=	77	
}
te_MBIST_PART_NB;


/* Number of LBIST partition */
typedef enum
{
	e_LBIST_PART_0	=	0	,
	e_LBIST_PART_1	=	1	,
	e_LBIST_PART_2	=	2	,
	e_LBIST_PART_3	=	3	,
	e_LBIST_PART_4	=	4	,
	e_LBIST_PART_5	=	5	,
	e_LBIST_PART_6	=	6	,
	e_LBIST_PART_7	=	7	,
	e_LBIST_PART_8	=	8	,
	e_LBIST_PART_9	=	9	
}
te_LBIST_PART_NB;

/* LBIST CTRL value :
   - CSM=0b : Run in sequential mode
   - PRPGEN=0b : Default LBIST value of the PRPG is used during LBIST run
   - SHS=011b : Shift at 1/4 rate of STCU2 core clock
   - SCEN_OFF= 0101b : 5 delay cycles
   - SCEN_ON=0101b : 5 delay cycles  
   - PFT=0 : Apply Flush Test Patterns
   - CWS=111b : controller waits 7 shift cycles for capture to finish  */
typedef enum
{
	/* PTR=0x1 : Next partition is partition 1 */
	e_NEXT_LBIST_1	=	0x01035507	,
	/* PTR=0x2 : Next partition is partition 2 */
	e_NEXT_LBIST_2	=	0x02035507	,
	/* PTR=0x3 : Next partition is partition 3 */
	e_NEXT_LBIST_3	=	0x03035507	,
	/* PTR=0x4 : Next partition is partition 4 */
	e_NEXT_LBIST_4	=	0x04035507	,
	/* PTR=0x5 : Next partition is partition 5 */
	e_NEXT_LBIST_5	=	0x05035507	,
	/* PTR=0x6 : Next partition is partition 6	*/
	e_NEXT_LBIST_6	=	0x06035507	,
	/* PTR=0x7 : Next partition is partition 7 */
	e_NEXT_LBIST_7	=	0x07035507	,
	/* PTR=0x8 : Next partition is partition 8 */
	e_NEXT_LBIST_8	=	0x08035507	,
	/* PTR=0x9 : Next partition is partition 9 */
	e_NEXT_LBIST_9	=	0x09035507	,
	/* PTR=0x7F : Last partition to be launched */
	e_LAST_LBIST	=	0x7F035507	
}
te_LBIST_CTRL_VALUE;

/* Pattern counter stop for each LBIST controller */
typedef enum
{
	e_LBIST_PATTERN_COUNT_0	=	0x00000580	,
	e_LBIST_PATTERN_COUNT_1	=	0x000004C0	,
	e_LBIST_PATTERN_COUNT_2	=	0x00000500	,
	e_LBIST_PATTERN_COUNT_3	=	0x00000600	,
	e_LBIST_PATTERN_COUNT_4	=	0x00000400	,
	e_LBIST_PATTERN_COUNT_5	=	0x00000580	,
	e_LBIST_PATTERN_COUNT_6	=	0x00000DC0	,
	e_LBIST_PATTERN_COUNT_7	=	0x00000380	,
	e_LBIST_PATTERN_COUNT_8	=	0x00000580	,
	e_LBIST_PATTERN_COUNT_9	=	0x00000580	

}
te_LBIST_PATTERN_COUNT_VALUE;


/* LBIST expected values low register (MISREL) */
typedef enum
{
	e_LBIST_EVL_0	=	0xC600B837	,
	e_LBIST_EVL_1	=	0x3E7EB360	,
	e_LBIST_EVL_2	=	0x893E9D7B	,
	e_LBIST_EVL_3	=	0xA20CC2AA	,
	e_LBIST_EVL_4	=	0xB3B30934	,
	e_LBIST_EVL_5	=	0x7D0928BE	,
	e_LBIST_EVL_6	=	0x23E0020A	,
	e_LBIST_EVL_7	=	0x3D71D224	,
	e_LBIST_EVL_8	=	0x0A44C59A	,
	e_LBIST_EVL_9	=	0x67F6D810	
}
te_LBIST_EXPECTED_VALUE_LOW;

/* LBIST expected values high register (MISREH) */
typedef enum
{
	e_LBIST_EVH_0	=	0x9CC36E3F	,
	e_LBIST_EVH_1	=	0x93067DD8	,
	e_LBIST_EVH_2	=	0x3ED132E8	,
	e_LBIST_EVH_3	=	0x8DC58C7A	,
	e_LBIST_EVH_4	=	0xCE7C169E	,
	e_LBIST_EVH_5	=	0xB6F928C2	,
	e_LBIST_EVH_6	=	0xBE153224	,
	e_LBIST_EVH_7	=	0xB784129E	,
	e_LBIST_EVH_8	=	0x13537D8B	,
	e_LBIST_EVH_9	=	0xD6C246F3	
}
te_LBIST_EXPECTED_VALUE_HIGH;


/* MBIST expected results*/
/* MBIST 0-8 */
#define MBIST_LMEM_0_OK         (uint32_t)0x1FF
/* MBIST 9-17 */
#define MBIST_LMEM_1_OK         (uint32_t)0x3FE00
/* MBIST 20-28 */
#define MBIST_LMEM_2_OK         (uint32_t)0x1FF00000
/* MBIST 63-69 */
#define MBIST_SRAM_M_OK         (uint32_t)0x80000000
#define MBIST_SRAM_H_OK         (uint32_t)0x3F
/* MBIST 37-38 */
#define MBIST_DMA_RMA_OK        (uint32_t)0x60
/* MBIST 77 */
#define MBIST_BAR_OK            (uint32_t)0x2000
/* MBIST 18-19, 29-36, 39-44, 45, 46-62, 74 */
#define MBIST_OTHER_RAM_L_OK    (uint32_t)0xE00C0000
#define MBIST_OTHER_RAM_M_OK    (uint32_t)0x7FFFFF9F
#define MBIST_OTHER_RAM_H_OK    (uint32_t)0x400
/* MBIST 70-73, 75-76 */
#define MBIST_DBG_RAM_OK        (uint32_t)0x1BC0

/* LBISTx expected result*/
#define LBIST_OK                (uint32_t)0x1

#define STCU2_GENERAL_RESULTS   (uint32_t) 0x31F0200

/* The RUNSW bit from the RUNSW register indicates if On-line BIST is still running */
typedef enum
{
   e_STCU2_BIST_IDLE = 0,
   e_STCU2_BIST_RUNNING_NOT_COMPLETED = 1
}
te_STCU2_BIST_RUNNING_STATE;

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal datas: ----------------------------------------------- */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */
/* none */

/* --------------------------- Function Prototypes --------------------------------------------------*/


#endif /* BOOT_BIST_CFEX_public_H */
