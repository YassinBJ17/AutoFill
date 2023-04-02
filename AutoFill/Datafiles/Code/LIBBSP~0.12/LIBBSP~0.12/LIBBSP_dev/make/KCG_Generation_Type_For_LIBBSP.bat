echo off

REM ----- CREATE CONFIG FILE

set XSCADE_LIST=^
..\..\LIBBSP_api\LIBBSP_TYPE\LIBBSP_types_consts.xscade ^
..\LIBBSP_TYPE\DummyForGeneration.xscade

set GENERATION_OPTIONS=^
-target_dir "..\..\LIBBSP_api\LIBBSP_TYPE\inc_gen" -target C -name_length 128 -significance_length 127 -user_config "user_macros_libbsp.h" -probes -separate_io_all


set ROOT=-root DummyForGeneration


echo %GENERATION_OPTIONS%> ..\..\LIBBSP_api\LIBBSP_TYPE\config.txt
echo %ROOT%>> ..\..\LIBBSP_api\LIBBSP_TYPE\config.txt
for %%S in (%XSCADE_LIST%) do echo "%%S">> ..\..\LIBBSP_api\LIBBSP_TYPE\config.txt

"C:\Program Files\ANSYS Inc\v194\SCADE\SCADE\bin\kcg66.exe"  -config "..\..\LIBBSP_api\LIBBSP_TYPE\config.txt"

pause