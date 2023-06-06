package SUTC.file.A0_Sheet;
import SUTC.file.Services.Excel;
import static SUTC.file.Services.ExcelFinal.lowLevelReq;
import static SUTC.file.Services.ExcelModifier.Fill_Cell;
import static COMMUN.BrowsingInputFolder.fileName;
import static COMMUN.LoggerInit.logger4j;

public class A0_ExcelSheet {

    public final int index_of_CSC_Name=0;
    public static final int index_of_CSU_Name=1;


    public static void A0_sheet(){

        logger4j.info("A0 Sheet in progress");
        String File_Name= lowLevelReq[index_of_CSU_Name] + ".c";
        Fill_Cell(File_Name, Excel.SHEET_A0, Excel.CELL_ROW_2,Excel.CELL_COL_3);// File Name Filling

        String CSU_Name= lowLevelReq[index_of_CSU_Name];
        Fill_Cell(CSU_Name,Excel.SHEET_A0, Excel.CELL_ROW_4,Excel.CELL_COL_3);//CSU Name Filling
        Fill_Cell(CSU_Name,Excel.SHEET_A0,Excel.CELL_ROW_15,Excel.CELL_COL_2);//CSU Name Filling

        String CSC_Name=CSU_Name.substring(0,CSU_Name.indexOf("_"));
        Fill_Cell(CSC_Name,Excel.SHEET_A0, Excel.CELL_ROW_3,Excel.CELL_COL_3);//CSC Name Filling



        Fill_Cell(fileName,Excel.SHEET_A0, Excel.CELL_ROW_8,Excel.CELL_COL_2);//Reference Documents Filling
        Fill_Cell("1C",Excel.SHEET_A0, Excel.CELL_ROW_8,Excel.CELL_COL_3);//Version of Documents Filling


    }


}
