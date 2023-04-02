;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : This function resets stack and registers before launching
;               the applicative software.
; --------------------------------------------------------------------------

; ---------- include required interface: -----------------------------------
   .include "BOOT_RESET_DEF_public.inc"
;   .include "BOOT_MAIN_private.inc"
;   .include "BOOT_FAULT_public.inc"

; ---------- internal define constants: ------------------------------------
; none


; ---------- internal types: -----------------------------------------------
; none

; ---------- internal operations: ------------------------------------------
; none

; ---------- internal constants: -------------------------------------------
; none

; ---------- internal data: ------------------------------------------------
; none

; ---------- provided operation bodies: ------------------------------------

; ----------------------------------------------------------------------------
; C PROTOTYPE :
; -----------------
   .global BOOT_MAIN_LAUNCH_SOFTWARE

; STACK USAGE :
; -----------------
; None
;

; REGISTER USAGE :
; -----------------
; r3 : address on a software to branch



; -----------------
; BODY :
   .file "BOOT_MAIN_LAUNCH_SOFTWARE_code.s"

   ; the align 4 is mandatory because the address of BOOT_MAIN_LAUNCH_SOFTWARE is givent to the MC_ME_CADDR register which
   ; impose that the address is align on 4 bytes.
   .align 4

; Implements REQ_[User Project Name]_BOOT-LLR_005
BOOT_MAIN_LAUNCH_SOFTWARE:









;-----------------------------------------------;
;               Clear registers                 ;
;-----------------------------------------------;

;  Initialize core registers
   LI       r0, 0x0
; do not erase r1 as the branch will be done
   LI       r2, 0x0
; r3 contains the software address
   LI       r4, 0x0
   LI       r5, 0x0
   LI       r6, 0x0
   LI       r7, 0x0
   LI       r8, 0x0
   LI       r9, 0x0
   LI       r10, 0x0
   LI       r11, 0x0
   LI       r12, 0x0
   LI       r13, 0x0
   LI       r14, 0x0
   LI       r15, 0x0
   LI       r16, 0x0
   LI       r17, 0x0
   LI       r18, 0x0
   LI       r19, 0x0
   LI       r20, 0x0
   LI       r21, 0x0
   LI       r22, 0x0
   LI       r23, 0x0
   LI       r24, 0x0
   LI       r25, 0x0
   LI       r26, 0x0
   LI       r27, 0x0
   LI       r28, 0x0
   LI       r29, 0x0
   LI       r30, 0x0
   LI       r31, 0x0

;  Init Special Purpose Registers (SPR)
   MTSPR    REG_XER,r31
   MTCRF    0xFF, r31
   MTSPR    REG_CTR,  r31
   MTSPR    REG_SPRG0, r31
   MTSPR    REG_SPRG1, r31
   MTSPR    REG_SPRG2, r31
   MTSPR    REG_SPRG3, r31
   MTSPR    REG_SRR0, r31
   MTSPR    REG_SRR1, r31
   MTSPR    REG_CSRR0, r31
   MTSPR    REG_CSRR1, r31
   MTSPR    REG_MCSRR0, r31
   MTSPR    REG_MCSRR1, r31
   MTSPR    REG_DEAR, r31
   MTSPR    REG_IVPR, r31
   MTSPR    REG_USPRG0, r31
   MTSPR    REG_ESR, r31
   MTSPR    REG_LR, r31
   MTSPR    REG_DSRR0, r31
   MTSPR    REG_DSRR1, r31

;  Call Function entry point
   MTSPR    REG_CTR, r3

; branch always
   BCCTRL   20,0

; ---------- internal operation bodies: ------------------------------------
; none

   .end
