package file.commun;

import org.apache.poi.ss.usermodel.*;
import org.apache.poi.ss.util.CellRangeAddress;
import org.apache.poi.ss.util.CellRangeAddressList;

import static file.commun.LoggerInitialize.log4Error;
import static file.sutc.Commun.ExcelManipulation.MergeCols;
import static file.sutc.Commun.ExcelManipulation.MergeRows;
import static file.sutc.Commun.ExcelRowsAndColsConstants.SHEET_B1_INDEX;
import static file.sutc.SutcCreationProcess.numberOfUFT;
import static file.sutc.SutcCreationProcess.workbook;

public class ExcelFormatMaintenance {


    static String[] objectType = {"Define constant", "Type", "Variable"};
    static String[] inputOutput = {"In", "Out", "In/Out"};
    static String[] access = {"R", "W", "R/W"};
    static String[] stubInputOutput = {"_in","_inout", "_out", "_no"};

    static String[] valideInvalide = {"V","I"};
    static String[] stubReturn = {"Return"};


    public static void excelFormatMaintenance(){
        Sheet sheet = workbook.getSheetAt(2);

        int startRange = getObjectTypeLine(sheet)+1;
        int endRange = getObjectTypeEnd(sheet);

        DataValidationHelper validationHelper = sheet.getDataValidationHelper();

        CellRangeAddressList objectTypePosition = new CellRangeAddressList(startRange, endRange,1, 1); // Cell A1 for example
        DataValidationConstraint objectTypeList = validationHelper.createExplicitListConstraint(objectType);

        DataValidation dataValidation = validationHelper.createValidation(objectTypeList, objectTypePosition);
        sheet.addValidationData(dataValidation);

        // Select B1
        sheet = workbook.getSheetAt(4);
        startRange=numberOfUFT+11;
        endRange=getAccessPosition(sheet);

        CellRangeAddressList objectInputOutput = new CellRangeAddressList(startRange,endRange-2, 3, 3); // Cell A1 for example
        DataValidationConstraint InputOutputList = validationHelper.createExplicitListConstraint(inputOutput);
        dataValidation = validationHelper.createValidation(InputOutputList, objectInputOutput);
        sheet.addValidationData(dataValidation);

        startRange=endRange+1;
        endRange=getStubDefinitionPosition(sheet);

        CellRangeAddressList accessObject = new CellRangeAddressList(startRange, endRange, 3, 3); // Cell A1 for example
        DataValidationConstraint accessList = validationHelper.createExplicitListConstraint(access);
        dataValidation = validationHelper.createValidation(accessList, accessObject);
        sheet.addValidationData(dataValidation);
        startRange=numberOfUFT+11;

        setStubInputOutput(sheet,endRange+5);
        setValideInvalide(sheet,startRange);
        mergeGreyCells(sheet,endRange+5);


    }

    private static void mergeGreyCells(Sheet sheet,int start) {

        int mergeStart=0,mergeEnd = 0;
        for (int i = start; i <= sheet.getLastRowNum(); i++) {
            Cell cell = sheet.getRow(i).getCell(1); // Assuming column index 1 (column D)
            if (cell != null) {
                if (cell.getStringCellValue().equals("Stub Parameters")) {
                    mergeStart=i+2;
                } else if (cell.getStringCellValue().equals("End of Stub")) {
                    mergeEnd=i;

                    String string_range= (char) (69)+""+(mergeStart)+":"+(char) (70)+mergeEnd;

                    CellRangeAddress range = CellRangeAddress.valueOf(string_range);
                    sheet.addMergedRegion(range);

                }
            }

        }
    }
    private static void setStubInputOutput(Sheet sheet,int start) {

        DataValidationHelper validationHelper = sheet.getDataValidationHelper();

        for (int i = start; i <= sheet.getLastRowNum(); i++) {
            Cell cell = sheet.getRow(i).getCell(3); // Assuming column index 1 (column D)
            if (cell != null) {
                if (cell.getStringCellValue().equals("Return")) {

                    CellRangeAddressList inputOutputStubObject = new CellRangeAddressList(i,i , 3, 3); // Cell A1 for example
                    DataValidationConstraint inputOutputStubList = validationHelper.createExplicitListConstraint(stubReturn);
                    DataValidation dataValidation = validationHelper.createValidation(inputOutputStubList, inputOutputStubObject);
                    sheet.addValidationData(dataValidation);
                }

                else
                {

                    CellRangeAddressList inputOutputStubObject = new CellRangeAddressList(i,i , 3, 3); // Cell A1 for example
                    DataValidationConstraint inputOutputStubList = validationHelper.createExplicitListConstraint(stubInputOutput);
                    DataValidation dataValidation = validationHelper.createValidation(inputOutputStubList, inputOutputStubObject);
                    sheet.addValidationData(dataValidation);

                }
            }
        }
    }

    private static void setValideInvalide(Sheet sheet,int start){

        System.out.println(start);
        DataValidationHelper validationHelper = sheet.getDataValidationHelper();

        for (int i = start; i <= sheet.getLastRowNum(); i++) {
            Cell cell = sheet.getRow(i).getCell(7); // Assuming column index 1 (column D)
            if (cell!=null)
                if (!cell.getStringCellValue().isEmpty()){
                    CellRangeAddressList valideInvalideObject = new CellRangeAddressList(i,i , 7, 7); // Cell A1 for example
                    DataValidationConstraint valideInvalideList = validationHelper.createExplicitListConstraint(valideInvalide);
                    DataValidation dataValidation = validationHelper.createValidation(valideInvalideList, valideInvalideObject);
                    sheet.addValidationData(dataValidation);
                }
        }

    }

    private static int getStubDefinitionPosition(Sheet sheet) {


        for (int i = numberOfUFT+11; i <= 200; i++) {
            Cell cell = sheet.getRow(i).getCell(1); // Assuming column index 1 (column D)
            if (cell != null) {
                if (cell.getStringCellValue().equals("Stub Definition")) {
                    return i;
                }
            }
        }
        return 0;
    }
    private static int getAccessPosition(Sheet sheet) {
        for (int i = numberOfUFT+11; i <= 110; i++) {
            Cell cell = sheet.getRow(i).getCell(3); // Assuming column index 1 (column B)
            if (cell != null) {
                if (cell.getStringCellValue().equals("Access")) {
                    return i;
                }
            }
        }
        return 0;
    }
    private static int getObjectTypeLine(Sheet sheet) {

        for (int i = 3; i < 60; i++) {
            Cell cell = sheet.getRow(i).getCell(1); // Assuming column index 1 (column B)
            if (cell != null) {
                if (cell.getStringCellValue().equals("Object type")) {
                    return i;
                }
            }
        }
        return 0;
    }
    private static int getObjectTypeEnd(Sheet sheet) {
        for (int i = 3; i < 60; i++) {
            Cell cell = sheet.getRow(i).getCell(1); // Assuming column index 1 (column B)
            if (cell != null) {
                if (cell.getStringCellValue().equals("End of Global Definition")) {
                    return i;
                }
            }
        }
        return 0;
    }


}


