;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : This functions sets the return address used by the instructions
;               rfi, rfdi, rfci, rfmci.
; ------------------------------------------------------------------------------

; ---------- include required interface: -----------------------------------


   .global BOOT_INTC_SET_RFI_ADDR

   .include "BOOT_RESET_DEF_public.inc"
   .include "BOOT_FAULT_public.inc"

   .text
   .align 4

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

;----------------------------------------------------------------------------
;  C PROTOTYPE :
;-----------------
;  void BOOT_INTC_SET_RFI_ADDR( uint32_t p_errorCode)
;

;  ---------- REGISTER  USAGE: ------------------------------------------------
;  When entering this function,
;  r3  = the error code

BOOT_INTC_SET_RFI_ADDR:

   STWU   r5 , -0x4(r1)
   STWU   r6 , -0x4(r1)

   ;-----------------------------------------------------------------------------;
   ;                       1) Is the computation required ?                      ;
   ;-----------------------------------------------------------------------------;

   ; In case the exception is a critical exception, a system call or a efpu round,
   ; the address respectively in CSRR0 and SRR0 corresponds to the next instruction
   ; to execute
   CMPI  0x0, 0x0, r3, BOOT_FAULT_CRITICAL_INPUT_IT
   BEQ   BOOT_INTC_SET_RFI_ADDR_END

   CMPI  0x0, 0x0, r3, BOOT_FAULT_SC_IT
   BEQ   BOOT_INTC_SET_RFI_ADDR_END

   CMPI  0x0, 0x0, r3, BOOT_FAULT_EFPU_ROUND_IT
   BEQ   BOOT_INTC_SET_RFI_ADDR_END

   ; If it is an instruction access IT, the address is in register REG_LR
   ; previously saved in r4 by BOOT_INTC_MACRO_CALL_ERROR_LOG.
   ; In this case, no computation is required because the exception has been raised
   ; by branching to an illegal area. Content of LR is the address of the next
   ; instruction
   CMPI  0x0, 0x0, r3, BOOT_FAULT_INST_ACCESS_IT
   BEQ BOOT_INTC_SET_ADDR

   ;-----------------------------------------------------------------------------;
   ;             2) Get the instruction depending on the exception               ;
   ;-----------------------------------------------------------------------------;

   ; For the other exceptions, the address in MCSRR0/DSRR0/SRR0 corresponds to
   ; the instruction that caused the exception

BOOT_INTC_MCSRR0:
   ; If it is a machine check exception, the address is in the register MCSRR0
   CMPI  0x0, 0x0, r3, BOOT_FAULT_MACHINE_CHECK_IT
   BNE   BOOT_INTC_DSRR0
   MFSPR r4, REG_MCSRR0
   B BOOT_INTC_COMPUTE_NEXT_INST

BOOT_INTC_DSRR0:
   ; If it is a debug exception, the address is in the register DSRR0
   CMPI  0x0, 0x0, r3, BOOT_FAULT_BRKPT_IT
   BNE   BOOT_INTC_SRR0
   MFSPR r4, REG_DSRR0
   B BOOT_INTC_COMPUTE_NEXT_INST

BOOT_INTC_SRR0:
   ; for other exceptions, the address is in the register SRR0
   MFSPR r4, REG_SRR0

   ;-----------------------------------------------------------------------------;
   ;                       3) Compute the next instruction                       ;
   ;-----------------------------------------------------------------------------;

BOOT_INTC_COMPUTE_NEXT_INST:

   ; Calculate the address of the next instruction
   ; If the first 4 bits have a value equal to 1, 3, 5 or 7,
   ; the instruction that caused the exception is a 32-bits instruction
   ; Else the first 4 bits have a value equal to 0, 2, 4, 6, 8, 9, A,
   ; B, C, D, E (and F, but F is reserved), and is a 16-bits instruction

   LHZ   r5, 0(r4)
   ANDI. r6, r5, 0x9000
   CMPI  0x0, 0x0, r6, 0x1000
   BNE   BOOT_INTC_ADJUST_INST_FOR_16BITS
   ADDI  r4, r4, 2

BOOT_INTC_ADJUST_INST_FOR_16BITS:
   ADDI  r4, r4, 2

   ;-----------------------------------------------------------------------------;
   ;              4) Set the return address for rfi, rfdi, rfmci                 ;
   ;-----------------------------------------------------------------------------;

BOOT_INTC_SET_ADDR:
   ; Set the return address
   MTSPR REG_MCSRR0, r4
   MTSPR REG_DSRR0, r4
   MTSPR REG_SRR0, r4

BOOT_INTC_SET_RFI_ADDR_END:

   LWZU   r6 , 0x0(r1)
   LWZU   r5 , 0x4(r1)
   ADDI   r1, r1, 4

   BLR

   .end
