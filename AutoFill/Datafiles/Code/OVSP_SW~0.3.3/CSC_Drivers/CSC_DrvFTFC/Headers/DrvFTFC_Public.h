/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVFTFC_PUBLIC_H
#define DRVFTFC_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVFTFC_PFLASH_START_ADDR      0x00000000UL
#define DRVFTFC_PFLASH_END_ADDR        0x0007FFFFUL

#define DRVFTFC_FLEXNVM_START_ADDR     0x10000000UL
#define DRVFTFC_FLEXNVM_END_ADDR       0x1000FFFFUL

#define DRVFTFC_CONFIG_START_ADDR      DRVFTFC_FLEXNVM_START_ADDR
#define DRVFTFC_CONFIG_SIZE            128UL
#define DRVFTFC_CONFIG_32BIT_NB        32UL

#define DRVFTFC_LOGBOOK_START_ADDR     0x1000FC00UL
#define DRVFTFC_LOGBOOK_SIZE           1024UL
#define DRVFTFC_LOGBOOK_32BIT_NB       256UL


/* ---------- provided types: ----------------------------------------------- */
typedef void (* TPF_DrvFTFC_Configure_ECC_Test) (void);

typedef void (* TPF_DrvFTFC_Erase) (const uint32_t, uint32_t * const);

typedef void (* TPF_DrvFTFC_Write) (const uint8_t  * const p_pt_SrcAddr,
                                    const uint32_t         p_DestAddr,
                                    const uint32_t         p_Length,
                                          uint32_t * const p_pt_Status);


/* ---------- provided constants: ------------------------------------------- */
extern const TPF_DrvFTFC_Configure_ECC_Test C_PtF_DrvFTFC_Config_ECC_Test;

extern const TPF_DrvFTFC_Erase C_PtF_DrvFTFC_Erase;
extern const TPF_DrvFTFC_Write C_PtF_DrvFTFC_Write;


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void DrvFTFC_Check_RegConfig (uint32_t * const p_pt_Check_Result);

extern void DrvFTFC_Check_EOC_32Bit_CRC (uint32_t * const p_pt_Check_Result);

extern void DrvFTFC_Copy_Data_To_RAM (void);

extern void DrvFTFC_Enable_Flash_Fault_It (uint32_t * const p_pt_Set_Status);

extern void DrvFTFC_Clear_Flash_Fault (uint32_t * const p_pt_Clear_Status);


#endif /* DRVFTFC_PUBLIC_H */
