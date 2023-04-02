SUBDIRS =\
AES\
ARINC_665\
COMMON\
CRC\
MEM\
NAND_FS\
SHA\
SIF

# CFLAGS for LIBUTI_A665:
# - A665_PART2: Allow Arinc 665 part2 loads
# - A665_PART3: Allow Arinc 665 part3 loads
# - A665_NODATA_ADDR: If set, support files will be placed right after LUH and data files addresses are set to NULL
# - A665_ADDR_ALIGN=N: If set, files addresses will be aligned to N bytes (default N=1)

SUBDIRS := $(foreach f, $(SUBDIRS), ../$(f))

export EXTRA_CFLAGS := -DA665_PART2 -DA665_PART3

.DEFAULT: all

.PHONY: all clean $(SUBDIRS)

all : $(SUBDIRS)

clean : $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ -f Makefile.mk $(MAKECMDGOALS)	


