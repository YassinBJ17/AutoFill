;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : Cores entrypoints after the software reset
; --------------------------------------------------------------------------

; ---------- include required interface: -----------------------------------
   .extern BOOT_RESET_CORE

; ---------- internal define constants: ------------------------------------
;   .include "BOOT_RESET_DEF_public.inc"

; ---------- internal types: -----------------------------------------------
; none

; ---------- internal operations: ------------------------------------------
; none

; ---------- internal constants: -------------------------------------------
; Core_0 number
   .set     CORE_0_NB,  0x1
; Core_1 number
   .set     CORE_1_NB,  0x3
; Core_2 number
   .set     CORE_2_NB,  0x0
; ---------- internal data: ------------------------------------------------
; none

; ---------- provided operation bodies: ------------------------------------

; ----------------------------------------------------------------------------
; C PROTOTYPE :
; -----------------
;    void BOOT_RESET_CORE_0(void)
;    void BOOT_RESET_CORE_1(void)
;    void BOOT_RESET_CORE_2(void)

; STACK USAGE :
; -----------------
; None
;

; REGISTER USAGE :
; -----------------
; r20 : address on a



; -----------------
; BODY :



   .global  BOOT_RESET_CORE_0
   .global  BOOT_RESET_CORE_1
   .global  BOOT_RESET_CORE_2

   .extern  CORE_0_MAPPING

   .extern  CORE_1_MAPPING

   .extern  CORE_2_MAPPING

   .section  ".init_core_c0", "ax"
   ; the align 4 is mandatory because the address of BOOT_RESET_CORE is givent to the MC_ME_CADDR register which
   ; impose that the address is align on 4 bytes.
   .align 4

; Implements REQ_[User Project Name]_BOOT-LLR_051
BOOT_RESET_CORE_0:
   LIS      r20, CORE_0_MAPPING@ha
   ADDI     r20, r20, CORE_0_MAPPING@l

   ;  Set BOOT_MAIN_START_SW input parameter (core number)
   LIS      r3, CORE_0_NB@ha
   ADDI     r3, r3, CORE_0_NB@l

;  jump to core initialization function
   B       BOOT_RESET_CORE

   .section  ".init_core_c1", "ax"
   ; the align 4 is mandatory because the address of BOOT_RESET_CORE is givent to the MC_ME_CADDR register which
   ; impose that the address is align on 4 bytes.
   .align 4

; Implements REQ_[User Project Name]_BOOT-LLR_052
BOOT_RESET_CORE_1:
   LIS      r20, CORE_1_MAPPING@ha
   ADDI     r20, r20, CORE_1_MAPPING@l

   ;  Set BOOT_MAIN_START_SW input parameter (core number)
   LIS      r3, CORE_1_NB@ha
   ADDI     r3, r3, CORE_1_NB@l

;  jump to core initialization function
   B       BOOT_RESET_CORE


   .section  ".init_core_c2", "ax"
   ; the align 4 is mandatory because the address of BOOT_RESET_CORE is givent to the MC_ME_CADDR register which
   ; impose that the address is align on 4 bytes.
   .align 4

; Implements REQ_[User Project Name]_BOOT-LLR_053
BOOT_RESET_CORE_2:
   LIS      r20, CORE_2_MAPPING@ha
   ADDI     r20, r20, CORE_2_MAPPING@l

   ;  Set BOOT_MAIN_START_SW input parameter (core number)
   LIS      r3, CORE_2_NB@ha
   ADDI     r3, r3, CORE_2_NB@l

;  jump to core initialization function
   B       BOOT_RESET_CORE



; ---------- internal operation bodies: ------------------------------------
; none

   .end
