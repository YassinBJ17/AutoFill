package SUTC.file.B1_Sheet.Classes;


import SUTC.file.SutcCreationProccess;
import static SUTC.file.COMMUN.ExcelRowsAndColsConstants.*;
import static COMMUN.LoggerInitialize.*;

public class ClassFilling {
    public static boolean isInteger(String str) {
        try {
            Integer.parseInt(str);
            return true;
        } catch (NumberFormatException e) {
            String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
logError(methodName+" : "+e.getMessage() );
            return false;
        }
    }
    public static String[] Classes_Filling(String[] parameter) {

        String c;
        String clas="{ ";

        if(!parameter[INDEX_OF_TYPE].contains("int"))
            return parameter;

        for (int i = 0; i < SutcCreationProccess.cause.size() ; i++) {

            c= SutcCreationProccess.cause.get(i);
            if (c.contains(parameter[INDEX_OF_NAME])) {

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
