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

    public static String searchExcelFiles(String directoryPath, String searchString,int searchForType){

        String matchingRows = "";         // string to store the matching rows
        File directory = new File(directoryPath);
        File[] files = directory.listFiles();
    try {

        assert files != null;
        for (File file : files) {
            if (file.isFile() && file.getName().endsWith(".xlsx")) {

                FileInputStream fileInputStream = new FileInputStream(file);
                XSSFWorkbook workbook = new XSSFWorkbook(fileInputStream);
                int numberOfSheets = workbook.getNumberOfSheets();
                for (int i = 0; i < numberOfSheets; i++) {
                    Sheet sheet = workbook.getSheetAt(i);

                    for (Row row : sheet) {
                        Iterator<Cell> cellIterator = row.cellIterator();

                        while (cellIterator.hasNext()) {
                            Cell cell = cellIterator.next();

                            if (cell.getCellType() == CellType.STRING && cell.getStringCellValue().trim().equalsIgnoreCase(searchString.trim())) {
                                Cell fourthCell = row.getCell(3);
                                Cell thirdCell = row.getCell(2);
                                Cell secondCell = row.getCell(1);

                                  matchingRows = secondCell.getStringCellValue();

                                if((matchingRows.equalsIgnoreCase("STRUCTURE"))||(matchingRows.equalsIgnoreCase("STRUCT"))||(matchingRows.equalsIgnoreCase("UNION"))) {
                                    matchingRows= "-";
                                }
                                else {
                                    if (searchForType==0)
                                        matchingRows = fourthCell.getStringCellValue(); // return Domain
                                else if (searchForType==2)
                                        if (thirdCell.getCellType() == CellType.STRING) {
                                            matchingRows = thirdCell.getStringCellValue(); // return array dimension
                                        } else {
                                            matchingRows = String.valueOf(thirdCell.getNumericCellValue());
                                        }


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
    public static String DataDictionarySearch(String ParameterToSearch, int searchForType){
        // specify the directory path
        String directoryPath = "../Datafiles/DD";

        // search for the string in the Excel files in the directory and print the matching rows

        ParameterToSearch=removeExtraCharacters(ParameterToSearch); // like * [ ]

        String matchingRows = searchExcelFiles(directoryPath, ParameterToSearch,searchForType);
        if (matchingRows.equals("")) {
            return "not exist in the DD";
        }
        return matchingRows;
    }

    private static String removeExtraCharacters(String ParameterToSearch) {

        if (ParameterToSearch.contains(".")||ParameterToSearch.contains("->")) {
            int index;
            index=ParameterToSearch.indexOf("->");

            if (index==-1)
                index=ParameterToSearch.indexOf(".");

            ParameterToSearch = ParameterToSearch.substring(0,index);
        }
            ParameterToSearch=ParameterToSearch.replace("Array of ","");
            ParameterToSearch=ParameterToSearch.replace("[","");
            ParameterToSearch=ParameterToSearch.replace("]","");
            ParameterToSearch=ParameterToSearch.replace("*","");

            return ParameterToSearch.trim();

    }
}


