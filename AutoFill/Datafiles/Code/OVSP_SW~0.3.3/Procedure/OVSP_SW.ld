/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file is the Linker Command File
 * -------------------------------------------------------------------------- */

DEFAULTS
{
   STACK_MAIN_SIZE = 0x0400
   STACK_PROCESS_SIZE = 0x0400

   SRAM_VECTORS_SIZE = 0x0400
}


MEMORY
{
   Region_Vectors         (RX): ORIGIN = 0x00000000, LENGTH = 0x00000400
   Region_Cartridge       (RX): ORIGIN = 0x00000500, LENGTH = 0x00000100
   Region_Code            (RX): ORIGIN = 0x00000600, LENGTH = 0x0001FA00

   Region_OVSP_Side_Id    (R) : ORIGIN = 0x0007FFFC, LENGTH = 0x00000001

   Region_SRAM            (RW): ORIGIN = 0x1FFF8000, LENGTH = 0x00001200

   Region_Stack_Main      (RW): ORIGIN = 0x1FFF9400, LENGTH = 0x00000400
   Region_Stack_Process   (RW): ORIGIN = 0x1FFFA600, LENGTH = 0x00000400

   Region_SRAM_Vectors    (RW): ORIGIN = 0x20000000, LENGTH = 0x00000400

   Region_CAN_Rx          (RW): ORIGIN = 0x20000800, LENGTH = 0x00000400

   Region_SCADE_DataIn    (RW): ORIGIN = 0x20000C00, LENGTH = 0x00002000
   Region_SCADE_DataOut   (RW): ORIGIN = 0x20002C00, LENGTH = 0x00002000
}


SECTIONS
{
   .VectorsTable:
   {
      __Linker_Vectors_Start = .;
      CSC_Drivers.a(DrvNVIC_VectorsTable_CPU.o)(.rodata)
      CSC_Drivers.a(DrvNVIC_VectorsTable_MCU.o)(.rodata)
      __Linker_Vectors_End = .;
   } > Region_Vectors

   /* Start address setting */
   _start = __Linker_Vectors_Start;

   .OVSP_SW_Cartridge:
   {
      OVSP_SW_Cartridge.o(.rodata)
   } > Region_Cartridge

   .text:
   {
      __Linker_Code_Start = .;
      "*(.text*)"
   } > Region_Code

   .rodata:
   {
      "*(.rodata*)"
      __Linker_Code_End = .;
   } > Region_Code

   .EOC_32Bit_CRC (__Linker_Code_End + SIZEOF (.data)):
   {
      CSC_Drivers.a(DrvFTFC_EOC_32Bit_CRC.o)(.rodata)
   }

   .data: AT (__Linker_Code_End)
   {
      __Linker_Data_Start = .;
      "*(.data*)"
      CSC_Drivers.a(DrvFTFC_Configure_ECC_Test.o)(.text)
      CSC_Drivers.a(DrvFTFC_Data.o)(.rodata)
      CSC_Drivers.a(DrvFTFC_Erase.o)(.text)
      CSC_Drivers.a(DrvFTFC_Write.o)(.text)

      CSC_Drivers.a(DrvFTM_Acquire_RawData.o)(.text)
      CSC_Drivers.a(DrvFTM_Acquire_Raw_NGOS1.o)(.text)
      CSC_Drivers.a(DrvFTM_Acquire_Raw_NGOS2.o)(.text)
      CSC_Drivers.a(DrvFTM_Acquire_Raw_NTLOS1.o)(.text)
      CSC_Drivers.a(DrvFTM_Acquire_Raw_NTLOS2.o)(.text)
      CSC_Drivers.a(DrvFTM_Acquire_Raw_TSpeed.o)(.text)
      CSC_Drivers.a(DrvFTM_Count_FTM0_Overflow.o)(.text)
      CSC_Drivers.a(DrvFTM_Count_FTM1_Overflow.o)(.text)
      CSC_Drivers.a(DrvFTM_Count_FTM3_Overflow.o)(.text)
      CSC_Drivers.a(DrvFTM_Count_Overflow.o)(.text)
      CSC_Drivers.a(DrvFTM_Data.o)(.rodata)
      __Linker_Data_End = .;
   } > Region_SRAM

   .bss:
   {
      __Linker_BSS_Start = .;
      "*(.bss*)"
      __Linker_BSS_End = .;
   } > Region_SRAM

   .Stack_Main:
   {
      __Linker_Stack_Main_Bottom = .;
      . += STACK_MAIN_SIZE;
      __Linker_Stack_Main = .;
   } > Region_Stack_Main

   .Stack_Process:
   {
      __Linker_Stack_Process_Bottom = .;
      . += STACK_PROCESS_SIZE;
      __Linker_Stack_Process = .;
   } > Region_Stack_Process

   .SRAM_VectorsTable:
   {
      __Linker_SRAM_Vectors_Start = .;
      . += SRAM_VECTORS_SIZE;
      __Linker_SRAM_Vectors_End = .;
   } > Region_SRAM_Vectors

   .CAN_RxQueues:
   {
      __Linker_CAN_Rx_Start = .;
      CSC_Drivers.a(DrvCAN_Data_RxQueues.o)(.bss)
      __Linker_CAN_Rx_End = .;
   } > Region_CAN_Rx

   .SCADE_DataIn:
   {
      CSC_OVSP.a(OVSP_Data_SCADE_InContext.o)(.bss)
   } > Region_SCADE_DataIn

   .SCADE_DataOut:
   {
      CSC_OVSP.a(OVSP_Data_SCADE_OutContext.o)(.bss)
   } > Region_SCADE_DataOut
}
