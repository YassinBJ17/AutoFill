package customisedMacro;

import org.apache.poi.ss.usermodel.WorkbookFactory;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

import static file.commun.GraphicUserInterfaces.*;
import static file.commun.LoggerInitialize.log4Error;
import static file.sutc.Commun.ExcelManipulation.Fill_Cell;
import static file.sutc.SutcCreationProcess.workbook;

public class CustoMacro {



    public static void customisedMacro(String directoryPath,String version,String date) throws IOException {

        File directory = new File(directoryPath);
        if (!directory.exists() || !directory.isDirectory()) {
            System.err.println("Invalid directory path.");
            return ;
        }



        File[] files = directory.listFiles();

        assert files != null;
        for (File file : files) {
            if (file.isDirectory()) {
                // Recursively search in subdirectories
                customisedMacro(file.getAbsolutePath(),version,date);

            } else {
                if (file.getName().endsWith(".xls")) {
                    // If the file is a .h file, search for the function prototype
                    System.out.println(file.getAbsolutePath());
                    Update(file,version,date);

                }
            }
        }

    }

    private static void Update(File file,String version , String date) throws IOException {
        FileInputStream XLSfile ;

        try {
            XLSfile = new FileInputStream(file);// open template
            workbook = WorkbookFactory.create(XLSfile);

        } catch (Exception e){
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );
            Error_interface(String.valueOf(e));

        }

        /*Sheet s = workbook.getSheetAt(SHEET_A0_INDEX);
        Cell c = s.getRow(2).getCell(3);
        if (c.getCellType() == CellType.BLANK)
            return;*/




        Fill_Cell("DD",0 ,8 ,2   ); // SDDD Name
        Fill_Cell("TEST",0 ,8 ,3 ); // SDDD Version



        Fill_Cell("1", 1,8 ,3 );


        FileOutputStream outputStream = new FileOutputStream(file);
        workbook.write(outputStream);
        outputStream.close();



    }


}
