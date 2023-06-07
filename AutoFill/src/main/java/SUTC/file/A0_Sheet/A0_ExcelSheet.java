package SUTC.file.A0_Sheet;
import static SUTC.file.SutcCreationProccess.lowLevelReq;
import static SUTC.file.COMMUN.ExcelModifier.Fill_Cell;
import static COMMUN.BrowsingInputFolder.fileName;
import static COMMUN.LoggerInitialize.*;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;
public class A0_ExcelSheet {

    public static final int index_of_CSU_Name=1;

    public static void A0_sheet(){

        logInfo("A0 Sheet in progress");
        String File_Name= lowLevelReq[index_of_CSU_Name] + ".c";
        Fill_Cell(File_Name, SHEET_A0, CELL_ROW_2, CELL_COL_3);// File Name Filling

        String CSU_Name= lowLevelReq[index_of_CSU_Name];
        Fill_Cell(CSU_Name, SHEET_A0, CELL_ROW_4, CELL_COL_3);//CSU Name Filling
        Fill_Cell(CSU_Name, SHEET_A0, CELL_ROW_15, CELL_COL_2);//CSU Name Filling

        String CSC_Name=CSU_Name.substring(0,CSU_Name.indexOf("_"));
        Fill_Cell(CSC_Name, SHEET_A0, CELL_ROW_3, CELL_COL_3);//CSC Name Filling



        Fill_Cell(fileName, SHEET_A0, CELL_ROW_8, CELL_COL_2);//Reference Documents Filling
        Fill_Cell("1C", SHEET_A0, CELL_ROW_8, CELL_COL_3);//Version of Documents Filling


    }


}
