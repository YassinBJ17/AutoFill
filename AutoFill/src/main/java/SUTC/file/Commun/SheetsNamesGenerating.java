package SUTC.file.Commun;
import static SUTC.file.Commun.ExcelRowsAndColsConstants.*;
import static SUTC.file.SutcCreationProcess.functionName;
import static SUTC.file.SutcCreationProcess.workbook;

public class SheetsNamesGenerating {

    public static final int MAXIMAL_SHEETNAME_LENGTH = 22;


    public static void fillingSheetsName(){

        String sheetName=functionName;

            while (sheetName.length()>=MAXIMAL_SHEETNAME_LENGTH) {
                     sheetName = sheetName.substring(sheetName.indexOf('_') + 1);
                }

                String B0_Sheet_name="B0 - "+sheetName+"_UFT";
                String B1_Sheet_name="B1 - "+sheetName+"_UTC";

                workbook.setSheetName(SHEET_B0_INDEX,B0_Sheet_name );
                workbook.setSheetName(SHEET_B1_INDEX, B1_Sheet_name);

                ExcelManipulation.Fill_Cell(B1_Sheet_name, SHEET_A0_INDEX, CELL_ROW_15, CELL_COL_3);
         }

}
