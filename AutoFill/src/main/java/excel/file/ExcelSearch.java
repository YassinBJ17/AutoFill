package excel.file;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Iterator;

import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.CellType;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.xssf.usermodel.*;

public class ExcelSearch {

    public static String[] Types_array = {
            "uint8_t",
            "uint16_t",
            "uint32_t",
            "uint64_t",
            "boolean_t",
            "float32_t",
            "float64_t"};

    public static boolean searchType(String[] array, String word) {
        for (String element : array) {
            if (word.contains(element)) {
                return true;
            }
        }
        return false;
    }

    public static String searchExcelFiles(String directoryPath, String searchString,boolean global) throws IOException {
        // string to store the matching rows
        String matchingRows = "";

        // get all the files in the directory
        File directory = new File(directoryPath);
        File[] files = directory.listFiles();



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
                                //   System.out.println(searchString + " in file " + file.getName() + ", sheet " + sheet.getSheetName() +", type:\n" + fourthCell.getStringCellValue());


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
    }

    public static String SearchFromDD(String ParameterToSearch, boolean global) throws IOException {
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


