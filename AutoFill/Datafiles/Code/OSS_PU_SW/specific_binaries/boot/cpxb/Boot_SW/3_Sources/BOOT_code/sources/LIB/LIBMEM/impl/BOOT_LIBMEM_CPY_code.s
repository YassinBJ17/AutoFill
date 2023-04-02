#/*-****************************************************************************
#* Component   : memcpy
#* Usage       : memcpy function
#* Author      : Optimize lib C
#* Description : memcpy function
#******************************************************************************
#* Derogations :
#* N03, N04, N06, N07, P03b, P12 : See Memo T/TE/037
#******************************************************************************
#* Historic : $Log:   Z:/GCF_common/archives/commun/logiciel/dev/libcplt/Dev/String/memcpy.s-arc  $
; 
;    Rev 1.5   Dec 28 2006 16:36:42   g207692
; Tracability update and rewording.
; Resolution for 1333: DSDD update: tracability and rewording (EASA 20)
;
;    Rev 1.4   Aug 24 2006 18:28:30   g207686
; Tracability update
; Resolution for 1173: [DOC] DSDD update for traceability
;
;    Rev 1.3   Jun 12 2006 15:54:26   p050595
; Code update for DSDD generation
; Resolution for 1173: [DOC] DSDD update for traceability
;
;    Rev 1.2   Apr 06 2006 16:59:32   g208188
; Teuchos Run2
; Resolution for 948: [Merge Comment] : Groupe PLT_1
;
; Teuchos FFT-PLT-452 (A.Soularue)  : Addition of requirement tags
;
;    Rev 1.1   Jan 13 2006 15:50:12   g208188
; Merge Teuchos
; Resolution for 611: [Merge Teuchos] : LibCplt
;
;    Rev 1.0.1.0   Jan 05 2006 11:18:58   g208188
; Teuchos correction
; Resolution for 611: [Merge Teuchos] : LibCplt
;
; Teuchos FFT 456 (A.Soularue) : Corrections further to DSDD technical control
;
; Teuchos FFT 456 (R.Mevel): Addition of requirement tags and Rule Checker
;                               corrections
;
;    Rev 1.0   Oct 25 2005 16:03:44   p050540
; Initial revision.
; Resolution for 375: Add diabData Lib on PVCS
;
#*****************************************************************************/
#/*-***********************************/
#/*- Traceability information         */
#/* Element : LibCPLT                 */
#/* Component : String                */
#/* CSU : memcpy                      */
#/*-***********************************/
#/*****************************************************************************
#* IMPORTED COMPONENTS :
#*****************************************************************************/
#/* None */

#/*****************************************************************************
#* COMPONENT CONST :
#*****************************************************************************/
#/* None */

#/*****************************************************************************
#* LOCAL CONST :
#*****************************************************************************/
#/* None */

#/*****************************************************************************
#* COMPONENT VARIABLES :
#*****************************************************************************/
#/* None */

#/*****************************************************************************
#* LOCAL VARIABLES :
#*****************************************************************************/
#/* None */

#/*****************************************************************************
#* LOCAL PROTOTYPES :
#*****************************************************************************/
#/* None */

#/*****************************************************************************
#* GLOBAL FUNCTIONS :
#*****************************************************************************/

#/**
# * @fn memcpy(const void * buf1, const void * buf2, size_t n);
# *
# * Copy characters from one source buffer to a destination buffer
# *
# * @param buf1   IN/OUT Destination buffer
# * @param buf2   IN     Source Buffer
#*  @param n      IN     Number of characters to copy
# *
# * @return  - Pointer on destination buffer : buf1
# */
#/* */
#/*>< Requirements : */
#/* DSDD_PLT_memcpy_0001.1 */
#/*   - Rigth shift of 3 the content of GPR5 (number of characters to copy) */
#/*     and store it into GPR7 */
#/*   - Initialise GPR6 to the address of GPR3 (destination buffer) */
#/*   - If 8 bytes (i.e. value in GPR7) are to be processed */
#/*      - Go to requirement memcpy_0003 */
#/*   - Otherwise */
#/*      - Check if GPR6 is aligned doing a AND operation on the 3 lsb */
#/*        The result is stored into GPR0 */
#/*      - Move GPR7 content into CTR register (i.e. counter) */
#/*      - If the content of GPR0 is not 0 */
#/*         - Go to requirement memcpy_0005 */
#/* */
#/* ADDITIONAL_REQUIREMENT */
#/* SRS-PLT-3270.1 */
#/* SRS-PLT-3271.2 */
#/* */
#/* DSDD_PLT_memcpy_0002.1 */
#/*   - Loop while CTR content is not 0 */
#/*      - Load a 64-bits data from GPR4 (source buffer) and store it into */
#/*        GPR6 (destination buffer) */
#/*      - GPR4 and GPR6 are moved of 8 bytes */
#/*      - Decrement CTR */
#/* */
#/*   - Check alignment of GPR5 address and store the result into GPR5 */
#/* */
#/* ADDITIONAL_REQUIREMENT */
#/* SRS-PLT-3270.1 */
#/* SRS-PLT-3271.2 */
#/* */
#/* DSDD_PLT_memcpy_0003.1 */
#/*   - If adress pointed by GPR5 (number of value to copy) contents is less */
#/*     than 4 */
#/*      - Go to requirement memcpy_0004 */
#/*   - Otherwise */
#/*      - Load a 32-bits word from GPR4 and store it into GPR6 */
#/*      - Decrement GPR5 content of 4 */
#/*      - GPR4 and GPR6 are moved of 4 bytes */
#/* */
#/* ADDITIONAL_REQUIREMENT */
#/* SRS-PLT-3270.1 */
#/* SRS-PLT-3271.2 */
#/* */
#/* DSDD_PLT_memcpy_0004.1 */
#/*   - Check if GPR5 is equal to 0 */
#/*     If so */
#/*      - Return GPR3 (destination buffer) to the caller */
#/*   - Otherwise */
#/*      - Move GPR5 content into CTR register (i.e. counter) */
#/*      - Move GPR4 and GPR6 pointers */
#/*      - Loop while CTR is not 0 */
#/*         - Load byte from GPR4 and store it into GPR6 */
#/*         - GPR4 and GPR6 are moved of 1 byte */
#/*         - Decrement CTR */
#/* */
#/*   - Return GPR3 to the caller */
#/* */
#/* ADDITIONAL_REQUIREMENT */
#/* SRS-PLT-3270.1 */
#/* SRS-PLT-3271.2 */
#/* */
#/* DSDD_PLT_memcpy_0005.1 */
#/*   - Calculate the number of loops to do and store the result into CTR */
#/*     register (i.e. counter)*/
#/*   - Loop while CTR is not 0 */
#/*      - Load byte from GPR4 (source buffer) and store it into GPR6 */
#/*        (destination buffer) */
#/*      - GPR4 and GPR6 are moved of 1 byte */
#/* */
#/*   - Substract the content of GPR0 of GPR5 and store it into GPR5 */
#/*   - Rigth shift of 3 the content of GPR5 and store it into GPR7 */
#/*   - If 8 bytes (i.e. value in GPR7) are to be processed */
#/*      - Go to requirement memcpy_0003 */
#/*   - Otherwise*/
#/*      - Move GPR7 content into CTR register (i.e. counter) */
#/*      - Go to requirement memcpy_0002 */
#/* */
#/* ADDITIONAL_REQUIREMENT */
#/* SRS-PLT-3270.1 */
#/* SRS-PLT-3271.2 */
#/* */
   .text
   .global BOOT_LIBMEM_CPY
   .align 4

   #/*>< GPR3 contains the address of destination buffer */
   #/* */
   #/*>< GPR4 contains the address of source buffer */
   #/* */
   #/*>< GPR5 contains the number of characters to copy */
   #/* */
# takes 26.337 µs to copy 2624bytes
BOOT_LIBMEM_CPY:
   #/* */
   #/* DSDD_PLT_memcpy_0001.1 */
   #/* Right shift of 3 bits the content of GPR5 and put it into GPR7 */
   srwi. r7,r5,3
   #/* Store the address of buff1 in GPR6 */
   addi  r6,r3,-4
   #/*- Store the address of buff2 in GPR4 */
   addi  r4,r4,-4
   #/* Check if less than 8 bytes to do and branch to memcpy_0003 if so */
   beq   2f             #/*- if less than 8 bytes to do */
   #/* Checks the 3 lsb of GPR6 and put it into GPR0 */
   andi. r0,r6,3        #/*- get dest word aligned */
   #/* Move GPR7 content to CTR register */
   mtctr r7
   #/* If GPR0 is not equal to 0, branch to memcpy_0005 */
   bne   5f
   #/* */
   #/* DSDD_PLT_memcpy_0002.1 */
   #/* Load low order 32 bits word in GPR4 + 4 and store it into GPR7. */
1: lwz   r7,4(r4)
   #/* Load high order 32 bits word in GPR4 + 8 and store it into GPR8 */
   #/* Moves GPR4 of 8 bytes */
   lwzu  r8,8(r4)
   #/* Store word from GPR7 into GPR6 + 4 (i.e. low order 32 bits of GPR6)*/
   stw   r7,4(r6)
   #/* Store word from GPR8 into GPR6 + 4 (i.e. high order 32 bits of GPR6)*/
   #/* Moves GPR6 of 8 bytes */
   stwu  r8,8(r6)
   #/* Decrement CTR, branch if CTR != 0 */
   bdnz  1b
   #/* Check the 7 lsb of GPR5 and store the result into GPR5 */
   andi. r5,r5,7
   #/* */
   #/* DSDD_PLT_memcpy_0003.1 */
   #/* Compare GPR5 to 4 and store result into CR */
2: cmpli   0,0,r5,4
   #/* Branch to memcpy_0004 if less than 4 */
   blt   3f
   #/* Load word in GPR4 and store it into GPR0. Moves GPR4 of 4 bytes */
   lwzu  r0,4(r4)
   #/* Set GPR5 to GPR5 content - 4 */
   addi  r5,r5,-4
   #/* Store word from GPR0 into GPR6. Moves GPR6 of 4 bytes */
   stwu  r0,4(r6)
   #/* */
   #/* DSDD_PLT_memcpy_0004.1 */
   #/* Compare GPR5 to 0 and store result into CR */
3: cmpi 0,0,r5,0
   #/* If equal to 0, return to the caller */
   #beqlr
   beq 7f
   #/* Move GPR5 content into CTR */
   mtctr r5
   #/* Move GPR4 pointer */
   addi  r4,r4,3
   #/* Move GPR6 pointer */
   addi  r6,r6,3
   #/* Load byte in GPR4 and store it into GPR0. Moves GPR4 of 1 byte */
4: lbzu  r0,1(r4)
   #/* Store byte from GPR0 into GPR6. Moves GPR6 of 1 byte */
   stbu  r0,1(r6)
   #/* Decrement CTR, branch if CTR != 0 */
   bdnz  4b
   #/* Return to the caller */
7:   blr
   #/* */
   #/* DSDD_PLT_memcpy_0005.1 */
   #/* Do the calculation (~GPR0 content) + 4 + 1, and store it into GPR0 */
5: subfic   r0,r0,4
   #/* Move GPR0 content into CTR */
   mtctr r0
   #/* Load byte in GPR4 and store it into GPR7. */
6: lbz   r7,4(r4)
   #/* Move GPR4 of 1 byte */
   addi  r4,r4,1
   #/* Store byte from GPR7 into GPR6. */
   stb   r7,4(r6)
   #/* Move GPR6 of 1 byte */
   addi  r6,r6,1
   #/* Decrement CTR, branch if CTR != 0 */
   bdnz  6b
   #/* Substracts the contents of GPR0 and GPR5 and store the result into GPR5*/
   subf  r5,r0,r5
   #/* Right shift of 3 bits the content of GPR5 and put it into GPR7 */
   #rlwinm.  r7,r5,32-3,3,31
   srwi. r7,r5,3
   #/* Check if 8 bytes to do and branch to memcpy_0003 if so */
   beq   2b
   #/* Move GPR7 content into CTR */
   mtctr r7
   #/* Branch to memcpy_0002 */
   b  1b

   .end

#/* */
#/*************************************
#* LOCAL FUNCTIONS :
#*************************************/#
#/* None */
