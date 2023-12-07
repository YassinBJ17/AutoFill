package file.code;

import java.io.*;

import static file.code.ExtractPrototype.searchHeader;
import static file.commun.LoggerInitialize.*;


public class ExtractCode {

    public static String[] searchFunction(File directory, String filename) {

        File[] files = directory.listFiles();

        if (files != null) {
            for (File file : files) {
                if (file.isDirectory()) {
                    String[] result = searchFunction(file, filename);
                    if (result != null) {
                        return result;
                    }
                } else if (file.getName().equalsIgnoreCase(filename)) {
                    try (BufferedReader br = new BufferedReader(new FileReader(file))) {
                        StringBuilder sb = new StringBuilder();
                        String line;
                        while ((line = br.readLine()) != null) {
                            sb.append(line).append(System.lineSeparator());
                        }
                        String[] result = new String[2];
                        result[0] = sb.toString();
                        result[1] = file.getAbsolutePath();
                        // Return the array.
                        return result;
                    } catch (IOException e) {
                        // If there is an error reading the file, print the stack trace and return null.
                        String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                        log4Error(methodName+" : "+e.getMessage() );
                        return null;
                    }
                }
            }
        }
        return null;
    }
    public static String extractFunctionCode(String functionName) {

        String returnedCode;
        String directory="..\\Datafiles\\Code"; // replace with the directory you want to start the search from
        String codeFileName=functionName.trim()+".c";
        String[] result = searchFunction(new File(directory), codeFileName);

        if (result != null) {
            String fileContents = result[0];

            //delete comments
            returnedCode = fileContents.replaceAll("//.*", "");

            // Remove multi-line comments
            int commentStart = returnedCode.indexOf("/*");
            while (commentStart != -1) {
                int commentEnd = returnedCode.indexOf("*/", commentStart + 2);
                if (commentEnd == -1) {
                    // The multi-line comment continues to the end of the code
                    returnedCode = returnedCode.substring(0, commentStart);
                } else {
                    // Remove the multi-line comment
                    returnedCode = returnedCode.substring(0, commentStart) + returnedCode.substring(commentEnd + 2);
                }
                commentStart = returnedCode.indexOf("/*");
            }

            returnedCode=returnedCode.replaceAll("(?m)^[ \t]*\r?\n", "");
            return returnedCode ;
        } else

            returnedCode =searchHeader(functionName,directory);
            if (returnedCode==null)
                log4Error(functionName+" Not found");
            return returnedCode;


    }

}
