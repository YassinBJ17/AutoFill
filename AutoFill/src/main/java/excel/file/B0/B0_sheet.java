package excel.file.B0;
import excel.file.Services.Excel;
import excel.file.Services.ExcelModifier;
import org.apache.poi.ss.usermodel.Workbook;

import java.util.ArrayList;
import java.util.Objects;

import static excel.file.Services.ExcelFinal.number_of_UFT;
import static excel.file.Services.ExcelModifier.Fill_Cell;

public class B0_sheet{

    public final int CAUSES_TABLE_POSITION = 2;
    public final int EFFECT_TABLE_POSITION = 43;

    public final int NUMBER_OF_EMPTY_CELL = 40;

    public final int END_OF_SHEET = 84;


    public B0_sheet(String [] llr_lines, ArrayList<String> causes_table, ArrayList<String> effects_table, Workbook workbook) {

        Fill_Cell("Unit Functional Tests for: " + llr_lines[1].toUpperCase(), Excel.SHEET_B0, Excel.CELL_ROW_0, Excel.CELL_COL_2);
        Fill_Cell(ExcelModifier.Req_detect(llr_lines), Excel.SHEET_B0, Excel.CELL_ROW_3, Excel.CELL_COL_4);
        Fill_Cell(ExcelModifier.Req_detect(llr_lines), Excel.SHEET_B0, EFFECT_TABLE_POSITION + 1, Excel.CELL_COL_4);


        int effects_number = 1;
        int number_of_causes = 1;

        for (String cause : causes_table) {
            if (!(Objects.equals(cause, "null"))) {
                cause = cause.replace("\n\n", "\n"); // delete extra line return
                Fill_Cell(cause, Excel.SHEET_B0, number_of_causes + CAUSES_TABLE_POSITION, Excel.CELL_COL_2);
                number_of_causes++;
            }
        }

        for (String effect : effects_table) {
            effect = effect.replace("\n\n", "\n"); // delete extra line return
            Fill_Cell(effect, Excel.SHEET_B0, effects_number + EFFECT_TABLE_POSITION, Excel.CELL_COL_2);
            effects_number++;
        }


        ExcelModifier.Remove_Extra_Rows(Excel.SHEET_B0, EFFECT_TABLE_POSITION + effects_number, END_OF_SHEET); // Remove Extra Effect Rows


        if (number_of_causes == 1)   // Number of causes is 0
        {
            workbook.getSheetAt(Excel.SHEET_B0).shiftRows(EFFECT_TABLE_POSITION, END_OF_SHEET, -(NUMBER_OF_EMPTY_CELL - number_of_causes));  // Remove Extra Causes Rows
            Fill_Cell("N/A", Excel.SHEET_B0, Excel.CELL_ROW_3, Excel.CELL_COL_3);
            Fill_Cell("N/A", Excel.SHEET_B0, Excel.CELL_ROW_3, Excel.CELL_COL_2);



        } else {
            workbook.getSheetAt(Excel.SHEET_B0).shiftRows(EFFECT_TABLE_POSITION, END_OF_SHEET, -(NUMBER_OF_EMPTY_CELL - number_of_causes + 1));
            if (number_of_causes > 2)  // Number of causes is 1
                ExcelModifier.Merge_Cells(Excel.SHEET_B0, Excel.CELL_COL_2+ number_of_UFT, Excel.CELL_COL_4, 2 + number_of_causes);// Merge LLR traceability
        }

        if (effects_number > 2)
            ExcelModifier.Merge_Cells(Excel.SHEET_B0, Excel.CELL_COL_2+number_of_UFT, 4 + number_of_causes, 2 + number_of_causes + effects_number);// Merge LLR traceability


    }
}
