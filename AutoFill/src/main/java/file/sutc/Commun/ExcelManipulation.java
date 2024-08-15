package file.sutc.Commun;
import org.apache.poi.ss.util.CellRangeAddress;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.*;

import static file.commun.LoggerInitialize.log4Debug;
import static file.commun.LoggerInitialize.log4Error;
import static file.sutc.SutcCreationProcess.workbook;


public class ExcelManipulation {

    public static String deleteExtraReturnLine(String requirement) {
        requirement = requirement.replaceAll("^(\\n)+", ""); // Remove leading newlines
        requirement = requirement.replaceAll("(\\n)+$", ""); // Remove trailing newlines
        return requirement;
    }

    public static boolean Search(String[] array, String word) {
        if (array==null)
            return false;

        for (String element : array) {
            if (element == null)
                continue;

            if (element.trim().equalsIgnoreCase(word.trim())) {
                return true;
            }
        }
        return false;
    } // simple search function
    public static CellStyle Fill_Cell_Red(){

        CellStyle style = workbook.createCellStyle();
        Font font = workbook.createFont();
        //font.setColor(IndexedColors.RED.getIndex());
        style.setVerticalAlignment(VerticalAlignment.CENTER);
        style.setAlignment(HorizontalAlignment.CENTER);
        style.setBorderBottom(BorderStyle.THIN);
        style.setBorderTop(BorderStyle.THIN);
        style.setBorderLeft(BorderStyle.THIN);
        style.setBorderRight(BorderStyle.THIN);
        style.setFont(font);

        return style;
    } // format of not found message

    public  static void CorrectAlign(int sheet, int row, int cel){

        Sheet s = workbook.getSheetAt(sheet);
        Cell cell = s.getRow(row).getCell(cel);
        CellStyle existingStyle = cell.getCellStyle();
        CellStyle newStyle = workbook.createCellStyle();
        newStyle.cloneStyleFrom(existingStyle); // Copy the existing style to the new style
        newStyle.setAlignment(HorizontalAlignment.LEFT); // Set the desired alignment
        cell.setCellStyle(newStyle); // Apply the new style to the cell

    }

    public static void Fill_Cell(String text,int sheet, int row, int cell) { // filling one specific cell

        //System.out.println(row+"-"+cell);
        Sheet s = workbook.getSheetAt(sheet);
            Row r = s.getRow(row);
            Cell c = r.getCell(cell);
            c.setCellValue(text);

            if ((text.equals("not exist in the DD"))||(text.equals("not exist in the Code")))
                c.setCellStyle(Fill_Cell_Red());

          /*  } catch (NullPointerException e) {
                String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                log4Error(methodName+" : "+e.getMessage() +" ["+row+","+cell+"] Sheet: "+sheet );
        }*/
    } // filling simple cell
    public static void removeExtraRows(int sheet, int start, int end) {
        try {
            Sheet s = workbook.getSheetAt(sheet);
            for (int i = start; i < end; i++) {
                Row r = s.getRow(i);
                if (r != null) {
                    s.removeRow(r);
                }
            }
        } catch (NullPointerException e) {
            // handle the exception here
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );
        }
    }

    public static void addThickOutsideBorder(int sheet,int row,int col){

        Cell cell=workbook.getSheetAt(sheet).getRow(row).getCell(col);
        CellStyle originalStyle = cell.getCellStyle();

        // Create a new style based on the original style
        CellStyle newStyle = workbook.createCellStyle();
        newStyle.cloneStyleFrom(originalStyle);

        // Set the thick border for the new style
        newStyle.setBorderTop(BorderStyle.MEDIUM);
        newStyle.setBorderBottom(BorderStyle.MEDIUM);
        newStyle.setBorderLeft(BorderStyle.MEDIUM);
        newStyle.setBorderRight(BorderStyle.MEDIUM);

        cell.setCellStyle(newStyle);
    }
    public static void MergeRows(int sheetNumber, int start_col, int start_row, int end_row) {

        Sheet sheet= workbook.getSheetAt(sheetNumber);


        String string_range= (char) (start_col + 65)+""+(start_row)+":"+(char) (start_col + 65)+end_row;
        //System.out.println(string_range);
        CellRangeAddress range = CellRangeAddress.valueOf(string_range);
        sheet.addMergedRegion(range);




    } // merge an interval of cells

    public static String toExcelColumn(int columnNumber) {
        StringBuilder columnName = new StringBuilder();
        columnNumber++; // Adjust for zero-indexed input

        while (columnNumber > 0) {
            int remainder = (columnNumber - 1) % 26;
            columnName.insert(0, (char) (remainder + 'A'));
            columnNumber = (columnNumber - 1) / 26;
        }

        return columnName.toString();
    }

    public static void MergeCols(int sheet, int start_col, int start_row, int end_cols) {

        Sheet s= workbook.getSheetAt(sheet);
        String string_range= toExcelColumn(start_col )+""+(start_row)+":"+ toExcelColumn(end_cols)+start_row;

        try {
            CellRangeAddress range = CellRangeAddress.valueOf(string_range);
            s.addMergedRegion(range);
        }catch (Exception e)
        {
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );
        }

    } // merge an interval of cells

    public static String reqModifier(String s) {
        log4Debug(s);

        s = s.replaceAll("(?i)\\]: (?:Set|set) ", " by setting ");


        // Replace multiple successive newlines with a single newline
        s = s.replaceAll("\\n{2,}", "\n");

        // Replace multiple successive spaces with a single space
        s = s.replaceAll(" {2,}", " ");

        s = s.replace("]:", "");
        s = s.replace("] :", " ");
        s = s.replace("] by setting", " by setting");
        s = s.replaceAll("(?i)( corresponds to the following call| corresponds to the call)", " by calling ");
        s = s.replaceAll("(?i)(corresponds to the following call|corresponds to the call)", " by calling ");
        s = s.replaceAll("(?i)( corresponds to the following CALL| corresponds to the call)", " by calling ");
        s = s.replaceAll("(?i)(corresponds to the following CALL|corresponds to the call)", " by calling ");
        s = s.replace("] by calling", " by calling");

        log4Debug(s);
    /*
        if (s.contains("["))
        {
            String s1=s;
            try {
                 s1=s.substring(s.indexOf("["),s.lastIndexOf("]"));
            }catch (StringIndexOutOfBoundsException e) {

                log4Error("Substring in square brackets not found.");
            }

            if ((s1.trim().split("\\s").length>1)||(s1.equalsIgnoreCase("index i"))) {
               s = s.replace("[", "");
                s = s.replace("]", "");
            }


        }  */


        return s;
    } // formatting STUB

    public static String CauseModifier(String s){

        s=s.replaceAll("\n", "");
        s=s.replace("[", "");
        s=s.replace("]", "");
        return s;
    }
    public static String Include_Modifier(String s){

        s=s.replace("#include \"", "");
        s=s.replace("\"", "");
        s=s.substring(s.lastIndexOf('/')+1);
        return s.trim();
    }
    public static String llrTraceability(String[] LLR){

        for (int i = 0; i < LLR.length ; i++) {
        if (LLR[i].contains("REQUIREMENTS")){
                return  LLR[i+1].substring(0, LLR[i+1].length()-1);
            }
        }
        return "";
    }
    public static String[] Parameters_Detect(String str) {
        str=str.replace("const","");
        str=str.replace("CONST","");
        String[] words = str.split("\\s+"); // Split the string into words
        String[] reversed = new String[words.length];
        int index = 0;
        for (int i = words.length - 1; i >= 0; i--) {
                reversed[index] = words[i];
                index++;

        }
        return reversed; // Return the reversed array of words
    }
    public static boolean Prototype_Detect(String line, String fct_name){

        line=line.toLowerCase();
        fct_name=fct_name.toLowerCase().trim();

        return  ((line.contains(fct_name+"("))||(line.contains(fct_name+" (")))&&(!(line.contains("#")));

    }


}


