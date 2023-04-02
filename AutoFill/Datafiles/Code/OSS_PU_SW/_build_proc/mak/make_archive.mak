# ----------------------------------------------------------------------------------------------------------------------
#                                             SAFRAN Electronics & Defense
#                                        Reproduction and disclosure forbidden.
# ----------------------------------------------------------------------------------------------------------------------
# DESCRIPTION : Instantiate the generic part for compiling and archiving
# ----------------------------------------------------------------------------------------------------------------------

# Instantiate the generic part for the CSS_WRAPPER_G1_2_3
DIR_SRC_PARAM  =  $(DIR_SRC_CSS_WRAPPER_G1_2_3)
ARCHIVE_NAME   =  $(ARC_CSS_WRAPPER_G1_2_3)

# Include generic part of the makefile
include R:/_build_proc/mak/make_generic.mak

# Instantiate the generic part for the CSS_WRAPPER_G4
DIR_SRC_PARAM  =  $(DIR_SRC_CSS_WRAPPER_G4)
ARCHIVE_NAME   =  $(ARC_CSS_WRAPPER_G4)

# Include generic part of the makefile
include R:/_build_proc/mak/make_generic.mak

# Instantiate the generic part for the CSS_WRAPPER_STUB
DIR_SRC_PARAM  =  $(DIR_SRC_CSS_WRAPPER_STUB)
ARCHIVE_NAME   =  $(ARC_CSS_WRAPPER_STUB)

# Include generic part of the makefile
include R:/_build_proc/mak/make_generic.mak

# Instantiate the generic part for the LIB_CRITICAL_SERVICE
DIR_SRC_PARAM  =  $(DIR_SRC_LIB_CRITICAL_SERVICE)
ARCHIVE_NAME   =  $(ARC_LIB_CRITICAL_SERVICE)

# Include generic part of the makefile
include R:/_build_proc/mak/make_generic.mak

# Instantiate the generic part for the MCSS_WRAPPER
DIR_SRC_PARAM  =  $(DIR_SRC_MCSS_WRAPPER)
ARCHIVE_NAME   =  $(ARC_MCSS_WRAPPER)

# Include generic part of the makefile
include R:/_build_proc/mak/make_generic.mak

# Instantiate the generic part for the OSS
DIR_SRC_PARAM  =  $(DIR_SRC_OSS)
ARCHIVE_NAME   =  $(ARC_OSS)

# Include generic part of the makefile
include R:/_build_proc/mak/make_generic.mak

# Instantiate the generic part for the SHARED
DIR_SRC_PARAM  =  $(DIR_SRC_SHARED)
ARCHIVE_NAME   =  $(ARC_SHARED)

# Include generic part of the makefile
include R:/_build_proc/mak/make_generic.mak

# Instantiate the generic part for the UOD_WRAPPER
DIR_SRC_PARAM  =  $(DIR_SRC_UOD_WRAPPER)
ARCHIVE_NAME   =  $(ARC_UOD_WRAPPER)

# Include generic part of the makefile
include R:/_build_proc/mak/make_generic.mak
