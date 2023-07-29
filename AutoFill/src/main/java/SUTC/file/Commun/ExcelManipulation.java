package SUTC.file.Commun;
import org.apache.poi.ss.util.CellRangeAddress;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.*;

import static Commun.LoggerInitialize.log4Error;
import static SUTC.file.SutcCreationProcess.workbook;


public class ExcelManipulation {

    public static String Delete_extra_return_line(String requirement ){

        while (requirement.startsWith("\n"))  // check if the first character of a string is a newline character (\n).
            requirement = requirement.substring(1); // remove the first character

        while (requirement.endsWith("\n"))
            requirement = requirement.substring(0, requirement.length() - 1);

        return requirement;
    }
    public static boolean Search(String[] array, String word) {
        if (array==null)
            return false;

        for (String element : array) {
            if (element == null)
                continue;

            if (element.equalsIgnoreCase(word.trim())) {
                return true;
            }
        }
        return false;
    } // simple search function
    public static CellStyle Fill_Cell_Red(){

        CellStyle style = workbook.createCellStyle();
        Font font = workbook.createFont();
        font.setColor(IndexedColors.RED.getIndex());
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

        Sheet s = workbook.getSheetAt(sheet);

        try {

            Cell c = s.getRow(row).getCell(cell);
            c.setCellValue(text);
            if ((text.equals("not exist in the DD"))||(text.equals("not exist in the Code")))
                c.setCellStyle(Fill_Cell_Red());

            } catch (NullPointerException e) {
                String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                log4Error(methodName+" : "+e.getMessage() +" ["+row+","+cell+"] Sheet: "+sheet );
        }
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
    public static void MergeRows(int sheet, int start_col, int start_row, int end_row) {

        Sheet s= workbook.getSheetAt(sheet);
        String string_range= (char) (start_col + 65)+""+(start_row)+":"+(char) (start_col + 65)+end_row;
      //  System.out.println(string_range);
        CellRangeAddress range = CellRangeAddress.valueOf(string_range);

        try {
            s.addMergedRegion(range);
        }catch (Exception e)
        {
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );
         }

    } // merge an interval of cells
    public static void MergeCols(int sheet, int start_col, int start_row, int end_cols) {

        Sheet s= workbook.getSheetAt(sheet);
        String string_range= (char) (start_col + 65)+""+(start_row)+":"+(char) (end_cols + 65)+start_row;
        CellRangeAddress range = CellRangeAddress.valueOf(string_range);

        try {
            s.addMergedRegion(range);
        }catch (Exception e)
        {
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
            log4Error(methodName+" : "+e.getMessage() );
        }

    } // merge an interval of cells

    public static String StubCall_Requirements_Modifier(String s) {

        for (int i = 0; i < 10; i++) {
            s=s.replace("  "," ");
            s=s.replace("\n\n","\n");
        }
        s = s.replaceAll("(?i)(] corresponds to the following call|] corresponds to the call)", " by calling ");
        s = s.replaceAll("(?i)(]corresponds to the following call|]corresponds to the call)", " by calling ");

        s = s.replace("]:", "");
        s = s.replace("] :", " ");

        if (s.contains("["))
        {
            String s1=s.substring(s.indexOf("["),s.lastIndexOf("]"));
            if ((s1.trim().split("\\s+").length>1)||(s1.equalsIgnoreCase("index i"))) {
               s = s.replace("[", "");
                s = s.replace("]", "");
            }
        }

        return s;
    } // formatting STUB
    public static String SettingValue_req_Modifier(String s) {

        for (int i = 0; i < 10; i++) {
            s=s.replace("  "," ");
        }

        //s=s.replaceAll("\\n\\s*\\n", "\n");
        s=s.replace("]: Set", " by setting");
        s=s.replace("]: SET", " by setting");
        s=s.replace("]: set", " by setting");
        s=s.replace("] set", " by setting");
        s=s.replace("] Set", " by setting");
        s=s.replace("] SET", " by setting");
        s=s.replace(" Set {", "By setting {");


        return s;
    }
    public static String Cause_Modifier(String s){

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

        return  (line.contains(fct_name))&&(!(line.contains("#")));

    }


}


