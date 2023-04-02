#include "BOOT_TCAHW_PIC.h"
#include "BOOT_ManageInterrupts.h"
#include "LIBBSP_CMN.h"

 void BOOT_TCAHW_DisableExternalITs(void); const tu_PIC_CTPR_Register PIC_CTPR = {    {       0     } }; const tu_PIC_GCR_Register PIC_GCR_Reset = {    {       1,        0    } }; const tu_PIC_GCR_Register PIC_GCR_Set = {    {       0,       1      } }; const tu_PIC_EIVPR_Register PIC_EIVPR = {    {       1,        0,        1,        0,        C_SCHEDULING_IT_PRIORITY_LVL,       C_BMI_SCHEDULING_IT_VECTOR,    } }; const tu_PIC_EIDR_Register PIC_EIDR = {    {       0,        0,        0,        0,        1,     } }; const tu_PIC_IIVPR_Register PIC_IIVPR = {    {       0,        0,        1,        C_ERROR_INTERNAL_IT_PRIORITY_LVL,       C_BMI_ERROR_INTERNAL_IT_VECTOR,    } }; const tu_PIC_IIDR_Register PIC_IIDR = {    {       0,        0,        1,     } };
