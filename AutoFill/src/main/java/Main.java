import java.io.*;

import static file.commun.BrowsingInputFolder.processing;
import static file.commun.GraphicUserInterfaces.*;
import static file.commun.LoggerInitialize.log4Info;


public class Main {


    public static void main(String[] args) throws IOException {


             System.setProperty("log4j2.enableStackWalker", "true");

             //String directory=Path_interface();

            //String version=Version_interface();
             //String date=Date_interface();

            // if(Verification_licences())
            //    System.exit(0);
            String directory="..\\Datafiles\\LLR\\";
            processing(directory);
           //customisedMacro(directory,version,date);

            log4Info("Process finished");
            System.exit(0);

    }

}