## ###################################################################
##     e200z4_branch_displacement_e10385.tcl:
##        A script for detecting the e200z e10385 errata. 
##
##     Copyright (c) 2016 - 2016 Freescale Semiconductor, Inc.
##     Freescale is a wholly owned subsidiary of NXP B.V
##     
##     All rights reserved.
##
##     Redistribution and use in source and binary forms, with or without modification,
##     are permitted provided that the following conditions are met:
##
##     o Redistributions of source code must retain the above copyright notice, this list
##       of conditions and the following disclaimer.
##
##     o Redistributions in binary form must reproduce the above copyright notice, this
##       list of conditions and the following disclaimer in the documentation and/or
##       other materials provided with the distribution.
##
##     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
##       contributors may be used to endorse or promote products derived from this
##       software without specific prior written permission.
##
##     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
##     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
##     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
##     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
##     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
##     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
##     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
##     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
##     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
##     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
##
##     http:                 www.nxp.com
##
##     Revisions:
##     - rev. 1.0 (2016-Aug-08)
##         Initial version.
##
##
## ###################################################################
set segments {}
# f_exec        Boolean indicating segment is executable
# vaddr         Virtual address of segment
# paddr         Physical address of segment
# file_size     Segment byte size as occupied in Elf32 file
# data          List of values found in the segment, values are passed as unsigned integers

set PF_X        1
set verbose 0

proc unsigned {bits args} {
    foreach varname $args {
        upvar 1 $varname var
        set var [ expr {$var}  & ((1 << $bits) - 1)]
    }
}

proc read_segments {chan} {
    seek $chan 28
    binary scan [read $chan 4] I phoff
    unsigned 32 phoff

    seek $chan 42
    binary scan [read $chan 4] SS phentsize phnum
    unsigned 16 phentsize phnum

    set next $phoff
    for {set i 0} {$i < $phnum} {incr i} {
        set seg {}
        seek $chan $next
        binary scan [read $chan $phentsize] IIIIIIII ptype poffset vaddr paddr fsize msize flags align
        set next [tell $chan]
        unsigned 32 ptype poffset vaddr paddr fsize msize flags align
        dict set seg f_exec    [ expr $flags & $::PF_X ]
        dict set seg file_size $fsize
        dict set seg vaddr $vaddr
        dict set seg paddr $paddr
        seek $chan $poffset
        set chunk [list]
        set chunksize 1
        set bits 8
        switch $bits {
            8  {set fmt c}
            16 {set fmt S}
            32 {set fmt I}
            default { set fmt c}
        }
        for {set j 0} {$j < $fsize} {incr j $chunksize } {
            binary scan [read $chan $chunksize] $fmt val
            unsigned $bits val
            lappend chunk $val
        }
        dict set seg data $chunk
        lappend ::segments $seg
    }
    #if {$::verbose} {puts -nonewline stderr "seg table : "; puts stderr $::segments }
}

proc e200_checker {filename {pattern ""}} {

    set chan [open $filename rb]
    read $chan 1
    if {[read $chan 3] ne "ELF"} {
        puts "unsupported format"
        close $chan
	return 1
    }
    read_segments $chan
    close $chan

    set rc 0

    set instr(e_b)  [list [expr 0x78] [expr 0x79]]
    set instr(e_bc) [expr 0x7a]
    set instr(se_x) [list [expr 0] [expr 2] [expr 4] [expr 6] [expr 8] [expr 0xa] [expr 0xb] [expr 0xc] [expr 0xd] [expr 0xe]] 

    foreach seg $::segments {
        if { [dict get $seg f_exec] == 0 } { continue }
        set size  [dict get $seg file_size ] ; # assume nothing will be in vaddr + [file_size..mem_size[
        if { $size == 0 } { continue }
        set vaddr [dict get $seg vaddr ]
        set data  [dict get $seg data ]
        puts "Checking $filename -- Processing segment from 0x[format %x $vaddr] .. 0x[format %x [expr { $vaddr + $size }]]"
        if { [expr { $vaddr % 16384 }] } {set off [expr { ( ( $vaddr + 0x4000 ) & ~ 0x3FFF ) - $vaddr } ] } else {set off $vaddr} 
        for {set off [expr { $off + 2 } ] } {$off < $size} {incr off 16384} {
            if {$::verbose} {puts stderr "\tChecking [format %x $off] 0x[format %x [expr { $vaddr + $off }]]"}
            if { -1 != [lsearch -exact -integer $instr(e_b) [lindex $data $off]]} {
                foreach {b1 b2 b3} [lrange $data $off+1 $off+3] {
                    set displ [expr {($b1 << 16) + ($b2 << 8) + $b3}]
                    if {[expr {$displ & 0x3fff}] == 0x3fff && $off > 4 && -1 == [lsearch -exact -integer $instr(se_x) [expr { ( 0x00F0 & [lindex $data $off-4] ) >> 4 }]]} {
                        puts "FAIL - illegal branch e_b at 0x[format %x [expr { $vaddr + $off }]]" 
			set rc 1
                    }
                    break
                }    
            }
            if {[lindex $data $off] == $instr(e_bc) } {
                foreach {b1 b2} [lrange $data $off+2 $off+3] {
                    set displ [expr {($b1 << 8) + $b2}]
                    if {[expr {$displ & 0x3fff}] == 0x3fff && $off > 4 && -1 == [lsearch -exact -integer $instr(se_x) [expr { ( 0x00F0 & [lindex $data $off-4] ) >> 4 }]]} {
                        puts " FAIL - illegal branch e_bc at 0x[format %x [expr { $vaddr + $off }]]" 
			set rc 1
                    }
                    break
                }    
            }
        }
    }
    return $rc
}

set elffile {}
array set mem_width {}

# Main program
#
set version 0009 
if {[expr  $tcl_version] < 8.5 } {
    puts "Requires tcl 8.5 or higher (current: $tcl_version)"
    exit 1
}
if {$argc >= 1} {
    for {set i 0} {$i < $argc} {incr i} {
        set arg [lindex $argv $i]
        if {[string first "-verbose" $arg] == 0} {
            set verbose 1
        } elseif {[string first "-version" $arg] == 0} {
            puts "[info script] version:$version"
            exit 0
        } elseif {[string first "-" $arg] == 0} {
            puts "Unknown argument: $arg"
            exit 1
        } elseif {$elffile == {}} {
            set elffile $arg
        } else {
            puts "Illegal extra argument: $arg"
            exit 1
        }
    }
    if {[file exists $elffile] != 0} {
      set rc [e200_checker $elffile]
	    if {$rc == 0} {puts "PASS"}
	      exit $rc
    } else {
	    puts "$elffile not found"
	    exit 1
    }
} else {
    puts "Usage: [info script] \[-verbose\] \[-version\] elffile"
    exit 1
}

