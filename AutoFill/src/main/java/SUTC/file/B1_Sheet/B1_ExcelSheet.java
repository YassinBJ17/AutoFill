package SUTC.file.B1_Sheet;
import SUTC.file.B1_Sheet.COMMUN.RemoveExtraRow;
import org.apache.poi.ss.usermodel.*;

import static SUTC.file.B1_Sheet.FunctionReturnFilling.FunctionRetrunFilling.Function_Return_Filling;
import static SUTC.file.B1_Sheet.Global.GlobalFilling.Global_Parameters_Filling;
import static SUTC.file.B1_Sheet.Initialize.InitializeData.Initialize_Data;
import static SUTC.file.B1_Sheet.PrametersFilling.ParametersFilling.Parameters_Filling;
import static SUTC.file.B1_Sheet.PrototypeFilling.PrototypeFilling.Prototype_Filling;
import static SUTC.file.B1_Sheet.Subs.StubsFilling.Stubs_Filling;
import static SUTC.file.SutcCreationProccess.*;
import static COMMUN.LoggerInitialize.*;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;

public class B1_ExcelSheet {

    public static final int START_OF_PARAMETERS_TABLE=10;
    public static final int END_OF_SHEET_POSITION =workbook.getSheetAt(SHEET_B1).getLastRowNum();
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



    public static void B1_sheet(Workbook workbook ) {

    String function_name= lowLevelReq[1];
    log4Info("B1 Sheet in progress");
    Initialize_Data(function_name);
    Stubs_Filling(lowLevelReq);
    log4Info("Stubs filling success");
    Parameters_Filling(codeOfTheSoftware, lowLevelReq);
    Global_Parameters_Filling(lowLevelReq);
    Function_Return_Filling(codeOfTheSoftware,function_name);
    Prototype_Filling();
    RemoveExtraRow.Remove_Extra_Row(workbook);
    log4Info("B1 Sheet success");

    }



}


