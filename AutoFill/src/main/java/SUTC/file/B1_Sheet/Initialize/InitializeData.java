package SUTC.file.B1_Sheet.Initialize;

import SUTC.file.B1_Sheet.B1_ExcelSheet;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;
import SUTC.file.COMMUN.ExcelModifier;

import java.util.Arrays;

public class InitializeData {

public static void Initialize_Data(String function_name) {
        Arrays.fill(B1_ExcelSheet.Globals, "");
        Arrays.fill(B1_ExcelSheet.Stubs, "");

        for (String[] row : B1_ExcelSheet.Parameters) {
        Arrays.fill(row, "");
        }
        ExcelModifier.Fill_Cell("Unit Test Cases for: " + function_name, SHEET_B1, CELL_ROW_0, CELL_COL_2);

        B1_ExcelSheet.Prototype=function_name+"(";

        }
}