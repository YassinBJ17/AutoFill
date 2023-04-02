# ----------------------------------------------------------------------------------------------------------------------
#                                             SAFRAN Electronics & Defense
#                                        Reproduction and disclosure forbidden.
# ----------------------------------------------------------------------------------------------------------------------
# DESCRIPTION : Configuration file for makefile (for psyko exclusively)
# ----------------------------------------------------------------------------------------------------------------------

# Tools command --------------------------------------------------------------------------------------------------------
# *.psyo compilation and *.parto / *.app generation
PSYKO                         =  "C:/Program Files (x86)/Krono-Safe/psyko-8.13.3/bin/psyko.exe" \
                                 --product power-mpc5777m-module \
                                 --kernel-dir "C:/Program Files (x86)/Krono-Safe/rtk-power-mpc5777m-module-4.4.5"

# *.dic generation and its flags
MD                            =  R:/tools/make_dico/makedic.exe -e
DFLAGS                        =  -f {0},{2},{3},{4:x} -l 256 -d

# Directories ----------------------------------------------------------------------------------------------------------
# Configuration directories
DIR_BLD                       =  $(DIR_TOP)/_build_proc
DIR_CFG                       =  $(DIR_BLD)/cfg
DIR_KMY                       =  $(DIR_BLD)/kmy

# Generation directories
DIR_AST                       =  $(DIR_OUT)/ast
DIR_DIC                       =  $(DIR_OUT)/dico
DIR_GEN                       =  $(DIR_OUT)/gen
DIR_INC                       =  $(DIR_OUT)/inc
DIR_LNK                       =  $(DIR_OUT)/lnk
DIR_PFL                       =  $(DIR_OUT)/pfl

# Link options generated -----------------------------------------------------------------------------------------------
LINK_PARTO_STUB_UOD_OSS_INT_SRC              =  $(DIR_LNK)/parto_stub_uod_oss_int_src.hjson
LINK_PARTO_STUB_UOD_OSS_EXT_SRC              =  $(DIR_LNK)/parto_stub_uod_oss_ext_src.hjson
LINK_PARTO_G1_2_3_OSS_INT_SRC                =  $(DIR_LNK)/parto_g1_2_3_oss_int_src.hjson
LINK_PARTO_G1_2_3_OSS_EXT_SRC                =  $(DIR_LNK)/parto_g1_2_3_oss_ext_src.hjson
LINK_PARTO_G4_OSS_INT_SRC                    =  $(DIR_LNK)/parto_g4_oss_int_src.hjson
LINK_PARTO_G4_OSS_EXT_SRC                    =  $(DIR_LNK)/parto_g4_oss_ext_src.hjson
LINK_APP_STUB_UOD_OSS_INT_SRC                =  $(DIR_LNK)/app_stub_uod_oss_int_src.hjson
LINK_APP_STUB_UOD_OSS_EXT_SRC                =  $(DIR_LNK)/app_stub_uod_oss_ext_src.hjson
LINK_APP_G1_2_3_OSS_INT_SRC                  =  $(DIR_LNK)/app_g1_2_3_oss_int_src.hjson
LINK_APP_G1_2_3_OSS_EXT_SRC                  =  $(DIR_LNK)/app_g1_2_3_oss_ext_src.hjson
LINK_APP_G4_OSS_INT_SRC                      =  $(DIR_LNK)/app_g4_oss_int_src.hjson
LINK_APP_G4_OSS_EXT_SRC                      =  $(DIR_LNK)/app_g4_oss_ext_src.hjson

# Configuration files to use or generate KMEMORY -----------------------------------------------------------------------
CONF_TO_GEN_KMEM_PARTO_G1_2_3_OSS            =  $(DIR_CFG)/conf_to_gen_kmem_parto_g1_2_3_oss.hjson
CONF_TO_USE_KMEM_PARTO_G1_2_3_OSS_PATCHED    =  $(DIR_CFG)/conf_to_use_kmem_parto_g1_2_3_oss_patched.hjson
CONF_TO_GEN_KMEM_PARTO_G4_OSS                =  $(DIR_CFG)/conf_to_gen_kmem_parto_g4_oss.hjson
CONF_TO_USE_KMEM_PARTO_G4_OSS_PATCHED        =  $(DIR_CFG)/conf_to_use_kmem_parto_g4_oss_patched.hjson
CONF_TO_GEN_KMEM_PARTO_STUB_UOD_OSS          =  $(DIR_CFG)/conf_to_gen_kmem_parto_stub_uod_oss.hjson
CONF_TO_USE_KMEM_PARTO_STUB_UOD_OSS_PATCHED  =  $(DIR_CFG)/conf_to_use_kmem_parto_stub_uod_oss_patched.hjson
CONF_TO_GEN_KMEM_APP_G1_2_3_OSS              =  $(DIR_CFG)/conf_to_gen_kmem_app_g1_2_3_oss.hjson
CONF_TO_GEN_KMEM_APP_G4_OSS                  =  $(DIR_CFG)/conf_to_gen_kmem_app_g4_oss.hjson
CONF_TO_GEN_KMEM_APP_STUB_UOD_OSS            =  $(DIR_CFG)/conf_to_gen_kmem_app_stub_uod_oss.hjson

# Budget ---------------------------------------------------------------------------------------------------------------
BUDGET                                       =  $(DIR_CFG)/budget.bgt

# Compilation options for psy ------------------------------------------------------------------------------------------
COMP_OPT_SRC_EXT                             =  $(DIR_CFG)/psy_compile_src_ext.hjson
COMP_OPT_SRC_INT                             =  $(DIR_CFG)/psy_compile_src_int.hjson

# KMEMORY --------------------------------------------------------------------------------------------------------------
KMEM_PARTO_G4_OSS_GEN                        =  $(DIR_KMY)/kmem_parto_g4_oss_gen.hjson
KMEM_PARTO_G4_OSS_PATCHED                    =  $(DIR_KMY)/kmem_parto_g4_oss_patched.hjson
KMEM_PARTO_G1_2_3_OSS_GEN                    =  $(DIR_KMY)/kmem_parto_g1_2_3_oss_gen.hjson
KMEM_PARTO_G1_2_3_OSS_PATCHED                =  $(DIR_KMY)/kmem_parto_g1_2_3_oss_patched.hjson
KMEM_PARTO_STUB_UOD_OSS_GEN                  =  $(DIR_KMY)/kmem_parto_stub_uod_oss_gen.hjson
KMEM_PARTO_STUB_UOD_OSS_PATCHED              =  $(DIR_KMY)/kmem_parto_stub_uod_oss_patched.hjson
KMEM_APP_PERIPH_G1_2_3_OSS                   =  $(DIR_KMY)/kmem_app_g1_2_3_oss_periph.hjson
KMEM_APP_PERIPH_G4_OSS                       =  $(DIR_KMY)/kmem_app_g4_oss_periph.hjson
KMEM_APP_PERIPH_STUB_UOD_OSS                 =  $(DIR_KMY)/kmem_app_stub_uod_oss_periph.hjson

# Partition and application --------------------------------------------------------------------------------------------
PARTO_G1_2_3_OSS_PARTO_INT_SRC               =  $(DIR_GEN)/g1_2_3/parto_g1_2_3_oss_int_src.parto
PARTO_G1_2_3_OSS_ELF_INT_SRC                 =  $(DIR_GEN)/g1_2_3/parto_g1_2_3_oss_int_src.elf
APP_G1_2_3_OSS_APP_INT_SRC                   =  $(DIR_GEN)/g1_2_3/app_g1_2_3_oss_int_src.app
APP_G1_2_3_OSS_ELF_INT_SRC                   =  $(DIR_GEN)/g1_2_3/app_g1_2_3_oss_int_src.elf
PARTO_G1_2_3_OSS_PARTO_EXT_SRC               =  $(DIR_GEN)/g1_2_3/parto_g1_2_3_oss_ext_src.parto
PARTO_G1_2_3_OSS_ELF_EXT_SRC                 =  $(DIR_GEN)/g1_2_3/parto_g1_2_3_oss_ext_src.elf
APP_G1_2_3_OSS_APP_EXT_SRC                   =  $(DIR_GEN)/g1_2_3/app_g1_2_3_oss_ext_src.app
APP_G1_2_3_OSS_ELF_EXT_SRC                   =  $(DIR_GEN)/g1_2_3/app_g1_2_3_oss_ext_src.elf
PARTO_G4_OSS_PARTO_INT_SRC                   =  $(DIR_GEN)/g4/parto_g4_oss_int_src.parto
PARTO_G4_OSS_ELF_INT_SRC                     =  $(DIR_GEN)/g4/parto_g4_oss_int_src.elf
APP_G4_OSS_APP_INT_SRC                       =  $(DIR_GEN)/g4/app_g4_oss_int_src.app
APP_G4_OSS_ELF_INT_SRC                       =  $(DIR_GEN)/g4/app_g4_oss_int_src.elf
PARTO_G4_OSS_PARTO_EXT_SRC                   =  $(DIR_GEN)/g4/parto_g4_oss_ext_src.parto
PARTO_G4_OSS_ELF_EXT_SRC                     =  $(DIR_GEN)/g4/parto_g4_oss_ext_src.elf
APP_G4_OSS_APP_EXT_SRC                       =  $(DIR_GEN)/g4/app_g4_oss_ext_src.app
APP_G4_OSS_ELF_EXT_SRC                       =  $(DIR_GEN)/g4/app_g4_oss_ext_src.elf
PARTO_STUB_UOD_OSS_PARTO_INT_SRC             =  $(DIR_GEN)/stub_uod/parto_stub_uod_oss_int_src.parto
PARTO_STUB_UOD_OSS_ELF_INT_SRC               =  $(DIR_GEN)/stub_uod/parto_stub_uod_oss_int_src.elf
APP_STUB_UOD_OSS_APP_INT_SRC                 =  $(DIR_GEN)/stub_uod/app_stub_uod_oss_int_src.app
APP_STUB_UOD_OSS_ELF_INT_SRC                 =  $(DIR_GEN)/stub_uod/app_stub_uod_oss_int_src.elf
PARTO_STUB_UOD_OSS_PARTO_EXT_SRC             =  $(DIR_GEN)/stub_uod/parto_stub_uod_oss_ext_src.parto
PARTO_STUB_UOD_OSS_ELF_EXT_SRC               =  $(DIR_GEN)/stub_uod/parto_stub_uod_oss_ext_src.elf
APP_STUB_UOD_OSS_APP_EXT_SRC                 =  $(DIR_GEN)/stub_uod/app_stub_uod_oss_ext_src.app
APP_STUB_UOD_OSS_ELF_EXT_SRC                 =  $(DIR_GEN)/stub_uod/app_stub_uod_oss_ext_src.elf
SRCO_INT_SOURCE_SRCO                         =  R:/specific_binaries/int_source/realtime.srco
SRCO_INT_SOURCE_ELF                          =  R:/specific_binaries/int_source/realtime.elf
SRCO_EXT_SOURCE_SRCO                         =  R:/specific_binaries/ext_source/_build_out/gen/xt_source.srco
SRCO_EXT_SOURCE_ELF                          =  R:/specific_binaries/ext_source/_build_out/gen/xt_source.elf
EMO_ERROR_HANDLER_EMO                        =  R:/specific_binaries/error_handler/_build_out/gen/emo_error_handler.emo
EMO_ERROR_HANDLER_ELF                        =  R:/specific_binaries/error_handler/_build_out/gen/emo_error_handler.elf

# Asterios generation directories --------------------------------------------------------------------------------------
G1_2_3_OSS_PARTO_INT_SRC_GENDIR              =  $(DIR_AST)/g1_2_3_oss_parto_int_src
G1_2_3_OSS_APP_INT_SRC_GENDIR                =  $(DIR_AST)/g1_2_3_oss_app_int_src
G1_2_3_OSS_PARTO_EXT_SRC_GENDIR              =  $(DIR_AST)/g1_2_3_oss_parto_ext_src
G1_2_3_OSS_APP_EXT_SRC_GENDIR                =  $(DIR_AST)/g1_2_3_oss_app_ext_src
G4_OSS_PARTO_INT_SRC_GENDIR                  =  $(DIR_AST)/g4_oss_parto_int_src
G4_OSS_APP_INT_SRC_GENDIR                    =  $(DIR_AST)/g4_oss_app_int_src
G4_OSS_PARTO_EXT_SRC_GENDIR                  =  $(DIR_AST)/g4_oss_parto_ext_src
G4_OSS_APP_EXT_SRC_GENDIR                    =  $(DIR_AST)/g4_oss_app_ext_src
STUB_UOD_OSS_PARTO_INT_SRC_GENDIR            =  $(DIR_AST)/stub_uod_oss_parto_int_src
STUB_UOD_OSS_APP_INT_SRC_GENDIR              =  $(DIR_AST)/stub_uod_oss_app_int_src
STUB_UOD_OSS_PARTO_EXT_SRC_GENDIR            =  $(DIR_AST)/stub_uod_oss_parto_ext_src
STUB_UOD_OSS_APP_EXT_SRC_GENDIR              =  $(DIR_AST)/stub_uod_oss_app_ext_src
