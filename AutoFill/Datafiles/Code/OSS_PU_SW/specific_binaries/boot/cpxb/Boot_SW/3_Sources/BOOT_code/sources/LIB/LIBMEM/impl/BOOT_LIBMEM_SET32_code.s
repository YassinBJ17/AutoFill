;-------------------------------------------------------------------------------
;                      SAFRAN Electronics & Defense
;                 Reproduction and disclosure forbidden.
;--------------------------------------------------------------------------
; DESCRIPTION : This function sets all word of the chosen memory zone
;              to the desired value.
;--------------------------------------------------------------------------
 
;---------- include required interface: -----------------------------------
;none
 
;---------- internal define constants: ------------------------------------
;none
 
;---------- internal types: -----------------------------------------------
;none
 
;---------- internal operations: ------------------------------------------
;none
 
;---------- internal constants: -------------------------------------------
;none
 
;---------- internal data: ------------------------------------------------
;none

;---------- provided operation bodies: ------------------------------------ 

;
;void BOOT_LIBMEM_SET32( uint8_t  const * buffer_pt,
;                        uint32_t const init_value,
;                        uint32_t const length )
;

   .text
   .global BOOT_LIBMEM_SET32
   .align 4

; Implements REQ_[User Project Name]_BOOT-LLR_060
BOOT_LIBMEM_SET32:
;save in stack the register used for the stmw
   STWU  r31, -4(r1)
   STWU  r30, -4(r1)
   STWU  r29, -4(r1)
   STWU  r28, -4(r1)
   STWU  r27, -4(r1)
   STWU  r26, -4(r1)
   STWU  r25, -4(r1)
   STWU  r24, -4(r1)
   STWU  r23, -4(r1)

; default value for the register used in multiword
   MR    r24, r4
   MR    r25, r4
   MR    r26, r4
   MR    r27, r4
   MR    r28, r4
   MR    r29, r4
   MR    r30, r4
   MR    r31, r4

; The size is divided by 32 bytes because the function BOOT_LIBMEM_SET writes by block of 8*32bits
   LI    r23, 0x20
   DIVW  r23,r5,r23

   MTCTR r23     ; write the loop counter into counter register

; The use "stmw" permits reduce significantly the execution time of the loop
; by doing burst writes on memory bus.

; performing the loop writting
loop_int:
   STMW  r24, 0x0(r3)
   ADDI  r3, r3, 32
   BDNZ  loop_int

; restore the r23 to r31 register
   LWZ   r23, 0(r1)
   ADDI  r1, r1, 4
   LWZ   r24, 0(r1)
   ADDI  r1, r1 ,4
   LWZ   r25, 0(r1)
   ADDI  r1, r1, 4
   LWZ   r26, 0(r1)
   ADDI  r1, r1, 4
   LWZ   r27, 0(r1)
   ADDI  r1, r1, 4
   LWZ   r28, 0(r1)
   ADDI  r1, r1, 4
   LWZ   r29, 0(r1)
   ADDI  r1, r1, 4
   LWZ   r30, 0(r1)
   ADDI  r1, r1, 4
   LWZ   r31, 0(r1)
   ADDI  r1, r1, 4

   BLR

   .end



