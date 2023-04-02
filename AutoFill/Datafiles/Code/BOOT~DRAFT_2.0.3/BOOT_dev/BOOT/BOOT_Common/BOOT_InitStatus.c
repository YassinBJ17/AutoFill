#include "BOOT_InitStatus.h"


void BOOT_InitStatus(
    /* IN/OUT */
    boolean_t *p_PinProgPBIT_Failed,
    boolean_t *p_CriticalPBIT_Failed,
    boolean_t *p_MajorPBIT_Failed,
    ts_PBIT_Results *p_PBIT_Results,
    ts_PinProgrammingInputsValues *p_PinProgrammingInputsValues,
    boolean_t *p_LoadFailed,
    boolean_t *p_FlashReadFailed,
    uint32_t *p_LoadedSoftwareLaunchAddress,
    ts_LoadStatus *p_PrimaryLoadStatus,
    uint32_t *p_NumberOfSecondaryLoads,
    ts_LoadStatus p_SecondaryLoadsStatus[C_BOOT_MAX_NUMBER_OF_SECONDARY_LOAD] 
)
{
    *p_PinProgPBIT_Failed = FALSE;
    *p_CriticalPBIT_Failed = FALSE;
    *p_MajorPBIT_Failed = FALSE;
    p_PBIT_Results->PLD_WatchdogPBIT_Failed = FALSE;
    p_PBIT_Results->L2SRAM_PBIT_Failed = FALSE;
    p_PBIT_Results->L2SRAM_ECC_PBIT_Failed = FALSE;
    p_PBIT_Results->SDRAM_PBIT_Failed = FALSE;
    p_PBIT_Results->SDRAM_ECC_PBIT_Failed = FALSE;
    p_PBIT_Results->DecrementerIT_PBIT_Failed = FALSE;
    p_PBIT_Results->SchedulingIT_PBIT_Failed = FALSE;
    p_PBIT_Results->FPU_PBIT_Failed = FALSE;
    p_PBIT_Results->MMU_PBIT_Failed = FALSE;
    p_PBIT_Results->MRAM_PBIT_Failed = FALSE;
    p_PBIT_Results->PinProgAccessPBIT_Failed = FALSE;
    p_PBIT_Results->PinProgParityPBIT_Failed = FALSE;
    p_PBIT_Results->PinProgFlickeringPBIT_Failed = FALSE;
    p_PBIT_Results->PAR_PinProgFlickeringPBIT_Failed = FALSE;
    p_PBIT_Results->LABO_PinProgFlickeringPBIT_Failed = FALSE;
    p_PBIT_Results->DTL_PinProgFlickeringPBIT_Failed = FALSE;
    p_PBIT_Results->ID1_PinProgFlickeringPBIT_Failed = FALSE;
    p_PBIT_Results->ID2_PinProgFlickeringPBIT_Failed = FALSE;
    p_PBIT_Results->ConfRegPBIT_Failed = FALSE;
    p_PinProgrammingInputsValues->PAR = FALSE;
    p_PinProgrammingInputsValues->LABO = FALSE;
    p_PinProgrammingInputsValues->DTL = FALSE;
    p_PinProgrammingInputsValues->ID1 = FALSE;
    p_PinProgrammingInputsValues->ID2 = FALSE;
    *p_LoadFailed = FALSE;
    *p_FlashReadFailed = FALSE;
    *p_LoadedSoftwareLaunchAddress = 0xFFFFFFFFul;
    LIBUTI_MEM_MemSet(
        (uint8_t *)(p_PrimaryLoadStatus), /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> MemSet handles generic buffers */
        (uint8_t)0,
        sizeof(ts_LoadStatus)
    );
    *p_NumberOfSecondaryLoads = 0ul;
    LIBUTI_MEM_MemSet(
        (uint8_t *)(p_SecondaryLoadsStatus), /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> MemSet handles generic buffers */
        (uint8_t)0,
        sizeof(ts_LoadStatus) * C_BOOT_MAX_NUMBER_OF_SECONDARY_LOAD
    );
}