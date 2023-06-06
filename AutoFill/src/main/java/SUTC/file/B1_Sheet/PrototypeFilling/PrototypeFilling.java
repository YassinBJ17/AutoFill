package SUTC.file.B1_Sheet.PrototypeFilling;

import SUTC.file.B1_Sheet.B1_ExcelSheet;
import SUTC.file.Services.Excel;
import SUTC.file.Services.ExcelModifier;


public class PrototypeFilling {

    public static void PrototypeFilling() {

        B1_ExcelSheet.Prototype= B1_ExcelSheet.Prototype+")";
        B1_ExcelSheet.Prototype= B1_ExcelSheet.Prototype.replace(", )",")");
        ExcelModifier.Fill_Cell(B1_ExcelSheet.Prototype, Excel.SHEET_B1, Excel.CELL_ROW_3, Excel.CELL_COL_2);
    }
}
