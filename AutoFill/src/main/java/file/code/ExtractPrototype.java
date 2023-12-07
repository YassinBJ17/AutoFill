package file.code;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import static file.commun.LoggerInitialize.log4Error;

public class ExtractPrototype {


        public static String searchHeader(String functionName, String directoryPath) {



            File directory = new File(directoryPath);
            if (!directory.exists() || !directory.isDirectory()) {
                log4Error("Invalid directory path.");
                return null;
            }

            String prototype ;
            File[] files = directory.listFiles();

            assert files != null;
            for (File file : files) {
                if (file.isDirectory()) {
                    prototype = searchHeader(functionName, file.getAbsolutePath());
                    if (prototype != null) {
                        return prototype;
                    }
                } else {
                    if (file.getName().endsWith(".h")) {
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
