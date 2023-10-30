package file.commun;

import java.io.*;
import java.util.Properties;

public class Verification_licences {

    public static boolean Verification_licences() throws IOException {

        Properties props = new Properties();
        try (InputStream is = new FileInputStream("..\\AutoFill\\.idea\\Properties\\sfh.properties")) {
            props.load(is);
        }

        // Get the current version and decrement it
        int version = Integer.parseInt(props.getProperty("version"));
        version--;
        if (version==0){
            return true;
        }

        // Write the updated version back to the properties file
        try (OutputStream os = new FileOutputStream("..\\AutoFill\\target\\maven-archiver\\sfh.properties")) {
            props.setProperty("version", String.valueOf(version));
            props.store(os, null);
        }

        return false;
    }

}
