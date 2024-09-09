package file.sutc.B0_Sheet;

import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static file.commun.GraphicUserInterfaces.Error_interface;
import static file.sutc.B1_Sheet.Commun.RemoveExtraColumn.removeExtraCols;
import static file.sutc.Commun.LongTextDivider.*;
import static file.sutc.Commun.ExcelManipulation.*;
import static file.sutc.Commun.ExcelRowsAndColsConstants.*;
import static file.commun.LoggerInitialize.*;
import static file.sutc.Commun.utcUftNumberCounter.numberOfCauses;
import static file.sutc.SutcCreationProcess.*;

public class B0_ExcelSheet {

    public static final int CAUSES_TABLE_POSITION = 2;
    public static final int EFFECT_TABLE_POSITION = 43;
    public static final int NUMBER_OF_EMPTY_CELL = 40;
    public static final int END_OF_SHEET = 84;
    private static void HeaderFilling() {
        Fill_Cell("Unit Functional Tests for: " + functionName, SHEET_B0_INDEX, CELL_ROW_0, CELL_COL_2);
    }
    private static int CausesFilling(){
        int number_of_causes = 1;

        Set<String> set = new LinkedHashSet<>(causesTable);

        causesTable = new ArrayList<>(set);

        for (String cause : causesTable) {
           // System.out.println(cause);
            if (!(Objects.equals(cause, "null"))) {

                cause = cause.replaceAll("\\n{2,}", "\n"); // delete extra line-return

                if (cause.startsWith("(") && cause.endsWith(")")) {
                    cause = cause.substring(1, cause.length() - 1);
                }

                Fill_Cell(cause, SHEET_B0_INDEX, number_of_causes + CAUSES_TABLE_POSITION, CELL_COL_2);
                number_of_causes++;
            }
        }
        return number_of_causes ;
    }
    private static int EffectFilling() {
        int number_of_effects = 1;

        Set<String> set = new LinkedHashSet<>(effectsTable);
        effectsTable = new ArrayList<>(set);

        for (String effect : effectsTable) {
            effect = effect.replace("CALL ","\nCALL ");
            effect = effect.replace("Set ","\nSet ");
            effect = effect.replaceFirst("^\\n", "");// delete the first character from a string if it is equal to a newline character (\n)
            effect = effect.replace("\n\n", "\n"); // delete extra line return

            //  if (effect.split("\n").length  < MAX_LINE_PER_EFFECT_CELL) {
                Fill_Cell(effect, SHEET_B0_INDEX, number_of_effects + EFFECT_TABLE_POSITION, CELL_COL_2);
                number_of_effects++;
           /* } else {
                List<String> effects = divideLongText(effect);
                for (String dividedEffect : effects) {
                    Fill_Cell(dividedEffect, SHEET_B0_INDEX, number_of_effects + EFFECT_TABLE_POSITION, CELL_COL_2);
                    number_of_effects++;
                }
            }*/
        }
        return number_of_effects;
    }
    private static void removeExtraCells(int number_of_effects){


        if (numberOfCauses == 1)
            for (int i = 1; i < number_of_effects; i++) {
                Fill_Cell("X", SHEET_B0_INDEX, EFFECT_TABLE_POSITION+i, CELL_COL_3);
            }

        if (number_of_effects==1)
        {
            Fill_Cell("N/A", SHEET_B0_INDEX, EFFECT_TABLE_POSITION+1, CELL_COL_2);
            number_of_effects=2;
        }

        removeExtraRows(SHEET_B0_INDEX, EFFECT_TABLE_POSITION + number_of_effects, END_OF_SHEET); // Remove Extra Effect Rows

        for (int i=0;i<20-numberOfUFT;i++)
            removeExtraCols(SHEET_B0_INDEX,numberOfUFT+CELL_COL_3);
        MergeCols(SHEET_B0_INDEX, CELL_COL_2, CELL_ROW_1, numberOfUFT+CELL_COL_6 );// Merge Header
        for (int i=2;i<=numberOfUFT+CELL_COL_6;i++)
            addThickOutsideBorder(SHEET_B0_INDEX, CELL_ROW_0, i);


        if (numberOfCauses == 1)   // Number of causes is 0
        {
            workbook.getSheetAt(SHEET_B0_INDEX).shiftRows(EFFECT_TABLE_POSITION, END_OF_SHEET, -(NUMBER_OF_EMPTY_CELL - numberOfCauses));  // Remove Extra Causes Rows
            Fill_Cell("N/A", SHEET_B0_INDEX, CELL_ROW_3, CELL_COL_3);
            Fill_Cell("N/A", SHEET_B0_INDEX, CELL_ROW_3, CELL_COL_2);

            if (number_of_effects > 2) {

                try {

                    MergeRows(SHEET_B0_INDEX, CELL_COL_3 + numberOfUFT, CELL_ROW_4 + 2, CELL_COL_2 + 2 + number_of_effects);// Merge LLR traceability
                }catch (Exception e){
                    String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                    log4Error(methodName+" : "+e.getMessage() );
                }


            }
        } else {
            workbook.getSheetAt(SHEET_B0_INDEX).shiftRows(EFFECT_TABLE_POSITION, END_OF_SHEET, -(NUMBER_OF_EMPTY_CELL - numberOfCauses + 1));

            if (numberOfCauses > 2)  // Number of causes is bigger than 1 cause

                try{
                MergeRows(SHEET_B0_INDEX, CELL_COL_3 + numberOfUFT, CELL_COL_4, CELL_COL_2 + numberOfCauses);// Merge LLR traceability
                }catch (Exception e){
                    String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                    log4Error(methodName+" : "+e.getMessage() );
                }

            if (number_of_effects > 2)
                try {
                MergeRows(SHEET_B0_INDEX, CELL_COL_3 + numberOfUFT, CELL_ROW_4 + numberOfCauses, CELL_COL_2 + numberOfCauses + number_of_effects);// Merge LLR traceability
        }catch (Exception e){
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );
        }
        }


        workbook.getSheetAt(SHEET_B0_INDEX).setColumnWidth(CELL_COL_3 + numberOfUFT,9000);


    }

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

                                    matchingRows = secondCell.getStringCellValue().trim();

                                    if((matchingRows.equalsIgnoreCase("STRUCTURE"))||(matchingRows.equalsIgnoreCase("STRUCT"))||(matchingRows.equalsIgnoreCase("UNION"))) {
                                        matchingRows= "-";
                                    }
                                    else {
                                        if (searchForType == 0)
                                            matchingRows = fourthCell.getStringCellValue(); // return Domain
                                        else if (searchForType == 2){
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
        public static String[] ExtractText( String input ) {

            // Regular expression to match text between a single pair of [ ]
            String regex = "\\[([^\\[\\]]+)]";

            Pattern pattern = Pattern.compile(regex);
            Matcher matcher = pattern.matcher(input);

            // List to hold the extracted content
            ArrayList<String> extractedTexts = new ArrayList<>();

            while (matcher.find()) {
                // Extract text between the brackets and add it to the list
                extractedTexts.add(matcher.group(1));
            }

            // Convert the ArrayList to an array

            return extractedTexts.toArray(new String[0]);
        }

    private static void FillTrueFalse() {
        String filePath = "../Datafiles/TF/UFT1.xls";
        File file = new File(filePath);
        String[] trueFalse = new String[0];

        try (FileInputStream fileInputStream = new FileInputStream(file);
             Workbook workbook = new HSSFWorkbook(fileInputStream)) {

            Sheet sheet = workbook.getSheetAt(0);
                Row row= sheet.getRow(1);
                Cell functionName = row.getCell(1);
                Cell testCases = row.getCell(3);

                if (functionName != null && testCases != null) {
                    String cell=testCases.getStringCellValue();
                    System.out.println(cell);
                    trueFalse=ExtractText (cell.substring(0,cell.indexOf("####")));
                }

                int i=0 ;
            for (String text : trueFalse) {
                System.out.println(text);
                Fill_Cell(text,SHEET_B0_INDEX,3+i,3);
                i++;
            }



        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void fillingB0Sheet() {

        int number_of_effects ;

        HeaderFilling();
        numberOfCauses=CausesFilling();
        number_of_effects=EffectFilling();
        //FillTrueFalse();
        removeExtraCells(number_of_effects);
        log4Info("B0 Sheet done");

    }



}
