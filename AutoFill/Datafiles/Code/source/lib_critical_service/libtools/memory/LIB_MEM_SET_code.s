#/* --------------------------------------------------------------------------
# *                           Sagem Defense Securite
# *                               SAFRAN Group
# * --------------------------------------------------------------------------
# * DESCRIPTION : Performs a initialization of a memory area
# * -------------------------------------------------------------------------- */

#/* ---------- include required interface: ----------------------------------- */

#/* ---------- internal define constants: ------------------------------------ */

#/* ---------- internal types: ----------------------------------------------- */

#/* ---------- internal operations: ------------------------------------------ */

#/* ---------- internal constants: ------------------------------------------- */

#/* ---------- internal data: ------------------------------------------------ */

#/* ---------- provided operation bodies: ------------------------------------ */
    
#/*   
#void LIB_MEM_SET( void  const * buffer_pt,
#                          BSW_INTEGER  const init_value,
#                          BSW_UNSIGNED const length )
#*/

   .text
   .global LIB_MEM_SET
#   .type   LIB_MEM_SET, %function
   .align 4

#/* */
LIB_MEM_SET:
#   /* Prepare the character into memory */
#   /* Shift it once on the left of 8 bits */
   rlwimi   r4,r4,8,16,23
#   /* Then shift it on the left of 16 bits */
   rlwimi   r4,r4,16,0,15

#   /* Store the address of buff in GPR6 */
   addi  r6,r3,-4
#   /* Compare GPR5 to 4 and store comparison result into CR */
   cmpi 0,0,r5,4
#   /* Branch to 7 label if less or equal */
   blt   7f
#   /* */
#   /* Store byte from GPR4 into GPR6 on 4 bytes and go to next 4 characters */
#   /* of GPR6 */
   stwu  r4,4(r6)
#   /* If previous comparison set the bit EQ (i.e. number of bytes to */
#   /* initialise) return to the caller */
#   beqlr
   beq out

#   /* Prepare the number of loops that will be done. Each loop will write 4*/
#   /* bytes at once. The result is moved to GPR0 */
   andi. r0,r6,3
   add   r5,r0,r5
   subf  r6,r0,r6
   srwi  r0,r5,2
#   /* Move GPR0 content to CTR register */
   mtctr r0
#   /* Decrement CTR, branch to label 7 if CTR = 0 */
   bdz   6f

#   /* Store byte from GPR4 into GPR6 on 4 bytes and go to next 4 characters */
#   /* of GPR6 */
1: stwu  r4,4(r6)
#   /* Decrement CTR, branch to memset_0004 if CTR != 0 */
   bdnz  1b

#   /* Calculate the number of remaining loops */
6: andi. r5,r5,3

#   /* Compare GPR5 to 0 and store comparison result into CR */
7: cmpi 0,0,r5,0
#   /* If the result of comparison is equal, return to the caller */
#   beqlr
   beq out
#   /* Move GPR5 content to CTR register */
   mtctr r5
   addi  r6,r6,3

#   /* Store byte from GPR4 into GPR6 on 1 byte and go to next byte of GPR6 */
8: stbu  r4,1(r6)
#   /* Decrement CTR, branch if CTR != 0 */
   bdnz  8b
#   /* Return to the caller */
out:
   blr

   .end



