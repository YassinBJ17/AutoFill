package SUTC.file.COMMUN;
import SUTC.file.SutcCreationProccess;
import org.apache.poi.ss.usermodel.Workbook;

import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;
public class SheetsNamesGenerating {

    public static final int MAXIMAL_SHEETNAME_LENGTH = 23;


    public static void Sheets_Name( Workbook workbook){

        if (SutcCreationProccess.lowLevelReq[1].length()>MAXIMAL_SHEETNAME_LENGTH)
         {
                String sheet_name= SutcCreationProccess.lowLevelReq[1].substring(SutcCreationProccess.lowLevelReq[1].lastIndexOf('_')+1);
                String B0_Sheet_name="B0-"+sheet_name+"_UFT";
                String B1_Sheet_name="B1-"+sheet_name+"_UTC";

                workbook.setSheetName(SHEET_B0,B0_Sheet_name );
                workbook.setSheetName(SHEET_B1, B1_Sheet_name);

                ExcelModifier.Fill_Cell(B1_Sheet_name, SHEET_A0, CELL_ROW_15, CELL_COL_3);
         }

      else {

                  String B0_Sheet_name="B0-"+ SutcCreationProccess.lowLevelReq[1]+"_UFT";
                  String B1_Sheet_name="B1-"+ SutcCreationProccess.lowLevelReq[1]+"_UTC";

                  workbook.setSheetName(SHEET_B0, B0_Sheet_name);
                  workbook.setSheetName(SHEET_B1, B1_Sheet_name);

                  ExcelModifier.Fill_Cell(B1_Sheet_name, SHEET_A0, CELL_ROW_15, CELL_COL_3);
           }
    }
}
