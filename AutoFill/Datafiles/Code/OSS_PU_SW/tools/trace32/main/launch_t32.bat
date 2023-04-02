@echo off
set t32mppc_executable="C:\T32\bin\windows64\t32mppc.exe"
if not exist %t32mppc_executable% set t32mppc_executable="C:\T32\bin\windows\t32mppc.exe"
echo Which probe/link to use?
echo ---------------------------
echo 1. BOARD-CPMB-006 - PROBE-E22030042912
echo 2. BOARD-CPMB-008 - PROBE-E22030042913
echo 3. BOARD-CPB-003 - PROBE-E20010037185
echo 4. BOARD-CPB-010 - PROBE-E16070029642
echo 5. USB (/!\ do not use)
set /p number="Select a number. "
if %number%==1 (
    echo BOARD-CPMB-006 - PROBE-E22030042912 selected.
    start "" %t32mppc_executable% -c "R:/tools/trace32/probe_config/config - BOARD-CPMB-006 - PROBE-E22030042912.t32" -s R:/tools/trace32/auxiliary/startup.cmm
)
if %number%==2 (
    echo BOARD-CPMB-008 - PROBE-E22030042913 selected.
    start "" %t32mppc_executable% -c "R:/tools/trace32/probe_config/config - BOARD-CPMB-008 - PROBE-E22030042913.t32" -s R:/tools/trace32/auxiliary/startup.cmm
)
if %number%==3 (
    echo BOARD-CPB-003 - PROBE-E20010037185 selected.
    start "" %t32mppc_executable% -c "R:/tools/trace32/probe_config/config - BOARD-CPB-003 - PROBE-E20010037185.t32" -s R:/tools/trace32/auxiliary/startup.cmm
)
if %number%==4 (
    echo BOARD-CPB-010 - PROBE-E16070029642 selected.
    start "" %t32mppc_executable% -c "R:/tools/trace32/probe_config/config - BOARD-CPB-010 - PROBE-E16070029642.t32" -s R:/tools/trace32/auxiliary/startup.cmm
)
if %number%==5 (
    echo USB selected.
    start "" %t32mppc_executable% -c "R:/tools/trace32/probe_config/config - USB.t32" -s R:/tools/trace32/auxiliary/startup.cmm
)
