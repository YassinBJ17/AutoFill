package SUTC.file.COMMUN;
import org.apache.poi.ss.util.CellRangeAddress;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.*;

import static SUTC.file.SutcCreationProccess.workbook;
import static COMMUN.LoggerInitialize.logger4j;


public class ExcelModifier {

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
    public static void Fill_Cell(String text,int sheet, int row, int cell) { // filling one specific cell

        Sheet s = workbook.getSheetAt(sheet);

        try {

            Cell c = s.getRow(row).getCell(cell);
            c.setCellValue(text);

            if ((text.equals("not exist in the DD"))||(text.equals("not exist in the Code")))
                c.setCellStyle(Fill_Cell_Red());

            } catch (NullPointerException e) {
            // handle the exception here
            logger4j.error(e);
        }
    } // filling simple cell
    public static void Remove_Extra_Rows(int sheet, int start, int end) {
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
            logger4j.error(e);
        }
    }
    public static void Merge_Cells(int sheet, int C1_start, int start_row, int end_row) {

        Sheet s= workbook.getSheetAt(sheet);
        String string_range= (char) (C1_start + 65)+""+(start_row)+":"+(char) (C1_start + 65)+end_row;
      //  System.out.println(string_range);
        CellRangeAddress range = CellRangeAddress.valueOf(string_range);

        try {
            s.addMergedRegion(range);
        }catch (Exception e)
        {
            logger4j.error(e);
         }

    } // merge an interval of cells
    public static String StubCall_req_Modifier(String s) {

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
        if (s.substring(s.indexOf("["),s.lastIndexOf("]")).trim().split("\\s+").length>1) {
            s = s.replace("[", "");
            s = s.replace("]", "");
        }}

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
    public static String Req_detect(String[] LLR){

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


        return  (line.contains(fct_name))&&(!(line.contains("#")));

    }


}


