package file.sutc.B1_Sheet.DataDictionarySearch;
import java.io.File;
import java.io.FileInputStream;
import java.util.Iterator;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.CellType;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.xssf.usermodel.*;

import static file.commun.GraphicUserInterfaces.Error_interface;
import static file.commun.LoggerInitialize.log4Debug;
import static file.commun.LoggerInitialize.log4Error;

public class DataDictionary {

    public static String[] Types_array = {
            "uint8_t",
            "uint16_t",
            "uint32_t",
            "uint64_t",
            "boolean_t",
            "float32_t",
            "float64_t"   };


    public static String searchExcelFiles(String directoryPath, String searchString,boolean global){
        // string to store the matching rows
        String matchingRows = "";

        // get all the files in the directory
        File directory = new File(directoryPath);
        File[] files = directory.listFiles();
    try {


        assert files != null;
        for (File file : files) {
            if (file.isFile() && file.getName().endsWith(".xlsx")) {

                FileInputStream fileInputStream = new FileInputStream(file);
                XSSFWorkbook workbook = new XSSFWorkbook(fileInputStream);
                int numberOfSheets = workbook.getNumberOfSheets();
                // iterate through all sheets in the workbook
                for (int i = 0; i < numberOfSheets; i++) {
                    Sheet sheet = workbook.getSheetAt(i);
                    // iterate through all rows in the sheet
                    for (Row row : sheet) {
                        Iterator<Cell> cellIterator = row.cellIterator();
                        // iterate through all cells in the row
                        while (cellIterator.hasNext()) {
                            Cell cell = cellIterator.next();
                            // check if the cell contains the search string
                            if (cell.getCellType() == CellType.STRING && cell.getStringCellValue().trim().equalsIgnoreCase(searchString.trim())) {
                                // find the 4th cell in the row and print its value
                                Cell fourthCell = row.getCell(3);
                                Cell secondCell = row.getCell(1);
                                log4Debug(searchString + " in file " + file.getName() + ", sheet " + sheet.getSheetName() +", type:\n" + fourthCell.getStringCellValue());
                                matchingRows = secondCell.getStringCellValue();

                                if((matchingRows.equalsIgnoreCase("STRUCT"))||(matchingRows.equalsIgnoreCase("UNION"))) {
                                    matchingRows= "-";
                                }
                                else {
                                    if (!global)
                                        matchingRows = fourthCell.getStringCellValue();

                                }
                            }
                        }
                    }
                }
                workbook.close();
                fileInputStream.close();
            }
        }

        // return the matching rows
        return matchingRows;
    } catch (Exception e){

        String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
        log4Error(methodName+" : "+e.getMessage() );
        Error_interface(String.valueOf(e));
    }
    return "";
    }

    public static String DataDictionarySearch(String ParameterToSearch, boolean global){
        // specify the directory path
        String directoryPath = "../Datafiles/DD";

        // search for the string in the Excel files in the directory and print the matching rows

        if (ParameterToSearch.contains(".")||ParameterToSearch.contains("->")) {
            int index;
            index=ParameterToSearch.indexOf("->");

            if (index==-1)
                index=ParameterToSearch.indexOf(".");

            ParameterToSearch = ParameterToSearch.substring(0,index);
        }

        String matchingRows = searchExcelFiles(directoryPath, ParameterToSearch,global);
        if (matchingRows.equals("")) {
            return "not exist in the DD";
        }
        return matchingRows;
    }
}


