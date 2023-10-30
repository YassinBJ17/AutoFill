package file.sutc.Commun;

import org.apache.poi.ss.usermodel.WorkbookFactory;

import java.io.FileInputStream;

import static file.commun.GraphicUserInterfaces.Error_interface;
import static file.commun.LoggerInitialize.log4Error;
import static file.sutc.B1_Sheet.B1_ExcelSheet.END_OF_SHEET_POSITION;
import static file.sutc.Commun.ExcelRowsAndColsConstants.SHEET_B1_INDEX;
import static file.sutc.SutcCreationProcess.templateXLSfile;
import static file.sutc.SutcCreationProcess.workbook;

public class OpenCloseExcelTemplate {

    public static void openExcelTemplate(){

        String SUTC_template= "../AutoFill/src/Template/SUTC TEMPLATE.xls";

        try {
            templateXLSfile = new FileInputStream(SUTC_template);// open template
            workbook = WorkbookFactory.create(templateXLSfile);
            END_OF_SHEET_POSITION =workbook.getSheetAt(SHEET_B1_INDEX).getLastRowNum();
        } catch (Exception e){
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );
            Error_interface(String.valueOf(e));

        }
    }

    public static void closeExcelTemplate(){


        try {
            templateXLSfile.close();// Close XLS to

        } catch (Exception e){
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );
            Error_interface(String.valueOf(e));
        }

    }

}
