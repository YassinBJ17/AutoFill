import static COMMUN.BrowsingInputFolder.Processing;
import static COMMUN.GraphicUserInterfaces.Path_interface;
import static COMMUN.LoggerInit.logger4j;
//import static services.Logger_init.loger4j;


public class Main {


    public static void main(String[] args){


        String directory=Path_interface();

        // if(Verification_licences())
        //    System.exit(0);

        Processing(directory);

        logger4j.info("Success");

    }

}