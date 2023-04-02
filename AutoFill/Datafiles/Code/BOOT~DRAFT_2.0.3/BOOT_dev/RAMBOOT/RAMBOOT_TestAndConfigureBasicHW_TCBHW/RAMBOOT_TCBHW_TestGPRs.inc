   ; .include "RAMBOOT_Registers.inc"
   ; .include "RAMBOOT_VectorTable.inc"

RAMBOOT_TCBHW_GPRs_FailureHandler:
   b RAMBOOT_TCBHW_InfiniteLoop

RAMBOOT_TCBHW_MoveGPR0_ToGPR31_ThroughAllGPRs: .macro
   mr      r1,r0
   mr      r2,r1
   mr      r3,r2
   mr      r4,r3
   mr      r5,r4
   mr      r6,r5
   mr      r7,r6
   mr      r8,r7
   mr      r9,r8
   mr      r10,r9
   mr      r11,r10
   mr      r12,r11
   mr      r13,r12
   mr      r14,r13
   mr      r15,r14
   mr      r16,r15
   mr      r17,r16
   mr      r18,r17
   mr      r19,r18
   mr      r20,r19
   mr      r21,r20
   mr      r22,r21
   mr      r23,r22
   mr      r24,r23
   mr      r25,r24
   mr      r26,r25
   mr      r27,r26
   mr      r28,r27
   mr      r29,r28
   mr      r30,r29
   mr      r31,r30
   .endm

RAMBOOT_TCBHW_TestGPRs: .macro
   lis     r0,0x00000000@h
   ori     r0,r0,0x55555555@l
   RAMBOOT_TCBHW_MoveGPR0_ToGPR31_ThroughAllGPRs
   cmpli   cr0,r31,0x55555555@l
   bne     RAMBOOT_TCBHW_GPRs_FailureHandler
   
   lis     r0,0x55555555@h
   RAMBOOT_TCBHW_MoveGPR0_ToGPR31_ThroughAllGPRs
   rotrwi  r31,r31,16
   cmpli   cr0,r31,0x55555555@l
   bne     RAMBOOT_TCBHW_GPRs_FailureHandler
   
   lis     r0, 0x00000000@h
   ori     r0,r0,0xAAAAAAAA@l
   RAMBOOT_TCBHW_MoveGPR0_ToGPR31_ThroughAllGPRs
   cmpli   cr0,r31,0xAAAAAAAA@l
   bne     RAMBOOT_TCBHW_GPRs_FailureHandler
   
   lis     r0,0xAAAAAAAA@h
   RAMBOOT_TCBHW_MoveGPR0_ToGPR31_ThroughAllGPRs
   rotrwi  r31,r31,16
   cmpli   cr0,r31,0xAAAAAAAA@l
   bne     RAMBOOT_TCBHW_GPRs_FailureHandler
   .endm