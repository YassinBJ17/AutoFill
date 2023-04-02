#include "BOOT_ManageFailuresAndLaunchSW.h"
#include "BOOT_Consts.h"
#include "BOOT_BootDescriptor.h"
#include "BOOT_JumpToAddress.h"
#include "LIBUTI_BOOT.h"
#include "BOOT_FailMode.h"
#include "LIBUTI_MEM.h"
#include "Memcpy.h"
#include "LIBUTI_CRC.h"
#include "LIBBSP_MRAM.h"
#include "LIBBSP_SHM.h"

#define C_MRAM_LOG_COUNTER_ADDRESS           0x00000000ul
#define C_MRAM_LOG_SLOTS_BASE_ADDRESS        0x00000400ul
#define C_MRAM_LOG_SLOTS_SIZE                0x400ul
#define C_BOOT_DESCRIPTOR_SDRAM_ADDRESS      0x00001000ul

#define C_MRAM_LOG_SIZE sizeof(TU_BOOT_MRAM_LogHW_Word) + sizeof(TS_BOOT_LogLoadsStatus) + sizeof(uint32_t)

#pragma section SECTION_BOOT_SDRAM_LOG "" ".BOOT_SDRAM_LOG"
#pragma use_section SECTION_BOOT_SDRAM_LOG BOOT_SDRAM_Log
TS_BOOT_SDRAM_Log BOOT_SDRAM_Log;

#pragma section SECTION_BOOT_DESCRIPTOR_COPY "" ".BOOT_DESCRIPTOR_COPY"
#pragma use_section SECTION_BOOT_DESCRIPTOR_COPY BootDescriptorCopy
TS_BOOT_BootDescriptor BootDescriptorCopy;

void BOOT_ManageFailuresAndLaunchSW(
   const ts_PBIT_Results* const p_PBIT_Results,
   const ts_PinProgrammingInputsValues* const p_PinProgrammingInputsValues,
   const boolean_t p_LoadFailed,
   const boolean_t p_FlashReadFailed,
   const uint32_t p_LoadedSoftwareLaunchAddress,
   const ts_LoadStatus* const p_PrimaryLoadStatus,
   const uint32_t p_NumberOfSecondaryLoads,
   const ts_LoadStatus p_SecondaryLoadsStatus[C_BOOT_MAX_NUMBER_OF_SECONDARY_LOAD]
)
{
   uint32_t v_Index;
   TE_LIBBSP_MRAM_ErrorCode v_MRAM_ErrorCode;
   TU_BOOT_MRAM_LogHW_Word v_MRAM_LogHW_Word;
   uint32_t v_MRAM_LogCounter;
   uint32_t v_MRAM_LogSlotNumber;
   uint8_t v_MRAM_LogReadBackBuffer[C_MRAM_LOG_SIZE];
   uint16_t v_CRC16_Buffer;
/*SDRAM log*/
   LIBUTI_MEM_MemSet(
      (uint8_t*)&BOOT_SDRAM_Log, /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> MemSet handles generic buffers */
      (uint8_t)0,
      sizeof(TS_BOOT_SDRAM_Log)
   );
   BOOT_SDRAM_Log.HW_Word.HW_WordValue                                         = 0ul;
   BOOT_SDRAM_Log.HW_Word.HW_WordBitField.MRAM_PBIT_Failed                     = (uint32_t)p_PBIT_Results->MRAM_PBIT_Failed;
   BOOT_SDRAM_Log.HW_Word.HW_WordBitField.PinProgAccessPBIT_Failed             = (uint32_t)p_PBIT_Results->PinProgAccessPBIT_Failed;
   BOOT_SDRAM_Log.HW_Word.HW_WordBitField.PinProgParityPBIT_Failed             = (uint32_t)p_PBIT_Results->PinProgParityPBIT_Failed;
   BOOT_SDRAM_Log.HW_Word.HW_WordBitField.PAR_PinProgFlickeringPBIT_Failed     = (uint32_t)p_PBIT_Results->PAR_PinProgFlickeringPBIT_Failed;
   BOOT_SDRAM_Log.HW_Word.HW_WordBitField.LABO_PinProgFlickeringPBIT_Failed    = (uint32_t)p_PBIT_Results->LABO_PinProgFlickeringPBIT_Failed;
   BOOT_SDRAM_Log.HW_Word.HW_WordBitField.DTL_PinProgFlickeringPBIT_Failed     = (uint32_t)p_PBIT_Results->DTL_PinProgFlickeringPBIT_Failed;
   BOOT_SDRAM_Log.HW_Word.HW_WordBitField.ID1_PinProgFlickeringPBIT_Failed     = (uint32_t)p_PBIT_Results->ID1_PinProgFlickeringPBIT_Failed;
   BOOT_SDRAM_Log.HW_Word.HW_WordBitField.ID2_PinProgFlickeringPBIT_Failed     = (uint32_t)p_PBIT_Results->ID2_PinProgFlickeringPBIT_Failed;
   BOOT_SDRAM_Log.HW_Word.HW_WordBitField.Expander2AccessPBIT_Failed           = (uint32_t)p_PBIT_Results->Expander2AccessPBIT_Failed;
   BOOT_SDRAM_Log.PinProg.PinProgValue         = 0ul;
   BOOT_SDRAM_Log.PinProg.PinProgBitField.PAR  = (uint32_t)p_PinProgrammingInputsValues->PAR;
   BOOT_SDRAM_Log.PinProg.PinProgBitField.LABO = (uint32_t)p_PinProgrammingInputsValues->LABO;
   BOOT_SDRAM_Log.PinProg.PinProgBitField.DTL  = (uint32_t)p_PinProgrammingInputsValues->DTL;
   BOOT_SDRAM_Log.PinProg.PinProgBitField.ID1  = (uint32_t)p_PinProgrammingInputsValues->ID1;
   BOOT_SDRAM_Log.PinProg.PinProgBitField.ID2  = (uint32_t)p_PinProgrammingInputsValues->ID2;
   
   LibC_Memcpy(
      BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.Name,
      p_PrimaryLoadStatus->Name,
      C_BOOT_LOAD_NAME_MAX_LENGTH
   );
   BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.PartNumberSize = (uint8_t) p_PrimaryLoadStatus->PartNumberSize; /* %RELAX<SYNCHRONe_C_Code_10.7> P/N size is stored as uint8_t in SDRAM. Value always fit on 8bits */
   LibC_Memcpy(
      BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.PartNumber,
      p_PrimaryLoadStatus->PartNumber,
      C_BOOT_PN_LENGTH
   );
   BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.LoadStatus.LoadStatusValue
      = 0ul;
   BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.LoadStatus.LoadStatusBitField.Corrupted
      = (uint32_t)p_PrimaryLoadStatus->Corrupted;
   BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.LoadStatus.LoadStatusBitField.OutOfOperationalCondition
      = (uint32_t)p_PrimaryLoadStatus->OutOfOperationalCondition;
   BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.LoadStatus.LoadStatusBitField.Incompatible
      = (uint32_t)p_PrimaryLoadStatus->Incompatible;
   BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.CRC_32 = p_PrimaryLoadStatus->CRC_32;
   BOOT_SDRAM_Log.LoadsStatus.NumberOfSecondaryLoads = p_NumberOfSecondaryLoads;
   for(v_Index=0ul;v_Index<p_NumberOfSecondaryLoads;v_Index++)
   {
      LibC_Memcpy(
         BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[v_Index].Name,
         p_SecondaryLoadsStatus[v_Index].Name,
         C_BOOT_LOAD_NAME_MAX_LENGTH
      );
      BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[v_Index].PartNumberSize = (uint8_t)p_SecondaryLoadsStatus[v_Index].PartNumberSize; /* %RELAX<SYNCHRONe_C_Code_10.7> P/N size is stored as uint8_t in SDRAM. Value always fit on 8bits */
      LibC_Memcpy(
         BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[v_Index].PartNumber,
         p_SecondaryLoadsStatus[v_Index].PartNumber,
         C_BOOT_PN_LENGTH
      );
      BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[v_Index].LoadStatus.LoadStatusValue
         = 0ul;
      BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[v_Index].LoadStatus.LoadStatusBitField.Corrupted
         = (uint32_t)p_SecondaryLoadsStatus[v_Index].Corrupted;
      BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[v_Index].LoadStatus.LoadStatusBitField.OutOfOperationalCondition
         = (uint32_t)p_SecondaryLoadsStatus[v_Index].OutOfOperationalCondition;
      BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[v_Index].LoadStatus.LoadStatusBitField.Incompatible
         = (uint32_t)p_SecondaryLoadsStatus[v_Index].Incompatible;
      BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[v_Index].CRC_32
         = p_SecondaryLoadsStatus[v_Index].CRC_32;
   }
/*MRAM log*/
   if((*p_PBIT_Results).MRAM_PBIT_Failed == FALSE)
   {
      v_MRAM_LogHW_Word.HW_Word_value = 0ul;
      v_MRAM_LogHW_Word.HW_WordBitField.SDRAM_ECC_PBIT_Failed             = (uint32_t)p_PBIT_Results->SDRAM_ECC_PBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.L2SRAM_ECC_PBIT_Failed            = (uint32_t)p_PBIT_Results->L2SRAM_ECC_PBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.SDRAM_PBIT_Failed                 = (uint32_t)p_PBIT_Results->SDRAM_PBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.L2SRAM_PBIT_Failed                = (uint32_t)p_PBIT_Results->L2SRAM_PBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.PLD_WatchdogPBIT_Failed           = (uint32_t)p_PBIT_Results->PLD_WatchdogPBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.DecrementerIT_PBIT_Failed         = (uint32_t)p_PBIT_Results->DecrementerIT_PBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.SchedulingIT_PBIT_Failed          = (uint32_t)p_PBIT_Results->SchedulingIT_PBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.FPU_PBIT_Failed                   = (uint32_t)p_PBIT_Results->FPU_PBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.MMU_PBIT_Failed                   = (uint32_t)p_PBIT_Results->MMU_PBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.PinProgAccessPBIT_Failed          = (uint32_t)p_PBIT_Results->PinProgAccessPBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.PinProgParityPBIT_Failed          = (uint32_t)p_PBIT_Results->PinProgParityPBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.PinProgFlickeringPBIT_Failed      = (uint32_t)p_PBIT_Results->PinProgFlickeringPBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.PAR_PinProgFlickeringPBIT_Failed  = (uint32_t)p_PBIT_Results->PAR_PinProgFlickeringPBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.LABO_PinProgFlickeringPBIT_Failed = (uint32_t)p_PBIT_Results->LABO_PinProgFlickeringPBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.DTL_PinProgFlickeringPBIT_Failed  = (uint32_t)p_PBIT_Results->DTL_PinProgFlickeringPBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.ID1_PinProgFlickeringPBIT_Failed  = (uint32_t)p_PBIT_Results->ID1_PinProgFlickeringPBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.ID2_PinProgFlickeringPBIT_Failed  = (uint32_t)p_PBIT_Results->ID2_PinProgFlickeringPBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.ConfRegPBIT_Failed                = (uint32_t)p_PBIT_Results->ConfRegPBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.Expander2AccessPBIT_Failed        = (uint32_t)p_PBIT_Results->Expander2AccessPBIT_Failed;
      v_MRAM_LogHW_Word.HW_WordBitField.FlashReadFailed                   = (uint32_t)p_FlashReadFailed;

      v_MRAM_ErrorCode = LIBBSP_MRAM_Open();
      if(v_MRAM_ErrorCode == E_LIBBSP_MRAM_OK)
      {
         /*Read v_MRAM_LogCounter*/
         /* {{RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> 3rd parameter of LIBBSP_MRAM_Read/Write should be the address of a buffer */
         LIBBSP_MRAM_Read(
            C_MRAM_LOG_COUNTER_ADDRESS,
            sizeof(uint32_t),
            (uint8_t*)&v_MRAM_LogCounter,
            &v_MRAM_ErrorCode
         );
         v_MRAM_LogCounter = v_MRAM_LogCounter + 1ul;
         v_MRAM_LogSlotNumber = (v_MRAM_LogCounter - 1ul) % 8ul;
         LIBBSP_MRAM_Write(
            C_MRAM_LOG_COUNTER_ADDRESS,
            sizeof(uint32_t),
            (uint8_t*)&v_MRAM_LogCounter,
            &v_MRAM_ErrorCode
         );
         LIBBSP_MRAM_Write(
            C_MRAM_LOG_SLOTS_BASE_ADDRESS + (v_MRAM_LogSlotNumber * C_MRAM_LOG_SLOTS_SIZE),
            sizeof(TU_BOOT_MRAM_LogHW_Word),
            (uint8_t*)&v_MRAM_LogHW_Word,
            &v_MRAM_ErrorCode
         );
         LIBBSP_MRAM_Write(
            C_MRAM_LOG_SLOTS_BASE_ADDRESS + (v_MRAM_LogSlotNumber * C_MRAM_LOG_SLOTS_SIZE)
               + sizeof(TU_BOOT_MRAM_LogHW_Word),
            sizeof(TS_BOOT_LogLoadsStatus),
            (uint8_t*)&BOOT_SDRAM_Log.LoadsStatus,
            &v_MRAM_ErrorCode
         );
         LIBBSP_MRAM_Write(
            C_MRAM_LOG_SLOTS_BASE_ADDRESS + (v_MRAM_LogSlotNumber * C_MRAM_LOG_SLOTS_SIZE)
               + sizeof(TU_BOOT_MRAM_LogHW_Word) + sizeof(TS_BOOT_LogLoadsStatus),
            sizeof(uint32_t),
            (uint8_t*)&v_MRAM_LogCounter,
            &v_MRAM_ErrorCode
         );
         /*Read back MRAM log*/
         LIBBSP_MRAM_Read(
            C_MRAM_LOG_SLOTS_BASE_ADDRESS + (v_MRAM_LogSlotNumber * C_MRAM_LOG_SLOTS_SIZE),
            C_MRAM_LOG_SIZE,
            v_MRAM_LogReadBackBuffer,
            &v_MRAM_ErrorCode
         );
         /*Read back MRAM log and compute CRC16*/
         v_CRC16_Buffer = LIBUTI_CRC_ComputeCRC16(v_MRAM_LogReadBackBuffer, C_MRAM_LOG_SIZE);
         LIBBSP_MRAM_Write(
            C_MRAM_LOG_SLOTS_BASE_ADDRESS + (v_MRAM_LogSlotNumber * C_MRAM_LOG_SLOTS_SIZE) + C_MRAM_LOG_SIZE,
            sizeof(uint16_t),
            (uint8_t*)(&v_CRC16_Buffer),
            &v_MRAM_ErrorCode
         );
         /* }} RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> */
         (void) LIBBSP_MRAM_Close();
      }
   }
/*SW launch or fail mode*/
   if(p_LoadFailed == FALSE)
   {
      LIBBSP_SHM_SetMode(E_LIBBSP_SHM_IDLE_STATE, C_PLD_COMPAGNON_PBITOK_SWITCH_GOLDEN);
      LibC_Memcpy(&BootDescriptorCopy, &C_BOOT_DESCRIPTOR, sizeof(TS_BOOT_BootDescriptor));
      BOOT_JumpToAddress(p_LoadedSoftwareLaunchAddress);
   } else {
      BOOT_FailMode();
   }
}
