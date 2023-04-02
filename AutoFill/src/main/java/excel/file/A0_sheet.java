package excel.file;


import static excel.file.ExcelModifier.Fill_Cell;

public class A0_sheet {

    public static final int index_of_CSC_Name=0;
    public static final int index_of_CSU_Name=1;


    public A0_sheet(String  [] LLR){

        String File_Name=LLR[index_of_CSU_Name] + ".c";

        Fill_Cell(File_Name,Excel.SHEET_A0, Excel.CELL_ROW_2,Excel.CELL_COL_3);

        String CSC_Name=LLR[index_of_CSC_Name];
        Fill_Cell(CSC_Name,Excel.SHEET_A0, Excel.CELL_ROW_3,Excel.CELL_COL_3);

        String CSU_Name=LLR[index_of_CSU_Name];
        Fill_Cell(CSU_Name,Excel.SHEET_A0, Excel.CELL_ROW_4,Excel.CELL_COL_3);
        Fill_Cell(CSU_Name,Excel.SHEET_A0,Excel.CELL_ROW_15,Excel.CELL_COL_2);

    }


}
