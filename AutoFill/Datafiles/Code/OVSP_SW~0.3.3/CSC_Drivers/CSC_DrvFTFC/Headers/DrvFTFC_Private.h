/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVFTFC_PRIVATE_H
#define DRVFTFC_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
extern void * __Linker_Code_End;

extern void * __Linker_Data_Start;
extern void * __Linker_Data_End;


/* ---------- provided define constants: ------------------------------------ */
#define DRVFTFC_FTCF_ADDRESS             0x40020000UL

#define DRVFTFC_FIELD_KEY_START_ADDR     0x00000400UL
#define DRVFTFC_CARTRIDGE_START_ADDR     0x00000500UL

#define DRVFTFC_FLEXNVM_ADDR_MASK        0x0000FFFFUL
#define DRVFTFC_FLEXNVM_SELECTION        0x00800000UL

#define DRVFTFC_FSTAT_CCIF_MASK          ((uint8_t) 0x80)
#define DRVFTFC_FSTAT_LAUNCH_CMD         ((uint8_t) 0x80)
#define DRVFTFC_FSTAT_CMD_COMPLETED      ((uint8_t) 0x00)
#define DRVFTFC_FSTAT_FPVIOL_ACCERR_MASK ((uint8_t) 0x30)
#define DRVFTFC_FSTAT_ERRORS_MASK        ((uint8_t) 0x70)
#define DRVFTFC_FSTAT_NO_ERROR           ((uint8_t) 0x00)

#define DRVFTFC_FCCOB0_ERASE_CMD         ((uint8_t) 0x09)
#define DRVFTFC_FCCOB0_WRITE_CMD         ((uint8_t) 0x07)

#define DRVFTFC_FERSTAT_DFDIF_MASK       ((uint8_t) 0x02)
#define DRVFTFC_FERSTAT_DFDIF_RESET      ((uint8_t) 0x00)

#define DRVFTFC_FERCNFG_CLEAR_VALUE      ((uint8_t) 0x00)
#define DRVFTFC_FERCNFG_DFDIE_MASK       ((uint8_t) 0x02)
#define DRVFTFC_FERCNFG_FDFD_CONFIG      ((uint8_t) 0x20)

#define DRVFTFC_32BIT_CRC_INIT_VALUE     0xFFFFFFFFUL


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint8_t S_FSTAT;
   uint8_t S_FCNFG;
   uint8_t S_FSEC;
   uint8_t S_FOPT;
   uint8_t S_FCCOB3;
   uint8_t S_FCCOB2;
   uint8_t S_FCCOB1;
   uint8_t S_FCCOB0;
   uint8_t S_FCCOB7;
   uint8_t S_FCCOB6;
   uint8_t S_FCCOB5;
   uint8_t S_FCCOB4;
   uint8_t S_FCCOBB;
   uint8_t S_FCCOBA;
   uint8_t S_FCCOB9;
   uint8_t S_FCCOB8;
   uint8_t S_FPROT3;
   uint8_t S_FPROT2;
   uint8_t S_FPROT1;
   uint8_t S_FPROT0;
   uint8_t S_FTFC_Reserved_1 [2];
   uint8_t S_FEPROT;
   uint8_t S_FDPROT;
   uint8_t S_FTFC_Reserved_2 [20];
   uint8_t S_FCSESTAT;
   uint8_t S_FTFC_Reserved_3 ;
   uint8_t S_FERSTAT;
   uint8_t S_FERCNFG;
} TS_DrvFTFC_Registers;


/* ---------- provided constants: ------------------------------------------- */
extern TS_DrvFTFC_Registers * const C_DrvFTFC_Registers;

extern const uint32_t C_DrvFTFC_EOC_32Bit_CRC;


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void DrvFTFC_Compute_32Bit_CRC (const uint8_t  * const pt_StartAddr,
                                       const uint32_t         p_Length,
                                             uint32_t * const pt_CrcComputed);

extern void DrvFTFC_Configure_ECC_Test (void);

extern void DrvFTFC_Erase (const uint32_t p_StartAddr, uint32_t * const p_pt_Status);

extern void DrvFTFC_Write (const uint8_t  * const p_pt_SrcAddr,
                           const uint32_t         p_DestAddr,
                           const uint32_t         p_Length,
                                 uint32_t * const p_pt_Status);


#endif /* DRVFTFC_PRIVATE_H */
