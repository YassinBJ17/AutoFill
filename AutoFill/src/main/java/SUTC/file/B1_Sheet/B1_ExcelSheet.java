package SUTC.file.B1_Sheet;

import static SUTC.file.B1_Sheet.Commun.RemoveExtraRow.RemoveExtraRows;
import static SUTC.file.B1_Sheet.FunctionReturnFilling.FunctionReturnFilling.Function_Return_Filling;
import static SUTC.file.B1_Sheet.Global.GlobalFilling.Global_Parameters_Filling;
import static SUTC.file.B1_Sheet.Initialize.InitializeData.Initialize_Data;
import static SUTC.file.B1_Sheet.PrametersFilling.ParametersFilling.Parameters_Filling;
import static SUTC.file.B1_Sheet.PrototypeFilling.PrototypeFilling.Prototype_Filling;
import static SUTC.file.B1_Sheet.Subs.StubsFilling.Stubs_Filling;
import static Commun.LoggerInitialize.*;

public class B1_ExcelSheet {

    public static int END_OF_SHEET_POSITION ;
    public static int START_OF_PARAMETERS_TABLE=31;
    public static final int MAXIMUM_UFT_NUMBER=20;
    public static final int STUB_DEFINITION_TABLE_POSITION=194;
    public static final int RETURN_FUNCTION_INDEX=STUB_DEFINITION_TABLE_POSITION-5;
    public static final int DISTANCE_BETWEEN_STUBS =69;
    public static int STUB_PARAMETERS_TABLE_POSITION=200 ;
    public static final int INTERNAL_DEFINITIONS_POSITION=32;
    public static int INTERNAL_VARIABLES_POSITION=113;
    public static int Global_Start;
    public static String prototypeOfTheFunction;
    public static String[] Globals=new String[100];
    public static String[] Stubs=new String[100];
    public static String[][] Parameters=new String[100][10];



    public static void fillingB1Sheet() {


    Initialize_Data();
    Stubs_Filling();
    Parameters_Filling();
    Global_Parameters_Filling();
    Function_Return_Filling();
    Prototype_Filling();
    RemoveExtraRows();
    log4Info("B1 Sheet done");


    }



}


