#========================================================================================================================================================================================================
oo::class create OfficeExcel {
#------------------------------------------------------------------------------ M E M B E R    V A R I A B L E S ----------------------------------------------------------------------------------------
	variable m_fullPath
	variable m_comExcel
	variable m_comExcelWorkbooks
	variable m_comExcelWorkbooksWorkbook
	variable m_comExcelWorkbooksWorkbookSheets
	variable m_detectedSheets
	variable m_detectedCells
#----------------------------------------------------------------------------------- C O N S T R U C T O R ----------------------------------------------------------------------------------------------
	constructor { fullPath { isVisible 1} } {
		if { ![file exists $fullPath] } {
			$::termColor putsColor "\[ERR]" ERR 1
			puts "Cannot open '$fullPath'"
			puts "Aborted."
			exit 1
		}
		set m_fullPath [file normalize $fullPath]
		$::termColor putsColor "\[INF]" INF 1
		puts -nonewline " OfficeExcel : Opening "
		$::termColor putsColor '[file nativename [file normalize $fullPath]]' FILE_NAME 1
		puts -nonewline "..." 
		flush stdout
		package require twapi
		set m_comExcel [::twapi::comobj Excel.Application]
		$m_comExcel Visible $isVisible
		set m_comExcelWorkbooks [$m_comExcel Workbooks]
		$m_comExcelWorkbooks Open $m_fullPath
		set m_comExcelWorkbooksWorkbook [$m_comExcelWorkbooks Item 1] 
		set m_comExcelWorkbooksWorkbookSheets [$m_comExcelWorkbooksWorkbook Sheets]
		
		# Discover sheets :
		set index 1
		while { ![catch { set mySheet [$m_comExcelWorkbooksWorkbookSheets Item $index] } errorMsg] } {
			set sheetName [string trim [$mySheet Name]]
			set m_detectedSheets($sheetName) $mySheet
			set m_detectedCells($sheetName) [$mySheet cells]
			incr index
		}

		puts "Done."
		$::termColor putsColor "\[INF]" INF 1
		puts " OfficeExcel : Found [expr {$index - 1}] sheet(s) :"
		foreach sheetName [lsort -ascii [array name m_detectedSheets]] {
			$::termColor putsColor "\[INF]" INF 1
			puts -nonewline " OfficeExcel :    -> '"
			$::termColor putsColor $sheetName SHEET_NAME 1
			puts '
		}
	}
#------------------------------------------------------------------------------------ D E S T R U C T O R -----------------------------------------------------------------------------------------------
	destructor {
		$::termColor putsColor "\[INF]" INF 1
		puts -nonewline " OfficeExcel : Closing..."
		flush stdout
		while { [catch {
			my Destroy
			} errorMsg] } {
			set messageStr "File '$m_fullPath' is blocked !"
			puts -nonewline $messageStr
			flush stdout
			after 500
			puts -nonewline "\b "
			flush stdout
			after 500
			puts -nonewline [string repeat "\b" [string length $messageStr]]
			puts -nonewline [string repeat " "  [string length $messageStr]]
			puts -nonewline [string repeat "\b" [string length $messageStr]]
			flush stdout
		}
		puts Done.
	}
#-------------------------------------------------------------------------------- P U B L I C    M E T H O D S ------------------------------------------------------------------------------------------
	method getListOfSheetsSorted { } {
		return [lsort -ascii [array names m_detectedSheets]]
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	method doesSheetExist { sheetName } {
		if { [lsearch -exact [array names m_detectedSheets] $sheetName ] == -1 } {
			return 0
		} else {
			return 1
		}
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	method getCellVal { sheet line column } {
		set cell  [my GetCell $sheet $line $column]
		set value [$cell Value]
		$cell destroy 
		return $value
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	method getCellValInt { sheet line column } {
		return [scan [my getCellVal $sheet $line $column] %d]
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	method getCellValTrimmed { sheet line column } {
		return [string trim [my  getCellVal $sheet $line $column]]
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	method getCellBorderSide { sheet line column side } {
		set cell [my GetCell $sheet $line $column]	
		switch -exact $side	{
			xlEdgeBottom {
				set sideInteger 4
			}
			default {
				$::termColor putsColor "\[ERR]" ERR 1
				puts "Unsupported side ($side) !"
				puts Aborted.
				exit 0
			}
		}
		return [[$cell Borders] Item $sideInteger]
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	method getCellBorderSideLineStyle { sheet line column side } {
		set border [my getCellBorderSide $sheet $line $column $side]
		set lineStyleInteger [$border LineStyle]
		switch -exact $lineStyleInteger {
			-4142 {
				set lineStyle none
			}
			1 {
				set lineStyle ???
			}
			default {
				$::termColor putsColor "\[ERR]" ERR 1
				puts "Unknown line style ($lineStyleInteger) !"
				puts Aborted.
				exit 0
			}
		}
		return $lineStyle
	}
#-------------------------------------------------------------------------------- P R I V A T E    M E T H O D S ----------------------------------------------------------------------------------------
	method Destroy { } {
		$m_comExcelWorkbooksWorkbook       Close 1
		$m_comExcelWorkbooksWorkbookSheets -destroy
		$m_comExcelWorkbooksWorkbook       -destroy
		$m_comExcelWorkbooks               -destroy
		$m_comExcel                        Quit
		$m_comExcel                        -destroy
	}
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	method GetCell { sheet line column } {
		return [$m_detectedCells($sheet) Item $line $column]
	}
}
#========================================================================================================================================================================================================
