; Save and restore registers
.set    REG_SRR0    ,26
.set    REG_SRR1    ,27

; Interrupt vector registers
.set    REG_IVPR    ,63
.set    REG_IVOR0   ,400
.set    REG_IVOR1   ,401
.set    REG_IVOR2   ,402
.set    REG_IVOR3   ,403
.set    REG_IVOR4   ,404
.set    REG_IVOR5   ,405
.set    REG_IVOR6   ,406
.set    REG_IVOR7   ,407
.set    REG_IVOR8   ,408
.set    REG_IVOR9   ,409
.set    REG_IVOR10  ,410
.set    REG_IVOR11  ,411
.set    REG_IVOR12  ,412
.set    REG_IVOR13  ,413
.set    REG_IVOR14  ,414
.set    REG_IVOR15  ,415
.set    REG_IVOR32  ,528
.set    REG_IVOR33  ,529
.set    REG_IVOR34  ,530
.set    REG_IVOR35  ,531

; Hardware Implementation Dependent registers
.set    REG_HID0    ,1008
.set    REG_HID1    ,1009

; Branch Unit Control and Status Register
.set    REG_BUCSR   ,1013

; Time base registers
.set    REG_TBL         ,284        # Timer Base Lower bits
.set    REG_TBU         ,285        # Timer Base Upper bits
.set    REG_TSR         ,336        # Timer Status Register
.set    REG_TSR_DIS_DIT ,0x08000000 # Decrementer Interrupt Status bit of TSR register
.set    REG_TCR         ,340        # Timer Control Register
.set    REG_DEC         ,22         # Decrementer Register
.set    REG_DECAR       ,54         # Decrementer Auto-Reload Register

; Process ID register
.set    REG_PID0        ,48

; MMU Assist registers
.set    REG_MAS0        ,624
.set    REG_MAS1        ,625
.set    REG_MAS2        ,626
.set    REG_MAS3        ,627
.set    REG_MAS4        ,628
.set    REG_MAS6        ,630
.set    REG_MAS7        ,944

; Cache registers
.set    REG_L1CSR0      ,1010   # L1 data Cache Control and Status Register
.set    REG_L1CSR1      ,1011   # L1 instruction Cache Control and Status Register
.set    REG_L1FINV      ,1016   # L1 Cache FLush and Invalidate Register

; MMU Control register
.set    REG_MMUCSR0     ,1012

; SPE APU Status and Control Register
.set    REG_SPEFSCR     ,512

.set    C_REG_TESCR1_ADDRESS,   0xFF010040

; MSR bit masks
.set    C_SET_SPE_BIT_MASK,     0x0200
.set    C_CLEAR_SPE_BIT_MASK_S, 7
.set    C_CLEAR_SPE_BIT_MASK_E, 5

; MMUCSR0 bit masks
.set    C_SET_FI_BIT_MASK,          0x0006

; L1CSR0 bit masks
.set    C_SET_CE_BIT_MASK,      0x0001
.set    C_SET_CINV_BIT_MASK,    0x0002
.set    C_CINV_BIT_NBR,         30
.set    C_SET_CABT_BIT_MASK,    0x0004
.set    C_CABT_BIT_NBR,         29

; BUCSR values
.set    C_REG_BUCSR_BPEN,   0x00000001  # Enable branch target buffer
.set    C_REG_BUCSR_BBFI,   0x00000200  # Invalidate branch target buffer

; L2 Cache ConTroL register
.set    C_REG_L2CTR_offset, 0x00020000
.set    C_SET_L2E_BIT_MASK, 0x8000
.set    C_SET_L2I_BIT_MASK, 0x4000

#/* _END_CONSTANT ==================================================================================================== */

#/* _BEGIN_MACRO ================================================ MACROS ============================================= */

#/*=================================================================================================================== */
#/*                                                        MSR                                                         */
#/*=================================================================================================================== */

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000022                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  REG_MSR_WRITE                                                                                     */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  This function writes a new MSR value. The MSR register is writeable only in supervisor mode. I */
#/* t is a macro function in assembly language.                                                                        */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
REG_MSR_WRITE: .macro v_reg1
	sync
	mtmsr    v_reg1
	sync
	isync
	.endm

#/*End of REG_MSR_WRITE*/

#/*=================================================================================================================== */
#/*                                                    CACHE                                                           */
#/*=================================================================================================================== */

#/* Set CINV bit in L1CSR0 register to invalidate cache and wait for end of invalidation */
REG_L1CSR0_CINV: .macro v_reg
CINV_start\@:
	#/* Get L1CSR0 register value */
	mfspr    v_reg, REG_L1CSR0                      # v_reg := REG_L1CSR0

	#/* Set CINV bit */
	ori      v_reg, v_reg, C_SET_CINV_BIT_MASK      # v_reg := v_reg | C_SET_CINV_BIT_MASK

	#/* Update L1CSR0 register value */
	msync                                           # Mandatory sync instruction (see E200Z6_RM �2.13.1)
	isync
	mtspr    REG_L1CSR0, v_reg                      # REG_L1CSR0 := v_reg

	#/* Wait for end of cache invalidation (CINV bit to 0) */
CINV_loop\@:
	#/* Read L1CSR0 register value */
	mfspr    v_reg, REG_L1CSR0                      # v_reg := REG_L1CSR0

	#/* Clear all bits but CINV */
	rlwinm   v_reg, v_reg, 0, C_CINV_BIT_NBR, C_CINV_BIT_NBR # v_reg := v_reg & C_SET_CINV_BIT_MASK

	#/* If CINV bit is still set then loop */
	cmpwi    0, v_reg, C_SET_CINV_BIT_MASK
	beq      CINV_loop\@


	#/* Check that cache invalidation completed successfully */
	#/* Read L1CSR0 register value */
	mfspr    v_reg, REG_L1CSR0                      # v_reg := REG_L1CSR0

	#/* Clear all bits but CABT */
	rlwinm   v_reg, v_reg, 0, C_CABT_BIT_NBR, C_CABT_BIT_NBR # v_reg := v_reg & C_SET_CABT_BIT_MASK

	#/* If CABT bit is still set then retry cache invalidation */
	cmpwi    0, v_reg, C_SET_CABT_BIT_MASK
	beq      CINV_start\@

	.endm

# Set CE bit in L1CSR0 register to enable L1 data cache
REG_L1CSR0_SET_CE: .macro v_reg

	#/* Get L1CSR0 register value */
	mfspr    v_reg, REG_L1CSR0                      # v_reg := REG_L1CSR0

	#/* Set CINV bit */
	ori      v_reg, v_reg, C_SET_CE_BIT_MASK        # v_reg := v_reg | C_SET_CE_BIT_MASK

	#/* Update L1CSR0 register value */
	msync                                           # Mandatory sync instruction (see E200Z6_RM �2.13.1)
	isync
	mtspr    REG_L1CSR0, v_reg                      # REG_L1CSR0 := v_reg

	.endm

# Set CE bit in L1CSR1 register to enable L1 instruction cache
REG_L1CSR1_SET_CE: .macro v_reg

	#/* Get L1CSR0 register value */
	mfspr    v_reg, REG_L1CSR1                      # v_reg := REG_L1CSR1

	#/* Set CINV bit */
	ori      v_reg, v_reg, C_SET_CE_BIT_MASK        # v_reg := v_reg | C_SET_CE_BIT_MASK

	#/* Update L1CSR0 register value */
	msync                                           # Mandatory sync instruction (see E200Z6_RM �2.13.1)
	isync
	mtspr    REG_L1CSR1, v_reg                      # REG_L1CSR1 := v_reg

	.endm

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000021                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  REG_DTLB_LOAD                                                                                     */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  This function loads a PTE into a DTLB register by using the "tlbld" instruction that loads the */
#/*  data TLB entry from DCMP and RPA registers value. The register in parameter contains the value of the effective a */
#/* ddress of the TLB entry. It is a macro function in assembly language.                                              */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
REG_TLB_LOAD: .macro
	sync
	tlbwe
	isync

	.endm
#/*End of REG_DTLB_LOAD*/

#/* _END_MACRO ======================================================================================================= */
