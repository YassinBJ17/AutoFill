;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : PBIT RAM Test: To test internal RAM
;-------------------------------------------------------------------------------

   .file "PBIT_Test_RAM.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
   .set C_RAM_START_ADDRESS, 0x1FFF8000
   .set C_RAM_END_ADDRESS, 0x20006FFF
   .set C_RAM_TEST_INITIAL_VALUE, 0x5D41F87E
   .set C_RAM_TEST_CONSTANT, 0x1000000B

;------------ function bodies: -------------------------------------------------
   .text
   .global PBIT_Test_RAM

; PBIT RAM Test: To test internal RAM
;
; Parameters:
;   Inputs: None
;   Outputs: None
;
;

PBIT_Test_RAM:
   ; C prototype:
      ; void PBIT_Test_RAM (void)
    
   ; Initialize the RAM test PBIT Test Result
   movw  r1,%lo(V_PBIT_RAM_Test_Result)
   movt  r1,%hi(V_PBIT_RAM_Test_Result)
   movs  r0,1
   str   r0,[r1]

   ; Initialize the GPRs
   LDR   r0, =C_RAM_START_ADDRESS
   LDR   r1, =C_RAM_END_ADDRESS
   LDR   r2, =C_RAM_TEST_INITIAL_VALUE
   LDR   r3, =C_RAM_TEST_CONSTANT

   PBIT_CORE_RAM_TEST_1:
      LSLS  r2, r2, #0x1
      bcc   PBIT_CORE_RAM_TEST_2
      EOR   r2, r2, r3

   PBIT_CORE_RAM_TEST_2:
      STR   r2, [r0]
      add   r0, r0, #0x4
      cmp   r0, r1
      blt    PBIT_CORE_RAM_TEST_1

   LDR   r0, =C_RAM_START_ADDRESS
   LDR   r2, =C_RAM_TEST_INITIAL_VALUE

   PBIT_CORE_RAM_TEST_3:
      LSLS  r2, r2, #0x1
      bcc   PBIT_CORE_RAM_TEST_4
      EOR   r2, r2, r3

   PBIT_CORE_RAM_TEST_4:
      LDR   r4, [r0]
      add   r0, r0, #0x4
      cmp   r2, r4
      bne    PBIT_CORE_RAM_TEST_FAILED
      cmp   r0, r1
      blt    PBIT_CORE_RAM_TEST_3

   LDR   r0, =C_RAM_START_ADDRESS
   LDR   r1, =C_RAM_END_ADDRESS
   LDR   r2, =0

   ; If no error, erase RAM
   PBIT_CORE_RAM_ERASE:
      STR   r2, [r0]
      add   r0, r0, #0x4
      cmp   r0, r1
      blt    PBIT_CORE_RAM_ERASE


   ; PBIT RAM succeed if section reached
   movw  r1,%lo(V_PBIT_RAM_Test_Result)
   movt  r1,%hi(V_PBIT_RAM_Test_Result)
   movs  r0,0
   str   r0,[r1]

   MOV   r0, #0
   MOV   r1, #0
   MOV   r2, #0
   MOV   r3, #0
   MOV   r4, #0
   MOV   r5, #0
   MOV   r6, #0
   MOV   r7, #0
   MOV   r8, #0
   MOV   r9, #0
   MOV   r10,#0
   MOV   r11,#0
   MOV   r12,#0

   BX    lr

   ; PBIT RAM Failed if any errors
   PBIT_CORE_RAM_TEST_FAILED:
      movw  r1,%lo(V_PBIT_RAM_Test_Result)
      movt  r1,%hi(V_PBIT_RAM_Test_Result)
      movs  r0,1
      str   r0,[r1]

   .end
