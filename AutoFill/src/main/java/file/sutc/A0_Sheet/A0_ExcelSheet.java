package file.sutc.A0_Sheet;
import static file.commun.BrowsingInputFolder.DD_Version;
import static file.sutc.Commun.OpenCloseExcelTemplate.openExcelTemplate;
import static file.sutc.Commun.ExcelManipulation.Fill_Cell;
import static file.commun.BrowsingInputFolder.designFileName;
import static file.sutc.Commun.ExcelRowsAndColsConstants.*;
import static file.sutc.SutcCreationProcess.*;

public class A0_ExcelSheet {


    public static String getSDDD_Version(String textFromSDDD ){

        String ret ;
        //System.out.println(textFromSDDD);
        ret = textFromSDDD.substring(textFromSDDD.indexOf("~")+1);
        ret=ret.substring(0,ret.indexOf(":"));
        //System.out.println(ret);
        return ret;

    }

    public static String getCSC_Name(String textFromSDDD ){

        String ret ;
        ret = textFromSDDD.substring(textFromSDDD.indexOf("_SDDD-")+1);
        ret=ret.substring(5,ret.indexOf("."));

        return ret;
    }

    public static void fillingA0Sheet(){


        openExcelTemplate();

        String File_Name= functionName + ".c";
        Fill_Cell(File_Name, SHEET_A0_INDEX, CELL_ROW_2, CELL_COL_3);// File Name Filling

        String CSU_Name= functionName;
        Fill_Cell(CSU_Name, SHEET_A0_INDEX, CELL_ROW_4, CELL_COL_3);//CSU Name Filling
        Fill_Cell(CSU_Name, SHEET_A0_INDEX, CELL_ROW_15, CELL_COL_2);//CSU Name Filling

        Fill_Cell(CSC_Name.toUpperCase(), SHEET_A0_INDEX, CELL_ROW_3, CELL_COL_3);//CSC Name Filling

        Fill_Cell(designFileName, SHEET_A0_INDEX, CELL_ROW_8, CELL_COL_2);//Reference Documents Filling
        Fill_Cell(SDDD_Version, SHEET_A0_INDEX, CELL_ROW_8, CELL_COL_3);//Version of Documents Filling

        //Fill_Cell("FADEX-OVSP_SDDD-DD.xlsx", SHEET_A0_INDEX, CELL_ROW_9, CELL_COL_2);//Reference Documents Filling
        Fill_Cell("FADEX-OSS_PU_SDDD-DD.xlsx", SHEET_A0_INDEX, CELL_ROW_9, CELL_COL_2);//Reference Documents Filling
        Fill_Cell(DD_Version , SHEET_A0_INDEX, CELL_ROW_9, CELL_COL_3);//Version of Documents Filling

      //   Fill_Cell(File_Name, SHEET_A0_INDEX, CELL_ROW_10, CELL_COL_2);//Reference Documents Filling
      //  Fill_Cell("1.0.1", SHEET_A0_INDEX, CELL_ROW_10, CELL_COL_3);


    }


}
