source [file dirname [info script]]/../../_tcl_utils/genericProcs.tcl
source [file dirname [info script]]/../../_tcl_utils/class_TermColor.tcl
#---------------------------------------------------------------------------------------------------------------------------------------------------------
set termColor [TermColor new {						\
	{ NORMAL			white	1		black 	0 } \
	{ TITLE				yellow	1		blue 	1 } \
	{ GREEN				green	1		black 	0 } \
	{ CODE				yellow	1		blue	0 } \
	{ VALUE				yellow	1		black	0 } \
	{ WARNING			yellow	1		black 	0 } \
	{ ZEROSIZE			black 	0		gray	0 } \
	{ ERROR				red		1		black 	0 } \
	{ OK				green	1		black 	0 } \
	{ UNKNOWN			gray	0		black 	0 } \
}]
#---------------------------------------------------------------------------------------------------------------------------------------------------------
set fh [open [file dirname [info script]]/../data/codes.csv r]
while { [gets $fh line] >= 0 } {
   set line [string trim $line]
   lassign [split $line \;] text code
   set code 0x[string toupper [string range $code 2 end]]
   if { [info exists listOfCodes($code)] } {
      puts "ERR : '$code' already present !"
      exit 0
   } else {
      set listOfCodes($code) $text
   }
}
close $fh

set previousRange ""
foreach code [lsort -integer [array names listOfCodes]]  {
   if { $previousRange ne "" && [string index $code 5] ne $previousRange } {
      puts -nonewline "[string repeat - 80]\[  -0x00"
      $termColor putsColor ${previousRange} CODE 1
      puts -nonewline "00000] - \[0x00"
      $termColor putsColor [string index $code 5] CODE 1
      puts "00000-  ]"
   }
   $termColor putsColor "$code" CODE 1
   puts -nonewline " -> "
   $termColor putsColor "$listOfCodes($code)" VALUE
   set previousRange [string index $code 5]
}
#---------------------------------------------------------------------------------------------------------------------------------------------------------
