;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : Starting point for embedded software
; --------------------------------------------------------------------------

; ---------- include required interface: -----------------------------------

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

;----------------------------------------------------------------------------
; C PROTOTYPE :
;-----------------
;
;

;  STACK USAGE :
;-----------------
;

;  REGISTER USAGE :
; -----------------
;

; -----------------
;  BODY :
;
;
   .extern BOOT_RESET_PLATFORM

;   b[31-16] : 0x005A corresponds to the Boot_Header_ID. It indicates to the mpc that the boot header is valid.
;   b[15-4]  : not implemented
;   b[3-0]: 0b0001, only CPU2 is enabled
;   see paragraph 8.4.3.20 of MPC5777MRM
   .set BOOT_RCHW_CONF, 0x005A0001

   .extern _BOOT_SDA2_BASE_
   .extern _BOOT_SDA_BASE
   .extern __BOOT_PLATFORM_SP_INIT



   .file "BOOT_RESET_RCHW_code.s"
   .section ".rchw", "ax"
   .globl BOOT_RCHW_HEADER
   .align 4


;  boot header configuration 7.11.2.3
BOOT_RCHW_HEADER:
   .long BOOT_RCHW_CONF                         ; Boot header configuration
   .long BOOT_RESET_PLATFORM                    ; CPU2 reset vector
   .long 0x00000000                             ; Configuration bits
   .long 0x00000000                             ; Configuration bits
   .long 0x00000000                             ; CPU0 reset vector
   .long 0x00000000                             ; CPU1 reset vector
   .long 0x00000000                             ; CPUC reset vector


; -----------------
;  BODY OF the DEFAULT RESET VECTOR
; -----------------
;     CORE 2
; -----------------

   .section  ".boot_c2", "ax"
   .globl   BOOT_RESETVECTOR_CPU_2
   .align 4

; CPU2 reset vector
BOOT_RESETVECTOR_CPU_2:
; jump to core_2 initialization function
   BL       BOOT_RESET_PLATFORM
INFINITE_LOOP_CPU2:
   B        INFINITE_LOOP_CPU2

; -----------------
;     CORE 0
; -----------------

   .section  ".boot_c0", "ax"
   .globl   BOOT_RESETVECTOR_CPU_0

   .align 4
; CPU0 reset vector
BOOT_RESETVECTOR_CPU_0:
; jump to core_0 initialization function
INFINITE_LOOP_CPU0:
   B        INFINITE_LOOP_CPU0

; -----------------
;     CORE 1
; -----------------

   .section  ".boot_c1", "ax"
   .globl   BOOT_RESETVECTOR_CPU_1

   .align 4
; CPU1 reset vector
BOOT_RESETVECTOR_CPU_1:
; jump to core_1 initialization function
INFINITE_LOOP_CPU1:
   B        INFINITE_LOOP_CPU1

; -----------------
;     CORE CC
; -----------------

   .section  ".boot_cc", "ax"
   .globl   BOOT_RESETVECTOR_CPU_CC

   .align 4
; CheckCore reset vector
BOOT_RESETVECTOR_CPU_CC:
; jump to checker_core initialization function
INFINITE_LOOP_CPUCC:
   B        INFINITE_LOOP_CPUCC




   .end
