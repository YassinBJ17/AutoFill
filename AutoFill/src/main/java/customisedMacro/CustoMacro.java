package customisedMacro;

import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.CellType;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.WorkbookFactory;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Objects;

import static Commun.GraphicUserInterfaces.Error_interface;
import static Commun.LoggerInitialize.log4Error;
import static SUTC.file.Commun.ExcelManipulation.Fill_Cell;
import static SUTC.file.Commun.ExcelRowsAndColsConstants.*;
import static SUTC.file.SutcCreationProcess.workbook;

public class CustoMacro {



    public static void customisedMacro(String directoryPath) throws IOException {

        File directory = new File(directoryPath);
        if (!directory.exists() || !directory.isDirectory()) {
            log4Error("Invalid directory path.");
            return ;
        }

        File[] files = directory.listFiles();

        assert files != null;
        for (File file : files) {
            if (file.isDirectory()) {
                // Recursively search in subdirectories
                customisedMacro(file.getAbsolutePath());

            } else {
                if (file.getName().endsWith(".xls")) {
                    // If the file is a .h file, search for the function prototype
                    System.out.println(file.getAbsolutePath());
                    Update(file);

                }
            }
        }

    }

    private static void Update(File file) throws IOException {
        FileInputStream XLSfile ;

        try {
            XLSfile = new FileInputStream(file);// open template
            workbook = WorkbookFactory.create(XLSfile);

        } catch (Exception e){
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );
            Error_interface(String.valueOf(e));

        }

        Sheet s = workbook.getSheetAt(SHEET_A0_INDEX);
        Cell c = s.getRow(2).getCell(3);
        if (c.getCellType() == CellType.BLANK)
            return;

        Fill_Cell("1E", SHEET_A0_INDEX,8 ,3 );
        Fill_Cell("17/07/2023", SHEET_A1_INDEX,3 ,2 );


        FileOutputStream outputStream = new FileOutputStream(file);
        workbook.write(outputStream);
        outputStream.close();



    }


}
