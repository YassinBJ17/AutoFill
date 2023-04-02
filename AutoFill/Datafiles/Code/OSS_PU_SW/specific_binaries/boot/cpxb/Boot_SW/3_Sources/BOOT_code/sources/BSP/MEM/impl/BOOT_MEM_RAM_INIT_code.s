;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : This function initializes the given memory to 0
;
; --------------------------------------------------------------------------

; ---------- include required interface: -----------------------------------


; ---------- internal define constants: ------------------------------------
; none

; ---------- provided datas: -------------------------------------------
; none


;----------------------------------------------------------------------------
;  C PROTOTYPE :
;-----------------
;  void BOOT_MEM_RAM_INIT(uint8_t * const p_start, uint8_t* const p_end);
;

;  STACK USAGE :
; -----------------
;   TBC
;

;  REGISTER USAGE :
; -----------------
;  r3 : p_start
;  r4 : p_end
;  r5 : temporary register
;  r30, r31 : initialisation values set to INIT_SRAM_VAL
 	.file      "BOOT_MEM_RAM_INITT_code.s"
   .globl  BOOT_MEM_RAM_INIT
   .align 4

   .set INIT_SRAM_VAL, 0x00000000

BOOT_MEM_RAM_INIT:

   MR       r6, r31
   MR       r7, r30

   LIS      r31, INIT_SRAM_VAL@ha
   ADDI     r31, r31, INIT_SRAM_VAL@l

   LIS      r30, INIT_SRAM_VAL@ha
   ADDI     r30, r30, INIT_SRAM_VAL@l


   SUBF    	r4,r3,r4
   ADDi		r4, r4, 1

   ; size area is divided by 8 because the core will write by blocks of 2*32 bits (see stmw)
   LI		r5, 8
   DIVW		r4,r4,r5
   MTCTR   	r4

LOOP_SYS_RAM_START:
   STMW     r30, 0(r3)
   ADDI     r3, r3, 8
   BDNZ     LOOP_SYS_RAM_START

   MR       r31, r6
   MR       r30, r7

   ; End of function
   BLR
