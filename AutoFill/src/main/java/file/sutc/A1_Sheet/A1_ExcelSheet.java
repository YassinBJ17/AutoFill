package file.sutc.A1_Sheet;
import static file.sutc.Commun.ExcelRowsAndColsConstants.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import static file.sutc.Commun.ExcelManipulation.Fill_Cell;

public class A1_ExcelSheet {


    private static String documentHistoryDate(){
        Date date = new Date();
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        return formatter.format(date);
    }


    public static void fillingA1Sheet(String userName){

        Fill_Cell(documentHistoryDate(), SHEET_A1_INDEX, CELL_ROW_3, CELL_COL_2); // Date Filling

        userName=userName.charAt(0) + "." + userName.substring(1);
        Fill_Cell(userName, SHEET_A1_INDEX, CELL_ROW_3, CELL_COL_3);//Author Filling

    }


}
