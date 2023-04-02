#========================================================================================================================================================================================================
oo::class create TermColor {
#------------------------------------------------------------------------------ M E M B E R    V A R I A B L E S ----------------------------------------------------------------------------------------
	variable m_colorAliases
	variable m_customColors
	variable m_availableColors
	variable m_OS
	variable m_consoleHandle
	variable m_colorMap
	variable m_defaultColors
#----------------------------------------------------------------------------------- C O N S T R U C T O R ----------------------------------------------------------------------------------------------
	constructor { listOfColorConfigs } {
		my Init
	
		foreach colorConfig $listOfColorConfigs {
			lassign $colorConfig colorAlias fgColor fgOptParams bgColor bgOptParams 
			my AddCustomColorAliasFgAndBg $colorAlias $fgColor $fgOptParams $bgColor $bgOptParams
		}
	}
#-------------------------------------------------------------------------------- P U B L I C    M E T H O D S ------------------------------------------------------------------------------------------
	method putsColor { str colorAlias { dontAddANewLine 0 } } {
		return [my PutsColor $str $colorAlias $dontAddANewLine]
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method putsColorBg { str bgColor { dontAddANewLine 1 } } {
		return [my PutsColorBg $str $bgColor $dontAddANewLine]
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method getFullFgOrBgColor { desiredColor isBright fg_Or_bg } {
		return [my GetFullFgOrBgColor $desiredColor $isBright $fg_Or_bg]
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method getDefaultColor { } {
		return [my GetDefaultColor]
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method resetToDefaultColor { } {	
		return [my ResetToDefaultColor]
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method addCustomColorAliasFgOrBg { fg_Or_bg colorAlias color isBright } { 
		return [my AddCustomColorAliasFgOrBg $fg_Or_bg $colorAlias $color $isBright]
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method removeAllAliasedColors	 { } {
		return [my RemoveAllAliasedColors]
	}
#-------------------------------------------------------------------------------- P R I V A T E    M E T H O D S ----------------------------------------------------------------------------------------
	method PutsColor { str colorAlias dontAddANewLine } {
		if { [lsearch -exact [array names m_customColors] $colorAlias] == -1 } {
			puts "::TermColor::PutsColor : ERROR : Cannot find '$colorAlias' aliased color ! Aborted."
			return 1
		}
		flush stdout
		my SetForegroundColor $m_customColors($colorAlias)
		puts -nonewline $str
		flush stdout
		my ResetToDefaultColor
		if { $dontAddANewLine } {
			puts -nonewline ""
		} else {
			puts ""
		}
		flush stdout
		return 0
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	method GetFullFgOrBgColor { desiredColor isBright fg_Or_bg } {
		if { $m_OS ne "win32" } {
			error "getFullFgOrBgColor is only available in win 32 environments !"
		} else {
			set colors { blue  green red purple yellow gray white }
			set conf {}
			foreach col $colors {
				lappend conf -${fg_Or_bg}$col
				if { $desiredColor == $col } {
						lappend conf true
				} else {
						lappend conf false
				}
			}
			lappend conf -${fg_Or_bg}bright $isBright
			return $conf
		}
	}	
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method ResetToDefaultColor { } {
		switch -exact $m_OS {
			linux {
				my SetForegroundColor $m_defaultColors
			}
			win32 {
				eval "::twapi::set_console_default_attr \{ $m_consoleHandle \} -fgblue false -fggreen false -fgred false -fgpurple false -fgyellow false -fggray false -fgwhite false -fgbright false\
				                                                                                -bgblue false -bggreen false -bgred false -bgpurple false -bgyellow false -bggray false -bgwhite false -bgbright false"
				my SetForegroundColor $m_defaultColors
			}
			default {
				::Logger::addLog ERR_LOG "Unsupported OS ($m_OS) ! Aborted."
				return 1
			}
		}
		return 0
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method GetDefaultColor { } {
		return $m_defaultColors
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method AddCustomColorAliasFgOrBg { fg_Or_bg colorAlias color isBright } { 
		if { [my CheckAliasedColorExistence $colorAlias] } {
			::Logger::addLog ERR_LOG "Cannot add '$colorAlias' twice ! Aborted."
			return 1
		}
		if { ![my IsThisColorAvailable $color] } {
			::Logger::addLog ERR_LOG "This color '$color' is not available ! Aborted."
			return 2
		}
		set m_customColors($colorAlias) [my GetFullFgOrBgColor $color $isBright $fg_Or_bg]
		return 0
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method AddCustomColorAliasFgAndBg { colorAlias fgColor fgOptParams bgColor bgOptParams } { 	
		if { [my CheckAliasedColorExistence $colorAlias] } {
			::Logger::addLog ERR_LOG "Cannot add '$colorAlias' twice ! Aborted."
			return 1
		}	
		if { ![my IsThisColorAvailable $fgColor] } {
			::Logger::addLog ERR_LOG "This fg color '$fgColor' is not available ! Aborted."
			return 2
		}
		if { ![my IsThisColorAvailable $bgColor] } {
			::Logger::addLog ERR_LOG "This bg color '$bgColor' is not available ! Aborted."
			return 3
		}		
		switch -exact $m_OS {
			linux {
				# fgOptParams : is fg normal / bold / light / blink / invert   :  # TODO : test param correctness and test them !
				set m_customColors($colorAlias) [my Int_+ $bgColor $fgColor $fgOptParams]  ; # TODO : isBright useful ? Check with upper case color 1st letters 
																												   ; # TODO : manage bold / blink / ...
			}
			win32 {
				# fgOptParams : is fg color bright ?
				# bgOptParams : is bg color bright ?
				set m_customColors($colorAlias) [concat [my GetFullFgOrBgColor $fgColor $fgOptParams fg] [my GetFullFgOrBgColor $bgColor $bgOptParams bg]]
			}
			default {
				::Logger::addLog ERR_LOG "Unsupported OS ($m_OS) ! Aborted."
				return 3
			}
		}
		return 0
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method RemoveAllAliasedColors { } {
		array unset m_customColors
		set m_customColors(default) $m_defaultColors
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method Init { } {
		::GenericProcs::checkPackageDependencies { ::GenericProcs } ; # Cannot require Logger, as ::Logger requires ::TKW::TermColor... ::TKW::TermColor uses ::Logger though, but not during initialization steps : trouble can occur @ execution if ::Logger is not sourced afterwords !
		set m_OS [::GenericProcs::getCurrentOS] 	; # linux / win32 / ...
		switch -exact $m_OS {
			win32 {
				package require twapi
				if { [catch {
					set m_consoleHandle [::twapi::get_console_handle stdout] 
				} errorMsg] } {
					set errorLog "*** ERROR : Cannot allocate console handle in twapi ($errorMsg) !"
					append  errorLog "Please make sure this application features a console."
					append  errorLog "Aborted."
					::Logger::addLog ERR_LOG $errorLog
					tk_messageBox -title Error -message $errorLog
				}
				
				set m_defaultColors [lindex [::twapi::get_console_screen_buffer_info $m_consoleHandle -textattr] 1]	
				set m_availableColors {black blue green red purple yellow gray white}
			}
			linux {
				set m_colorMap {
					normal  0 bold    1 \
					light   2 blink   5 \
					invert  7 \
					black  30 red    31 \
					green  32 yellow 33 \
					blue   34 purple 35 \
					cyan   36 white  37 \
					Black  40 Red    41 \
					Green  42 Yellow 43 \
					Blue   44 Purple 45 \
					Cyan   46 White  47 \
				}
				set m_defaultColors [my Int_+ normal]
				set m_availableColors {black red green yellow blue purple cyan white \
				                                        Black Red Green Yellow Blue Purple Cyan White }  ; # Infered from _colorMap
			}
			default {
				puts "[::TermColor::Init] Unsupported OS !"   ; # Logger is unavailable within int_init.
			}
		}
		set m_customColors(default) $m_defaultColors
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method SetForegroundColor { color } {
		switch -exact $m_OS {
			linux {
				puts -nonewline $color
			}
			win32 {
				set  evalStr "::twapi::set_console_default_attr \{ $m_consoleHandle \} $color"
				eval $evalStr
			}
			default {
				::Logger::addLog ERR_LOG "Unsupported OS ($m_OS) !"
			}
		}
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method SetBackgroundColor { color } {
		eval "::twapi::set_console_default_attr \{ $m_consoleHandle \} $color"  ; # TODO : why different from fg ?
	}	
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method CheckAliasedColorExistence	{ colorAlias } {
		if { [lsearch -exact [array names m_customColors] $colorAlias] != -1 } {
			return 1
		} else {
			return 0
		}
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	method IsThisColorAvailable { color } {
		if { [lsearch -exact $m_availableColors $color] != -1 } {
			return 1
		} else {
			return 0
		}
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	method Int_+ { args } {   
		switch -exact $m_OS {
			linux {            							
				set t 0
				foreach i $args {
					set ix [ lsearch -exact $m_colorMap $i ]
					if { $ix > -1 } {
						lappend t [ lindex $m_colorMap [ incr ix ] ]
					}
				}
				return "\033\[[join $t {;}]m"
			}
			default {
				#  Used in linux world only
				::Logger::addLog WNG_LOG "This call is unexpected here ! Investigation required."
				return ""
			}
		}
	}	
	
}
#========================================================================================================================================================================================================
