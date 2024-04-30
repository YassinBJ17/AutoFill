package file.sutc.B1_Sheet;

import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;

import static file.sutc.B1_Sheet.Commun.ExtractData.robustnessTestOn;
import static file.sutc.B1_Sheet.Commun.RemoveExtraRow.RemoveExtraRows;
import static file.sutc.B1_Sheet.FunctionReturnFilling.FunctionReturnFilling.Function_Return_Filling;
import static file.sutc.B1_Sheet.Global.GlobalFilling.GlobalParametersFilling;
import static file.sutc.B1_Sheet.Initialize.InitializeData.Initialize_Data;
import static file.sutc.B1_Sheet.PrametersFilling.ParametersFilling.Parameters_Filling;
import static file.sutc.B1_Sheet.PrototypeFilling.PrototypeFilling.Prototype_Filling;
import static file.sutc.B1_Sheet.Subs.StubsFilling.Stubs_Filling;
import static file.commun.LoggerInitialize.*;
import static file.sutc.Commun.ExcelManipulation.Fill_Cell;
import static file.sutc.Commun.ExcelRowsAndColsConstants.*;
import static file.sutc.SutcCreationProcess.workbook;

public class B1_ExcelSheet {

    public static int END_OF_SHEET_POSITION ;
    public static int START_OF_PARAMETERS_TABLE=31;
    public static final int MAXIMUM_UFT_NUMBER=20;
    public static final int STUB_DEFINITION_TABLE_POSITION=215;
    public static final int RETURN_FUNCTION_INDEX=STUB_DEFINITION_TABLE_POSITION-5;
    public static final int DISTANCE_BETWEEN_STUBS =69;
    public static int STUB_PARAMETERS_TABLE_POSITION=221 ;
    public static int INTERNAL_VARIABLES_POSITION=113;
    public static int Global_Start;
    public static String prototypeOfTheFunction;
    public static int numberOfStubs;
    public static int numberOfParameters;
    public static String[] Globals=new String[100];
    public static String[] Stubs=new String[100];
    public static String[][] Parameters=new String[100][10];


    private static void robustnessTests() {


        if(robustnessTestOn) {
            robustnessTestOn=false;
            return;
        }
        int i=10;
        Sheet B1_sheet= workbook.getSheetAt(SHEET_B1_INDEX);
        Row row = B1_sheet.getRow(CELL_ROW_8);
        Cell checkCell = row.getCell(i);


            boolean lastCell = !((checkCell.getStringCellValue().isEmpty() || checkCell.getStringCellValue().isBlank()));
            while (lastCell){
            Fill_Cell("Functional", SHEET_B1_INDEX, CELL_ROW_8, i);
            i++;
            checkCell = row.getCell(i);
            if (checkCell==null)
                break;

            lastCell = !((checkCell.getStringCellValue().isEmpty() || checkCell.getStringCellValue().isBlank()));

        }
        }



    public static void fillingB1Sheet() {


    Initialize_Data();
    Stubs_Filling();
    Parameters_Filling();
    GlobalParametersFilling();
    Function_Return_Filling();
    Prototype_Filling();
    RemoveExtraRows();
    robustnessTests();
    log4Info("B1 Sheet done");


    }




}


