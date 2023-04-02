   .file "BOOT_ManageExceptions.s"
   .include "BOOT_Registers.inc"
   .include "BOOT_VectorTable.inc"

   .global ClearDecrementerIT_Status
   .global SaveContext
   .global RestoreContext
   .global CriticalInputInterruptHandler
   .global MachineCheckInterruptHandler
   .global DataStorageInterruptHandler
   .global InstructionStorageInterruptHandler
   .global AlignementInterruptHandler
   .global ProgramInterruptHandler
   .global SystemCallInterruptHandler
   .global FPU_UnavailableInterruptHandler
   .global FixedIntervalTimerInterruptHandler
   .global InstructionTLB_InterruptHandler
   .global DebugInterruptHandler
   .global SPE_APU_UnavailableInterruptHandler
   .global EFP_DataExceptionInterruptHandler
   .global EFP_RoundExceptionInterruptHandler
   .global PerformanceMonitorInterruptHandler

   .set C_IT_CONTEXT_BACKUP_SIZE           ,512

   .set C_R0_IT_CONTEXT_BACKUP_OFFSET      ,32
   .set C_R0_IT_CONTEXT_BACKUP_OFFSET_LOW  ,36
   .set C_R1_IT_CONTEXT_BACKUP_OFFSET      ,40
   .set C_R1_IT_CONTEXT_BACKUP_OFFSET_LOW  ,44
   .set C_R2_IT_CONTEXT_BACKUP_OFFSET      ,48
   .set C_R2_IT_CONTEXT_BACKUP_OFFSET_LOW  ,52
   .set C_R3_IT_CONTEXT_BACKUP_OFFSET      ,56
   .set C_R3_IT_CONTEXT_BACKUP_OFFSET_LOW  ,60
   .set C_R4_IT_CONTEXT_BACKUP_OFFSET      ,64
   .set C_R4_IT_CONTEXT_BACKUP_OFFSET_LOW  ,68
   .set C_R5_IT_CONTEXT_BACKUP_OFFSET      ,72
   .set C_R5_IT_CONTEXT_BACKUP_OFFSET_LOW  ,76
   .set C_R6_IT_CONTEXT_BACKUP_OFFSET      ,80
   .set C_R6_IT_CONTEXT_BACKUP_OFFSET_LOW  ,84
   .set C_R7_IT_CONTEXT_BACKUP_OFFSET      ,88
   .set C_R7_IT_CONTEXT_BACKUP_OFFSET_LOW  ,92
   .set C_R8_IT_CONTEXT_BACKUP_OFFSET      ,96
   .set C_R8_IT_CONTEXT_BACKUP_OFFSET_LOW  ,100
   .set C_R9_IT_CONTEXT_BACKUP_OFFSET      ,104
   .set C_R9_IT_CONTEXT_BACKUP_OFFSET_LOW  ,108
   .set C_R10_IT_CONTEXT_BACKUP_OFFSET     ,112
   .set C_R10_IT_CONTEXT_BACKUP_OFFSET_LOW ,116
   .set C_R11_IT_CONTEXT_BACKUP_OFFSET     ,120
   .set C_R11_IT_CONTEXT_BACKUP_OFFSET_LOW ,124
   .set C_R12_IT_CONTEXT_BACKUP_OFFSET     ,128
   .set C_R12_IT_CONTEXT_BACKUP_OFFSET_LOW ,132
   .set C_R13_IT_CONTEXT_BACKUP_OFFSET     ,136
   .set C_R13_IT_CONTEXT_BACKUP_OFFSET_LOW ,140
   .set C_R14_IT_CONTEXT_BACKUP_OFFSET     ,144
   .set C_R14_IT_CONTEXT_BACKUP_OFFSET_LOW ,148
   .set C_R15_IT_CONTEXT_BACKUP_OFFSET     ,152
   .set C_R15_IT_CONTEXT_BACKUP_OFFSET_LOW ,156
   .set C_R16_IT_CONTEXT_BACKUP_OFFSET     ,160
   .set C_R16_IT_CONTEXT_BACKUP_OFFSET_LOW ,164
   .set C_R17_IT_CONTEXT_BACKUP_OFFSET     ,168
   .set C_R17_IT_CONTEXT_BACKUP_OFFSET_LOW ,172
   .set C_R18_IT_CONTEXT_BACKUP_OFFSET     ,176
   .set C_R18_IT_CONTEXT_BACKUP_OFFSET_LOW ,180
   .set C_R19_IT_CONTEXT_BACKUP_OFFSET     ,184
   .set C_R19_IT_CONTEXT_BACKUP_OFFSET_LOW ,188
   .set C_R20_IT_CONTEXT_BACKUP_OFFSET     ,192
   .set C_R20_IT_CONTEXT_BACKUP_OFFSET_LOW ,196
   .set C_R21_IT_CONTEXT_BACKUP_OFFSET     ,200
   .set C_R21_IT_CONTEXT_BACKUP_OFFSET_LOW ,204
   .set C_R22_IT_CONTEXT_BACKUP_OFFSET     ,208
   .set C_R22_IT_CONTEXT_BACKUP_OFFSET_LOW ,212
   .set C_R23_IT_CONTEXT_BACKUP_OFFSET     ,216
   .set C_R23_IT_CONTEXT_BACKUP_OFFSET_LOW ,220
   .set C_R24_IT_CONTEXT_BACKUP_OFFSET     ,224
   .set C_R24_IT_CONTEXT_BACKUP_OFFSET_LOW ,228
   .set C_R25_IT_CONTEXT_BACKUP_OFFSET     ,232
   .set C_R25_IT_CONTEXT_BACKUP_OFFSET_LOW ,236
   .set C_R26_IT_CONTEXT_BACKUP_OFFSET     ,240
   .set C_R26_IT_CONTEXT_BACKUP_OFFSET_LOW ,244
   .set C_R27_IT_CONTEXT_BACKUP_OFFSET     ,248
   .set C_R27_IT_CONTEXT_BACKUP_OFFSET_LOW ,252
   .set C_R28_IT_CONTEXT_BACKUP_OFFSET     ,256
   .set C_R28_IT_CONTEXT_BACKUP_OFFSET_LOW ,260
   .set C_R29_IT_CONTEXT_BACKUP_OFFSET     ,264
   .set C_R29_IT_CONTEXT_BACKUP_OFFSET_LOW ,268
   .set C_R30_IT_CONTEXT_BACKUP_OFFSET     ,272
   .set C_R30_IT_CONTEXT_BACKUP_OFFSET_LOW ,276
   .set C_R31_IT_CONTEXT_BACKUP_OFFSET     ,280
   .set C_R31_IT_CONTEXT_BACKUP_OFFSET_LOW ,284
   
   .set C_CR_IT_CONTEXT_BACKUP_OFFSET      ,0
   .set C_XER_IT_CONTEXT_BACKUP_OFFSET     ,4
   .set C_LR_IT_CONTEXT_BACKUP_OFFSET      ,8
   .set C_CTR_IT_CONTEXT_BACKUP_OFFSET     ,12
   .set C_SRR0_IT_CONTEXT_BACKUP_OFFSET    ,16
   .set C_SRR1_IT_CONTEXT_BACKUP_OFFSET    ,20
   .set C_SPEFSCR_IT_CONTEXT_BACKUP_OFFSET ,288

   .set TSR_DIS_SET_MASK, 0x08000000

ClearDecrementerIT_Status:
   mtsprg2 r3 ; Save R3 in SPRG2
   mfspr   r3, REG_TSR
   oris    r3, r3, TSR_DIS_SET_MASK@h
   ori     r3, r3, TSR_DIS_SET_MASK@l
   mtspr   REG_TSR, r3
   mfsprg2 r3
   blr

; Save
SaveContext:
   stwu        r1, -C_IT_CONTEXT_BACKUP_SIZE(r1)
   
   mtsprg1     r3
   REG_MSR_SET_SPE r3
   mfsprg1     r3
   
   stw         r0, C_R0_IT_CONTEXT_BACKUP_OFFSET_LOW(r1)   ; Store lower 32bits of r0
   evmergelohi r0, r0, r0      ; Invert high and low orders 32bits of r0
   stw         r0, C_R0_IT_CONTEXT_BACKUP_OFFSET    (r1)   ; Store upper 32bits of r0
   evmergelohi r0, r0, r0      ; Invert high and low orders 32bits of r0
   
   ; stw         r1, C_R1_IT_CONTEXT_BACKUP_OFFSET_LOW(r1)   ; Store lower 32bits of r1
   ; evmergelohi r1, r1, r1      ; Invert high and low orders 32bits of r1
   ; stw         r1, C_R1_IT_CONTEXT_BACKUP_OFFSET    (r1)   ; Store upper 32bits of r1
   ; evmergelohi r1, r1, r1      ; Invert high and low orders 32bits of r1
   
   stw         r2, C_R2_IT_CONTEXT_BACKUP_OFFSET_LOW(r1)   ; Store lower 32bits of r2
   evmergelohi r2, r2, r2      ; Invert high and low orders 32bits of r2
   stw         r2, C_R2_IT_CONTEXT_BACKUP_OFFSET    (r1)   ; Store upper 32bits of r2
   evmergelohi r2, r2, r2      ; Invert high and low orders 32bits of r2
   
   stw         r3, C_R3_IT_CONTEXT_BACKUP_OFFSET_LOW(r1)   ; Store lower 32bits of r3
   evmergelohi r3, r3, r3      ; Invert high and low orders 32bits of r3 in r3
   stw         r3, C_R3_IT_CONTEXT_BACKUP_OFFSET    (r1)   ; Store upper 32bits of r3
   evmergelohi r3, r3, r3      ; Invert high and low orders 32bits of r3 in r3
   
   stw         r4, C_R4_IT_CONTEXT_BACKUP_OFFSET_LOW(r1)   ; Store lower 32bits of r4
   evmergelohi r4, r4, r4      ; Invert high and low orders 32bits of r4
   stw         r4, C_R4_IT_CONTEXT_BACKUP_OFFSET    (r1)   ; Store upper 32bits of r4
   evmergelohi r4, r4, r4      ; Invert high and low orders 32bits of r4
   
   stw         r5, C_R5_IT_CONTEXT_BACKUP_OFFSET_LOW(r1)   ; Store lower 32bits of r5
   evmergelohi r5, r5, r5      ; Invert high and low orders 32bits of r5
   stw         r5, C_R5_IT_CONTEXT_BACKUP_OFFSET    (r1)   ; Store upper 32bits of r5
   evmergelohi r5, r5, r5      ; Invert high and low orders 32bits of r5
   
   stw         r6, C_R6_IT_CONTEXT_BACKUP_OFFSET_LOW(r1)   ; Store lower 32bits of r6
   evmergelohi r6, r6, r6      ; Invert high and low orders 32bits of r6
   stw         r6, C_R6_IT_CONTEXT_BACKUP_OFFSET    (r1)   ; Store upper 32bits of r6
   evmergelohi r6, r6, r6      ; Invert high and low orders 32bits of r6
   
   stw         r7, C_R7_IT_CONTEXT_BACKUP_OFFSET_LOW(r1)   ; Store lower 32bits of r7
   evmergelohi r7, r7, r7      ; Invert high and low orders 32bits of r7
   stw         r7, C_R7_IT_CONTEXT_BACKUP_OFFSET    (r1)   ; Store upper 32bits of r7
   evmergelohi r7, r7, r7      ; Invert high and low orders 32bits of r7
   
   stw         r8, C_R8_IT_CONTEXT_BACKUP_OFFSET_LOW(r1)   ; Store lower 32bits of r8
   evmergelohi r8, r8, r8      ; Invert high and low orders 32bits of r8
   stw         r8, C_R8_IT_CONTEXT_BACKUP_OFFSET    (r1)   ; Store upper 32bits of r8
   evmergelohi r8, r8, r8      ; Invert high and low orders 32bits of r8
   
   stw         r9, C_R9_IT_CONTEXT_BACKUP_OFFSET_LOW(r1)   ; Store lower 32bits of r9
   evmergelohi r9, r9, r9      ; Invert high and low orders 32bits of r9
   stw         r9, C_R9_IT_CONTEXT_BACKUP_OFFSET     (r1)  ; Store upper 32bits of r9
   evmergelohi r9, r9, r9      ; Invert high and low orders 32bits of r9
   
   stw         r10, C_R10_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r10
   evmergelohi r10, r10, r10   ; Invert high and low orders 32bits of r10
   stw         r10, C_R10_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r10
   evmergelohi r10, r10, r10   ; Invert high and low orders 32bits of r10
   
   stw         r11, C_R11_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r11
   evmergelohi r11, r11, r11   ; Invert high and low orders 32bits of r11
   stw         r11, C_R11_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r11
   evmergelohi r11, r11, r11   ; Invert high and low orders 32bits of r11
   
   stw         r12, C_R12_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r12
   evmergelohi r12, r12, r12   ; Invert high and low orders 32bits of r12
   stw         r12, C_R12_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r12
   evmergelohi r12, r12, r12   ; Invert high and low orders 32bits of r12
   
   stw         r13, C_R13_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r13
   evmergelohi r13, r13, r13   ; Invert high and low orders 32bits of r13
   stw         r13, C_R13_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r13
   evmergelohi r13, r13, r13   ; Invert high and low orders 32bits of r13
   
   stw         r14, C_R14_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r14
   evmergelohi r14, r14, r14   ; Invert high and low orders 32bits of r14
   stw         r14, C_R14_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r14
   evmergelohi r14, r14, r14   ; Invert high and low orders 32bits of r14
   
   stw         r15, C_R15_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r15
   evmergelohi r15, r15, r15   ; Invert high and low orders 32bits of r15
   stw         r15, C_R15_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r15
   evmergelohi r15, r15, r15   ; Invert high and low orders 32bits of r15
   
   stw         r16, C_R16_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r16
   evmergelohi r16, r16, r16   ; Invert high and low orders 32bits of r16
   stw         r16, C_R16_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r16
   evmergelohi r16, r16, r16   ; Invert high and low orders 32bits of r16
   
   stw         r17, C_R17_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r17
   evmergelohi r17, r17, r17   ; Invert high and low orders 32bits of r17
   stw         r17, C_R17_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r17
   evmergelohi r17, r17, r17   ; Invert high and low orders 32bits of r17
   
   stw         r18, C_R18_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r18
   evmergelohi r18, r18, r18   ; Invert high and low orders 32bits of r18
   stw         r18, C_R18_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r18
   evmergelohi r18, r18, r18   ; Invert high and low orders 32bits of r18
   
   stw         r19, C_R19_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r19
   evmergelohi r19, r19, r19   ; Invert high and low orders 32bits of r19
   stw         r19, C_R19_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r19
   evmergelohi r19, r19, r19   ; Invert high and low orders 32bits of r19
   
   stw         r20, C_R20_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r20
   evmergelohi r20, r20, r20   ; Invert high and low orders 32bits of r20
   stw         r20, C_R20_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r20
   evmergelohi r20, r20, r20   ; Invert high and low orders 32bits of r20
   
   stw         r21, C_R21_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r21
   evmergelohi r21, r21, r21   ; Invert high and low orders 32bits of r21
   stw         r21, C_R21_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r21
   evmergelohi r21, r21, r21   ; Invert high and low orders 32bits of r21
   
   stw         r22, C_R22_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r22
   evmergelohi r22, r22, r22   ; Invert high and low orders 32bits of r22
   stw         r22, C_R22_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r22
   evmergelohi r22, r22, r22   ; Invert high and low orders 32bits of r22
   
   stw         r23, C_R23_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r23
   evmergelohi r23, r23, r23   ; Invert high and low orders 32bits of r23
   stw         r23, C_R23_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r23
   evmergelohi r23, r23, r23   ; Invert high and low orders 32bits of r23
   
   stw         r24, C_R24_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r24
   evmergelohi r24, r24, r24   ; Invert high and low orders 32bits of r24
   stw         r24, C_R24_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r24
   evmergelohi r24, r24, r24   ; Invert high and low orders 32bits of r24
   
   stw         r25, C_R25_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r25
   evmergelohi r25, r25, r25   ; Invert high and low orders 32bits of r25
   stw         r25, C_R25_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r25
   evmergelohi r25, r25, r25   ; Invert high and low orders 32bits of r25
   
   stw         r26, C_R26_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r26
   evmergelohi r26, r26, r26   ; Invert high and low orders 32bits of r26
   stw         r26, C_R26_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r26
   evmergelohi r26, r26, r26   ; Invert high and low orders 32bits of r26
   
   stw         r27, C_R27_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r27
   evmergelohi r27, r27, r27   ; Invert high and low orders 32bits of r27
   stw         r27, C_R27_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r27
   evmergelohi r27, r27, r27   ; Invert high and low orders 32bits of r27
   
   stw         r28, C_R28_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r28
   evmergelohi r28, r28, r28   ; Invert high and low orders 32bits of r28
   stw         r28, C_R28_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r28
   evmergelohi r28, r28, r28   ; Invert high and low orders 32bits of r28
   
   stw         r29, C_R29_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r29
   evmergelohi r29, r29, r29   ; Invert high and low orders 32bits of r29
   stw         r29, C_R29_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r29
   evmergelohi r29, r29, r29   ; Invert high and low orders 32bits of r29
   
   stw         r30, C_R30_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r30
   evmergelohi r30, r30, r30   ; Invert high and low orders 32bits of r30
   stw         r30, C_R30_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r30
   evmergelohi r30, r30, r30   ; Invert high and low orders 32bits of r30
   
   stw         r31, C_R31_IT_CONTEXT_BACKUP_OFFSET_LOW(r1) ; Store lower 32bits of r31
   evmergelohi r31, r31, r31   ; Invert high and low orders 32bits of r31
   stw         r31, C_R31_IT_CONTEXT_BACKUP_OFFSET    (r1) ; Store upper 32bits of r31
   evmergelohi r31, r31, r31   ; Invert high and low orders 32bits of r31
   
   mtsprg1     r3
   ; Save CR register
   mfcr        r3
   stw         r3,C_CR_IT_CONTEXT_BACKUP_OFFSET(r1)
   
   ; Save XER register
   mfxer       r3
   stw         r3,C_XER_IT_CONTEXT_BACKUP_OFFSET(r1)
   
   ; Save CTR register
   mfctr       r3
   stw         r3,C_CTR_IT_CONTEXT_BACKUP_OFFSET(r1)
   
   ; Save SRR0 register (used to restart the process at the same place)
   mfsrr0      r3
   stw         r3,C_SRR0_IT_CONTEXT_BACKUP_OFFSET(r1)
   
   ; Save SRR1 register (used to restore MSR register on rfi instruction)
   mfsrr1      r3
   stw         r3,C_SRR1_IT_CONTEXT_BACKUP_OFFSET(r1)
   
   ; Save SPEFSCR
   mfspr       r3,REG_SPEFSCR
   stw         r3,C_SPEFSCR_IT_CONTEXT_BACKUP_OFFSET(r1)
   mfsprg1     r3
   blr

; Restore
RestoreContext:
   
   
   ; Restore CR register
   lwz         r3,C_CR_IT_CONTEXT_BACKUP_OFFSET(r1)
   mtcr        r3
   
   ; Restore XER register
   lwz         r3,C_XER_IT_CONTEXT_BACKUP_OFFSET(r1)
   mtxer       r3
   
   ; Restore CTR register
   lwz         r3,C_CTR_IT_CONTEXT_BACKUP_OFFSET(r1)
   mtctr       r3
   
   ; Restore SSR0 register (restart address)
   lwz         r3,C_SRR0_IT_CONTEXT_BACKUP_OFFSET(r1)
   mtsrr0      r3
   
   ; Restore SSR1 register (MSR value)
   lwz         r3,C_SRR1_IT_CONTEXT_BACKUP_OFFSET(r1)
   mtsrr1      r3
   
   ; Restore GPRs (except R4 and R3)
   evldw       r0, C_R0_IT_CONTEXT_BACKUP_OFFSET (r1)
   ; evldw       r1, C_R1_IT_CONTEXT_BACKUP_OFFSET (r1)
   evldw       r2, C_R2_IT_CONTEXT_BACKUP_OFFSET (r1)
   evldw       r5, C_R5_IT_CONTEXT_BACKUP_OFFSET (r1)
   evldw       r6, C_R6_IT_CONTEXT_BACKUP_OFFSET (r1)
   evldw       r7, C_R7_IT_CONTEXT_BACKUP_OFFSET (r1)
   evldw       r8, C_R8_IT_CONTEXT_BACKUP_OFFSET (r1)
   evldw       r9, C_R9_IT_CONTEXT_BACKUP_OFFSET (r1)
   evldw       r10,C_R10_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r11,C_R11_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r12,C_R12_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r13,C_R13_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r14,C_R14_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r15,C_R15_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r16,C_R16_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r17,C_R17_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r18,C_R18_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r19,C_R19_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r20,C_R20_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r21,C_R21_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r22,C_R22_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r23,C_R23_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r24,C_R24_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r25,C_R25_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r26,C_R26_IT_CONTEXT_BACKUP_OFFSET(r1)
   evldw       r27,C_R27_IT_CONTEXT_BACKUP_OFFSET(r1)
   ; Add offset in R3 because evldw intruction offset must be < 256
   addi        r3,r1,0x0100
   evldw       r28,(C_R28_IT_CONTEXT_BACKUP_OFFSET - 0x0100)(r3)
   evldw       r29,(C_R29_IT_CONTEXT_BACKUP_OFFSET - 0x0100)(r3)
   evldw       r30,(C_R30_IT_CONTEXT_BACKUP_OFFSET - 0x0100)(r3)
   evldw       r31,(C_R31_IT_CONTEXT_BACKUP_OFFSET - 0x0100)(r3)
   
   ; Restore SPEFSCR
   lwz         r4,(C_SPEFSCR_IT_CONTEXT_BACKUP_OFFSET - 0x0100)(r3)
   mtspr       REG_SPEFSCR, r4
   isync
   
   ; Restore R4
   evldw       r4,C_R4_IT_CONTEXT_BACKUP_OFFSET(r1)
   ; Restore R3
   evldw       r3,C_R3_IT_CONTEXT_BACKUP_OFFSET(r1)
   
   addi r1, r1, C_IT_CONTEXT_BACKUP_SIZE
   
   blr

CriticalInputInterruptHandler:
   b BOOT_FailMode

MachineCheckInterruptHandler:
   b BOOT_FailMode

InstructionStorageInterruptHandler:
   b BOOT_FailMode

AlignementInterruptHandler:
   b BOOT_FailMode

ProgramInterruptHandler:
   b BOOT_FailMode

SystemCallInterruptHandler:
   b BOOT_FailMode

FPU_UnavailableInterruptHandler:
   b BOOT_FailMode

FixedIntervalTimerInterruptHandler:
   b BOOT_FailMode

InstructionTLB_InterruptHandler:
   b BOOT_FailMode

DebugInterruptHandler:
   b BOOT_FailMode

SPE_APU_UnavailableInterruptHandler:
   b BOOT_FailMode

EFP_RoundExceptionInterruptHandler:
   b BOOT_FailMode

PerformanceMonitorInterruptHandler:
   b BOOT_FailMode