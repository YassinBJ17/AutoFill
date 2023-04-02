@echo OFF

tclsh %~dp0auxiliary\%~n0.tcl %~1 %~2
if ERRORLEVEL 1 GOTO TRY_TCLSH86
goto END_OF_SCRIPT

:TRY_TCLSH86
echo Now trying tclsh86.exe...
tclsh86 %~dp0auxiliary\%~n0.tcl %~1 %~2

:END_OF_SCRIPT
