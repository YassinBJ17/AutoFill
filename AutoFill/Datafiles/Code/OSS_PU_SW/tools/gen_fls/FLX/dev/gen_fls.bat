REM FLS generator command Line
R:\tools\gen_fls\FLX\dev\FLX.exe -cmd -elf -dl OLL -i R:\tools\gen_fls\FLX\dev\oss_pu.txt -sfi SFIccT0179T0046 -n OSS_CU -o R:\_build_out\gen\fls\oss_pu\
R:\tools\gen_fls\FLX\dev\FLX.exe -cmd -bin 0x20000000 -dl OLL -i R:\tools\gen_fls\FLX\dev\mram_uod_icdl.txt -sfi SFIccT0177T0460 -n MRAM_APP -o R:\_build_out\gen\fls\mram\uod_icdl\
R:\tools\gen_fls\FLX\dev\FLX.exe -cmd -bin 0x20000000 -dl OLL -i R:\tools\gen_fls\FLX\dev\mram_uod_rs.txt -sfi SFIccT0177T0461 -n MRAM_APP -o R:\_build_out\gen\fls\mram\uod_rs\
R:\tools\gen_fls\FLX\dev\FLX.exe -cmd -bin 0x01200000 -dl OLL -i R:\tools\gen_fls\FLX\dev\oss_conf_g3.txt -sfi SFIccT0181T3406 -n OSS_CONF -o R:\_build_out\gen\fls\oss_conf\g3\
R:\tools\gen_fls\FLX\dev\FLX.exe -cmd -bin 0x01200000 -dl OLL -i R:\tools\gen_fls\FLX\dev\oss_conf_g4.txt -sfi SFIccT0181T4406 -n OSS_CONF -o R:\_build_out\gen\fls\oss_conf\g4\
