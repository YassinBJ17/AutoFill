/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef LOGBOOK_PRIVATE_H
#define LOGBOOK_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "DrvFTFC_Public.h"

#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define LOGBOOK_FAILURES_NB            100UL


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t S_Failure_Code;
   uint32_t S_Failure_Detail;
} TS_Logbook_Failure;


typedef union
{
   uint32_t U_Array_32BitUint [DRVFTFC_LOGBOOK_32BIT_NB];

   struct
   {
      uint32_t S_Nb_Failures_Logged;
      uint32_t S_Next_Failure_Index;
      TS_Logbook_Failure S_Failures [LOGBOOK_FAILURES_NB];
      uint32_t S_FlexNVM_Mapping_Reserved [54];
   } U_Fields;

} TU_Logbook_FlexNVM_Mapping;


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
extern TU_Logbook_FlexNVM_Mapping V_Logbook;

extern boolean_t V_Logbook_Failure_to_Write;

extern TS_Logbook_Failure V_Logbook_Previous_PBIT_Failure;
extern TS_Logbook_Failure V_Logbook_Previous_CBIT_Failure;


/* ---------- provided operations: ------------------------------------------ */
extern void Logbook_Write_In_FlexNVM (void);


#endif /* LOGBOOK_PRIVATE_H */
