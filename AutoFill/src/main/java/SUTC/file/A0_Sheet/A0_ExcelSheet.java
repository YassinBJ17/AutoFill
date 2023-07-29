package SUTC.file.A0_Sheet;
import static SUTC.file.Commun.OpenCloseExcelTemplate.openExcelTemplate;
import static SUTC.file.SutcCreationProcess.functionName;
import static SUTC.file.Commun.ExcelManipulation.Fill_Cell;
import static Commun.BrowsingInputFolder.designFileName;
import static SUTC.file.Commun.ExcelRowsAndColsConstants.*;
public class A0_ExcelSheet {


    public static void fillingA0Sheet(){


        openExcelTemplate();

        String File_Name= functionName + ".c";
        Fill_Cell(File_Name, SHEET_A0_INDEX, CELL_ROW_2, CELL_COL_3);// File Name Filling

        String CSU_Name= functionName;
        Fill_Cell(CSU_Name, SHEET_A0_INDEX, CELL_ROW_4, CELL_COL_3);//CSU Name Filling
        Fill_Cell(CSU_Name, SHEET_A0_INDEX, CELL_ROW_15, CELL_COL_2);//CSU Name Filling

        String CSC_Name="CSC_"+CSU_Name.substring(0,CSU_Name.indexOf("_"));
        Fill_Cell(CSC_Name, SHEET_A0_INDEX, CELL_ROW_3, CELL_COL_3);//CSC Name Filling

        Fill_Cell(designFileName, SHEET_A0_INDEX, CELL_ROW_8, CELL_COL_2);//Reference Documents Filling
        Fill_Cell("1C", SHEET_A0_INDEX, CELL_ROW_8, CELL_COL_3);//Version of Documents Filling

        Fill_Cell("FADEX-OVSP_SDDD-DD.xlsx", SHEET_A0_INDEX, CELL_ROW_9, CELL_COL_2);//Reference Documents Filling
        Fill_Cell("2", SHEET_A0_INDEX, CELL_ROW_9, CELL_COL_3);//Version of Documents Filling

    }


}
