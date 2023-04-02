BASE_DIR := ../..

include $(BASE_DIR)/Makefile/MakefileVar.mk

SCI := BOOT
GEN_DIR := $(BASE_DIR)/BOOT_gen/$(SCI)
CSC_DIRS := BOOT_ChooseAndLoadSW_CLSW \
			BOOT_Common \
			BOOT_ManageFailuresAndLaunchSW_MFLSW \
			BOOT_ManageInterrupts_MI \
			BOOT_TestAndConfigureAdditionalHW_TCAHW \
			BOOT_ConfigureBasicHW_CBHW

LIBBSP_GEN_DIR := $(BASE_DIR)/LIBBSP_gen
LIBUTI_GEN_DIR := $(BASE_DIR)/LIBUTI_gen

SNT_SPI := ../createSPI.py

CONF_SPI := spi.ini
CONF_DLD := $(SCI).dld

export EXTRA_CFLAGS := -DA665_PART2 -DA665_PART3

CSC_A := $(foreach csd, $(CSC_DIRS), $(GEN_DIR)/$(csd)/lib/$(csd).a)

LD_A := $(LIBBSP_GEN_DIR)/LIBBSP_CMN/lib/LIBBSP_CMN.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_DISC/lib/LIBBSP_DISC.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_ECCMEM/lib/LIBBSP_ECCMEM.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_ELBC/lib/LIBBSP_ELBC.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_ENVM/lib/LIBBSP_ENVM.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_FLOAT/lib/LIBBSP_FLOAT.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_FNOR/lib/LIBBSP_FNOR.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_GPIO/lib/LIBBSP_GPIO.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_I2C/lib/LIBBSP_I2C.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_MRAM/lib/LIBBSP_MRAM.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_PLDCMP/lib/LIBBSP_PLDCMP.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_PLDMEG/lib/LIBBSP_PLDMEG.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_RMM/lib/LIBBSP_RMM.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_SHM/lib/LIBBSP_SHM.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_SPI/lib/LIBBSP_SPI.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_WD/lib/LIBBSP_WD.a \
		$(LIBUTI_GEN_DIR)/AES/lib/AES.a \
		$(LIBUTI_GEN_DIR)/ARINC_665/lib/ARINC_665.a \
		$(LIBUTI_GEN_DIR)/COMMON/lib/COMMON.a \
		$(LIBUTI_GEN_DIR)/CRC/lib/CRC.a \
		$(LIBUTI_GEN_DIR)/SHA/lib/SHA.a \
		$(LIBUTI_GEN_DIR)/SIF/lib/SIF.a \
		$(LIBUTI_GEN_DIR)/MEM/lib/MEM.a \
		$(BASE_DIR)/QACG_StdLib_source_gen/lib/StdLib.a


OUT_EXE := $(GEN_DIR)/$(SCI).elf
OUT_MAP := $(GEN_DIR)/$(SCI).map
OUT_LUP := $(GEN_DIR)/$(SCI).lup
OUT_SPI := $(GEN_DIR)/$(SCI).spi
OUT_S37 := $(GEN_DIR)/$(SCI).s37

all: $(OUT_LUP) $(OUT_SPI)

clean:
	@$(foreach csd, $(CSC_DIRS), ("$(MAKE)" -C $(csd) -I $(BASE_DIR) -f ../SubMakefile.mk clean);)
	rm -rf $(OUT_EXE)
	rm -rf $(OUT_MAP)
	rm -rf $(OUT_LUP)
	rm -rf $(OUT_SPI)
	rm -rf $(OUT_S37)

$(CSC_DIRS):
	@$(MAKE) -C $@ -I $(BASE_DIR) -f ../SubMakefile.mk all

$(OUT_EXE): $(CONF_DLD) $(CSC_DIRS)
	@echo Creation of the elf $@
	$(LD) $(LDFLAGS) $(CSC_A) $(LD_A) -o$@ "$<" -@O="$(OUT_MAP)"

$(OUT_S37): $(OUT_EXE)
	@echo Creation of the Motorola S-Record $@
	@$(DUMP) $(DD_ARG) -o $@ $^

$(OUT_LUP): $(OUT_S37)
	@echo Creation of the LUP File $@
	@$(LUP) $(LUP_ARG) $^ $@

$(OUT_SPI): $(CONF_SPI)
	@echo Creation of the SPI Config File $@
	@py -3 $(SNT_SPI) -o $@ $^

.PHONY: all clean $(CSC_DIRS)
