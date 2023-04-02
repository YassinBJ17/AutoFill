   ; .include "RAMBOOT_Registers.inc"
   ; .include "RAMBOOT_VectorTable.inc"
   
   .set C_11111111,    0x11111111
   .set C_44444444,    0x44444444
   .set C_55555555,    0x55555555
   .set C_22222222,    0x22222222
   .set C_88888888,    0x88888888
   .set C_CCCCCCCC,    0xCCCCCCCC
   .set C_33333333,    0x33333333
   .set C_FFFFFFFF,    0xFFFFFFFF
   .set C_AAAAAAAA,    0xAAAAAAAA
   .set C_00000005,    0x00000005
   .set C_12345678,    0x12345678
   .set C_F3DD1BB0,    0xF3DD1BB0
   .set C_E0000000,    0xE0000000
   .set C_BBBBBBBC,    0xBBBBBBBC
   .set C_00000002,    0x00000002
   .set C_00000003,    0x00000003
   .set C_00000000,    0x00000000
   .set C_00000001,    0x00000001
   .set C_00000007,    0x00000007
   .set C_FFFFFFFE,    0xFFFFFFFE
   .set C_00000004,    0x00000004
   .set C_AAAAAAAB,    0xAAAAAAAB
   .set C_FFFF0000,    0xFFFF0000
   .set C_0000FFFF,    0x0000FFFF
   .set C_55555554,    0x55555554
   .set C_2AAAAAAA,    0x2AAAAAAA
   .set C_D5555555,    0xD5555555
   .set C_1,           1
   .set C_16,          16

RAMBOOT_TCBHW_ALU_FailureHandler:
   b RAMBOOT_TCBHW_InfiniteLoop

RAMBOOT_TCBHW_TestALU: .macro
; Load constants values used during ALU test
   lis     r1, C_2AAAAAAA@ha
   addi    r1, r1, C_2AAAAAAA@l
   lis     r2, C_D5555555@ha
   addi    r2, r2, C_D5555555@l
   lis     r3, C_11111111@ha
   addi    r3, r3, C_11111111@l
   lis     r4, C_44444444@ha
   addi    r4, r4, C_44444444@l
   lis     r5, C_55555555@ha
   addi    r5, r5, C_55555555@l
   lis     r6, C_22222222@ha
   addi    r6, r6, C_22222222@l
   lis     r7, C_88888888@ha
   addi    r7, r7, C_88888888@l
   lis     r8, C_AAAAAAAA@ha
   addi    r8, r8, C_AAAAAAAA@l
   lis     r9, C_CCCCCCCC@ha
   addi    r9, r9, C_CCCCCCCC@l
   lis     r10, C_33333333@ha
   addi    r10, r10, C_33333333@l
   lis     r11, C_FFFFFFFF@ha
   addi    r11, r11, C_FFFFFFFF@l
   lis     r12, C_00000005@ha
   addi    r12, r12, C_00000005@l
   lis     r13, C_BBBBBBBC@ha
   addi    r13, r13, C_BBBBBBBC@l
   lis     r14, C_12345678@ha
   addi    r14, r14, C_12345678@l
   lis     r15, C_F3DD1BB0@ha
   addi    r15, r15, C_F3DD1BB0@l
   lis     r16, C_E0000000@ha
   addi    r16, r16, C_E0000000@l
   lis     r17, C_00000002@ha
   addi    r17, r17, C_00000002@l
   lis     r18, C_00000003@ha
   addi    r18, r18, C_00000003@l
   lis     r19, C_00000000@ha
   addi    r19, r19, C_00000000@l
   lis     r20, C_00000001@ha
   addi    r20, r20, C_00000001@l
   lis     r21, C_00000007@ha
   addi    r21, r21, C_00000007@l
   lis     r22, C_FFFFFFFE@ha
   addi    r22, r22, C_FFFFFFFE@l
   lis     r23, C_00000004@ha
   addi    r23, r23, C_00000004@l
   lis     r24, C_AAAAAAAB@ha
   addi    r24, r24, C_AAAAAAAB@l
   lis     r25, C_FFFF0000@ha
   addi    r25, r25, C_FFFF0000@l
   lis     r26, C_0000FFFF@ha
   addi    r26, r26, C_0000FFFF@l
   lis     r27, C_1@ha
   addi    r27, r27, C_1@l
   lis     r28, C_16@ha
   addi    r28, r28, C_16@l
   lis     r29, C_55555554@ha
   addi    r29, r29, C_55555554@l

   ;           Test arithmetical operations:
   ; ==================================================
   ; - integer addition on 32 bits words
   ; --------------------------------------------------
   ; r3  =  C_11111111
   ; r4  =  C_44444444
   ; r5  =  C_55555555
   ; r6  =  C_22222222
   ; r7  =  C_88888888
   ; r8  =  C_AAAAAAAA
   ; r9  =  C_CCCCCCCC
   ; r10 =  C_33333333
   ; r11 =  C_FFFFFFFF
   
   ; * 0x11111111 + 0x44444444 -> 0x55555555
ALU_Test01:
   add     r31, r3, r4
   cmpw    r31, r5
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * 0x22222222 + 0x88888888 -> 0xaaaaaaaa
ALU_Test02:
   add     r31, r6, r7
   cmpw    r31, r8
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * 0xcccccccc + 0x33333333 -> 0xffffffff
ALU_Test03:
   add     r31, r9, r10
   cmpw    r31, r11
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; - integer substraction on 32 bits words
   ; --------------------------------------------------
   ; r3  = C_11111111
   ; r4  = C_44444444
   ; r5  = C_55555555
   ; r6  = C_22222222
   ; r7  = C_88888888
   ; r8  = C_AAAAAAAA
   ; r9  = C_CCCCCCCC
   ; r10 = C_33333333
   ; r11 = C_FFFFFFFF

   ; * 0x55555555 - 0x11111111 -> 0x44444444
ALU_Test04:
   sub     r31, r5, r3
   cmpw    r31, r4
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * 0xaaaaaaaa - 0x22222222 -> 0x88888888
ALU_Test05:
   sub     r31, r8, r6
   cmpw    r31, r7
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * 0xffffffff - 0xcccccccc -> 0x33333333
ALU_Test06:
   sub     r31, r11, r9
   cmpw    r31, r10
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; - integer multiplication on 32 bits words
   ; --------------------------------------------------
   ; r12 = C_00000005
   ; r3  = C_11111111
   ; r5  = C_55555555
   ; r6  = C_22222222
   ; r8  = C_AAAAAAAA
   ; r9  = C_CCCCCCCC
   ; r13 = C_BBBBBBBC
   ; r14 = C_12345678
   ; r15 = C_F3DD1BB0
   ; r16 = C_E0000000

   ; * 0x00000005 * 0x11111111 -> 0x55555555
ALU_Test07:
   mullw   r31, r12, r3
   cmpw    r31, r5
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * 0x00000005 * 0x22222222 -> 0xaaaaaaaa
ALU_Test08:
   mullw   r31, r12, r6
   cmpw    r31, r8
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * 0x55555555 * 0xcccccccc -> 0xbbbbbbbc
ALU_Test09:
   mullw   r31, r5, r9
   cmpw    r31, r13
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * 0xaaaaaaaa * 0x12345678 -> 0xf3dd1bb0
ALU_Test10:
   mullw   r31, r8, r14
   cmpw    r31, r15
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * 0xe0000000 * 0x11111111 -> 0xe0000000
ALU_Test11:
   mullw   r31, r16, r3
   cmpw    r31, r16
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; - signed integer division on 32 bits words
   ; --------------------------------------------------
   ; r8  = C_AAAAAAAA
   ; r17 = C_00000002
   ; r2  = C_D5555555
   ; r11 = C_FFFFFFFF
   ; r18 = C_00000003
   ; r19 = C_00000000
   ; r5  = C_55555555
   ; r24 = 0xAAAAAAAB
   
   ; * 0xaaaaaaaa / 0x00000002 -> 0xd5555555
ALU_Test12:
   divw    r31, r8, r17
   cmpw    r31, r2
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * 0xffffffff / 0x00000003 -> 0x00000000
ALU_Test13:
   divw    r31, r11, r18
   cmpw    r31, r19
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * 0x55555555 / 0xffffffff -> 0xaaaaaaab
ALU_Test14:
   divw    r31, r5, r11
   cmpw    r31, r24
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; - unsigned integer division on 32 bits words
   ; --------------------------------------------------
   ; r11 = C_FFFFFFFF
   ; r18 = C_00000003
   ; r5  = C_55555555
   ; r8  = C_AAAAAAAA
   ; r20 = C_00000001
   ; r12 = C_00000005
   ; r3  = C_11111111
   ; r21 = C_00000007
   ; r19 = C_00000000
   ; r22 = C_FFFFFFFE
   ; r23 = C_00000004
   ; r17 = C_00000002

   ; * 0xffffffff / 0x00000003 -> 0x55555555
ALU_Test15:
   divwu   r31, r11, r18
   cmpw    r31, r5
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * 0xaaaaaaaa / 0x00000001 -> 0xaaaaaaaa
ALU_Test16:
   divwu   r31, r8, r20
   cmpw    r31, r8
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * 0x55555555 / 0x00000005 -> 0x11111111
ALU_Test17:
   divwu   r31, r5, r12
   cmpw    r31, r3
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * 0x00000005 / 0x00000007 -> 0x00000000
ALU_Test18:
   divwu   r31, r12, r21
   cmpw    r31, r19
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * 0xfffffffe / 0xffffffff -> 0x00000000
ALU_Test19:
   divwu   r31, r22, r11
   cmpw    r31, r19
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * 0x00000004 / 0x00000002 -> 0x00000002
ALU_Test20:
   divwu   r31, r23, r17
   cmpw    r31, r17
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; - negate on 32 bits word
   ; --------------------------------------------------
   ; r5  = C_55555555
   ; r24 = C_AAAAAAAB
   ; r20 = C_00000001
   ; r11 = C_FFFFFFFF
   
   ; * negate 0x55555555 -> 0xaaaaaaab
ALU_Test21:
   neg     r31, r5
   cmpw    r31, r24
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * negate 0x00000001 -> 0xffffffff
ALU_Test22:
   neg     r31, r20
   cmpw    r31, r11
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ;           Test logical operations:
   ; ==================================================
   ; - logical bitwise OR on 32 bits words
   ; --------------------------------------------------
   ; r5  = C_55555555
   ; r11 = C_FFFFFFFF
   ; r8  = C_AAAAAAAA

   ; * 0xaaaaaaaa OR 0x55555555 -> 0xffffffff
ALU_Test23:
   or      r31, r8, r5
   cmpw    r31, r11
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * 0xaaaaaaaa OR 0xaaaaaaaa -> 0xaaaaaaaa
ALU_Test24:
   or      r31, r8, r8
   cmpw    r31, r8
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * 0x55555555 OR 0x55555555 -> 0x55555555
ALU_Test25:
   or      r31, r5, r5
   cmpw    r31, r5
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; - logical bitwise AND on 32 bits words
   ; --------------------------------------------------
   ; r5  = C_55555555
   ; r11 = C_FFFFFFFF
   ; r19 = C_00000000
   ; r8  = C_AAAAAAAA

   ; * 0xaaaaaaaa AND 0x55555555 -> 0x00000000
ALU_Test26:
   and     r31, r8, r5
   cmpw    r31, r19
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * 0xaaaaaaaa AND 0xaaaaaaaa -> 0xaaaaaaaa
ALU_Test27:
   and     r31, r8, r8
   cmpw    r31, r8
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * 0x55555555 AND 0x55555555 -> 0x55555555
ALU_Test28:
   and     r31, r5, r5
   cmpw    r31, r5
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; - logical bitwise XOR on 32 bits words
   ; --------------------------------------------------
   ; r5  = C_55555555
   ; r11 = C_FFFFFFFF
   ; r8  = C_AAAAAAAA
   ; r19 = C_00000000
   
   ; * 0xaaaaaaaa XOR 0x55555555 -> 0xffffffff
ALU_Test29:
   xor     r31, r8, r5
   cmpw    r31, r11
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * 0xaaaaaaaa XOR 0xaaaaaaaa -> 0x00000000
ALU_Test30:
   xor     r31, r8, r8
   cmpw    r31, r19
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * 0x55555555 XOR 0x55555555 -> 0x00000000
ALU_Test31:
   xor     r31, r5, r5
   cmpw    r31, r19
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; - logical bitwise NOR on 32 bits words
   ; --------------------------------------------------
   ; r5  = C_55555555
   ; r11 = C_FFFFFFFF
   ; r8  = C_AAAAAAAA
   ; r19 = C_00000000
   
   ; * 0xaaaaaaaa NOR 0x55555555 -> 0x00000000
ALU_Test32:
   nor     r31, r8, r5
   cmpw    r31, r19
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * 0xaaaaaaaa NOR 0xaaaaaaaa -> 0x55555555
ALU_Test33:
   nor     r31, r8, r8
   cmpw    r31, r5
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * 0x55555555 NOR 0x55555555 -> 0xaaaaaaaa
ALU_Test34:
   nor     r31, r5, r5
   cmpw    r31, r8
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; - logical bitwise NAND on 32 bits words
   ; --------------------------------------------------
   ; r5  = C_55555555
   ; r11 = C_FFFFFFFF
   ; r8  = C_AAAAAAAA

   ; * 0xaaaaaaaa NAND 0x55555555 -> 0xffffffff
ALU_Test35:
   nand    r31, r8, r5
   cmpw    r31, r11
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * 0xaaaaaaaa NAND 0xaaaaaaaa -> 0x55555555
ALU_Test36:
   nand    r31, r8, r8
   cmpw    r31, r5
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * 0x55555555 NAND 0x55555555 -> 0xaaaaaaaa
ALU_Test37:
   nand    r31, r5, r5
   cmpw    r31, r8
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; - logical bitwise NOT on 32 bits words
   ; --------------------------------------------------
   ; r5  = C_55555555
   ; r8  = C_AAAAAAAA

   ; * NOT 0xaaaaaaaa -> 0x55555555
ALU_Test38:
   not     r31, r8
   cmpw    r31, r5
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * NOT 0x55555555 -> 0xaaaaaaaa
ALU_Test39:
   not     r31, r5
   cmpw    r31, r8
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; - logical bitwise rotate left and right on 32 bits words
   ; --------------------------------------------------------
   ; r5  = C_55555555
   ; r8  = C_AAAAAAAA
   ; r25 = C_FFFF0000
   ; r26 = C_0000FFFF

   ; * Rotate left 1 step 0x55555555 -> 0xaaaaaaaa
ALU_Test40:
   rotlwi  r31, r5, C_1
   cmpw    r31, r8
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * Rotate left 1 step 0xaaaaaaaa -> 0x55555555
ALU_Test41:
   rotlwi  r31, r8, C_1
   cmpw    r31, r5
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * Rotate left 16 steps 0xffff0000 -> 0x0000ffff
ALU_Test42:
   rotlwi  r31, r25, C_16
   cmpw    r31, r26
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * Rotate right 16 steps 0x0000ffff -> 0xffff0000
ALU_Test43:
   rotrwi  r31, r26, C_16
   cmpw    r31, r25
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * Rotate right 1 step 0x55555555 -> 0xaaaaaaaa
ALU_Test44:
   rotrwi  r31, r5, C_1
   cmpw    r31, r8
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; - logical bitwise shift on 32 bits words
   ; --------------------------------------------------
   ; r5  = C_55555555
   ; r8  = C_AAAAAAAA
   ; r29 = C_55555554
   ; r11 = C_FFFFFFFF
   ; r25 = C_FFFF0000
   ; r26 = C_0000FFFF
   ; r1  = C_2AAAAAAA

   ; * Shift left 1 step 0x55555555 -> 0xaaaaaaaa
ALU_Test45:
   slwi    r31, r5, C_1
   cmpw    r31, r8
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * Shift left 1 step 0xaaaaaaaa -> 0x55555554
ALU_Test46:
   slwi    r31, r8, C_1
   cmpw    r31, r29
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * Shift left 16 steps 0xffffffff -> 0xffff0000
ALU_Test47:
   slwi    r31, r11, C_16
   cmpw    r31, r25
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * Shift right 16 steps 0xffffffff -> 0x0000ffff
ALU_Test48:
   srwi    r31, r11, C_16
   cmpw    r31, r26
   bne     RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * Shift right 1 step 0x55555555 -> 0x2aaaaaaa
ALU_Test49:
   srwi    r31, r5, C_1
   cmpw    r31, r1
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ;               Test comparisons
   ; ==================================================
   ; r26 = C_1
   ; r27 = C_1
   ; r28 = C_16
   lis     r26, C_00000001@ha
   addi    r26, r26, C_00000001@l
   
   ; * "egal" with result TRUE
ALU_Test50:
   cmpw    r26, r27
   beq     ALU_Test51
   b       RAMBOOT_TCBHW_ALU_FailureHandler

   ; * "egal" with result FALSE
ALU_Test51:
   cmpw    r27, r28
   beq     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * "different" with result TRUE
ALU_Test52:
   cmpw    r27, r28
   bne     ALU_Test53
   b       RAMBOOT_TCBHW_ALU_FailureHandler

   ; * "different" with result FALSE
ALU_Test53:
   cmpw    r26, r27
   bne     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * "above" with result TRUE
ALU_Test54:
   cmpw    r28, r27
   bgt     ALU_Test55     ; Branch if Greater Than
   b       RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * "above" with result FALSE
ALU_Test55:
   cmpw    r27, r28
   bgt     RAMBOOT_TCBHW_ALU_FailureHandler   ; Branch if Greater Than

   ; * "above or equal" with result TRUE
ALU_Test56:
   cmpw    r28, r27
   bge     ALU_Test57
   b       RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * "above or equal" with result FALSE
ALU_Test57:
   cmpw    r27, r28
   bge     RAMBOOT_TCBHW_ALU_FailureHandler

   ; * "below" with result TRUE
ALU_Test58:
   cmpw    r27, r28
   blt     ALU_Test59                      ; Branch if Less Than
   b       RAMBOOT_TCBHW_ALU_FailureHandler

   ; * "below" with result FALSE
ALU_Test59:
   cmpw    r28, r27
   blt     RAMBOOT_TCBHW_ALU_FailureHandler   ; Branch if Less Than

   ; * "below or equal" with result TRUE
ALU_Test60:
   cmpw    r27, r28
   ble     ALU_Test61   ; Branch if Less or Equal 
   b       RAMBOOT_TCBHW_ALU_FailureHandler
   
   ; * "below or equal" with result FALSE.
ALU_Test61:
   cmpw    r28, r27
   ble     RAMBOOT_TCBHW_ALU_FailureHandler   ; Branch if Less or Equal
   .endm