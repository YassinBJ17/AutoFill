package file.sutc.B0_Sheet;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.ss.util.CellRangeAddress;

import static file.sutc.B1_Sheet.Commun.RemoveExtraColumn.removeExtraCols;

import static file.sutc.Commun.LongTextDivider.*;
import static file.sutc.Commun.ExcelManipulation.*;
import static file.sutc.Commun.ExcelRowsAndColsConstants.*;

import java.util.List;
import java.util.Objects;

import static file.commun.LoggerInitialize.*;
import static file.sutc.Commun.utcUftNumberCounter.numberOfCauses;
import static file.sutc.SutcCreationProcess.*;

public class B0_ExcelSheet {

    public static final int CAUSES_TABLE_POSITION = 2;
    public static final int EFFECT_TABLE_POSITION = 43;
    public static final int NUMBER_OF_EMPTY_CELL = 40;
    public static final int END_OF_SHEET = 84;

    static void LLR_TraceabilityFilling(){

    Fill_Cell(llrTraceability(llrOfTheFunction), SHEET_B0_INDEX, CELL_ROW_3, CELL_COL_4);//LLR traceability Filling
    Fill_Cell(llrTraceability(llrOfTheFunction), SHEET_B0_INDEX, EFFECT_TABLE_POSITION + 1, CELL_COL_4);//LLR traceability Filling
    }
    private static void HeaderFilling() {
        Fill_Cell("Unit Functional Tests for: " + functionName, SHEET_B0_INDEX, CELL_ROW_0, CELL_COL_2);
    }
    private static int CausesFilling(){
        int number_of_causes = 1;
        for (String cause : causesTable) {
            if (!(Objects.equals(cause, "null"))) {
                cause = cause.replace("\n\n", "\n"); // delete extra line-return
                Fill_Cell(cause, SHEET_B0_INDEX, number_of_causes + CAUSES_TABLE_POSITION, CELL_COL_2);
                number_of_causes++;
            }
        }
        return number_of_causes ;
    }
    private static int EffectFilling() {
        int number_of_effects = 1;
        for (String effect : effectsTable) {
            effect = effect.replace("CALL ","\nCALL ");
            effect = effect.replace("Set ","\nSet ");
            effect = effect.replaceFirst("^\\n", "");// delete the first character from a string if it is equal to a newline character (\n)
            effect = effect.replace("\n\n", "\n"); // delete extra line return

            if (effect.length() < 32767) {
                Fill_Cell(effect, SHEET_B0_INDEX, number_of_effects + EFFECT_TABLE_POSITION, CELL_COL_2);
                number_of_effects++;
            } else {
                List<String> effects = divideLongText(effect, 5000);
                for (String dividedEffect : effects) {
                    //System.out.println(dividedEffect);
                    Fill_Cell(dividedEffect, SHEET_B0_INDEX, number_of_effects + EFFECT_TABLE_POSITION, CELL_COL_2);
                    number_of_effects++;
                }
            }
        }
        return number_of_effects;
    }
    private static boolean isCellMerged(Sheet sheet, int rowIndex, int columnIndex) {
        for (CellRangeAddress range : sheet.getMergedRegions()) {
            if (range.isInRange(rowIndex, columnIndex)) {
                return true;
            }
        }
        return false;
    }
        private static void removeExtraCells(int number_of_effects){


            if (numberOfCauses == 1)
                for (int i = 1; i < number_of_effects; i++) {
                    Fill_Cell("T", SHEET_B0_INDEX, EFFECT_TABLE_POSITION+i, CELL_COL_3);
                }

            if (number_of_effects==1)
            {
                Fill_Cell("N/A", SHEET_B0_INDEX, EFFECT_TABLE_POSITION+1, CELL_COL_2);
                number_of_effects=2;
            }

            removeExtraRows(SHEET_B0_INDEX, EFFECT_TABLE_POSITION + number_of_effects, END_OF_SHEET); // Remove Extra Effect Rows

            for (int i=0;i<20-numberOfUFT;i++)
                removeExtraCols(SHEET_B0_INDEX,numberOfUFT+CELL_COL_3);
            MergeCols(SHEET_B0_INDEX, CELL_COL_2, CELL_ROW_1, numberOfUFT+CELL_COL_6 );// Merge Header
            for (int i=2;i<=numberOfUFT+CELL_COL_6;i++)
                addThickOutsideBorder(SHEET_B0_INDEX, CELL_ROW_0, i);


            if (numberOfCauses == 1)   // Number of causes is 0
            {
                workbook.getSheetAt(SHEET_B0_INDEX).shiftRows(EFFECT_TABLE_POSITION, END_OF_SHEET, -(NUMBER_OF_EMPTY_CELL - numberOfCauses));  // Remove Extra Causes Rows
                Fill_Cell("N/A", SHEET_B0_INDEX, CELL_ROW_3, CELL_COL_3);
                Fill_Cell("N/A", SHEET_B0_INDEX, CELL_ROW_3, CELL_COL_2);

                if (number_of_effects > 2)
                    MergeRows(SHEET_B0_INDEX, CELL_COL_3 + numberOfUFT, CELL_ROW_4 + 2, CELL_COL_2 + 2 + number_of_effects);// Merge LLR traceability



            } else {
                workbook.getSheetAt(SHEET_B0_INDEX).shiftRows(EFFECT_TABLE_POSITION, END_OF_SHEET, -(NUMBER_OF_EMPTY_CELL - numberOfCauses + 1));

                if (numberOfCauses > 2)  // Number of causes is bigger than 1 cause
                    MergeRows(SHEET_B0_INDEX, CELL_COL_3 + numberOfUFT, CELL_COL_4, CELL_COL_2 + numberOfCauses);// Merge LLR traceability

                if (number_of_effects > 2)
                    MergeRows(SHEET_B0_INDEX, CELL_COL_3 + numberOfUFT, CELL_ROW_4 + numberOfCauses, CELL_COL_2 + numberOfCauses + number_of_effects);// Merge LLR traceability

            }


            workbook.getSheetAt(SHEET_B0_INDEX).setColumnWidth(CELL_COL_3 + numberOfUFT,9000);


        }


    public static void fillingB0Sheet() {

        int number_of_effects ;

        log4Info("B0 Sheet in progress");
        HeaderFilling();
        LLR_TraceabilityFilling();
        numberOfCauses=CausesFilling();
        number_of_effects=EffectFilling();
        removeExtraCells(number_of_effects);

    }

}
