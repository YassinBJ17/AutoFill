package CODE.file;

import java.io.*;

import static COMMUN.LoggerInitialize.*;


public class ExtractCode {

    public static String[] searchFunction(File directory, String filename) {
        // Get a list of all the files in the directory.
        File[] files = directory.listFiles();
        // If the list is not null, loop through each file in the list.
        if (files != null) {
            for (File file : files) {
                // If the current file is a directory, call this method recursively with the directory as the parameter.
                if (file.isDirectory()) {
                    String[] result = searchFunction(file, filename);
                    // If the method call returns a non-null result, return that result.
                    if (result != null) {
                        return result;
                    }
                    // If the current file is not a directory and has the same name as the filename parameter, read the contents of the file.
                } else if (file.getName().equalsIgnoreCase(filename)) {
                    try (BufferedReader br = new BufferedReader(new FileReader(file))) {
                        StringBuilder sb = new StringBuilder();
                        String line;
                        // Loop through each line of the file and append it to the StringBuilder.
                        while ((line = br.readLine()) != null) {
                            sb.append(line).append(System.lineSeparator());
                        }
                        // Create a new array of two strings, with the first string being the contents of the file and the second string being the absolute path of the file.
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
        // If the file is not found or if there is an error reading the file, return null.
        return null;
    }
    public static String extractFunctionCode(String filename) {

        String directory="..\\Datafiles\\Code"; // replace with the directory you want to start the search from


        String[] result = searchFunction(new File(directory), filename);

        if (result != null) {
            String fileContents = result[0];

            //delete comments
            String cCode = fileContents.replaceAll("//.*", "");

            // Remove multi-line comments
            int commentStart = cCode.indexOf("/*");
            while (commentStart != -1) {
                int commentEnd = cCode.indexOf("*/", commentStart + 2);
                if (commentEnd == -1) {
                    // The multi-line comment continues to the end of the code
                    cCode = cCode.substring(0, commentStart);
                } else {
                    // Remove the multi-line comment
                    cCode = cCode.substring(0, commentStart) + cCode.substring(commentEnd + 2);
                }
                commentStart = cCode.indexOf("/*");
            }

            cCode=cCode.replaceAll("(?m)^[ \t]*\r?\n", "");
            return cCode ;
        } else {


            log4Error("File not found: "+filename);

        }
        return "" ;
    }

}
