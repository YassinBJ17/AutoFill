import static Commun.BrowsingInputFolder.Processing;
import static Commun.GraphicUserInterfaces.Path_interface;
import static Commun.LoggerInitialize.*;


public class Main {


    public static void main(String[] args){

        try {

            String directory=Path_interface();
            System.setProperty("log4j2.enableStackWalker", "true");

            // if(Verification_licences())
            //    System.exit(0);

            Processing(directory);
            log4Info("Process finished");
            System.exit(0);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

}