#include "DrvNVIC_Private.h"

   TS_DrvNVIC_IRQ_Registers * const C_DrvNVIC_Registers = (TS_DrvNVIC_IRQ_Registers *) (DRVNVIC_IRQ_ADDRESS);   const TS_DrvNVIC_IRQ_Config C_DrvNVIC_Boot_IRQ_Config [DRVNVIC_BOOT_IRQ_NB] =   {      {17UL, 0UL, 0x00020000UL, 1UL}, {21UL, 0UL, 0x00200000UL, 1UL},      {44UL, 1UL, 0x00001000UL, 1UL}, {45UL, 1UL, 0x00002000UL, 1UL}   };   const TS_DrvNVIC_IRQ_Config C_DrvNVIC_Seq_IRQ_Config [DRVNVIC_SEQ_IRQ_NB] =   {      { 17UL, 0UL, 0x00020000UL, 1}, { 21UL, 0UL, 0x00200000UL, 1}, { 44UL, 1UL, 0x00001000UL, 1},      { 45UL, 1UL, 0x00002000UL, 1}, { 48UL, 1UL, 0x00010000UL, 9}, { 88UL, 2UL, 0x01000000UL, 8},      { 99UL, 3UL, 0x00000008UL, 2}, {100UL, 3UL, 0x00000010UL, 2}, {101UL, 3UL, 0x00000020UL, 2},      {104UL, 3UL, 0x00000100UL, 6}, {107UL, 3UL, 0x00000800UL, 2}, {110UL, 3UL, 0x00004000UL, 6},      {117UL, 3UL, 0x00200000UL, 2}, {119UL, 3UL, 0x00800000UL, 2}, {122UL, 3UL, 0x04000000UL, 7}   };
