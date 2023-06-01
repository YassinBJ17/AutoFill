package excel.file.B1_Sheet.PrototypeFilling;

import excel.file.Services.Excel;
import excel.file.Services.ExcelModifier;
import static excel.file.B1_Sheet.B1_ExcelSheet.Prototype;


public class Prototype_Filling {

    public static void PrototypeFilling() {

        Prototype=Prototype+")";
        Prototype=Prototype.replace(", )",")");
        ExcelModifier.Fill_Cell(Prototype, Excel.SHEET_B1, Excel.CELL_ROW_3, Excel.CELL_COL_2);
    }
}
