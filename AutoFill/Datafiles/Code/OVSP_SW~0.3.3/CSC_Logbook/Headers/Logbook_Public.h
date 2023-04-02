/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef LOGBOOK_PUBLIC_H
#define LOGBOOK_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define LOGBOOK_PBIT_FAILURE_ID 0x000000AAUL
#define LOGBOOK_CBIT_FAILURE_ID 0x000000BBUL

#define LOGBOOK_NO_FAILURE_CODE 0x00000000UL


/* ---------- provided types: ----------------------------------------------- */
typedef union
{
   uint32_t U_32BitUint;

   struct
   {
      uint32_t S_FC_PFlash_Mem :1;
      uint32_t S_FC_FlexNVM :1;
      uint32_t S_FC_RAM :1;
      uint32_t S_FC_Micro_Reg_Conf :1;
      uint32_t S_FC_Micro_Int_Ressources :1;
      uint32_t S_FC_Unused_3 :3;
      uint32_t S_FC_Discrete_IO :1;
      uint32_t S_FC_Square_IO :1;
      uint32_t S_FC_Analog_In :1;
      uint32_t S_FC_CAN_Bus :1;
      uint32_t S_FC_Unused_2 :4;
      uint32_t S_FC_OVSP_Side_Id :1;
      uint32_t S_FC_EOC_Integrity :1;
      uint32_t S_FC_Config_Integrity :1;
      uint32_t S_FC_Unused_1 :5;
      uint32_t S_FC_xBIT_Id :8;
   } U_Fields;

} TU_Logbook_Failure_Code;


typedef union
{
   uint32_t U_32BitUint;

   struct
   {
      uint32_t S_FD_PFlash_Mem :1;
      uint32_t S_FD_FlexNVM :1;
      uint32_t S_FD_RAM_Addressability :1;
      uint32_t S_FD_RAM_ECC_Single_Bit :1;
      uint32_t S_FD_RAM_ECC_Multi_Bit :1;
      uint32_t S_FD_FPU_Invalid_Operation :1;
      uint32_t S_FD_FPU_Divide_By_Zero :1;
      uint32_t S_FD_FPU_Overflow :1;
      uint32_t S_FD_FPU_Underflow :1;
      uint32_t S_FD_FPU_Inexact :1;
      uint32_t S_FD_FPU_Input_Denormal :1;
      uint32_t S_FD_MCM :1;
      uint32_t S_FD_SPI :1;
      uint32_t S_FD_Flash :1;
      uint32_t S_FD_PCC :1;
      uint32_t S_FD_PAD :1;
      uint32_t S_FD_LPIT :1;
      uint32_t S_FD_GPIO :1;
      uint32_t S_FD_CAM :1;
      uint32_t S_FD_FTM :1;
      uint32_t S_FD_Test_Speed :1;
      uint32_t S_FD_ADC :1;
      uint32_t S_FD_CAN_Bus :1;
      uint32_t S_FD_OVSP_Side_Id :1;
      uint32_t S_FD_EOC_Integrity :1;
      uint32_t S_FD_Config_Integrity :1;
      uint32_t S_FD_Reserved :5;
   } U_Fields;

} TU_Logbook_Failure_Detail;


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void Logbook_Initialize (void);

extern void Logbook_Log_New_Failure (const uint32_t p_Failure_Type,
                                     const uint32_t p_Failure_Code,
                                     const uint32_t p_Failure_Detail);

extern void Logbook_Write_In_FlexNVM (void);

extern boolean_t Logbook_Is_Failure_to_Write (void);


#endif /* LOGBOOK_PUBLIC_H */
