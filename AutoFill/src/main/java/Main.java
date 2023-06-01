import java.io.*;

import static services.BrowsingLRR_Folder.Processing;
import static services.GUInterfaces.Error_interface;
import static services.GUInterfaces.Path_interface;
import static services.Logger_init.logger4j;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import services.Logger_init;


public class Main {




    public static void main(String[] args) throws IOException {

        String directory=Path_interface();

      //  if(Verification_licences())
        //    System.exit(0);

        System.setProperty("log4j.configurationFile", ".idea/log4j2.xml");


        try {
            Processing(directory);
        } catch (Exception e) {
            logger4j.error(e);
            Error_interface(String.valueOf(e));
        }

    }

}