BASE_DIR := ..

include $(BASE_DIR)/Makefile/MakefileVar.mk

SCI_ELBCBOOT := ELBCBOOT
SCI_RAMBOOT := RAMBOOT
SCI_BOOT := BOOT

SCI := $(SCI_BOOT) $(SCI_RAMBOOT) $(SCI_ELBCBOOT)
GEN_DIR := $(BASE_DIR)/BOOT_gen

SNT_BIN := createSHA256.py
SNT_MEM := createMEM.py

CONF_MEM := boot.ini

SNT_ELBCBOOT_SREC_ARG := -a 32 --header="SN ELBCBOOT" -s 0xF000 -e 0xFFFFFFFC
SNT_RAMBOOT_SREC_ARG := -a 32 --header="SN RAMBOOT" -s 0x8000 -e 0x00002010

SNT_ELBCBOOT_MEM_ARG := -a 0x3C00
SNT_RAMBOOT_MEM_ARG := -a 0x2000

OUT_RAMBOOT_BIN := $(GEN_DIR)/$(SCI_RAMBOOT).bin
OUT_RAMBOOT_SPI := $(GEN_DIR)/$(SCI_RAMBOOT).spi

OUT_BOOT_BIN := $(GEN_DIR)/$(SCI_BOOT).bin
OUT_BOOT_SPI := $(GEN_DIR)/$(SCI_BOOT).spi

OUT_PLD_MEM := $(GEN_DIR)/compagnon_envm.mem

IN_ELBCBOOT_LUP := $(GEN_DIR)/$(SCI_ELBCBOOT)/$(SCI_ELBCBOOT).lup
IN_RAMBOOT_LUP := $(GEN_DIR)/$(SCI_RAMBOOT)/$(SCI_RAMBOOT).lup
IN_RAMBOOT_SPI := $(GEN_DIR)/$(SCI_RAMBOOT)/$(SCI_RAMBOOT).spi
IN_BOOT_LUP := $(GEN_DIR)/$(SCI_BOOT)/$(SCI_BOOT).lup
IN_BOOT_SPI := $(GEN_DIR)/$(SCI_BOOT)/$(SCI_BOOT).spi

all: bclean $(OUT_BOOT_BIN) $(OUT_RAMBOOT_BIN) $(OUT_BOOT_SPI) $(OUT_RAMBOOT_SPI) $(OUT_PLD_MEM)

bclean:
	rm -rf $(OUT_RAMBOOT_BIN)
	rm -rf $(OUT_RAMBOOT_SPI)
	rm -rf $(OUT_BOOT_BIN)
	rm -rf $(OUT_BOOT_SPI)
	rm -rf $(OUT_PLD_MEM)

clean: bclean
	@$(MAKE) -C $(SCI_ELBCBOOT) -f Makefile.mk clean
	@$(MAKE) -C $(SCI_RAMBOOT) -f Makefile.mk clean
	@$(MAKE) -C $(SCI_BOOT) -f Makefile.mk clean

$(SCI):
	@$(MAKE) -C $@ -f Makefile.mk all

$(IN_ELBCBOOT_LUP): $(SCI_ELBCBOOT)

$(IN_RAMBOOT_LUP) $(IN_RAMBOOT_SPI): $(SCI_RAMBOOT)

$(IN_BOOT_LUP) $(IN_BOOT_SPI): $(SCI_BOOT)

$(OUT_RAMBOOT_BIN): $(IN_RAMBOOT_LUP) $(IN_BOOT_LUP)
	@echo Creation of the $(SCI_RAMBOOT) BIN File $@
	@py -3 $(SNT_BIN) -o $@ -i $< $^

$(OUT_RAMBOOT_SPI): $(IN_RAMBOOT_SPI)
	@cp -vf $< $@

$(OUT_BOOT_BIN): $(IN_BOOT_LUP)
	@cp -vf $< $@

$(OUT_BOOT_SPI): $(IN_BOOT_SPI)
	@cp -vf $< $@

$(OUT_PLD_MEM): $(CONF_MEM) $(OUT_RAMBOOT_BIN) $(IN_ELBCBOOT_LUP)
	@echo Creation of the NVM memory file $@
	@py -3 $(SNT_MEM) -o $@ $<

.PHONY: all clean $(SCI)
