package excel.file.B1_Sheet.Classes;

import excel.file.Services.Excel;

import static excel.file.Services.ExcelFinal.cause;

public class ClassFilling {
    public static boolean isInteger(String str) {
        try {
            Integer.parseInt(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
    public static String[] Classes_Filling(String[] parameter) {

        String c;
        String clas="{ ";

        if(!parameter[Excel.INDEX_OF_TYPE].contains("int"))
            return parameter;

        for (int i = 0; i <cause.size() ; i++) {

            c=cause.get(i);
            if (c.contains(parameter[Excel.INDEX_OF_NAME])) {

                c=change_Form(c);
            }
        }
        return parameter;
    }

    private static String change_Form(String input) {
        String result = "";


        if (input.contains("equal to")) {
            result=input.substring(input.indexOf(":")+1);
            result=result+";"+result.replace("equal to" ,"different from");

        } else if (input.contains("different from")) {
            result=input.substring(input.indexOf(":")+1  );
            result=result+";"+result.replace("different from" ,"equal to");
        }




        return result;
    }

}
