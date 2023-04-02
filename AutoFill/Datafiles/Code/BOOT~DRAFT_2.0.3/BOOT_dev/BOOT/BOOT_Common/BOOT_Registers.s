#/***********************************************************************************************************************
#*
#*                                                Safran Electronics & Defense
#*
#* _BEGIN_FILE_HEADER --------------------------------------------------------------------------------------------------
#*
#* File name  : RLB_RBI_Registers.P2020.s
#* CSC name   :
#*
#* Description: Regisers interface CSU.
#*
#* Configuration management identification:
#*    %full_name:  sknNEXT#1/ascii/BOOT_Registers.s/2 %
#*    Creation  :
#*
#* _END_FILE_HEADER ----------------------------------------------------------------------------------------------------
#*
#* LANGUAGE: ASM - Source file
#*
#* ---------------------------------------------------------------------------------------------------------------------
#* Copyright (c) 2017, SAFRAN E&D
# * SAFRAN Electronics & Defense document. Reproduction and disclosure forbidden.
#**********************************************************************************************************************/
   .file "BOOT_Registers.s"

#/* _BEGIN_INCLUDE ========================================== INCLUDE FILES ========================================== */
   .include "BOOT_Registers.inc"
   .include "BOOT_VectorTable.inc"
#/* _END_INCLUDE ===================================================================================================== */

#/* _BEGIN_EXTERN_FUNCTION ========EXTERN FUNCTIONS DEFINITIONS ============ */
   .text

   #/* Flush cash parameters */
   .set     C_CACHE_LINE_SIZE,          32

   .global BSP_REG_GetHid0Register
   .global REG_WriteTlbEntry
   .global REG_InvalidateTlb
   .global REG_ClearSPEFSCR
   .global REG_SetPID
   .global BSP_REG_SCEnableFloatIt
   .global BSP_REG_SCDisableFloatIt
   .global BSP_REG_EnableFP
   .global BSP_REG_DisableFP
   .global BSP_REG_GetDec
   .global BSP_REG_GetSRR0
   .global BSP_REG_GetSRR1
   .global BSP_REG_GetStoredR1

   .global getTicks

   getTicks:
      mftbl   r3
      blr

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000186                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  BSP_REG_GetHid0Register                                                                           */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  This function returns the value of HID0 register. This is an assembly language function functi */
#/* on because HID0 can only be accessed in assembly language.                                                         */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
BSP_REG_GetHid0Register:
   mfspr       r3, REG_HID0

   blr
#/*End of BSP_REG_GetHid0Register*/

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000020                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  REG_WriteTlbEntry                                                                                 */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  This function sets one process TLB registes by copying input values to selected TLB register.  */
#/* This is an assembly function.                                                                                      */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
REG_WriteTlbEntry:
   #/* Prepare MMU Assist registers */
   mtspr    REG_MAS0,   r3
   mtspr    REG_MAS1,   r4
   mtspr    REG_MAS2,   r5
   mtspr    REG_MAS3,   r6
   mtspr    REG_MAS7,   r7

   #/* Write TLB entry */
   REG_TLB_LOAD

   blr
#/*End of REG_WriteTlbEntry */

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000059                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  REG_InvalidateTlb                                                                                 */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  This function does a flash invalidate. It invalidates all non protected TLB entries.           */
#/*                     Only DMS TLB entries shall be protected.                                                       */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
REG_InvalidateTlb:
   #/* Invalidate all non protected TLB entries */
   #/* Only DMS TLB entries shall be protected */
   REG_MMUCSR0_FI_SET r3

   #/* Clears r4 */
   lis      r4,         0x00000000@ha
   addi     r4,   r4,   0x00000000@l

tlbLoop:
   #/* Read MMUCSR0 */
   mfspr    r3,   REG_MMUCSR0

   #/* Loop while TLB invalidation is not finished (FI bit is set) */
   cmp      0 , 0 , r3 , r4
   bgt      tlbLoop

   blr
#/*End of REG_InvalidateTlb */

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000196                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  REG_ClearFPSCR                                                                                    */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  Clear the FPSCR register using the mtfsfi instruction.                                         */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
REG_ClearSPEFSCR:
   #/* r3 := 0x00000000 */
   lis      r3,         0x00000000@ha
   addi     r3,   r3,   0x00000000@l

   #/* SPEFSCR := r3 */
   mtspr    REG_SPEFSCR, r3

   #/* See E500CORERM �2.16 */
   isync

   blr
#/*End of REG_ClearFPSCR */

REG_SetPID:
   mtspr    REG_PID0, r3

   #/* See E500CORERM �2.16 */
   isync

   blr

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000191                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  BSP_REG_SCEnableFloatIt                                                                           */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  This function enables float interrupt in the process configuration. For the process, this conf */
#/* iguration is managed through the SRR1 register.                                                                    */
#/* This function is called by user processes through a system call.                                                   */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
BSP_REG_SCEnableFloatIt:

   #/* There is no FPU in E200Z6 core. Therefore FE0 and FE1 bit in MSR has not effect. */
   #/* Floating point error will be handle with SPE (see IVOR33). There is no global    */
   #/* SPE error interrupt inhibition bit. IT are only enabled by error type through    */
   #/* SPEFSCR bits.

   blr
#/*End of BSP_REG_SCEnableFloatIt */

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000192                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  BSP_REG_SCDisableFloatIt                                                                          */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  This function disables float interrupt in the process configuration. For the process, this con */
#/* figuration is managed through the SRR1 register.                                                                   */
#/* This function is called by user processes through a system call.                                                   */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
BSP_REG_SCDisableFloatIt:

   #/* There is no FPU in E200Z6 core. Therefore FE0 and FE1 bit in MSR has not effect. */
   #/* Floating point error will be handle with SPE (see IVOR33). There is no global    */
   #/* SPE error interrupt inhibition bit. IT are only enabled by error type through    */
   #/* SPEFSCR bits.

   blr
#/*End of BSP_REG_SCDisableFloatIt */

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000159                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  BSP_REG_EnableFP                                                                                  */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  This function enables floating point operation. This is an assembly function.                  */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
BSP_REG_EnableFP:
   REG_MSR_SET_SPE r12
   blr
#/*End of BSP_REG_EnableFP */

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000160                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  BSP_REG_DisableFP                                                                                 */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  This function disables floating point operation. This is an assembly function.                 */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
BSP_REG_DisableFP:
   REG_MSR_CLEAR_SPE r12
   blr
#/*End of BSP_REG_DisableFP */

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000112                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  BSP_REG_GetDec                                                                                    */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  This function returns the DEC register value.                                                  */
#/* It is used by the "GetDec" service. It is also used to compute execution time of a process. This is an assembly fu */
#/* nction.                                                                                                            */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
BSP_REG_GetDec:

   #/* Gets DEC register value */
   mfdec    r3

   blr
#/*End of BSP_REG_GetDec */

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000XXX                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  BSP_REG_GetSRR0                                                                                   */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  Return the SRR0 register value.                                                                */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
BSP_REG_GetSRR0:
   #/* Get SRR0 register value */
   mfsrr0  r3

   blr
#/*End of BSP_REG_GetSRR0*/

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000XXX                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  BSP_REG_GetSRR1                                                                                   */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  Return the SRR1 register value.                                                                */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
BSP_REG_GetSRR1:
   #/* Get SRR1 register value */
   mfsrr1  r3

   blr
#/*End of BSP_REG_GetSRR1*/

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000XXX                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  BSP_REG_GetStoredR1                                                                               */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  Return the context stored value of R1 register.                                                */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
BSP_REG_GetStoredR1:

   #/* Checks if we come from kernel code       */
   #/* by checking backup of MSR EE bit in SRR1 */
   mfsrr1   r3
   rlwinm   r3,   r3,    0,  16,   16
   cmpi     0,    0,    r3,   0  #/* SRR1[EE] == 0 ? */

   bne      .GSR_FromUser

   #/* If we come from superviser, return current R1 register value */
   mr       r3,   r1

   blr

.GSR_FromUser:
   #/* If we come from user, get current process stored R1 register value */

   #/* Get start of stack context area */
   mfsprg0 r3

   #/* Get stored R1 value */
   lwz     r3, C_R1_OFFSET(r3)

   blr
#/*End of BSP_REG_GetStoredR1*/
#/* _END_EXTERN_FUNCTION ==================================================== */
