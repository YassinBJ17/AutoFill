package SUTC.file.A1_Sheet;
import SUTC.file.Services.Excel;

import java.text.SimpleDateFormat;
import java.util.Date;

import static SUTC.file.Services.ExcelModifier.Fill_Cell;

public class A1_ExcelSheet {


    private static String documentHistoryDate(){
        Date date = new Date();
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        return formatter.format(date);
    }


    public static void A1_sheet(String userName){

        Fill_Cell(documentHistoryDate(), Excel.SHEET_A1,Excel.CELL_ROW_3,Excel.CELL_COL_2); // Date Filling

        userName=userName.charAt(0) + "." + userName.substring(1);
        Fill_Cell(userName,Excel.SHEET_A1,Excel.CELL_ROW_3,Excel.CELL_COL_3);//Author Filling

    }


}
