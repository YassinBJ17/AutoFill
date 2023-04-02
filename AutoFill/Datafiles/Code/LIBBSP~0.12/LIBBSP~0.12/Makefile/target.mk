.DEFAULT : elf
clean : clean_elf clean_lup
#all : lup elf
clean_scade : 
	cleanGen.bat	
build_scade : scade_gen
	buildGen.bat	
scade_gen: clean_scade
	KCG_ScadeGeneration.bat
.PHONY : build_scade clean_elf clean_all clean_all build_scade lup elf clean 