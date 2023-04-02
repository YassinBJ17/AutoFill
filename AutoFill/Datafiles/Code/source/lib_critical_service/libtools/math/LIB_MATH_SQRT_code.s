#/* --------------------------------------------------------------------------
# *                        SAFRAN Electronics & Defense
# *                   Reproduction and disclosure forbidden.
# * -------------------------------------------------------------------------- */
   .text
   .global sqrt
   .align 4

sqrt:
   efssqrt r3, r3
   blr

   .end
