package SUTC.file.B1_Sheet.Services;

import SUTC.file.Services.Excel;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.ss.util.CellRangeAddress;

import static SUTC.file.B1_Sheet.B1_ExcelSheet.START_OF_PARAMETERS_TABLE;
import static SUTC.file.Services.ExcelFinal.number_of_UFT;
import static COMMUN.LoggerInit.logger4j;

public class RemoveExtraRow {

    public static void  Remove_Extra_Row( Workbook workbook){

        Sheet B1_sheet= workbook.getSheetAt(Excel.SHEET_B1);
        Sheet A2_sheet= workbook.getSheetAt(Excel.SHEET_A2);
        boolean bool=true;

        while (bool){
            bool=false;
            for (int i = START_OF_PARAMETERS_TABLE+1+ number_of_UFT; i <B1_sheet.getLastRowNum() ; i++) {

                Row row = B1_sheet.getRow(i);

                if (row != null) {
                    // Get the second cell in the row
                    Cell secondCell = row.getCell(1);

                    boolean isMerged=false;
                    for (CellRangeAddress mergedRegion : B1_sheet.getMergedRegions()) {
                        if (mergedRegion.isInRange(i, 1)) {
                            isMerged = true;
                            break;
                        }
                    }
                    if(secondCell!=null){
                        if (secondCell.getCellType() == CellType.BLANK && !isMerged) {
                            // If the second cell is empty or null, delete the row
                            try {
                                B1_sheet.shiftRows(i + 1, B1_sheet.getLastRowNum(), -1);
                            }catch (Exception e)
                            {
                                logger4j.error(e);
                            }
                            bool=true;
                        }
                    }
                }
            }


            for (int i = 2; i <A2_sheet.getLastRowNum(); i++) {

                Row row = A2_sheet.getRow(i);
                Cell secondCell = row.getCell(2);

                boolean isMerged=false;
                for (CellRangeAddress mergedRegion : A2_sheet.getMergedRegions()) {
                    if (mergedRegion.isInRange(i, 1)) {
                        isMerged = true;
                        break;
                    }
                }

                if ((secondCell.getCellType() == CellType.BLANK)&& !isMerged) {
                    // If the second cell is empty or null, delete the row
                    A2_sheet.shiftRows(i + 1, A2_sheet.getLastRowNum(), -1);
                }

            }

        }
    }
}
