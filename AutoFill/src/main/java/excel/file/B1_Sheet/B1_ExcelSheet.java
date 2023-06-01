package excel.file.B1_Sheet;
import excel.file.Services.Excel;
import org.apache.poi.ss.usermodel.*;

import java.io.IOException;

import static excel.file.B1_Sheet.FunctionReturnFilling.FunctionRetrunFilling.Function_Return_Filling;
import static excel.file.B1_Sheet.Global.GlobalFilling.Global_Parameters_Filling;
import static excel.file.B1_Sheet.Initialize.Initialize_Data.Initialize_Data;
import static excel.file.B1_Sheet.PrametersFilling.ParametersFilling.Parameters_Filling;
import static excel.file.B1_Sheet.PrototypeFilling.Prototype_Filling.PrototypeFilling;
import static excel.file.B1_Sheet.Services.RemoveExtraRow.Remove_Extra_Row;
import static excel.file.B1_Sheet.Subs.StubsFilling.Stubs_Filling;
import static excel.file.Services.ExcelFinal.*;


public class B1_ExcelSheet {

    public static final int START_OF_PARAMETERS_TABLE=10;
    public static final int END_OF_SHEET_POSITION =workbook.getSheetAt(Excel.SHEET_B1).getLastRowNum();
    public static final int RETURN_FUNCTION_INDEX=132;
    public static final int DISTANCE_BETWEEN_STUBS =59;
    public static final int STUB_PARAMETERS_TABLE_POSITION =140;
    public static final int STUB_DEFINITION_TABLE_POSITION=133;
    public static final int INTERNAL_DEFINITIONS_POSITION=30;
    public static final int INTERNAL_VARIABLES_POSITION=71;
    public static int Global_Start=43;
    public static String Prototype;
    public static String[] Globals=new String[100];
    public static String[] Stubs=new String[100];
    public static String[][] Parameters=new String[100][10];





    ///////////////////////////////////////////////REMOVE EXTRA ROWS/////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




    public static void B1_sheet(Workbook workbook ) throws IOException {

    String function_name= lowLevelReqDocument[1];

    Initialize_Data(function_name);
    Stubs_Filling(lowLevelReqDocument);
    Parameters_Filling(codeOfTheSoftware, lowLevelReqDocument);
    Global_Parameters_Filling(lowLevelReqDocument);
    Function_Return_Filling(codeOfTheSoftware,function_name);
    PrototypeFilling();
    Remove_Extra_Row(workbook);

    }



}


