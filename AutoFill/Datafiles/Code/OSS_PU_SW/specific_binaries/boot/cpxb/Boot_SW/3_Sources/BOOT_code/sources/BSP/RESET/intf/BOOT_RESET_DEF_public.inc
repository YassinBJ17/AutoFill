;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION  :
;---------------------------------------------------------------------------
;
; ---------- include required interface: -----------------------------------
; none
;
; ---------- provided macro: -----------------------------------------------
; none
;
; ---------- provided constant: ------------------------------------------------

;   - Code definition for Special Purpose Register

;    Identifier for register used for indicating conditions such as carries and overflows for integer operation
   .set     REG_XER             ,1

;    Identifier for Link register
   .set     REG_LR              ,8

;    Identifier for Count Register
   .set     REG_CTR             ,9

;    Identifier for  save/restore register 0
   .set     REG_SRR0            ,26

;    Identifier for  save/restore register 1
   .set     REG_SRR1            ,27

;    Identifier for Critical save/restore register 0
   .set     REG_CSRR0           ,58

;    Identifier for Critical save/restore register 1
   .set     REG_CSRR1           ,59

;    Identifier for Data Exception Address
   .set     REG_DEAR            ,61

;    Identifier for Exeception Syndrome register
   .set     REG_ESR             ,62

;    Identifier for IVPR  Interrupt Vector Base Address
   .set     REG_IVPR            ,63

;    Identifier for USPRG0 register
   .set     REG_USPRG0          ,256

;    Identifier for SPRG0 register
   .set     REG_SPRG0           ,272

;    Identifier for SPRG1 register
   .set     REG_SPRG1           ,273

;    Identifier for SPRG2 register
   .set     REG_SPRG2           ,274

;    Identifier for SPRG3 register
   .set     REG_SPRG3           ,275

;    Identifier of the Processor Version special purpose register
   .set     REG_PIR             ,286

;    Identifier End-to-End ECC Control Register 0 (E2ECTL0)
   .set     REG_DCR             ,510

;    Identifier for APU status and control Register 0
   .set     REG_SPEFSCR         ,512

;    Identifier for Machine Check Save Restore register
   .set     REG_MCSRR0          ,570

;    Identifier for Machine Check Save Restore register
   .set     REG_MCSRR1          ,571

;    Identifier for Machine Check Save Restore register
   .set     REG_MCSR            ,572

;    Identifier for Debug Interrupt SRR register 0
   .set     REG_DSRR0           ,574

;    Identifier for Debug Interrupt SRR register 1
   .set     REG_DSRR1           ,575

;    Identifier of the HID0 special purpose register
   .set     REG_HID0            ,1008

;    Identifier of the HID1 special purpose register
   .set     REG_HID1            ,1009

;    Identifier of the L1CSR0 special purpose register
   .set     REG_L1CSR0          ,1010

;    Identifier of the L1CSR1 special purpose register
   .set     REG_L1CSR1          ,1011

;    Identifier of the BTB special purpose register
   .set     REG_BUCSR           ,1013

;    Identifier of the MPU0CSR0 special purpose register
   .set     REG_MPU0CSR0        ,1014

;----------------------------------
;  Core_0 and Core_1 (e200Z710n3)
;----------------------------------


;    L1CSR0: ??=0, WID=0000, WDD=0000, DCWM=00, DCWA=00,
;    DCECE=0, DCEI=0, DCEDT=00, DCLC=0, DCUL=0, DCLO=0, DCLFC=0, DCLOA=0, DCEA=00, DCBZ32=0, DCABT=0, DCINV=1, DCE=0
   .set     DCACHE_L1CSR0_VALUE     ,0x00000002
   .set     DCACHE_L1CSR0_ABT_MSK   ,0xFFFFFFFB
   .set     DCACHE_L1CSR0_ABT_VALUE ,0x00000004

;    L1CSR1: ??=0, ICECE=0, ICEI=0, ICEDT=00, ICUL=0, ICLO=0, ICLFC=0, ICLOA=0, ICEA=00, ICABT=0, ICINV=1, ICE=0
   .set     ICACHE_L1CSR1_VALUE     ,0x00000002
   .set     ICACHE_L1CSR1_ABT_MSK   ,0xFFFFFFFB
   .set     ICACHE_L1CSR1_ABT_VALUE ,0x00000004

;    BUCSR: ??=0, BPFI=1, BALLOC=0, BPRED=0, BPEN=1
   .set     BUCSR_VALUE       ,0x00000201

   .set     MCSR_CLEAR_VALUE  ,0xFFFFFFFF
; System RAM address
   .set SYSTEM_RAM_L,  0x40000000
   .set SYSTEM_RAM_H,  0x40065000

; Initialization value of RAMs
   .set INIT_SRAM_VAL_1, 0x00000000
   .set INIT_SRAM_VAL_2, 0x00000000

;    Core MSR: ??=0,CE=0,??=0,EE=0,PR=0,??=0,ME=0,??=0,DE=0,??=0,PMM=0,RI=0,??=0
   .set     CORE_MSR_VALUE, 0x00

   .set     STACK_END_VAL, 0xDEADC0DE

; ---------- provided operation: -------------------------------------------
; none
