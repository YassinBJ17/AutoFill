# this file defines the common targets

# compiler
CC := dcc

# compiler flags
CFLAGS := -tP1011EH:simple -O -g2 -X3=0 -X6=1 -X7=1 -X8 -X9=3 -X11 -X12 -X15=0 -X16=0 -X18=4 -X19=0 -X21=0 -X23 -X25=2 -X27=0x725A7777 -X28=0xFFFFA3D6 -X29 -X31=0 -X32=2 -X35=0 -X36=1 -X38=0 -X43 -Xsavefpr-avoid -X49=8 -X53=1 -X54=4 -X60=1 -X63=0 -X66 -X70 -X74=0xFF -X76=4 -X77=0 -X78=0xFF0000 -X82=1 -X83=3 -X84=0x08 -X86=3 -X88=0 -X91=1 -X97=0 -X98=0 -X103=0x41 -X115=0 -X118=1 -X119=4 -X125 -X127=0 -X129=1 -X139 -X143=0 -X146=6 -X147=3 -X153=2 -X154=0x00C000C1 -Xdebug-local-cie -Xshow-configuration=1 -X180=0 -X191=1 -X194=0 -X199=0 -X404=0x2000 -X419 -X422=10000000 -X423=6000000 -X424=600000 -Xno-builtin -Xalternate-coloring -X451=1 -Xname-const=.rodata -Xname-string=.rodata -Xswitch-array-off -DP2020 -DFLOAT_64

# assembler
AS := das

# assembler flags
ASFLAGS := -tP1011EH:simple -l -Xalign-fill-text=16 -Xalign-value=4 -Xasm-debug-on -Xheader -Xlabel-colon -Xoptim-off

# archiver 
AR := dar

# archiver flags
ARFLAGS := -rcu

# linker
LD := dld

# linker flags
LDFLAGS := -tP1011EH:simple -m6 -Xbranch-islands -Xcheck-input-patterns=2 -Xcheck-overlapping -Xelf -Xrescan-libraries -Xrescan-restart -Xunused-sections-list -Xremove-unused-sections

# depend command
DEP := gcc

# depend arg
DEP_ARG := -MM

# dumper command
DUMP := ddump

# dumper options for converting elf into abs
DD_ARG := -R -n .intvec,.text,.sdata2


# LUP creator command
LUP := objcopy

# LUP options for converting abs into lup
LUP_ARG := -I elf32-big -O binary