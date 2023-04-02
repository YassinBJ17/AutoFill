source [file dirname [info script]]/../../_tcl_utils/genericProcs.tcl
source [file dirname [info script]]/../../_tcl_utils/class_TermColor.tcl
source [file dirname [info script]]/../../_tcl_utils/class_Elf.tcl
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
set termColor [TermColor new {							\
	{ NORMAL				white	0		black 	0 } \
	{ WARNING				yellow	1		black 	0 } \
	{ ZEROSIZE				black 	0		gray	0 } \
	{ ERROR					red		1		black 	0 } \
	{ OK					green	1		black 	0 } \
	{ UNKNOWN				gray	0		black 	0 } \
	{ ELF_DATA				blue	1		black	0 } \
	{ ELF_CODE				green	1		black 	0 } \
	{ ELF_KEYWORD_TEXT		white	1		green	0 } \
	{ ELF_KEYWORD_BSS		white	1		purple	0 } \
	{ ELF_KEYWORD_RODATA	black	0		yellow	0 } \
	{ ELF_KEYWORD_DATA		white	1		blue	1 } \
	{ ELF_KEYWORD_DEBUG		blue	0		black	0 } \
	{ ELF_SPARE				red		0		black	0 } \
}]
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
set elfFileName [lindex $::argv 0]
if { ![file exists $elfFileName] } {
	$termColor putsColor "***ERR" ERROR 1
	puts " : Cannot find file '$elfFileName' !"
	puts "           -> Please check parameter."
	puts "           -> Aborted."
	exit 0
} elseif { [lsearch -exact {StartAddr Section ID} [lindex $::argv 1]] == -1 } {
	$termColor putsColor "***ERR" ERROR 1
	puts " : Unknown sort mode '[lindex $::argv 1]' !"
	puts "           -> It should be one of these : StartAddr Section ID"
	puts "           -> Please check parameter."
	puts "           -> Aborted."
	exit 0
} else {
	set elfObj [Elf new $elfFileName]
	$elfObj display [lindex $::argv 1]
}
return 0
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
