C55 E200Z4 BRANCH DISPLACEMENT ERRATUM 10385 CHECKER

Summary:
========
branch_displacement_erratum_10385_checker: Check for E200Z4 BRANCH DISPLACEMENT defect. 

This program is a modified version of the GNU objdump program for
e200z4. The program has been modified to check for the conditions
which may cause the e200z4 branch displacement issue. Refer to 
external documentation for details of this issue, but generally,
a 32-bit instruction misaligned on a 16K memory boundary followed
by a 32-bit branch instruction whose lower 14-bits of the branch
target is 0x3FFE will cause a problem if the instructions are 
dual issued.

The program is a read-only tool. The program does not change
the input files in any way. This applies whether the tool is
reading ELF, hex, or srec type input files.

The distribution can be uncompressed in any user directory. After
uncompressing, the user should use a suitable command line shell
console to run the program. The user should set their PATH environment
variable to include the 'bin' directory in this distribution and
the path to 'bin' should precede any other executable paths.

Linux example:
export PATH=<userdir>/bin:$PATH

Windows example:
set PATH=C:<userdir>/bin;%PATH%

The command line is:

%>branch_displacement_erratum_10385_checker <executable ELF file> | <SREC file> [optional_flags]
where optional_flags are:
--version, print version of program and exit
--ignore-address <address_value>, ignore violation detected at <address_value>

The program will scan ELF file segments or SREC file segments and detect the 
sequence of instructions that may trigger the fault indicated by the errata.

A TCL script is provided as a secondary means of verifying an ELF file.
The TCL scripts is a read-only tool. It does not modify the ELF file in
any way. See below for usage details of the TCL script.


Release History:
================
Build 0009, Aug 08, 2016
------------------------
- TCL script to check for errata in _ELF files only_ is added to
the distribution.

Notes:
To further prove the veracity of the 'branch_displacement_erratum_10385_checker' 
native executable tool, the distribution now includes an independently
developed TCL script which checks for the errata conditions in ELF files.

TCL (or Tool Command Language) is a mature and highly regarded scripting
language in the software development community. An internet search will 
yield a multitude of information for downloading and installing TCL on
a local host.

The 'e200z4_branch_displacement_e10385.tcl' program is provided as source. 

'tclsh 8.5' or higher is required to execute the script.

Usage:
'tclsh' should be in your PATH.

>tclsh path/to/e200z4_branch_displacement_e10385.tcl <elf_file>

The program will detect and report errata violations in the <elf_file>
to the console. If any failures are detected, the script exits with
a non-zero value to the system, and a distinctive "FAIL" string to the
console. If no failures are detected, the script exits with 0 to the
system and a distinctive "PASS" string to the console output.

Options:
The following flags are optional to the TCL script:

-version, print the version of the TCL script and exit with 0
-verbose, verbose output, noting each 16KB boundary that is checked.

Note that the native executable version of 'branch_displacement_erratum_10395_checker'
and the TCL script do not produce the exact same console output (the native
version has disassembly capabilities).

  
Build 0008, July 18, 2016
-------------------------
- Add support for Intel Hex format (HEX)

Notes:
The program now supports Intel Hex format files. The
constraints for HEX format are identical to those of
SREC format. File formats are automatically detected,
and if the file format is HEX or SREC, all sections are
checked for possible violations. For ELF format, only
executable sections are checked for possible violations.


Build 0007, July 8, 2016
------------------------

- Add support for SREC files.
- Add new flag, --ignore-address <address_value>
- Changes in output report format.

Notes:

The program now supports SREC (aka S19) files. The program automatically
distinguishes between SREC and ELF files. Scanning SREC files is slightly
different than ELF files. While ELF files normally will have enough context
to identify executable code segments, SREC files do not. Therefore, if an
SREC file is used as input, _all_ information in the file is scanned for a
possible violation. That is, there is no distinction between code and data
segments for SREC input files, therefore all segments are scanned for a
possible violation.

Recognizing that data segments in SREC files could trigger a false positive
report due to data patterns, a new option flag is provided to ignore such false 
positive reports.  It is the user's responsibility to determine whether a 
positive detection of a issue can be safely ignored because it was triggered 
by data, not executable code.

--ignore-address <address_value> will ignore the positive detection of
the branch errata 10385 issue. This flag can be issued multiple times
for multiple addresses. The address is the address of the first detected
instruction (even if data is disassembled as an instruction).
The program will report as "PASSED: ..." if all violations are ignored and
return 0 to the shell. 


Build 0006, June 27 2016
------------------------

- Updated pdf presentation with section constraint info.

Build 0005, June 24 2016
------------------------

- Updated pdf presentation

Build 0004, June 23 2016
------------------------

- Modified output status of the program to return '1' to the system if any
  violations are detected, otherwise the program returns '0' status if no
  violations are detected.

- Inserted "FAILED: " text in the last line of output if violations are detected.
  Inserted "PASSED: " text in the last line of output if no violations are detected.

Build 0003, June 10 2016
------------------------

- Initial release.


