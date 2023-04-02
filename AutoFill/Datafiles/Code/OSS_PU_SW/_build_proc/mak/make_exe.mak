# ----------------------------------------------------------------------------------------------------------------------
#                                             SAFRAN Electronics & Defense
#                                        Reproduction and disclosure forbidden.
# ----------------------------------------------------------------------------------------------------------------------
# DESCRIPTION : Instantiate the generic part for compiling psy
# ----------------------------------------------------------------------------------------------------------------------

# CSS_WRAPPER_G1_2_3 ---------------------------------------------------------------------------------------------------
# Instantiate the generic part for the CSS_WRAPPER_G1_2_3 for internal source
DIR_SRC_PARAM1    =  $(DIR_SRC_CSS_WRAPPER_G1_2_3)
DIR_SRC_PARAM2    =  $(DIR_SRC_MCSS_WRAPPER)
SRC_TYPE          =  src_int
# Enable these lines to generate a kmemory
# KMY_NAME          =  $(KMEM_PARTO_G1_2_3_OSS_GEN)
# KMY_DEP           =  $(CONF_TO_GEN_KMEM_PARTO_G1_2_3_OSS) $(ARC_CSS_WRAPPER_G1_2_3) $(ARC_MCSS_WRAPPER)
DIR_GEN_PARAM     =  $(DIR_EXE)/g1_2_3
KMY_PATCHED_NAME  =  $(KMEM_PARTO_G1_2_3_OSS_PATCHED)
PAR_NAME          =  $(PARTO_G1_2_3_OSS_PARTO_INT_SRC)
PAR_DEP           =  $(CONF_TO_USE_KMEM_PARTO_G1_2_3_OSS_PATCHED) $(LINK_PARTO_G1_2_3_OSS_INT_SRC) \
                     $(ARC_CSS_WRAPPER_G1_2_3) $(ARC_MCSS_WRAPPER)
DIR_PAR           =  $(G1_2_3_OSS_PARTO_INT_SRC_GENDIR)
APP_NAME          =  $(APP_G1_2_3_OSS_ELF_INT_SRC)
KMY_APP_NAME      =  $(KMEM_APP_PERIPH_G1_2_3_OSS)
APP_DEP           =  $(CONF_TO_GEN_KMEM_APP_G1_2_3_OSS) $(PARTO_G1_2_3_OSS_PARTO_INT_SRC) $(LINK_APP_G1_2_3_OSS_INT_SRC) \
                     $(SRCO_INT_SOURCE_SRCO) $(EMO_ERROR_HANDLER_EMO)

# Include generic part of the makefile
include R:/_build_proc/mak/make_generic_psyko.mak

# Instantiate the generic part for the CSS_WRAPPER_G1_2_3 for external source
DIR_SRC_PARAM1    =  $(DIR_SRC_CSS_WRAPPER_G1_2_3)
DIR_SRC_PARAM2    =  $(DIR_SRC_MCSS_WRAPPER)
SRC_TYPE          =  src_ext
# Enable these lines to generate a kmemory
# KMY_NAME          =  $(KMEM_PARTO_G1_2_3_OSS_GEN)
# KMY_DEP           =  $(CONF_TO_GEN_KMEM_PARTO_G1_2_3_OSS) $(ARC_CSS_WRAPPER_G1_2_3) $(ARC_MCSS_WRAPPER)
DIR_GEN_PARAM     =  $(DIR_EXE)/g1_2_3
KMY_PATCHED_NAME  =  $(KMEM_PARTO_G1_2_3_OSS_PATCHED)
PAR_NAME          =  $(PARTO_G1_2_3_OSS_PARTO_EXT_SRC)
PAR_DEP           =  $(CONF_TO_USE_KMEM_PARTO_G1_2_3_OSS_PATCHED) $(LINK_PARTO_G1_2_3_OSS_EXT_SRC) \
                     $(ARC_CSS_WRAPPER_G1_2_3) $(ARC_MCSS_WRAPPER)
DIR_PAR           =  $(G1_2_3_OSS_PARTO_EXT_SRC_GENDIR)
APP_NAME          =  $(APP_G1_2_3_OSS_ELF_EXT_SRC)
KMY_APP_NAME      =  $(KMEM_APP_PERIPH_G1_2_3_OSS)
APP_DEP           =  $(CONF_TO_GEN_KMEM_APP_G1_2_3_OSS) $(PARTO_G1_2_3_OSS_PARTO_EXT_SRC) $(LINK_APP_G1_2_3_OSS_EXT_SRC) \
                     $(SRCO_EXT_SOURCE_SRCO) $(EMO_ERROR_HANDLER_EMO)

# Include generic part of the makefile
include R:/_build_proc/mak/make_generic_psyko.mak

# CSS_WRAPPER_G4 ---------------------------------------------------------------------------------------------------
# Instantiate the generic part for the CSS_WRAPPER_G4 for internal source
DIR_SRC_PARAM1    =  $(DIR_SRC_CSS_WRAPPER_G4)
DIR_SRC_PARAM2    =  $(DIR_SRC_MCSS_WRAPPER)
SRC_TYPE          =  src_int
# Enable these lines to generate a kmemory
# KMY_NAME          =  $(KMEM_PARTO_G4_OSS_GEN)
# KMY_DEP           =  $(CONF_TO_GEN_KMEM_PARTO_G4_OSS) $(ARC_CSS_WRAPPER_G4) $(ARC_MCSS_WRAPPER)
DIR_GEN_PARAM     =  $(DIR_EXE)/g4
KMY_PATCHED_NAME  =  $(KMEM_PARTO_G4_OSS_PATCHED)
PAR_NAME          =  $(PARTO_G4_OSS_PARTO_INT_SRC)
PAR_DEP           =  $(CONF_TO_USE_KMEM_PARTO_G4_OSS_PATCHED) $(LINK_PARTO_G4_OSS_INT_SRC) \
                     $(ARC_CSS_WRAPPER_G4) $(ARC_MCSS_WRAPPER)
DIR_PAR           =  $(G4_OSS_PARTO_INT_SRC_GENDIR)
APP_NAME          =  $(APP_G4_OSS_ELF_INT_SRC)
KMY_APP_NAME      =  $(KMEM_APP_PERIPH_G4_OSS)
APP_DEP           =  $(CONF_TO_GEN_KMEM_APP_G4_OSS) $(PARTO_G4_OSS_PARTO_INT_SRC) $(LINK_APP_G4_OSS_INT_SRC) \
                     $(SRCO_INT_SOURCE_SRCO) $(EMO_ERROR_HANDLER_EMO)

# Include generic part of the makefile
include R:/_build_proc/mak/make_generic_psyko.mak

# Instantiate the generic part for the CSS_WRAPPER_G4 for external source
DIR_SRC_PARAM1    =  $(DIR_SRC_CSS_WRAPPER_G4)
DIR_SRC_PARAM2    =  $(DIR_SRC_MCSS_WRAPPER)
SRC_TYPE          =  src_ext
# Enable these lines to generate a kmemory
# KMY_NAME          =  $(KMEM_PARTO_G4_OSS_GEN)
# KMY_DEP           =  $(CONF_TO_GEN_KMEM_PARTO_G4_OSS) $(ARC_CSS_WRAPPER_G4) $(ARC_MCSS_WRAPPER)
DIR_GEN_PARAM     =  $(DIR_EXE)/g4
KMY_PATCHED_NAME  =  $(KMEM_PARTO_G4_OSS_PATCHED)
PAR_NAME          =  $(PARTO_G4_OSS_PARTO_EXT_SRC)
PAR_DEP           =  $(CONF_TO_USE_KMEM_PARTO_G4_OSS_PATCHED) $(LINK_PARTO_G4_OSS_EXT_SRC) \
                     $(ARC_CSS_WRAPPER_G4) $(ARC_MCSS_WRAPPER)
DIR_PAR           =  $(G4_OSS_PARTO_EXT_SRC_GENDIR)
APP_NAME          =  $(APP_G4_OSS_ELF_EXT_SRC)
KMY_APP_NAME      =  $(KMEM_APP_PERIPH_G4_OSS)
APP_DEP           =  $(CONF_TO_GEN_KMEM_APP_G4_OSS) $(PARTO_G4_OSS_PARTO_EXT_SRC) $(LINK_APP_G4_OSS_EXT_SRC) \
                     $(SRCO_EXT_SOURCE_SRCO) $(EMO_ERROR_HANDLER_EMO)

# Include generic part of the makefile
include R:/_build_proc/mak/make_generic_psyko.mak

# STUB_UOD -------------------------------------------------------------------------------------------------------------
# Instantiate the generic part for the STUB_UOD for internal source
DIR_SRC_PARAM1    =  $(DIR_SRC_UOD_WRAPPER)
DIR_SRC_PARAM2    =  $(DIR_SRC_CSS_WRAPPER_STUB)
SRC_TYPE          =  src_int
# Enable these lines to generate a kmemory
# KMY_NAME          =  $(KMEM_PARTO_STUB_UOD_OSS_GEN)
# # $(ARC_UOD_WRAPPER) $(ARC_CSS_WRAPPER_STUB) ==> to add to the following line if not empty
# KMY_DEP           =  $(CONF_TO_GEN_KMEM_PARTO_STUB_UOD_OSS) $(ARC_UOD)
DIR_GEN_PARAM     =  $(DIR_EXE)/stub_uod
KMY_PATCHED_NAME  =  $(KMEM_PARTO_STUB_UOD_OSS_PATCHED)
PAR_NAME          =  $(PARTO_STUB_UOD_OSS_PARTO_INT_SRC)
PAR_DEP           =  $(CONF_TO_USE_KMEM_PARTO_STUB_UOD_OSS_PATCHED) $(LINK_PARTO_STUB_UOD_OSS_INT_SRC) \
                     $(ARC_UOD)
DIR_PAR           =  $(STUB_UOD_OSS_PARTO_INT_SRC_GENDIR)
APP_NAME          =  $(APP_STUB_UOD_OSS_ELF_INT_SRC)
KMY_APP_NAME      =  $(KMEM_APP_PERIPH_STUB_UOD_OSS)
APP_DEP           =  $(CONF_TO_GEN_KMEM_APP_STUB_UOD_OSS) $(PARTO_STUB_UOD_OSS_PARTO_INT_SRC) $(LINK_APP_STUB_UOD_OSS_INT_SRC) \
                     $(SRCO_INT_SOURCE_SRCO) $(EMO_ERROR_HANDLER_EMO)

# Include generic part of the makefile
include R:/_build_proc/mak/make_generic_psyko.mak

# Instantiate the generic part for the STUB_UOD for external source
DIR_SRC_PARAM1    =  $(DIR_SRC_UOD_WRAPPER)
DIR_SRC_PARAM2    =  $(DIR_SRC_CSS_WRAPPER_STUB)
SRC_TYPE          =  src_ext
# Enable these lines to generate a kmemory
# KMY_NAME          =  $(KMEM_PARTO_STUB_UOD_OSS_GEN)
# # $(ARC_UOD_WRAPPER) $(ARC_CSS_WRAPPER_STUB) ==> to add to the following line if not empty
# KMY_DEP           =  $(CONF_TO_GEN_KMEM_PARTO_STUB_UOD_OSS) $(ARC_UOD)
DIR_GEN_PARAM     =  $(DIR_EXE)/stub_uod
KMY_PATCHED_NAME  =  $(KMEM_PARTO_STUB_UOD_OSS_PATCHED)
PAR_NAME          =  $(PARTO_STUB_UOD_OSS_PARTO_EXT_SRC)
PAR_DEP           =  $(CONF_TO_USE_KMEM_PARTO_STUB_UOD_OSS_PATCHED) $(LINK_PARTO_STUB_UOD_OSS_EXT_SRC) \
                     $(ARC_UOD)
DIR_PAR           =  $(STUB_UOD_OSS_PARTO_EXT_SRC_GENDIR)
APP_NAME          =  $(APP_STUB_UOD_OSS_ELF_EXT_SRC)
KMY_APP_NAME      =  $(KMEM_APP_PERIPH_STUB_UOD_OSS)
APP_DEP           =  $(CONF_TO_GEN_KMEM_APP_STUB_UOD_OSS) $(PARTO_STUB_UOD_OSS_PARTO_EXT_SRC) $(LINK_APP_STUB_UOD_OSS_EXT_SRC) \
                     $(SRCO_EXT_SOURCE_SRCO) $(EMO_ERROR_HANDLER_EMO)

# Include generic part of the makefile
include R:/_build_proc/mak/make_generic_psyko.mak
