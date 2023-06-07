package SUTC.file.B1_Sheet.PrototypeFilling;

import SUTC.file.B1_Sheet.B1_ExcelSheet;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;
import SUTC.file.COMMUN.ExcelModifier;


public class PrototypeFilling {

    public static void Prototype_Filling() {

        B1_ExcelSheet.Prototype= B1_ExcelSheet.Prototype+")";
        B1_ExcelSheet.Prototype= B1_ExcelSheet.Prototype.replace(", )",")");
        ExcelModifier.Fill_Cell(B1_ExcelSheet.Prototype, SHEET_B1, CELL_ROW_3, CELL_COL_2);
    }
}
