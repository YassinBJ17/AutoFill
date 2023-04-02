@echo off
if %CD:~0,2% == R: GOTO END_OF_SCRIPT
if exist R: subst R: /D > nul
subst R: "%~dp0/../.."

:END_OF_SCRIPT
subst
R:
