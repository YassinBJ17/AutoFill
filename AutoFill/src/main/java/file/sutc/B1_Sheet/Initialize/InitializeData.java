package file.sutc.B1_Sheet.Initialize;

import file.sutc.B1_Sheet.B1_ExcelSheet;
import static file.sutc.Commun.ExcelRowsAndColsConstants.*;
import static file.sutc.SutcCreationProcess.functionName;

import file.sutc.Commun.ExcelManipulation;

import java.util.Arrays;

public class InitializeData {

public static void Initialize_Data() {
        Arrays.fill(B1_ExcelSheet.Globals, "");
        Arrays.fill(B1_ExcelSheet.Stubs, "");

        for (String[] row : B1_ExcelSheet.Parameters) {
        Arrays.fill(row, "");
        }
        ExcelManipulation.Fill_Cell("Unit Test Cases for: " + functionName, SHEET_B1_INDEX, CELL_ROW_0, CELL_COL_2);

        B1_ExcelSheet.prototypeOfTheFunction =functionName+"(";

        }
}