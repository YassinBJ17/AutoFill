#ifndef BOOT_MEM_public_H
#define BOOT_MEM_public_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"
/* ---------- external define constants: ------------------------------------ */

/*************/
#define SRAM_ECC_ON_VALUE   0x00000001ul
#define SRAM_ECC_OFF_VALUE  0x00000000ul
/*   RAMs    */
/*************/
#define SYSTEM_RAM_L    ((uint8_t*)0x40000000)
#define SYSTEM_RAM_H ((uint8_t*)0x40064FFF)

/* The size is the same for all cores */
#define IMEM_SIZE   0x4000ul
#define DMEM_SIZE   0x10000ul

#define INIT_SRAM_VAL 0x00000000

/************/
/*   EBI    */
/************/

#define EBI_RSRVD_A_SIZE (3)
#define EBI_RSRVD_B_SIZE (59)

/* */
#define EBI_BASE_ADDR (0xFFFF0000)

/* MCR : Automatic CLKOUT Gating is disabled, Module Disable Mode is inactive, DATA[0:15] signals are used for */
/* 16-bit port accesses, 32-bit Data Bus Mode is used */
#define EBI_MCR_VAL (0x00000800UL)

/* BR0 : Base address : 0x20000000, LWRN=0, PS=0 (32-bit port), EOE=b00, SBL=0, AD_MUX=0, BL=0, WEBS=1, TDIP=0,*/
/* GCSN=0, BI=1 (burst inhibit), V=1 (bank is valid) */
/* MRAM  - size: 0x400000 (4Mo) */
#define EBI_BR0_VAL (0x20000823UL)

/* BR1 : Base address : 0x20000000, LWRN=0, PS=0 (32-bit port), EOE=b01, SBL=0, AD_MUX=0, BL=1, WEBS=0, TDIP=0,*/
/* GCSN=0, BI=0 (burst enabled), V=1 (bank is valid) */
/* FPGA1 - size: 0x400000 (4Mo) */
#define EBI_BR1_VAL (0x21000251UL)

/* BR2 : Base address : 0x22000000, LWRN=0, PS=0 (32-bit port), EOE=b01, SBL=0, AD_MUX=0, BL=1, WEBS=1, TDIP=0,*/
/* GCSN=0, BI=0 (burst enable), V=1 (bank is valid) */
/* FPGA2 - size: 0x400000 (4Mo) */
#define EBI_BR2_VAL (0x24000271UL)

/* ORx : 4Mo accessible, APS=1, PS=0, AWE=1, SCY=3; BSCY=0 */
#define EBI_OR0_VAL (0xFFF01450UL)

/* ORx : 16Mo accessible, APS=1, AWE=1, SCY=0; BSCY=0 */
#define EBI_OR1_VAL (0xFFE01400UL)

/* ORx : 16Mo accessible, APS=1, AWE=0, SCY=3; BSCY=03 */
#define EBI_OR2_VAL (0xFF801036UL)

/************/
/*          */
/************/

/************/
/*   SMPU    */
/************/
#define SMPU_BASE_ADDR (0xFC010000)

#define SMPU_CESR0                  (0x00008001ul)
#define SMPU_CESR0_DIS              (0x00008000ul)

/************/
/*          */
/************/

/*   CMPU    */

#define MPU0CSR0_BASE_ADDR (0xFFFB8000)

/* ---------- external types: ----------------------------------------------- */

/************/
/*   EBI    */
/************/

/* */
typedef struct
{
   reg32_t s_EBI_MCR;
   reg32_t s_EBI_rsvdA[EBI_RSRVD_A_SIZE];
   reg32_t s_EBI_BR0;
   reg32_t s_EBI_OR0;
   reg32_t s_EBI_BR1;
   reg32_t s_EBI_OR1;
   reg32_t s_EBI_BR2;
   reg32_t s_EBI_OR2;
}
ts_EBI_REG;


/*************/
/*   SMPU    */
/*************/

/* none */
#define SMPU_RSRVD_A_SIZE (254)
#define SMPU_RSRVD_B_SIZE (32)

typedef struct
{
   reg32_t s_SMPU_CESR0;
   reg32_t s_SMPU_CESR1;
   reg32_t s_SMPU_rsvdA[SMPU_RSRVD_A_SIZE];
   reg32_t s_SMPU_RGD0_WORD0;
   reg32_t s_SMPU_RGD0_WORD1;
   reg32_t s_SMPU_RGD0_WORD2_FTM0;
   reg32_t s_SMPU_RGD0_WORD3;
   reg32_t s_SMPU_RGD1_WORD0;
   reg32_t s_SMPU_RGD1_WORD1;
   reg32_t s_SMPU_RGD1_WORD2_FTM0;
   reg32_t s_SMPU_RGD1_WORD3;
   reg32_t s_SMPU_RGD2_WORD0;
   reg32_t s_SMPU_RGD2_WORD1;
   reg32_t s_SMPU_RGD2_WORD2_FTM0;
   reg32_t s_SMPU_RGD2_WORD3;
   reg32_t s_SMPU_RGD3_WORD0;
   reg32_t s_SMPU_RGD3_WORD1;
   reg32_t s_SMPU_RGD3_WORD2_FTM0;
   reg32_t s_SMPU_RGD3_WORD3;
   reg32_t s_SMPU_rsvdB[SMPU_RSRVD_B_SIZE];
}
ts_SMPU_REG;

typedef struct
{
   uint32_t s_CONF_SMPU_RGD0_WORD0;
   uint32_t s_CONF_SMPU_RGD0_WORD1;
   uint32_t s_CONF_SMPU_RGD0_WORD2_FTM0;
   uint32_t s_CONF_SMPU_RGD0_WORD3;
   uint32_t s_CONF_SMPU_RGD1_WORD0;
   uint32_t s_CONF_SMPU_RGD1_WORD1;
   uint32_t s_CONF_SMPU_RGD1_WORD2_FTM0;
   uint32_t s_CONF_SMPU_RGD1_WORD3;
   uint32_t s_CONF_SMPU_RGD2_WORD0;
   uint32_t s_CONF_SMPU_RGD2_WORD1;
   uint32_t s_CONF_SMPU_RGD2_WORD2_FTM0;
   uint32_t s_CONF_SMPU_RGD2_WORD3;
   uint32_t s_CONF_SMPU_RGD3_WORD0;
   uint32_t s_CONF_SMPU_RGD3_WORD1;
   uint32_t s_CONF_SMPU_RGD3_WORD2_FTM0;
   uint32_t s_CONF_SMPU_RGD3_WORD3;
}
ts_SMPU_CONF;

/*************/
/*    MPU    */
/*************/

typedef enum
{
   e_MPU_DIS_VAL = 0x0,
   e_MPU_EN_VAL = 0x1,
   e_MPU_INV_VAL = 0x2
} te_MPU_CONFIG_VAL;


/************/
/*          */
/************/

/* ---------- external operations: ------------------------------------------ */
/* none */

/* ---------- external datas: ----------------------------------------------- */
/* none */ 

/* ---------- external constants: ------------------------------------------- */
/* {{RELAX<SYNCHRONe_C_Code_8.15> The memory area is modified in an assembly function which is not */
/* analysed by rulechecker*/
extern uint8_t * const c_IMEM0_L;
extern uint8_t * const c_IMEM0_H;
extern uint8_t * const c_DMEM0_L;
extern uint8_t * const c_DMEM0_H;
                 
extern uint8_t * const c_IMEM1_L;
extern uint8_t * const c_IMEM1_H;
extern uint8_t * const c_DMEM1_L;
extern uint8_t * const c_DMEM1_H;
                 
extern uint8_t * const c_IMEM2_L;
extern uint8_t * const c_IMEM2_H;
extern uint8_t * const c_DMEM2_L;
extern uint8_t * const c_DMEM2_H;
/* }}<SYNCHRONe_C_Code_8.15> */
/* ---------- provided operations: ------------------------------------------- */
/* none */

/* */
extern void BOOT_MEM_EBI_INIT( void );

extern void BOOT_MEM_CMPU_CONFIG( te_MPU_CONFIG_VAL const p_value  ) ;

extern void BOOT_MEM_SMPU_CONFIG_PBIT( void );
extern void BOOT_MEM_SMPU_CONFIG( void ) ;
extern void BOOT_MEM_SMPU_DISABLE( void ) ;

extern void BOOT_MEM_MPU_WRITE_ENTRY
( uint32_t const p_mas0, uint32_t const p_mas1, uint32_t const p_mas2, uint32_t const p_mas3 );

extern void BOOT_MEM_ECC_CONFIG( uint32_t const p_DCR_init_value ) ;

extern void BOOT_MEM_LRAM_CTRL_INIT( void );
extern void BOOT_MEM_RAM_INIT(uint8_t * const p_start, uint8_t* const p_end);
extern void BOOT_MEM_LRAM_INIT( void );

#endif /* BOOT_MEM_public_H */
