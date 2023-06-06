package SUTC.file.B0_Sheet;
import SUTC.file.Services.Excel;
import SUTC.file.Services.ExcelFinal;
import SUTC.file.Services.ExcelModifier;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.ss.util.CellRangeAddress;

import java.util.ArrayList;
import java.util.Objects;

import static COMMUN.LoggerInit.logger4j;

public class A0_ExcelSheet{

    public static final int CAUSES_TABLE_POSITION = 2;
    public static final int EFFECT_TABLE_POSITION = 43;
    public static final int NUMBER_OF_EMPTY_CELL = 40;
    public static final int END_OF_SHEET = 84;

    static void LLR_TraceabilityFilling(){

    ExcelModifier.Fill_Cell(ExcelModifier.Req_detect(ExcelFinal.lowLevelReq), Excel.SHEET_B0, Excel.CELL_ROW_3, Excel.CELL_COL_4);//LLR traceability Filling
    ExcelModifier.Fill_Cell(ExcelModifier.Req_detect(ExcelFinal.lowLevelReq), Excel.SHEET_B0, EFFECT_TABLE_POSITION + 1, Excel.CELL_COL_4);//LLR traceability Filling
    }
    private static void HeaderFilling() {
        ExcelModifier.Fill_Cell("Unit Functional Tests for: " + ExcelFinal.lowLevelReq[1], Excel.SHEET_B0, Excel.CELL_ROW_0, Excel.CELL_COL_2);
    }
    private static int CausesFilling(ArrayList<String> causes_table){
        int number_of_causes = 1;
        for (String cause : causes_table) {
            if (!(Objects.equals(cause, "null"))) {
                cause = cause.replace("\n\n", "\n"); // delete extra line return
                ExcelModifier.Fill_Cell(cause, Excel.SHEET_B0, number_of_causes + CAUSES_TABLE_POSITION, Excel.CELL_COL_2);
                number_of_causes++;
            }
        }
        return number_of_causes ;
    }
    private static int EffectFilling(ArrayList<String> effects_table) {
        int number_of_effects = 1;
        for (String effect : effects_table) {
            effect = effect.replace("\n\n", "\n"); // delete extra line return
            ExcelModifier.Fill_Cell(effect, Excel.SHEET_B0, number_of_effects + EFFECT_TABLE_POSITION, Excel.CELL_COL_2);
            number_of_effects++;
        }
        return number_of_effects ;
    }

    private static boolean isCellMerged(Sheet sheet, int rowIndex, int columnIndex) {
        for (CellRangeAddress range : sheet.getMergedRegions()) {
            if (range.isInRange(rowIndex, columnIndex)) {
                return true;
            }
        }
        return false;
    }

    private static void ExtraRowsRemoving(int number_of_effects, int number_of_causes){

        ExcelModifier.Remove_Extra_Rows(Excel.SHEET_B0, EFFECT_TABLE_POSITION + number_of_effects, END_OF_SHEET); // Remove Extra Effect Rows

        if (number_of_causes == 1)   // Number of causes is 0
        {
            ExcelFinal.workbook.getSheetAt(Excel.SHEET_B0).shiftRows(EFFECT_TABLE_POSITION, END_OF_SHEET, -(NUMBER_OF_EMPTY_CELL - number_of_causes));  // Remove Extra Causes Rows
            ExcelModifier.Fill_Cell("N/A", Excel.SHEET_B0, Excel.CELL_ROW_3, Excel.CELL_COL_3);
            ExcelModifier.Fill_Cell("N/A", Excel.SHEET_B0, Excel.CELL_ROW_3, Excel.CELL_COL_2);
        } else {
            ExcelFinal.workbook.getSheetAt(Excel.SHEET_B0).shiftRows(EFFECT_TABLE_POSITION, END_OF_SHEET, -(NUMBER_OF_EMPTY_CELL - number_of_causes + 1));
            if (number_of_causes > 2)  // Number of causes is bigger than 1 cause
                ExcelModifier.Merge_Cells(Excel.SHEET_B0, Excel.CELL_COL_2+ ExcelFinal.number_of_UFT, Excel.CELL_COL_4, 2 + number_of_causes);// Merge LLR traceability
        }

        if (number_of_effects > 2)
            ExcelModifier.Merge_Cells(Excel.SHEET_B0, Excel.CELL_COL_2+ ExcelFinal.number_of_UFT, 4 + number_of_causes, 2 + number_of_causes + number_of_effects);// Merge LLR traceability

    }


    public static void B0_sheet(ArrayList<String> causes_table, ArrayList<String> effects_table) {

        int number_of_effects = 1;
        int number_of_causes = 1;
        logger4j.info("B0 Sheet in progress");
        HeaderFilling();
        LLR_TraceabilityFilling();
        number_of_causes=CausesFilling(causes_table);
        number_of_effects=EffectFilling(effects_table);
        ExtraRowsRemoving(number_of_effects,number_of_causes);

    }

}
