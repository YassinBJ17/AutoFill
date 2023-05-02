package excel.file.A1;
import excel.file.Services.Excel;

import java.text.SimpleDateFormat;
import java.util.Date;

import static excel.file.Services.ExcelModifier.Fill_Cell;

public class A1_sheet {

    public A1_sheet(String userName){

        Date date = new Date();
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        String strDate= formatter.format(date);

        Fill_Cell(strDate, Excel.SHEET_A1,Excel.CELL_ROW_3,Excel.CELL_COL_2);
        Fill_Cell(userName,Excel.SHEET_A1,Excel.CELL_ROW_3,Excel.CELL_COL_3);
    }


}
