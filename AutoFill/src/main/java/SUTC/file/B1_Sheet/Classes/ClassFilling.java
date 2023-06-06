package SUTC.file.B1_Sheet.Classes;

import SUTC.file.Services.Excel;
import SUTC.file.Services.ExcelFinal;

import static COMMUN.LoggerInit.logger4j;

public class ClassFilling {
    public static boolean isInteger(String str) {
        try {
            Integer.parseInt(str);
            return true;
        } catch (NumberFormatException e) {
            logger4j.error(e);
            return false;
        }
    }
    public static String[] Classes_Filling(String[] parameter) {

        String c;
        String clas="{ ";

        if(!parameter[Excel.INDEX_OF_TYPE].contains("int"))
            return parameter;

        for (int i = 0; i < ExcelFinal.cause.size() ; i++) {

            c= ExcelFinal.cause.get(i);
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
