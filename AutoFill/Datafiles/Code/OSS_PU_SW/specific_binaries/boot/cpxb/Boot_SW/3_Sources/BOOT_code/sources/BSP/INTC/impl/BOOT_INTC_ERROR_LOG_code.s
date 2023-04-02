;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : Common instructions of all exceptions handlers (all cores)
; --------------------------------------------------------------------------

; ---------- include required interface: -----------------------------------
   .extern __SP_BOOT_INTC_ERROR_END
   .extern _BOOT_SDA2_BASE_
   .extern _BOOT_INTC_ERROR_SDA_BASE_

 ; tres important, cela permet au link de ne pas supprimer les donnees BOOT_INTC_EX_VECTOR_CRITICAL_INPUT
   .extern BOOT_INTC_VECTOR_CRITICAL_INPUT
   .extern V_BOOT_PBIT_INTC

   .global BOOT_INTC_ERROR_LOG
   .set BOOT_EXECUTION_FLAG, 0xB007
   .set PBIT_CMPU_FLAG, 0x99887766

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
;  void BOOT_INTC_ERROR_LOG( uint32_t p_errorCode)
;

;  ---------- REGISTER  USAGE: ------------------------------------------------


; TODO : implementer du code pour interruption inattendu
BOOT_INTC_ERROR_LOG:

; The code line 52 to 72 and 119 to 140 is required for PBIT on INTC and REG_PROT
   ; -----------------------------------------------------------;
   ;                      Save LR in stack                      ;
   ; -----------------------------------------------------------;
   STWU  r8 , -0x4(r1)
   STWU  r7 , -0x4(r1)
   STWU  r6 , -0x4(r1)
   STWU  r5 , -0x4(r1)
   MFSPR r5, REG_LR
   STWU  r5 , -0x4(r1)

   ; -----------------------------------------------------------;
   ;       Look if the exception was raised during BIT          ;
   ; -----------------------------------------------------------;

   LIS    r5,V_BOOT_PBIT_INTC@ha
   ADDI   r5, r5, V_BOOT_PBIT_INTC@l
   LWZU   r6, 0x0(r5)

   LIS    r7,PBIT_CMPU_FLAG@ha
   ADDI   r7, r7, PBIT_CMPU_FLAG@l

   ; If V_BOOT_PBIT_INTC = PBIT_CMPU_FLAG, the exception has been caused by a BIT
   ; return to BIT
   CMP    r6, r7
   BEQ    BOOT_INTC_RETURN_TO_BIT

   ;  Disable external interrupts for the current core
   WRTEEI   0
   ISYNC

   ; -----------------------------------------------------------;
   ;                       Manage the error                     ;
   ; -----------------------------------------------------------;

   ; Special treatment is done if the exception is an externel interrupt
   LIS 		r4, BOOT_FAULT_EXT_IT@ha
   ADDI 	r4, r4, BOOT_FAULT_EXT_IT@l
   CMP 		r3, r4
   BNE 		BOOT_INTC_ERROR_MANAGEMENT

   ; Get PIR register in order to know on which core is being executed
   MFSPR    r3, REG_PIR
   BL BOOT_INTC_GET_EXT_IT_SRC


BOOT_INTC_ERROR_MANAGEMENT:

   ;param 1 = error code
   ;param 2 = origin ID
   LI r4, INTC_ORIGIN
   ;param 3 =  Address of the instruction
   MFSPR  r5, REG_SRR0
   ;param 4 = Core number
   MFSPR  r6, REG_PIR
   ;param 5 = Stack pointer value
   MFSPR  r7, REG_SPRG0
   ;param 6 = indication that the boot was executing
   LIS     r8, BOOT_EXECUTION_FLAG@ha
   ADDI    r8, r8, BOOT_EXECUTION_FLAG@l

   ; Power PC EABI : move the stack pointer from 8 bytes
   STWU     r1, -8 (r1)

   BL     BOOT_FAULT_LOG
   BL     BOOT_FAULT_INFINITELOOP

; The code line 52 to 72 and 119 to 140 is required for PBIT on INTC and REG_PROT
   ; -----------------------------------------------------------;
   ;                 Compute the return address                 ;
   ; -----------------------------------------------------------;

BOOT_INTC_RETURN_TO_BIT:

   ;  Enable external interrupts
   WRTEEI   1
   ISYNC

   ;  set V_BOOT_PBIT_INTC to error code
   STWU   r3, 0x0(r5)

   ;  r3  = the error code
   ;  r4  = LR when the exception occurs
   BL BOOT_INTC_SET_RFI_ADDR

   ; -----------------------------------------------------------;
   ;   Restore LR to return to BOOT_INTC_MACRO_CALL_ERROR_LOG   ;
   ; -----------------------------------------------------------;
   LWZU  r5 , 0x0(r1)
   MTSPR REG_LR, r5
   LWZU  r5 , 0x4(r1)
   LWZU  r6 , 0x4(r1)
   LWZU  r7 , 0x4(r1)
   LWZU  r8 , 0x4(r1)
   ADDI   r1, r1, 4

   ; -----------------------------------------------------------;

   BLR

   .end
