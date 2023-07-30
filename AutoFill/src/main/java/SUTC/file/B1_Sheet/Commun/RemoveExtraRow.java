package SUTC.file.B1_Sheet.Commun;

import static SUTC.file.B1_Sheet.B1_ExcelSheet.MAXIMUM_UFT_NUMBER;
import static SUTC.file.B1_Sheet.Commun.RemoveExtraColumn.removeExtraCols;
import static SUTC.file.Commun.ExcelManipulation.MergeCols;
import static SUTC.file.Commun.ExcelRowsAndColsConstants.*;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.ss.util.CellRangeAddress;
import static SUTC.file.B1_Sheet.B1_ExcelSheet.START_OF_PARAMETERS_TABLE;
import static Commun.LoggerInitialize.*;
import static SUTC.file.SutcCreationProcess.*;

public class RemoveExtraRow {

    public static void RemoveExtraRows(){

        Sheet B1_sheet= workbook.getSheetAt(SHEET_B1_INDEX);
        Sheet A2_sheet= workbook.getSheetAt(SHEET_A2_INDEX);
        boolean bool=true;


        for (int i=0;i<40-numberOfUTC;i++)
            removeExtraCols(SHEET_B1_INDEX,numberOfUTC+CELL_COL_10);


        while (bool){
            bool=false;
            for (int i = START_OF_PARAMETERS_TABLE; i <B1_sheet.getLastRowNum() ; i++) {

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
                                String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                                log4Error(methodName+" : "+e.getMessage() );
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


        if (numberOfUFT<MAXIMUM_UFT_NUMBER)
        {
            try {
                B1_sheet.shiftRows(START_OF_PARAMETERS_TABLE-2, B1_sheet.getLastRowNum(), numberOfUFT-(MAXIMUM_UFT_NUMBER));

                for (int i = 0; i <numberOfUFT ; i++) {
                    MergeCols(SHEET_B1_INDEX,1,10+i,9);
                }

            }catch (Exception e)
            {
                String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                log4Error(methodName+" : "+e.getMessage() );
            }

        }


    }
}
