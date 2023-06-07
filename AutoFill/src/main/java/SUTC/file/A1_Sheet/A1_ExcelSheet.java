package SUTC.file.A1_Sheet;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import static SUTC.file.COMMUN.ExcelModifier.Fill_Cell;

public class A1_ExcelSheet {


    private static String documentHistoryDate(){
        Date date = new Date();
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        return formatter.format(date);
    }


    public static void A1_sheet(String userName){

        Fill_Cell(documentHistoryDate(), SHEET_A1, CELL_ROW_3, CELL_COL_2); // Date Filling

        userName=userName.charAt(0) + "." + userName.substring(1);
        Fill_Cell(userName, SHEET_A1, CELL_ROW_3, CELL_COL_3);//Author Filling

    }


}
