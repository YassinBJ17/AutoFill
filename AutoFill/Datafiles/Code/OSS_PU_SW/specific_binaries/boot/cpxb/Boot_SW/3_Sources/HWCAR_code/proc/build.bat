@ECHO OFF
CLS

REM Set input variables and environment
ECHO ---------------------------------------
ECHO Setting input variables and environment
ECHO ---------------------------------------

REM Set mandatory variables for top makefile location, build options and s-record tools
SET EFS_HWCAR_PROC_DIR=%~dp0
SET EFS_BUILD_OPT_DIR=%EFS_HWCAR_PROC_DIR%\..\..\..\4_Build_Options
SET SREC_TOOLS="%EFS_HWCAR_PROC_DIR%\..\..\..\5_Tools"
SET CCC_TOOL="C:\App\SYNCHRONe\CCC\4.0"

REM Errata processor E010385 checker
SET E010385_ERRATA_E2004_TOOL="%EFS_HWCAR_PROC_DIR%\..\..\..\5_Tools\Errata processor\PA_e200z425-branch-checker_Win32_b0009\bin"

SET WRD_UTILS_PATH=C:\WindRiver\utilities-1.0\x86-win32\bin

REM Check utilities are available and add them if and only if they are not already in the PATH
whoami --help > NUL 2> NUL 
IF ERRORLEVEL 1 SET "PATH=%WRD_UTILS_PATH%;%PATH%"

@ECHO OFF

REM Clean all generated files
ECHO -----------------------------------
ECHO   Cleaning of all generated files
ECHO -----------------------------------
make -r -R clean

REM Generate all required objects
ECHO -----------------------------------
ECHO  Generation of all required objects
ECHO -----------------------------------
make -r -R generate
make -r -R all


ECHO -----------------------------------
ECHO  Generation of ABS Files
ECHO -----------------------------------
make -r -R load_ccc

ECHO -----------------------------------
ECHO              THE END
ECHO -----------------------------------

