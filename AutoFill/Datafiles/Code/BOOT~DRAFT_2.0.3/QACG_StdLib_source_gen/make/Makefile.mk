LIB_FOLDER := ../../QACG_StdLib_source_gen/lib
LIB_NAME := StdLib
OBJ_FOLDER := ../../QACG_StdLib_source_gen/obj
#SCI := ITF
SOURCES_FILES:=\
ACos.c\
CopySign.c\
Floor.c\
IsZero.c\
Memcpy.c\
Sqrt.c\
ASin.c\
Cos.c\
IsInf.c\
LibIEEE.c\
RestrictedPow.c\
Tan.c\
ATan.c\
CubeRoot.c\
IsNan.c\
LibTrig.c\
Sin.c\
ATan2.c\
Expo.c\
IsSubnormal.c\
Log2.c\
SinCos.c

VPATH = ../../QACG_StdLib_source/MCP_StdLib_source


INCLUDE_FILES := .

include ../../Makefile/MakefileLibGenerical.mk




