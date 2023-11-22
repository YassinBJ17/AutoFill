package file.code;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

import static file.commun.GraphicUserInterfaces.Error_interface;
import static file.commun.LoggerInitialize.log4Error;

public class ExtractPrototype {


        public static String searchHeader(String functionName, String directoryPath) {



            File directory = new File(directoryPath);
            if (!directory.exists() || !directory.isDirectory()) {
                log4Error("Invalid directory path.");
                return null;
            }

            String prototype = null;
            File[] files = directory.listFiles();

            for (File file : files) {
                if (file.isDirectory()) {
                    // Recursively search in subdirectories
                    prototype = searchHeader(functionName, file.getAbsolutePath());
                    if (prototype != null) {
                        return prototype;
                    }
                } else {
                    if (file.getName().endsWith(".h")) {
                        // If the file is a .h file, search for the function prototype
                        prototype = searchFunctionInHeader(file, functionName);
                        if (prototype != null) {
                            return prototype;
                        }
                    }
                }
            }
            return null;
        }

        private static String searchFunctionInHeader(File headerFile, String functionName) {
            try (BufferedReader reader = new BufferedReader(new FileReader(headerFile))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    if ((line.contains(functionName+" ("))||(line.contains(functionName+"( "))) {
                        // Assuming the function prototype is on the same line and not spanning multiple lines
                        line=line.replace("extern","");
                        return line.trim();
                    }
                }
            } catch (IOException e) {
                String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
                log4Error(methodName+" : "+e.getMessage() );
            }

            return null;
        }

}
