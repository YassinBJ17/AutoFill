package excel.file.Services;
import org.apache.poi.ss.usermodel.Workbook;
import static excel.file.Services.ExcelFinal.lowLevelReqDocument;

public class SheetsName {

    public static final int MAXIMAL_SHEETNAME_LENGTH = 23;


    public static void Sheets_Name( Workbook workbook){

        if (lowLevelReqDocument[1].length()>MAXIMAL_SHEETNAME_LENGTH)
         {
                String sheet_name= lowLevelReqDocument[1].substring(lowLevelReqDocument[1].lastIndexOf('_')+1);
                String B0_Sheet_name="B0-"+sheet_name+"_UFT";
                String B1_Sheet_name="B1-"+sheet_name+"_UTC";

                workbook.setSheetName(Excel.SHEET_B0,B0_Sheet_name );
                workbook.setSheetName(Excel.SHEET_B1, B1_Sheet_name);

                ExcelModifier.Fill_Cell(B1_Sheet_name,Excel.SHEET_A0,Excel.CELL_ROW_15,Excel.CELL_COL_3);
         }

      else {

                  String B0_Sheet_name="B0-"+ lowLevelReqDocument[1]+"_UFT";
                  String B1_Sheet_name="B1-"+ lowLevelReqDocument[1]+"_UTC";

                  workbook.setSheetName(Excel.SHEET_B0, B0_Sheet_name);
                  workbook.setSheetName(Excel.SHEET_B1, B1_Sheet_name);

                  ExcelModifier.Fill_Cell(B1_Sheet_name,Excel.SHEET_A0,Excel.CELL_ROW_15,Excel.CELL_COL_3);
           }
    }
}
