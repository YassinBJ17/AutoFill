# ----------------------------------------------------------------------------------------------------------------------
#                                             SAFRAN Electronics & Defense
#                                        Reproduction and disclosure forbidden.
# ----------------------------------------------------------------------------------------------------------------------
# DESCRIPTION : Configuration file for makefile
# ----------------------------------------------------------------------------------------------------------------------

# Tools command --------------------------------------------------------------------------------------------------------
# Recursive wildcard
RWILDCARD                     =  $(foreach d,$(wildcard $(1:=/*)),$(call RWILDCARD,$d,$2) $(filter $(subst *,%,$2),$d))

# *.c compilation and its flags
CC                            =  dcc
CFLAGS                        =  -tPPCE200Z710N3VFF -O -Xshow-configuration=1 -X3=1 -X6=1 -X7=1 -X9=3 -X15=0 -X16=0 \
                                 -X18=4 -X19=0 -X25=2 -X32=2 -X43 -X49=8 -X53=1 -X54=4 -X60=1 -X76=4 -X82=1 -X83=3 \
                                 -X84=0x08 -X97=0 -X98=0 -X118=1 -X139 -X191=1 -Xname-const=.rodata \
                                 -Xname-string=.rodata -Xname-uconst=.rodata -Xswitch-table-off -Xswitch-array-off \
                                 -Xno-builtin -Xsavefpr-avoid -H -X8 -X11 -X12 -X21=0 -X23 -X27=0x721A7777 \
                                 -X28=0xFFFFA3D6 -X29 -X31=0 -X35=0 -X36=1 -X38=0 -X63=0 -X66 -X70=2 -X74=0xFF -X77=0 \
                                 -X78=0xFF0000 -X86=3 -X88=0 -X91=1 -X103=0x41 -X119=4 -X125 -X127=0 -X146=6 -X147=3 \
                                 -X153=2 -X154=0x00C000C1 -X180=0 -X194=0 -X199=0 -X404=0x2000 -X419 -X422=10000000 \
                                 -X423=6000000 -X424=600000 -X451=1 -Xalternate-coloring -Xlocal-data-area=0 -X58=6 \
                                 -X96=3 -X129=1 -g2 -Xdebug-dwarf2 -Xdebug-local-cie -ee1500 -ee1481

# *.s compilation and its flags
AS                            =  das
SFLAGS                        =  -tPPCE200Z710N3VFF -l -Xheader -Xoptim-off -Xlabel-colon -Xalign-value=4 \
                                 -Xalign-fill-text=16 -Xasm-debug-on -Xasm-debug-on

# *.o archiving and its flags
AR                            =  dar
RFLAGS                        =  -rcu

# Directories ----------------------------------------------------------------------------------------------------------
# Base directory
DIR_TOP                       =  R:

# Generation directories
DIR_OUT                       =  $(DIR_TOP)/_build_out
DIR_ARC                       =  $(DIR_OUT)/arc
DIR_DEP                       =  $(DIR_OUT)/dep
DIR_LOG                       =  $(DIR_OUT)/log
DIR_OBJ                       =  $(DIR_OUT)/obj

# Source directories
DIR_SRC                       =  $(DIR_TOP)/source
DIR_SRC_CSS_WRAPPER_G1_2_3    =  $(DIR_SRC)/css_wrapper_g1_2_3
DIR_SRC_CSS_WRAPPER_G4        =  $(DIR_SRC)/css_wrapper_g4
DIR_SRC_CSS_WRAPPER_STUB      =  $(DIR_SRC)/css_wrapper_stub
DIR_SRC_LIB_CRITICAL_SERVICE  =  $(DIR_SRC)/lib_critical_service
DIR_SRC_MCSS_WRAPPER          =  $(DIR_SRC)/mcss_wrapper
DIR_SRC_OSS                   =  $(DIR_SRC)/oss
DIR_SRC_SHARED                =  $(DIR_SRC)/shared
DIR_SRC_UOD_WRAPPER           =  $(DIR_SRC)/uod_wrapper

# Log file -------------------------------------------------------------------------------------------------------------
LOG                           =  $(DIR_LOG)/log.txt

# Generated elements by *.c and *.s compilation after archiving --------------------------------------------------------
ARC_CSS_WRAPPER_G1_2_3        =  $(DIR_ARC)/css_wrapper_g1_2_3.a
ARC_CSS_WRAPPER_G4            =  $(DIR_ARC)/css_wrapper_g4.a
ARC_CSS_WRAPPER_STUB          =  $(DIR_ARC)/css_wrapper_stub.a
ARC_LIB_CRITICAL_SERVICE      =  $(DIR_ARC)/lib_critical_service.a
ARC_MCSS_WRAPPER              =  $(DIR_ARC)/mcss_wrapper.a
ARC_OSS                       =  $(DIR_ARC)/oss.a
ARC_SHARED                    =  $(DIR_ARC)/shared.a
ARC_UOD_WRAPPER               =  $(DIR_ARC)/uod_wrapper.a
ARC_UOD                       =  R:/specific_binaries/uod_lib/UODG.a
