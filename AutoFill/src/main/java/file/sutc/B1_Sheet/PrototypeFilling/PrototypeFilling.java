package file.sutc.B1_Sheet.PrototypeFilling;

import file.sutc.B1_Sheet.B1_ExcelSheet;
import static file.sutc.Commun.ExcelRowsAndColsConstants.*;
import file.sutc.Commun.ExcelManipulation;


public class PrototypeFilling {

    public static void Prototype_Filling() {

        B1_ExcelSheet.prototypeOfTheFunction = B1_ExcelSheet.prototypeOfTheFunction +")";
        B1_ExcelSheet.prototypeOfTheFunction = B1_ExcelSheet.prototypeOfTheFunction.replace(", )",")");
        ExcelManipulation.Fill_Cell(B1_ExcelSheet.prototypeOfTheFunction, SHEET_B1_INDEX, CELL_ROW_3, CELL_COL_2);
    }
}
