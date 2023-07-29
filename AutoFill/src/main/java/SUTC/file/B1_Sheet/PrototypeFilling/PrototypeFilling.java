package SUTC.file.B1_Sheet.PrototypeFilling;

import SUTC.file.B1_Sheet.B1_ExcelSheet;
import static SUTC.file.Commun.ExcelRowsAndColsConstants.*;
import SUTC.file.Commun.ExcelManipulation;


public class PrototypeFilling {

    public static void Prototype_Filling() {

        B1_ExcelSheet.prototypeOfTheFunction = B1_ExcelSheet.prototypeOfTheFunction +")";
        B1_ExcelSheet.prototypeOfTheFunction = B1_ExcelSheet.prototypeOfTheFunction.replace(", )",")");
        ExcelManipulation.Fill_Cell(B1_ExcelSheet.prototypeOfTheFunction, SHEET_B1_INDEX, CELL_ROW_3, CELL_COL_2);
    }
}
