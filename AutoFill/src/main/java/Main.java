import static COMMUN.BrowsingInputFolder.Processing;
import static COMMUN.GraphicUserInterfaces.Path_interface;
import static COMMUN.LoggerInitialize.*;

//import static services.Logger_init.loger4j;


public class Main {


    public static void main(String[] args){


        String directory=Path_interface();
        System.setProperty("log4j2.enableStackWalker", "true");

        // if(Verification_licences())
        //    System.exit(0);
        String methodName = Thread.currentThread().getStackTrace()[1].getMethodName();
        logError(methodName+" : START" );

        Processing(directory);
        logInfo("Success");

    }

}