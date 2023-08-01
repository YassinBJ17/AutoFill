package CODE.file;

import static CODE.file.ExtractCode.extractFunctionCode;

public class ExtractFunction {

    public static String[] ExtractFunctionFromCode(String functionName){


        if (functionName.equals("None")){
            return null;
        }

        String Code_text= extractFunctionCode(functionName);
        if (Code_text==null)
            return null;
        Code_text="\n"+Code_text+"\n.";
        return Code_text.split("\n");
    }

}
