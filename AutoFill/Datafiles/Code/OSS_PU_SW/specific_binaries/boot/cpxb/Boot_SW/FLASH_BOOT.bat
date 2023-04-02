@echo off
SET CUR_DIR=%~dp0

set t32mppc_executable="C:\T32\bin\windows64\t32mppc.exe"
if not exist %t32mppc_executable% set t32mppc_executable="C:\T32\bin\windows\t32mppc.exe"

echo USB selected.
CALL %t32mppc_executable% -c %CUR_DIR%\5_Tools\confT32\config.t32 -s %CUR_DIR%\5_Tools\_LAUTERBACH\Load_arbo.cmm