package excel.file;

import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.ss.util.CellRangeAddress;

public class ExcelModifier {

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
    }
    public static void Fill_Cell(String text,int sheet, int row, int cell) {

        Sheet s = ExcelFinal.workbook.getSheetAt(sheet);
        try {

            Cell c = s.getRow(row).getCell(cell);
            c.setCellValue(text);
        } catch (NullPointerException e) {
            // handle the exception here
            e.printStackTrace();
        }
    }

    public static void Remove_Extra_Rows(int sheet, int start, int end) {
        try {
            Sheet s = ExcelFinal.workbook.getSheetAt(sheet);
            for (int i = start; i < end; i++) {
                Row r = s.getRow(i);
                if (r != null) {
                    s.removeRow(r);
                }
            }
        } catch (NullPointerException e) {
            // handle the exception here
            e.printStackTrace();
        }
    }


    public static void Merge_Cells(int sheet, int C1_start, int C1_end, int numberOfCell) {

        Sheet s= ExcelFinal.workbook.getSheetAt(sheet);

        String S_range= (char) (C1_start + 65)+""+(C1_end)+":"+(char) (C1_start + 65)+numberOfCell;
        CellRangeAddress range = CellRangeAddress.valueOf(S_range);
        s.addMergedRegion(range);

    }

    public static String Stub_Modifier(String s) {

        for (int i = 0; i < 10; i++) {
            s=s.replace("  "," ");
            s=s.replace("\n\n","\n");
        }
        s = s.replace("corresponds to the following call", "by calling ");
        s = s.replace("Corresponds to the call", "by calling ");
        s = s.replace("]:", "");
        s = s.replace("] :", " ");

        if (s.contains("["))
        {
        if (s.substring(s.indexOf("["),s.lastIndexOf("]")).trim().split("\\s+").length>1) {
            s = s.replace("[", "");
            s = s.replace("]", "");
        }}

        return s;
    }
    public static String Set_Modifier(String s) {

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




    public static String[] Param_detect(String str) {

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


