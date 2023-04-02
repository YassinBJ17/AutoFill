   .file "BOOT_TestAndConfigureAdditionalHW_Assembly.s"
   .include "BOOT_Registers.inc"
   .include "BOOT_VectorTable.inc"

   .set MSR_EE_SET_MASK, 0x00008000
   .set MSR_EE_CLEAR_MASK, 0xFFFF7FFF

   .set TCR_DECAR_CLEAR_MASK, 0xFFBFFFFF
   .set TCR_DIE_SET_MASK, 0x04000000
   .set TCR_DIE_CLEAR_MASK, 0xFBFFFFFF
   
   .global BOOT_TCAHW_EnableExternalITs
   .global BOOT_TCAHW_DisableExternalITs
   .global BOOT_TCAHW_LoadDecrementerWith500us
   .global BOOT_TCAHW_EnableDecrementerIT
   .global BOOT_TCAHW_DisableDecrementerIT

BOOT_TCAHW_EnableExternalITs:
   mtsprg2 r3 ; Save R3 in SPRG2
   mfmsr   r3
   oris    r3, r3, MSR_EE_SET_MASK@h
   ori     r3, r3, MSR_EE_SET_MASK@l
   REG_MSR_WRITE r3 
   mfsprg2 r3
   blr
   
BOOT_TCAHW_DisableExternalITs:
   mtsprg2 r3 ; Save R3 in SPRG2
   mtsprg3 r4 ; Save R4 in SPRG3
   lis     r4, MSR_EE_CLEAR_MASK@ha
   addi    r4, r4, MSR_EE_CLEAR_MASK@l
   mfmsr   r3
   and     r3, r3, r4
   REG_MSR_WRITE r3
   mfsprg2 r3
   mfsprg3 r4
   blr

BOOT_TCAHW_LoadDecrementerWith500us:
   mtsprg2 r3 ; Save R3 in SPRG2
   mtsprg3 r4 ; Save R4 in SPRG3
   lis     r3, 0x000061A8@ha ; 25000 ticks in dec = 500us
   addi    r3, r3, 0x000061A8@l
   ;lis     r3, 0x0003D090@ha ; 250000 ticks in dec = 5ms
   ;addi    r3, r3, 0x0003D090@l
   mtdec   r3
   ; Disable auto reload
   lis     r4, TCR_DECAR_CLEAR_MASK@ha
   addi    r4, r4, TCR_DECAR_CLEAR_MASK@l
   mfspr   r3, REG_TCR
   and     r3, r3, r4
   mtspr   REG_TCR, r3
   mfsprg2 r3
   mfsprg3 r4
   blr
   
BOOT_TCAHW_EnableDecrementerIT:
   mtsprg2 r3 ; Save R3 in SPRG2
   mfspr   r3, REG_TCR
   oris    r3, r3, TCR_DIE_SET_MASK@h
   ori     r3, r3, TCR_DIE_SET_MASK@l
   mtspr   REG_TCR, r3
   mfsprg2 r3
   blr
   
BOOT_TCAHW_DisableDecrementerIT:
   mtsprg2 r3 ; Save R3 in SPRG2
   mtsprg3 r4 ; Save R4 in SPRG3
   lis     r4, TCR_DIE_CLEAR_MASK@ha
   addi    r4, r4, TCR_DIE_CLEAR_MASK@l
   mfspr   r3, REG_TCR
   and     r3, r3, r4
   mtspr   REG_TCR, r3
   mfsprg2 r3
   mfsprg3 r4
   blr