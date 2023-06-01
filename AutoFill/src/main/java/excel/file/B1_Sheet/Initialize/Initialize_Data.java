package excel.file.B1_Sheet.Initialize;

import excel.file.B1_Sheet.B1_ExcelSheet;
import excel.file.Services.Excel;
import excel.file.Services.ExcelModifier;
import java.util.Arrays;
import static excel.file.B1_Sheet.B1_ExcelSheet.Parameters;
import static excel.file.B1_Sheet.B1_ExcelSheet.Stubs;
import static excel.file.B1_Sheet.B1_ExcelSheet.Prototype;

public class Initialize_Data {

public static void Initialize_Data(String function_name) {
        Arrays.fill(B1_ExcelSheet.Globals, "");
        Arrays.fill(Stubs, "");

        for (String[] row : Parameters) {
        Arrays.fill(row, "");
        }
        ExcelModifier.Fill_Cell("Unit Test Cases for: " + function_name, Excel.SHEET_B1, Excel.CELL_ROW_0, Excel.CELL_COL_2);

        Prototype=function_name+"(";

        }
}