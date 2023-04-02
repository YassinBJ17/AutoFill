/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVNVIC_PRIVATE_H
#define DRVNVIC_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "DrvNVIC_Public.h"

#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
extern void * __Linker_Stack_Main;
extern void * __Linker_Stack_Process;


/* ---------- provided define constants: ------------------------------------ */
#define DRVNVIC_IRQ_ADDRESS            0xE000E100UL

#define DRVNVIC_IRQ_32BIT_NB           8UL
#define DRVNVIC_IRQ_IP_NB              240UL

#define DRVNVIC_BOOT_IRQ_NB            4UL
#define DRVNVIC_SEQ_IRQ_NB             15UL

#define DRVNVIC_IRQ_RESET_VALUE        0xFFFFFFFFUL
#define DRVNVIC_IRQ_PRIORITY_SHIFT     4UL

#define DRVNVIC_VTOR_OFFSET_REG_ADDR   0xE000ED08UL
#define DRVNVIC_VTOR_SRAM_ADDR         0x20000000UL

#define DRVNVIC_VTOR_SIZE              256UL
#define DRVNVIC_CPU_VECTORS_NB         15UL
#define DRVNVIC_MCU_VECTORS_NB         241UL

#define DRVNVIC_VTOR_FPU_INDEX              33UL
#define DRVNVIC_VTOR_FTFC_INDEX             37UL
#define DRVNVIC_VTOR_ECC_SINGLE_INDEX       60UL
#define DRVNVIC_VTOR_ECC_MULTI_INDEX        61UL
#define DRVNVIC_VTOR_TASK_MAIN_INDEX        64UL
#define DRVNVIC_VTOR_CAN1_INDEX            104UL
#define DRVNVIC_VTOR_ACQ_TSPEED_HS_INDEX   115UL
#define DRVNVIC_VTOR_ACQ_NTLOS1_INDEX      116UL
#define DRVNVIC_VTOR_ACQ_NGOS1_INDEX       117UL
#define DRVNVIC_VTOR_CNT_FTM0_OVF_INDEX    120UL
#define DRVNVIC_VTOR_ACQ_TSPEED_LS_INDEX   123UL
#define DRVNVIC_VTOR_CNT_FTM1_OVF_INDEX    126UL
#define DRVNVIC_VTOR_ACQ_NGOS2_INDEX       133UL
#define DRVNVIC_VTOR_ACQ_NTLOS2_INDEX      135UL
#define DRVNVIC_VTOR_CNT_FTM3_OVF_INDEX    138UL


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t S_ISER [DRVNVIC_IRQ_32BIT_NB];
   uint32_t S_NVIC_IRQ_Reserved_1 [24UL];
   uint32_t S_ICER [DRVNVIC_IRQ_32BIT_NB];
   uint32_t S_NVIC_IRQ_Reserved_2 [24UL];
   uint32_t S_ISPR [DRVNVIC_IRQ_32BIT_NB];
   uint32_t S_NVIC_IRQ_Reserved_3 [24UL];
   uint32_t S_ICPR [DRVNVIC_IRQ_32BIT_NB];
   uint32_t S_NVIC_IRQ_Reserved_4 [24UL];
   uint32_t S_IABR [DRVNVIC_IRQ_32BIT_NB];
   uint32_t S_NVIC_IRQ_Reserved_5 [56UL];
   uint8_t  S_IP [DRVNVIC_IRQ_IP_NB];
   uint32_t S_NVIC_IRQ_Reserved_6 [644UL];
   uint32_t S_STIR;
} TS_DrvNVIC_IRQ_Registers;

typedef struct
{
   uint32_t S_HW_IT_Id;
   uint32_t S_HW_IT_Line;
   uint32_t S_HW_IT_Line_BitMask;
   uint8_t  S_IRQ_Priority;
} TS_DrvNVIC_IRQ_Config;


/* ---------- provided constants: ------------------------------------------- */
extern TS_DrvNVIC_IRQ_Registers * const C_DrvNVIC_Registers;

extern const TS_DrvNVIC_IRQ_Config C_DrvNVIC_Boot_IRQ_Config [DRVNVIC_BOOT_IRQ_NB];

extern const TS_DrvNVIC_IRQ_Config C_DrvNVIC_Seq_IRQ_Config [DRVNVIC_SEQ_IRQ_NB];

extern const TPTF_DrvNVIC_VectorsTable C_DrvNVIC_VectorsTable_CPU [DRVNVIC_CPU_VECTORS_NB];
extern const TPTF_DrvNVIC_VectorsTable C_DrvNVIC_VectorsTable_MCU [DRVNVIC_MCU_VECTORS_NB];


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void DrvNVIC_Unmapped_IRQ (void);


#endif /* DRVNVIC_PRIVATE_H */
